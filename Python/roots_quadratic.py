import math
a=int(input("enter the value of a:"))
b=int(input("enter the vlaue of b: "))
c=int(input("enter the value of c: "))
d=b*b-(4*a*c)
if(d>=0):
    r1=(-b+math.sqrt(d))/(2*a)
    r2=(-b-math.sqrt(d))/(2*a)
if(d>0):
    print("roots are real and different")
    print(r1)
    print(r2)
elif(d==0):
    print("roots are real and equal")
    print(r1)
else:
    print("roots are imaginary")
