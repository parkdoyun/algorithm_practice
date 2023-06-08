#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 백준 1918 - 후위 표기식
// stack, string
// 골드 2

/*
반례

A*(B+C)/D
답: ABC+*D/

A+(B-C)/D
답: ABC-D/+

A+B*C+D
답: ABC*+D+

*/

// 괄호 안에 있거나, 연산자 우선순위 높다면 (+,- vs *,/) 먼저 수식에 들어가야 함
// 괄호 끝나거나/우선순위 높은 연산(*, /) 후 무조건 뒤에 연산자 붙음
// 괄호 안에 들어가 있거나 높은 연산자면 무조건 넣기

struct node
{
	char op; // 연산자
	int depth = 0; // 괄호 깊이
};

stack<node> st;
stack<string> oper; // 피연산자

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string origin_expr, expr;
	cin >> origin_expr;
	expr = "";

	string tmp_operand = "";
	char e;
	int par_depth = 0; // 현재 괄호 깊이
	for (int i = 0; i < origin_expr.size(); i++)
	{
		e = origin_expr[i];
		if (e >= 'A' && e <= 'Z')
		{
			expr += e;
			tmp_operand += e;
		}
		else if (e == '+' || e == '-')
		{
			// 스택에 있는 먼저 표시해야 하는 우선순위의 연산 먼저 표시
			while (!st.empty() && (((st.top().op == '*'|| st.top().op == '/') && par_depth < st.top().depth) || ((st.top().op == '+' || st.top().op == '-') && par_depth <= st.top().depth)))
			{
				expr += st.top().op;
				st.pop();
				oper.pop();
			}
			oper.push(tmp_operand);
			tmp_operand.clear();
			st.push({ e , par_depth});
		}
		else if (e == '*' || e == '/')
		{
			// 먼저 표시해야 하는 우선순위의 연산 먼저 표시
			while (!st.empty() && (((st.top().op == '*' || st.top().op == '/') && par_depth <= st.top().depth) || ((st.top().op == '+' || st.top().op == '-') && par_depth < st.top().depth)))
			{
				expr += st.top().op;
				st.pop();
				oper.pop();
			}
			if (origin_expr[i + 1] >= 'A' && origin_expr[i + 1] <= 'Z')
			{
				tmp_operand += origin_expr[i + 1];

				expr += origin_expr[++i];
				expr += e;
				if (origin_expr[i + 1] == ')') // 괄호 닫는 연산일 때
				{
					i++;
					par_depth--;
				}
			}
			else if (origin_expr[i + 1] == '(') // 바로 다음 괄호 있을 때
			{
				oper.push(tmp_operand);
				tmp_operand.clear();
				st.push({ e, par_depth });
			}
		}
		else if (e == '(')
		{
			par_depth++;
		}
		else // e == ')'
		{
			par_depth--;
			if (st.empty()) continue;
 			expr += st.top().op;
			st.pop();

			tmp_operand = oper.top() + tmp_operand;
			oper.pop();
			oper.push(tmp_operand);
			tmp_operand.clear();

			// 다음에 연산 있을 때 처리 (만약 스택에 먼저 처리되어야 하는 연산 있을 때)
			if (i + 1 != origin_expr.size())
			{
				if (origin_expr[i + 1] == '/' || origin_expr[i + 1] == '*')
				{
					if (!st.empty() && (st.top().op == '/' || st.top().op == '*'))
					{
						while (!st.empty() && st.top().depth >= par_depth && (st.top().op == '/' || st.top().op == '*'))
						{
							expr += st.top().op;
							st.pop();
							oper.pop();
						}
					}
					else continue;
				}
			}
		}
	}

	// 마지막 남은 연산자들 표시
	while (!st.empty())
	{
		expr += st.top().op;
		st.pop();
	}

	cout << expr;	

	return 0;
}