class nil:
	def __repr__(self):
		return 'nil'
	def __len__(self):
		return 0
	def __getitem__(self, i):
		raise IndexError('Index out of range')
	def map(self, fn):
		return nil

nil = nil()

class Pair:
	def __init__(self, first, second):
		self.first = first
		self.second = second
	def __repr__(self):
		return 'Pair({},{})'.format(self.first, self.second)
	def __len__(self):
		return 1 + len(self.second)
	def __getitem__(self, i):
		if i == 0:
			return self.first
		else:
			return self.second[i-1]
	def map(self, fn):
		return Pair(fn(self.first), self.second.map(fn))

(cons '+' (cons 1 (cons 2 ((cons '-' (Pair (3 (Pair (4 'nil')))) ))))
(+ 1 2 3 4)
(+ 1 (* 2 3))
(Pair ('+', Pair(2, Pair(4, Pair(6, Pair(8, nil))))))
(Pair ('+', Pair(1, Pair(Pair('*', Pair(2, Pair(3, nil))), nil)))

def calc_eval(exp):
	if isinstance(exp, Pair)
elifexp

