#1
# a=input("enter the string ")
# l=list(a)
# print(a)

#2
# x=input("enter the string: ")
# k=1
# l=len(x)
# m=list(x)
# for i in range(0,l):
#     for j in range(i+1,l):
#         if(m[i]==m[j]):
#             print(m[i])
#             break
#         else:
#             k+=1

#3
# A=input("enter the lowercase string: ")
# B=input("enter the lowercase string: ")
# c=list(A)
# d=list(B)
# e=len(A)
# f=len(B)
# for i in range(0,e):
#     for j in range(0,f):
#         if(c[i]==d[j]):
#            print(c[i])  
#            break

#4
# a=input("enter the string: ")
# k=list(a)
# l=len(a)
# for i in range(0,l):
#     m=0
#     for j in range(0,l):
#         if(k[i]==k[j]):
#             m+=1
#     if(m==1):
#      print(k[i])

#5
# a=input("enter the string: ")
# b=input("enter the substring: ")
# l=len(a)
# n=a.find(b,0,l)
# if(n==-1):
#     print("not found")
# else:
#     print("index:",n)