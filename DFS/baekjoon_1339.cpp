#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���� 1339 - �ܾ� ����
// greedy, backtracking
// ��� 4

// ��� ����� �� �� ������
// 9 ~ ����� ����ŭ
// backtracking �� ��� ����� ��
// �ð� �ʹ� ���� �ɸ��� -> �ð� ���� ��� ã��
// �ð� ���� ��� 1. stoi(), to_string() ���� string ���� ����
//                2. DAT�� �ϳ� �� �߰��Ͽ�(value[]) ���ĺ� -> ���� ��ȯ �� ����

int max1 = 0;
int DAT[10];
int value[26]; // ���ĺ� dat -> �ð� ���� ���� (������ alpha_vec ã�� �ʵ���)
int total_size; // ���ĺ� �� �����

vector<string> words;
struct node
{
	char ch;
	int num;
};
vector<node> alpha_vec; // ���ĺ� dat

void DFS(int lv)
{
	if (lv == total_size)
	{
		// ���
		int sum = 0;
		int tmp;
		int tens;
		for (int i = 0; i < words.size(); i++)
		{
			//string s = "";
			tens = 0;
			for (int j = 0; j < words[i].size(); j++)
			{
				tmp = value[(int)(words[i][j] - 'A')];
				tens = (tens * 10) + tmp;
				
				//s += to_string(tmp); // string ���� �ð� ���� ��
			}
			//sum += stoi(s);
			sum += tens;
		}
		if (sum > max1) max1 = sum;
		
		return;
	}

	for (int i = 0; i < total_size; i++)
	{
		// backtracking
		if (DAT[i] == 1) continue;
		DAT[i] = 1;
		alpha_vec[lv].num = 9 - i;
		value[(int)(alpha_vec[lv].ch - 'A')] = 9 - i;
		DFS(lv + 1);
		DAT[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		words.push_back(s);
		for (int j = 0; j < s.length(); j++)
		{
			value[(int)(s[j] - 'A')] = 1;
		}
	}

	// alphabet
	for (int i = 0; i < 26; i++)
	{
		if (value[i] == 1)
		{
			alpha_vec.push_back({ (char)('A' + i), -1 });
		}
	}

	total_size = alpha_vec.size();

	
	for (int i = 0; i < total_size; i++)
	{
		// backtracking
		if (DAT[i] == 1) continue;
		DAT[i] = 1;
		alpha_vec[0].num = 9 - i;
		value[(int)(alpha_vec[0].ch - 'A')] = 9 - i;
		DFS(1);
		DAT[i] = 0;
	}
	
	
	
	cout << max1;

	return 0;
}