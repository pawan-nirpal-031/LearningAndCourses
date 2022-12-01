#!/usr/bin/python
# -*- coding: utf-8 -*-

from collections import namedtuple
from subprocess import * 
import os 
Item = namedtuple("Item", ['index', 'value', 'weight'])

def solve_it(inputData):
    # Write inputData to a temporary file

    tmpFileName = 'tmp.data'
    tmpFile = open(tmpFileName, 'w')
    tmpFile.write(inputData)
    tmpFile.close()

    # Run the command: 
    process = Popen(['./Solver', tmpFileName], stdout=PIPE)
    (stdout, stderr) = process.communicate()


    # remove the temporary file
    os.remove(tmpFileName)

    return stdout.strip()



if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        file_location = sys.argv[1].strip()
        with open(file_location, 'r') as input_data_file:
            input_data = input_data_file.read()
        print(solve_it(input_data))
    else:
        print('This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/ks_4_0)')

