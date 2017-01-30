things = ['a', 'b', 'c', 'd']
print things [1]

things[1]='z'
print things[1]

stuff = {'name': 'Zed', 'age':39, 'height': 6*12+2}
print stuff['name']

print stuff['height']

stuff['city'] = "San Francisco"
print stuff['city']
stuff[1] = "wow"
stuff[2] = "Neato"

print stuff[1]
print stuff[2]
del stuff['city']
del stuff[1]
stuff

states = {
	'Oregon' : 'OR', 
	'Florida': 'FL', 
	'California': 'CA', 
	'New York': 'NY',
	'Michigan': 'MI'
}

cities = {
	'CA': 'San Francisco',
	'MI': 'Detroit',
	'FL': 'Jacksonville'
}

cities['NY'] = 'New York'
cities['OR'] = 'Portland'

print '-' * 10
print "NY State has: ", cities['NY']


print '-'*10
print "Abbreviation", states['Michigan']


print cities[states['Michigan']]

for abbrev, city in cities.items():
	print "%s has the city %s" %(abbrev, city)

	for state, abbrev in states.items():
		print "%s state is abbreviated %s and has city %s" %(state, abbrev, cities[abbrev])
		
	
state = states.get('Texas')
if not state:
	print "Sorry, no Texas."
	
city = cities.get('Tx', 'Does Not Exist')
print "the city for the state 'TX' is: %s" % city