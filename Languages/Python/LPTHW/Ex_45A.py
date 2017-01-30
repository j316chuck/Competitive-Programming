""""class Hello(object):
	def __init__(self, x):
		self.x = x
		
	def test(self):
		print ("test")
		return 0;
"""

class Freshman(object):
	
	def enter(self):
		print "Freshman year is fun"
		print "However it is very busy too"
		answer = raw_input("Do you spend your time studying or playing? ")
		if answer == "studying":
			return "Sophomore"
		else:
			return "Fail"
			
class Sophomore(object):
	
	def enter(self):
		print "Sophomore year sucks"
		answer = raw_input("Do you spend your time getting a gf or reading bible? ")
		if answer == "gf":
			return "Fail"
		else:
			return "Junior"
			
	def get_name(self):
		print "Sophomore"
		return 0
		
class Junior(object):
	
	def enter(self):
		print "Junior year is better"
		answer = raw_input("Did you study for FB hacker cup or do study abroad? ")
		if answer == "FB hacker cup":
			return "Senior"
		if answer == "study abroad":
			return "Fail"
			
class Senior(object):

	def enter(self):
		print "Senior year rocks"
		answer = raw_input("Did you slack off or find a job? ")
		if answer == "job":
			return "Graduation"
		else:
			return "Fail"