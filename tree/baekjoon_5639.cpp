#include <iostream>
using namespace std;

// ���� 5639 - ���� �˻� Ʈ��
// ���� Ž�� Ʈ��
// ���� ��ȸ�ϸ鼭 �� ��� + �޸� ����

struct node
{
	int value;
	node *left = NULL;
	node *right = NULL;
};

void preOrder(int value, node *tmp, node *prev);
void postOrder(node *tmp);

int main()
{
	int n;
	cin >> n;
	node *root = new node;
	root->value = n;
	
	while (cin >> n) // �Է� ���� ���� �� �̷� ������ ó��
	{
		preOrder(n, root, NULL);
	}
	postOrder(root);
	return 0;
}

void preOrder(int value, node *tmp, node *prev) // ���� ��ȸ
{
	if (tmp == NULL) // leaf node
	{
		node *n = new node;
		n->value = value;
		if (value < prev->value) prev->left = n; // tmp�� ���ϸ� �� �� (NULL�̱� ������ right�� ����)
		else prev->right = n;
		return;
	}
	if (value < tmp->value)	preOrder(value, tmp->left, tmp);
	if (value > tmp->value) preOrder(value, tmp->right, tmp);
}

void postOrder(node *tmp) // ���� ��ȸ
{
	if (tmp->left != NULL) postOrder(tmp->left);
	if (tmp->right != NULL) postOrder(tmp->right);
	cout << tmp->value << '\n';
	if (tmp->left == NULL && tmp->right == NULL) delete tmp; // �޸� ����
}