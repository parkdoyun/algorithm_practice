#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// ���� 18891 - ��21�� ��ȸ�ǿ� ����
// ����
// �÷�Ƽ�� 5

// �Ҽ��� ���� ���ʷ� ����� �Ҽ��� ū ������� 1�� ����Ѵٴ� ��

int P, V;
struct party
{
    string name;
    int location_n; // ������ �Ǽ� �� / ��ʴ�ǥ �Ǽ� ��
    int vote_n; // ��ʴ�ǥ��ȸ�ǿ����� ��ǥ ��
    double p; // �Ǽ��Ҵ������� ��ǥ�� / ��� �Ǽ��Ҵ������� ��ǥ�� ��
    bool flag = false; // �Ǽ��Ҵ��������� �ƴ���
    int chair_n = 0; // ���� �Ǽ� ��
};
vector<party> vec;
double s[51];

struct ch // �ܿ��Ǽ� ������ ��, �ʰ��Ǽ�, �Ǽ���й�Ŀ����� ���
{
    int idx; // ��ü ���Ϳ��� �������
    int a; // ���� �κ�
    double b; // �Ҽ��� �κ�
};
vector<ch> vec_ch;
bool cmp_ch(ch l1, ch l2)
{
    if (l1.b > l2.b) return true;
    else if (l1.b == l2.b && l1.idx < l2.idx) return true;
    return false;
}
bool final_cmp(party p1, party p2) // ���� ��� ��
{
    if (p1.chair_n > p2.chair_n) return true;
    else if (p1.chair_n == p2.chair_n && p1.name < p2.name) return true;
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> P >> V;
    vec.resize(P);
    vec_ch.resize(P);

    int none_party = 0; // ���Ҽ� ������ �Ǽ� ��
    int total_vote = 0; // �� �Ǽ��Ҵ����� ��
    int total_location = 0; // ���Ҽ� �ƴ� ������ �Ǽ� ��
    int none_location = 0; // �Ǽ��Ҵ������� �ƴ� ������ ������ �缱�� ��
    int total = 0; // ��ü ��ǥ �� (��ȿǥ ���� ���Ͽ�)
    for (int i = 0; i < P; i++)
    {
        cin >> vec[i].name >> vec[i].location_n >> vec[i].vote_n;
        total += vec[i].vote_n;
        vec[i].chair_n = vec[i].location_n;
        total_location += vec[i].location_n; // ������ �Ǽ� �� üũ
    }

    none_party = 253 - total_location;

    for (int i = 0; i < P; i++)
    {
        // �Ǽ��Ҵ���������
        if ((double)(vec[i].vote_n / (double)(total)) >= 0.03 || vec[i].location_n >= 5)
        {
            vec[i].flag = true;
            total_vote += vec[i].vote_n;
        }
        else none_location += vec[i].location_n;
    }

    // p ���ϱ�
    for (int i = 0; i < P; i++)
    {
        if (vec[i].flag == false) continue;
        vec[i].p = (double)vec[i].vote_n / (double)total_vote;
    }

    double total_s = 0;
    for (int i = 0; i < P; i++)
    {
        s[i] = ((double)(300 - none_party - none_location) * vec[i].p - (double)vec[i].location_n) / (double)2;
        if (s[i] < 1) s[i] = 0;
        else s[i] = floor(s[i] + 0.5); // �ݿø�
        total_s += s[i];
    }

    if (total_s != 30)
    {
        if (total_s > 30)
        {
            for (int i = 0; i < P; i++)
            {
                vec_ch[i].idx = i;
                vec_ch[i].b = (double)(30 * s[i]) / total_s;
                vec_ch[i].a = floor(vec_ch[i].b);
                vec_ch[i].b -= (double)vec_ch[i].a;
            }
        }
        else // total_s < 30
        {
            double tmp_left = 30 - total_s;
            for (int i = 0; i < P; i++)
            {
                vec_ch[i].idx = i;
                vec_ch[i].b = s[i] + tmp_left * vec[i].p;
                vec_ch[i].a = floor(vec_ch[i].b);
                vec_ch[i].b -= (double)vec_ch[i].a;
            }
        }
        sort(vec_ch.begin(), vec_ch.end(), cmp_ch);

        // ���
        int total_num = 0;
        for (int i = 0; i < P; i++) // ���� ���� ���
        {
            if (vec[vec_ch[i].idx].flag == false) continue;
            vec[vec_ch[i].idx].chair_n += vec_ch[i].a;
            total_num += vec_ch[i].a;
        }
        int i = 0;
        int tmp_total_left = 30 - total_num;
        while (total_num < 30)
        {
            if (vec[vec_ch[i].idx].flag == false)
            {
                i = (i + 1) % P;
                continue;
            }
            vec[vec_ch[i].idx].chair_n++;
            total_num++;
            i = (i + 1) % P;
        }
    }
    else // total_s == 30, s[i] �״�� ���
    {
        for (int i = 0; i < P; i++) // ���� ���� ���
        {
            if (vec[i].flag == false) continue;
            vec[i].chair_n += s[i];
        }
    }

    // ������ 17�� ���
    for (int i = 0; i < P; i++)
    {
        vec_ch[i].idx = i;
        vec_ch[i].b = (double)(17) * vec[i].p;
        vec_ch[i].a = floor(vec_ch[i].b);
        vec_ch[i].b -= (double)vec_ch[i].a;
    }
    sort(vec_ch.begin(), vec_ch.end(), cmp_ch);

    // ���
    int total_num = 0;
    for (int i = 0; i < P; i++) // ���� ���� ���
    {
        if (vec[vec_ch[i].idx].flag == false) continue;
        vec[vec_ch[i].idx].chair_n += vec_ch[i].a;
        total_num += vec_ch[i].a;
    }
    int i = 0;
    int tmp_total_left = 17 - total_num;
    while (total_num < 17)
    {
        if (vec[vec_ch[i].idx].flag == false)
        {
            i = (i + 1) % P;
            continue;
        }
        vec[vec_ch[i].idx].chair_n++;
        total_num++;
        i = (i + 1) % P;
    }

    // ��� ���
    sort(vec.begin(), vec.end(), final_cmp);
    for (int i = 0; i < P; i++)
    {
        cout << vec[i].name << ' ' << vec[i].chair_n << '\n';
    }

    return 0;
}