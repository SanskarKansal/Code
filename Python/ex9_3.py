s=input("enter the string: ")
a=97
b=65
count=0
for i in range(0,26):
    for j in s:
        if(chr(a)==j or chr(b)==j):
            count+=1
    a+=1
    b+=1
if(count==26):
    print("string is pangram")
else:
    print("string is not a pangram")