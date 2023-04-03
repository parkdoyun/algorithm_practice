#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 백준 23629 - 이 얼마나 끔찍하고 무시무시한 수식이니
// string, map
// 골드 5

// 1. 맨 뒤 등호가 안 들어갈 경우 오답
// 2. 중간 연산자에 등호가 들어갈 경우 오답
// 3. +, -, x, / 외 다른 연산자가 들어갈 경우 오답
// 4. 정확한 숫자 외에 다른 애들이 들어갈 경우 오답

// 반례 1. EIGHTZEROZERO-NINEZEROZERO = -ONE 나옴
// 반례 2. EIGHT-EIGHT= 안 나옴

unordered_map<string, int> num_map;
unordered_map<int, string> num_map_reverse;

long long int res = 0; // 수식의 값
long long int tmp; // 앞으로 연산될 값

bool cal(char ope)
{
	if (ope == '+') res += tmp;
	else if (ope == '-') res -= tmp;
	else if (ope == 'x') res *= tmp;
	else if (ope == '/') res /= tmp;
	else return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string exp;
	cin >> exp;

	num_map.insert({ "ZERO", 0 }); num_map.insert({ "ONE", 1 });
	num_map.insert({ "TWO", 2 }); num_map.insert({ "THREE", 3 });
	num_map.insert({ "FOUR", 4 }); num_map.insert({ "FIVE", 5 });
	num_map.insert({ "SIX", 6 }); num_map.insert({ "SEVEN", 7 });
	num_map.insert({ "EIGHT", 8 }); num_map.insert({ "NINE", 9 });

	num_map_reverse.insert({ 0, "ZERO" }); num_map_reverse.insert({ 1, "ONE"});
	num_map_reverse.insert({ 2, "TWO" }); num_map_reverse.insert({ 3, "THREE"});
	num_map_reverse.insert({ 4, "FOUR" }); num_map_reverse.insert({ 5, "FIVE" });
	num_map_reverse.insert({ 6, "SIX"}); num_map_reverse.insert({ 7, "SEVEN"});
	num_map_reverse.insert({ 8, "EIGHT"}); num_map_reverse.insert({ 9, "NINE"});

	int flag = 0;
	string change_exp = ""; // 변환되는 수식
	string tmp_s; // 현재 숫자들
	string num_s; // 숫자
	int tmp_flag;
	if (exp.back() != '=') // 끝이 =이 아니라면
	{
		cout << "Madness!";
		return 0;
	}
	for (int i = 0; i < exp.length();)
	{
		if (!(exp[i] >= 'A' && exp[i] <= 'Z')) // 연산자가 나온다면
		{
			flag = 1;
			break;
		}
		tmp_s = "";
		while (exp[i] >= 'A' && exp[i] <= 'Z' && i < exp.length())
		{
			num_s = "";
			tmp_flag = 0;
			for (int j = 0; j < 5; j++)
			{
				num_s += exp[i];
				if (num_map.find(num_s) != num_map.end()) // 찾았으면
				{
					tmp_s += (char)('0' + num_map[num_s]);
					tmp_flag = 1;
					i++;
					break;
				}
				if (!(exp[i] >= 'A' && exp[i] <= 'Z')) break;
				i++;
			}
			if (tmp_flag == 0) // 숫자가 없다면
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

		// 숫자와 연산자 추가
		change_exp += tmp_s + exp[i];
		if (exp[i] == '=' && i != exp.length() - 1) // 중간에 = 연산자 들어갈 때
		{
			flag = 1;
			break;
		}
		i++;
	}

	if (flag == 1) cout << "Madness!";
	else
	{ 
		// 수식 계산

		// 처음 값 계산
		int i = 0;
		long long int tens;
		while (i < change_exp.length()) 
		{
			if (!(change_exp[i] >= '0' && change_exp[i] <= '9'))
			{
				tens = 1;
				for (int j = i - 1; j >= 0; j--)
				{
					res += (long long int)(change_exp[j] - '0') * tens;
					tens *= 10;
				}
				break;
			}
			i++;
		}

		// 계속 값 계산
		char ope = change_exp[i]; // 연산자
		int prev = i + 1;
		i++;
		while (i < change_exp.length()) // 마지막은 =이므로
		{
			if (!(change_exp[i] >= '0' && change_exp[i] <= '9'))
			{
				tens = 1;
				tmp = 0;
				for (int j = i - 1; j >= prev; j--)
				{
					tmp += (long long int)(change_exp[j] - '0') * tens;
					tens *= 10;
				}

				// 연산
				if (!cal(ope))
				{
					cout << "Madness!";
					return 0;
				}

				// 다음 준비
				prev = i + 1;
				ope = change_exp[i];
			}
			i++;
		}

		// res 값 문자열로 바꾸기
		tmp_s = "";
		if (res < 0)
		{
			tmp_s = "-";
			res *= -1;
		}
		tens = 1;
		while (true)
		{
			if (tens * 10 > res) break;
			tens *= 10;
		}

		// 답이 0이거나 0이 중간에 나올 경우 문자열에 추가 안 함
		while (tens > 0)
		{
			tmp_s += num_map_reverse[res / tens];
			res %= tens;
			tens /= 10;
		}

		cout << change_exp << '\n' << tmp_s;
	}

	return 0;
}