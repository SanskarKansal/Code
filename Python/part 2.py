import math
l=[]
n=int(input("enter number of chocholate box: "))
for i in range(n):
    a=int(input("enter the number of chocholates: "))
    l.append(a)
l.sort()
m=int(input("enter the number of students: "))
if(m>n):
    print("incorrect value")
else:
    i=0
    k=m
    d=[]
    c=[]
    while((i+k-1)<n):
        d.append(l[i+k-1]-l[i])
        c.append(i)
        i+=1
    min=0
    s=0
    for i in range(n):
        if(l[i]<min):
            min=d[i]
            s=i
    for i in range(s+1,s+m+1):
        print(l[i])
