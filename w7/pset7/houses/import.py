# modules
import sys
import csv
import cs50


# main function
def main(argv):

    if len(argv) != 2:

        print("Usage: python import.py /PATH/TO/.csv")

    else:

        # Create Database

        open("students.db", 'w').close()

        db = cs50.SQL("sqlite:///students.db")

        # Create Table

        with open(argv[1], 'r') as csv_in:

            headings = csv_in.readline()

            headingsSplit = headings.split(",")

            db.execute("CREATE TABLE students (first, middle, last, house, birth)")

            reader = csv.reader(csv_in)

            for row in reader:

                nameSplit = row[0].split()

                if len(nameSplit) == 2:

                    fname = nameSplit[0]

                    lname = nameSplit[1]

                    db.execute("INSERT INTO students VALUES(?, NULL, ?, ?, ?)",
                               fname, lname, row[1], int(row[2]))

                elif len(nameSplit) == 3:

                    fname = nameSplit[0]

                    mname = nameSplit[1]

                    lname = nameSplit[2]

                    db.execute("INSERT INTO students VALUES(?, ?, ?, ?, ?)",
                               fname, mname, lname, row[1], int(row[2]))


if __name__ == "__main__":

    main(sys.argv)
