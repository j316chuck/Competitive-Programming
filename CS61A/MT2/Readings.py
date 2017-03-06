Always make sure to use the constructors and selectors given to you

""" 
trees and lists in 2.3 examples
"""
"""
mark mikasjkasdlka tree problems, in order, post order
"""

"""
immutables
"""
#lists
digits = [1,8,2,8]
len(digits) 
digits[3]
[2,7] + digits * 2

add([2, 7], mul(digits, 2))

pairs = [[10, 20], [30, 40]]

1 in digits

5 not in digits

not(5 in digits)

for element in s:
# for element in s: name bound in first frame of the current environemnt (not a new frame)
#not a new frame at all :) element in s

for <name suite> in <expression>:

	<expression> must be a sequence

	A. Bind <name> to that element
	B. Execute the <suite>

#sequence unpacking
pairs = [[1,2], [2,2], [3, 2], [4,4]]
for x, y  in pairs:
	if x == y:
		same_count = same_count+1

#sequence unpacking

list(range(-2, 2))
[-2, -1, 0, 1]
range(4)
starts with 0-3

#list comprehensions

leters = ['a', 'b', 'c', 'd', 'e', 'f']
[leters[i] for i in [3, 4, 6, 8]]

[<map exp> for <name> in <iter exp> if <filter exp> ]
#a AMEN!!!! :)

[<map exp> for <name> in <iter exp> if <filter exp>]

#map zip, etc. 

[<map exp> for <name> in <iter exp> if <filter exp> ]
[<map exp> if <filter exp> else < map exp> for <name> in <iter exp> ]
add a new frame with current frame as its parent
create an empty result listbind <name> to that element in the new frame from step 1
add the value of <map exp> to the result list!!!

dictionaries:

dictionaries = unordered collectiosn of key-value pairs
2 restrictions 
key cannot be a list or dictionary (no mutable type)
two keys cannot be equal, one value for every keymultiple values with a key store them in a list

map(lambda pair: max(pair), zip(a,b))


map(fn, list)

list comprehensions

lst = map(lambda pair: max(pair), zip(a, b))

zip(a, b)


map(fn, zip(a,b))

reduce(f3, zip(map(f1,seq1), map(f2, seq2))

filter(lambda x: x%2, sequence)
reduce(function, sequence, [initial])

def map(fb, seq):
	return [fn(i) for i in seq]

def filter(fn, seq):
	return [v for v in seq if fn(v)]

def reduce(fn, seq, init):
	r = init	
	for s in seq:
		r = fn(r, s)
	return r

sum, min, max = can be used on list
sum([1, 2, 3])
etc.

del list1[2];

len([1, 2, 3])

for x in [1, 2, 3]: print x

L[-2]
L[1:]

cmp(lst1, lst2)

slicing
digits[0:2]
digits[1:]
digits[::-1]

#strings

str(2)

one_two = [1, 2] 

#trees

t = tree(3, [tree(4), tree(3, [tree(3)])])
[1, [2, 3, [4, [3, 4]] ]
[1, [2], [3, [1], [1]]]
[3, [1], [2, [1, 1]]]

t = tree(3, )etc.

[3, [1], [1, [2], [2]]]

tree(3, [tree(3, tree(3)))

def join_link(s, separator):
	if s == empty:
		return ""
	elif rest(s) == empty:
		return str(first(s))
	else:
		return s.first+separator+join_link(s.rest, separator)

if type(tree)!= list or len(tree) < 1:
	return False

#immutables
immutable values are protected from mutation
turtle = (1, 2, 3)
ooze()
turtle = (1,2, 3)
s = ([1, 2], 3)

#identiy
list is still same list but two lists can have same contents but are different

<exp0> is <exp1>
evalues to true if same object

<exp 0> == <exp 1> 
if values are equal

# local variables
rebind balance in the first non-local frame
nonlocal effect: future assignments to that name change 
first non-local frame fo the current environment in which that name is bound
