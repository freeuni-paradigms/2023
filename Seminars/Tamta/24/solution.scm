; 1
(define (digits a)
    (if 
        (< a 10) (list a)
        (append 
            (digits (quotient a 10))
            (list (remainder a 10))
        )
    )
)

(define (list_power lst)
    (map (lambda (elem) (expt elem (length lst))) lst)
)

(define (sum lst)
    (apply + lst)
)

(define (narcisisstic? n)
    (equal? n (sum (list_power (digits n))))
)

; 2
(define (count a lst)
    (sum
        (map (lambda (elem) 
            (if (equal? elem a) 1
                0
            ))
        lst
        )
    )
)

(define (set lst)
    (cond 
        ((null? lst) lst)
        ((equal?
            0
            (count (car lst) (set (cdr lst)))
        )
        (cons (car lst) (set (cdr lst)))
        )
        (else (set (cdr lst)))
    )
)

(define (frequency lst)
    (map (lambda (elem) (list elem (count elem lst))) (set lst))
)

; 3
(define (mul_helper n elem)
    (if (= n 0) '()
            (cons elem (mul_helper (- n 1) elem)
        )
    )
)

(define (multiply n lst) 
    (apply append (map 
        (lambda (elem) (mul_helper n elem)) 
    lst))
)