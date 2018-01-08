; 对于特别小的数，并不能给出正确答案
; 对于特别大的数，因为对比的猜测值和真实值之间的差，所以会进入死循环

(define (sqrt-iter guess x)
    (if (good-enough? guess (improve guess x))
        guess
        (sqrt-iter (improve guess x)
                    x)))

(define (improve guess x)
    (average guess (/ x guess)))


(define (average x y)
    (/ (+ x y) 2))

(define (good-enough? old_guess new_guess)
    (> 0.01
        (/ (abs (- new_guess old_guess)) 
            old_guess)))

(define (sqrt x)
    (sqrt-iter 1.0 x))


(sqrt 0.00009)
