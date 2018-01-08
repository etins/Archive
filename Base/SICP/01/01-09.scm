(define (+ a b)
    (if (= a 0))
        b
        (inc (+ (dec a) b)))

(define (+ a b)
    (if (= a 0)
        b
        (+ (dec a) (inc b))))

(+ 4 5)

; 第一个是一个递归计算过程，第二个是迭代计算过程