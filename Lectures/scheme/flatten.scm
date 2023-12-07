(define (flatten seq)
  (cond ((null? seq) '())
		((not (list? seq)) (list seq))
		(else (append (flatten (car seq))
				(flatten (cdr seq))))))

(display (flatten '(1 2 (3 (4 5) (6 (7)) 8 9))))
(newline)
