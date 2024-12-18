a=int(input("enter the vlaue:"))
for i in range(1,11):
    a=a+a*5/100
print("tution price after 10 yeras :",a)
b=a
for i in range(1,4):
    a=a+a*5/100
    b=b+a
print("total tution price for 4 years :",b)