class Tree(object):
	def __init__(self, entry, left = None, right = None):
		self.entry = entry
		self.left = left
		self.right = right

def flip_tree(tree):
	
	#if tree.left == None or tree.right == None:
	#	return tree 
#
#	for b in [tree.left, tree.right]
#		flip_tree(b)
#
#	tree.left, tree.right = tree.right, tree.left
	if tree is None:
		return 
	tree.left, tree.right = tree.right, tree.left
	flip_tree(tree.left)
	flip_tree(tree.right)

def in_order_traversal(tree):
	if tree is None:
		return 
	in_order_traversal(tree.left)
	print(tree.entry)
	in_order_traversal(tree.right)

remember in_order_traversal does not return anything so you cannot print in_order_traversal

def pre_order_traversal(tree):
	if tree is None:
		return 
	print(tree.entry)
	pre_order_traversal(tree.left)
	pre_order_traversal(tree.right)

def post_order_traversal(tree):

	if tree is None:
		return 
	post_order_traversal(tree.left)
	post_order_traversal(tree.right)
	print(tree.entry)

def insert(item, tree)
	if tree is None:
		return 

	"""elif item < tree.entry:
		if tree.left is None:
			tree.left = Tree(item)
		elif tree.left.entry <= item:
			tree.left = Tree(item, tree.left, None)
		else:
			insert(item, tree.left)
	elif item >= tree.entry:
		if tree.right is None:
			tree.right = item
		elif tree.right.entry <=item:
			tree.right = Tree(item, tree.right, None)
		else:
			insert(item, tree.right)
	"""
	elif item < tree.entry:
		if tree.left:
			insert(item, tree.left)
		else:
			tree.left = Tree(item)

def tree_to_reversed_list(tree):
	if tree is None: #Tree.empty List.empty
		return []
	else:
		return tree_to_reversed_list(tree.right)+[tree.entry]+ tree_to_reversed_list(tree.left)
	lst = []
	if tree is not None:
		if tree.right:
			lst.extend(tree_to_reversed(tree.right))
		lst.append(tree.entry)
		if tree.left:
			lst.extend(tree_to_reversed(tree.left))
	return lst

def is_binary_search_tree(tree):
	if tree is None:
		return True
	elif tree.left is None:
		if tree.right is None:
			return True
		elif tree.right > tree.entry:
			return True
		else:
			return False
	elif tree.right is None:
		if tree.left is None:
			return True
		elif tree.left > tree.entry:
			return True
		else:
			return False
	return tree.left < tree.entry and tree.right > tree.entry and is_binary_search_tree(tree.left) and is_binary_search_tree(tree.right)

def append_rlist_iter(a, b):
	if a is rlist.Empty:
		return b
	else:
		return Rlist(a.first, append_rlist_iter(a.rest, b))

def mutating_reverse(rlist):
	if rlist.rest is Rlist.empty:
		return 
	if rlist.rest is not Rlist.empty
		item = pop(rlist)
		reverse(rlist)
		rlist = insert(item, rlist)

	def pop(rlist):
		if rlist.rest.rest is Rlist.empty:
			item = rlist.rest.first
			rlist.rest = empty
			return item
		return pop(rlist.rest)
	def insert(item, rlist):
		rlist.first = item
		rlist.second = Rlist(rlist.first, rlist.rest)
