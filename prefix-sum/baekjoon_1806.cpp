#include <iostream>

using namespace std;

// ���� 1806 - �κ���
// prefix sum, two pointer
// ��� 4

// ���� �� �б�!! S �̻� ����

int arr[100001];
int sumArr[100001]; // �κ��� �迭

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	cin >> n >> s;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sumArr[i] = arr[i] + sumArr[i - 1];
	}
	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sumArr[i] >= s)
		{
			idx = i;
			break;
		}
	}
	int start = 1;
	// idx���� ���� �����ϸ鼭 �κ��� Ȯ��
	int min1 = n + 1;
	while (true)
	{
		if (start > idx) break;
		if (idx > n) break;
		if (sumArr[idx] - sumArr[start - 1] == s)
		{
			if (min1 > idx - start + 1) min1 = idx - start + 1;
			idx++;
		}
		else if (sumArr[idx] - sumArr[start - 1] > s) // ���� �� �б� (�̻� ����)
		{
			if (min1 > idx - start + 1) min1 = idx - start + 1;
			start++;
		}
		else
		{
			idx++;
		}
	}

	if (min1 == n + 1) cout << 0;
	else cout << min1;

	return 0;
}