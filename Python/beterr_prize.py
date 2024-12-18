a=int(input("enter the weight in shop 1: "))
b=int(input("enter the price in shop 1: "))
c=int(input("enter the weight in shop 2: "))
d=int(input("enter the price in shop 2: "))
e=b/a
f=d/c
if(e>f):
    print("shop 2 is better")
elif(e==f):
    print("both shop prize is same")
else:
    print("shop 1 price is better")