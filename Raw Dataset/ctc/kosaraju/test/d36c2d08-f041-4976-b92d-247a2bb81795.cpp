#include <bits/stdc++.h>


using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

int n,m,x,y,vis[100005],k,ans,st[100005];

vector<int> v[100005],vt[100005],comp[100005];

void dfs(int nod)

{

    vis[nod]=1;

    for(auto it:v[nod])

        if(vis[it]==0) dfs(it);

    st[++k]=nod;

}

void dfst(int nod)

{

    vis[nod]=1;

    comp[ans].push_back(nod);

    for(auto it:vt[nod])

        if(vis[it]==0) dfst(it);

}

int main()

{

    in>>n>>m;

    for(int i=1;i<=m;i++)

    {

        in>>x>>y;

        v[x].push_back(y);

        vt[y].push_back(x);

    }

    for(int i=1;i<=n;i++)

        if(vis[i]==0) dfs(i);

    memset(vis,0,sizeof(vis));

    while(k>0)

    {

        ans++;

        dfst(st[k]);

        while(vis[st[k]]==1&&k>0) {

            k--;

        }

    }

    out<<ans<<'\n';

    for(int i=1;i<=ans;i++)

    {

        for(auto it:comp[i]) out<<it<<" ";

        out<<'\n';

    }

    return 0;

}
