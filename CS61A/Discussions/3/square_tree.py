#constructor
def tree(root, branches=[]):
	return [root] + list(branches)
#selectors

def root(tree):
	return tree[0]
def branches(tree):
	return tree[1:]
def is_leaf(tree):
	return not branches(tree)

def square_tree(t):
	#if is_leaf(t):
	#	return tree(root(t)*root(t))
	#else:
		for i in branches(t):
			return tree(root(t)*root(t) + list(square_tree(i)))
			#tree(root(t)**2, [square_tree(b) for b in branches(t)])

def height_tree(t):
	if is_leaf(t):
		return 0;
	#height = 0;
	#for i in branches(t):
	#	height = max(height_tree(t), height)
	#eturn 1+height
	return 1 + max([height(b) for b in branches(t)])

def tree_max(t):
	if is_leaf(t):
		return root(t)

	return max([root(t)]+tree_max(b) for b in branches(t))

def tree_max(t):
	if is_leaf(t):
		return root(t)
	return max([root(t)]+[tree_max(b) for b in branches(t)])

def find_path(tree, x):
	if root(tree) == x:
		return x
	#if is_leaf(tree)!= x:
	#	return None
	paths = [find_path(b) for b in branches(tree)]
	for p in paths:
		if p:
			return [root(tree)+p]

	#find_path(b) for b in branches(tree)
