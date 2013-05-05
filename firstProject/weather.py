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
		template_values={'errata':"e.g. Shimla, Kyelong, Manali..."}
		template = jinja_environment.get_template('weather_get.html')
		self.response.out.write(template.render(template_values))
	def post(self):
		'''indq="http://www.wunderground.com/cgi-bin/findweather/hdfForecast?query=india"
		indv=urllib2.urlopen(indq)
		indht=indv.read()
		indsoup=BeautifulSoup(indht)
		indthead=indsoup.findAll("div",{"class":"borderBox brBot5"})
		self.response.out.write(indthead[0])
		'''
		query=str(self.request.get('city'))
		if query=="":
			template_values={'errata':"Hey! No input???"}
			template = jinja_environment.get_template('weather_get.html')
			self.response.out.write(template.render(template_values))
		else:
			w=query.replace(" ","+")
			try:
				wurl="http://www.wunderground.com/cgi-bin/findweather/hdfForecast?query="+w+"&MR=1"
				wvar=urllib2.urlopen(wurl)
				whtml=wvar.read()
			except:
				template_values={'errata':"Sorry! No such location found."}
				template = jinja_environment.get_template('weather_get.html')
				self.response.out.write(template.render(template_values))
			else:
				try:
					wsoup=BeautifulSoup(whtml)
					wlong=wsoup.find("div",{"id":"infoLongitude"})#Logitude
					wlat=wsoup.find("div",{"id":"infoLatitude"})#Latitude
					welev=wsoup.find("div",{"id":"infoElevation"})#Latitude
					wtime=wsoup.find("div",{"id":"infoTime"})#Current Time
					wrise=wsoup.find("div",{"id":"sRise"})#Sun Rise
					wset=wsoup.find("div",{"id":"sSet"})#Sun Set
					wf=wsoup.find("div",{"id":"tempFeel"})#to find current temprature
					ww=wsoup.find("span",{"id":"windCompassSpeed"})#wind Speed
					wc=wsoup.find("div",{"id":"nowCond"})#Current COndition
					wfore=wsoup.findAll("div",{"class":"foreSummary"})#future Expectations
					wrain=wsoup.findAll("div",{"class":"foreCondition"})
					#ws=wsoup.findAll("div",{"id":"stationName"})#to find the Station
					#wp=wsoup.findAll("span",{"class":"rfGreen"})#updation info
					template_values={'location':query,'time':wtime,'sunrise':wrise,'sunset':wset,'temp':wf,
							'wind':ww,'condition':wc,'tonight':wfore[0],'rtn':wrain[0],'tomorrow':wfore[1],
							'rtm':wrain[1],'lat':wlat,'long':wlong,'elev':welev,'val':"New Location???"}	
				except:
					template_values={'errata':"Sorry! We can't produce data."}
					template = jinja_environment.get_template('weather_get.html')
					self.response.out.write(template.render(template_values))	
				else:
					template = jinja_environment.get_template('weather_post.html')
					self.response.out.write(template.render(template_values))
def main():
	application = webapp2.WSGIApplication([('/.*', MainHandler)],debug=True)
	wsgiref.handlers.CGIHandler().run(application)
if __name__ == '__main__':
	main()
