#include<fstream>
#include<cmath>
#include<vector>
#include<queue>




using namespace std;

int n,m,nr[1510];

struct Muchie{int x,y;double cost;};

Muchie M[2510];

vector <int> G[1510];

double dist[1510];

bool viz[1510];



void Citire()

{

 int i;

 ifstream fin("dmin.in");

 fin>>n>>m;

 for(i=1;i<=m;i++)

 {

  fin>>M[i].x>>M[i].y>>M[i].cost;

  M[i].cost=log(M[i].cost);

  G[M[i].x].push_back(i);

  G[M[i].y].push_back(i);

 }

 fin.close();

}



void Bellman_Ford()

{

 queue <int> Q;

 vector <int>::iterator it;

 int i,x,y;

 for(i=2;i<=n;i++)

  dist[i]=2000000000.0;

 nr[1]=1;

 viz[1]=true;

 Q.push(1);

 while(!Q.empty())

 {

  x=Q.front();

  Q.pop();

  viz[x]=false;

  for(it=G[x].begin();it!=G[x].end();it++)

  {

   y=M[*it].x+M[*it].y-x;

   if(0.000001<dist[y]-dist[x]-M[*it].cost)

   {

    dist[y]=dist[x]+M[*it].cost;

    nr[y]=nr[x];

    if(!viz[y])

    {

     viz[y]=true;

     Q.push(y);

    }

   }

   else

    if(dist[x]+M[*it].cost-dist[y]<=0.000001)

    {

     nr[y]+=nr[x];

     if(nr[y]>=104659)

      nr[y]-=104659;

    }

  }

 }

}



void Afisare()

{

 int i;

 ofstream fout("dmin.out");

 for(i=2;i<=n;i++)

  fout<<nr[i]<<' ';

 fout<<"\n";

 fout.close();

}



int main()

{

 Citire();

 Bellman_Ford();

 Afisare();

 return 0;

}
