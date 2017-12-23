import sys
import itertools

def valid(i):
    s = str(i)
    length = len(s)
    if length > n:
        return False
    for tuple in itertools.permutations(perm, length):
        valid = True
        for cnt, k in enumerate(s):
            if k not in strs[tuple[cnt]]:
                valid = False
                break;
        if valid:
            return True
    return False

n = int(sys.stdin.readline().rstrip())
perm = [x for x in range(n)]
strs = []
for i in range(n):
    strs.append("".join(sys.stdin.readline().rstrip().split()))

for i in range(1, 1001):
    if not valid(i):
        print(i - 1)
        exit()

