/******************************************************************************
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *****************************************************************************/


#ifndef CALLIB_H
#    define CALLIB_H

// === Libraries and header files ===

// === Constants and Macro definitions ===

// === Enumerations, structures and typedefs ===

// === Global variables ===

// === ROM Constant variables ===

// === Global function definitions ===
typedef int (*pCallback) (char*, char*, void*);
int parseCmdLine(int argc, char* argv[], pCallback(p), void* userData);
int parseCallback(char *key,char *value,void *userData);


typedef struct{
    
    char *key;
    char *value;
    
}args_t;                    //estructuras donde se van a guardar los resultados validos

#endif /* CALLIB_H */
