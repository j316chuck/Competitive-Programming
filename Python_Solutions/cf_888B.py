n = int(input())
s = input()
mp = {'U' : 0, 'D' : 0, 'L' : 0, 'R' : 0}
for c in s:
    mp[c] += 1

total = min(mp['U'], mp['D']) + min(mp['R'], mp['L'])
print (total * 2)