#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 13164 - 행복 유치원
// greedy
// 골드 5

// n명의 아이들을 k개의 조
// n명 사이의 키 차이는 n - 1개
// k개의 조를 만드려면 이 키 차이 중 가장 큰 k - 1개 제외하면 됨
// a, b 키 차이 큰 것 제외 (= a, b 아예 다른 팀으로 만든다)
// 어차피 팀의 양 끝 키 차이 = 옆에 있는 애들 키 차이 전부 더한 것
// k - 1개 제외하고 나머지 더하면 됨

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