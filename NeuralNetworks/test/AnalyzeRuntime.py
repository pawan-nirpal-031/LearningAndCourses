import decimal

def ClangRuntime():
    f = open('clanglog.txt')
    lst = []
    for line in f:
        lst = line.split(' ')
    lst.pop()
    avg = 0
    for n in lst:
        avg+=decimal.Decimal(n)
    avg = avg/len(lst)
    print(avg)

def GccRuntime():
    f = open('gcclog.txt')
    lst = []
    for line in f:
        lst = line.split(' ')
    lst.pop()
    avg = 0
    for n in lst:
        avg+=decimal.Decimal(n)
    avg = avg/len(lst)
    print(avg)

def AoccRuntime():
    f = open('aocclog.txt')
    lst = []
    for line in f:
        lst = line.split(' ')
    lst.pop()
    avg = 0
    for n in lst:
        avg+=decimal.Decimal(n)
    avg = avg/len(lst)
    print(avg)

GccRuntime()
