#include <iostream>
#include <string>

using namespace std;

// 백준 16120 - PPAP
// string, greedy
// 골드 4

// PPAP => 중간 P로 치환되어야 함
// PPAP 내 문자열 가리키는 포인터 사용하여 항상 PPAP가 중간 P로 치환되도록 함

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int point = 0; // PPAP 문자열 내 포인터

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'P') // 'P'PAP 이거나 P'P'AP 일 때
		{
			point++;
			continue;
		}

		if (point >= 2 && s[i + 1] == 'P') // 'A' 위치일 때
		{
			point--; // 중간 P로 치환
			i++; // 다음 PPAP 문자열 이동
		}
		else
		{
			cout << "NP";
			return 0;
		}
	}

	if(point == 1) cout << "PPAP"; // 중간 P인지 확인
	else cout << "NP"; // 아니라면

	return 0;
}