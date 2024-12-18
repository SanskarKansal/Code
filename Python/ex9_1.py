s=input("enter the string: ")
count_l=0
count_u=0
for i in s:
    if(i>='a' and i<='z'):
        count_l+=1
    if(i>='A' and i<='Z'):
        count_u+=1
print("lower case:",count_l)
print("upper case:",count_u)