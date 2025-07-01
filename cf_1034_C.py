#not working
#time limit exceeded
#switched to c++
def is_min(lis, index):
    for j in range(index):
        if lis[j] < lis[index]:
            return False
    return True

def is_max(lis, index, x_len):
    for j in range(index+1, x_len):
        if lis[j] > lis[index]:
            return False
    return True

n = int(input())
for i in range(n):
    x_len = int(input())
    lis = list(map(int, input().split()))
    for j in range(x_len):
        if j == 0 or j == x_len-1:
            print("1", end="")
        else:
            if is_min(lis, j) or is_max(lis, j, x_len):
                print("1", end="")
            else:
                print("0", end="")
    print("")