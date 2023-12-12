; 1
(define (first-elem lst)
    (if (null? lst) "None"
        (car lst)
    )
    ; implementation with cond below:
    ; (cond
    ;     ((null? lst) "None"))
    ;     (else (car lst))
    ; )
)

; 2
(define (abs_ x)
    (if (negative? x) (- x)
        x
    )
)

; 3
(define (right-triangle lst)
    (equal?
        (+
            (square (car lst))
            (square (cadr lst))
        )
        (square (caddr lst))
    )
)

; 4
(define (last-elem lst)
    (cond
        ((null? lst) "None")
        ((null? (cdr lst)) (car lst))
        (else (last-elem (cdr lst)))
    )
)

; 5
(define (length_ lst)
    (if (null? lst) 0
        (+ 1 (length_ (cdr lst)))
    )
)

; 6
(define (k-th-element lst k)
    (cond
        ((null? lst) "None")
        ((zero? k) (car lst))
        (else (k-th-element (cdr lst) (- k 1)))
    )
)

; 7
(define (filter-range lst a b)
    (cond
        ((null? lst) lst)
        ((> a b ) (filter-range lst b a))
        (
            (and 
                (>= (car lst) a)
                (<= (car lst) b)
            )
            (cons (car lst) (filter-range (cdr lst) a b))
        )
        (else (filter-range (cdr lst) a b))
    )
)

; 8
(define (prime? n)
    (if 
        (equal? n 1) #f 
        (prime_helper n 2)
    )
)

(define (prime_helper n k)
    (cond
        ((> k (sqrt n)) #t)
        ((zero? (remainder n k)) #f)
        (else 
            (prime_helper n (+ 1 k))
        )
    )
)

; 9 - next seminar
(define (primes? lst)
    (if (null? lst) lst
        (cons (prime? (car lst)) (primes? (cdr lst)))
    )
)