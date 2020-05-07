def main():
    h = -1
    while (not check(h)):
        h = input("Height: ")

    h = int(h)
    for i in range(h):
        print(" " * (h - i - 1), end="")
        print("#" * (i + 1), end="")
        print("  ", end="")
        print("#" * (i + 1), end="")
        print()


def check(n):
    try:
        n = int(n)
        if (n <= 0 or n > 8):
            return 0
    except ValueError:
        return 0
    else:
        return 1


main()