(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

;; the if conditional returns + operator if b is +ve
;; and a - operator if b is -ve, thus always resulting
;; in a-plus-abs-b; essentially even operators behave like
;; other elements
