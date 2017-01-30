"""
a = int(raw_input())
b = int(raw_input())
i = 0
numbers = []

while i < a:
	print "At the top i is %d" % i
	numbers.append(i)

	i = i+b


print "The Numbers."

for num in numbers:
	print num
"""
a = int(raw_input())
inc = int(raw_input())

for i in xrange(0, a, inc):
	print i