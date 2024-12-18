a=int(input("enter the loan amount: "))
b=int(input("enter the loan period: "))
rate=5
mon=0
amount=a
print("rate          ","monthly payment      ","total payment")
while(rate<=8):
    for i in range(1,b):
        amount=amount+(rate)*amount/100
    mon=amount/(b*12)
    print(rate,"      ",mon,"      ",amount)
    rate=rate+1/8