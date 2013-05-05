import wsgiref.handlers
import urllib2
from BeautifulSoup import BeautifulSoup
import webapp2
import jinja2
import os
import re
jinja_environment = jinja2.Environment(loader=jinja2.FileSystemLoader(os.path.dirname(__file__)+'/templates'))
class MainHandler(webapp2.RequestHandler):
	def get(self):
		template_values={'val':"Make a Forcast???"}
		template = jinja_environment.get_template('locations_get.html')
		self.response.out.write(template.render(template_values))
def main():
	application = webapp2.WSGIApplication([('/.*', MainHandler)],debug=True)
	wsgiref.handlers.CGIHandler().run(application)
if __name__ == '__main__':
	main()
