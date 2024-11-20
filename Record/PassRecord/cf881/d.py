import sys, os, io
from collections import defaultdict
 
from types import GeneratorType
 
 
def bootstrap(f, stack=[]):
    def wrapped(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrapped
 
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())

ans = []
edges = []
n = 0
@bootstrap
def dfs(u, p):
    ## print('{} {}'.format(u, p))
    if (len(edges[u]) == 1 and edges[u][0] == p):
        ans[u] = 1
    for v in edges[u]:
        if v == p:
            continue
        ans[u] += yield dfs(v, u)
    yield ans[u]
Ans = []
for _ in range(t):
    n = int(input())

    edges = [[] for i in range(n + 1)]
    for i in range(n - 1):
        u, v = map(int, input().split())
        edges[u].append(v)
        edges[v].append(u)
    ans = [0] * (n + 1)
    dfs(1, 0)
    ## for i in range(1, n):
    ##    print('!{} {}'.format(i, ans[i]))
    q = int(input())
    for i in range(q):
        c1, c2 = map(int, input().split())
        Ans.append(ans[c1] * ans[c2])

sys.stdout.write("\n".join(map(str, Ans)))
