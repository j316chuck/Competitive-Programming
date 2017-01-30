class American(object):	
	@staticmethod
	def printNationality():
		print "America"

class NewYorker(American):
	"""
	To add initial value that is different
	American.__init__(self)
	New stuff
	"""
	def printNationality(self):
		print "American from New York"
		

A = American()
A.printNationality()
American.printNationality()
B = NewYorker()
B.printNationality()

