num=int(input("enter the number: "))
z=0
sum=0
for i in range(2,num+1):
    for j in range(2,i):
        if(i%j==0):
            z=1
            break
        else:
            z=0
    if(z==0):
        print(i)
        sum=sum+i
print("sum is",sum)