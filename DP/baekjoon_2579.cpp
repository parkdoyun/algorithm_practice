#include <iostream>

using namespace std;

// 백준 2579 - 계단 오르기
// DP
// 실버 3

// 무조건 두개 밟고 점프가 아니라 한개 밟고도 점프 가능 => no에 one, two 최댓값 넣기

int no[301]; // 이 계단 안 밟을 때
int one[301]; // 이 계단을 첫번째로 밟을 때
int two[301]; // 이 계단을 두번째로 밟을 때

// 계단 값
int arr[301];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// 기저 조건
	one[1] = arr[1];

	two[2] = arr[1] + arr[2];
	one[2] = arr[2];
	no[2] = arr[1];

	for (int i = 3; i <= n; i++)
	{
		no[i] = max(two[i - 1], one[i-1]);
		one[i] = no[i - 1] + arr[i];
		two[i] = one[i - 1] + arr[i];
	}

	cout << max(one[n], two[n]);


	return 0;
}