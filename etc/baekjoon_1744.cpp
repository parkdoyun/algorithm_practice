#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 1744 - �� ����
// ��� 5
// brute-force

// ������ ���� ū ���鳢�� ���ؾ� ���� ũ��.
// ������ ���� �迭, ����� ���� �迭 ���� �ְ� �����ؼ�
// ���� ū �� ���� �� ���Ѵ�.

vector<int> vec;
vector<int> vec_minus;

long long res;
long long res2;

bool cmp(int a, int b)
{
	if (a > b) return true;
	return false;
}

bool cmp2(int a, int b)
{
	if (a < b) return true;
	return false;
}

int main()
{
	res = 0;
	res2 = 0;

	int n, a;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a > 0)
		{
			vec.push_back(a);
		}
		else
		{
			vec_minus.push_back(a);
		}
	}

	// ū ������� ����
	sort(vec.begin(), vec.end(), cmp);
	sort(vec_minus.begin(), vec_minus.end(), cmp2);


	// ������ ������
	for (int i = 0; i < vec.size(); i++)
	{
		if (i % 2 == 1)
		{
			if (vec[i] + vec[i - 1] > vec[i] * vec[i-1])
			{
				res += vec[i] + vec[i - 1];
			}
			else
			{
				res += vec[i] * vec[i - 1];
			}
		}
		if (vec.size() % 2 == 1 && i == vec.size() -1)
		{
			res += vec[i];
		}
	}

	for (int i = 0; i < vec_minus.size(); i++)
	{
		if (i % 2 == 1)
		{
			if (vec_minus[i] + vec_minus[i - 1] > vec_minus[i] * vec_minus[i - 1])
			{
				res2 += vec_minus[i] + vec_minus[i - 1];
			}
			else
			{
				res2 += vec_minus[i] * vec_minus[i - 1];
			}
		}
		if (vec_minus.size() % 2 == 1 && i == vec_minus.size() - 1)
		{
			res2 += vec_minus[i];
		}
	}


	if (n == 1)
	{
		if (vec_minus.size() == 0)
		{
			cout << vec[0];
		}
		else cout << vec_minus[0];
		//cout << vec[0];
	}
	else {
		cout << res + res2;
	}

	return 0;
}