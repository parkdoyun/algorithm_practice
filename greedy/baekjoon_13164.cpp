#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 13164 - �ູ ��ġ��
// greedy
// ��� 5

// n���� ���̵��� k���� ��
// n�� ������ Ű ���̴� n - 1��
// k���� ���� ������� �� Ű ���� �� ���� ū k - 1�� �����ϸ� ��
// a, b Ű ���� ū �� ���� (= a, b �ƿ� �ٸ� ������ �����)
// ������ ���� �� �� Ű ���� = ���� �ִ� �ֵ� Ű ���� ���� ���� ��
// k - 1�� �����ϰ� ������ ���ϸ� ��

int n, k;
int arr[300001];
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	cin >> arr[0];

	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		vec.push_back({ arr[i] - arr[i - 1] });
	}

	sort(vec.begin(), vec.end());

	long long int total = 0;
	for (int i = 0; i < n - k; i++)
	{
		total += (long long int)vec[i];
	}
	cout << total;
	return 0;
}