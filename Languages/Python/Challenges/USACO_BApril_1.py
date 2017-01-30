import sys

sys.stdin = open('paint.in', 'r')
sys.stdout = open('paint.out', 'w')

one = raw_input()
two = raw_input()
a , b = one.split(' ')
a = int(a)
b = int(b)
c , d = two.split(' ')
c = int(c)
d = int(d)
#print a, b, c, d
my_list = [True] * 101
for i in xrange(0, 101):
	if i >= a and i < b :
		#print i, a, b, c, d
		my_list[i] = False
	elif i >= c and i < d :
		my_list[i] = False
		
num = 0
for i in xrange(0,101):
	if my_list[i] == False:
		#print my_list[i]
		num += 1 
	
print num
#"""