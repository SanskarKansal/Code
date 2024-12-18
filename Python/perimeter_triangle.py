a=int(input("enter the edge: "))
b=int(input("enter the edge: "))
c=int(input("enter the edge: "))
if((a+b)>c and (b+c)>a and (c+a)>b ):
    print("priemter is ",(a+b+c))
else:
    print("invalid intput")