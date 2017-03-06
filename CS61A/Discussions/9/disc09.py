def combiner(iterator1, iterator2, combiner):
	while True:
		one = next(iterator1)
		two = next(iterator2)
		yield combiner(one, two)
	

combiner(nats, nats, add)


def generate_subsets():
	lst = [[]]
	curr = 0
	while True:
		yield lst
		curr+=1
		new_lst = lst + [x+[curr] for x in lst[:]]:

(define (map-stream f s)
	(if (null? s)
		s
		(cons-stream (f(car s)) (map-stream f (cdr-stream s)))
	)
)
(define (range-stream start end)
	(if (eq? end start) nil
		(cons-stream start (range-stream (+ 1 start ) end))

	)
)

(define (slice stream start end)
	(cond
		((null? stream ) stream)
		((> start 0) (slice (cdr-stream stream) (- 1 start) (- 1 end)))
		((and (= start 0) (> end 0)) (cons (car stream) (slice (cdr-stream stream) 0 (- 1 end))))
		(else nil)
	)
)

(define (zip-with f xs ys)

)
(define factorials
	(zip-with * naturals ones)
)

(define fibs
	(cons-stream 1 (zip with + ))
)

