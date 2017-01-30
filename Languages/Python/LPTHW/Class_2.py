"""
class Circle(object):
	def __init__(self, radius):
		self.radius = radius
	
	def get_Area(self):
		return self.radius*self.radius*3.14
	

class Rectangle(object):
	def __init__(self, length, width):
		self.length = length
		self.width = width
		
	def get_Area(self):
		return self.width*self.length

A = Circle(5)
print A.get_Area()
B = Rectangle(3, 4)
print B.get_Area()

"""

class Shape(object):
	def __init__(self):
		pass
	def area(self):
		return 0
		
class Square(Shape):
	def __init__(self, length):
		Shape.__init__(self)
		self.length = length
		
	def area(self):
		return self.length*self.length
		
aSquare = Square(3)
print aSquare.area()