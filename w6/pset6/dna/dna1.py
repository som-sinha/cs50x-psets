# Modules
import csv
import sys


def main(argv):
    # Check for correct usage

    if (len(argv) == 3):

        # str, here is Short Tandem Repeat (jargon from Biology)
        DBdictList, strsInDB, checkSeq = load(argv[1], argv[2])

        # create an entry for user input
        inSeqDict = {}

        # Go through the STRs and input seq to check for largest consequtive match

        for STR in strsInDB:
            STRlen = len(STR)
            tmpCt = 0
            consecCt = 0
            #enumerate because this won't be a consistent iteration
            for i, c in enumerate(checkSeq):
                # a way to shorten iteration also will check for consecutiveness
                if c is STR[0]:

                    # if the substring is equal to the STR
                    if checkSeq[i:(STRlen + i)] == STR:

                        # update temporary count when a match found
                        tmpCt += 1
                else:

                    #consecutiveness
                    tmpCt = 0
                # store in final counter so that only consecutive repitition count is stored
                consecCt = tmpCt if consecCt < tmpCt else consecCt
            inSeqDict[str(STR)] = str(consecCt)

        # print(check(DBdictList, strsInDB))

    else:

        # Report incorrect usage
        print("Usage: python dna.py path/to/csv file path/to/dna sequence")


def load(addrOfDB, addrOfSeq):

    # Loading sequence first

    with open(addrOfSeq, 'r') as seqFile:

        checkSeq = seqFile.readline()

    # Then opening the csv DB

    with open(addrOfDB, 'r', newline='') as DBfile:

        # Reading the STR names

        reader = csv.reader(DBfile)

        row = next(reader)

        strsInDB = []

        for s in row[1:]:
            strsInDB.append(s)

        # Going back to the beginning of the csv
        DBfile.seek(0)

        # Reading all of the data into a list of dictionaries

        dictReader = csv.DictReader(DBfile)

        # Declaring a list of dictionaries
        DBdictList = [{}]

        for row in dictReader:
            DBdictList.append(row)

    return DBdictList, strsInDB, checkSeq

# check the database for a person with the same STR patterns

def check(DBdictList, strsInDB):
    
    




if __name__ == "__main__":

    main(sys.argv)