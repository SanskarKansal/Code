print("enter the number of tuple you want in list")
n=int(input())
print("enter number of element in tuple")
t=int(input())
l=[]
for i in range(n):
    a=()
    print("enter input")
    for i in range(t):
         x=input()
         a=a+(x,)
    l.append(a)
print(l)
for i in range(t):
    l1=[]
    for j in range(n):
        l1.append(l[j][i])
    print(l1)
