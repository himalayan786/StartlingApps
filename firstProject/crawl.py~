import wsgiref.handlers
import urllib2
from BeautifulSoup import BeautifulSoup
import webapp2
import jinja2
import os
jinja_environment = jinja2.Environment(loader=jinja2.FileSystemLoader(os.path.dirname(__file__)+'/templates'))
class MainHandler(webapp2.RequestHandler):
	def get(self):
		template_values={'errata':"e.g. http://www.google.com/"}
		template = jinja_environment.get_template('crawl_get.html')
		self.response.out.write(template.render(template_values))
	def post(self):
		query =str( self.request.get('url'))
		if query=="":
			template_values={'errata':"Hey! No input???"}
			template = jinja_environment.get_template('crawl_get.html')
			self.response.out.write(template.render(template_values))
		else:			
			try:
				http=urllib2.urlopen(query)
				var=http.read()
			except:
				template_values={'errata':"Sorry! Server not reporting."}
				template = jinja_environment.get_template('crawl_get.html')
				self.response.out.write(template.render(template_values))				
			else:
				try:
					soup=BeautifulSoup(var)
					j=soup.findAll('a',href=True)
				except:
					template_values={'errata':"Sorry! We can't produce data."}
					template = jinja_environment.get_template('crawl_get.html')
					self.response.out.write(template.render(template_values))					
				else:
					firstpage=[]
					unique=[]
					for i in j:
						i=i['href']
						i=str(i)
						ht=i.split(':')
						if ht[0]=="http":
							firstpage.append(i)
					for i in firstpage:
						if i not in unique:
							unique.append(i)
					template_values={'val':"New Crawl???",'url':query,'data':unique}
					template = jinja_environment.get_template('crawl_post.html')
					self.response.out.write(template.render(template_values))
def main():
	application = webapp2.WSGIApplication([('/.*', MainHandler)],debug=True)
	wsgiref.handlers.CGIHandler().run(application)
if __name__ == '__main__':
	main()
