#ifndef LOGENTRY_H_INCLUDED
#define LOGENTRY_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include <time.h>
#include "menu.h"

typedef struct
{

    char date[11];
    char time[6];
    char serviceName[65];
    int gravedad;
    char msg[65];
} LogEntry;

#endif // LOGENTRY_H_INCLUDED
//MOSTRAR
void mostrar(LogEntry* pElement);
int mostrarLista(LinkedList* lista);
//CONTRUCTORES
LogEntry* log_new();
LogEntry* log_newParam(char* date,char* time, char* service, char* gravedad, char* msg);

///SETTERS
int log_setDate(LogEntry* pElement,char* date);
int log_setTime(LogEntry* pElement,char* time);
int log_setService(LogEntry* pElement,char* service);
int log_setGravedad(LogEntry* pElement, int gravedad);
int log_setMsg(LogEntry* pElement,char* msg);
///GETTERS
int log_getDate(LogEntry* pElement,char* date);
int log_getTime(LogEntry* pElement,char* time);
int log_getService(LogEntry* pElement,char* service);
int log_getGravedad(LogEntry* pElement, int* gravedad);
int log_getMsg(LogEntry* pElement,char* msg);
void log_destroy(LogEntry* pElement);

//llFILTER-------------------------
int filtrarPorGravedad3(void* pElement);
int filtrarPorGravedad4_7(void* pElement);
int filtrarPorGravedad7(void* pElement);
int filtrarPorGravedadMenorA3(void* pElement);
