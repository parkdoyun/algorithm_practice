#include <iostream>

using namespace std;

// ���� 5721 - ���� �ݱ� ��ȸ
// DP
// ��� 4 

// ������ ���ٿ����� ���� ����� �ص� ��� ����
// ���ٳ��� �ִ� ���ϰ� => �迭�� �־���´�
// M���� 1���� �迭�� �������� ���� DP�� �ٽ� ���Ѵ�
// ���� DP �ι� �����ϸ� �ȴ�

// ��ȭ�� : �긦 �����ϴ� �ִ�
// DP[i] = max(DP[i - 1], DP[i - 2] + arr[i])
// ��ü �ִ�

int m, n;
long long int arr[100001]; // �� �� ����
long long int total_arr[100001]; // ��ü �� ����
long long int tmp_DP[100001]; // �� �� DP
long long int total_DP[100001]; // ��ü �� DP

long long int find_tmp()
{
	tmp_DP[0] = arr[0];
	long long int max1 = tmp_DP[0];

	if (n == 1) return max1; // ���� : ���ٸ� ���� �� �ٷ� return

	tmp_DP[1] = max(arr[0], arr[1]);
	if (tmp_DP[1] > max1) max1 = tmp_DP[1];

	for (int i = 2; i < n; i++)
	{
		tmp_DP[i] = max(tmp_DP[i - 1], (long long int)(tmp_DP[i - 2] + arr[i]));
		if (tmp_DP[i] > max1) max1 = tmp_DP[i];
	}
	return max1;
}
long long int find_total()
{
	total_DP[0] = total_arr[0];
	long long int max1 = total_DP[0];

	if (m == 1) return max1; // ���� : ���ٸ� ���� �� �ٷ� return

	total_DP[1] = max(total_arr[0], total_arr[1]);
	if (total_DP[1] > max1) max1 = total_DP[1];

	for (int i = 2; i < m; i++)
	{
		total_DP[i] = max(total_DP[i - 1], (long long int)(total_DP[i - 2] + total_arr[i]));
		if (total_DP[i] > max1) max1 = total_DP[i];
	}
	return max1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[j];
			}

			// ���� DP
			// �ִ� total_arr[i]�� ���
			total_arr[i] = find_tmp();
		}
		cout << find_total() << '\n';
	}

	return 0;
}