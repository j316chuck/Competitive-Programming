from datetime import datetime
tues = date(2011, 9, 12)
repr(tues)
tues.__repr__() #'datetime.date(2011,9,12)'
tues.__str__() #'2012-09-12'

Account.__bool__ = lambda self: self.balance!=0

bool(Account('Jack'))
if not Account('Jack'):


'Go Bears!'.__len__()

print('Go Bears'[3])

class Adder(object):
	def __init__(self, n):
		self.n = n;
	def __call_(self, k):
		return self.n+k

isinstance(c, ComplexMa)
isinstance(c, Complex)

class ComplexRI(Complex):
	def __init__(self, real, imag):
		self.real = real
		self.imag = imag
	@property
	def magnitude(self):
		return (self.real**2+self.imag**2)**0.5

def is_real(c):
	if isinstance(c, ComplexRI):
		return c.imag == 0
	elif isinstance(c, complexMA)
	return c.angel % pi == 0 

Rational.type_tag = 'rat'
Complex.type_tag = 'com'

Rational(2,5).type_rag == Rational(1,2).type_tag

