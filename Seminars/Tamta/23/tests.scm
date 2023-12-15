(load "solution.scm")

(display (if (equal? (reverse_ '()) '()) "1 SUCCESS" "1 FAILURE"))(newline)
(display (if (equal? (reverse_ '(1 2 3)) '(3 2 1)) "2 SUCCESS" "2 FAILURE"))(newline)

(display (if (equal? (sorted? '(1 2 3)) #t) "3 SUCCESS" "3 FAILURE"))(newline)
(display (if (equal? (sorted? '(5 3 6)) #f) "4 SUCCESS" "4 FAILURE"))(newline)


(display (if (equal? (max_ '()) 0) "5 SUCCESS" "5 FAILURE"))(newline)
(display (if (equal? (max_ '(4 5 3)) 5) "6 SUCCESS" "6 FAILURE"))(newline)

(display (if (equal? (filter_ positive? '(1 -2 45 -10 -20)) '(1 45)) "7 SUCCESS" "7 FAILURE"))(newline)
(display (if (equal? (filter_ odd? '(4 5 3)) '(5 3)) "8 SUCCESS" "8 FAILURE"))(newline)

(display (if (equal? (max_divisible3 '(4 9 3)) 9) "9 SUCCESS" "9 FAILURE"))(newline)
(display (if (equal? (max_divisible3 '(4 8)) 0) "10 SUCCESS" "10 FAILURE"))(newline)
(display (if (equal? (max_divisible3 '(33 48 22 102)) 102) "11 SUCCESS" "11 FAILURE"))(newline)


(display (if (equal? (range 5) '(1 2 3 4 5)) "12 SUCCESS" "12 FAILURE"))(newline)

(display (if (equal? (pow 2 5) 32) "13 SUCCESS" "13 FAILURE"))(newline)
(display (if (equal? (pow 7 1) 7) "14 SUCCESS" "14 FAILURE"))(newline)

(display (if (equal? (generate_powers 2 4) '(2 4 8 16)) "15 SUCCESS" "15 FAILURE"))(newline)
(display (if (equal? (generate_powers_map 2 4) '(2 4 8 16)) "16 SUCCESS" "15 FAILURE"))(newline)

