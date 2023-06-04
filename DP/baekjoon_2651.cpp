#include <iostream>
#include <string>

using namespace std;

// ���� 2651 - �ڵ������ִ�ȸ
// DP
// ��� 4

// ��ȭ��
// DP[i] = min(i�κ��� �ִ� max_len��ŭ �ڿ� �ִ� �ֵ��� ����� �ð�) + time[i];
// �������� ���ܷ� time[i] �� ����

int max_len; // �ִ� �Ÿ�
int n; // ����� ��
int len[103]; // ����� �� �Ÿ�
int time[102]; // �����
int DP[103];
int prev_stop[103]; // i�� ����ҿ��� �� ���� �����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> max_len >> n;
	for (int i = 0; i <= n; i++) cin >> len[i];
	for (int i = 1; i <= n; i++) cin >> time[i];
	for (int i = 0; i <= n + 1; i++) DP[i] = -1;

	// DP
	// ���� ����
	DP[0] = 0; // ������
	prev_stop[0] = -1;

	for (int i = 1; i <= n; i++)
	{
		int now_len = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			now_len += len[j];
			if (now_len > max_len) break;

			if (DP[i] > DP[j] || DP[i] == -1)
			{
				DP[i] = DP[j];
				prev_stop[i] = j;
			}
		}
		DP[i] += time[i];
	}

	// ������ ��� (n + 1)
	int now_len = 0;
	for (int j = n; j >= 0; j--)
	{
		now_len += len[j];
		if (now_len > max_len) break;

		if (DP[n + 1] > DP[j] || DP[n + 1] == -1)
		{
			DP[n + 1] = DP[j];
			prev_stop[n + 1] = j;
		}
	}

	cout << DP[n + 1] << '\n';
	if (DP[n + 1] != 0)
	{
		int stop_cnt = 0;
		string list = "";

		int idx = prev_stop[n + 1];
		while (idx != 0)
		{
			stop_cnt++;
			list = to_string(idx) + " " + list;
			idx = prev_stop[idx];
		}
		cout << stop_cnt << '\n' << list;
	}
	else cout << 0;

	return 0;
}