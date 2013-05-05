#!/usr/bin/env python
import urllib2
import webapp2
import jinja2
import os
from BeautifulSoup import BeautifulSoup
jinja_environment = jinja2.Environment(loader=jinja2.FileSystemLoader(os.path.dirname(__file__)+'/templates'))
class MainHandler(webapp2.RequestHandler):
	def get(self):
		template_values={'errata':"For Example:  http://www.google.com/"}
		template = jinja_environment.get_template('crawler_get.html')
		self.response.out.write(template.render(template_values))
	      #  self.response.headers["Content-Type"] = "text/plain"
	def post(self):
		query =( self.request.get('url'))
		if query=="":
			template_values={'errata':"Hey! No input???"}
			template = jinja_environment.get_template('crawler_get.html')
			self.response.out.write(template.render(template_values))
		else:			
			try:
				http=urllib2.urlopen(query)
				var=http.read()
			except:
				template_values={'errata':"Sorry! Server not reporting."}
				template = jinja_environment.get_template('crawler_get.html')
				self.response.out.write(template.render(template_values))				
			else:
				try:
					soup=BeautifulSoup(var)
					j=soup.findAll('a',href=True)
				except:
					template_values={'errata':"Sorry! We can't produce data."}
					template = jinja_environment.get_template('crawler_get.html')
					self.response.out.write(template.render(template_values))					
				else:
					firstpage=[]
					unique=[]
					for i in j:
						i=i['href']
						i=str(i)
						ht=i.split(':')
						if ht[0]=="http" or ht[0]=="https":
							firstpage.append(i)
					for i in firstpage:
						if i not in unique:
							unique.append(i)
					if len(unique)==0:
						x="No http/https URL found in "+query
						unique.append(x)
						template_values={'url':query,'data':unique}
						template = jinja_environment.get_template('crawler_post.html')
						self.response.out.write(template.render(template_values))
					else:
						template_values={'url':query,'data':unique}
						template = jinja_environment.get_template('crawler_post.html')
						self.response.out.write(template.render(template_values))

app = webapp2.WSGIApplication([
    ('/.*', MainHandler)
], debug=True)
