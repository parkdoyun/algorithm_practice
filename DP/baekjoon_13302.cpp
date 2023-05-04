#include <iostream>
#include <algorithm>

using namespace std;

// ���� 13302 - ����Ʈ
// DP (bottom-up)
// ��� 4

// �� ���������� ���ٰ� �ٽ� ��� ��ȯ�ϸ鼭 DP ä��
// �ᱹ �� �ʱ� ����(1��°, ���� 0��)�� ������ ��

#define INF 999999999

int n, m;
int DP[101][101];
int absent[101]; // ���� ��

int chk(int day, int cou)
{
	if (day > n) return 0; // ���� n�� ���Ķ�� ���信 �����ϸ� �� �ǹǷ�
	else if (DP[day][cou] != INF) return DP[day][cou]; // �̹� �������ٸ� (�ð� ���� ����)

	// �� ���� ���� ��� ���� ���� �ѱ�
	if (absent[day] == 1)
	{
		DP[day][cou] = chk(day + 1, cou);
		return DP[day][cou];
	}

	int tmp_min = min(DP[day][cou], chk(day + 1, cou) + 10000); // 1�ϱ� ���
	tmp_min = min(tmp_min, chk(day + 3, cou + 1) + 25000); // ���� 3�ϱ� ���
	tmp_min = min(tmp_min, chk(day + 5, cou + 2) + 37000); // ���� 5�ϱ� ���

	if (cou >= 3) // ���� ��� ������ ��
	{
		tmp_min = min(tmp_min, chk(day + 1, cou - 3));
	}

	DP[day][cou] = tmp_min; // ����

	return DP[day][cou];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	// �ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 100; j++) DP[i][j] = INF;
	}

	int a;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		absent[a] = 1;
	}

	// DP
	cout << chk(1, 0);

	return 0;
}