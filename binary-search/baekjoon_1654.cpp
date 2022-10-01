#include <iostream>

using namespace std;

// ���� 1654 - ���� �ڸ���
// �̺�Ž��
// �ǹ� 2

// �̺�Ž�� ����
// 1. ���� �ƴ� �̺�Ž��(���̽����� �߰� �߶� ��)
// V 2. ���� ���� ���� �ֵ��� �̺�Ž��(�ݾ� �ڸ��ų� �ٽ� ���ϸ鼭 ����) �ϸ鼭 ��� ���̽� üũ

int arr[1000001];

int main()
{
	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	long long start = 1;
	long long end = 2147483647;
	long long mid;
	int tmp_cnt;

	int res = -1;

	while (start <= end) // **start, end ���� ���� Ȯ���ؾ� �Ѵ�**
	{
		// �ڸ��� Ȯ���غ���
		mid = (start + end) / 2;
		tmp_cnt = 0;
		
		for (int i = 0; i < k; i++)
		{
			tmp_cnt += (arr[i] / mid);
		}
		if (tmp_cnt >= n) // ���̰� ���� ª��
		{
			if (mid > res) res = mid;
			start = mid + 1;
		}
		else // ���̰� �ʹ� ��� -> ���̱�
		{
			end = mid - 1;
		}
	}

	cout << res;

	return 0;
}