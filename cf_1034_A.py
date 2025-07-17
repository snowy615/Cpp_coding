n = int(input())
for i in range(n):
    x = int(input())-1
    md = x%4
    m = int(x/4)
    n_1= m
    n_2 = m
    n_3 = m
    n_0 = m+1

    if md >=1:
        n_1 += 1
    if md >=2:
        n_2 += 1
    if md >= 3:
        n_3 += 1
    # print(md)
    # print(n_0, n_1, n_2, n_3)
    if (n_1 + n_2) % 2 == 0 and (n_3+n_0) % 2 == 0:
        print("Bob")
    else:
        print("Alice")