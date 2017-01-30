import sys

sys.stdin = open('milk2.in', 'r')
sys.stdout = open('milk2.out', 'w')

#matrix = [[0 for i in xrange(5)] for i in xrange(5)]

my_array = []
N = int(raw_input())

largest = 0
smallest = 1000001
for i in xrange(0, N):
	a = raw_input()
	one, two = a.split(' ')
	if int(two) > largest:
		largest = int(two)
	if int(one) < smallest:
		smallest = int(one)
	my_array.append([])
	my_array[i].append(int(one))
	my_array[i].append(int(two))

#for i in xrange(0,N):
#	print my_array[i][0], my_array[i][1]
#print largest 
	
my_list = [True] * 1000001
for i in xrange(0, N):
	for j in xrange(my_array[i][0], my_array[i][1]):
		my_list[j] = False
		
max_true = 0
max_false = 0
prev_i = False
curr_true = 0
curr_false = 0

for i in xrange(smallest, largest):
	#print prev_i, my_list[j], max_true, max_false
	if prev_i == True and my_list[i]== True:
		curr_true+=1;
		curr_false = 0;
		prev_i=True;
		max_true = max(max_true, curr_true)
	elif prev_i == True and my_list[i] == False:
		curr_true = 0;
		curr_false = 1;
		prev_i=False;
		max_false = max(max_false, curr_false)
	elif prev_i == False and my_list[i] == False:
		curr_false+=1;
		curr_true=0;
		prev_i=False;
		max_false = max(max_false, curr_false)
	elif prev_i == False and my_list[i] == True:
		curr_true = 1;
		curr_false = 0;
		prev_i=True;
		max_true = max(max_true, curr_true)

print max_false, max_true
