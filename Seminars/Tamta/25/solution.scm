; reverse and duplicate list
(define (reverseDup lst)
    (let 
        ((reversed (reverse lst)))
        (append reversed reversed)
    )
)

; a^b in O(log(n))
(define (binpow a b)
    (cond 
        ((zero? b) 1)
        ((= b 1) a)
        (else 
            (* 
                (let
                    ((a_pow_b_div2 (binpow a (quotient b 2))))
                    (* a_pow_b_div2 a_pow_b_div2)
                )
                (binpow a (remainder b 2))
            )
        )
    )
)

; fibonacci
(define (fib n)
    (let loop
        ((a 0) (b 1) (count 0))
        (if 
            (= n count) a
            (loop b (+ a b) (+ count 1))
        )
    )
)

; partition with two passes over lst. We can do with one pass with (exrecursion
(define (partition n lst)
    (list
        (apply append (map (lambda (elem) (if (< elem n) (list elem) '())) lst))
        (apply append (map (lambda (elem) (if (>= elem n) (list elem) '())) lst))
    )
)