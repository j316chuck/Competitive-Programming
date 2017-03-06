(define (map procedure s)
	(define map-reverse s m)(
		(if (null? s)
			m
			(map-reverse (cdr s) (cons (procedure (car s)) m))
		)
	)
	(reverse (map-reverse s nil))
)
(define (reverse s)
	(define (reverse-iter s r)
		(if (null? s)
			r
			(reverse-iter (cdr s) (cons (car s) r))
		)
	)
	(reverse-iter s nil)
)

Pair('+', Pair(1, Pair(2, Pair(Pair('-', Pair(3, Pair(4, nil))), nil))))

(define (fib n) 
	(define (fibo n prev curr)
		(if (= n 1)
			curr
			(fibo (- n 1) curr (+ prev curr))
		)
	)
	(fibo n 0 1)
)

(define (reverse lst)
	(define (reverse-so-far lst curr)
		(if (null? lst) 
			curr 
			(reverse-so-far (cdr lst) (cons (car lst) curr))
		)
	)
	(reverse-so-far lst nil)
)

(define (insert n lst)
	(define (inserts n lst lst-so-far)
		(if null? lst (cons n rev-lst))
		(if (< n (car lst))
			(append (reverse lst-so-far) (cons n lst))
			(inserts n (cdr lst) (cons (car lst) (lst-so-far)))
		)
	)
	(inserts n lst nil)
)

(define (insert n lst)
	(define (rev-insert lst rev-lst)
		(cond ((null? lst) cons n rev-lst)
			((> (car lst) n) (append (reverse lst) (cons n rev-lst)))
			(else (rev-insert (cdr lst) (cons (car lst) (rev-lst))))
		)
	)
	(reverse (rev-insert lst nil))
)

def calc_eval(exp):
	if isinstance(exp, Pair):
		if exp.first == 'and':
			return eval_and(exp.second)
		else:
			return calc_apply(calc_eval(exp.first), list(exp.second.map(calc_eval)))
	elif exp in OPERATORS:
		return OPERATORS[exp]
	else: 
		return exp
def eval_and(operands):
	curr = operands
	last = True
	while curr is not nil:
		first = operands.first
		last = calc_eval(first)
		if last == False:
			reeturn false;
		curr = oprands.second
	return last


d = {'one': 1, 'two': 2, 'three': 3}

iterables = iter(d)
next(iterables)

counts = [1, 2, 3]
items = iter(counts)
try:
	while True:
		item = next(items)
		print(item)
except StopIteration:
	pass 

def plus_minus(x):
	yield x
	yield -x

class Countdown:
	def __init__(self, start):
		self.start = start
	def __iter__(self):
		v = self.start
		while v > 0:
			yield v
			v-=1

def a_then_b(a, b):
	for x in a:
		yield x
	for x in b:
		yield x
def a_then_b(a, b):
	yield from a
	yield from b

def sum_primes(a, b):
	return sum(filter(is_prime, range(a, b)))

(car (cons 1 2))

(car (cons-stream 1 2))
(cdr-stream (cons-stream 1 2))
((cons-stream 1 (cons-steam 2 nil)))
(car (cons-stream 1 2))
(cdr-stream (cons-stream 1 2))

(define (range-stream a b)
	(if (= b a)
		nil
		(cons-stream a (range-stream (+ 1 a) b))
	)
)

(define (int-stream start)
	(cons-stream (+ 1 start) (int-stream (+ 1 start)))
)

(define (scale-stream s k)
	(if (null? s) s
		(cons-stream (* (car s) k) (scale-stream (cdr s) k)) 
	)
)

(define (has-cycle constant s)
	((lambda (slow fast) (cycle-stepper slow fast)) s (cdr-stream s))
	(let ((slow s) (fast (cdr-stream s))) (cycle-stepper slow fast)) 

	(let ((slow s) (fast (cdr-stream s))) (cycle-stepper slow fast))
)
(define (cycle-stepper slow fast)
	(cond ((or (null? fast) (null? (cdr-stream fast))) #f)
	((eq? slow fast) #t )
	(else (cycle-stepper (cdr-stream slow) (cdr-stream (cdr-stream fast)))) 

	)
)

