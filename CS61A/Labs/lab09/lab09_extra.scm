;; Extra Scheme Questions ;;

; Q5
(define (square x) (* x x))

(define (pow b n)
	(cond ((= n 0) 1)
		((even? n)  (square (pow b (/ n 2))))
		(else (* b (pow b (- n 1))))
	)
)

; Q6

(define lst
  (cons (cons 1 '()) 
  		(cons 2 
  			(cons 	(cons 3 4) 
  					(cons 5 '()))))
)

; Q7
(define (composed f g)
  (lambda (x) ( f (g x) ) )
)

; Q8
(define (remove item lst)
  'YOUR-CODE-HERE
  (if (null? lst) lst
  		(if (= (car lst) item)
  			(remove item (cdr lst))
  			(cons (car lst) (remove item (cdr lst)))
  		)
  )
)


;;; Tests
(remove 3 nil)
; expect ()
(remove 3 '(1 3 5))
; expect (1 5)
(remove 5 '(5 3 5 5 1 4 5 4))
; expect (3 1 4 4)

; Q9
(define (max a b) (if (> a b) a b))
(define (min a b) (if (> a b) b a))
(define (gcd a b)
  'YOUR-CODE-HERE
  (if (zero? (min a b)) (max a b)
  		(if (zero? (modulo (max a b) (min a b)))
  			(min a b)
    		(gcd (min a b) (modulo (max a b) (min a b)))
    	)
  )
)

;;; Tests
(gcd 24 60)
; expect 12
(gcd 1071 462)
; expect 21

; Q10
(define (no-repeats s)
  'YOUR-CODE-HERE
	(define (filter f lst)
		(cond ((null? lst) lst) 
			((= f (car lst)) (filter f (cdr lst)))
			(else (cons (car lst ) (filter f (cdr lst))))
		)
	) 
	(if (null? s) s
		(cons (car s) (filter (car s) (no-repeats (cdr s))))
	)
)



; Q11
(define (substitute s old new)
	(cond ((null? s) s) 
		((pair? (car s)) (cons (substitute (car s) old new) (substitute (cdr s) old new) ))
		((equal? old (car s)) (cons new (substitute (cdr s) old new)))
		(else (cons (car s) (substitute (cdr s) old new )))
	)
)




; Q12



(define (sub-all s olds news)
  'YOUR-CODE-HERE
	
	(define (replace value old new)
	  		(cond ((null? old) value)
	  		      ((equal? (car old) value) (car new))
	  		      (else (replace value (cdr old) (cdr new) ))
	  		)
	)  
  	(if (null? s) s
  		(if (pair? (car s)) 
  			(cons (sub-all (car s) olds news) (sub-all (cdr s) olds news) )
  			(cons (replace (car s) olds news) (sub-all (cdr s) olds news) )   
  		) 	
  	)
)
