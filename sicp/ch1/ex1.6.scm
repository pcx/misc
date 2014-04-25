(define (sqrt x)
  (sqrt-iter 1.0 x))

(define (sqrt-iter guess x)
  (new-if (good-enough guess x) guess
	  (sqrt-iter (improve guess x) x)))

(define (good-enough guess x)
  (> 0.001
     (abs (- (square guess) x))))

(define (improve guess x)
  (average guess
	   (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
	(else else-clause)))

;; since new-if is a function, all its arguments have to be evaluated first.
;; the interpreter tries to evaluate the call to sqrt-iter which ends up in infinite recursion
