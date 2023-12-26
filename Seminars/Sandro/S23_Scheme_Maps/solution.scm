(define (digits n)
  (if (< n 10) (list n)
	 (append (digits (div n 10))  (list (remainder n 10))   )
	 )
  )




;; (define (mapfn x)
;;   (expt x (length lst))
;;   )

(define (list_power lst)
  (map
	 (lambda (x) (expt x (length lst)))
	 lst
	 )
  )

(define (sum lst)
  (apply + lst)
  )

(define (narcisisstic? n)
  (= (sum (list_power (digits n))) n)
  )

(define (count n lst)
  (sum (map (lambda (x) (if (= x n) 1 0)) lst))
  )

(define (set lst)
  (cond
	 ((null? lst) '())
	 ((= (count (car lst) (cdr lst)) 0)   (cons (car lst) (set (cdr lst))) )
	 (else (set (cdr lst)) )
	 )
  )

(define (frequency lst)
  (map (lambda (x) (list x (count x lst)) )   (set lst))
  )

(define (multiplyone n k)
  (if (= k 0) '()
	 (cons n (multiplyone n (- k 1)))
	 )
  )

(define (multiply n lst)
  (apply append (map (lambda (x) (multiplyone x n)) lst ))
  )


(define (ksubset n lst)
  (cond 
	 ((= n 0) '( () ))
	 ((> n (length lst)) '())
	 ((= n (length lst)) (list lst))
	 (else
		(append 
			(map (lambda (subset) (cons (car lst) subset)) (ksubset (- n 1) (cdr lst)))
				; n-1 subsets of rest of the list with (car lst)
		  (ksubset n (cdr lst)) ; n subsets of rest of the list
		  )
		)
	 )

  


  )



