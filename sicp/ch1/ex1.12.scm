;; element el at position x for nth row
;; el(x)(n) = 0 if x<1 or x> n+1
;;          = 1 if x=1 or x=n+1
;;          = el(x-1)(n-1) + el(x)(n-1)

(define (pt-el x n)
  (cond ((or (> x (+ n 1)) (< x 1)) 0)
	((or (= x 1) (= x (+ n 1))) 1)
	(else (+ (pt-el (- x 1) (- n 1))
		 (pt-el x (- n 1))))))
