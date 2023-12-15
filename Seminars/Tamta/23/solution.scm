(define (reverse_ lst)
    (if 
    (null? lst) '()
    (append (reverse_ (cdr lst)) (list (car lst)))
    )
)

(define (sorted? lst)
    (cond
        ((< (length lst) 2) #t)
        ((< (car lst) (cadr lst)) (sorted? (cdr lst)))
        (else #f)
    )
)

(define (max_ lst)
    (cond
        ((null? lst) 0)
        ((< (car lst) (max_ (cdr lst))) (max_ (cdr lst)))
        (else (car lst))
    )
)

(define (filter_ func lst)
    (cond
        ((null? lst) lst)
        ((func (car lst)) (cons (car lst) (filter_ func (cdr lst))))
        (else (filter_ func (cdr lst)))
    )
)

(define (divisible_by_3? elem)
    (zero? (remainder elem 3)) 
)

(define (max_divisible3 lst)
    (max_ (filter_ divisible_by_3? lst))
)

(define (range k)
    (cond
        ((zero? k) '())
        (else (append (range (- k 1)) (list k)))
    )
)

(define (pow a n)
    (cond
        ((zero? n) 1)
        (else (* (pow a (- n 1)) a))
    )
)

(define (generate_powers a k )
    (if
    (= 1 k) (list a)
    (append (generate_powers a (- k 1)) (list (pow a k)))
    )
)

(define (generate_powers_map a k )
    (map (lambda (elem) (pow a elem)) (range k))
)




