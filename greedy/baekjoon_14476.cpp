#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 14476 - �ִ����� �ϳ� ����
// ��� 2
// greedy

// ��ü �ִ����� ���Ѵ�
// i) �ִ� ������� K�� �� -> �ִ������� ���� ���� �� �ϳ��� ������ ��
// ���� ���� �� K ���� �ι�°�� ���� ���� K ���̿��� �ִ� ����� ���� �� �ִ��� Ȯ��
// ii) �ִ� ������� K�� ����� �� -> �ٸ� �� ���� K�� �ִ� ����� �� �� �ִ���
// �̷����� vec[1]���� vec[n - 1]���� K�� �� ������ �ְ� �ϳ����� �Ѵ�

// ���� : K�� �������� K���� ���� �� �ִ������� �� �ִ� (K�� ����� �ƴ�)

int n, total_divisor;
vector<int> vec;
bool cmp(int a, int b)
{
	return a < b;
}

bool chk(int num)
{
	for (int i = 1; i < n; i++)
	{
		if (vec[i] % num != 0) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end(), cmp);

	// ��ü �ִ� ����� ���ϱ�
	// K���� K�� ��� ���� ������ ��

	// ���� : K�� �������� K���� ���� �� �ִ������� �� �ִ� (K�� ����� �ƴ�)
	int total_divisor2 = -1;
	for (int i = vec[0]; i > 0; i--)
	{
		if (vec[0] % i != 0)
		{
			if (i < total_divisor2) continue;
			if (chk(i)) total_divisor2 = i;
			continue;
		}
		if (chk(i))
		{
			total_divisor = i;
			break;
		}
	}
	int flag = -1;

	for (int i = vec[1]; i > vec[0]; i--) // vec[0] + 1�� vec[1] ���̿� �ִ� ����� �ִ��� Ȯ��
	{
		if (chk(i))
		{
			flag = i;
			break;
		}
	}

	if (flag != -1)
	{
		cout << flag << ' ' << vec[0];
		return 0;
	}

	// �� �ϳ��� �����ؼ� K�� �ִ� ����� �� �� �ִ���
	// �̷����� vec[1]���� vec[n - 1]���� K�� �� ������ �ְ� �ϳ����� �Ѵ�
	int cnt = 0;
	int idx;
	for (int i = 1; i < n; i++)
	{
		if (vec[i] % vec[0] != 0)
		{
			cnt++;
			idx = i;
		}
	}

	if (cnt == 1)
	{
		cout << vec[0] << ' ' << vec[idx];
		return 0;
	}
	
	// ���� : K�� �������� K���� ���� �� �ִ������� �� �ִ� (K�� ����� �ƴ�)
	if (total_divisor2 != -1) cout << total_divisor2 << ' ' << vec[0];
	else cout << -1;

	return 0;
}