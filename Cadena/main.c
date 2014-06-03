#include <stdio.h>
#include <stdlib.h>

#define TAM 10

char * rotarCadena(const char * cad, int n);

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

char * rotarCadena(const char * cad, int n)
{

}
