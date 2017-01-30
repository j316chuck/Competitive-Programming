def fib(n):
	if n == 1:
		return 1
	if n == 0:
		return 0
	if n>1:
		return fib(n-1)+fib(n-2)

def fib_test():
		assert fib(1) == 1
		assert fib(2) == 1
		assert fib(10) == 67

fib_test()