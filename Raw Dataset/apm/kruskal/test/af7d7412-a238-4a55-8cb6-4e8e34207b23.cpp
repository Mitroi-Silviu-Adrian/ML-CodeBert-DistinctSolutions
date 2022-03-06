#include <iostream>
#include<stdio.h>
#include <fstream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");
int father[100005], group[100005], n, m, answer;

vector< pair<int, pair<int, int> > > edges;

vector< pair<int, int> > apm;



int findFather(int node)

{

    if(node == father[node])

    {

        return node;

    }

    int new_father = findFather(father[node]);

    father[node] = new_father;

    return new_father;

}



int main ()

{

    int a, b, cost;

    f >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        f >> a >> b >> cost;

        edges.push_back(make_pair(cost, make_pair(a, b)));

    }

    sort(edges.begin(), edges.end());



    for(int i = 1; i <= n; i++)

        {

        father[i] = i;

        group[i] = 1;

    }



    for(auto edge : edges)

    {

        int a = edge.second.first;

        int b = edge.second.second;



        int fa = findFather(a);

        int fb = findFather(b);



        if(fa == fb)

        {

            continue;

        }



        apm.push_back(edge.second);

        answer += edge.first;



        if(group[fa] > group[fb])

        {

            father[fb] = fa;

            group[fa] += group[fb];

        }

        else

        {

            father[fa] = fb;

            group[fb] += group[fa];

        }

    }



    g << answer << "\n" << n - 1 << "\n";

    for(auto edge : apm)

    {

        g << edge.first << " " << edge.second << "\n";

    }



    return 0;

}
