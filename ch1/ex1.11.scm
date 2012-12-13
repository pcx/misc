(define (f n)
  (cond ((< n 3) n)
	(else (+ (f (- n 1))
		 (* 2 (f (- n 2)))
		 (* 3 (f (- n 3)))))))
(define (f-new n)
  (f-iter 0 1 2 n))

(define (f-iter a b c count)
  (if (< count 3)
      c
      (f-iter b c (+ c
		     (* 2 b)
		     (* 3 a))
	      (- count 1))))

(f 7)
(f-new 7)
