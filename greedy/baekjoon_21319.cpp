#include <iostream>

using namespace std;

// ���� 21319 - è�Ǿ� (Easy)
// greedy
// ��� 2

// ���� ������ ������ ������ �Ұ�
// �ι�°�� ������ ���� ������� ����
// ������ ������ ���� ������� ����ؾ� ��
// 
// ��� �ص� �� �̱�� -> ���� �Ѿ
// è�Ǿ� �� �� ������ -> ��ȣ ���

// ������ ���� ���ٸ� -> è�Ǿ� �� ��
// ���ʿ� �ִ� �ֵ� ���� + ���� ������ �ִ��� �� ũ�ٸ� -> è�Ǿ� �� ��
// ������ ����

// �ð� �ʰ�
// �ѹ��� �迭 Ȯ���ϸ� �� �� ������?

long long int arr[200001];
long long int chk_arr[200001]; // i��°������ �ּ� chk_arr[i] �� �̻��̾�� è�Ǿ� ����
int n;

bool chk(int idx) // è�Ǿ� üũ
{
	if (arr[idx - 1] == arr[idx]) return false; // ������ ���� ���ٸ� -> è�Ǿ� �� ��
	if (idx == n) return true; // �� ���̶�� ����
	
	if (chk_arr[idx] < arr[idx] + (long long int)(idx - 1) ) return true;
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int flag = -1;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	if (n == 1) // ���� ó��
	{
		cout << 1;
		return 0;
	}

	// chk_arr �迭
	long long int tmp = arr[n] + (long long int)1;
	for (int i = n - 1; i >= 1; i--)
	{
		tmp -= (long long int)1;
		chk_arr[i] = tmp;
		if (tmp < arr[i] + (long long int)1 ) tmp = arr[i] + (long long int)1;
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == arr[1]) continue; // ���� ������ pass

		// è�Ǿ� �� �� �ִ��� Ȯ��
		if (chk(i))
		{
			cout << i << ' ';
			flag = 0;
		}
	}

	if (flag == -1) cout << -1;
	
	return 0;
}