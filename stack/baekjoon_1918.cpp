#include <iostream>
#include <string>
#include <stack>

using namespace std;

// ���� 1918 - ���� ǥ���
// stack, string
// ��� 2

/*
�ݷ�

A*(B+C)/D
��: ABC+*D/

A+(B-C)/D
��: ABC-D/+

A+B*C+D
��: ABC*+D+

*/

// ��ȣ �ȿ� �ְų�, ������ �켱���� ���ٸ� (+,- vs *,/) ���� ���Ŀ� ���� ��
// ��ȣ �����ų�/�켱���� ���� ����(*, /) �� ������ �ڿ� ������ ����
// ��ȣ �ȿ� �� �ְų� ���� �����ڸ� ������ �ֱ�

struct node
{
	char op; // ������
	int depth = 0; // ��ȣ ����
};

stack<node> st;
stack<string> oper; // �ǿ�����

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
	int par_depth = 0; // ���� ��ȣ ����
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
			// ���ÿ� �ִ� ���� ǥ���ؾ� �ϴ� �켱������ ���� ���� ǥ��
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
			// ���� ǥ���ؾ� �ϴ� �켱������ ���� ���� ǥ��
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
				if (origin_expr[i + 1] == ')') // ��ȣ �ݴ� ������ ��
				{
					i++;
					par_depth--;
				}
			}
			else if (origin_expr[i + 1] == '(') // �ٷ� ���� ��ȣ ���� ��
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

			// ������ ���� ���� �� ó�� (���� ���ÿ� ���� ó���Ǿ�� �ϴ� ���� ���� ��)
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

	// ������ ���� �����ڵ� ǥ��
	while (!st.empty())
	{
		expr += st.top().op;
		st.pop();
	}

	cout << expr;	

	return 0;
}