import wsgiref.handlers
import urllib2
import webapp2
import jinja2
import os
import random
jinja_environment = jinja2.Environment(loader=jinja2.FileSystemLoader(os.path.dirname(__file__)+'/templates'))
class MainHandler(webapp2.RequestHandler):
	def get(self):
		dev=random.randrange(1,3)
		pic1=random.randrange(1,62)
		pic2=random.randrange(1,62)
		if pic1==2 or pic1==5 or pic1==10 or pic1==22:
			pic1=pic1+1
		if pic1==pic2:
			pic2=pic1+1
		dict1={	1:"Christ Church, Shimla",2:"Snow covered Scandal Point, Shimla",3:"Ridge Ground Night View, Shimla",
		4:"The Mall, Shimla",5:"Snow covered Ridge, Shimla",6:"View of Shimla", 7:"Kufri Hill Station near Shimla",
		8:"Snow covered Ridge, Shimla", 9:"Ridge Ground Shimla(Helicopter View)",10:"10th century LaxmiNarayan Temple, Chamba",
		11:"Railway Station Shimla",12:"Himachali Apple",13:"Asia's Highest Bridge at Satluj, Bilaspur",14:"Lord Baijnath Temple, Kangra",
		15:"Himalayan Queen at Barog Station, Solan",16:"BhimaKali Temple Rampur, Shimla",17:"Himachali Dance(Natti)",
		18:"Hotel 'Gufa' at Ridge, Shimla", 19:"Himachali Pear", 20:"BhimaKali Temple Rampur, Shimla",
		21:"Himachali Tableau at Rajpath(Delhi) on 2013 Republic Day",
		22:"Lord Budha, Spiti Valley", 23:"Hatu Temple, Shimla",24:"Hill Station, Kasauli",25:"Godddess Chintpurni Temple, Una",
		26:"Janjehli Valley, Mandi",27:"Garib Das Temple, Una",28:"Kalpa Valley, Kinnaur",29:"The famous KaliBari Temple, Shimla",
		30:"Kaza(Elevation:3,650m), Spiti Valley",31:"Himalayan Queen in Kangra",32:"Kye Monastery, Spiti Valley",33:"ManiMahesh, Chamba",
		34:"Goddess Naina Devi Temple, Manikaran",35:"Manali, Kullu",36:"Highest Cricket Stadium of the World, Dharamsala",
		37:"Goddess Naina Devi, Bilaspur", 38:"Nako Lake Pooh, Kinnaur",39:"Shrikhand Mahadev Way, Shimla",
		40:"Paragliding near Baijnath, Kangra",41:"The famous Rewalsar Lake, Mandi",42:"Hills View from Shikari Devi, Mandi",
		43:"Rohtang Pass, Manali",44:"Sujanpur Fort, Hamirpur",45:"Hill's Road View near Durgethi, Kinnaur",
		46:"Himalayan Queen near Pathankot, Kangra",47:"Nako Lake Pooh, Kinnaur",48:"Lord Baijnath Temple, Kangra",
		49:"The real spice of Himachal: Himachali Apple",50:"The toy train track",51:"The Beautiful Himachal",
		52:"The Last Hut near Chitkul Village(Indo-Tibetan Border), Kinnaur", 53:"Anadale Ground, Shimla",
		54:"Govt. Engineering College Sundernagar, Mandi",55:"Summerhill Railway Station, Shimla",
		56:"God Hanuman's Statue at Jakhu Temple, Shimla",57:"Museum at Anadale, Shimla",58:"Sundernagar Lake, Mandi",
		59:"Anadale Ground, Shimla",60:"Baba Balak Nath Temple, Hamirpur", 61:"Jakhu Temple, Shimla",
		62:"Goddess Hadimba, Manali"}
		tit1=dict1[pic1]			
		tit2=dict1[pic2]
		val="Your Google Query???"
		template_values={'placeholder':val,'me1':dev,'right1':pic1, 'title1':tit1,'right2':pic2, 'title2':tit2}
		template = jinja_environment.get_template('home_get.html')
		self.response.out.write(template.render(template_values))
	def post(self):
		query = str(self.request.get('googly'))
		dev=random.randrange(1,3)
		pic1=random.randrange(1,62)
		pic2=random.randrange(1,62)
		if pic1==2 or pic1==5 or pic1==10 or pic1==22:
			pic1=pic1+1
		if pic1==pic2:
			pic2=pic1+1
		dict1={	1:"Christ Church, Shimla",2:"Snow covered Scandal Point, Shimla",3:"Ridge Ground Night View, Shimla",
		4:"The Mall, Shimla",5:"Snow covered Ridge, Shimla",6:"View of Shimla", 7:"Kufri Hill Station near Shimla",
		8:"Snow covered Ridge, Shimla", 9:"Ridge Ground Shimla(Helicopter View)",10:"10th century LaxmiNarayan Temple, Chamba",
		11:"Railway Station Shimla",12:"Himachali Apple",13:"Asia's Highest Bridge at Satluj, Bilaspur",14:"Lord Baijnath Temple, Kangra",
		15:"Himalayan Queen at Barog Station, Solan",16:"BhimaKali Temple Rampur, Shimla",17:"Himachali Dance(Natti)",
		18:"Hotel 'Gufa' at Ridge, Shimla", 19:"Himachali Pear", 20:"BhimaKali Temple Rampur, Shimla",
		21:"Himachali Tableau at Rajpath(Delhi) on 2013 Republic Day",
		22:"Lord Budha, Spiti Valley", 23:"Hatu Temple, Shimla",24:"Hill Station, Kasauli",25:"Godddess Chintpurni Temple, Una",
		26:"Janjehli Valley, Mandi",27:"Garib Das Temple, Una",28:"Kalpa Valley, Kinnaur",29:"The famous KaliBari Temple, Shimla",
		30:"Kaza(Elevation:3,650m), Spiti Valley",31:"Himalayan Queen in Kangra",32:"Kye Monastery, Spiti Valley",33:"ManiMahesh, Chamba",
		34:"Goddess Naina Devi Temple, Manikaran",35:"Manali, Kullu",36:"Highest Cricket Stadium of the World, Dharamsala",
		37:"Goddess Naina Devi, Bilaspur", 38:"Nako Lake Pooh, Kinnaur",39:"Shrikhand Mahadev Way, Shimla",
		40:"Paragliding near Baijnath, Kangra",41:"The famous Rewalsar Lake, Mandi",42:"Hills View from Shikari Devi, Mandi",
		43:"Rohtang Pass, Manali",44:"Sujanpur Fort, Hamirpur",45:"Hill's Road View near Durgethi, Kinnaur",
		46:"Himalayan Queen near Pathankot, Kangra",47:"Nako Lake Pooh, Kinnaur",48:"Lord Baijnath Temple, Kangra",
		49:"The real spice of Himachal: Himachali Apple",50:"The toy train track",51:"The Beautiful Himachal",
		52:"The Last Hut near Chitkul Village(Indo-Tibetan Border), Kinnaur", 53:"Anadale Ground, Shimla",
		54:"Govt. Engineering College Sundernagar, Mandi",55:"Summerhill Railway Station, Shimla",
		56:"God Hanuman's Statue at Jakhu Temple, Shimla",57:"Museum at Anadale, Shimla",58:"Sundernagar Lake, Mandi",
		59:"Anadale Ground, Shimla",60:"Baba Balak Nath Temple, Hamirpur", 61:"Jakhu Temple, Shimla",
		62:"Goddess Hadimba, Manali"}
		tit1=dict1[pic1]			
		tit2=dict1[pic2]
		val="Your Google Query???"
		if query=="":
			val="e.g. Startling Apps"
			template_values={'placeholder':val,'me1':dev,'right1':pic1, 'title1':tit1,'right2':pic2, 'title2':tit2}
			template = jinja_environment.get_template('home_get.html')
			self.response.out.write(template.render(template_values))
		else:
			query1=query.replace(" ","+")		
			url="http://www.google.com/search?q=" + query1 +"&site_search=google.com/"
			template_values={'home_url':url,'home_query':query}
			template = jinja_environment.get_template('home_post.html')
			self.response.out.write(template.render(template_values))
			
def main():
	application = webapp2.WSGIApplication([('/.*', MainHandler)],debug=True)
	#(/.*) indicate that jitne bhi iss page pe requests aaenge unhe MainHandler class ko de de...
	wsgiref.handlers.CGIHandler().run(application)
if __name__ == '__main__':
	main()
