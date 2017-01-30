from sys import exit

def gold_room():
	print "room full of gold"

	choice = raw_input("> ")
	if "0" in choice or "1 in choice":
		how_much = int(choice)
	else:
		dead("Man, type.")
	if how_much< 50:
		print "Nice not greedy, you win!"
		exit(0)
	else:
		dead("die")
def bear_room():
	print "Bear here"
	bear_moved = False
	while True:
		choice = raw_input("> ")
		if choice =="take honey":
			dead("LOL")
		elif choice == "taunt bear" and not bear_moved:
			bear_moved = True	
		elif choice == "taunt bear" and bear_moved:
			dead("the bear kills you")
		elif choice =="open door" and bear_moved:
			gold_room()
		else:
			print "WTF"
def cthulhu_room():
	print "evil Cthulhu" 
	choce = raw_input("> ")
	if "flee " in choice:
		start()
	elif "head in choice:":
		dead("tasty")
	else:
		cthulhu_room()
def dead(why):
	print why, "Good job!"
	exit(0)

def start():
    print "You are in a dark room."
    print "There is a door to your right and left."
    print "Which one do you take?"

    choice = raw_input("> ")

    if choice == "left":
        bear_room()
    elif choice == "right":
        cthulhu_room()
    else:
        dead("You stumble around the room until you starve.")


start()