import math

class Imaginary(object):
	def __init__(self, re, im):
		self.re = re
		self.im = im
		
	def __add__(self, im):
		a = self.re + im.re
		b = self.im + im.im
		return Imaginary(a,b)
		
	def __sub__(self, no):
		real = self.re - no.re
		imaginary = self.im - no.im
		return Imaginary(real, imaginary)	
		
	def __mul__(self, no):
		real = self.re * no.re - self.im * no.im
		imaginary = self.im * no.re + self.re * no.im
		return Imaginary(real, imaginary)
	
	def __div__(self, no):	
		bot = no.re ** 2 + no.im **2 
		top_re = self.re * no.re + self.im * no.im
		top_im = self.re * (-1*no.im) + self.im * no.re
		return Imaginary(top_re/bot, top_im/bot)
	
	def mod(self):
		real = math.sqrt(self. re*self.re + self.im*self.im)
		return Imaginary(real, 0)
		
	def __str__(self):
		if self.im == 0:
			result = ("%.2f+0.00i") % self.re
		elif self.re == 0:
			if self.im > 0:
				result = ("0.00+%.2fi") % self.im
			else:
				result = ("0.00-%.2fi") % abs(self.im)
		elif self.im > 0:
			result = ("%.2f+%.2fi") % (self.re, self.im)
		else:
			result = ("%.2f-%.2fi") % (self.re, abs(self.im))
		return result
		

C = map(float, raw_input().split());
D = map(float, raw_input().split());

A = Imaginary(*C)
B = Imaginary(*D)
#int a, b, c, d

list = [A+B, A-B, A*B, A/B, A.mod(), B.mod()]
	
print '\n'.join(map(str, list))
