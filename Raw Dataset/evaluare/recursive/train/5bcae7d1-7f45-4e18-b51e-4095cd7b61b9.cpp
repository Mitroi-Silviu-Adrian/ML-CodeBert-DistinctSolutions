#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("evaluare.in");
ofstream out("evaluare.out");

const int N = 100001;
char s[N];
int p;

int expresie();
int termen();
int factor();

int expresie() {
    int sum = termen();
    while (s[p] == '+' || s[p] == '-') {
        if (s[p] == '+') {
            p++;
            sum += termen();
        }
        else {
            p++;
            sum -= termen();
        }
    }

    return sum;
}

int termen() {
    int sum = factor();
    while (s[p] == '*' || s[p] == '/') {
        if (s[p] == '*') {
            p++;
            sum *= factor();
        }
        else {
            p++;
            sum /= factor();
        }
    }

    return sum;
}

int factor() {
    int val = 0, semn = 1;

    while (s[p] == '-') {
        p++;
        semn = -semn;
    }

    if (s[p] == '(') {
        p++;
        val = expresie();
        p++;

        return semn * val;
    }

    while (s[p] >= '0' && s[p] <= '9') {
        val = val * 10 + (s[p] - '0');
        p++;
    }

    return semn * val;
}

int main()
{
    in >> s;
    out << expresie() << endl;
    return 0;
}
