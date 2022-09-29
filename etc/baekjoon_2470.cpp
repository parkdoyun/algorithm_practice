#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 2470 - �� ���
// ��� 5
// two-pointer

vector<long> vec;

bool cmp(long a, long b) // ���밪 ū �� ��
{
	if (abs(a) < abs(b)) return true;
	return false;
}


int main()
{
	int n;
	long a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end(), cmp);

	int p_idx = 0;
	int m_idx = 1;
	long sum = -2232133132; // �ּ� -20�� �̸����� �����ؾ� ��
	int now_p = -1;
	int now_m = -1;

	while (p_idx < vec.size() && m_idx <vec.size())
	{
		long tmp = vec[p_idx] + vec[m_idx];
		while (abs(sum) >= abs(tmp))
		{
			sum = tmp;
			now_p = vec[p_idx];
			now_m = vec[m_idx];
			p_idx++;
			if (p_idx == vec.size()) break;
			tmp = vec[p_idx] + vec[m_idx];
		}
		m_idx = p_idx;
		p_idx++;
		

	}
	
	if (now_m < now_p)
	{
		cout << now_m << ' ' << now_p;
	}
	else
	{
		cout << now_p << ' ' << now_m;
	}
	

	return 0;
}