l=[0,1]
n=int(input(" enter the total terms in series :"))
for i in range(0,n-2):
    a=l[i]+l[i+1]
    l.append(a)
print(l)