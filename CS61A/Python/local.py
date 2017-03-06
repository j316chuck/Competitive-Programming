from datetime import datetime
#tues = date(2014, 5, 13) #date = bound to class tues = instance
# <expression>.<name> attributes = name
# expression = object
# objects also have methods which are function-valued attributes
chinese = ['coin', 'string', 'myriad']
suits = chinese

suits.pop()
suits.remove('string')
suits.append('cup')
suits.extend(['sword', 'club'])
print(suits)
print(chinese)

"""a = 6;
a = a+1;
print(a)
s = "alskdjalks";
b = s+"a"
print(s)
print(b)
#can't delete stuff ins tring

print(b)
print(s)"""

#lists are mutable only lists are mutable
#dicts, tuples, and ints, and floats, and strings are not mutable not mutable

nest = list(suits) #creates separate variable
nest[0] = suits
suits.insert(2, 'Joker')
print(nest)

#is tests whether or not the two objects point to the same part
print(suits is nest[0]) #true because they are the same object
print(suits is ['heart', 'diamond', 'spade', 'club']) #false because not pointing to same object
print(suits == ['heart', 'diamond', 'spade', 'club']) #true values are equal

#is checks for identity, while == checks for equality of contents, one looks at where it is the other checks contents lol

#nonlocal
def make_withdraw(balance):
	def withdraw(amount):
		nonlocal balance
		if amount > balance:
			return 'Insufficient'
		else:
			balance = balance - amount
			return balance
		return withdraw