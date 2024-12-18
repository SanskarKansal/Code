l=[]
n=int(input("enter the number of values: "))
for i in  range(n):
    t=()
    print("enter the pair")
    x=int(input())
    y=int(input())
    t=t+(x,y)
    l.append(t)
print(l)
l2=[]
for i in l:
    l2.append(i[0])
    l2.append(i[1])

s=set(l2)
l3=list(s)
l3.sort()
print(l3)