#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

const int Nmax = 100001;

ifstream f("cmap.in");

ofstream g("cmap.out");

struct punct

{

    int x, y;

};



punct Px[Nmax], Tmp[Nmax];

int N;



bool compx(const punct &A, const punct &B)

{

    return A.x < B.x;

}



bool compy(const punct &A, const punct &B)

{

    return A.y < B.y;

}



inline long long patrat(long long x)

{

    return x * x;

}



long long dist2(const punct &A, const punct &B)

{

    return patrat(A.x - B.x) + patrat(A.y - B.y);

}



long long distMin(int p, int u)

{

    long long dmin = 0x7FFFFFFFFFFFFFFFLL;

    for(int i = p; i < u; i++)

        for(int j = i + 1; j <= u; j++)

        {

            long long dij = dist2(Px[i], Px[j]);

            if(dmin > dij)dmin = dij;

        }

    return dmin;

}



long long calcDmin(int p, int u)

{

    if(u - p < 4)

    {

        sort(Px + p, Px + u + 1, compy);

        return distMin(p, u);

    }

    int m = (p + u) / 2;

    int x = Px[m].x;

    long long d1 = calcDmin(p, m);

    long long d2 = calcDmin(m, u);

    long long dd = min(d1, d2);

    merge(Px + p, Px + m + 1, Px + m + 1, Px + u + 1, Tmp + p, compy);

    int k = 0;

    for(int i = p; i <= u; i++)

    {

        Px[i] = Tmp[i];

        if(patrat(Px[i].x - x) < dd)

            Tmp[++k] = Px[i];

    }

    for(int i = 1; i < k; i++)

        for(int j = i + 1; j <= k && patrat(Tmp[j].y - Tmp[i].y) < dd; j++)

        {

            d1 = dist2(Tmp[i], Tmp[j]);

            if(dd > d1)dd = d1;

        }

    return dd;

}



int main()

{

    f >> N;

    for(int i = 1; i <= N; i++)

        f >> Px[i].x >> Px[i].y;

    sort(Px + 1, Px + N + 1, compx);

    g << fixed << setprecision(6) << sqrt(calcDmin(1, N));

    return 0;

}
