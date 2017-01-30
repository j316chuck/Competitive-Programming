the_counts = [1 , 2, 3, 4, 5]
fruits = ['apples', 'oranges', 'pears', 'apricots']
change = [1, 'pennies', 2, 'dimes', 3, 'quarters']

for number in the_counts:
	print "This is count %d " % number
for fruit in fruits:
	print "A fruit of type: %s" % fruit
for i in change:
	print "I got %r " % i
	
#elements = range(0, 6)		
for i in range(0,6):
	print "adding %d to the list." %i
	elements.append(i)
	
for i in elements:
	print "Element was: %d" % i
	

