#include <iostream>

using namespace std;

// 백준 2879 - 코딩은 예쁘게
// DP
// 골드 3

// 나보다 크다면 큰 만큼 추가 DP[i] = DP[i - 1] + abs(arr[i] - arr[i - 1]);
// 나보다 작다면 DP[i] = DP[i - 1];

// 사이에 있는 거 따질 필요 X -> 같이 포함해서 탭하나 따로 하나 같음
// i번째에서
// 사이에 있는 갯수가 더 크다면 -> DP[i + k] = DP[i - 1] + arr[i + k];
// 만약 작다면 같이 올려버린다 -> DP[i + k] = DP[i - 1] + arr[i - 1];

int n;
int arr1[1001];
int arr2[1001];
int arr[1001]; // 최종 수
int DP_minus[1001]; // 음수
int DP_plus[1001]; // 양수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr1[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> arr2[i];
		arr[i] = arr1[i] - arr2[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] >= 0)
		{	
			// 일단 마이너스 찾기
			int now_idx = i + 1;
			while (now_idx <= n && arr[now_idx] >= 0) now_idx++;
			if (now_idx > n)
			{
				DP_minus[n] = DP_minus[i - 1]; // 출력 위해
				break; // 마이너스 없다면 나가기
			}

			DP_minus[now_idx] = DP_minus[i - 1] + abs(arr[now_idx]);
			i = now_idx;
		}
		else
		{
			if (arr[i] < arr[i - 1])
			{
				DP_minus[i] = DP_minus[i - 1] + abs(arr[i] - arr[i - 1]);
			}
			else
			{
				DP_minus[i] = DP_minus[i - 1];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] <= 0)
		{
			// 일단 플러스 찾기
			int now_idx = i + 1;
			while (now_idx <= n && arr[now_idx] <= 0) now_idx++;
			if (now_idx > n)
			{
				DP_plus[n] = DP_plus[i - 1];
				break; // 플러스 없다면 나가기
			}

			DP_plus[now_idx] = DP_plus[i - 1] + arr[now_idx];
			i = now_idx;
		}
		else
		{
			if (arr[i] > arr[i - 1])
			{
				DP_plus[i] = DP_plus[i - 1] + arr[i] - arr[i - 1];
			}
			else
			{
				DP_plus[i] = DP_plus[i - 1];
			}
		}
	}

	cout << DP_minus[n] + DP_plus[n];

	return 0;
}