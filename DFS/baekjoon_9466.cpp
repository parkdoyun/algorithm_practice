#include <iostream>

using namespace std;

// ���� 9466 - �� ������Ʈ
// DFS
// ��� 3

// DFS�� cycle Ȯ��
// �̹� cycle Ȯ���� �ִ� 2�� ǥ��, �˻����� �ִ� 1, cycle �� �� �ִ� -1

int arr[100001];
int chk[100001]; // �̹� cycle Ȯ���� �ִ� 2�� ǥ��, �˻����� �ִ� 1, cycle �� �� �ִ� -1

int findR(int a)
{
	if (arr[a] == a) // �길 ���̰� ������ �ƿ�
	{
		chk[a] = 2;
		return -1;
	}
	else if (chk[arr[a]] == 1) // �˻� �� -> ����� �������� cycle ����
	{
		chk[a] = 2;
		chk[arr[a]] = 2;
		return 1;
	}
	else if (chk[arr[a]] == 2) // �� ���Ե��� �ʴ� �ٸ� cycle
	{
		chk[a] = -1;
		return -1;
	}
	else if (chk[arr[a]] == -1)
	{
		chk[a] = -1;
		return -1;
	}

	chk[a] = 1;
	int answer = findR(arr[a]);
	if (answer == -1) // cycle X�� ���� X
	{
		chk[a] = -1;
		return -1;
	}
	else if (answer == 1 && chk[a] == 2) // �������� cycle, �� �ں��� cycle X
	{
		return -1;
	}
	else if (answer == 1 && chk[a] == 1) // ���� cycle�� ����
	{
		chk[a] = 2;
		return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, n;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			chk[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			if (chk[i] != 0) continue;
			findR(i);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (chk[i] == -1) cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;

}