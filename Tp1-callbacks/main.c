/******************************************************************************
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *****************************************************************************/

// === Libraries and header files ===
#include <stdio.h>
#include <stdlib.h>

#include "callib.h"
//#include "test.h"
#include <string.h>


/// @privatesection
// === Constants and Macro definitions ===

// === Enumerations, structures and typedefs ===

// === Global variables ===

// === Function prototypes for private functions with file level scope ===

// === ROM Constant variables with file level scope ===

// === Static variables and constant variables with file level scope ===

// === Global function definitions ===
/// @publicsection

/**
 * @brief Main
 */

int
main(int argc, char* argv [])
{   
    args_t argStruc[10];
    int cantidad;
    
    char *prueba[]={"hola","-altura","150"};
    
    cantidad=parseCmdLine(3,prueba,parseCallback,argStruc);
    
    //test();
    printf("%d\n",cantidad);
    
    printf("%s\n",argStruc[0].key);
    printf("%s",argStruc[0].value);

    return (EXIT_SUCCESS);
}

int parseCallback(char *key,char* value,void *userData){
    
    args_t * argStruc= (args_t*) userData;            //casteo la struc donde debo guardar
    int valid=1,num;
    if(key==NULL){                                  // si fue parametro lo guardo 
        
        argStruc->key = value;
        
    }
    else{
        
        if(!strcmp(key,"altura")){                  // si fue opcion verifico que sea la clave correcta
            
            argStruc->key=key;
        }
        else{
            valid=0;                                // si no fue correcta devuelvo 0
        }
        
        num=atoi(value);
        
        
        if(num<300 && valid==1){                    // verifico que el valor sea el rango que espero,sino devuelvo 0
            
            argStruc->value=value;
        }
        else{
            valid=0;
        }
    }
    printf("HECHO\n");
    return valid;
}

/// @privatesection
// === Local function definitions ===