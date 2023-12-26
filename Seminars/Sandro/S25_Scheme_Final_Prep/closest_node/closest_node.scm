;; (define (closest-node node)
;;   (+ (car node) 
;;
;; 				  (apply min (cons 0 (map
;; 				 (lambda (subtree)
;; 					(closest-node subtree)
;; 					)
;; 				 (cadr node)
;; 				 ))
;;
;; 		 )
;;
;; 	  )
;; 	)


(define (closest-node node)
  (+ (car node) 

	  (if (null? (cadr node)) 0
				  (apply min (map
				 closest-node
				 (cadr node)
				 ))

		 )

	  )
	)
