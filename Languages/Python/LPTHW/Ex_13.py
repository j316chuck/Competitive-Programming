#from sys import argv

#script, first, second, third = argv
#print "The script is called:", script
#print "Your first variable is:", first
#print "your second variable is:", second
#print "your third variable is:", third

from sys import argv

script, one, two, three, four = argv
five = raw_input("fifth number is:")

print "%s %s %s %s %s" %(script, one, two, three, four,), five
