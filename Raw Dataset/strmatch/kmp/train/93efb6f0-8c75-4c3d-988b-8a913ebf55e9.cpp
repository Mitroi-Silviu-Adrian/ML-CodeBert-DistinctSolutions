#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>




using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char s[2000001], p[2000001];



int sol[1001], lps[2000001], cnt;



void precalculare()

{

 int len = 0;

 int lg_p = strlen(p);

 lps[0] = 0;

 int i = 1;

 while (i < lg_p) {

  if (p[i] == p[len]) {

   len++;

   lps[i] = len;

   i++;

  }

  else

  {

   if (len != 0) {

    len = lps[len - 1];

   }

   else

   {

    lps[i] = 0;

    i++;

   }

  }

 }

}



void KMP(char* p, char* s)

{

 int lg_p = strlen(p);

 int lg_s = strlen(s);

 precalculare();

 int i = 0, j = 0;

 while (i < lg_s) {

  if (s[i] == p[j])

  {

   i++;

   j++;

  }

  if (j == lg_p)

  {

   cnt++;

   if (cnt <= 1000)

    sol[cnt] = i - j;

   j = lps[j - 1];

  }

  else if (i < lg_s && s[i] != p[j])

  {

   if (j != 0)

    j = lps[j - 1];

   else

    i++;

  }

 }

}



int main()

{

 fin >> p;

 fin >> s;

 KMP(p, s);

 fout << cnt << '\n';

 for (int i = 1; i <= min(cnt,1000); i++) {

  fout << sol[i] << ' ';

 }

}
