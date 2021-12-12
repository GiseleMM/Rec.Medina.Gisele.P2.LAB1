#include "menu.h"


int menu()
{
    int opcion;
    system("cls");
    printf("\n**********LOG-ENTRY ********\n");
    printf("1- Leer archivo.\n");
    printf("2- Procesar informacion.\n");
    printf("3- Mostrar estadistica.\n");
    printf("4- Imprimir lista logs.\n");
    printf("5- Salir.  \n");
    printf("Eliga opcion: \n");
    fflush(stdin);
    while(!scanf("%d",&opcion))
    {
        fflush(stdin);
        printf("Error, Reingrese opcion: ");
    }
    return opcion;
}
