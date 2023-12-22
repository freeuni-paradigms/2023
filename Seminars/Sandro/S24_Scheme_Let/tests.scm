(load "solution.scm")


(display (if (equal? (reverseDup '()) '()) "reverseDup 1 SUCCESS" "reverseDup 1 FAILURE"))(newline)
(display (if (equal? (reverseDup '(1)) '(1 1)) "reverseDup 2 SUCCESS" "reverseDup 2 FAILURE"))(newline)
(display (if (equal? (reverseDup '(1 2 3)) '(3 2 1 3 2 1)) "reverseDup 3 SUCCESS" "reverseDup 3 FAILURE"))(newline)


(display (if (equal? (binpow 2 0) 1) "binpow 4 SUCCESS" "binpow 4 FAILURE"))(newline)
(display (if (equal? (binpow 2 3) 8) "binpow 5 SUCCESS" "binpow 5 FAILURE"))(newline)
(display (if (equal? (binpow 15 7) 170859375) "binpow 6 SUCCESS" "binpow 6 FAILURE"))(newline)
;;
;;
(display (if (equal? (fib 0) 0) "fib 7 SUCCESS" "fib 7 FAILURE"))(newline)
(display (if (equal? (fib 1) 1) "fib 8 SUCCESS" "fib 8 FAILURE"))(newline)
(display (if (equal? (fib 2) 1) "fib 9 SUCCESS" "fib 9 FAILURE"))(newline)
(display (if (equal? (fib 7) 13) "fib 10 SUCCESS" "fib 10 FAILURE"))(newline)
(display (if (equal? (fib 64) 10610209857723) "fib 11 SUCCESS" "fib 11 FAILURE"))(newline)
; (display (fib 10000))(newline)


;;

(display (if (equal? (partition 0 '()) '(()())) "partition 10 SUCCESS" "partition 10 FAILURE"))(newline)
(display (if (equal? (partition 4 '(3 7 1 10 4 8)) '((3 1)(7 10 4 8))) "partition 11 SUCCESS" "partition 11 FAILURE"))(newline)
(display (if (equal? (partition 5 '(6 3 2 7 8 4 1 10 2 9 8)) '((3 2 4 1 2)(6 7 8 10 9 8))) "partition 12 SUCCESS" "partition 12 FAILURE"))(newline)
;;

(display (if (equal? (removeallx 5 '(1 2 3 4 5 6)) '(1 2 3 4 6)) "rem 13 SUCCESS" "rem 13 FAILURE"))(newline)
(display (if (equal? (removeallx 5 '(5 2 3 4 5 6)) '(2 3 4 6)) "rem 13 SUCCESS" "rem 13 FAILURE"))(newline)
(display (if (equal? (permutation? '() '()) #t) "permutation? 13 SUCCESS" "permutation? 13 FAILURE"))(newline)
(display (if (equal? (permutation? '(1 3 4 5) '(5 3 1 4)) #t) "permutation? 14 SUCCESS" "permutation? 14 FAILURE"))(newline)
(display (if (equal? (permutation? '(1 1) '(1 2)) #f) "permutation? 15 SUCCESS" "permutation? 15 FAILURE"))(newline)

;;
;;
;; (display (if (equal? (isWay? '((1 2) (2 3) (1 3) (2 4)) 1 4) #t) "isWay? 16 SUCCESS" "isWay? 16 FAILURE"))(newline)
;; (display (if (equal? (isWay? '((1 2) (2 3) (1 3) (4 5)) 1 5) #f) "isWay? 17 SUCCESS" "isWay? 17 FAILURE"))(newline)
;; (display (if (equal? (isWay? '((1 2)) 1 1) #t) "isWay? 18 SUCCESS" "isWay? 18 FAILURE"))(newline)
