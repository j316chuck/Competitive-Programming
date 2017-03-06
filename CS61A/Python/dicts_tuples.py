#tuple = immutable

("the", 1, "and", "only")
()
(10, )

code = ("up", "up", "down", "down") + ("left") * 2;
len(code)
code.count("down")

#can't change value

#can change mutable value inside
#for instance
nest = (10, 20, [30, 40])
nest[2].pop()
print(nest)

#dictionaries, key value pairs

numerals = {'I':1, 'V': 5, 'X': 10}
print(numerals['X'])
#unordered so may be added to end of output

#interable values = .value.keys. iterms
sum(numerals.value)
sum(numerals.items)

dict([(3,9), (4, 16)])

#key of dictionary cannot be mutable
#can be at most one value for given key. 

numerals.get('A', 0) # 0 default value
numerals.get('V', 0) # 5 real value
#why are we learning dicts already loool gg rip cs61a kids hahahahaha

