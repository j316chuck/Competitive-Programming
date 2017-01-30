tabby_cat = "\tI'm tabbed in %s and %s"
persian_cat = "I'm split \non a line"
backslash_cat = "I'm \\ a \\cat"

fat_cat = """
I'll do a list:
\t* Cat food
\t* Fishies
\t* Catnip\n\t* Grass
"""

print tabby_cat %("a tree", "a forest")
print persian_cat
print backslash_cat
print fat_cat

#while True:
#	for i in ["/", "-", "|"]:
#		print"%s\r" %i,

print "%s"