i=[0]*(5+5)
# print(k)
# i=[ 0, 286, 317, 0 ,279, -882 ]
a=0

rounds=[[2,3,603],[1,1,286],[4,4,882],]

for st,ed,amt in rounds:
    
    i[ed+1]-=amt
    i[st]+=amt
    # i[ed+1]=i[ed+1]-amt
    # i[st]=i[st]+amt
    print(i)

print(i)

for it in range(1,6):
    i[it]+=i[it-1]
    a=max(a,i[it])
    print(a)

print(i)

print(a)
