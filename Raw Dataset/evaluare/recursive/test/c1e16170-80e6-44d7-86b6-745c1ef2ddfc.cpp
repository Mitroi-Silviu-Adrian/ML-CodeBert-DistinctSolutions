#include <bits/stdc++.h>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char *p, s[100005];

int eval();

int termen();

int factor();

int eval()

{

    int r=termen();

    while(*p=='+' || *p=='-')

        if(*p=='+')

        {

            p++;

            r+=termen();

        }

        else

        {

            p++;

            r-=termen();

        }

    return r;

}

int termen()

{

    int r=factor();

    while(*p=='*' || *p=='/')

        if(*p=='*')

        {

            p++;

            r*=factor();

        }

        else

        {

            p++;

            r/=factor();

        }

        return r;

}

int factor()

{

    int r=0;

    if(*p=='(')

    {

        p++;

        r=eval();

        p++;

    }

    else

        while(*p>='0' && *p<='9')

    {

        r=r*10+*p-'0';

        p++;

    }

    return r;

}

int main()

{

    f.getline(s,100000);

    p=s;

    int rez=eval();

    g<<rez;

    return 0;

}
