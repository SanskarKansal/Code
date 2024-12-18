n=int(input("enter the number of items in the list: "))
list=[]
for i in range(0,n):
    a=int(input())
    list.append(a)
    sum=1
for i in range(0,n):
    sum*=list[i]
print(sum)