#include <bits/stdc++.h>






using namespace std;
const int NMAX=1e5+10;



vector < int > Edge[NMAX], Components[NMAX];



int n, m, RootLevel[NMAX], NodeLevel[NMAX], niv, nrCMP;



bitset < NMAX > Seen, Belongs;



stack < int > Stack;







void Read()



{

    freopen("ctc.in", "r", stdin);

    scanf("%d%d", &n, &m);





    int x, y;



    for(int i=1; i<=m; i++)



    {



        scanf("%d%d", &x, &y);

        Edge[x].push_back(y);

    }



}







void Tarjan(int x)



{



    niv++;



    Seen[x]=1;



    Belongs[x]=1;



    Stack.push(x);



    RootLevel[x]=niv;



    NodeLevel[x]=niv;



    for(int i : Edge[x])



    {



        if(!Seen[i])



        {



            Tarjan(i);



            RootLevel[x]=min(RootLevel[x], RootLevel[i]);



        }



        else



            if(Belongs[i])



                RootLevel[x]=min(RootLevel[x], RootLevel[i]);



    }



    if(RootLevel[x]==NodeLevel[x])



    {



        nrCMP++;



        int node=0;



        do



        {



            node=Stack.top();



            Stack.pop();



            Components[nrCMP].push_back(node);



            Belongs[node]=0;



        }

        while(node!=x);



    }



}







int main()



{



    Read();



    for(int i=1; i<=n; i++)



        if(!Seen[i])



            niv=0, Tarjan(i);

    freopen("ctc.out", "w", stdout);

    printf("%d", nrCMP);

    printf("\n");





    for(int i=1; i<=nrCMP; i++)



    {



        for(int it : Components[i])

            printf("%d ", it);



            printf("\n");





    }



    return 0;







}
