(define (cube-iter x guess)
    (if (good-enough? guess (improve x guess))
        guess
        (cube-iter x (improve x guess))))

(define (good-enough? old_guess new_guess)
    (> 0.01 
        (/ (abs (- old_guess new_guess)) old_guess)))

(define (improve x guess)
    (/ (+ (/ x (square guess)) (* 2 guess)) 3))

(define (cube x)
    (cube-iter x 1.0))