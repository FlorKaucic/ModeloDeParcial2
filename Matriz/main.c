#include <stdio.h>

#define COL 6
#define FIL 4

int * mayorSubMatriz(int m[][COL], int col, int fil, int i, int j, int * cantF, int * cantC);
int * crearSubMatriz(int m[][COL], int tam, int fi, int ff, int ci, int cf);
void mostrarSubMatriz(int * m, int cantF, int cantC);

int main()
{
    int i, j, cantF, cantC;
    int m[FIL][COL]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24}};
    mostrarSubMatriz(m, FIL, COL);
    do{
        printf("\n\nIngresar posicion del vertice de la forma i,j: ");
        scanf("%d,%d",&i,&j);
    }while(i>=FIL||j>=COL);
    int * subm = mayorSubMatriz(m, COL, FIL, i, j, &cantF, &cantC);
    printf("\n\nMatriz resultante:");
    mostrarSubMatriz(subm, cantF, cantC);
    printf("\n\n");
    return 0;
}

int * mayorSubMatriz(int m[][COL], int col, int fil, int i, int j, int * cantF, int * cantC)
{
    int ci, cf, fi, ff;

    if(j+1>col-j)
    {
        ci = 0;
        cf = j;
    }
    else
    {
        ci = j;
        cf = col-1;
    }

    if(i+1>fil-i)
    {
        fi = 0;
        ff = i;
    }
    else
    {
        fi = i;
        ff = fil-1;
    }

    *cantF = ff - fi + 1;
    *cantC = cf - ci + 1;

    return crearSubMatriz(m, (*cantF)*(*cantC), fi, ff, ci, cf);
}

int * crearSubMatriz(int m[][COL], int tam, int fi, int ff, int ci, int cf)
{
    int * nueva = (int *)malloc(tam*sizeof(int));
    int * p = nueva;
    int i, j;
    for(i=fi;i<=ff;i++)
    {
        for(j=ci;j<=cf;j++)
        {
            *p = m[i][j];
            p++;
        }
    }
    return nueva;
}

void mostrarSubMatriz(int * m, int cantF, int cantC)
{
    int i, j;
    for(i=0;i<cantF;i++)
    {
        printf("\n");
        for(j=0;j<cantC;j++)
        {
            printf("%d\t", *m);
            m++;
        }
    }
}
