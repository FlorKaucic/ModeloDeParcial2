#include <stdio.h>
#include <stdlib.h>

#define TAM 10

char * rotarCadena(char *, int, int);

int main()
{
    int numero, der_izq;
    char cadena[TAM+1];
    printf("Ingrese la cadena de 10 caracteres: ");
    gets(cadena);
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);
    printf("\n\nCadena girada: \"%s\"", rotarCadena(cadena, sizeof(cadena)/sizeof(char)-1,numero));
    return 0;
}

char * rotarCadena(char * cad, int len, int n)
{
    char aux, * inicio = cad;
    int dir, i;
    if(len==0)
        return inicio;

    if((n%2)==0)
        dir = 1;
    else
        dir = 0;

    if(n<0)
    {
        dir = !dir;
        n = -n;
    }

    n = n%len;

    if(n>(len/2))
    {
        dir = !dir;
        n = len-n;
    }

    if(dir) // dir = 1 => derecha // dir = 0 => izquierda
    {
        // Gira a la derecha
        printf("\nGira a la derecha %d posiciones",n);
        for(i=0;i<n;i++)
        {
            cad = inicio + len - 1;
            aux = *cad;
            while(cad != inicio)
            {
                *cad = *(cad-1);
                cad--;
            }
            *cad = aux;
        }
    }
    else
    {
        // Gira a la izquierda
        printf("\nGira a la izquierda %d posiciones",n);
        for(i=0;i<n;i++)
        {
            cad = inicio;
            aux = *cad;
            while(*(cad+1))
            {
                *cad = *(cad+1);
                cad++;
            }
            *cad = aux;
        }
    }
    return inicio;
}
