n = int(input())

ones = [-1, 1, 1]
zeros = [-1, 0, 1]

for i in range(3, n + 1):
    zeros.append(ones[i - 1] + zeros[i - 1])
    if i % 2 == 1: zeros[i] -= 1
    ones.append(ones[i - 1] + zeros[i - 1])

print(zeros[n])