'''
import datetime
from google.appengine.api import users

print 'Content-Type: text/html'
print ''
print '<p>The time is: %s</p>' % str(datetime.datetime.now())


# Say hello to the current user
user = users.get_current_user()
if user:
  nickname = user.nickname()
else:
  nickname = "guest"
print "Hello, " + nickname
'''


import wsgiref.handlers
import webapp2
class MainHandler(webapp2.RequestHandler):
	formstring = '''<form method="post" action="/">
<p>Enter Guess: <input type="text" name="guess"/></p>
<p><input type="submit"></p>
</form>'''
	def get(self):
		self.response.out.write('<p>Good luck!</p>\n')
		self.response.out.write(self.formstring)
	def post(self):
		stguess = self.request.get('guess')
		try:
			guess = int(stguess)
		except:
			guess = -1
		answer = 42
		if guess == answer:
			msg = 'Congratulations'
		elif guess < 0 :
			msg = 'Please provide a number guess'
		elif guess < answer:
			msg = 'Your guess is too low'
		else:
			msg = 'Your guess is too high'
		self.response.out.write('<p>Guess:'+stguess+'</p>\n')
		self.response.out.write('<p>'+msg+'</p>\n')
		self.response.out.write(self.formstring)
def main():
	application = webapp2.WSGIApplication([('/', MainHandler)],debug=True)
	wsgiref.handlers.CGIHandler().run(application)
if __name__ == '__main__':
	main()


