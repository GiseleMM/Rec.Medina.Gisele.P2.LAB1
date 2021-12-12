#include "controller.h"


int controller_loadFromText(char* path, LinkedList* lista)
{
    FILE* pFile=NULL;
    int todoOk=0;
    if(path!=NULL && lista!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            if(parser_logFromText(pFile,lista))
            {
                printf("Se cargo con exito archivo de texto a lista\n");
                todoOk=1;
            }
            fclose(pFile);
        }
        else
        {
            printf("Error, no se pudo abrir archivo\n");
        }
    }
    return todoOk=1;
}
int controller_listar(LinkedList* lista)
{
    int todoOk=0;
    if(lista!=NULL)
    {
        if(mostrarLista(lista))
        {
            todoOk=1;
        }
    }
    return todoOk;
}
int controller_saveAsText(char* path, LinkedList* lista)
{
    int todoOk=0;
   // char confirma[3];
    int tam;
    //campos

    char date[30];
    char time[30];
    char service[30];
    int gravedad;
    char msg[30];

   LogEntry* auxLog=NULL;

    int contador=0;
    FILE* pFile=NULL;

            pFile=fopen(path,"w");
            if(pFile!=NULL)
            {
                tam=ll_len(lista);
                fprintf(pFile, "date,time,serviceName,gravedad,msg\n");
                for(int i=0;i<tam;i++)
                {
                    auxLog=(LogEntry*)ll_get(lista,i);
                    if(auxLog!=NULL)
                    {
                        //printf("%d\n",log_getId(auxLog,&id));
                         //  printf("%d\n",log_getNombre(auxLog,nombre));
                         //  printf("%d\n",log_getAutor(auxLog,autor));
                          // printf("%d\n",log_getPrecio(auxLog,&precio));
                          // printf("%d\n",log_getIdEditorial(auxLog,&idEditorial));
                          // printf("%d\n",log_getIdEditorialCompleto(auxLog,editorial));
                        if(log_getDate(auxLog,date)&&
                           log_getTime(auxLog,time)&&
                           log_getService(auxLog,service)&&
                           log_getGravedad(auxLog,&gravedad)&&
                           log_getMsg(auxLog,msg))
                        {
                            printf("%s,%s,%s,%d,%s\n",date,time,service,gravedad,msg);
                          fprintf(pFile,"%s;%s;%s;%d;%s\n",date,time,service,gravedad,msg);
                           contador++;
                           todoOk=1;
                        }
                    }
                }
            }
            else
            {
                printf("No se pudo abrir archivo\n");
            }


    printf("se cargaron %d elementos en archivo\n",contador);
    return todoOk;
}
int controller_procesar(LinkedList* lista)
{
    system("cls");
    //Si la gravedad es 3, se deberán copiar los mensajes en el archivo warnings.txt
    //Si la gravedad tiene un valor entre 4 y 7 (inclusive) se imprimirán por pantalla
    //Si la gravedad es mayor a 7, se copiarán los mensajes en el archivo errors.txt
    int todoOk=0;
    char pathGravedad3[]="warnings.txt";
    char pathGravedad7[]=" errors.txt";
    LinkedList* listaFiltrada3=NULL;
    LinkedList* listaFiltrada4_7=NULL;
    LinkedList* listaFiltrada7=NULL;
    int flagGravedad3=0;
    int flagGravedad4y7=0;
    int flagGravedad7=0;


    if(lista!=NULL)
    {
/*FILTRO GRAVEDAD 3*/
        listaFiltrada3=ll_filter(lista,filtrarPorGravedad3);
        if(listaFiltrada3!=NULL)
        {
            if(ll_isEmpty(listaFiltrada3))
            {
                printf("Lista de gravedad 3 vacia");
            }
            else
            {
                 printf("\n ***LISTA GRAVEDAD 3***\n\n");
                if(controller_saveAsText(pathGravedad3,listaFiltrada3))
                {

                    //controller_listar(listaFiltrada3);
                    printf("\nLista guardada en archivo: %s ",pathGravedad3);
                    flagGravedad3=1;
                }

            }

        }
system("pause");
system("cls");
 /* FILTRO GRAVEDAD 4y7 */
        listaFiltrada4_7=ll_filter(lista,filtrarPorGravedad4_7);
        if(listaFiltrada4_7!=NULL)
        {
            if(ll_isEmpty(listaFiltrada4_7))
            {
                printf("Lista de gravedad 4 y 7 vacia\n");
            }
            else
            {
                printf("\n  *****LISTA GRAVEDAD ENTRE 4 y 7(inclusive)*****\n\n");
               // printf("Fecha| Hora |Nombre servicio |Gravedad |Mensaje de error\n");
               //ya esta en listar el encabezado
                controller_listar(listaFiltrada4_7);
                flagGravedad4y7=1;
            }

        }
system("pause");
system("cls");
 /*FILTRO GRAVEDAD 7*/
        listaFiltrada7=ll_filter(lista,filtrarPorGravedad7);
        if(listaFiltrada7!=NULL)
        {
            if(ll_isEmpty(listaFiltrada7))
            {
                printf("lista de gravedad 7 vacia\n");
            }
            else
            {
                printf("\n  ***LISTA GRAVEDAD 7***\n\n");//lo coloco adelante de save por que save muestra semi lista
                if(controller_saveAsText(pathGravedad7,listaFiltrada7))
                {

                    //mostrarLista(listaFiltrada7);
                    printf("\nLista guardada en archivo %s",pathGravedad7);
                    flagGravedad7=1;
                }


            }

        }
    }
    if(flagGravedad3 && flagGravedad4y7 && flagGravedad7)/*se proceso correctamente la informacion*/
    {
        todoOk=1;
    }
    return todoOk;

}
int controller_estadistica(LinkedList* lista)
{
    /*3.
    Mostrar estadísticas
Deberá indicar por pantalla la cantidad de fallos para los siguientes valores de
gravedad:
• Menores a 3
• 3
• 4 y 7 (inclusive)
• Mayores a 7

    */
    system("cls");
    int todoOk=0;
    int tamGravedadMenorA3;
    int tamGravedad3;
    int tamGravedad4y7;
    int tamGravedad7;
    int flagGravMenorA3=0;
    int flagGrav3=0;
    int flagGrav4y7=0;
    int flagGrav7=0;
    LinkedList* listaAux=NULL;
    printf("***Estadistica****\n");

 //GRAVEDAD MENOR A 3
    listaAux=ll_filter(lista,filtrarPorGravedadMenorA3);
    if(listaAux!=NULL)
    {
        tamGravedadMenorA3=ll_len(listaAux);
        printf("Cantidad de fallos para los valores de gravedad menor a 3:     %d\n",tamGravedadMenorA3);
        ll_clear(listaAux);
        flagGravMenorA3=1;

    }

//GRAVEDAD 3
    listaAux=ll_filter(lista,filtrarPorGravedad3);
    if(listaAux!=NULL)
    {
        tamGravedad3=ll_len(listaAux);
        printf("Cantidad de fallos para los valores de gravedad 3:             %d\n",tamGravedad3);
        ll_clear(listaAux);
        flagGrav3=1;

    }

//GRAVEDAD 4y7
    listaAux=ll_filter(lista,filtrarPorGravedad4_7);
    if(listaAux!=NULL)
    {
        tamGravedad4y7=ll_len(listaAux);
        printf("Cantidad de fallos para los valores de gravedad entre 4 y 7:   %d\n",tamGravedad4y7);
        ll_clear(listaAux);
        flagGrav4y7=1;
    }


 //GRAVEDAD 7
    listaAux=ll_filter(lista,filtrarPorGravedad7);
    if(listaAux!=NULL)
    {
        tamGravedad7=ll_len(listaAux);
        printf("Cantidad de fallos para los valores de gravedad mayor a 7:     %d\n",tamGravedad7);
        ll_clear(listaAux);
        flagGrav7=1;
    }

    if(flagGravMenorA3 && flagGrav3 && flagGrav4y7 && flagGrav7)
    {
        todoOk=1;
    }
    return todoOk;

}
