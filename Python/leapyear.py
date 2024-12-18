n=int(input(" enter the year: "))
if(n%4==0):
    if(n%100==0):
        if(n%400==0):
            print(" leap year")
        else:
            print("not a leap year")
    else:
        print("leap year")
else:
    ("not a leap year")