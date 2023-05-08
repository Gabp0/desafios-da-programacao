from random import randrange

n = randrange(1, 10000)
q = randrange(1, 10000)

with open("input.txt", "w") as f:
    f.write(f"{n}\n")
    for i in range(n):
        f.write(f"{randrange(0, 10)}")
    f.write(f"\n{q}\n")
    for i in range(q):
        op = randrange(1, 4)
        if op == 1 or op == 2:
            a1 = randrange(0, n+1)
            b1 = randrange(a1, n+1)
            a2 = randrange(0, n+1)
            b2 = randrange(a2, n+1)
            f.write(f"{op} {a1} {b1} {a2} {b2} {randrange(1, 9)}\n")
        elif op == 3:
            a = randrange(0, n+1)
            b = randrange(1, 10)
            f.write(f"{op} {a} {b}\n")