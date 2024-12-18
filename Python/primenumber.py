n=int(input("enter the number : "))
for i in range(2,n):
    if(n%i==0):
        a=1
        break
    else:
        a=0
if(a==0):
    print("it is a prime number")
else:
    print("not a prime numberr")