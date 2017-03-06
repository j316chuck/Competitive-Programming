(define (cddr s)
  (cdr (cdr s)))

(define (cadr s)
  'YOUR-CODE-HERE
  (car (cdr s))
)

(define (caddr s)
  'YOUR-CODE-HERE
  (car (cddr s))
)

(define (sign x)
  'YOUR-CODE-HERE
  (cond
    ((> x 0) 1)
    ((< x 0) -1)
    (else 0)
  )
)

(define (square x) (* x x))

(define (pow b n)
  'YOUR-CODE-HERE
  (cond 
    ((equal? n 0) 1)
    ((even? n) (square (pow b (/ n 2))))
    ((odd? n) (* b (pow b (- n 1))))
  )
)

(define (ordered? s)
  'YOUR-CODE-HERE
  (cond
    ((null? s) true)
    ((null? (cdr s)) true)
    ((<= (car s) (cadr s)) (ordered? (cdr s)))
    (else false)
  )
)

(define (nodots s)
  (cond ((null? s) nil)
        ((and (pair? (car s)) (pair? (cdr s))) (cons (nodots (car s)) (nodots (cdr s))))
        ((and (pair? (car s)) (null? (cdr s))) (cons (nodots (car s)) (cdr s)))
        ((pair? (car s)) (cons (nodots (car s)) (cons (cdr s) nil)))
        ((pair? (cdr s)) (cons (car s) (nodots (cdr s))))
        ((null? (cdr s)) s)
        (else (cons (car s) (cons (cdr s) nil)))
  )
)
; Sets as sorted lists


(define (empty? s) (null? s))
 
(define (contains? s v)
    (cond ((empty? s) false)
          ((> (car s) v) #f)
          ((= (car s) v) #t)
          (else (contains? (cdr s) v) ; replace this line
          )
)
)
; Equivalent Python code, for your reference:
;
; def empty(s):
;     return s is Link.empty
;
; def contains(s, v):
;     if empty(s):
;         return False
;     elif s.first > v:
;         return False
;     elif s.first == v:
;         return True
;     else:
;         return contains(s.rest, v)
 
(define (add s v)
    (cond ((empty? s) (list v))
          ((= (car s) v) (cons (car s) (cdr s)))
          ((and (< (car s) v) (empty? (cdr s)) (cons (car s) (cons v nil))))
          ((and (< (car s) v) (> (car (cdr s)) v)) (cons (car s) (cons v (cdr s))))
          ((> (car s) v) (cons v s))
          (else (cons (car s) (add (cdr s) v)))
          ))
 
(define (intersect s t)
    (cond ((or (empty? s) (empty? t)) nil)
          ((= (car s) (car t)) (cons (car s) (intersect (cdr s) (cdr t))))
          ((> (car s) (car t)) (intersect s (cdr t)))
          (else (intersect (cdr s) t))
          )
      )
 
; Equivalent Python code, for your reference:
;
; def intersect(set1, set2):
;     if empty(set1) or empty(set2):
;         return Link.empty
;     else:
;         e1, e2 = set1.first, set2.first
;         if e1 == e2:
;             return Link(e1, intersect(set1.rest, set2.rest))
;         elif e1 < e2:
;             return intersect(set1.rest, set2)
;         elif e2 < e1:
;             return intersect(set1, set2.rest)
(define (union s t)
    (cond ((empty? s) t)
          ((empty? t) s)
          ((> (car s) (car t)) (cons (car t) (union s (cdr t))))
          ((< (car s) (car t)) (cons (car s) (union (cdr s) t)))
          (else (cons (car s) (union (cdr s) (cdr t))))
          ))
 
; Q9 - Survey
(define (survey)
    ; Midsemester Survey: https://goo.gl/forms/a3NTVfZWFjWReu0x1
    procedure
)