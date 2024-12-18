n=int(input("enter the total lenght of pattern: "))
for i in range(1,n+1):
    for j in range(n-i,0,-1):
        print("",end="  ")
    for j in range(1,i+1):
        print(2**(j-1),end=" ")
    for j in range(1,i):
        print(2**(i-j-1),end =" ")
    print()