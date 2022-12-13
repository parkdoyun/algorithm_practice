#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// softeer - ���� ��ǻ�� Ŭ������
// binary-search
// �� 3

// ���� ���� �ֵ� �ø��� �� ���� �غ���
// ���� ������ break
// pq�� ���� �ֵ鳢��

// ���� Ž�� ����
// start = ��ǻ�� ���� �ּ�, end = ��ǻ�� ���� �ִ�

// ���� ��� ����
// ������ ���� �Լ� �߶�� ��
// ���� ���� ��������� �� (�ƴ� �ʹ� Ŀ�� ������ ��)

int n;
unsigned long long int a, b;
unsigned long long int max1 = 0;

vector<unsigned long long int> vec;
bool cmp(unsigned long long int l1, unsigned long long int l2)
{
	if (l1 < l2) return true;
	return false;
}

bool cal(unsigned long long int goal)
{
	unsigned long long int tmp_budget = 0;

	for (int i = 0; i < n; i++)
	{
		if (vec[i] >= goal) break;

		// ���ϴ� �κп��� ���� ���� ����
		if ((unsigned long long int)(goal - vec[i]) >= 4294967296 || (unsigned long long int)(goal - vec[i]) > b) return false;
		else if ((unsigned long long int)((unsigned long long int)(goal - vec[i]) * (unsigned long long int)(goal - vec[i])) > (unsigned long long int)(b - tmp_budget)) return false;

		tmp_budget = (unsigned long long int)(tmp_budget + (unsigned long long int)((unsigned long long int)(goal - vec[i]) * (unsigned long long int)(goal - vec[i])));

		// ���� ������ ���� �Լ� �ڸ���
		if (tmp_budget > b) return false;

	}

	if (tmp_budget <= b) return true;
	return false;
}

void binary_search(unsigned long long int max, unsigned long long int min)
{
	unsigned long long int start = min;
	unsigned long long int end = max;
	unsigned long long int mid;

	while (start <= end)
	{
		mid = (unsigned long long int)((unsigned long long int)(start + end) / 2);

		// mid�� �������� Ȯ��
		bool res = cal(mid); // �������� Ȯ��(mid ���� �ּҷ� �Ǵ���)
		if (res == true) // �����ϴٸ�
		{
			if (mid > max1) max1 = mid;
			start = (unsigned long long int)(mid + (unsigned long long int)1);
		}
		else // �Ұ����ϴٸ�
		{
			end = (unsigned long long int)(mid - (unsigned long long int)1);
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> b;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end(), cmp);

	max1 = 0;
	binary_search(2000000000, 0); // �̷��� ������� �ִ� b�� �ϸ� ���� ó����

	cout << max1;

	return 0;
}