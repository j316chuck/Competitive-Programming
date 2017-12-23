n, m = map(int, input().split())
s = input()
lst = []
for i in range(n):
    lst.append(s[i].strip())

for _ in range(m):
    l, r, c1, c2 = input().split()
    l, r = int(l) - 1, int(r)
    for i in range(l, r):
        if lst[i] == c1: lst[i] = c2;
print("".join(lst))