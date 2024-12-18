n=int(input("enter the number of element in the list"))
list=[]
for i in range(0,n):
    x=input()
    list.append(x)
count=0
for i in list:
  if( len(i)>=2 and (i[0]==i[-1])):
     count+=1   
print(count)