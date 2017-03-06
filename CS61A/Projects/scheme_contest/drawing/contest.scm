;;; Scheme Recursive Art Contest Entry
;;;
;;; Please do not include your name or personal info in this file.
;;;
;;; Title: <Your title here>
;;;
;;; Description:
;;;   <It's your masterpiece.
;;;    Use these three lines to describe
;;;    its inner meaning.>

(define (fill fn c)
	(color c)
	(begin_fill)
	(fn)
	(end_fill)
)

(define (draw fn c)
	(color c)
	(fn)
)

(define (head)
	(color "#edea4b")
	(begin_fill)
	(repeat (lambda() (fd 1.5) (rt 0.5)) 30)
	(repeat (lambda() (fd 1.5) (rt 1)) 45)
	(repeat (lambda() (fd 1) (rt 0.5)) 120)
	(repeat (lambda() (fd 1.5) (rt 1)) 45)
	(repeat (lambda() (fd 1.5) (rt 0.5)) 30)
	(repeat (lambda() (fd 1.5) (rt 1)) 90)
	(repeat (lambda() (fd 1) (rt 0.2)) 50)
	(repeat (lambda() (fd 1.5) (rt 1)) 90)
	(end_fill)
)

(define (eyes)
	(color "white")
	(reset -50 -20)
	(begin_fill)
	(circle 20)
	(end_fill)
	(reset 50 -20)
	(begin_fill)
	(circle 23)
	(end_fill)
)

;(define (sad_mouth x y len)
;	(if (< y -80)
;		'done
;		((reset x y)
;		(seth 90)
;		(fd len)
;		(mouth (+ x 0.2) (- y 0.5) (- len 0.4)))
;	)
;)

(define (happy_mouth x y)
	(reset x y)	
	(seth 90)
	(repeat (lambda() (fd 3) (lt 3)) 10)
	(repeat (lambda()) (fd 4) (rt 10) 10)
)	

(define (body)
	(reset -80 -65)
	(color "#edea4b")
	(begin_fill)
	(seth -150)
	(fd 125)
	(seth 65)
	(fd 75)
	(seth 185)
	(fd 150)
	(seth 90)
	(fd 140)
	(seth -5)
	(fd 150)
	(seth 125)
	(fd 75)
	(seth -30)
	(fd 135)
	(end_fill)
)

(define (curve n len)
	(repeat (lambda () (right 1) (forward len)) n)
)


(define (heart)
	(color "red")
	(begin_fill)
	(reset -20 -175)
	(seth -45)
	(forward 45)
	(curve 200 0.3)
	(seth 15)
	(curve 200 0.3)
	(setpos -20 -175)
	(end_fill)
)

(define (flower x)
	(if (= x 90)(
			(color "green")
			(stem -170 -130 0)
		)
		((forward (* x (* 0.0001 (* x x)))) 
		(left 91)
		(flower (+ 1 x))
		)
	)
)

(define (stem x y counter)
	(if (= counter 10) 'done (
			(reset x y)
			(seth 135)
			(forward 60)
			(stem x (+ 1 y) (+ 1 counter))
		)
	)
)

(define (repeat fn k)
	(if (= k 0) 'done
		(begin (fn) (repeat fn (- k 1)))
	)
)

(define (reset x y)
	(penup)
	(setpos x y)
	(pendown)
)


(speed 0)
(reset -120 0)
(head)
(eyes)
(happy_mouth -30 -60)
(body)
(heart)
(reset -200 -100)
(color "red")
(flower 0)
(hideturtle)
(bgcolor "#95b26c")
(exitonclick)

; Please leave this last line alone.  You may add additional procedures above
; this line.
