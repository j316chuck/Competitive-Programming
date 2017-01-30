#from Ex_45A import Freshman
#from Ex_45A import Sophomore
#from Ex_45A import Senior
#from Ex_45A import Junior
import Ex_45A 
	
class Graduation(object):
	
	def enter(self):
		print "You Finished"
		exit(1)
	
	#def get_name(self):
		return "graduation"

			
class Fail(object):
	
	def enter(self):
		print "You Dropped Out"
		exit(1)
		
	def get_name(self):
		return "failed"

class Engine(object):
	
	def __init__(self, room):
		self.room = room
		#self.next_scene = 0;
	
	def play(self):
	
		while self.room != "Graduation":
			#print self.room
			A = Map(self.room)
			Year = A.next_scene(self.room)
			self.room = Year.enter()
			#print self.room
			if self.room == "Graduation":
				B = Graduation()
				B.enter()
			if self.room == "Fail":
				B = Fail()
				B.enter()
		
		"""
		while self.room!= "Graduation":
			counter+=1;
			self.room = next_place.enter() #sophomore #fail
			A = Map(self.room) #sophomore  
			next_place = A.next_scene(self.room) #sophomore() #fail()
			if self.room == end_room or self.room == "Fail": 
				next_place.enter()
		
		#print self.room 
		#next_place.enter()
		"""
		
	def get_room(self):
		return self.room

class Map(object):
	scenes = {
		"Freshman": Ex_45A.Freshman(),
		"Sophomore": Ex_45A.Sophomore(),
		"Junior": Ex_45A.Junior(),
		"Senior": Ex_45A.Senior(),
		"Graduation": Graduation()
		#"Failed": Fail()
	}
	
	def __init__(self, start):
		self.start = start
	
	def narrate(self):
		print "This is a game describing your college life"
		print "In the first stage, you are entering freshman year!"
		return 0;
		
	def next_scene(self, scenes):
		return Map.scenes.get(scenes)
	
	def enter(self):
		A = Map(self.start)
		Year = A.next_scene(self.start) 
		B = Engine(self.start)
		#print "You are a", B.get_room()#B.play()
		B.play()
		
	def get_scene(self):
		return self.start
		
A = Map("Freshman")
A.narrate()
A.enter()