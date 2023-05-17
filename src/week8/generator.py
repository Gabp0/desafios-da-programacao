from random import randrange

n = 100000

with open("input.txt", "w") as f:
    f.write(f"{n}\n")
    for i in range(1, 5000):
        f.write(f"1 {i}\n")
    for i in range(2, 4999):
        f.write(f"2 {i}\n");
    f.write("2 1\n");

    for i in range(5000, 10000):
        f.write(f"1 {i}\n")
    for i in range(5001, 9999):
        f.write(f"2 {i}\n");
    f.write("2 5000\n");