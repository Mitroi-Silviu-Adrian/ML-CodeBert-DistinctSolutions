#include <fstream>

const int N=100001;
char s[N];
int p;

using namespace std;

int expresie();
int termen();
int factor();

int expresie()
{
    int sum = termen();
    while(s[p] == '+'||s[p] == '-')
    {
        if(s[p] == '+')
        {
            p++;
            sum += termen();
        }
        else
        {
            p++;
            sum -= termen();
        }
    }
    return sum;
}

int termen()
{
    int produs = factor();
    while(s[p] == '*'|| s[p] == '/')
    {
        if(s[p] == '*')
        {
            p++;
            produs *= factor();
        }
        else
        {
            p++;
            produs /= factor();
        }
    }
    return produs;
}

int factor()
{
    int val = 0, semn = 1;
    while(s[p] == '-')
    {
        p++;
        semn = -semn;
    }
    if(s[p] == '(')
    {
        p++;
        val = expresie();
        p++;
        return semn * val;
    }
    while('0' <= s[p] && s[p] <= '9')
    {
        val = val*10 +(s[p] - '0');
        p++;
    }
    return semn*val;
}

int main()
{
    ifstream in("evaluare.in");
    ofstream out("evaluare.out");
    in >> s;
    out << expresie();
    return 0;
}
