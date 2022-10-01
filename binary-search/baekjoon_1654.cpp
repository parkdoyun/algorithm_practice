#include <iostream>

using namespace std;

// 백준 1654 - 랜선 자르기
// 이분탐색
// 실버 2

// 이분탐색 유형
// 1. 내가 아는 이분탐색(케이스들의 중간 잘라서 비교)
// V 2. 랜선 길이 같은 애들을 이분탐색(반씩 자르거나 다시 곱하면서 조절) 하면서 모든 케이스 체크

int arr[1000001];

int main()
{
	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	long long start = 1;
	long long end = 2147483647;
	long long mid;
	int tmp_cnt;

	int res = -1;

	while (start <= end) // **start, end 같을 때도 확인해야 한다**
	{
		// 자르고 확인해보기
		mid = (start + end) / 2;
		tmp_cnt = 0;
		
		for (int i = 0; i < k; i++)
		{
			tmp_cnt += (arr[i] / mid);
		}
		if (tmp_cnt >= n) // 길이가 아직 짧다
		{
			if (mid > res) res = mid;
			start = mid + 1;
		}
		else // 길이가 너무 길다 -> 줄이기
		{
			end = mid - 1;
		}
	}

	cout << res;

	return 0;
}