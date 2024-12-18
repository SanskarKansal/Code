a=int(input("enter the year:" ))
b=int(input("enter the month between 1 to 12:" ))
if(b==1):
    print("january" ,a, " has 31 days")
elif(b==2):
    if(a%400==0 or a%100!=0 and a%4==0):
       print("february", a ," has 29 days")
    else:
        print("february", a ," has 28 days")
elif(b==3):
     print("march" ,a, " has 31 days")
elif(b==4):
     print("april", a ," has 30 days")
elif(b==5):
     print("may" ,a, " has 31 days")
elif(b==6):
   print("june" ,a ," has 30 days")
elif(b==7):
    print("july", a ," has 31 days")
elif(b==8):
     print("august", a, " has 31 days")
elif(b==9):
   print("september", a ," has 30 days")
elif(b==10):
    print("october", a ," has 31 days")
elif(b==11):
 print("november" ,a, " has 30 days")
elif(b==12):
    print("december", a, " has 31 days")
