(load "solution.scm")

(display (if (equal? (first-elem '(1 2 3)) 1) "1 SUCCESS" "1 FAILURE"))(newline)
(display (if (equal? (first-elem '()) "None") "2 SUCCESS" "2 FAILURE"))(newline)


(display (if (equal? (abs_ 0) 0) "3 SUCCESS" "3 FAILURE"))(newline)
(display (if (equal? (abs_ 10) 10) "4 SUCCESS" "4 FAILURE"))(newline)
(display (if (equal? (abs_ -8) 8) "5 SUCCESS" "5 FAILURE"))(newline)


(display (if (equal? (right-triangle '(1 2 3)) #f) "6 SUCCESS" "6 FAILURE"))(newline)
(display (if (equal? (right-triangle '(3 4 5)) #t) "7 SUCCESS" "7 FAILURE"))(newline)


(display (if (equal? (last-elem '(1 2 3)) 3) "8 SUCCESS" "8 FAILURE"))(newline)
(display (if (equal? (last-elem '(5)) 5) "9 SUCCESS" "9 FAILURE"))(newline)
(display (if (equal? (last-elem '()) "None") "10 SUCCESS" "10 FAILURE"))(newline)


(display (if (equal? (length_ '()) 0) "11 SUCCESS" "11 FAILURE"))(newline)
(display (if (equal? (length_ '(1 2 3 4 5)) 5) "12 SUCCESS" "12 FAILURE"))(newline)


(display (if (equal? (k-th-element '(1 2 3) 2) 3) "13 SUCCESS" "13 FAILURE"))(newline)
(display (if (equal? (k-th-element '() 0) "None") "14 SUCCESS" "14 FAILURE"))(newline)


(display (if (equal? (filter-range '(1 2 3 4) 2 4) '(2 3 4)) "15 SUCCESS" "15 FAILURE"))(newline)
(display (if (equal? (filter-range '(1 2 3 4) 9 14) '()) "16 SUCCESS" "16 FAILURE"))(newline)
(display (if (equal? (filter-range '(1 2 3 4) 4 1) '(1 2 3 4)) "17 SUCCESS" "17 FAILURE"))(newline)


(display (if (equal? (prime? 2) #t) "18 SUCCESS" "18 FAILURE"))(newline)
(display (if (equal? (prime? 12) #f) "19 SUCCESS" "19 FAILURE"))(newline)
(display (if (equal? (prime? 1) #f) "20 SUCCESS" "20 FAILURE"))(newline)


(display (if (equal? (primes? '(1 2 3 4)) '(#f #t #t #f)) "21 SUCCESS" "21 FAILURE"))(newline)
(display (if (equal? (primes? '()) '()) "22 SUCCESS" "22 FAILURE"))(newline)
(display (if (equal? (primes? '(10 12 23 33)) '(#f #f #t #f)) "23 SUCCESS" "23 FAILURE"))(newline)