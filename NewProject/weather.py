#!/usr/bin/env python
import webapp2
import jinja2
import urllib2
import os
import random
import json
jinja_environment = jinja2.Environment(loader=jinja2.FileSystemLoader(os.path.dirname(__file__)+'/templates'))
class MainHandler(webapp2.RequestHandler):
	def get(self):
		template_values={'errata':"For Example:  Shimla, Bangkok, New York etc."}
		template = jinja_environment.get_template('weather_get.html')
		self.response.out.write(template.render(template_values))
	def post(self):
		query=(self.request.get('location'))
		if query=="":
			template_values={'errata':"Hey! No input???"}
			template = jinja_environment.get_template('weather_get.html')
			self.response.out.write(template.render(template_values))
		else:
			w=query.replace(" ","+")
			try:
				wurl="http://api.wunderground.com/api/2225b8ee850d2f4c/geolookup/conditions/q/"+w+".json"
				f=urllib2.urlopen(wurl) #location XML content requested
				json_string=f.read()	#location XML content read
			except:
				template_values={'errata':"Sorry! No such location found."}
				template = jinja_environment.get_template('weather_get.html')
				self.response.out.write(template.render(template_values))
			else:
				try:
					parsed_json = json.loads(json_string) #json string loaded for parsing
					obs_time=parsed_json['current_observation']['local_time_rfc822']				
					temp_c=parsed_json['current_observation']['temp_c']
					rel_humidity=parsed_json['current_observation']['relative_humidity']
					wind_dir=parsed_json['current_observation']['wind_string']
					dew_c=parsed_json['current_observation']['dewpoint_c']
					visibility=parsed_json['current_observation']['visibility_km']
					country=parsed_json['current_observation']['display_location']['full']
					longitude=parsed_json['location']['lon']
					latitude=parsed_json['location']['lat']
					elev=parsed_json['current_observation']['display_location']['elevation']
					template_values={'location':query,'time':obs_time,'temp':temp_c,
							'humidity':rel_humidity,'wind':wind_dir,'dew':dew_c,'visibility':visibility,
							'country':country,'lat':latitude,'long':longitude,'elev':elev}	
				except:
					template_values={'errata':"Sorry! No such location found."}
					template = jinja_environment.get_template('weather_get.html')
					self.response.out.write(template.render(template_values))	
				else:
					template = jinja_environment.get_template('weather_post.html')
					self.response.out.write(template.render(template_values))

app = webapp2.WSGIApplication([
    ('/.*', MainHandler)
], debug=True)



'''
http://api.wunderground.com/api/2225b8ee850d2f4c/geolookup/conditions/q/new+york.json
import urllib2
import json
f = urllib2.urlopen('http://api.wunderground.com/api/Your_Key/geolookup/conditions/q/IA/Cedar_Rapids.json') 
json_string = f.read()
parsed_json = json.loads(json_string) 
location = parsed_json['location']['city'] 
temp_f = parsed_json['current_observation']['temp_f'] 
print "Current temperature in %s is: %s" % (location, temp_f) 
f.close()
'''
