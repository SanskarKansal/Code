n=int(input("enter the number of elements in list : "))
l1=[]
l2=[]
print("input for list 1")
for i in range(0,n):
    x=input()
    l1.append(x)
print("input for list 2")
for i in range(0,n):
    y=input()
    l2.append(y)
for i in range(0,n):
    x=l1[i]
    l1.append(x)
for i in range(0,n):
    y=l1[i]
    l1.append(y)
a=0
c=0
p=0
for i in range(0,n):
    if(l1[i]==l2[0]):
        a=i
        for i in range(0,n):
            if(l1[a+i]==l2[i]):
                c+=1
                if(c==n):
                    print("true")
                    p=1
if(p==0):
    print("false")