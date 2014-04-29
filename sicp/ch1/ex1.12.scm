;; Calculate an element in pascal's triangle
;; n -> the row number in the triangle, where
;; the triangle starts from row 1
;; i-> the column number in each row, where the
;; row starts from column number 1

(define (pascal n i)
  (cond ((or (= i 1) (= n i)) 1)
	(else (+ (pascal (- n 1) (- i 1))
		 (pascal (- n 1) i)))))

(pascal 4 2)
(pascal 5 2)
(pascal 6 2)
(pascal 6 3)
(pascal 7 3)
(pascal 8 3)
(pascal 9 3)
(pascal 10 3)
(pascal 10 4)
(pascal 10 5)
