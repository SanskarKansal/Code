count=0
for i in range(100,1000):
    if(i%30==0):
        print(i,end=" ")
        count+=1
        if(count%10==0):
            print()