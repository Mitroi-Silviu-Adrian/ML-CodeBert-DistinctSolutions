#include <fstream>






using namespace std;



struct arbore

{

    char tip;

    int val;

    char op;

    arbore *st, *dr;

};



char St_Op[100001];

arbore* St_Nod[100001];

int idx_expr = 0, idx_op = -1, idx_nod = -1;



int prioritate(char a, char b)

{

    if(a == '*' || a == '/')

        if(b == '+' || b == '-')

            return 0;

    return 1;

}



void adaugare_nod()

{

    arbore* nod = new arbore;

    nod->tip = 'O';

    nod->op = St_Op[idx_op--];

    nod->dr = St_Nod[idx_nod--];

    nod->st = St_Nod[idx_nod--];



    St_Nod[++idx_nod] = nod;

}



arbore* Formare(char* expr)

{

    while(expr[idx_expr] != '\0')

    {

        if(expr[idx_expr] == '(')

        {

            St_Op[++idx_op] = '(';

            idx_expr++;

        }

        if(expr[idx_expr] == ')')

        {

            while(St_Op[idx_op] != '(')

            {

                if(St_Op[idx_op - 1] != '(' && prioritate(St_Op[idx_op], St_Op[idx_op - 1]))

                {

                    idx_op--;

                    idx_nod--;

                    adaugare_nod();



                    idx_nod++;

                    St_Nod[idx_nod] = St_Nod[idx_nod + 1];



                    idx_op++;

                    St_Op[idx_op] = St_Op[idx_op + 1];

                }

                else

                    adaugare_nod();

            }

            idx_op--;

            idx_expr++;

        }

        else if(expr[idx_expr] < '0')

        {

            while( idx_op > -1 && St_Op[idx_op] != '(' && prioritate(expr[idx_expr], St_Op[idx_op]))

                adaugare_nod();

            St_Op[++idx_op] = expr[idx_expr];

            idx_expr++;

        }

        else

        {

            int NR = 0;

            while(expr[idx_expr] >= '0' && expr[idx_expr] <= '9')

            {

                NR = NR * 10 + (expr[idx_expr] - '0');

                idx_expr++;

            }

            arbore* nod = new arbore;

            nod->tip = 'V';

            nod->val = NR;

            nod->st = NULL;

            nod->dr = NULL;

            St_Nod[++idx_nod] = nod;

        }

    }



    while(idx_op > 0)

    {

        if(prioritate(St_Op[idx_op], St_Op[idx_op - 1]))

        {

            idx_op--;

            idx_nod--;

            adaugare_nod();



            idx_nod++;

            St_Nod[idx_nod] = St_Nod[idx_nod + 1];



            idx_op++;

            St_Op[idx_op] = St_Op[idx_op + 1];

        }

        else

            adaugare_nod();

    }

    if(idx_op == 0)

        adaugare_nod();

    return St_Nod[0];

}



int Eval(arbore* nod)

{

    if(nod->tip == 'V')

        return nod->val;

    else

    {

        int STANGA = Eval(nod->st);

        int DREAPTA = Eval(nod->dr);

        switch (nod->op)

        {

        case '+':

            return STANGA + DREAPTA;

            break;

        case '-':

            return STANGA - DREAPTA;

            break;

        case '*':

            return STANGA * DREAPTA;

            break;

        case '/':

            return STANGA / DREAPTA;

            break;

        }

        return 0;

    }

}



int main()

{

    ifstream f("evaluare.in");

    char EXPR[100001];



    f.getline(EXPR, 100001 + 1);

    arbore* TREE = Formare(EXPR);



    ofstream g("evaluare.out");

    g<<Eval(TREE);

    return 0;

}
