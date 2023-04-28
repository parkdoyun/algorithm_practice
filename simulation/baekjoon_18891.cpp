#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 백준 18891 - 제21대 국회의원 선거
// 구현
// 플래티넘 5

// 소수점 이하 차례로 배분은 소수점 큰 순서대로 1씩 배분한다는 뜻

int P, V;
struct party
{
    string name;
    int location_n; // 지역구 의석 수 / 비례대표 의석 수
    int vote_n; // 비례대표국회의원선거 득표 수
    double p; // 의석할당정당의 득표수 / 모든 의석할당정당의 득표수 합
    bool flag = false; // 의석할당정당인지 아닌지
    int chair_n = 0; // 얻은 의석 수
};
vector<party> vec;
double s[51];

struct ch // 잔여의석 남았을 때, 초과의석, 의석배분방식에서도 사용
{
    int idx; // 전체 벡터에서 어디인지
    int a; // 정수 부분
    double b; // 소수점 부분
};
vector<ch> vec_ch;
bool cmp_ch(ch l1, ch l2)
{
    if (l1.b > l2.b) return true;
    else if (l1.b == l2.b && l1.idx < l2.idx) return true;
    return false;
}
bool final_cmp(party p1, party p2) // 정답 출력 시
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

    int none_party = 0; // 무소속 지역구 의석 수
    int total_vote = 0; // 총 의석할당정당 수
    int total_location = 0; // 무소속 아닌 지역구 의석 수
    int none_location = 0; // 의석할당정당이 아닌 정당의 지역구 당선인 수
    int total = 0; // 전체 투표 수 (무효표 제외 위하여)
    for (int i = 0; i < P; i++)
    {
        cin >> vec[i].name >> vec[i].location_n >> vec[i].vote_n;
        total += vec[i].vote_n;
        vec[i].chair_n = vec[i].location_n;
        total_location += vec[i].location_n; // 지역구 의석 수 체크
    }

    none_party = 253 - total_location;

    for (int i = 0; i < P; i++)
    {
        // 의석할당정당인지
        if ((double)(vec[i].vote_n / (double)(total)) >= 0.03 || vec[i].location_n >= 5)
        {
            vec[i].flag = true;
            total_vote += vec[i].vote_n;
        }
        else none_location += vec[i].location_n;
    }

    // p 구하기
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
        else s[i] = floor(s[i] + 0.5); // 반올림
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

        // 배분
        int total_num = 0;
        for (int i = 0; i < P; i++) // 정수 먼저 배분
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
    else // total_s == 30, s[i] 그대로 배분
    {
        for (int i = 0; i < P; i++) // 정수 먼저 배분
        {
            if (vec[i].flag == false) continue;
            vec[i].chair_n += s[i];
        }
    }

    // 나머지 17석 배분
    for (int i = 0; i < P; i++)
    {
        vec_ch[i].idx = i;
        vec_ch[i].b = (double)(17) * vec[i].p;
        vec_ch[i].a = floor(vec_ch[i].b);
        vec_ch[i].b -= (double)vec_ch[i].a;
    }
    sort(vec_ch.begin(), vec_ch.end(), cmp_ch);

    // 배분
    int total_num = 0;
    for (int i = 0; i < P; i++) // 정수 먼저 배분
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

    // 결과 출력
    sort(vec.begin(), vec.end(), final_cmp);
    for (int i = 0; i < P; i++)
    {
        cout << vec[i].name << ' ' << vec[i].chair_n << '\n';
    }

    return 0;
}