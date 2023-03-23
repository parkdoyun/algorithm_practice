#include <iostream>

using namespace std;

// 백준 1365 - 꼬인 전깃줄
// binary search, LIS
// 골드 2

// LIS (Longest Increasing Subsequence, 최장 증가 수열) - 이분탐색
// LIS를 DP로 푸는 경우, O(n^2)이므로 시간 초과
// 최장 증가 수열 길이 찾은 후
// 전체 n에서 뺀다

int n;
int sub_size; // 최장 증가 수열 길이
int arr[100001];
int subsequence[100001];

void binary_search(int num)
{
	int start = 1;
	int end = sub_size;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (subsequence[mid] > num)
		{
			end = mid - 1;
		}
		else // subsequence[mid] < num
		{
			start = mid + 1;
		}
	}
	if (subsequence[mid] > num)
	{
		subsequence[mid] = num;
	}
	else // subsequence[mid] < num
	{
		subsequence[mid + 1] = num;
		if (mid + 1 > sub_size) sub_size = mid + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	subsequence[1] = arr[1];
	sub_size = 1;

	for (int i = 2; i <= n; i++)
	{
		binary_search(arr[i]);
	}

	cout << n - sub_size;

	return 0;
}