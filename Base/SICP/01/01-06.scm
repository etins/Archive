(define (new-if predicate then-clause else-caluse)
    (cond (predicate then-caluse)
          (else else-caluse)
    )
)

(new-if (= 2 3) 0 5)

(define (sqrt-iter guess x)
    (new-if (good-enough? guess x)
        guess
        (sqrt-iter (improve guess x)
                    x)))

(define (improve guess x)
    (average guess (/ x guess)))


(define (average x y)
    (/ (+ x y) 2))

(define (good-enough? guess x)
    (< (abs (- (square guess) x)) 0.001))

(define (sqrt x)
    (sqrt-iter 1.0 x))


(sqrt 9)

; Aborting!: maximum recursion depth exceeded
; 定义这个 new-if 会导致在执行 new-if 这个过程时候会计算两种情况的值，会一直迭代下去；而对于 if 做了特殊的优化，只执行满足条件的语句。  
