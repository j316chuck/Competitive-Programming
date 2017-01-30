import sys

sys.stdin = open('wormhole.in', 'r')
sys.stdout = open('wormhole.out', 'w')

def Recurse(car, list, used):
	if len(list)!=0:
		for i in list:
			for j in list:
				if i == j or i in used or j in used:
					continue
				else:
					pair = [list[i], list[j]]
					car.append(pair)
					used.append(list[i])
					used.append(list[j])
					Recurse(car, list, used)
	elif len(list)==0:
		for i in car:
			print "1st: ", car[i][0][0], car[i][0][1], "2nd: ", car[i][1][0], car[i][1][1]
			
#def Repeat()

N = int(raw_input())
mylist = []

for i in range(0, N):
	a, b = raw_input().split()
	pair = [int(a), int(b)]
	mylist.append(pair)
	
#for i in range(0, N):
#	print mylist[i][0], mylist[i][1]

car = []
used = []
Recurse(car, mylist, used)
