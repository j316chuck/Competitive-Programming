n = int(input())
x, y = 0, 0
for i in range(n):
    a, b = map(int, input().split())
    if a >= 0: x += 1
    else: y += 1;
if x > 1 and y > 1:
    print('No')
else:
    print('Yes')