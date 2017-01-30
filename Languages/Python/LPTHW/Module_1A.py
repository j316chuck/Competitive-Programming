numberone = 1
ageofqueen = 78

def printhello():
	print "Hello"
	
class Piano:
	def __init__(self):
		self.type = raw_input("What type of piano?")
		self.height = raw_input("What height?")
		
	def printdetails(self):
		print self.height 
