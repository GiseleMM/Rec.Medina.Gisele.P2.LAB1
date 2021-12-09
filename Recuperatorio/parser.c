#include "parser.h"


//PARSER

int parser_logFromText(FILE* pFile,LinkedList* lista)
{
    int todoOk=0;
    char buffer[5][50];
    LogEntry* auxlog=NULL;
    int cant;
    int contador=0;
    if(pFile!=NULL && lista!=NULL)
    {
        fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
               buffer[0],
               buffer[1],
               buffer[2],
               buffer[3],
               buffer[4]
              );
        printf("%s -%s -%s -%s  -%s\n",buffer[0],buffer[1],
               buffer[2],buffer[3],buffer[4]);
        do
        {

            cant=    fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
                            buffer[0],
                            buffer[1],
                            buffer[2],
                            buffer[3],
                            buffer[4]
                           );
            if(cant<5)
            {
                break;
            }
            auxlog=log_newParam(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(auxlog!=NULL)
            {
                mostrar(auxlog);
                ll_add(lista,auxlog);
                contador++;
                todoOk=1;
                auxlog=NULL;

            }

        }
        while(!feof(pFile));
        todoOk=1;
    }
    printf("\nse cargaron %d elementos a la lista\n", contador);
    return todoOk;
}
