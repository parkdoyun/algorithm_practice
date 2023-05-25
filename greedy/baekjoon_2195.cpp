#include <iostream>
#include <string>
#include <map>

using namespace std;

// ���� 2195 - ���ڿ� ����
// greedy
// ��� 5

// ������ �� �� ���� �����ؾ� ��
// �׳� ������� �� Ȯ��
// �迭�� �ּ� ���Ƚ�� ���Ѵ�

#define INF 999999999

string s, p;
int s_len;
map<string, int> map_str;
int arr[1001];

bool chkStr(string tmp_s, int n)
{
	int flag;
	for (int i = 0; i <= s_len - n; i++)
	{
		flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[i + j] != tmp_s[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> p;

	s_len = s.length();
	int p_len = p.length();

	for (int i = 0; i < p_len; i++) arr[i] = INF;

	string tmp_str;

	// �ּ� ���Ƚ�� ���ϱ�
	
	// ���� ����
	tmp_str = "";
	int tmp_len = 0;
	for (int i = 0; i < p_len; i++)
	{
		tmp_str += p[i];
		tmp_len++;
		if (chkStr(tmp_str, tmp_len)) arr[i] = 1;
		if (tmp_len == s_len) break;
	}

	for (int i = 1; i < p_len; i++)
	{
		tmp_str = p[i];
		tmp_len = 1;
		if ((chkStr(tmp_str, tmp_len)) && arr[i] == INF) arr[i] = arr[i - 1] + 1;

		for (int j = i + 1; j < p_len; j++)
		{
			tmp_str += p[j];
			tmp_len++;
			if ((chkStr(tmp_str, tmp_len)) && arr[j] > arr[i] + 1) arr[j] = arr[i - 1] + 1;
			if (tmp_len == s_len) break;
		}
	}

	cout << arr[p_len - 1];

	return 0;
}