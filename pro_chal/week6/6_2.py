abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "

lines = []
while True:
    line = input()
    if line == "#":
         break
    lines.append(line)
line = input()
#print(lines)
best = len(line)
for k in range(27):
    _line = ""
    for c in line:
        n = abc.find(c)
        n = (n + k) % 27
        _c = abc[n]
        #print(c,_c)
        _line += _c
    #print(_line)
    for l in lines:
        #print(l)
        #print(_line.find(l))
        if(_line.find(l) != -1):
            _line = _line.replace(l,"")
            #print(best,len(_line))
            if(best > len(_line)):
                best = len(_line)
                key = k
                break
    #print()
#print(key)
str = ""
lists = []
for c in line:
    n = abc.find(c)
    n = (n + key) % 27
    _c = abc[n]
    if(_c == " "):
        lists.append(str)
        str = ""
    str += _c
    if(str == " "):
        str = ""
lists.append(str)
#print(lists)
c = 0
flag = True
for i,l in enumerate(lists):
    if(len(l)-1 + c >= 60):
        print()
        c = 0
        flag = True
    else:
        if(not flag):
            print(" ",end="")
    flag = False
    print(l,end = "")
    if(i == len(lists)-2):
        break
    c += len(l)+1
print()
