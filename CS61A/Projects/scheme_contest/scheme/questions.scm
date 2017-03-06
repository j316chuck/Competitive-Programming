(define (caar x) (car (car x)))
(define (cadr x) (car (cdr x)))
(define (cdar x) (cdr (car x)))
(define (cddr x) (cdr (cdr x)))

; Some utility functions that you may find useful to implement.

(define (map proc items)
  (if (null? items) items
    (cons (proc (car items)) (map proc (cdr items)))
  )
)
(define (condition x first)
  (if (null? x) x 
    (if (number? x) (cons first (cons x '()))
      (append (list first) x)
    )
  )
)
(define (cons-all first rests)
  (map (lambda (x) (condition x first)) rests)
)


(define (zip pairs)
  (define (l1 pairs)
    (if (null? pairs) pairs
      (cons (caar pairs) (l1 (cdr pairs)))   
    )
  )
  (define (l2 pairs)
    (if (null? pairs) pairs
        (append (cdar pairs) (l2 (cdr pairs)))
    )
  )
  (list (l1 pairs) (l2 pairs))
)
;; Problem 17
;; Returns a list of two-element lists
(define (enumerate s)
  ; BEGIN PROBLEM 17
  (define (enum s counter)
    (if (null? s) s
        (cons (list counter (car s))  (enum (cdr s) (+ 1 counter)))
    )
  )
  (enum s 0)
)
  ; END PROBLEM 17

;; Problem 18
;; List all ways to make change for TOTAL with DENOMS

(define (list-change total denoms)
  ; BEGIN PROBLEM 18
  (cond ((null? denoms) denoms)
    ((= total (car denoms)) (cons (cons total '()) (list-change total (cdr denoms)))) ;-1 stands for true result
    ((> 0 total) '())
    (else (append (cons-all (car denoms) (list-change (- total (car denoms)) denoms))
        (list-change total (cdr denoms))) 
    )
  )
)
  ; END PROBLEM 18

;; Problem 19
;; Returns a function that checks if an expression is the special form FORM
(define (check-special form)
  (lambda (expr) (equal? form (car expr))))

(define lambda? (check-special 'lambda))
(define define? (check-special 'define))
(define quoted? (check-special 'quote))
(define let?    (check-special 'let))

;; Converts all let special forms in EXPR into equivalent forms using lambda
(define (let-to-lambda expr)
  (cond ((atom? expr)
         ; BEGIN PROBLEM 19
         expr
         ; END PROBLEM 19
         )
        ((quoted? expr)
         ; BEGIN PROBLEM 19
         expr
         ; END PROBLEM 19
         )
        ((or (lambda? expr)
             (define? expr))
         (let ((form   (car expr))
               (params (cadr expr))
               (body   (cddr expr)))
           ; BEGIN PROBLEM 19
            (cons form (cons params (let-to-lambda body)))
           ))
        ((let? expr)
         (let ((values (cadr expr))
               (body   (cddr expr)))
           ; BEGIN PROBLEM 19
           'replace-this-line
            (define params (car (zip (let-to-lambda values))))
            (define expressions (cadr (zip (let-to-lambda values))))
            (define real-body (car (let-to-lambda body)))
            (cons (cons (quote lambda) (cons params (cons real-body '()))) expressions) 
            ;(cons (cons (quote lambda) (cons params) )
            ;(cons (cons (quote lambda) (cons params (let-to-lambda body))) (expressions))
            ;'((lambda (eval(let-to-lambda params)) (let-to-lambda body)) (let-to-lambda expressions))
            ;'((lambda (params) (body)) expressions)
           ; END PROBLEM 19
           ))
        (else
         ; BEGIN PROBLEM 19
          (map let-to-lambda expr)
         ; END PROBLEM 19
         )))
