import cs50
import re


def main():
    cardNum = "JUST FOR WHILE LOOP"
    while not cardNum.isdigit():
        cardNum = cs50.get_string("Number: ")

    length = len(cardNum)
    if length is 15:
        if re.search("^34|37", cardNum):
            brand = "AMEX"
    if length is 16:
        if re.search("^51|52|53|54|55", cardNum):
            brand = "MASTERCARD"
    if length is 16 or 13:
        if re.search("^4", cardNum):
            brand = "VISA"

    luhnSum = 0
    end1 = 0
    end2 = -1
    if (length % 2 == 0):
        end1 = -1
        end2 = 0

    for i in range(length - 2, end1, -2):
        temp = str(int(cardNum[i]) * 2)
        for c in temp:
            luhnSum += int(c)

    for i in range(length - 1, end2, -2):
        luhnSum += int(cardNum[i])

    if (luhnSum % 10) == 0:
        print(brand)
    else:
        print("INVALID")


main()