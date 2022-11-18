#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ���� 2143 - �� �迭�� ��
// map
// ��� 3

// two pointer�� ���
// A �迭�� B �迭�� ��� �κ��� ����� �� ���ؼ� �ʿ� ���� ��
// ���ؼ� T�� �Ǵ� �ֵ� ī��Ʈ�Ѵ�.

long long arr1[1002];
long long arr2[1002];
long long arr1s[1002]; // �κ��� �迭
long long arr2s[1002];
long long T;
int n, m;

unordered_map<long long, long long> vec1;
unordered_map<long long, long long> vec2; // �κ��� ����� �� ��� �迭

int main()
{
	cin >> T >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr1[i];
		arr1s[i] = arr1s[i - 1] + arr1[i];
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> arr2[i];
		arr2s[i] = arr2s[i - 1] + arr2[i];
	}

	// ��� �κ��� �� ���ϱ�
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (vec1.find(arr1s[j] - arr1s[i - 1]) == vec1.end())
			{
				vec1.insert({arr1s[j] - arr1s[i - 1], 1	});
			}
			else vec1[arr1s[j] - arr1s[i - 1]]++;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			if (vec2.find(arr2s[j] - arr2s[i - 1]) == vec2.end())
			{
				vec2.insert({ arr2s[j] - arr2s[i - 1], 1 });
			}
			else vec2[arr2s[j] - arr2s[i - 1]]++;
		}

	}

	long long cnt = 0;
	for (auto v : vec1)
	{
		if (vec2.find(T - v.first) != vec2.end())
		{
			cnt += vec2[T - v.first] * v.second;
		}
	}
	
	cout << cnt;

	return 0;
}