#include <iostream>

using namespace std;

// ���� 16971 - �迭 B�� ��
// greedy
// ��� 3

// ù�� or ���� �� ù�� or ������ ���� �۾ƾ� �ִ�
// + �� �� ���� ���� �������Ƿ� �����ؾ� �� -> �� �� ���� ���� ���̳� ���� ��ü�Ǿ�� ��
// ��� �� �� ���� ���� ū �ַ� �ѹ� �ٲ�
// �񱳴� ���� * 2 - �糡 ������ �ؾ� ��Ȯ�� (������ �迭 B�� �̷��� �������Ƿ�)

// (1,1), (n, m)�� �ѹ��� ������
// (1, k), (k, 1), (k, n - 1), (n - 1, k)�� �ι� ������ 
// ������(�߰� ��)�� 4�� ������

#define INF 999999999
int n, m;
int arr[1001][1001];
long long int total = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int first_row = 0; // ù��° ��
	int last_row = 0; // ������ ��
	int first_col = 0; // ù��° ��
	int last_col = 0; // ������ ��
	int res_row, res_col;
	int res_row_cmp, res_col_cmp; // �񱳴� �� ������ �����ؼ� �ؾ� �� (���� * 2 - �糡 �� ����)
	int min_row = INF;
	int min_col = INF;
	int min_row_idx;
	int min_col_idx;
	int min_row_cmp = INF; // ���� �� �� ��
	int min_col_cmp = INF; // ���� �� �� ��

	cin >> n >> m;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			tmp += arr[i][j];
		}
		total += (long long int)tmp;
		if (i == 0) first_row = tmp;
		else if (i == n - 1) last_row = tmp;
		else
		{
			int t = tmp * 2 - arr[i][0] - arr[i][m - 1];
			if (t < min_row_cmp)
			{
				min_row_cmp = t;
				min_row = tmp;
				min_row_idx = i;
			}
		}
	}

	// �� Ȯ��
	for (int i = 0; i < m; i++)
	{
		tmp = 0;
		for (int j = 0; j < n; j++)
		{
			tmp += arr[j][i];
		}
		if (i == 0) first_col = tmp;
		else if (i == m - 1) last_col = tmp;
		else
		{
			int t = tmp * 2 - arr[0][i] - arr[n - 1][i];
			if (t < min_col_cmp)
			{
				min_col_cmp = t;
				min_col = tmp;
				min_col_idx = i;
			}
		}
	}

	total = total * (long long int)4;

	if (first_row > last_row)
	{
		res_row = first_row;
		res_row_cmp = first_row * 2 - arr[0][m - 1] - arr[0][0];
	}
	else
	{
		res_row = last_row;
		res_row_cmp = last_row * 2 - arr[n - 1][0] - arr[n - 1][m - 1];
	}

	if (first_col > last_col)
	{
		res_col = first_col;
		res_col_cmp = first_col * 2 - arr[0][0] - arr[n - 1][0];
	}
	else
	{
		res_col = last_col;
		res_col_cmp = last_col * 2 - arr[0][m - 1] - arr[n - 1][m - 1];
	}

	// �� �� ū ���� Ȯ��
	if ((res_row_cmp - min_row_cmp <= 0) && (res_col_cmp - min_col_cmp <= 0)) // �� �ٲٴ� �� ���ٸ�
	{
		total = total - (long long int)(first_col * 2) - (long long int)(last_col * 2) - (long long int)(first_row * 2) - (long long int)(last_row * 2) + (long long int)arr[0][m - 1] + (long long int)arr[0][0] + (long long int)arr[n - 1][0] + (long long int)arr[n - 1][m - 1];
	}
	else if ((res_row_cmp - min_row_cmp) > (res_col_cmp - min_col_cmp)) // �� ����
	{
		// cout << "ROW : " << min_row_idx << '\n';
		total = total - (long long int)(first_col * 2) - (long long int)(last_col * 2) - (long long int)(min_row * 2) + (long long int)arr[min_row_idx][0] + (long long int)arr[min_row_idx][m - 1];
		if (res_row == first_row)
		{
			total = total - (long long int)(last_row * 2) + (long long int)arr[n - 1][0] + (long long int)arr[n - 1][m - 1];
		}
		else
		{
			total = total - (long long int)(first_row * 2) + (long long int)arr[0][0] + (long long int)arr[0][m - 1];
		}
	}
	else // �� ����
	{
		//cout << "COL : " << min_col_idx << '\n';
		total = total - (long long int)(first_row * 2) - (long long int)(last_row * 2) - (long long int)(min_col * 2) + (long long int)arr[0][min_col_idx] + (long long int)arr[n - 1][min_col_idx];
		if (res_col == first_col)
		{
			total = total - (long long int)(last_col * 2) + (long long int)arr[0][m - 1] + (long long int)arr[n - 1][m - 1];
		}
		else
		{
			total = total - (long long int)(first_col * 2) + (long long int)arr[0][0] + (long long int)arr[n - 1][0];
		}
	}
	
	cout << total;

	return 0;
}