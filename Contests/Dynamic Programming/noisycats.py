class Cat(Pet):
		def __init__(self, name, owner, lives = 9):
			Pet.__init__(self, name, owner)
			self.lives = lives
			#self.is_alive = True
		def talk(self):
			print("A cat says meow!")
		def lose_life(self)

			self.lives = self.lives -1
			if self.lives == 0:
				self.is_alive = False;



2
4
4
