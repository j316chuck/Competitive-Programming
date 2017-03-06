class LetterIter:
	def __init__(self, start = 'a', end = 'e'):
		self.next_letter = start
		self.end = end
	def __next__(self):
		if self.next_letter == self.end:
			raise StopIteration
		letter = self.next_letter
		self.next_letter = chr(ord(letter)+1)
		return letter

letter_iter = LetterIter()
letter_iter.__next__()
letter_iter.__next__()
next(letter_iter)

class LettersWithYield:
        def __init__(self, start='a', end='e'):
            self.start = start
            self.end = end
        def __iter__(self):
            next_letter = self.start
            while next_letter < self.end:
                yield next_letter
                next_letter = chr(ord(next_letter)+1)

class Positives:
	def __init__(self)
		self.next_positive = 0
	def __next__(self):
		self.next_positive+=1
		return self.next_positive


caps = map(lambda x: x .upper(), b_to_k)
next(caps)

def letters_generator():
	current = 'a'
	while current <= 'd':
		yield current
		current = chr(ord(current)+1)

for letter in letters_generator():
	print(letter)


def repeated(t, k):
	assert j  > 1
	n , v = 1 , next(t)
	for i in t:
		if i == v:
			n+=1
			if n == k:
				return v;
			else:
				n, v = 1, i

def letters_generator():
	current = 'a'
	while current <= 'd':
		yield current 

letters = letters_generator()
type(letters)
letters.__next__()

def map_stream(fn, s):
	if s is Stream.empty:
		return s
	def computer_rest():
		return map_stream(fn, s.rest)
	return Stream(fn(s.first), computer_rest)
letters = letters_generator()


def filter_stream(fn, s):
	if s is Stream.empty:
		return s
	def filter():
		return filter_stream(fn, s.rest)
	if fn(s):
		return Stream(s.first, filter) #filter because it is not () becuase u pass in function not value
	else:
		return filter()
#STREAMS
(car (cons 1 2)) #error
(cdr-stream (cons-stream 1 (/ 1 0))) #error
(define (range-stream a b)
	(if (>= a b)
		nil
		(cons-stream a (range-stream (+ a 1) b))
	)
)

(define ones (cons-stream 1 ones))

(define (add-streams s t)
 (cons-stream (+ (car s) (car t))
 	(add-streams (cdr-stream s) (cdr-stream t))
 )


(define (slice stream start end)
	(cond ((or (null? stream) (= end 0)) nil)
	((> start 0) (slice (cdr-stream stream) (-start 1) (- end 1)))
	(else (cons (car stream) (slice (cdr-stream) 0 (- end 1))) )
)
)

(define a (cons-stream 1 (cons-stream 2 (cons-stream 3 a))))