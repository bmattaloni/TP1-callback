/******************************************************************************
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *****************************************************************************/



// === Libraries and header files ===
#include <stdio.h>
#include <stdlib.h>

// This file
#include "callib.h"

/// @privatesection
// === Constants and Macro definitions ===

// === Enumerations, structures and typedefs ===

// === Global variables ===

// === Function prototypes for private functions with file level scope ===

// === ROM Constant variables with file level scope ===

// === Static variables and constant variables with file level scope ===


// === Global function definitions ===
/// @publicsection

/*
 Comentsrios espantosos
 Falta callback y agregar datos a memoria
 */


int parseCmdLine(int argc, char *argv[],pCallback (p), void *userData)
{
    int result=0, i,valid=1;
    char *clave;
    char *valor;
    
    for(i = 1; i < argc; i++)
    {
        if((*(argv[i]) == '-')&&(*((argv[i])+1)== '\0'))  //Error de tipo 2
        {                                          //Encontro opcion con clave vacia
            result=-EXIT_FAILURE;
            i=argc;
        }
        else if((*(argv[i]) == '-')&&( argv[i+1] == NULL)) //Error de tipo 1
        {                                        //Encontro opcion sin valor
            result=-EXIT_FAILURE;
            i=argc;
        }
        else if((*(argv[i]) == '-')&&(argv[i] != NULL)) //Encontro opcion
        {   
            clave=argv[i++];                                //Avanzo dos(este mas el del for())
            valor=argv[i];
            
            valid=p(clave+1,valor,((args_t*)userData)+result) ;   //llamo al callback y le paso el userdata donde guardar(a clave le sumo uno para que no pase el '-')
               if (!valid){                                             //al user data le sumo result para que siempre guarde en la siguiente struct
                   i=argc;
                   result=-EXIT_FAILURE;
                }                                               //si callback devuelve 0 hubo un error entonces corto
            result++;
        }
        else                                            //Encontro parametro
        {   
            valor=argv[i];
            valid=p(NULL,valor,((args_t*)userData)+result);      //lo mismo que con opciones per aplicado a parametros
            
                if (!valid){
                    i=argc;
                    result=-EXIT_FAILURE;
                }
                  
            result++;
        }
    
    }
    return result;
}




/// @privatesection
// === Local function definitions ===
