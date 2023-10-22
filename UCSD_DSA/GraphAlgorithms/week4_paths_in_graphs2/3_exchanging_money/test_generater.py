import os
import random

# Specify the directory path where you want to search for files
directory_path = '/home/panirpal/workspace/Learning/Courses/UCSD_DSA/GraphAlgorithms/week4_paths_in_graphs2/3_exchanging_money'

# List all files in the directory
files = os.listdir(directory_path)

# Filter files that start with "input"
input_files = [file for file in files if file.startswith("input")]

# Print the names of the input files


nextTest = 0
for file in input_files:
    nextTest = max(nextTest,int(file[-5]))
nextTest+=1

nextTestFile = "input"+str(nextTest)+".txt"

def generateTestCase(File):
    nLim = 10
    eLim = 20
    wRange = 6 # -6 to 6 and not 0 
    nodes = random.randint(5,nLim)
    edges = random.randint(8,eLim)
    edgeList = []
    for e in range(edges):
        nd1 = random.randint(1,nodes)
        nd2 = random.randint(1,nodes)
        if(nd1==nd2):
            nd2 = random.randint(1,nodes)
            if(nd1==nd2): # now the probablity will be very less for self loop
                nd2 = random.randint(1,nodes)
        w = random.randint(1,wRange)
        sign = random.randint(0,1)
        if(sign==0):
            w = -w
        if(w==0):
            w = random.randint(1,wRange)
            sign = random.randint(0,1)
            if(sign==0):
                    w = -w
            if(w==0):
                sign = random.randint(0,1)
                w =  ((random.randint(1,wRange)+10)%6)
                if(sign==0):
                    w = -w
        edgeList.append([nd1,nd2,w])
    for e in range(len(edgeList)):
        for eo in range(len(edgeList)):
            if(e==eo):
                continue
            if(edgeList[e][0]==edgeList[eo][1] and edgeList[e][1]==edgeList[eo][0]):
                if(eo<len(edgeList)):
                    edgeList.pop(eo)
    # nodesFinal = 0 
    # edgesFinal = len(edgeList)
    # for edge in edgeList:
    #     pass
    #     #nodesFinal = max(nodesFinal,max(edge[0],edge[1]))
    # print(nodesFinal,edgesFinal)
    # print(edgeList)

try:
    with open(nextTestFile,'w') as file:
        generateTestCase(file)
except Exception as e:
    print(e)