feet=int(input("enter the lenght in feet: "))
meter=(1/0.305)*feet
print("lenght in metr is",meter)
pound=int(input("enter the weight in pounds: "))
kilogram=(1/0.454)*pound
print("weight in kilogram is ", kilogram)
itemp=int(input("enter initial temp: "))
ftemp=int(input("enter finsl temp: "))
weight=int(input("enter weight of water: "))
energy=weight*(ftemp-itemp)*4184
print("energy is :",energy)