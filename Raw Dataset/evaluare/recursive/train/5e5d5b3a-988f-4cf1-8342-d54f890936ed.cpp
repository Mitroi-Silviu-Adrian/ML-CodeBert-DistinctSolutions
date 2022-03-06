#include <iostream>
#include <fstream>
using namespace std;

long long int sol, i;

int expresie();

int termen ();

int factor();

char s[100010];

int main()

{

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    fin.get(s,1000001);

    sol=expresie();

    fout<<sol;



    return 0;

}

int expresie()

{

    int r=termen();

    while(s[i]=='+'||s[i]=='-')

        if(s[i]=='+')

        {

            i++;

            r+=termen();

        }

        else

        {

            i++;

            r-=termen();

        }

    return r;

}

int termen()

{



    int r=factor();

    while(s[i]=='*'||s[i]=='/')

        if(s[i]=='*')

        {

            i++;

            r*=factor();

        }

        else

        {

            i++;

            r/=factor();

        }

    return r;

}



int factor()

{

    int r;

    if(s[i]=='(')

    {

        i++;

        r=expresie();

        i++;

    }

    else

    {

        r = 0;

        while (s[i] >= '0' && s[i] <= '9') {

            r = r*10 + s[i]-'0';

            i++;

        }

    }

    return r;

}
