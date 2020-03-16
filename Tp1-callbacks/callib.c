/******************************************************************************
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *****************************************************************************/

/******************************************************************************
 * 
 * @file    callib.c
 * 
 * @brief   ;
 * 
 * @details ; 
 *
 * @author  Gino Minnucci                               <gminnucci@itba.edu.ar>
 * @author  
 * @author 
 * 
 * 
 * @copyright GNU General Public License v3
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
int
parseCmdLine(int argc, char *argv[], void *userData)
{
    int result=0, i;

    for(i = 1; i < argc; i++)
    {
        if((*(argv[i]) == '-')&&(argv[i+1] == NULL))  //Error de tipo 1
        {                                          //Encontro clave sin su valor
            result=-EXIT_FAILURE;
            i=argc;
        }
        else if((*(argv[i]) == '-')&&(*((argv[i])+1) == '\0')) //Error de tipo 2
        {                                        //Encontro opcion sin su clave
            result=-EXIT_FAILURE;
            i=argc;
        }
        else if((*(argv[i]) == '-')&&(argv[i] != NULL)) //Encontro opcion
        {
            i++;        //Avanzo dos(este mas el del for())
            result++;
        }
        else                                            //Encontro parametro
        {
            result++;
        }
    
    }
    return result;
}

/// @privatesection
// === Local function definitions ===
