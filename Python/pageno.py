print("enter page number: ")
a=int(input())
p=a-1
x=p
count=0
while(p>=5):
    count+=1
    p=int(p/5)
sum=x*2
for i in range(1,count+1):
    l=int(x/pow(5,i))
    sum=sum+(l*pow(10,i))
print(sum)