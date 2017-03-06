def remove_duplicates(lnk):
	if lnk == Link.empty or lnk.rest == Link.empty:
		return lnk
	elif lnk.first == lnk.rest.first:
		lnk.rest = lnk.rest.rest
		remove_duplicates(lnk)
		return lnk
	else:
		remove_duplicates(lnk.rest)
		return lnk
def reverse(lnk):
	#WATCH THE solution VIDEO
	""""def new_link(new, old):
		if old is Link.empty:
			return 
		else:
			return Link(lnk.first, new)
	new_link(Link(lnk.first), lnk)"""
	if lnk == Link.empty or lnk.rest == Link.empty:
		return lnk
	rest_rev = reverse(lnk.rest)
	lnk.rest.rest = lnk
	lnk.rest = Link.empty
	return rest_rev

def multiply_lnks(Lst_of_lnks):
	product = 1;
	for lnk in lst_of_lnks:
		if lnk is Link.empty:
			return Link.empty:
		else:
			product*=lnk.first
			
	return Link(product, multiply_lnks([lnk.rest for lnk in lst_of_lnks]))


def foo(lst):
	return [i*lst[i] for i in range(len(lst)) if i % 2 == 0]

def max_product(lst):
	#if lst == []:
	#	return 1
	#return max([lst[i] * max_product(lst[i+2:]) for i in range(len(lst))]):
	if lst == []:
		return 1
	elif len(lst) == 1:
		return lst[0]
	else:
		return max(lst[0]*max_product(lst[2:]), max_product(lst[1:]))
"""
6 5 4 3 2 1

6 1 2 3 4 5
6 1 6 1 2 3 4 5	

123456

1 2 3 

reverse (2, 3)
(2)
reverse(2, 3)

rest_rev = Link(3)
lnk.rest.rest = Link(2)
lnk = Link(2, ())
return rest_rev = Link(3)
reverse (3)
return 3
"""

def eval_tree(tree):
	if is_leaf(tree):
		return root(tree)
	#else:
	#	return reduce(tree.root, [eval_tree(b) for b in branches(tree)])
	if root(tree) == '+':
		return sum([eval_tree(b) for b in branches(tree)])
	elif root(tree) == '*':
		return prod([eval_tree(b) for b in branches(tree)])

def quisort_list(lst):
	#if all([lst[i] <= lst[i+1] for i in range(0, len(lst)-1)]):
	#	return lst:
	#pivot = lst[0]
	#less = [b for b in lst if b <= pivot]
	#greater = [b for b in lst if b > pivot]
	#return less + [pivot] + greater
	if len(lst) <= 1:
		return lst

	pivot = lst[0]
	less = [b for b in lst[1:] if b <= pivot]
	greater = [b for b in lst[1:] if b > pivot]

def quicksort_link(link):
	if link is Link.empty or link.rest is Link.empty
		return link
	pivot, link = link, link.rest
	less, greater = Link.empty, Link.empty
	while link is not Link.empty:
		curr, rest = link, link.rest
		if curr.first < pivot.first:
			less, curr.rest = curr, less
		else:
			greater, curr.rest = curr, greater
		link = rest
	less = quicksort_link(less)
	greater = quicksort_link(greater)
	return Link(less, Link(pivot, greater))
