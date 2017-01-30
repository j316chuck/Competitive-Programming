import math
import sys

sys.stdin = open("input.in")

class Coord(object):
	def __init__(self, x, y, z):
		self.x = x
		self.y = y
		self.z = z
		
	def line(self, B):
		a = B.x-self.x
		b = B.y-self.y
		c = B.z-self.z
		return Coord(a,b,c)
	
	def get_Coord(self):
		return self.x, self.y, self.z
		
	def cross(self, B, C):
		a = B.y * C.z - B.z * C.y 
		b = -1 * (B.x * C.z - B.z * C.x)
		c = B.x * C.y - B.y * C.x 
		return Coord(a,b,c)
	
	def dot(self, B):
		a = self.x * B.x
		b = self.y * B.y 
		c = self.z * B.z 
		return float(a+b+c)
	
	def abs(self):
		return math.sqrt(self.x**2+self.y**2+self.z**2)
		
A = map(float, raw_input().split())
B = map(float, raw_input().split())
C = map(float, raw_input().split())
D = map(float, raw_input().split())

A = Coord(*A)
B = Coord(*B)
C = Coord(*C)
D = Coord(*D)

AB = A.line(B)
BC = B.line(C)
CD = C.line(D)
#print AB.get_Coord(), BC.get_Coord(), CD.get_Coord()

X = A.cross(AB, BC)
Y = B.cross(BC, CD)

#print X.get_Coord(), Y.get_Coord()
#print X.dot(Y)
#print X.abs()
result = X.dot(Y)/(X.abs()*Y.abs())
#print result
result = math.degrees(math.acos(result))

print "%.2f" %round(result,2) #*180/math.pi
#print X.x, X.y, X.z 
#print Y.x, Y.y, Y.z

#list = [A, B, C  :)  yeah man ummm yeah manu mm yeah man ummm :D, D]
#print list
