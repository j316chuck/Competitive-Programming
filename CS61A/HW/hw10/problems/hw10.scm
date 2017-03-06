(define (substitute s old new)
  'YOUR-CODE-HERE
  (cond ((null? s) s) 
    ((pair? (car s)) (cons (substitute (car s) old new) (substitute (cdr s) old new)))
    ((equal? (car s) old) (cons new (substitute (cdr s) old new ) ))
    (else (cons (car s) (substitute (cdr s) old new)))
  )
)

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

(define (cadr s) (car (cdr s)))
(define (caddr s) (cadr (cdr s)))


; derive returns the derivative of EXPR with respect to VAR
(define (derive expr var)
  (cond ((number? expr) 0)
        ((variable? expr) (if (same-variable? expr var) 1 0))
        ((sum? expr) (derive-sum expr var))
        ((product? expr) (derive-product expr var))
        ((exp? expr) (derive-exp expr var))
        (else 'Error)))

; Variables are represented as symbols
(define (variable? x) (symbol? x))
(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))

; Numbers are compared with =
(define (=number? expr num)
  (and (number? expr) (= expr num)))

; Sums are represented as lists that start with +.
(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))
(define (sum? x)
  (and (list? x) (eq? (car x) '+)))
(define (addend s) (cadr s))
(define (augend s) (caddr s))

; Products are represented as lists that start with *.
(define (make-product m1 m2)
(cond ((or (=number? m1 0) (=number? m2 0)) 0)
      ((=number? m1 1) m2)
      ((=number? m2 1) m1)
      ((and (number? m1) (number? m2)) (* m1 m2))
      (else (list '* m1 m2))))
(define (product? x)
  (and (list? x) (eq? (car x) '*)))
(define (multiplier p) (cadr p))
(define (multiplicand p) (caddr p))

(define (derive-sum expr var)
  'YOUR-CODE-HERE
    (make-sum (derive (addend expr) var) (derive (augend expr) var))
  )

(define (derive-product expr var)
  'YOUR-CODE-HERE
    ;(make-product (multiplier (derive-product multiplcand var)) 
    ;)
    (make-sum   
       (make-product (derive (multiplier expr) var) (multiplicand expr))
       (make-product (multiplier expr) (derive (multiplicand expr) var))
    )
)

; Exponentiations are represented as lists that start with ^.
(define (make-exp base exponent)
  'YOUR-CODE-HERE
  (cond ((equal? exponent 0) 1)
        ((equal? exponent 1) base)
        ((number? base) (expt base exponent))
        (else (cons '^ (cons base (cons exponent '())))) 
  )
)

(define (base exp)
  'YOUR-CODE-HERE
    (cadr exp)
  )

(define (exponent exp)
  'YOUR-CODE-HERE
    (caddr exp)
)

(define (exp? exp)
  'YOUR-CODE-HERE
  (and (list? exp) (eq? (car exp) '^)))
)

(define x^2 (make-exp 'x 2))
(define x^3 (make-exp 'x 3))

(define (derive-exp exp var)
  'YOUR-CODE-HERE
  ;make-exp if it is a number then return for check edge cases. 
  ;(base exp)
  (make-product (exponent exp) (make-exp (base exp) (- (exponent exp) 1)))

)
