(define (closest-node lst) 
    (cond 
        ((null? lst) 0)
        ((null? (cadr lst)) (car lst))
        (else (+ (car lst) (apply min (map closest-node (cadr lst)))))
    )
)