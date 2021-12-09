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
    int todoOk=0;
    LinkedList* listaFiltrada3=NULL;
    LinkedList* listaFiltrada4_7=NULL;
    LinkedList* listaFiltrada7=NULL;

    if(lista!=NULL)
    {
        listaFiltrada3=ll_filter(lista,filtrarPorGravedad3);
        if(listaFiltrada3!=NULL)
        {
            if(ll_isEmpty(listaFiltrada3))
            {
                printf("lista vacia");
            }
            printf("LISTA GRVAEDAD 3\n");
            controller_listar(listaFiltrada3);
            controller_saveAsText("warnings.txt",listaFiltrada3);
            todoOk=1;
        }
        listaFiltrada4_7=ll_filter(lista,filtrarPorGravedad4_7);
        if(listaFiltrada4_7!=NULL)
        {
            printf("LISTA GRVAEDAD 4 y 7 inclusive\n");
            printf("Fecha Hora Nombre servicio Mensaje de error Gravedad\n");
            controller_listar(listaFiltrada4_7);
        }
        listaFiltrada7=ll_filter(lista,filtrarPorGravedad7);
        if(listaFiltrada7!=NULL)
        {
            printf("LISTA GRAVEDAD 7\n");
            mostrarLista(listaFiltrada7);
            controller_saveAsText("errors.txt",listaFiltrada7);
        }
    }
    return todoOk;

}
