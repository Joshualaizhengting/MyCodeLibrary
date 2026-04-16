def solve(N, A):
#add you codes
    count = 0
    for i in range(1, N-1):
        left, right = 0, N-1
        while left < right:
            if left == i:
                left += 1
                continue
            if right == i:
                right -= 1
                continue
            s = A[left] + A[right]
            target = 2 * A[i]

            if s == target and left < i < right:
                count += 1
                left += 1
                right -= 1
            elif s<target:
                left += 1
            else:
                right -= 1
    
    return count

    

import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
A = list(map(int, data[1:]))
print(solve(N,A))