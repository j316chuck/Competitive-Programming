#four = [1, [2, [3, [4, 'empty']]]]

empty = 'empty'

def is_link(s):
	return s == empty or (len(s) == 2 and is_link(s[1]))

def link(first, rest):
	assert is_link(rest), "rest must be a linked list."
	return [first, rest]

def first(s):
	assert is_link(s), "first only applies to linked lists"
	assert s != empty, "empty linked list has no first element"
	return s[0]

def rest(s):
	assert is_link(s), "first only applies to linked lists"
	assert s != empty, "empty linked list has no first element"
	return s[1]

def len_link(s):
	length = 0
	while s!= empty:
		length+=1
		s = rest(s)
	return length

def getitem_link(s, i):
	while i > 0:
		s = rest(s)
		i = i-1
	return first(s)

four = link(1, link(2, link(3, link(4, empty))))
print(first(four))
print(rest(four))
print(len_link(four))
print(getitem_link(four, 1))

def recursive_len(s):
	if s == empty:
		return 0
	else: 
		return 1 + recursive_len(rest(s))

def recursive_getitem(s, i):
	if i == 0:
		return first(s)
	else:
		return recursive_getitem(rest(s), i-1)

print(recursive_len(four))
print(recursive_getitem(four, 1))

def extend_link(s, t):
	assert is_link(s) and is_link(t)
	if s == empty:
		return t
	else:	
		return [first(s), extend_link(rest(s), t)]	
	
print(extend_link(four, four))

def apply_to_all_link(f, s):
	if s == empty:
		return empty
	else:
		return[f(first(s)), apply_to_all_link(f, rest(s))]

print(apply_to_all_link(lambda x: x*x, four))

def keep_if_link(f,s):
	assert is_link(s)
	if s == empty:
		return empty
	elif f(first(s)):
		return [first(s), keep_if_link(f, rest(s))]
	else:
		return keep_if_link(f, rest(s))

print(keep_if_link(lambda x: x%2 == 0, four))

def join_link(s, separator):
	if s == empty:
		return ""
	elif rest(s) == empty:
		return str(first(s))
	else:
		return str(first(s))+separator+join_link(rest(s), separator)

print(join_link(four, ', '))

def partitions(n, m):
	if n == 0:
		return link(empty, empty)
	elif n < 0 or m == 0:
		return empty
	else:
		using_m = partitions(n-m, m)
		with_m = apply_to_all_link(lambda s: link(m, s), using_m)
		without_m = partitions(n, m-1)
		return extend_link(with_m, without_m)

print(partitions(4, 6))

def print_partitions(n, m):
	lists = partitions(n, m)
	strings = apply_to_all_link(lambda s: join_link(s, "+"), lists)
	print(join_link(strings, "\n"))

print(print_partitions(6, 4))