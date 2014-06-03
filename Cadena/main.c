#include <stdio.h>
#include <stdlib.h>

#define TAM 10

char * rotarCadena(char *, int);
int str_len(char *);

int main()
{
    int numero, der_izq;
    char cadena[TAM+1];
    printf("Ingrese la cadena de 10 caracteres: ");
    gets(cadena);
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);
    printf("Cadena girada: %s", rotarCadena(cadena, numero));
    return 0;
}

char * rotarCadena(char * cad, int n)
{
    char * inicio = cad;
    char aux;
    int i;
    int len=str_len(cad);
    if(len==0)
        return inicio;
    if((n%2)==0)
    {
        // Es par, gira a la derecha
        for(i=0;i<(n%len);i++)
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
        // Es impar, gira a la izquierda
        for(i=0;i<(n%len);i++)
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

int str_len(char * c)
{
    int i = 0;
    while(*c)
    {
        i++;
        c++;
    }
    return i;
}
