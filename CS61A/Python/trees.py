def tree(root, branches=[]):
    for branch in branches:
        assert is_tree(branch), 'branches must be trees'
    return [root] + list(branches)

def root(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def is_leaf(tree):
    return not branches(tree)

#tree
t = tree(3, [tree(1), tree(2, [tree(1), tree(1)])])
print(t)
print(root(t))
print(branches(t))
print(is_leaf(t))
print(is_leaf(branches(t)[0]))

#fibonacci
def fib_tree(n):
	if n == 0 or n == 1:
		return tree(n)
	else:
		left, right = fib_tree(n-2), fib_tree(n-1);
		return tree(root(left) + root(right), [right, left]);

print(fib_tree(5))

def count_leaves(tree):
	count = 0
	if is_leaf(tree):
		return 1
	else:
		for branch in branches(tree):
			count+= count_leaves(branch) 
	return count

print(count_leaves(fib_tree(5)))

def partition_tree(n, m):
	if n == 0:
		return tree(True)
	elif n < 0 or m == 0:
		return tree(False)
	else:
		left = partition_tree(n-m, m)
		right = partition_tree(n, m-1)
		return tree(m, [left, right])

print(partition_tree(6,4))

def print_parts(tree, partition=[]):
	if is_leaf(tree):
		if root(tree):
			print(' + '.join(partition))
	else:
		left, right = branches(tree)
		m = str(root(tree))
		print_parts(left, partition+[m])
		print_parts(right, partition)

print_parts(partition_tree(6, 4))

"""
def tree(root, branches=[]):
	for branch in branches:
		assert is_tree(branch), 'branches must be trees'
	return [root] + list(branches) 
def root(tree):
	return tree(0)
def branches(tree):
	return tree[1:]
def is_leaf(tree):
	return not branches(tree)
def is_tree(tree):
	if len(tree) < 1 or type(tree)!=list:
		return False
	for branch in branches(tree):
		if not is_tree(branch):
			return False
	return True

def fib_tree(n):
	if n == 0 or n==1:
		return tree(n)
	else:
		right, left = fib_tree(n-1), fib_tree(n-1)
		return tree(root(right)+root(left), [right, left])
print(fib_tree(5))
"""