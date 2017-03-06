strings represent language and programs

str: legible to humans (no '', try to display normally)
repr: legible to the Python interpreter
often the same but not always

eval(repr(object)) == object

12e12
120000.0

repr(half)
'Fraction(1,2)'
str(half)
'1/2'

print(half)
1/2
<string> function

half.__repr__()
'Fracition(1,2)'
half.__str__()


__init__ invoked whenever object is constructed
__str__ invoked when printing No quotes
__repr__ invoked when interactive session used has quotes
__bool__ to determine truth value
__call__(self, k) behaves like a higher order function

can be called by

__.__bool__ or bool(__)
'Go Bears!'[3]
'Go Bears'.__getitem__(3)

repr invoked in iteractive session has quotes
print no quotes used in printing str

