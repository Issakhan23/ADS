d=iter(open(0).read().split())
while (n:=int(next(d)))>0:
    t=[next(d) for _ in range(n)]
    s=next(d)
    c=[sum(s.startswith(w,j) for j in range(len(s))) for w in t]
    m=max(c)
    if m:print(m,*sorted(w for w,v in zip(t,c) if v==m),sep='\n')