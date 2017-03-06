def factorial(n):
	if n == 0 or n == 1:
		return 1
	else:
		return n * factorial(n-1)

def multiply(m, n):
	if n == 1:
		return m;
	else:
		return m + multiply(m, n-1)

def countdown(n):
	print(n) #countup if print(n-(n-1))
	if n == 1:
		return
	else:
		countdown(n-1)

def sum_digit(n):
	if n < 10:
		return n
	else:
		return n % 10 + sum_digit(n//10)

def fibonacci(n):
	if n == 0:
		return 0
	elif n == 1:
		return 1
	else:
		return fibonacci(n-1) + fibonacci(n-2)

def count_stairs(n):
	if n == 2:
		return 2
	elif n == 1:
		return 1
	else:
		return count_stairs(n-1) + count_stairs(n-2)

def count_k(n, k):
	if n < 0:
		return 0
	if n == 0:
		return 1
	if n == 1:
		return 1;
	if n == 2:
		return 2;
	if n > 2:
		ways = 0;
		for i in range(1, k+1):
			ways += count_k(n-i, k)
			#print(n-i, k, ways)
		return ways
"""
print(factorial(6))
print(sum_digit(123))
print(multiply(3, 4))
print(countdown(12)) 
print(fibonacci(10))
print(count_stairs(10))
"""
print(count_k(10, 3))