(define (find s predicate)
  'YOUR-CODE-HERE
  (cond
  	((null? s) #f)
  	((predicate(car s)) (car s))
  	(else (find (cdr-stream s) predicate))
  )
)

(define (scale-stream s k)
  'YOUR-CODE-HERE
  (if (null? s) s
  	(if (number? (car s))
  		(cons-stream (* k (car s)) (scale-stream (cdr-stream s) k))
  		(cons-stream (scale-stream (car s) k) (scale-stream (cdr-stream s) k))
  	)
  )
)

(define (has-cycle s)
  'YOUR-CODE-HERE
  'memeq'
  	(define (checkequal a b)
	  	(cond 
	  		((number? a) #f)
	  	   	((null? a) #f)
	  		((eq? (car a) b) #t)
	  		(else (checkequal (cdr-stream a) b))
	  	)
	)

  	(define (cycle s lst)
  		(cond 
	  		((null? s) #f)
	  		((checkequal lst (car s)) #t)
	  		(else 
	  			(cycle (cdr-stream s) (cons-stream (car s) lst)) 'set!'
	  		)
	  	)
  	)
  	(cycle s '())
)

(define (has-cycle-constant s)
  'YOUR-CODE-HERE
  
  (define (cycle slow fast)
  	(cond 
  		((null? fast) #f)
  		((null? (cdr-stream fast)) #f)
  		((eq? (car fast) (car slow)) #t)
  		(else (cycle (cdr-stream slow) (cdr-stream (cdr-stream fast))))
  	)
  )
  (cycle s s)
)
