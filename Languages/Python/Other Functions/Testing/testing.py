#from doctest import testmod
#from doctest import run_docstring_examples

def sum_naturals(n):
	"""

	>>> sum_naturals(10)
	55
	>>> sum_naturals(100)
	5050
	"""
	total, k = 0, 1
	while k <= n:
		total, k = total + k, k + 1
	return total


#testmod()
#run_docstring_examples(sum_natural, globals(), True)
#run_docstring_examples(func_name, globals(), True)

#on python command line py -3 -m doctest <sourcefile> #testing.py