; partition with recursion
(define (partition n lst)
    (if (null? lst) '(()())
        (let
            ((elem (car lst)) (rest_ans (partition n (cdr lst))))
            (cond
                ((< elem n) 
                    (list
                        (cons elem (car rest_ans))
                        (cadr rest_ans)
                    )
                )
                (else
                    (list
                        (car rest_ans)
                        (cons elem (cadr rest_ans))
                    )
                )
            )
        )
    )
)

; is lst2 permutation of lst1
(define (permutation? lst1 lst2)
    (cond
        ((and (null? lst1) (null? lst2)) #t)
        ((not (= (length lst1) (length lst2))) #f)
        (else (permutation? (remove (car lst1) lst1) (remove (car lst1) lst2)))
    )
)

(define (remove elem lst)
    (apply append (map (lambda (x) (if (= x elem) '() (list x))) lst))
)

; isWay with bfs
(define (isWay? edges start finish)
    (bfs edges (list start) (list start) start finish)
)

(define (bfs edges queue visited start finish)
    (cond
        ((= start finish) #t)
        ((null? queue) #f)
        (else
            (let ((neighbours (get_neighbours edges visited start)))
                (bfs
                    edges
                    (append (cdr queue) neighbours)
                    (append visited neighbours)
                    (car queue)
                    finish
                )
            )
        )      
    )
)

(define (get_neighbours edges visited node)
    (apply append 
        (map
            (lambda (pair)
                (cond 
                    (
                        (and 
                            (= (car pair) node)
                            (not (contains (cadr pair) visited))
                        )
                        (list (cadr pair))
                    )
                    (
                        (and 
                            (= (cadr pair) node)
                            (not (contains (car pair) visited))
                        )
                        (list (car pair))
                    )
                    (else '())
                )
            )
            edges
        )
    )
)

; "apply or" doesn't work because "or" is not a function (check with (procedure? or))
(define (contains elem lst)
    (eval (cons or (map (lambda (x) (= elem x)) lst)))
)