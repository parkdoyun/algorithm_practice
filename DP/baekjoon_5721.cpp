#include <iostream>

using namespace std;

// 백준 5721 - 사탕 줍기 대회
// DP
// 골드 4 

// 어차피 한줄에서는 지들 맘대로 해도 상관 없음
// 한줄끼리 최댓값 구하고 => 배열에 넣어놓는다
// M개의 1차원 배열로 만들어놓고 같은 DP로 다시 구한다
// 같은 DP 두번 수행하면 된다

// 점화식 : 얘를 포함하는 최댓값
// DP[i] = max(DP[i - 1], DP[i - 2] + arr[i])
// 전체 최댓값

int m, n;
long long int arr[100001]; // 한 줄 정보
long long int total_arr[100001]; // 전체 줄 정보
long long int tmp_DP[100001]; // 한 줄 DP
long long int total_DP[100001]; // 전체 줄 DP

long long int find_tmp()
{
	tmp_DP[0] = arr[0];
	long long int max1 = tmp_DP[0];

	if (n == 1) return max1; // 예외 : 한줄만 있을 때 바로 return

	tmp_DP[1] = max(arr[0], arr[1]);
	if (tmp_DP[1] > max1) max1 = tmp_DP[1];

	for (int i = 2; i < n; i++)
	{
		tmp_DP[i] = max(tmp_DP[i - 1], (long long int)(tmp_DP[i - 2] + arr[i]));
		if (tmp_DP[i] > max1) max1 = tmp_DP[i];
	}
	return max1;
}
long long int find_total()
{
	total_DP[0] = total_arr[0];
	long long int max1 = total_DP[0];

	if (m == 1) return max1; // 예외 : 한줄만 있을 때 바로 return

	total_DP[1] = max(total_arr[0], total_arr[1]);
	if (total_DP[1] > max1) max1 = total_DP[1];

	for (int i = 2; i < m; i++)
	{
		total_DP[i] = max(total_DP[i - 1], (long long int)(total_DP[i - 2] + total_arr[i]));
		if (total_DP[i] > max1) max1 = total_DP[i];
	}
	return max1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[j];
			}

			// 한줄 DP
			// 최댓값 total_arr[i]에 담기
			total_arr[i] = find_tmp();
		}
		cout << find_total() << '\n';
	}

	return 0;
}