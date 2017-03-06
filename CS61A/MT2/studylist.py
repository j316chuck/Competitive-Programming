#Everything for Christ
#Everything already Gucci
#Learning first

#Lab

#Midterm check (tonight)

#Discussion sections #all of them 3 hours
#Albert Wu 2 hours #Thursday + Midterm

#Go over concepts unsure/guerilla sections = should be p good 3 hours on Wednesday

#Make a review sheet/unsure = 3 hours
#Thursday 3 practice exams :)

"""class Email:
	def __init__(self, msg, sender_name, recipient_name):
		self.msg = msg
		self.sender_name = sender_name
		self.recipient_name = recipient_name

class Postman:
	def __init__(self):
		self.clients = {}
		
	def send(self, email):

		recipient = email.recipient_name
		self.clients[recipient].receive(email)

	def register_client(self, client, client_name):
		if client_name not in self.clients:
			self.clients[client_name] = client


class Client:
	def __init__(self, mailman, name):
		self.inbox = []
		self.mailman = mailman
		self.name = name
		self.mailman.register_client(self, self.name)

	def compose(self, msg, recipient_name):
		email = Email(msg, self.name, recipient_name)
		self.mailman.send(email)
#never forgot self 
#neverforget to read
	def receive(self, email):
		self.inbox.append(email)

class Pet(object):
	def __init__(self, name, owner):
		self.is_alive = True # It's alive!!!
		self.name = name
		self.owner = owner
	def eat(self, thing):
		print(self.name + " ate a " + str(thing) + "!")
	def talk(self):
		print(self.name)

class Cat(Pet):
	def __init__(self, name, owner, lives = 9)
		Pet.__init__(self, name, owner)
		self.lives = lives

	def talk(self):
		print("MEOW")

	def lose_life(self):
		if self.lives < 1:
			continue
		else:
			self.lives = self.lives-1
			if self.lives == 0:
				self.is_alive = False

class A:
	def f(self):
		return 2
	def g(self, obj, x):
		if x == 0:
			return A.f(obj)
			return obj.f() + self.g(self, x - 1)
class B(A):
	def f(self):
		return 4

def bathtub(n):
	def ducky_annihilator(rate):
		def ducky():
			nonlocal n
			n-=rate
			return n + "rubber duckies left"
		return ducky
	return ducky_annihilartor

def memory(n):

	def f(fn):
		nonlocal n
		n = fn(n)
		print(n)
		return f
	return f

>>> lst2[1] = 42
>>> lst2
>>> lst1 = lst1 + [5]
>>> lst1 == lst2
>>> lst1
>>> lst2
>>> lst2 is lst1
"""

#[[y*2 for y in [x, x+1]]for x in [1, 2, 3, 4]]

def tree(root, branches = []):
	for b in branches:
		assert isTree(b)
	return [root] + list(branches)
def root(tree):
	return tree[0]

def branches(tree):
	return tree[1:]

def is_leaf(tree):
	return not branches(tree)

t = Tree(1, [Tree(2), Tree(3, [Tree(4)])])

def square_tree(t):
	if is_leaf(t):
		return Tree(root(t)**2)
	else:
		return Tree(root(t)**2, [square_tree(b) for b in branches(t)])

def height(t):
	if is_leaf(t):
		return 0
	else:
		return 1+max([height(b) for b in branches(t)])

def tree_max(t):
	if is_leaf(t):
		return t.root
	return max([root(t)] + [tree_max(b) for b in branches(t)])

def find_path(tree, x):
	if root(tree) == x:
		return [root(tree)]
	
	#if is_leaf(tree)
	#	return None
	
	#for b in branches(tree):
	#	if find_path(b, x):
	#		return [root(tree)] + find_path(b, x)
	trees = branches(trees)
	for path in [find_path(t, x) for t in trees]:
		if path:
			return [root(tree)] + path
	#for b in branches(trees):
	# 	if find_path(branches, x):
	# 		return [root(tree)] + find_path(branches, x)
	#return None

def prune(t, k):
	
	if k == 0:
		return Tree(root(t), [])
	else:
		return Tree(root(t), [prune(b, k-1) for b in branches(t)])

def hailstone_tree(n, h)	
	if h == 0:
		return Tree(n)
	#else:
	#	hailtree = hailstone_tree(n, h-1)
	#	nexthailtree = Tree(root(hailtree)*2, branches(hailtree)) 
	#	if (root(hailtree)*2-1) % 3 == 0:
	#		return Tree(root(hailtree), [nexthailtree, Tree(root(hailtree)*3-1, branches(hailtree))])
	#	else:
	#		return Tree(root(hailtree), [nexthailtree]) 
	branches = [hailstone_tree(n*2, h-1)]
	if ((n-1)//3)%2 == 1 and (n-1)//3 > 1:
		branches+=[hailstone_tree((n-1)//3, h-1)]
	return tree(n, branches)

	