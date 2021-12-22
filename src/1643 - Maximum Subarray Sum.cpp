n = int(input())
v = [int(x) for x in raw_input().split()]
ans, min_pref, pref = v[0], 0, 0
for x in v:
    pref = pref + x
    ans = max(ans, pref - min_pref)
    min_pref = min(min_pref, pref)

print(ans)

