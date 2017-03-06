(define (how-many-dots s)
  'YOUR-CODE-HERE
  ;(cond ((null? s) 0)
  ;	((and (pair? (car s)) (null? (cdr s))) (how-many-dots (car s)))
  ;	((and (pair? (car s)) (number? (cdr s))) (+ 1 how-many-dots(car s)))
  ;	((pair? (car s)) (+ (how-many-dots (car s)) (how-many-dots (cdr s))))
  ;	((null? (cdr s)) 0)
  ;	((number? (cdr s)) 1)
  ;	(else (how-many-dots (cdr s)))
  ;)
  ;(if (or (null? s) (number? s)) 0
  ;(if (pair? s)  
  ;	(+ 1 
  ;			(how-many-dots (car s))
  ;			(how-many-dots (cdr s))
  ;		) (+
  ;			(how-many-dots (car s))
  ;			(how-many-dots (cdr s))
  ;		)
  ;	)
  ;)
  ;(if (not (pair? s)) 0
  ;		(if (number? (cdr s))
  ;			(+ 1 (how-many-dots (car s)) (how-many-dots (cdr s)))
  ;			(+ (how-many-dots (car s)) (how-many-dots (cdr s)))	
  ;		)
  ;)(define (how-many-dots s)
  'YOUR-CODE-HERE
  (cond ((null? s) 0)
  	((and (pair? (car s)) (null? (cdr s))) (how-many-dots (car s)))
  	((and (pair? (car s)) (number? (cdr s))) (+ 1 (how-many-dots (car s))))
  	((pair? (car s)) (+ (how-many-dots (car s)) (how-many-dots (cdr s))))
  	((null? (cdr s))  0)
  	((number? (cdr s))  1)
  	(else (how-many-dots (cdr s)))
  )

)

;;; Tests

(how-many-dots '(1 2 3))
; expect 0
(how-many-dots '(1 2 . 3))
; expect 1
(how-many-dots '((1 . 2) 3 . 4))
; expect 2
(how-many-dots '((((((1 . 2) . 3) . 4) . 5) . 6) . 7))
; expect 6
(how-many-dots '(1 . (2 . (3 . (4 . (5 . (6 . (7)))))))
; expect 0