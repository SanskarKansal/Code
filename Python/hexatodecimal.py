import math
x=input("enter the hexadecimal number: ")
b=0
C=0
dec=0
rev=""
for i in x:
    rev=i+rev
for i in rev:
    if(i=="A"):
        C=10
    elif(i=='B'):
        C=11
    elif(i=='C'):
        C=12
    elif(i=='D'):
        C=13
    elif(i=='E'):
        C=14
    elif(i=='F'):
        C=15
    else:
         C=int(i)
    dec= dec+ (C*pow(16,b))
    b+=1
print(dec)