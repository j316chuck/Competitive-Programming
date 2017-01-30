ten_things = "Apples Oranges Crows Telephone Light Sugar"

print "wait there are not 10 things in that list. let's fix that"

stuff = ten_things.split(' ')
more_stuff = ["Day", "night", "song", "frisbee", "corn", "banana", "girl", "boy" ]

while len(stuff) !=10:
	next_one = more_stuff.pop()
	print "Adding: ", next_one
	stuff.append(next_one)

print stuff	
print stuff[1]
print stuff[-1]
print stuff.pop()
print ' '.join(stuff)
print '#'.join(stuff[3:5])
#' '.join(stuff)