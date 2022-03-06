#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char sir[2000005], pattern[2000005];

int prefix[2000005] , rez[1005];



int main() {



    int lsir = 0, lpattern = 0, i = 0, j = 0, n = 0;

    fin>>pattern>>sir;



    lsir = strlen(sir);

    lpattern = strlen(pattern);



    for(i = lsir; i >= 1; --i)

        sir[i] = sir[i-1];

    for(i = lpattern; i >= 1; --i)

        pattern[i] = pattern[i-1];



    for(i = 2; i <= lpattern; ++i) {

        while(j && pattern[j + 1] != pattern[i])

            j = prefix[j];

        if(pattern[i] == pattern[j+1])

            ++j;

        prefix[i] = j;

    }



    j = 0;

    for(i = 1; i <= lsir; ++i) {

        while(j && sir[i] != pattern[j+1])

            j = prefix[j];

        if(sir[i] == pattern[j+1])

            ++j;

        if(j == lpattern) {

            j = prefix[lpattern];

            ++n;

            if(n<=1000)

                rez[n]=i-lpattern;

        }

    }

    fout<<n<<"\n";

    n = (n < 1000 ? n : 1000);

    for(i = 1; i <= n; ++i)

        fout<<rez[i]<<" ";

    fout<<"\n";

}
