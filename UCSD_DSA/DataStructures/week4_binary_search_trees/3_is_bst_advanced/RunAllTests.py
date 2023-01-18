import os

def CreateTestFiles(tests=0):
    for test in range(tests+1):
        if(test==0):
            continue
        command = "touch input"+str(test)+".sh"
        os.system(command)    

def RunOnAllCppTests(source_file,tests):
    build_command = "g++ "+source_file + ".cpp -o " + source_file
    os.system(build_command)
    for test in range(tests+1):
        if(test==0): 
            continue
        command = "./"+source_file +" < "+ "input"+str(test)+".sh"
        os.system(command)

