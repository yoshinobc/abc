v = [0 for _ in range(1005)]
v[0] = v[1] = 1
for i in range(2,1005):
    v[i] = 0
    for j in range(i):
        v[i] = v[i] + v[j] * v[i-j-1]
while(True):
    try:
        a = input()
        if(a == ""):
            break
    except EOFError:
        break
    print(v[int(a)])
