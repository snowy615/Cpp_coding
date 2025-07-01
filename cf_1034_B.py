n = int(input())
for i in range(n):
    n, j , k = map(int, input().split())
    lis = list(map(int, input().split()))
    if k >=2:
        print("YES")
    else:
        max_num = 0
        for x in lis:
            if x > max_num:
                max_num = x
        if lis[j-1] >= max_num:
            print("YES")
        else:
            print("NO")