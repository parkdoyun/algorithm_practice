#include <iostream>

using namespace std;

// ���� 5373 - ť��
// simulation
// �÷�Ƽ�� 5

// �鵵 �ð� / �ݽð� �������� ������ ��

int n;
char colors[6] = { 'w', 'y', 'r', 'o', 'g', 'b' }; // �ʱ�ȭ�� �迭
char cube[6][3][3] = 
{
	{{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}}, // ����, ���
	{{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}}, // �Ʒ���, �����
	{{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}}, // �ո�, ������
	{{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}}, // �޸�, ��������
	{{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}}, // ���ʸ�, �ʷϻ�
	{{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}} // �����ʸ�, �Ķ���
};
char tmp_arr[3];

void faceRotate(int face, char dir)
{
	for (int i = 0; i < 3; i++) tmp_arr[i] = cube[face][0][i];
	if (dir == '+') // �ð� ����
	{
		for (int i = 0; i < 3; i++) cube[face][0][2 - i] = cube[face][i][0];
		for (int i = 0; i < 3; i++) cube[face][i][0] = cube[face][2][i];
		for (int i = 0; i < 3; i++) cube[face][2][i] = cube[face][2 - i][2];
		for (int i = 1; i < 3; i++) cube[face][i][2] = tmp_arr[i];
	}
	else // �ݽð�
	{
		for (int i = 0; i < 3; i++) cube[face][0][i] = cube[face][i][2];
		for (int i = 0; i < 3; i++) cube[face][i][2] = cube[face][2][2 - i];
		for (int i = 0; i < 3; i++) cube[face][2][2 - i] = cube[face][2 - i][0];
		for (int i = 1; i < 3; i++) cube[face][i][0] = tmp_arr[2 - i];
	}
}

void rotate(char face, char dir)
{
	if (face == 'U')
	{
		faceRotate(0, dir);
		if (dir == '+') // �ð� ���� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[2][0][i]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[2][0][i] = cube[5][0][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[5][0][i] = cube[3][0][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[3][0][i] = cube[4][0][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[4][0][i] = tmp_arr[i]; // �� -> ��
		}
		else // �ݽð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[4][0][i]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[4][0][i] = cube[3][0][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[3][0][i] = cube[5][0][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[5][0][i] = cube[2][0][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[2][0][i] = tmp_arr[i]; // �� -> ��
		}
	}
	else if (face == 'D')
	{
		faceRotate(1, dir);
		if (dir == '-') // �ݽð� ���� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[2][2][i]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[2][2][i] = cube[5][2][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[5][2][i] = cube[3][2][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[3][2][i] = cube[4][2][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[4][2][i] = tmp_arr[i]; // �� -> ��
		}
		else // �ð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[4][2][i];
			// �ű��
			for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[3][2][i] = cube[5][2][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[5][2][i] = cube[2][2][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[2][2][i] = tmp_arr[i]; // �� -> ��
		}
	}
	else if (face == 'F')
	{
		faceRotate(2, dir);
		if (dir == '+') // �ð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[4][i][2]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[4][i][2] = cube[1][2][2 - i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[1][2][i] = cube[5][i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[5][i][0] = cube[0][2][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[0][2][2 - i] = tmp_arr[i]; // �� -> ��
		}
		else // �ݽð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[0][2][i]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[0][2][i] = cube[5][i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[5][i][0] = cube[1][2][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2 - i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[4][2 - i][2] = tmp_arr[i]; // �� -> ��
		}
	}
	else if (face == 'B')
	{
		faceRotate(3, dir);
		if (dir == '-') // �ݽð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[4][i][0]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[4][i][0] = cube[1][0][2 - i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[1][0][i] = cube[5][i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[5][i][2] = cube[0][0][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[0][0][2 - i] = tmp_arr[i]; // �� -> ��
		}
		else // �ð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[0][0][i]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[0][0][i] = cube[5][i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[5][i][2] = cube[1][0][i]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[1][0][i] = cube[4][2 - i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[4][2 - i][0] = tmp_arr[i]; // �� -> ��
		}
	}
	else if (face == 'L') // ����
	{
		faceRotate(4, dir);
		if (dir == '+') // �ð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[0][i][0]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[0][i][0] = cube[3][2 - i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[3][i][2] = cube[1][i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[1][i][2] = cube[2][2 - i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[2][i][0] = tmp_arr[i]; // �� -> ��
		}
		else // �ݽð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[2][i][0]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[2][i][0] = cube[1][2 - i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[1][i][2] = cube[3][i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[3][i][2] = cube[0][2 - i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[0][i][0] = tmp_arr[i]; // �� -> ��
		}
	}
	else // R
	{
		faceRotate(5, dir);
		if (dir == '-') // �ݽð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[0][i][2]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[0][i][2] = cube[3][2 - i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[3][i][0] = cube[1][i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[1][i][0] = cube[2][2 - i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[2][i][2] = tmp_arr[i]; // �� -> ��
		}
		else // �ð� (�� -> �� -> �� -> ��)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[2][i][2]; // ��
			// �ű��
			for (int i = 0; i < 3; i++) cube[2][i][2] = cube[1][2 - i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[1][i][0] = cube[3][i][0]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[3][i][0] = cube[0][2 - i][2]; // �� -> ��
			for (int i = 0; i < 3; i++) cube[0][i][2] = tmp_arr[i]; // �� -> ��
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	char face, dir; // ��, ���� ����
	for (int tc = 1; tc <= T; tc++)
	{
		// ť�� �ʱ�ȭ
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int r = 0; r < 3; r++) cube[i][j][r] = colors[i];
			}
		}

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> face >> dir;

			rotate(face, dir);

		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << cube[0][i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}