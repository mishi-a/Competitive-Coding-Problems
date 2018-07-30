t = int(input())
while t>0:
    str = input();
    val = str.split()
    for i in range(len(val)):
        if(i==len(val)-1):
            new = val[i][1:]
            new = new.lower()
            #print (new)
            x = val[i][0]
            x = x.upper()
            print(x+new)
        else :
            val[i] = val[i].capitalize()
            print(val[i][0]+". ",end="")
    t-=1;
    
