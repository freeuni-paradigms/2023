
(define (count x seq)
  (apply + (map (lambda (e) (if (= x e) 1 0))  seq))
  )

;; (display (count 5 '()))(newline)

(define (unique seq)
  (cond
	((null? seq) '())
	((= (count (car seq) (cdr seq)) 0) (cons (car seq) (unique (cdr seq)) )  )
	(else (unique (cdr seq)))
	)
  )
;; (display (unique '( 1 2 3 1 1 5)))(newline)

;;
;;
(define (unique-sums-helper seq)
  (if (null? seq) '(0)
		(unique (apply append(map (lambda (elem) (list elem (+ elem (car seq)))) (unique-sums-helper (cdr seq)))))
	 )
)

(define (unique-sums seq)
  (length (unique-sums-helper seq))
)
;;
