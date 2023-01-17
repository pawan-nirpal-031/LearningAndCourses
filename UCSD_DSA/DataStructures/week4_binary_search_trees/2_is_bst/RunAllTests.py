import os 

tests = int(input("enter number of tests"))

os.system("g++ is_bst.cpp -o is_bst")
for test in range(tests+1):
    if(test==0): 
      continue
    command = "./is_bst < "+ "input"+str(test)+".sh"
    os.system(command)