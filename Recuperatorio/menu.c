#include "menu.h"


int menu()
{
    int opcion;
    system("cls");
    printf("\n**********LOG-ENTRY ********\n");
    printf("1- leeer archivo\n");
    printf("2- Procesar información\n");
    printf("3-mostrar estadistica \n");
    printf("4-Imprimir lista logs \n");
    printf("5-salir  \n");
    printf("Eliga opcion: \n");
    fflush(stdin);
    while(!scanf("%d",&opcion))
    {
        fflush(stdin);
        printf("Error, Reingrese opcion: ");
    }
    return opcion;
}
