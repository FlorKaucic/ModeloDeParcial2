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
    printf("Ingresar posicion del vertice de la forma i,j: ");
    scanf("%d,%d",&i,&j);
    int * subm = mayorSubMatriz(m, COL, FIL, i, j, &cantF, &cantC);
    printf("\n\nMatriz resultante:");
    mostrarSubMatriz(subm, cantF, cantC);
    printf("\n\n");
    return 0;
}

int * mayorSubMatriz(int m[][COL], int col, int fil, int i, int j, int * cantF, int * cantC)
{
    int col1, col2, fil1, fil2;

    col1 = j+1;
    col2 = col-j;
    fil1 = i+1;
    fil2 = fil-i;

    //printf("\nTam1: %d\nTam2: %d\nTam3: %d\nTam4: %d", fil1 * col1, fil1 * col2, fil2 * col1, fil2 * col2);

    if(fil1 * col1>fil1 * col2)
        if(fil1 * col1>fil2 * col1)
            if(fil1 * col1>fil2 * col2)
            {
                //printf("\n\nTAM1");
                *cantF = fil1;
                *cantC = col1;
                return crearSubMatriz(m, fil1 * col1, 0, i, 0, j);
            }
            else
            {
                //printf("\n\nTAM4");
                *cantF = fil2;
                *cantC = col2;
                return crearSubMatriz(m, fil2 * col2, i, fil-1, j, col-1);
            }
        else
            if(fil2 * col1>fil2 * col2)
            {
                //printf("\n\nTAM3");
                *cantF = fil2;
                *cantC = col1;
                return crearSubMatriz(m, fil2 * col1, i, fil-1, 0, j);
            }
            else
            {
                //printf("\n\nTAM4");
                *cantF = fil2;
                *cantC = col2;
                return crearSubMatriz(m, fil2 * col2, i, fil-1, j, col-1);
            }
    else
        if(fil1 * col2>fil2 * col1)
            if(fil1 * col2>fil2 * col2)
            {
                //printf("\n\nTAM2");
                *cantF = fil1;
                *cantC = col2;
                return crearSubMatriz(m, fil1 * col2, 0, i, j, col-1);
            }
            else
            {
                //printf("\n\nTAM4");
                *cantF = fil2;
                *cantC = col2;
                return crearSubMatriz(m, fil2 * col2, i, fil-1, j, col-1);
            }
        else
            if(fil2 * col1>fil2 * col2)
            {
                //printf("\n\nTAM3");
                *cantF = fil2;
                *cantC = col1;
                return crearSubMatriz(m, fil2 * col1, i, fil-1, 0, j);
            }
            else
            {
                //printf("\n\nTAM4");
                *cantF = fil2;
                *cantC = col2;
                return crearSubMatriz(m, fil2 * col2, i, fil-1, j, col-1);
            }
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
