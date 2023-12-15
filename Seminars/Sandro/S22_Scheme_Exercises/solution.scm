(define (reverse_ lst)
  (if (null? lst) '()
	 (append (reverse_ (cdr lst)) (list (car lst) ))
	 )
)



(define (sorted? lst)
  (cond
	 ((null? lst) #t)
	 ((null? (cdr lst)) #t)
	 ((< (car lst) (cadr lst))  (sorted? (cdr lst))) ; a < b
	 (else #f) ; a >= b
	 )
  )

(define (max_ lst) 
  (cond 
	 ((null? lst) 0)
	 ((< (car lst) (max_ (cdr lst))) (max_ (cdr lst)))
	 (else (car lst))
	 )
  )

(define (filter_ filter_fn lst)
  (cond 
	 ((null? lst) '())
	 ((filter_fn (car lst)) (cons (car lst) (filter_ filter_fn (cdr lst)) )  ) ; true means keep
	 (else (filter_ filter_fn (cdr lst)))
	 )
  )


(define (ismulof3? x)
  (= (remainder x 3) 0) ; x%3==0
  )


(define (max_divisible3 lst)
  (max_ (filter_ ismulof3? lst))
  )

(define (range n)
  (if (= n 0) '()
	 (append (range (- n 1)) (list n) )
	 )
  )


(define (pow a b)
  (if (= b 0) 1
	 (* a (pow a (- b 1)))
	 )
  )


;; (define (generate_powers n k)
;;   (if (= k  1) (list n)
;; 	 (append 
;; 		(generate_powers n (- k 1)) 
;; 		(list (pow n k))
;; 		)
;; 	 )
;;   ) ; n^1 n^2 .. n^k



(define (map_ map_fn lst)
  (if (null? lst) '()
	 (cons (map_fn (car lst)) (map_ map_fn (cdr lst)))
	 )
  )





(define (generate_powers n k)
  (map_  
	 (lambda (elem) (pow n elem))
			(range k)) ; 1 2 3 4 -> n^1 n^2 n^3 n^4
  ) ; n^1 n^2 .. n^k







