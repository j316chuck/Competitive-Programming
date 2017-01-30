import operator 
import sys

sys.stdin = open('milk.in', 'r')
sys.stdout = open('milk.out', 'w')

a, b= raw_input().split()
a = int(a)
b = int(b)
#print a 

list = []
for i in range(0, b):
	c, d = raw_input().split()
	
	list.append([int(c), int(d)])

#for i in range(0, a):
#	print list[i][0], list[i][1]

list.sort(key = lambda x: x[0])

#for i in range(0, b):
#print list[i][0], list[i][1]

sum = 0
cost = 0
#print a 
for i in range(0, len(list)):
	if sum >= a:
		cost = cost-((sum-a)*list[i-1][0])
		#print sum-a, list[i][0]
		break
	elif sum < a:
		cost = cost+list[i][1]*list[i][0]
		sum += list[i][1]
		#print list[i][1], list[i][0], sum, cost
		
print cost



	
		
