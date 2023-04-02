#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// ���� 23629 - �� �󸶳� �����ϰ� ���ù����� �����̴�
// string, map
// ��� 5

// 1. �� �� ��ȣ�� �� �� ��� ����
// 2. �߰� �����ڿ� ��ȣ�� �� ��� ����
// 3. +, -, x, / �� �ٸ� �����ڰ� �� ��� ����
// 4. ��Ȯ�� ���� �ܿ� �ٸ� �ֵ��� �� ��� ����

// �ݷ� 1. EIGHTZEROZERO-NINEZEROZERO = -ONE ����
// �ݷ� 2. EIGHT-EIGHT= �� ����

unordered_map<string, int> num_map;
unordered_map<int, string> num_map_reverse;

long long int res = 0; // ������ ��
long long int tmp; // ������ ����� ��

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
	string change_exp = ""; // ��ȯ�Ǵ� ����
	string tmp_s; // ���� ���ڵ�
	string num_s; // ����
	int tmp_flag;
	if (exp.back() != '=') // ���� =�� �ƴ϶��
	{
		cout << "Madness!";
		return 0;
	}
	for (int i = 0; i < exp.length();)
	{
		if (!(exp[i] >= 'A' && exp[i] <= 'Z')) // �����ڰ� ���´ٸ�
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
				if (num_map.find(num_s) != num_map.end()) // ã������
				{
					tmp_s += (char)('0' + num_map[num_s]);
					tmp_flag = 1;
					i++;
					break;
				}
				if (!(exp[i] >= 'A' && exp[i] <= 'Z')) break;
				i++;
			}
			if (tmp_flag == 0) // ���ڰ� ���ٸ�
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

		// ���ڿ� ������ �߰�
		change_exp += tmp_s + exp[i];
		if (exp[i] == '=' && i != exp.length() - 1) // �߰��� = ������ �� ��
		{
			flag = 1;
			break;
		}
		i++;
	}

	if (flag == 1) cout << "Madness!";
	else
	{ 
		// ���� ���

		// ó�� �� ���
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

		// ��� �� ���
		char ope = change_exp[i]; // ������
		int prev = i + 1;
		i++;
		while (i < change_exp.length()) // �������� =�̹Ƿ�
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

				// ����
				if (!cal(ope))
				{
					cout << "Madness!";
					return 0;
				}

				// ���� �غ�
				prev = i + 1;
				ope = change_exp[i];
			}
			i++;
		}

		// res �� ���ڿ��� �ٲٱ�
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

		// ���� 0�̰ų� 0�� �߰��� ���� ��� ���ڿ��� �߰� �� ��
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