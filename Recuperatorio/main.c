#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include <time.h>
#include "menu.h"
#include "LogEntry.h"
#include "controller.h"
#include "parser.h"





int main()
{

    //https://github.com/GiseleMM/Rec.Medina.Gisele.P2.LAB1.git
    LinkedList* lista=ll_newLinkedList();
    if(lista==NULL)
    {
        printf("Fallo  creacion de lista\n");
        exit(1);
    }


    char path[30];
    int seguir=0;

    do
    {
        switch(menu())
        {
        case 1:
            if(ll_isEmpty(lista))
            {
                fflush(stdin);
                printf("Ingrese path(log.txt): ");
                gets(path);
                if(controller_loadFromText(path,lista))
                {
                    printf("Archivo %s cargado con exito\n",path);
                }
            }
            else
            {
                printf("Lista ya cargada en el sistema\n");
            }
            break;

        case 2:
            if(!ll_isEmpty(lista))/*no esta vacia*/
            {
                controller_procesar(lista);
            }
            else
            {
                printf("No hay elementos en la lista\n");
            }
            break;
        case 3:
            if(!ll_isEmpty(lista))/*no esta vacia*/
            {
                controller_estadistica(lista);
            }
            else
            {
                printf("No hay elementos en la lista\n");
            }
            break;
        case 4:
            if(!ll_isEmpty(lista))/*no esta vacia*/
            {
                controller_listar(lista);
            }
            else
            {
                printf("No hay elementos en la lista\n");
            }
            break;
        case 5:
            seguir=10;
            break;
        default:
            printf("Opcion invalida\n");
            break;



        }//FIN DEL SWITCH---------------------------------------
        system("pause");
    }
    while(seguir!=10);

    return 0;
}//---------------------------------------------------------------------


