#include <iostream>
using namespace std;

// ���� 3584 - ���� ����� ���� ����
// Ʈ�� (���� X)

struct node
{
	int value;
	node *parent = NULL;
};

int main()
{
	int t, n, a, b, node1, node2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		struct node tree[10001];
		int node1_route[10001]{ 0 }; // ��Ʈ������ ��� �ִ� �迭
		int node2_route[10001]{ 0 };
		cin >> n;
		for (int j = 0; j < n - 1; j++)
		{
			cin >> a >> b;
			tree[b].parent = &tree[a];
			tree[b].value = b;
			tree[a].value = a; // �̷��� �� �ϸ� ��Ʈ�� �� �� ��
		}
		cin >> node1 >> node2;
		// ��Ʈ������ ��� ���
		int node1_route_len = 0; // �迭���� 0�� ���� �� ��.
		int node2_route_len = 0; 
		node1_route[0] = -1; // �񱳰� ����
		node2_route[0] = -2;
		node *tmp = &tree[node1];
		while (tmp != NULL) // ��Ʈ����
		{
			node1_route[++node1_route_len] = tmp->value;
			tmp = tmp->parent;
		}
		tmp = &tree[node2];
		while (tmp != NULL)
		{
			node2_route[++node2_route_len] = tmp->value;
			tmp = tmp->parent;
		}
		// �� ��ο��� ������ ã��
		while (node1_route_len != 0 && node2_route_len != 0)
		{			
			if ((node1_route[node1_route_len] == node2_route[node2_route_len]) && 
				(node1_route[node1_route_len-1] != node2_route[node2_route_len-1]))
			{
				cout << node1_route[node1_route_len] << '\n';
				break;
			}				
			node1_route_len--;
			node2_route_len--;
		}
	}
	return 0;
}