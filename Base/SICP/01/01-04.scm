(define (a-plus-abs-b a b)
    ((if (> b 0) + -) a b)
)

; 该过程是求 a + |b|
; 第一个 if 是根据 b 的正负返回一个符号，如果 b < 0, 那么返回一个 - 号，此时为  a - b; 否则为 a + b.