n,m=map(int,input().split())
if n>m:n,m=m,n
if n==1:print(m)
elif n==2:print((m//4)*4+min((m%4)*2,4))
else:print((n*m)-(n*m)//2)