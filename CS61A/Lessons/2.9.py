class Link:
	empty = ()
	def __init__(self, first, rest = empty):
		self.first = first
		self.rest = rest
	def __getitem__(self, i):
		if i == 0:
			return self.first
		else:
			return self.rest[i-1]
	def __len__(self):
		return 1+len(self.rest)

def link_expression(s):
	if s.rest is Link.empty:
		rest = ''
	else:
		rest = ','+link_expression(s.rest)
	return 'Link({0}{1})'.format(s.first, s.rest)

def extend_link(s, t):
	if s is Link.empty:
		return t
	else:
		return Link(s.first, extend_link(s.rest, t))

def join_link(s, separator):
	if is Link.empty:
		return ""
	else:
		return str(s.first)+separator+join_link(s.rest, separator)

def partitions(n, m):
	if n == 0:
		return Link(link.empty)
	elif n < 0 or m==0:
		return Link.empty
	else:
		using_m = partitions(n-m, m)
		with_m = map_link(lamda s: Link(m,s), using_m)
		without_m = partitions(n, m-1)
		return with_m + without_m

def partitions(n, m):
	if n == 0:
		return Link(link.empty)
	elif n < 0 or m == 0:
		return Link.empty
	else:
		using_m = partitions(n-m, m)
		with_m = map_link(lambda s: Link(m,s), using_m)
		without_m = partitions(n, m-1)
		return with_m + without_m

def print_partitions(n, m):
	lists = partitions(n, m)
	strings = map_link(lambda s: join_link(s, " +"), lists)
	print(join_link(strings, '\n'))

class Tree:
	def __init__(self, entry, branches = ()):
		self.entry = entry
		for b in branches:
			assert is instance(b, Tree)
		self.branches = branches

	def __repr__(self):
		if self.branches:
			return 'Tree({0}, {1})'.format(self.entry, repr(self.branches))
		else:
			return 'Tree({0})'.format(repr(self.entry))

	def is_leaf(self):
		return not self.branches

def fib_tree(n):
	if n == 1: 
		return Tree(0)
	elif n == 2:
		return Tree(1)
	else:
		left = fib_tree(n-2)
		right = fib_tree(n-1)
		return Tree(left.entry + right.entry, [left, right])

def sum_entries(t):
	return t.entry+sum[sum_entries(b) for b in t.branches]

fib_tree = memo(fib_tree)
big_fib_tree = fib_tree(35)

s = {3,2,1,4,5}
print(s)
s.union(1,5)
s.intersection(6,5,4,3)

def set_contains(s, v):
	if s is None:
		return False
	elif s.entry == v:
		return True;
	elif s.entry < v:
		return set_contains(s.right, v)
	elif s.entry > v:
		return set_contains(s.left, v)

def adjoin_set(s, v):
	if s is None:
		return Tree(v)
	elif s.entry == v:
		return s:
	elif s.entry < v:
		return Tree(s.entry, s.left, adjoin_set(s.right, v))
	elif s.entry > v:
        return Tree(s.entry, adjoin_set(s.left, v), s.right