.data

n:    .word 10

.text

main:
    addi  s3, zero, 0
    lw    s4, n
    j     tribonacci

tribonacci:
    # default
    beqz  s4, print   # if (n == 0)
    addi  s3, zero, 1
    addi  s4, s4, -1
    beqz  s4, print   # if (n == 1)
    addi  s4, s4, -1
    beqz  s4, print   # if (n == 2)
    # start from n = 3
    addi  s0, zero, 1 # T_(n-3)
    addi  s1, zero, 1 # T_(n-2)
    addi  s2, zero, 2 # T_(n-1)
    addi  s3, zero, 2 # T_(n)
    j     loop

loop:
    # for loop
    addi  s4, s4, -1
    beqz  s4, print   # check ending condition
    add   s3, s1, s0  # implement
    add   s3, s3, s2  # T_(n) = T_(n-1) + T_(n-2) + T_(n-3)
    mv    s0, s1      # T_0 = T_1
    mv    s1, s2      # T_1 = T_2
    mv    s2, s3      # T_2 = T_3
    j     loop

print:
    # print the result
    mv    a0, s3
    li    a7, 1
    ecall
    j     exit

exit:
    li    a7, 10
    ecall