(define (fib n)
  (if (<= n 2) 1
	  (+ (fib (- n 1))
		 (fib (- n 2)))))

(display (fib 5))
(newline)

(display (fib 10))
(newline)
