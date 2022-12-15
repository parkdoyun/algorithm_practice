#include <iostream>

using namespace std;

// ���� 2138 - ������ ����ġ
// greedy
// ��� 5

// ���� �ѹ��� ���� ���� �غ��� �� ����
// ������ ���� ���� �ѹ��� �����ǹǷ�

// �ι��� �غ��� �ȴ�
// 1. ó�� ������ �� ��
// 2. ó�� ������ ���� ���� ��

int light[100001];
int tmp[100001];
int goal[100001];
int n;
int flag = 0; // ����� 1
int total_cnt = 1000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		light[i] = (int)(c - '0');
	}
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		goal[i] = (int)(c - '0');
	}

	// ó�� ������ ���� ���� ��
	tmp[0] = light[0];
	tmp[1] = light[1];
	int cnt = 0;

	for (int i = 1; i < n - 1; i++)
	{
		if (tmp[i - 1] != goal[i - 1]) // �ٲ۴�
		{
			cnt++;
			if (tmp[i - 1] == 0) tmp[i - 1] = 1;
			else tmp[i - 1] = 0;
			if (tmp[i] == 0) tmp[i] = 1;
			else tmp[i] = 0;
			if (light[i + 1] == 0) tmp[i + 1] = 1;
			else tmp[i + 1] = 0;
		}
		else // �׳� �д�
		{
			tmp[i + 1] = light[i + 1];
		}
	}

	// n - 1��°
	if (tmp[n - 2] != goal[n - 2]) // �ٲ۴�
	{
		cnt++;
		if (tmp[n - 2] == 0) tmp[n - 2] = 1;
		else tmp[n - 2] = 0;
		if (tmp[n - 1] == 0) tmp[n - 1] = 1;
		else tmp[n - 1] = 0;
	}

	// ������ üũ
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (tmp[i] != goal[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		if (total_cnt > cnt) total_cnt = cnt;
	}

	for (int i = 0; i < n; i++)
	{
		tmp[i] = 0;
	}

	// ó�� ������ �� ��
	cnt = 1;
	if (light[0] == 0) tmp[0] = 1;
	else tmp[0] = 0;
	if (light[1] == 0) tmp[1] = 1;
	else tmp[1] = 0;

	for (int i = 1; i < n - 1; i++)
	{
		if (tmp[i - 1] != goal[i - 1]) // �ٲ۴�
		{
			cnt++;
			if (tmp[i - 1] == 0) tmp[i - 1] = 1;
			else tmp[i - 1] = 0;
			if (tmp[i] == 0) tmp[i] = 1;
			else tmp[i] = 0;
			if (light[i + 1] == 0) tmp[i + 1] = 1;
			else tmp[i + 1] = 0;
		}
		else // �׳� �д�
		{
			tmp[i + 1] = light[i + 1];
		}
	}
	// n��°
	if (tmp[n - 2] != goal[n - 2]) // �ٲ۴�
	{
		cnt++;
		if (tmp[n - 2] == 0) tmp[n - 2] = 1;
		else tmp[n - 2] = 0;
		if (tmp[n - 1] == 0) tmp[n - 1] = 1;
		else tmp[n - 1] = 0;
	}

	// ������ üũ
	flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (tmp[i] != goal[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		if (total_cnt > cnt) total_cnt = cnt;
	}

	if (total_cnt == 1000000) cout << -1;
	else cout << total_cnt;


	return 0;
}