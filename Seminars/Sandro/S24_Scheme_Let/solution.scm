;1 reverse duplicate

;; (define (dup lst)
;;   (append lst lst)
;;   )

(define (reverseDup lst)
  ((lambda (rlst) (append rlst rlst)) (reverse lst))
  )


  ;; (let 
	 ;; (
	 ;;  (rlst (reverse lst)) ; rlst  <- (reverse lst)
	 ;;  )
	 ;;  (append rlst rlst)
	 ;; )
  ;; )


(define (binpow a b)
  (if (= b 0) 1
	 (let 
		(
		 (c (binpow a (div b 2))) ; c <- pow(a, b/2)
		 )
		(if (= (remainder b 2) 0) (* c c)
		  (* c c a)
		  )
		)
	 )
  )


;; (define (fib n)
;;   (if (<= n 1) n ; 0 -> 0 1 -> 1
;; 	 (+ (fib (- n 1)) (fib (- n 2)))
;; 	 )
;;   )

(define (fib n)
  (let loop
	 (
	  (a 0)
	  (b 1)
	  (i 0)
	  )
	 (if (= i n) a
		(loop b (+ a b) (+ i 1))
	  )
	 )
  )

(define (partition k lst)
  (if (null? lst) '( () () )
	  (let*
		 (
		  (splitlists (partition k (cdr lst))) ;splitlists <- ((1 2) (3 4)) -cdr-> ((3 4)) -car-> (3 4)
		  (first (car splitlists))
		  (second (cadr splitlists))
		  )
		 (if (< (car lst) k)
			(list (cons (car lst) first)  second                  ) ; true
			(list first                   (cons (car lst) second) ) ; false
			)
		 )
	 )
  )


(define (filter_ filter_fn lst)
  (cond 
	 ((null? lst) '())
	 ((filter_fn (car lst)) (cons (car lst) (filter_ filter_fn (cdr lst)) )  ) ; true means keep
	 (else (filter_ filter_fn (cdr lst)))
	 )
  )

(define (removeallx x l)
  (filter_ (lambda (e) (not (= x e))) l  )
  )

(define (removeallx x l)
  (filter_ (lambda (e) (not (= x e))) l  )
  )

(define (permutation? l1 l2)
  (cond 
	 ((and (null? l1) (null? l2)) #t)
	 ((not (= (length l1) (length l2))) #f)
	 (else (permutation? (removeallx (car l1) l1) (removeallx (car l1) l2) ))
	 )
  )
;;



(define (get_neighbours g x)
  (apply append (map
	 (lambda (edge)
		(
		 let
		 (
		  (a (car edge))
		  (b (cadr edge))
		  )
		 (cond
			((= a x) (list b))
			((= b x) (list a))
			(else '())
			)
		 )
		)
	 g
	 ))
  )

(define (contains lst x)
  (eval (cons or (map (lambda (elem) (= x elem)) lst)))
  )

(define (bfs g end q visited) ; -> t/f
  (cond
	 ((null? q) #f)
	 ((= (car q) end) #t)
	 ;; if (car q) in visited; 
	 ((contains visited (car q))   (bfs 
				g 
				end 
				(cdr q)
				visited
				))
	 (else (bfs 
				g 
				end 
				(append (cdr q) (get_neighbours g (car q)))
				(cons (car q) visited)
				)
			 )
	)
  )


(define (isWay? g start end)
  (bfs g end (list start) '())
  )






