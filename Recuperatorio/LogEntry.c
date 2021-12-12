#include "LogEntry.h"



//MOSTRAR
void mostrar(LogEntry* pElement)
{
    if(pElement!=NULL)
    {
        printf("%-10s - %-5s - %-25s - %-5d - %-10s\n",pElement->date,
               pElement->time,
               pElement->serviceName,
               pElement->gravedad,
               pElement->msg

              );
    }
}
int mostrarLista(LinkedList* lista)
{
    int todoOk=0;
    LogEntry* aux=NULL;
    int tam;
    if(lista!=NULL)
    {
        tam=ll_len(lista);
        printf("Fecha |Hora|Nombre del servicioque fallo|Gravedad del error|Msg de error\n\n");
        for(int i=0; i<tam; i++)
        {
            aux=(LogEntry*)ll_get(lista,i);
            if(aux!=NULL)
            {
                mostrar(aux);
            }
        }
        if(tam==0)
        {
            printf("Lista vacia\n");
        }
        printf("\n\n");
        todoOk=1;

    }
    return todoOk;
}
//CONTRUCTORES
LogEntry* log_new()
{
    LogEntry* nueva=NULL;
    nueva=(LogEntry*)malloc(sizeof(LogEntry));
    if(nueva!=NULL)
    {

        strcpy(nueva->date," ");
        strcpy(nueva->time," ");
        strcpy(nueva->serviceName," ");
        nueva->gravedad=0;
        strcpy(nueva->msg," ");
    }
    return nueva;
}
LogEntry* log_newParam(char* date,char* time, char* service, char* gravedad, char* msg)
{
    LogEntry* nueva=NULL;
    if(date!=NULL && time!=NULL && service!=NULL && gravedad!=NULL && msg!=NULL)
    {
        nueva=log_new();
        if(nueva!=NULL)
        {

            strcpy(nueva->date,date);
            strcpy(nueva->time,time);
            strcpy(nueva->serviceName,service);
            nueva->gravedad=atoi(gravedad);
            strcpy(nueva->msg,msg);
        }

    }
    return nueva;
}

///SETTERS
int log_setDate(LogEntry* pElement,char* date)
{
    int todoOk=0;
    if(pElement!=NULL && date!=NULL)
    {
        strcpy(pElement->date,date);
        todoOk=1;
    }

    return todoOk;
}
int log_setTime(LogEntry* pElement,char* time)
{
    int todoOk=0;
    if(pElement!=NULL && time!=NULL)
    {
        strcpy(pElement->time,time);

        todoOk=1;
    }

    return todoOk;
}
int log_setService(LogEntry* pElement,char* service)
{
    int todoOk=0;
    if(pElement!=NULL && service!=NULL)
    {
        strcpy(pElement->serviceName,service);
        todoOk=1;
    }

    return todoOk;
}
int log_setGravedad(LogEntry* pElement, int gravedad)
{
    int todoOk=0;
    if(pElement!=NULL && gravedad>=0)
    {
        todoOk=1;
        pElement->gravedad=gravedad;
    }
    return todoOk;
}
int log_setMsg(LogEntry* pElement,char* msg)
{
    int todoOk=0;
    if(pElement!=NULL && msg!=NULL)
    {
        todoOk=1;
        strcpy(pElement->msg,msg);
    }
    return todoOk;
}
///GETTERS
int log_getDate(LogEntry* pElement,char* date)
{
    int todoOk=0;
    if(pElement!=NULL && date!=NULL)
    {
        strcpy(date,pElement->date);
        todoOk=1;
    }

    return todoOk;
}
int log_getTime(LogEntry* pElement,char* time)
{
    int todoOk=0;
    if(pElement!=NULL && time!=NULL)
    {
        strcpy(time,pElement->time);

        todoOk=1;
    }

    return todoOk;
}
int log_getService(LogEntry* pElement,char* service)
{
    int todoOk=0;
    if(pElement!=NULL && service!=NULL)
    {
        strcpy(service,pElement->serviceName);
        todoOk=1;
    }

    return todoOk;
}
int log_getGravedad(LogEntry* pElement, int* gravedad)
{
    int todoOk=0;
    if(pElement!=NULL && gravedad!=NULL)
    {
        todoOk=1;
        *gravedad=pElement->gravedad;
    }
    return todoOk;
}
int log_getMsg(LogEntry* pElement,char* msg)
{
    int todoOk=0;
    if(pElement!=NULL && msg!=NULL)
    {
        todoOk=1;
        strcpy(msg,pElement->msg);
    }
    return todoOk;
}
void log_destroy(LogEntry* pElement)
{
    if(pElement!=NULL)
    {
        free(pElement);
    }
}

//ll-FILTER-------------------------
int filtrarPorGravedad3(void* pElement)
{
    int es3=0;
    if(pElement!=NULL)
    {
        if( ((LogEntry*)pElement)->gravedad == 3)
        es3=1;
    }
    return es3;
}
int filtrarPorGravedad4_7(void* pElement)
{
    int es4=0;
    if(pElement!=NULL)
    {
        if( ((LogEntry*)pElement)->gravedad >= 4 && (((LogEntry*)pElement)->gravedad <=7))
        es4=1;
    }
    return es4;
}
int filtrarPorGravedad7(void* pElement)
{
    int es7=0;
    if(pElement!=NULL)
    {
        if( ((LogEntry*)pElement)->gravedad > 7)
        es7=1;
    }
    return es7;
}
int filtrarPorGravedadMenorA3(void* pElement)
{
    int esMenorA3=0;
    if(pElement!=NULL)
    {
        if( ((LogEntry*)pElement)->gravedad < 3)
        esMenorA3=1;
    }
    return esMenorA3;
}

