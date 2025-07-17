#unfinished
#still need to debug
n = int(input())
for i in range(n):
    x_len, k = map(int, input().split())
    lis = input()
    n_0 = 0
    n_1 = 0
    for x in range(x_len):
        if lis[x] == '0':
            n_0 += 1
        if lis[x] == '1':
            n_1 += 1
    print(n_0, n_1)
    t = 0
    while True:
        if t > 100:
            print("Bob")
            break
        add = min(n_1, k)
        n_0 += add
        n_1 -= add
        if n_0 >= x_len:
            print("Alice")
            break
        add = min(n_0, k)
        n_1 += add
        n_0 -= add
        t += 1
