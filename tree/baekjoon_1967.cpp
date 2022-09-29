#include <iostream>
#include <vector>
using namespace std;

// ���� 1967�� - Ʈ���� ����
// Ʈ��, DFS
// �������� �ö���鼭 �ڽ��� ���κ��� �������� �Ʒ��� ������� ��� �߿�
// ���� �ΰ�(����ġ ����)�� ���ؼ� route_max�� ���Ѵ�
// ��δ� ������ ���� ���� ���
// DFS �Լ��� ����ġ �ֻ��� ��ο� ���� ����ġ ���� �� ���� (�ڽ��� ��带 ��ġ�� ��� �߿� �ִ� ����)

struct node
{
	node *parent = NULL;
	vector<int> child; // �ڽ��� �ε��� ��ȣ
};
struct edge // edge_arr �迭�� �ε��� : �ڽ� ��� ��ȣ
{
	int value = 0;
	int parent = -1; // tree �迭�� �ε��� ��ȣ (��� ��ȣ)
};

// �ö���鼭 ���� ū ��ΰ� ����
int DFS(int idx);
int route_max = 0;

node tree[10001]; // ��Ʈ : tree[1]
edge edge_arr[10001]; // ���� ���� ���� �迭

int main()
{
	int n, p, c, v;
	cin >> n;
	for (int i = 1; i < n; i++) // Ʈ�� ����
	{
		cin >> p >> c >> v;
		tree[p].child.push_back(c);
		tree[c].parent = &tree[p];
		edge_arr[c].parent = p;
		edge_arr[c].value = v;		
	}
	DFS(1);
	cout << route_max << '\n';
	return 0;
}

// ���� ��� �ö���鼭 ���
// ���������� ��� �߿� ���� ū �Ͱ� �ι�°�� ū �� ���
// ��� �ִ� ���

int DFS(int idx) // ����ġ �� �� ���� ū ��(�ٸ��� �������� ���� ���������� ��)�ΰ�
{
	int max1 = 0; // ����ġ ���� ū ��� ��(�ٸ� �����κ��� �ڽű���)
	int sec_max1 = 0; // �ι�°�� ū ��� ��
	if (tree[idx].child.size() == 0) // ���� �����
	{
		return edge_arr[idx].value;	// ���� ������ ����	
	}	
	else
	{
		for (int i = 0; i < tree[idx].child.size(); i++)
		{
			int a = DFS(tree[idx].child[i]); // ��ΰ� ��
			if (a > max1)
			{			
				sec_max1 = max1;
				max1 = a;
			}
			else if (a > sec_max1) sec_max1 = a;
			
		}
	}
	int tmp = max1 + sec_max1;
	if (tmp > route_max) route_max = tmp; // route_max�� ��
	return max1 + edge_arr[idx].value;
}