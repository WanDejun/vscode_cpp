def f(n):
    if n <= 2:
        return 1
    (a, b, c) = (1, 1, 2)
    for i in range(2, n):
        c = a + b
        a = b
        b = c
    return c


print(str(f(93)))
