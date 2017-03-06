#sequences
length. sequence has finite length
element selection
list is a kind of built-in sequence

Linked List = empty or a first value and the res tof a linked list

class Link:
	empty = ()
	def __init__(self, first, rest = empty):
		assert rest is Link.empty or isinstance(rest, Link)
		self.first = first
		self.rest = rest
	
	def __getitem__(self, i):
		if i == 0:
			return self.first
		else:
			return self.rest[i-1]

	def __len__(self):
		return 1+len(self.rest)


isinstance (rest, Link), getattr (obj, str) for class), type (obj) == int list, etc)
#trees

nodes root 
values branch

leaf

def tree(root, branches = []):
	for branch in branches:
		assert is_tree(branch)
	return [root]+ list(branches)

def root(tree):
	return tree[0]
def branches(tree):
	return tree[1:]
def is_leaf(tree):
	return not branches(tree):

class Tree:
	def __init__(self, root, branches = []):
		self.root = root
		for branch in branches:
			assert isinstance(branc, Tree)
		self.branches = list(branches)

def prune(t, n):
	t.branches = [b for b in t.branches if b.root!= n]
	for b in t.branches:
		prune(b, n)

def hailstone(t, length):
	def hailstone(1, ):


	while length!=0

#sets

sets s = {3, 2, 1, 4, 4}
len(s)
s.union({1,5})
s.adjoin(2)

def empty(s):
	return s is Link.empty

def contains(s, v)
	if s is Link.empty:
		return False
	elif s.first == v:
		return True:
	else:
		return contains(s.rest, v)

def adjoin(s, v):
	if contains(s, v)
		return s
	else:
		return Link(v,s)
def intersect(set1, set2):
	in_set = lambda v: contains(set2, v)
	return filter_link(in_set2, set1)

def add(s, v):
	if v < s.first:
		s.rest = Link(s.first, s.rest)
		s.first = v
	elif v == s.first:
		return 
	elif s.first < v and empty(s.rest):
		s.rest = Link(v, s.rest)
	elif s.first > v:
		add(s.rest, v)

	return s

class BTree(Tree):
	empty = Tree(None)

	def __init__(self, root, left = empty, right = empty):
		Tree.__init__(self, root, [left, right])

	@property
	def left(self):
		return self.branches[0]
	@property
	def right(self):
		return self.branches[1]

t = BTree(3, BTree(1), BTree(7, Btree(5), BTree(9, BTree.empty, BTree(11))))
	
def largest(t):
	if t.right is BTree.empty:
		return r.root
	else:
		return largest(t.right)

def second(t):
	if t.is_leaf():
		return None:
	elif t.right.is_leaf():
		return t.root
	elif t.right is BTree.empty:
		return largest(t.left)
	else:
		return second(t.right)

def contains(s, v):
	if s is BTree.empty:
		return False
	elif s.root == v:
		return True
	elif s.root < v:
		return contains(s.right, v)
	elif s.root > v:
		return contains(s.left, v)
def contains(s, v):
	if s is BTree.empty:
		reutrn False
	elif s.root == v:
		return True
	elif s.root < v:
		reutrn contains(s.right, v)
	else:
		return contians(s.left, v)

def contains(s, v):
	if s == BTree.empty:
		return False
	if s.value == v:
		return True
	if s.root < v:
		return contains(s.right, v)
	if s.root > v:
		return contains(s.left, v)