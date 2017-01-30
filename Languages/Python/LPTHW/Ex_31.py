print "You enter a dark room with two doors. Do you go through door #1 or door #2"

door = raw_input("> ")

if door == "1":
	print "There's a giant bear here eating a cheese cake. What do you do?"
	print "1. Take the cake."
	print "2. Scream at the bear."
	
	bear = raw_input("> ")
	
	if bear == "1":
		print "The bear kills you"
	elif Bear == "2":
		print "the bear eats you"
	else:
		print "Well, doing %s is probably better" %bear
		
elif door == "2":
	print "you Stare into the endless abyess"
	insanity = raw_input("> ")
	if insanity == "1" or insanity == "2":
		print "you survived"
	else:
		print " you died"
		
else:
	print "You die"