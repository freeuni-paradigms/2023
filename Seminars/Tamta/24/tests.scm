(load "solution.scm")

(display (if (equal? (digits 5) '(5)) "digits 1 SUCCESS" "digits 1 FAILURE"))(newline)
(display (if (equal? (digits 150) '(1 5 0)) "digits 2 SUCCESS" "digits 2 FAILURE"))(newline)

(display (if (equal? (list_power '(5)) '(5)) "list_power 1 SUCCESS" "list_power 1 FAILURE"))(newline)
(display (if (equal? (list_power '(1 2 3)) '(1 8 27)) "list_power 2 SUCCESS" "list_power 2 FAILURE"))(newline)

(display (if (equal? (sum '(1 2 3)) 6) "sum 1 SUCCESS" "sum 1 FAILURE"))(newline)
(display (if (equal? (sum '(9)) 9) "sum 2 SUCCESS" "sum 2 FAILURE"))(newline)

(display (if (equal? (narcisisstic? 153) #t) "narcisisstic? 1 SUCCESS" "narcisisstic? 1 FAILURE"))(newline)
(display (if (equal? (narcisisstic? 1634) #t) "narcisisstic? 2 SUCCESS" "narcisisstic? 2 FAILURE"))(newline)
(display (if (equal? (narcisisstic? 1025) #f) "narcisisstic? 3 SUCCESS" "narcisisstic? 3 FAILURE"))(newline)


(display (if (equal? (count 4 '()) 0) "count 1 SUCCESS" "count 1 FAILURE"))(newline)
(display (if (equal? (count 5 '(1 2 3 5 1 5 1 5)) 3) "count 2 SUCCESS" "count 2 FAILURE"))(newline)

; ; შეიძლება სხვა პასუხებიც იყოს ამიტომ თუ გაფეილდა ცალკე გაუშვით და ნახეთ სწორად აბრუნებს თუ არა
(display (if (equal? (set '(1 1 2 2 3 3 4)) '(1 2 3 4)) "set 1 SUCCESS" "set 1 FAILURE"))(newline)
(display (if (equal? (set '(5 1 5 1 5)) '(1 5)) "set 2 SUCCESS" "set 2 FAILURE"))(newline)

(display (if (equal? (frequency '(1 1 2 2 3 3 4)) '((1 2) (2 2) (3 2) (4 1))) "frequency 1 SUCCESS" "frequency 1 FAILURE"))(newline)
(display (if (equal? (frequency '(5 1 5 1 5)) '((1 2) (5 3))) "frequency 2 SUCCESS" "frequency 2 FAILURE"))(newline)


(display (if (equal? (multiply 2 '(1 1 2 2 3)) '(1 1 1 1 2 2 2 2 3 3)) "multiply 1 SUCCESS" "multiply 1 FAILURE"))(newline)
(display (if (equal? (multiply 4 '(5 1)) '(5 5 5 5 1 1 1 1)) "multiply 2 SUCCESS" "multiply 2 FAILURE"))(newline)