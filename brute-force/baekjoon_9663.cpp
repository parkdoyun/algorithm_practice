#include <iostream>

using namespace std;

// ���� 9663 - N-Queen
// ��� 4
// brute-force

// �� �غ��� => �ð� �ʰ� => ������ ��� ���� �ϳ��� ���� ��
// �� backtracking => �ش� lv�� �´� ���� �˻��ϸ� ��

int n;
int cnt = 0;
int vec_x[16];
int vec_y[16];
int vec_plus[40]; // y + x (�밢��1)
int vec_minus[40]; // y - x + 15 (�밢��2)

void backtracking(int lv, int y, int x)
{
	if (lv == n)
	{
		// ��ġ���� ���
		cnt++;
		return;
	}

	int i = y + 1;
	for (int j = 0; j < n; j++)
	{
		if (vec_x[j] ==  1 || vec_plus[i + j] == 1 || vec_minus[i - j + 15] == 1) continue;
		vec_y[i] = 1;
		vec_x[j] = 1;
		vec_plus[i + j] = 1;
		vec_minus[i - j + 15] = 1;
		backtracking(lv + 1, i, j);
		vec_y[i] = 0;
		vec_x[j] = 0;
		vec_plus[i + j] = 0;
		vec_minus[i - j + 15] = 0;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	// �ѹ��̸� �� (�� ��)
	for (int j = 0; j < n; j++)
	{
		vec_y[0] = 1;
		vec_x[j] = 1;
		vec_plus[0 + j] = 1;
		vec_minus[0 - j + 15] = 1;
		backtracking(1, 0, j);
		vec_y[0] = 0;
		vec_x[j] = 0;
		vec_plus[0 + j] = 0;
		vec_minus[0 - j + 15] = 0;
	}

	cout << cnt;

	return 0;
}