#include <fstream>
#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

int N, M;

vector<int> parent, tree_size;





struct comp

{

    inline bool operator()(const pair<int, pii> &edge1, const pair<int, pii> &edge2)

    {

        return edge1.first > edge2.first;

    }

};

priority_queue<pair<int, pii>, vector<pair<int, pii>>, comp> adj;





void make_set(const int &vertex)

{

    parent[vertex] = vertex;

    tree_size[vertex] = 1;

}





int find_leader(const int &vertex)

{

    if (parent[vertex] == vertex)

    {

        return vertex;

    }



    return parent[vertex] = find_leader(parent[vertex]);

}





void unite_sets(int &set1, int &set2)

{

    set1 = find_leader(set1);

    set2 = find_leader(set2);



    if (set1 != set2)

    {

        if (tree_size[set1] < tree_size[set2])

        {

            swap(set1, set2);

        }



        tree_size[set1] += tree_size[set2];

        parent[set2] = set1;

    }

}





void Kruskal()

{

    vector<pii> MST_edges;

    int total_weight = 0;



    for (int node = 1; node <= N; ++node)

    {

        make_set(node);

    }



    for (int i = 1; i < N; ++i)

    {

        int CC1, CC2, leader1, leader2;



        do

        {

            CC1 = adj.top().second.first;

            CC2 = adj.top().second.second;

            leader1 = find_leader(CC1);

            leader2 = find_leader(CC2);

            adj.pop();

        } while (leader1 == leader2);



        total_weight += adj.top().first;

        MST_edges.push_back({CC1, CC2});

        unite_sets(leader1, leader2);

    }



    ofstream fout("apm.out");



    fout << total_weight << "\n" << N - 1 << "\n";

    for (const pii &MST_edge : MST_edges)

    {

        fout << MST_edge.first << " " << MST_edge.second << "\n";

    }

}





int main()

{

    ifstream fin("apm.in");



    fin >> N >> M;

    parent.resize(N + 1);

    tree_size.resize(N + 1);



    while (M--)

    {

        int i, j, weight;

        fin >> i >> j >> weight;



        adj.push({weight, {i, j}});

        adj.push({weight, {j, i}});

    }



    Kruskal();

}
