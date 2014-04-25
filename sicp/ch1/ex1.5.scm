(define (p) (p))

(define (test x y)
  (if (= x 0)
      0
      y))

(test 0 (p))
;; the above call will try to evaluate function p
;; which is a self-referncing function
