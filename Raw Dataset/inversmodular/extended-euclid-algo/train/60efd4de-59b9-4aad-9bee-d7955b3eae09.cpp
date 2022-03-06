#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int Euclid(long long a, long long b, long long &x, long long &y){

    if (b == 0){

        x = 1;

        y = 0;

        return a;

    }

    else{

        long long x0, y0;

        long long d = Euclid(b, a % b, x0, y0);

        x = y0;

        y = x0 - 1LL * (a / b) * y0;

        return d;

    }

}



int main(){

    long long a, n;

    fin >> a >> n;

    long long x, y, d;

    d = Euclid(a, n, x, y);

   if (x < 0) x = n + x % n;

    fout << x;

    fin.close();

    fout.close();

    return 0;

}
