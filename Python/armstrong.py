n=int(input("enter the number:  "))
d=0
k=n
while(k>0):
    d+=1
    k=k//10
sum=0
a=n
for i in range(0,d):
    sum += (a%10)**d
    a=a//10
if(sum==n):
    print("it is a armstrong number")
else:
    print("no")