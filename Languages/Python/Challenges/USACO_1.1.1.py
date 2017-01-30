import sys

sys.stdin = open('ride.in', 'r')
sys.stdout = open('ride.out', 'w')

first = raw_input()
second = raw_input()

multiply = 1
for i in first:
	a = ord(i)-64
	multiply *= a 
	multiply = multiply % 47

multiply2 = 1

for i in second:
	a = ord(i)-64
	multiply2 *= a 
	multiply2 = multiply2 % 47
	
if multiply == multiply2:
	print "GO"
else:
	print "STOP"

	
