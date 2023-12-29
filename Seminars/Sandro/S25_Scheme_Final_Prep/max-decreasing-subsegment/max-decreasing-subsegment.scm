
(define (lex_cmp l1 l2)
  (cond
	 ((null? l1) l1)
	 ((< (car l1) (car l2))   l2 )
	 ((> (car l1) (car l2))   l1 )
	 (else (cons (car l1) (lex_cmp (cdr l2) (cdr l2))))
	 )
  )

(define (pick_best l1 l2)
  (cond 
	 ((< (length l1) (length l2)) l2)
	 ((> (length l1) (length l2)) l1)
	 (else (reverse (lex_cmp (reverse l1) (reverse l2))))
	 )
	)




(define (max-decreasing-subsegment-helper lst cur)
  (if (null? lst) '()

  (let
	 (
	  (max_dec_sub
		 (cond 
			 ((null? cur)  (list (car lst))   )
			 ((< (car lst) (car cur)) (cons (car lst) cur) )
			 (else (list (car lst)))
			)
		 )
	  )
	 (pick_best
		 (max-decreasing-subsegment-helper (cdr lst) max_dec_sub)
			max_dec_sub
	 )
	 )
  )
  )


(define (max-decreasing-subsegment lst)
	(reverse (max-decreasing-subsegment-helper lst '()))
  )

