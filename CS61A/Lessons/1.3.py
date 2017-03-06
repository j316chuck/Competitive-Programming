from operator import add

def square(x):
	return x*x

def sum_squares(x, y):
	return add(square(x), square(y))

def g():
	return 1
	
print (g)
g()
g=2
print g
def g(h,i):
	return h+i
print g(1,2)
print(sum_squares(3, 4))

def pressure(v, t, n = 6.0022e23):
	k = 1.38e-23
	return n*k*t/v
	
print(pressure(1, 273.14))