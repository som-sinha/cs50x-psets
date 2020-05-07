# Modules
import csv
import sys

# Global Variables
STR = []


def main(argv):
    # Check for correct usage
    if (len(argv) == 3):

        dataDict = load(argv[1])
        with open(argv[2]) as dnaSeqFile:
            dnaSeq = dnaSeqFile.readline()
        seqDict = {}

        for i in range(len(STR)):
            consecCount = 0
            tmp = 0
            j = 0

            while j < len(dnaSeq):
                if dnaSeq[j] is STR[i][0]:
                    if (dnaSeq[j:(j + len(STR[i]))]) == STR[i]:
                        tmp += 1
                        j = j + len(STR[i]) - 1
                    if tmp > consecCount:
                        consecCount = tmp
                else:
                    tmp = 0
                j += 1

            seqDict[STR[i]] = consecCount

        for row in dataDict:
            tmp = 0
            for seq in STR:
                if int(row[seq]) is seqDict[seq]:
                    tmp += 1
                if tmp is len(STR):
                    print(row["name"])
                    return
        print("No match")
    else:
        # Report incorrect usage
        print("Usage: python dna.py path/to/csv file path/to/dna sequence")


def load(loc):
    cRead = csv.reader(open(loc, "r"))
    row1 = next(cRead)

    for i in range(1, len(row1)):
        STR.insert(i-1, row1[i])

    return csv.DictReader(open(loc, "r"))

if __name__ == "__main__":
    main(sys.argv)