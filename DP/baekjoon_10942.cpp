#include <iostream>
#include <map>

using namespace std;

// ���� 10942 - �Ӹ����?
// DP
// ��� 4

// ó���� �� �ε����� �ε��� ���̸� �߽����� �ϴ� ���� �� ȸ�� ã�Ƽ�
// ó�� �ε����� ������ �ε����� �迭�� ���� �����Ѵ�
// s, e �Է¹����� �ش� ���� �߽��� ã�� ���� �� ȸ���� ���� �ȿ� ������ Ȯ���Ѵ�.

// �ð� �ʰ�
// map �������� arr�� ���� => map �ð� ���� �ɸ� => �ذ�

int arr[2001];

struct node
{
	int start; // ����
	int end;
};

node map1[5000]; // �ε��� ����(2�� 3����)�� �߽����� �ϴ� ȸ���� ã�ƾ� ��


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m, s ,e;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// map1 ����� (ȸ�� ����)
	int start, end;
	for (int i = 2; i <= 2 * n; i++)
	{
		if (i % 2 == 0) // �ϳ����� �����ϴ� ȸ��
		{
			start = i / 2;
			end = i / 2;
		}
		else // .5�� ȸ�� ó��
		{
			start = i / 2;
			end = i / 2 + 1;
		}
		while (arr[start] == arr[end] && start >= 1 && end <= n)
		{
			start--;
			end++;

		}
		map1[i].start = start + 1;
		map1[i].end = end - 1;
		//map1.insert({ (d / 2), {start + 1, end - 1} });
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		if (s == e)
		{
			cout << 1 << '\n';
			continue;
		}
		
		if (s >= map1[s + e].start && e <= map1[s + e].end)
		{
			cout << 1 << '\n';
		}
		else cout << 0 << '\n';
	}

	return 0;
}