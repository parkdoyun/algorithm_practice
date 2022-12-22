#include <iostream>

using namespace std;

// ���� 1068 - Ʈ��
// DFS
// ��� 5

// 1. ���� ������ ��� ���鼭 root[a]�� del_n��� ��� ���߰� �� �ر��� ���� �����
// 2. �� �Ŀ� ���� ���鼭 �ڽ� �ִ� �ֵ� üũ
// 3. root[i]�� -2 (������ ���) �ƴϰ� �ڽ� ���� �ֵ� (���� ���) ���

int n, del_n;

int root[51]; // -2�̸� ���� ���
int hasChild[51]; // �ڽ� ������ 1 ǥ��

int searchRoot(int a)
{
	if (root[a] == del_n) // �θ� �����ƴٸ�
	{
		root[a] = -2; // ����
		return -1;
	}
	else if (root[a] == -2) // �̹� �����ƴٸ�
	{
		return -1;
	}
	else if (root[a] == a) // �����ϰ� ��Ʈ�� �Դٸ� �ٽ� ������
	{
		return 1;
	}

	int res = searchRoot(root[a]);
	if (res == -1)
	{
		root[a] = -2; // �� ����
		return -1;
	}
	else if (res == 1) return 1;
}

// �θ� ��� üũ
void chkChild(int a) // -2�̸� ���ʿ� ������ �� �ϰ�
{
	if (hasChild[a] == 1) return; // �̹� üũ�ƴٸ� ��� ����
	hasChild[a] = 1; // �ڽ� �ִٰ� ǥ��
	if (root[a] == a) return; // ��Ʈ��� ��� ����
	chkChild(root[a]); // �θ� Ȯ��
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> root[i];
		if (root[i] == -1) root[i] = i;
	}
	cin >> del_n;
	root[del_n] = -2; // ��� ����
	for (int i = 0; i < n; i++)
	{
		searchRoot(i); // Ʈ�� Ž��
	}

	// �θ� ��� üũ
	for (int i = 0; i < n; i++)
	{
		if (root[i] == -2) continue;
		chkChild(root[i]);
	}

	int total_cnt = 0; // ��Ʈ�� ���� �Ǿ��� �� ���� ó��
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (root[i] != -2) total_cnt++;
		if (root[i] == -2 || hasChild[i] == 1) continue; // �θ� ����̰ų� ������ ����� pass
		cnt++;
	}

	// ��� ���
	if (total_cnt == 1) cout << 1;
	else cout << cnt;

	return 0;
}