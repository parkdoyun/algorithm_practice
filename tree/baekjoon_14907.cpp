#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ���� 14907 - ������Ʈ �����ٸ�
// tree
// ��� 2

// �θ� ������ -> �θ���� ���� �Ϸ�� ������ ���� �� �Ѵ�
// �θ���� �ִ񰪿��� ���ؾ� ��
// ���� �ִ� 26�� (A : 0 ~ Z : 25)
// �ڽ� ������, �θ� ������ => Ʈ�� ���� 2���� �迭

// **���� : ��Ʈ�� ������ �� ����**

#define INF 999999999

int root[26]; // 1�̸� �θ� X, ��Ʈ
int vertex_time[26];
int total_time[26]; // �ҿ�� �ð�
vector<vector<int>> parent; // �θ� ����
vector<vector<int>> child; // �ڽ� ����

// ���� �ٸ� �θ� INF (�ϴ� ������)
// ���� ��� �θ� INF �ƴ϶�� �� �� �ִ�� ����
// �ڽĵ�� Ÿ�� ����
void recursion(int now)
{
	if (total_time[now] != INF) return; // �̹� ���� �� pass

	if (root[now] == 1) total_time[now] = vertex_time[now];
	else
	{
		int max1 = -1;
		for (int i = 0; i < parent[now].size(); i++)
		{
			if (total_time[parent[now][i]] == INF) return; // �ϳ��� ���� �湮 �� �ƴٸ�
			if (max1 < total_time[parent[now][i]]) max1 = total_time[parent[now][i]];
		}
		total_time[now] = max1 + vertex_time[now];
	}

	// �ڽ����� ����
	for (int i = 0; i < child[now].size(); i++)
	{
		recursion(child[now][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 26; i++)
	{
		vertex_time[i] = -1;
		total_time[i] = INF;
	}

	int idx, vertex, tmp_time;
	string s, tmp;
	parent.resize(26);
	child.resize(26);

	// �Է�
	while (!cin.eof())
	{
		getline(cin, s);
		if (cin.eof()) break; // eof �Է� ������

		vertex = (int)(s[0] - 'A');

		idx = 2;

		tmp = ""; // �ڿ���
		for (; idx < s.length(); idx++)
		{
			if (s[idx] == ' ' || (s[idx] >= 'A' && s[idx] <= 'Z')) break;
			tmp += s[idx];
		}
		tmp_time = stoi(tmp);
		vertex_time[vertex] = tmp_time; // �ش� ���������� �ɸ��� �ð�

		idx++;
		tmp = "";
		for (; idx < s.length(); idx++)
		{
			if (s[idx] == ' ') break;
			tmp += s[idx];
		}

		if (tmp.empty()) root[vertex] = 1; // �θ� ������ ��Ʈ
		else // ǥ���ϱ�
		{
			for (int i = 0; i < tmp.length(); i++)
			{
				idx = (int)(tmp[i] - 'A');
				parent[vertex].push_back(idx);
				child[idx].push_back(vertex);
			}
		}
	}

	// �ּڰ� ���ϱ�
	// ��Ʈ���� Ÿ��Ÿ��
	for (int i = 0; i < 26; i++)
	{
		if (root[i] == 0) continue;
		recursion(i);
	}

	int max1 = -1;
	for (int i = 0; i < 26; i++)
	{
		if (vertex_time[i] == -1) continue;
		if (total_time[i] > max1) max1 = total_time[i];
	}

	cout << max1;

	return 0;
}