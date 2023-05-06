from random import randrange

with open("input.txt", "w") as f:
    f.write("100000\n")
    for i in range(100000):
        f.write(f"{randrange(0, 8)}")
    f.write("\n100000\n")
    for i in range(100000//2):
        f.write("1 1 100000 1 100000 8\n")
        f.write("2 1 100000 1 100000 8\n")