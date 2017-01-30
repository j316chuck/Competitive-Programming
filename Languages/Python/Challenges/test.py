def pal(a):
	if str(a) == str(a)[::-1]:
		return True
	else:
		return False
	
print pal("1001")