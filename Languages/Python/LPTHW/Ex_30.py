people = 30;
cars = 40;
trucks = 15

if cars > people:
	print "We should take the cars."
elif cars < people:
	print "we should not take the cars."
else:
	print "We can't decide."
	
if trucks > cars:
	print " That's too many trucks. "
elif trucks < cars:
	print "Maybe we could take the trucks."
else:
	print " We still can't decide."
	
if people > trucks:
	print "alright, let's just take the trucks."
else:
	print "Fine, let's stay home then."
	
