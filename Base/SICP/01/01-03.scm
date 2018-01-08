(define (sum-of-biggertwo x y z)
      (cond ((and (< x y) (< x z))  (+ y z))
            ((and (< y x) (< y z))  (+ x z))
            (else (+ x y))
      )
)

(sum-of-biggertwo 1 2 3)
