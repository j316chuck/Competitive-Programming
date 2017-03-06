#List functions
digits = [1,8,2,8]
print(len(digits))
print(digits[3])

#sequence unpacking
pairs = [[1,2], [2,2], [2,3], [4,4]]

same_count = 0;

for x, y in pairs:
	if x == y:
		same_count += 1

print(same_count);

#range, underscore

for _ in range(3):
	print("Go Bears");

#List Comprehensions
odds = [1,3,5,7,9]
#[x+1 for x in odds]
#print(odds)

print([x for x in odds if 25%x == 0])
print(odds)

#Aggregation sum, min, max = aggregation

#apply_to_all = lambda map_fn, s:list(map(map_fn, s
#keep_if = lambda filter_fn, s: list(filter(filter_fn, s))

#membership
2 in digits
1828 not in digits
#slicing
digits[0:2]
digits[1:]
digits[1:-1]
digits.append(3)
digits.extend([3, 4])
digits.insert(0, 3)
print(digits)

#in list
'c' in digits
digits.index(3)
print(digits.count(3))

#removing

digits.pop(1)
digits.pop()
del digits[0]
digits.remove(3)
print(digits)
#binarytree

#def right_binarize(tree):

# strings

print('here' in "Where's waldo?")

str(2)+"is a digit of "+str(digits)