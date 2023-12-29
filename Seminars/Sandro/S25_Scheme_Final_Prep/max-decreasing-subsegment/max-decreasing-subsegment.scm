(define (last-elem lst)
  (if (null? (cdr lst)) (car lst)
    (last-elem (cdr lst))
  )
)

(define (push-back sequence elem)
  (append sequence (list elem))
)

(define (get-result-equal a b)
  (cond ((null? a) #t)
	((> (car a) (car b)) #t)
	((< (car a) (car b)) #f)
	(else (get-result-equal (cdr a) (cdr b))))
)

(define (get-result curr-mds curr-result)
  (if (> (length curr-mds) (length curr-result)) curr-mds
    (if (< (length curr-mds) (length curr-result)) curr-result
      (if (get-result-equal curr-mds curr-result) curr-mds
        curr-result
      )
    )
  )
)

(define (mds-rec sequence curr-mds curr-result)
  (if (null? sequence) curr-result
    (if (> (last-elem curr-mds) (car sequence)) (mds-rec (cdr sequence) (push-back curr-mds (car sequence)) (get-result (push-back curr-mds (car sequence)) curr-result))
      (mds-rec (cdr sequence) (list (car sequence)) (get-result curr-result (list (car sequence))))
    )
  )
)

(define (max-decreasing-subsegment sequence)
  (mds-rec (cdr sequence) (list (car sequence)) (list (car sequence)))
)
