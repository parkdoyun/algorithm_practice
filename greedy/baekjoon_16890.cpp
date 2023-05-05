#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 백준 16890 - 창업
// greedy
// 골드 2

// 일단 둘다 오름차순으로 정렬 후
// s1[i] < s2[i]일 경우는 그냥 번갈아 가며 순서대로 쌓으면 된다
// 근데 s1[i] > s2[i]로 바뀔 경우 끝까지 이런 상태로 간다 ex) 큐브러버 G H B A 구사과 P Q W Z
// 구사과는 가장 큰 애들부터, 큐브러버는 가장 작은 애들부터 뒤에 쌓으려고 할 것이다

// 만약 s1[i] > s2[i]이면 뒤의 인덱스부터 넣어야 함

int n;
string koo, cube, s1, s2;

bool cmp(char c1, char c2)
{
	return c1 > c2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string answer = "";

	cin >> koo >> cube;

	n = koo.length();
	for (int i = 0; i < n; i++) answer += '.';

	sort(koo.begin(), koo.end());
	sort(cube.begin(), cube.end(), cmp);

	if (n % 2 == 1) s1 = koo.substr(0, (n + 1) / 2);
	else s1 = koo.substr(0, n / 2);
	s2 = cube.substr(0, n / 2);

	int idx1 = 0;
	int idx11 = s1.length() - 1;
	int idx2 = 0;
	int idx22 = s2.length() - 1;
	int front_idx = 0; // answer 앞부터 채워지지 않은 idx
	int end_idx = n - 1; // answer 뒤부터 채워지지 않은 idx

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) // 구사과
		{
			if (i == n - 1 || s1[idx1] < s2[idx2])
			{
				answer[front_idx] = s1[idx1];
				front_idx++;
				idx1++;
			}
			else
			{
				answer[end_idx] = s1[idx11];
				end_idx--;
				idx11--;
			}
		}
		else // 큐브러버
		{
			if (s1[idx1] < s2[idx2])
			{
				answer[front_idx] = s2[idx2];
				front_idx++;
				idx2++;
			}
			else
			{
				answer[end_idx] = s2[idx22];
				end_idx--;
				idx22--;
			}
		}
	}

	cout << answer;

	return 0;
}