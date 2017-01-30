from sys import argv #import sys module/library so you can use argv 

script, filename = argv #argv takes the two arguments from the python module and assigns it to the two variables
txt = open(filename) #open's the document and assigns it to the txt variable

print "Here's your file %r: " %filename #prints out the file name
print txt.read() #prints out the txt variable
txt.close()

print "Type the filename again:"  
file_again = raw_input ("> ")#read raw input
#txt_again = open(file_again) #open file name
#print txt_again.read() #read out file
print open(file_again).read()
#txt_again.close()
#file_again.close()
