x=int(input("enter the number of stoves: "))
y=int(input("enter the time : "))
a=x*y
print("Customer that can be served are: ", a)

X=int(input("enter the threshold speed : "))
Y=int(input("enter the currrent speed : "))
print("Is chef prone to error:  " ,end="")
if(Y>X):
    print("yes")
else:
    print("no")

b=int(input("enter the marks of Alice: "))
c=int(input("enter the marks of Bob: "))
if(b>=2*c):
    print("Alice is happy")
else:
    print("Alice is not happy")