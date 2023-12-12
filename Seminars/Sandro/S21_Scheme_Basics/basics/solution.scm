(define (first-elem lst)
  (if (null? lst) "None"
		(car lst)
	 )
)

(define (abs_ x) 
  (if (< x 0)
	 (- x) 
	 x 	
	 )
  )


(define (right-triangle lst)
  (=
	 (square (caddr lst))
	 (+ 
		(square (car lst))
		(square (cadr lst))
		)
	 )
  )


(define (last-elem lst)
  (cond 
	 ((null? lst) "None")
	 ((null? (cdr lst)) (car lst))
	 (else (last-elem (cdr lst)))
	 )
  )


(define (length_ lst)
  (if
	 (null? lst) 
	 0
	 (+ 1 (length_ (cdr lst)))
	 )
  )

(define (k-th-element lst k)
  (cond 
	 ((null? lst) "None")
	 ((= k 0) (car lst))
	 (else (k-th-element (cdr lst) (- k 1)))
	 )
  )

(define (filter-range lst a b)
  (cond
	 ((null? lst) '())
	 ; a <= (car lst) <= b
	 ((> a b) (filter-range lst b a))
	 (
		  (and
			 (<= a (car lst))
			 (<= (car lst) b)
			 ) 
		  (cons (car lst) (filter-range (cdr lst) a b))
	  )
	 (else 
		(filter-range (cdr lst) a b)
		)
	 )


  )



(define (prime-helper n d)
  (cond
	 ((> d (sqrt n)) #t)
	 ((equal? (remainder n d) 0) #f)
	 (else (prime-helper n (+ d 1)))
	 )
  )

(define (prime? p)
  (if (= p 1)
	 #f
	  (prime-helper p 2)
	 )
  )



