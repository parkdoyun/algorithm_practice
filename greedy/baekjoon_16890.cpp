#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// ���� 16890 - â��
// greedy
// ��� 2

// �ϴ� �Ѵ� ������������ ���� ��
// s1[i] < s2[i]�� ���� �׳� ������ ���� ������� ������ �ȴ�
// �ٵ� s1[i] > s2[i]�� �ٲ� ��� ������ �̷� ���·� ���� ex) ť�귯�� G H B A ����� P Q W Z
// ������� ���� ū �ֵ����, ť�귯���� ���� ���� �ֵ���� �ڿ� �������� �� ���̴�

// ���� s1[i] > s2[i]�̸� ���� �ε������� �־�� ��

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
	int front_idx = 0; // answer �պ��� ä������ ���� idx
	int end_idx = n - 1; // answer �ں��� ä������ ���� idx

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) // �����
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
		else // ť�귯��
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