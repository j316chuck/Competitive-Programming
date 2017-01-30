import math

def isPrime(a):
	prime = True
	num = 2
	while num <= int(math.sqrt(a)):
		if(a % num == 0):
			prime = False
			return prime
		num+=1
	
	return prime


a = raw_input('Enter your number: ')
a = int(a)
n = int(math.sqrt(a))
for i in range (2, n+1):
	if a % i == 0:
		print "Is not prime"
		break
	if i == n:
		print "Is prime"

print isPrime(a)

