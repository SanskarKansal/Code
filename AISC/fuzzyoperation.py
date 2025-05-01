A = {"a": 0.4, "b": 0.3, "c": 0.6, "d": 0.6, "e": 0.5, "f": 0.7, "g": 0.2, "h": 0.5, "i": 0.5}
B = {"a": 0.6, "b": 0.9, "c": 0.4, "d": 0.5, "e": 0.8, "f": 0.3, "g": 0.2, "h": 0}

def union(A,B):
    result={}
    for key in A.keys()|B.keys():
        result[key]=round(max(A.get(key,0),B.get(key,0)),1)
    return result

def intersection(A,B):
    result={}
    for key in A.keys()|B.keys():
        result[key]=round(min(A.get(key,0),B.get(key,0)),1)
    return result

def complement(X):
    result={}
    for key in X:
        result[key]=round(1-X[key],1)
    return result

def difference(A,B):
    result={}
    for key in A.keys()|B.keys():
        result[key]=round(min(A.get(key,0),1-B.get(key,0)),1)
    return result

Union=union(A,B)
Intersection=intersection(A,B)
ComplementA=complement(A)
ComplementB=complement(B)
Difference=difference(A,B)

print("Union of these sets:",dict(sorted(Union.items())))
print("Intersection of these sets:",dict(sorted(Intersection.items())))
print("Complement of set A:",dict(sorted(ComplementA.items())))
print("Complement of set B:",dict(sorted(ComplementB.items())))
print("Difference of these sets (A - B):",dict(sorted(Difference.items())))
