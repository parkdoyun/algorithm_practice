# 백준 1036 - 36진수
# string
# 골드 1

n = int(input())
vec_str = []
vec_alpha = {}

for i in range(n):
    s = input()
    s = s.replace(" ", "") # 공백 제거
    vec_str.append(s)

k = int(input())

def calAlpha(c):
    if c >= '0' and c <= '9':
        tmp_n = int(c)
    else:
        tmp_n = ord(c) - ord('A') + 10
    tmp_n = 35 - tmp_n

    val = 0

    for i in range(n):
        ten = 1
        j = len(vec_str[i]) - 1
        for _ in range(len(vec_str[i])):
            if vec_str[i][j] == c:
                val += tmp_n * ten
            ten *= 36
            j -= 1

    vec_alpha[c] = val

for i in range(n):
    for j in range(len(vec_str[i])):
        if vec_alpha.get(vec_str[i][j]) == None:
            calAlpha(vec_str[i][j])

# sort
dic_alpha = dict(sorted(vec_alpha.items(), key=lambda x: x[1], reverse=True))
i = 0
for key,val in dic_alpha.items():
    if i >= k:
        break
    table = str.maketrans(key, 'Z')
    # 바꾸기
    for s in range(len(vec_str)):
        vec_str[s] = vec_str[s].translate(table)
    i += 1

# 계산
res = 0
for s in vec_str:
    ten = 1
    tmp = 0
    z_val = 0
    j = len(s) - 1
    for r in range(len(s)):
        if s[j] >= '0' and s[j] <= '9':
            res += int(s[j]) * ten
            tmp += int(s[j]) * ten
        else:
            res += (ord(s[j]) - ord('A') + 10) * ten
            tmp += (ord(s[j]) - ord('A') + 10) * ten
        z_val += 36**r * 35
        ten *= 36
        j -= 1

# 문자열 변환
res_str = ""
tmp_c = '.'
while res > 0:
    tmp = int(res % 36)
    if tmp >= 10:
        tmp_c = chr(ord('A') + int(tmp - 10))
    else:
        tmp_c = str(tmp)
    res_str = tmp_c + res_str
    res = int(res // 36)

if res_str == "": print(0)
else: print(res_str)
