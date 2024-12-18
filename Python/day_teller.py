a=int(input("enter th number between 1 and 7 :"))
if(a==0):
    print("day is  sunday")
elif(a==1):
    print("day is monday")
elif(a==2):
    print("day is tuesday")
elif(a==3):
    print("day is wednesday")
elif(a==4):
    print("day is thursday")
elif(a==5):
    print("day is friday")
elif(a==6):
    print("day is saturday")
b=int(input("enter the days afer you want to choose: "))
d=a+b
c=d%7
if(c==0):
    print("day is  sunday")
elif(c==1):
    print("day is monday")
elif(c==2):
    print("day is tuesday")
elif(c==3):
    print("day is wednesday")
elif(c==4):
    print("day is thursday")
elif(c==5):
    print("day is friday")
elif(c==6):
    print("day is saturday")
