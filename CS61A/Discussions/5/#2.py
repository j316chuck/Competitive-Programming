class Email:
	def __init__(self, msg, sender_name, recipient_name):
		self.msg = msg
		self.sender_name = sender_name
		self.recipient_name = recipient_name

class Postman:
	def __init__(self):
		self.clients = {}

	def send(self, email):
		self.clients[email.recipient_name].receive(email)

	def register_client(self, client, client_name):
		self.clients[client_name] = client

class Client:
	def __init__(self, mailman, name):
		self.inbox = []
		self.mailman = mailman
		self.mailman.register_client(self, self.name)
		self.name = name

	def compose(self, msg, recipient_name):
		myemail = Email(msg, self.name, recipient_name)
		self.mailman.send(myemail)

	def receive(self, email):
		self.inbox.append(email)

class Pet(object):
	def __init__(self, name, owner):
		self.is_alive = True
		self.name = name
		self.owner = owner
	def eat(self, thing):
		print(self.name + " ate a " + str(thing) + "!")
	def talk(self):
		print(self.name)

class Dog(Pet):
	def __init__(self, name, owner, color):
		Pet.__init__(self,  name, owner)
		self.color = color
	def talk(self):
		print(self.name + ' says woof! ')

class Cat(Pet):
	def __init__(self, name, owner, lives = 9):
		Pet.__init__(self, name, owner)
		self.lives = lives
	def talk(self):
		print("Meow")
	def lose_life(self):
		if self.lives == 0:
			self.is_alive = False
		else:
			self.lives-=1

class NoisyCat(Cat):
	#def __init__(self, name, owner, lives = 9): 
	def talk(self):
		print("Meow Meow")

class A:
	def f(self):
		return 2
	def g(self, obj, x):
		if x == 0:
			return A.f(obj)
		return obj.f()+self.g(self, x-1)

class B(A):
	def f(self):
		return 4

