#close -- Closes the file. Like File->Save.. in your editor.
#read -- Reads the contents of the file. You can assign the result to a variable.
#readline -- Reads just one line of a text file.
#truncate -- Empties the file. Watch out if you care about the file.
#write('stuff') -- Writes "stuff" to the file.

from sys import argv

script, filename = argv
print "We're going to erase %r." % filename
print "If you don't want that, hit CTRL-S (^C)."
print "If you do what that, hit RETURN."

raw_input("?")

print "Opening the file..."
target = open(filename, 'w')

print "Truncating the file. Goodbye!"
target.truncate()

print "Now I'm going to ask you for three lines."
line1 = raw_input("Line 1:")
line2 = raw_input("Line 2:")
line3 = raw_input("Line 3:")

print "I'm going to write these to a file"

target.write("%s\n %s\n %s\n" %(line1, line2, line3))

target.close()

