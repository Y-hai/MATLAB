#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int q[N];

int main()
{
    int m;
    cout << "�����뵱ǰ��������";
    cin >> m;
    double p = m / 3600.0;
    cout << "���ʣ�" << p << endl;
    int ok = 5;
    double zwait = 0;
    while (ok--)
    {
        int T = 0, t = -1, count = 0, wait = 0, jj = 0;
        int hh = 0, tt = -1;
        while (hh <= tt || T <= 3600)
        {
            // �ж��Ƿ����
            if (T <= 3600)
            {
                double yyds = rand() % 1000 / 1000.0;
                if (yyds <= p)
                {
                    cout << yyds << endl;
                    if (tt - hh <= 350)
                    {
                        q[++tt] = T;
                        count++;
                    }
                    else
                    {
                        jj++;
                    }
                }
            }
            // ʱ��++
            T++, t++;
            // �ж��Ƿ����
            if (!(t % 90))
            {
                wait += T - q[hh];
                hh++; // ����
            }
        }
        zwait += wait / 60.0 / count;
        // cout << "�ܾ�������" << jj << endl;
        // cout << "��������" << count << endl;
    }
    cout << "�ȴ�ʱ�䣺" << zwait / 5 << endl;
    return 0;
}