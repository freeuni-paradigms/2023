(load "unique_sums.scm")

;; Testing lib

(define (assert-eq actual expected)
  (let ((act (eval actual))
	(exp (eval expected)))
	(if (equal? act exp) (list #t)
	    (list #f actual expected act exp))))

(define (is-list-tests args)
  (cond ((null? args) #f)
	((equal? "--list_tests" (car args)) #t)
	(else (is-list-tests (cdr args)))))

(define (is-run-test args)
  (cond ((null? args) #f)
	((string-prefix? "--run_test=" (car args)) (substring (car args) (string-length "--run_test=") (length (car args))))
	(else (is-run-test (cdr args)))))

(define (is-score args)
  (cond ((null? args) #f)
	((string-prefix? "--results_file=" (car args)) (substring (car args) (string-length "--results_file=") (length (car args))))
	(else (is-score (cdr args)))))

(define (assign-weights weight tests)
  (if (null? tests) '()
      (cons (list (caar tests) weight (cadr (car tests)))
	      (assign-weights weight (cdr tests)))))

(define (extract-suite-tests suite)
  (assign-weights (/ (car suite) (length (cadr suite)))
		  (cadr suite)))

(define (extract-tests suites)
  (if (null? suites) '()
      (append (extract-suite-tests (car suites))
	      (extract-tests (cdr suites)))))  

(define (extract-names tests)
  (map car tests))

(define (run-test test)
  (display "TESTING: ")
  (display (car test))
  (newline)
  (let ((res (apply assert-eq (caddr test))))
    (if (not (car res))
	(begin
	  (display "Expected: ")
	  (display (car (cddddr res)))
	  (display " Got: ")
	  (display (cadddr res))
	  (newline)))
    (display "TEST ")
    (display (car test))
    (display (if (car res) ": SUCCESS" ": FAILURE"))
    (newline)
    (car res)))

(define (run-tests tests)
  (map run-test tests))

(define (filter expr seq)
  (cond ((null? seq) '())
	((expr (car seq)) (cons (car seq) (filter expr (cdr seq))))
	(else (filter expr (cdr seq)))))

(define (find-test name tests)
  (filter (lambda (test) (equal? name (car test))) tests))

(define (display-names tests)
  (map (lambda (name) (display name)(newline))
       (extract-names tests))
  #t)

(define (read-all-lines in)
  (let ((line (read-line in)))
    (if (eof-object? line) '()
	(cons line (read-all-lines in)))))

(define (line->result line)
  (let ((items (string-split line " ")))
    (list (car items) (string->number (cadr items)))))

(define (lines->results lines)
  (if (null? lines) '()
      (cons (line->result (car lines)) (lines->results (cdr lines)))))

(define (read-results results-file)
  (define in (open-input-file results-file))
  (let ((results (lines->results (read-all-lines in))))
    (close-input-port in)
    results))

(define (calculate-score results-file tests)
  (apply + (map * (map cadr (read-results results-file))
		(map cadr tests))))
       
(define (process-tests args tests)
  (cond ((is-list-tests args) (display-names tests))
	((is-score args) (display (calculate-score (is-score args) tests)))
	((is-run-test args)
	 (eval (cons and (run-tests (find-test (is-run-test args) tests)))))
	(else (eval (cons and (run-tests tests))))))

;; End of testing lib

(define (from-to from to)
  (if (>= from to) (cons from (from-to (- from 1) to))
      '()))

(define (generate-tests)
  (quasiquote ((0.8 (("T-0" ((unique-sums '()) 1))
		     ("T-1" ((unique-sums '(1 2)) 4))
		     ("T-2" ((unique-sums '(1 2 3)) 7))
		     ("T-3" ((unique-sums '(2 2 4)) 5))
		     ("T-4" ((unique-sums '(1 2 3 4 5 6 7 8 9 10)) 56))
		     ("T-5" ((unique-sums '(1 2 3 5 10)) 22))
		     ("T-6" ((unique-sums '(1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)) 21))
		     ("T-7" ((unique-sums '(1 2 4 8 16 32 64 128 256 512 1024 2048)) 4096))
		     ("T-8" ((unique-sums '(-13	34 0 90 80 -25 2 69)) 102))
		     ("T-9" ((unique-sums '(-396 -217 0 -251 -276)) 16))
		     ("T-10" ((unique-sums '(62 -21 -95 0 -26 -9 -4)) 60))))
	       ;(0.2 (("T-11" ((unique-sums '(1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 0)) 32768))
		     ;("T-12" ((unique-sums '(1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288)) 1048576))))
         )
  )
)


(if (not (process-tests (vector->list command-line-arguments)
			(extract-tests (generate-tests))))
    (exit 1))
