import turtle

def draw_triangle():
	t.fd(15)
	t.left(120)
	t.fd(30)
	t.left(120)
	t.fd(30)
	t.left(120)
	t.fd(15)

"""def draw_sierpinski(length, depth):
	if depth == 1:
		for i in range(0, 3):
			t.fd(length)
			t.left(120)
	else:
		draw_sierpinski(length/2, depth-1)
		t.fd(length/2)
		draw_sierpinski(length/2, depth-1)
		t.bk(length/2)
		t.left(60)
		t.fd(length/2)
		t.right(60)
		draw_sierpinski(length/2, depth-1)
		t.left(60)
		t.bk(length/2)
		t.right(60)
"""
def draw_sierpinski(length, depth):
	if depth == 1:
		for i in range(0, 3):
			t.fd(length)
			t.left(120)
	else:
		draw_sierpinski(length/2, depth-1)
		t.bk(length/2)
		draw_sierpinski(length/2, depth-1)
		t.left(60)
		t.fd(length/2)
		t.right(60)
		draw_sierpinski(length/2, depth-1)
		t.right(60)
		t.fd(length/2)
		t.left(60)
"""
def draw_sierpinski(length, depth):
	if depth == 1:
		for i in range(0, 6):
			t.fd(length)
			t.left(60)
"""
window = turtle.Screen()
t = turtle.Turtle()
draw_sierpinski(400, 3)
#draw_triangle()
window.exitonclick()

""";;; Scheme Recursive Art Contest Entry
;;;
;;; Please do not include your name or personal info in this file.
;;;
;;; Title: <Your title here>
;;;
;;; Description:
;;;   <It's your masterpiece.
;;;    Use these three lines to describe
;;;    its inner meaning.>

(define (square x) 
	(if (= x 20)
		'done
		((fd (* x (* 0.0001 (* x x)))) 
		(lt 120)
		(square (+ 1 x))
		)
	)
)

(define (draw)
  (color "red")
  (square 1)
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
	
; Please leave this last line alone.  You may add additional procedures above
; this line.
(speed 0)
(draw)
(bgcolor "#0d0c04")
(exitonclick)

;(speed 0)
"""