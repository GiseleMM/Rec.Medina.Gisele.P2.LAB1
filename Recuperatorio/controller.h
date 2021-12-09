#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include <time.h>
#include "menu.h"
#include "parser.h"
#include "LogEntry.h"

#endif // CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* lista);
int controller_listar(LinkedList* lista);
int controller_saveAsText(char* path, LinkedList* lista);
int controller_procesar(LinkedList* lista);
