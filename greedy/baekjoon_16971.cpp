#include <iostream>

using namespace std;

// 백준 16971 - 배열 B의 값
// greedy
// 골드 3

// 첫행 or 끝행 및 첫열 or 끝열이 가장 작아야 최댓값
// + 양 끝 값이 적게 더해지므로 생각해야 함 -> 양 끝 값이 작은 행이나 열로 대체되어야 함
// 행과 열 중 가장 차이 큰 애로 한번 바꿈
// 비교는 한줄 * 2 - 양끝 값으로 해야 정확함 (실제로 배열 B가 이렇게 더해지므로)

// (1,1), (n, m)은 한번만 더해짐
// (1, k), (k, 1), (k, n - 1), (n - 1, k)은 두번 더해짐 
// 나머지(중간 값)는 4번 더해짐

#define INF 999999999
int n, m;
int arr[1001][1001];
long long int total = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int first_row = 0; // 첫번째 행
	int last_row = 0; // 마지막 행
	int first_col = 0; // 첫번째 열
	int last_col = 0; // 마지막 열
	int res_row, res_col;
	int res_row_cmp, res_col_cmp; // 비교는 양 끝까지 감안해서 해야 함 (한줄 * 2 - 양끝 값 빼기)
	int min_row = INF;
	int min_col = INF;
	int min_row_idx;
	int min_col_idx;
	int min_row_cmp = INF; // 비교할 때 쓸 값
	int min_col_cmp = INF; // 비교할 때 쓸 값

	cin >> n >> m;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			tmp += arr[i][j];
		}
		total += (long long int)tmp;
		if (i == 0) first_row = tmp;
		else if (i == n - 1) last_row = tmp;
		else
		{
			int t = tmp * 2 - arr[i][0] - arr[i][m - 1];
			if (t < min_row_cmp)
			{
				min_row_cmp = t;
				min_row = tmp;
				min_row_idx = i;
			}
		}
	}

	// 열 확인
	for (int i = 0; i < m; i++)
	{
		tmp = 0;
		for (int j = 0; j < n; j++)
		{
			tmp += arr[j][i];
		}
		if (i == 0) first_col = tmp;
		else if (i == m - 1) last_col = tmp;
		else
		{
			int t = tmp * 2 - arr[0][i] - arr[n - 1][i];
			if (t < min_col_cmp)
			{
				min_col_cmp = t;
				min_col = tmp;
				min_col_idx = i;
			}
		}
	}

	total = total * (long long int)4;

	if (first_row > last_row)
	{
		res_row = first_row;
		res_row_cmp = first_row * 2 - arr[0][m - 1] - arr[0][0];
	}
	else
	{
		res_row = last_row;
		res_row_cmp = last_row * 2 - arr[n - 1][0] - arr[n - 1][m - 1];
	}

	if (first_col > last_col)
	{
		res_col = first_col;
		res_col_cmp = first_col * 2 - arr[0][0] - arr[n - 1][0];
	}
	else
	{
		res_col = last_col;
		res_col_cmp = last_col * 2 - arr[0][m - 1] - arr[n - 1][m - 1];
	}

	// 둘 중 큰 차이 확인
	if ((res_row_cmp - min_row_cmp <= 0) && (res_col_cmp - min_col_cmp <= 0)) // 안 바꾸는 게 낫다면
	{
		total = total - (long long int)(first_col * 2) - (long long int)(last_col * 2) - (long long int)(first_row * 2) - (long long int)(last_row * 2) + (long long int)arr[0][m - 1] + (long long int)arr[0][0] + (long long int)arr[n - 1][0] + (long long int)arr[n - 1][m - 1];
	}
	else if ((res_row_cmp - min_row_cmp) > (res_col_cmp - min_col_cmp)) // 행 변경
	{
		// cout << "ROW : " << min_row_idx << '\n';
		total = total - (long long int)(first_col * 2) - (long long int)(last_col * 2) - (long long int)(min_row * 2) + (long long int)arr[min_row_idx][0] + (long long int)arr[min_row_idx][m - 1];
		if (res_row == first_row)
		{
			total = total - (long long int)(last_row * 2) + (long long int)arr[n - 1][0] + (long long int)arr[n - 1][m - 1];
		}
		else
		{
			total = total - (long long int)(first_row * 2) + (long long int)arr[0][0] + (long long int)arr[0][m - 1];
		}
	}
	else // 열 변경
	{
		//cout << "COL : " << min_col_idx << '\n';
		total = total - (long long int)(first_row * 2) - (long long int)(last_row * 2) - (long long int)(min_col * 2) + (long long int)arr[0][min_col_idx] + (long long int)arr[n - 1][min_col_idx];
		if (res_col == first_col)
		{
			total = total - (long long int)(last_col * 2) + (long long int)arr[0][m - 1] + (long long int)arr[n - 1][m - 1];
		}
		else
		{
			total = total - (long long int)(first_col * 2) + (long long int)arr[0][0] + (long long int)arr[n - 1][0];
		}
	}
	
	cout << total;

	return 0;
}