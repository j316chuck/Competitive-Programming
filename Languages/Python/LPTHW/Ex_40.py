class Song(object):
	def __init__(self, lyrics):
		self.lyrics = lyrics
	
	def sing_me_a_song(self):
		for line in self.lyrics:
			print line

list = ["Happy Birthday to you", 
		" I don't want to get sued", 
		"So I'll stop right there"]			

happy_bday = Song(list)	

bulls = Song(["They rally around tha family",
				"With pockets full of shells"])

happy_bday.sing_me_a_song()

bulls.sing_me_a_song()