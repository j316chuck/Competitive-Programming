import sys
sys.stdin = open('input.in', 'r')
sys.stdout = open('output.out', 'w')

n = int(input().strip())
lst = []
for x in range(n):
    lst.append(list(map(int, sys.stdin.readline().strip().split())))

lst.sort(key = lambda x : x[1])
l, r, ans = 0, len(lst) - 1, 0;

while l < r:
    number = min(lst[l][0], lst[r][0])
    ans = max(ans, lst[l][1] + lst[r][1])
    lst[l][0] -= number
    lst[r][0] -= number
    if lst[l][0] == 0:
        l += 1
    if lst[r][0] == 0:
        r -= 1

if l == r:
    ans = max(ans, 2 * lst[l][1]);

print(ans)


