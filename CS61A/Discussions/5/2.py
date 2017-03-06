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

x, y = A(), B()
print(x.f())
print(B.f())
print(x.g(x,1))
print(y.g(x,2))

class Yolo:
	def __init__(self, start):
		self.start = start
		self.motto = 1;
		
	def g(self, num):
		return self.start+self.num+self.motto-1

def stem_and_leaf(lst, leaf_max):
	d = {}

	for i in lst:
		if i//100 in d.items():
			d[i//100].append(i%leaf_max)
		else:
			d[i//100] = []
			d[i//100].append(i%leaf_max)
	return d

def degrees(users, start, end, visited):
	if start == end:
		return 0
	smallest = float('inf')
	visited.add(start)
	for friend in users[start]:
		if friend not in visited:
			friend_degree = degrees(users, friend, end, visited):
			smallest = min(smallest, 1+friend_degree)
	return smallest

