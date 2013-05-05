#!/usr/bin/env python
import urllib2
import webapp2
import jinja2
import os
from BeautifulSoup import BeautifulSoup
jinja_environment = jinja2.Environment(loader=jinja2.FileSystemLoader(os.path.dirname(__file__)+'/templates'))
class MainHandler(webapp2.RequestHandler):
	def get(self):
		template_values={'errata':"For Example:  Amazing, Application etc."}
		template = jinja_environment.get_template('dict_get.html')
		self.response.out.write(template.render(template_values))
	def post(self):
		query =str(self.request.get('word'))
		if query=="":
			template_values={'errata':"Hey! No input???"}
			template = jinja_environment.get_template('dict_get.html')
			self.response.out.write(template.render(template_values))
		else:	
			c=query.replace(" ","-")
			try:
				curl="http://www.collinsdictionary.com/dictionary/english/"+c#link for collins 
				durl="http://www.yourdictionary.com/"+c#link for yourdictionary
				cvar=urllib2.urlopen(curl)
				chtml=cvar.read()
				dvar=urllib2.urlopen(durl)
				dhtml=dvar.read()
			except:
				template_values={'errata':"Sorry! Word not found."}
				template = jinja_environment.get_template('dict_get.html')
				self.response.out.write(template.render(template_values))
			else:
				try:
					csoup=BeautifulSoup(chtml)
					cj=csoup.findAll("ol")
					dsoup=BeautifulSoup(dhtml)
					dj=dsoup.findAll("div",{"class":"custom_entry"})
					template_values={'word':query,'collins':cj[0],'your':dj}
				except:
					template_values={'errata':"Sorry! We can't produce data."}
					template = jinja_environment.get_template('dict_get.html')
					self.response.out.write(template.render(template_values))
				else:
					template = jinja_environment.get_template('dict_post.html')
					self.response.out.write(template.render(template_values))

app = webapp2.WSGIApplication([
    ('/.*', MainHandler)
], debug=True)
