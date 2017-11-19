# Author: Alex R. Mead
# Date: November 2017
# Description: This simply python program will generate large text files which
# we can use to the performance of <vector> vs. <list> usage in our CPP programs.

# modules
import random


# file generation parameters
numberOfStudents = 10000
numberOfHomeworkGrades = 10
percentageOfFailingStudents = 3

def main():
    fileName = 'studentFile_' + str(numberOfStudents) + '.dat'
    f = open(fileName,'w')

    print("Generating file contents \n")
    for i in range(0,numberOfStudents,1):
        name = str(int(random.getrandbits(8)))
        midterm = str(int(random.uniform(0,100)))
        final = str(int(random.uniform(0,100)))
        hwGrades = ''
        for j in range(1,numberOfHomeworkGrades-1,1):
            hwGrades = hwGrades + str(int(random.uniform(0,100))) + ' '

        hwGrades = hwGrades + str(int(random.uniform(0,100))) + '\n'
        f.write(name + ' ' + midterm + ' ' + hwGrades)

    f.close()
    print("File generated \n")

    return 0



# Boiler plate used to run script as function.
if __name__ == "__main__":
    main()