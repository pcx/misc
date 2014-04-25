(define (sqrt x)
  (sqrt-iter 1.0 x))

(define (sqrt-iter guess x)
  (if (good-enough guess x)
      guess
      (sqrt-iter (improve guess x) x)))

(define (good-enough guess x)
  (> 0.001
     (abs
      (- (square guess) x))))

(define (improve guess x)
  (average guess
	   (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))
