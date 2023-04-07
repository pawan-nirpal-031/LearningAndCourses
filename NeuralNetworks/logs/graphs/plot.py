import matplotlib.pyplot as plt 

file = open('logs/training/log3.log')

x = []
y = []
for line in file:
    if(line[-1]=='\n'):
        line = line[:-1]
    tup = line.split(' ')
    if(tup[0]=='[]' or tup[1]=='[]'):
        continue
    x.append(int(tup[0]))
    y.append(float(tup[1]))

plt.plot(x,y)
plt.savefig('/home/pnirpal/Workspace/Learning/Courses/NeuralNetworks/logs/graphs/training3.png')
