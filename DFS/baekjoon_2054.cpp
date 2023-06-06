#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2054 - 계산 문제
// backtracking, string
// 골드 1

string expr;
string cal_expr; // 마지막 계산용
char oper[4] = { ' ', '*', '+', '-' };
char path[10];
int expr_len;
vector<string> vec; // 마지막 정렬용

vector<int> cal_num; // 숫자
vector<int> cal_num2;
vector<char> cal_opr; // 연산자
vector<char> cal_opr2;

void cal()
{
	// 수식 생성
	cal_expr = "";
	for (int i = 0; i < expr_len; i++)
	{
		cal_expr += expr[i];
		if (path[i] != ' ')
		{
			cal_expr += path[i];
		}
	}
	// 마지막 수 넣기
	cal_expr += expr[expr_len];

	// 계산
	cal_num2 = cal_num;
	cal_opr2 = cal_opr;

	// 곱하기부터 계산
	int res = 0;
	for (int i = 0; i < cal_opr2.size(); i++)
	{
		if (cal_opr2[i] == '*')
		{
			res = cal_num2[i] * cal_num2[i + 1];
			cal_num2.erase(cal_num2.begin() + i);
			cal_num2.erase(cal_num2.begin() + i);
			cal_num2.insert(cal_num2.begin() + i, res);

			cal_opr2.erase(cal_opr2.begin() + i);
			i--;
		}
	}
	// 더하기, 빼기 순서대로 계산
	res = cal_num2[0];
	for (int i = 0; i < cal_opr2.size(); i++)
	{
		if (cal_opr2[i] == '+')
		{
			res += cal_num2[i + 1];
		}
		else // '-'
		{
			res -= cal_num2[i + 1];
		}
	}

	if (res == 2000)
	{
		vec.push_back(cal_expr);
	}
}

void backtracking(int lv, string tmp_num)
{
	if (lv == expr_len)
	{
		tmp_num += expr[lv];
		cal_num.push_back(stoi(tmp_num));
		cal();
		cal_num.pop_back();
		return;
	}

	cal_num.push_back(stoi(tmp_num + expr[lv]));
	for (int i = 1; i <= 3; i++)
	{
		path[lv] = oper[i];
		cal_opr.push_back(oper[i]);
		backtracking(lv + 1, "");
		cal_opr.pop_back();
	}
	cal_num.pop_back();

	if (tmp_num + expr[lv] == "0") return;

	path[lv] = ' ';
	backtracking(lv + 1, tmp_num + expr[lv]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> expr;
	expr_len = expr.length();
	expr_len--;

	if (expr_len == 0) return 0; // 예외 처리

	string tmp_num = "";
	tmp_num += expr[0];
	path[0] = oper[0];
	backtracking(1, tmp_num);

	tmp_num = "";
	cal_num.push_back((int)(expr[0] - '0'));
	for (int i = 1; i <= 3; i++)
	{
		path[0] = oper[i];
		cal_opr.push_back(oper[i]);
		backtracking(1, tmp_num);
		cal_opr.pop_back();
	}

	sort(vec.begin(), vec.end());
	for (auto e : vec) cout << e << '\n';

	return 0;
}