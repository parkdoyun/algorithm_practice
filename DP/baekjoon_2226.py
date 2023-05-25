# // 백준 2226 - 이진수
# // DP
# // 골드 5
# //
# // 홀수번째 문자열의 양 끝 1, 중간 00
# // 짝수번째 문자열의 양 끝 0, 1, 중간 01
# // n번쨰 문자열 = (n-1번째 문자열 flip) + (n - 1번째 문자열)
#s
# // zeros[i] = ones[i - 1] + zeros[i - 1];
# // if(홀수번째면) zeros[i]--;
# // ones[i] = ones[i - 1] + zeros[i - 1];


n = int(input())

ones = [-1, 1, 1]
zeros = [-1, 0, 1]

for i in range(3, n + 1):
    zeros.append(ones[i - 1] + zeros[i - 1])
    if i % 2 == 1: zeros[i] -= 1
    ones.append(ones[i - 1] + zeros[i - 1])

print(zeros[n])