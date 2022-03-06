#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <fstream>






using namespace std;



ifstream cin("inversmodular.in"); ofstream cout("inversmodular.out");



void euclid_ext(long long a, long long b, long long& d, long long& x, long long& y) {

 if (b == 0) {

  d = a;

  x = 1; y = 0;

 }

 else {

  long long x0, y0;

  euclid_ext(b, a % b, d, x0, y0);

  x = y0;

  y = x0 - (a / b) * y0;

 }

}



int main() {



 long long a, b, d, x, y;

 cin >> a >> b;

 euclid_ext(a, b, d, x, y);

 x = (x % b + b) % b;

 cout << x;

 return 0;

}
