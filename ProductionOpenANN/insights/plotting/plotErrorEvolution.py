import matplotlib.pyplot as plt 

log = open("../../logs/ouputlogs/log8.log")

def isFloat(s):
   try:
      float(s)
      return True
   except:
      return False

error = []
x = []
for line in log: 
    if(line[-1]=='\n'):
        line = line[:-1]
    sent = line.split(' ')
    if(len(sent)==1 and isFloat(sent[0])):
       error.append(sent[0])

for i in range(len(error)):
   x.append(i)

plt.plot(x,error)
plt.savefig("error_log8.png")