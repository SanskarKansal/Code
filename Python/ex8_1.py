a=()
print("enter the lenght: ")
n=int(input())
print("enter input")
for i in range(n):
    x=input()
    a=a+(x,)
print(a)
print("enter the number you wnat to find:")
y=input()
p=0
for i in a:
    if(y==i):
        print(p)
        break
    p=p+1