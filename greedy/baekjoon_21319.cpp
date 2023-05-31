#include <iostream>

using namespace std;

// 백준 21319 - 챔피언 (Easy)
// greedy
// 골드 2

// 가장 전투력 낮으면 무조건 불가
// 두번째로 전투력 낮은 사람부터 시작
// 무조건 나보다 가장 사람부터 대결해야 함
// 
// 어떻게 해도 못 이긴다 -> 다음 넘어감
// 챔피언 될 수 있으면 -> 번호 출력

// 왼쪽이 나와 같다면 -> 챔피언 못 함
// 왼쪽에 있는 애들 갯수 + 현재 나보다 최댓값이 더 크다면 -> 챔피언 못 함
// 나머지 가능

// 시간 초과
// 한번만 배열 확인하면 될 거 같은데?

long long int arr[200001];
long long int chk_arr[200001]; // i번째에서는 최소 chk_arr[i] 값 이상이어야 챔피언 가능
int n;

bool chk(int idx) // 챔피언 체크
{
	if (arr[idx - 1] == arr[idx]) return false; // 왼쪽이 나와 같다면 -> 챔피언 못 함
	if (idx == n) return true; // 맨 끝이라면 가능
	
	if (chk_arr[idx] < arr[idx] + (long long int)(idx - 1) ) return true;
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int flag = -1;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	if (n == 1) // 예외 처리
	{
		cout << 1;
		return 0;
	}

	// chk_arr 배열
	long long int tmp = arr[n] + (long long int)1;
	for (int i = n - 1; i >= 1; i--)
	{
		tmp -= (long long int)1;
		chk_arr[i] = tmp;
		if (tmp < arr[i] + (long long int)1 ) tmp = arr[i] + (long long int)1;
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == arr[1]) continue; // 제일 작으면 pass

		// 챔피언 될 수 있는지 확인
		if (chk(i))
		{
			cout << i << ' ';
			flag = 0;
		}
	}

	if (flag == -1) cout << -1;
	
	return 0;
}