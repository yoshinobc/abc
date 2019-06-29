ct = nct = 0
abc = "abcdefghijklmnopqrstuvwxyz"
num = int(input())
for i in range(num):
    flag = True
    str = input()
    for c in range(len(str)):
        if(str[c] == "("):
            lists = []
            clists = []
            while(str[c] != ")"):
                if(str[c] in abc):
                    #print(lists)
                    #print(clists)
                    if(str[c-1] == "~"):
                        if(str[c] in lists):
                            flag = False
                        clists.append(str[c])
                    else:
                        if(str[c] in clists):
                            flag = False
                        lists.append(str[c])
                c+=1
        if(str[c] == "|"):
            if(not flag):
                flag = True
            else:
                break

    if(flag):
        print("YES")
    else:
        print("NO")
