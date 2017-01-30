import sys

def base (i, b):
	res = ""
	while i!=0:
		a = i%b
		if a==0:
			res+='0'
		elif a==1:
			res+='1'
		elif a==2:
			res+='2'
		elif a==3:
			res+='3'
		elif a==4:
			res+='4'
		elif a==5:
			res+='5'
		elif a==6:
			res+='6'
		elif a==7:
			res+='7'
		elif a==8:
			res+='8'
		elif a==9:
			res+='9'
		elif a==10:
			res+='A'
		elif a==11:
			res+='B'
		elif a==12:
			res+='C'
		elif a==13:
			res+='D'
		elif a==14:
			res+='E'
		elif a==15:
			res+='F'
		elif a==16:
			res+='G'
		elif a==17:
			res+='H'
		elif a==18:
			res+='I'
		elif a==19:
			res+='J'
		i = i/b
		#print res
		if i == 0:
			res = res[::-1]
			return res

def pal(a):
	if str(a) == str(a)[::-1]:
		return True
	else:
		return False
	
#print pal("1001")
sys.stdin = open('palsquare.in', 'r')
#sys.stdout = open('palsquare.out', 'w')

N = int(raw_input())

for i in range(1,301):
	a = base(i, N)
	c = base(i*i, N)
	if pal(c) == True:
		print a, c
		

