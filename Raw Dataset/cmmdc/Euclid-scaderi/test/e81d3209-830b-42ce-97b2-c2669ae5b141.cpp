#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int main()

{

    int a, b, r;

    fin >> a >> b;

    while (a != b)

    {

        if (a > b)

            a = a - b;

        if (b > a)

            b = b - a;

    }

    if (a == 1)

        fout << 0;

    else fout << a;



    return 0;

}
