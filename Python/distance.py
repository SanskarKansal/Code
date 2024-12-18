import math
ax=int(input("enter x of a: "))
ay=int(input("enter y of a: "))
bx=int(input("enter x of b: "))
by=int(input("enter y of b: "))
distance=math.sqrt(pow((ax-bx),2)+pow((ay-by),2))
print("distance is ",distance)