#!/usr/bin/env python
import webapp2
import jinja2
import os
import urllib2
from BeautifulSoup import BeautifulSoup
jinja_environment = jinja2.Environment(loader=jinja2.FileSystemLoader(os.path.dirname(__file__)+'/templates'))
class MainHandler(webapp2.RequestHandler):
    def get(self):
		template_values={'placeholder':"QBing Query???"}
		template = jinja_environment.get_template('app_get.html')
		self.response.out.write(template.render(template_values))
    def post(self):
		query =str( self.request.get('query'))
		if query=="":
			template_values={'placeholder':"Hey! No input???"}
			template = jinja_environment.get_template('app_get.html')
			self.response.out.write(template.render(template_values))
		else:			
			try:
				c=query.replace(" ","+")
				curl="http://www.bing.com/search?q="+c
				http=urllib2.urlopen(curl)
				var=http.read()
			except:
				template_values={'placeholder':"Sorry! Server not reporting."}
				template = jinja_environment.get_template('app_get.html')
				self.response.out.write(template.render(template_values))				
			else:
				try:
					soup=BeautifulSoup(var)
					j=soup.findAll('cite')
					p=soup.findAll('a',href=True)
				except:
					template_values={'placeholder':"Sorry! We can't produce data."}
					template = jinja_environment.get_template('app_get.html')
					self.response.out.write(template.render(template_values))					
				else:
					firstpage=[]
					unique=[]
					for i in p:
						i=i['href']
						i=str(i)
						ht=i.split(':')
						if ht[0]=="http":
							firstpage.append(i)
					for i in j:
						if i not in unique:
							unique.append(i)
					for i in firstpage:
						if i not in unique:
							unique.append(i)
					firstpage=[]
					for i in unique:
						if (len(i)<150):
							firstpage.append(i)
					template_values={'query':query,'data':firstpage}
					template = jinja_environment.get_template('app_post.html')
					self.response.out.write(template.render(template_values))

app = webapp2.WSGIApplication([
    ('/.*', MainHandler)
], debug=True)
