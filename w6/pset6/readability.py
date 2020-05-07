from cs50 import get_string
from re import sub


def main():
    text = get_string("Text: ")
    l = letters(text)
    w = words(text)
    s = sen(text)

    print(l, w, s)

    L = (l * 100) / w
    S = (s * 100) / w

    coleLiau = round((0.0588 * L) - (0.296 * S) - 15.8)
    if coleLiau >= 16:
        print("Grade 16+")
    elif coleLiau < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {coleLiau}")


def letters(text):
    ls = 0
    for c in text:
        if (c.isalpha()):
            ls += 1
    return ls


def words(text):
    count = 1
    for c in (sub(" +", " ", text)):
        if c is " ":
            count += 1
    return count


def sen(text):
    count = 0
    for c in (sub("\.+", ".", text)):
        if c is "." or c is "?" or c is "!":
            print(c)
            count += 1
            print(count)
    return count


main()