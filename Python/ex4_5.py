n=int(input("enter the number: "))
print("pattern A")
for i in range(1,n+1):
    for j in range(1,i+1):
        print(j,end=" ")
    print()
print("pattern B")
for i in range(n,0,-1):
    for j in range(1,i+1):
        print(j,end=" ")
    print()
print("pattern C")
for i in range(1,n+1):
    for j in range(n-i,0,-1):
        print("",end="  ")
    for j in range(1,i+1):
        print(i+1-j,end=" ")
    print()