a=int(input("enter the number: "))
b=a%5
c=a%6
d=0
e=0
if(b==0):
    d=1
if(c==0):
    e=1
if(d==1 and e==1):
    print("number divisible by both 5 and 6")
elif(d==1 or e==1):
    print("number divisible by 5 or 6")
    if((d==1 and e!=1) ):
        print("number divisible by 5")
    elif(d!=1 or e==1):
        print("number divisible by 6")