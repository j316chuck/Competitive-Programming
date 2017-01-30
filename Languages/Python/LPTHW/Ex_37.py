#List to memorize in python
import sys

a = True
x = "hello"
float = 10.389
numbers = 10
x = None
lists = [12]
dicts = {'x': 1, 'y':2}

"""
\\ \' \" \a \t \v \r \n
%d % i %f %c %
"""
exec 'print "Hello"'
#finally: pass

#yield with as try except raie lamdbda  assert

mylist = [x*x for x in range(3)]

mygenerator = (x*x for x in range(3))
for i in mygenerator:
	print i
#yield
def createGenerator():
	mylist = range(3)
	for i in mylist:
		yield i*i
mygenerator = createGenerator()
print mygenerator
for i in mygenerator:
	print(i)

#with as
"""a = raw_input()
def controlled_execution(callback):
	try: callback(thing)
"""
#try 
(x,y) = (5,0)
try:
	z = x/y
except ZeroDivisionError:
	print "Divide by zero"
#except

#raise
if x==5:
	raise Exception("error")
#lamdbda

def KelvinToFahrenheit(Temperature):
   assert (Temperature >= 0),"Colder than absolute zero!"
   return ((Temperature-273)*1.8)+32

print KelvinToFahrenheit(273)
print int(KelvinToFahrenheit(505.78))
print KelvinToFahrenheit(-5)

#assert

g = lambda x: return x**2
print g(8)