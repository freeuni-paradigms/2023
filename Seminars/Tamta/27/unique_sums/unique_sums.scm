(define (unique-sums lst)
    (length (unique-sums-helper lst))
)

(define (merge lst1 lst2)
    (cond
        ((null? lst1) lst2)
        ((null? lst2) lst1)
        ((< (car lst1) (car lst2)) (cons (car lst1) (merge (cdr lst1) lst2)))
        ((> (car lst1) (car lst2)) (cons (car lst2) (merge lst1 (cdr lst2))))
        (else (merge (cdr lst1) lst2))
    )
)

(define (unique-sums-helper lst)
    (cond
        ((null? lst) (list 0))
        (else 
            (let
                ((sublist_sums (unique-sums-helper (cdr lst))))
                (merge
                    (map (lambda (elem) (+ elem (car lst))) sublist_sums)
                    sublist_sums
                )
            )
        )
    )
)