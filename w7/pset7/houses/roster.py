# Modules
import cs50
import sys


# Main Function
def main(argv):
    # Checking for correct input

    if len(argv) != 2:

        print("Usage: python3 roster.py \"House Name\"")

    else:

        # Getting values

        dbStudents = cs50.SQL("sqlite:///students.db")

        dbDictList = dbStudents.execute(
            "SELECT first, middle, last, birth FROM students WHERE house == ? ORDER BY last ASC, first ASC", argv[1])

        for row in dbDictList:
            print(f"{row['first']}", end=" ")
            if row['middle']:
                print(f"{row['middle']}", end=" ")
            print(f"{row['last']}, born {row['birth']}")


# Running main() in the beginning
if __name__ == "__main__":

    main(sys.argv)
