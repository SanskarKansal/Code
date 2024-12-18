a=int(input("enter the value:"))
b=int(input("enter the value:"))
c=int(input("enter the value:"))
d=int(input("enter the value:"))
e=int(input("enter the value:"))
f=int(input("enter the value:"))
g=a*d-b*c
if(g==0):
    print("no solution")
else:
    x=(e*d-b*f)/(a*d-b*c)
    y=(a*f-e*c)/(a*d-b*c)
    print(x)
    print(y)
