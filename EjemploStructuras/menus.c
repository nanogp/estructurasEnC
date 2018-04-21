#include <stdio.h>
#include "estructuras.h"
#include "funciones_generales.h"

void mostrarMenu(const eMenu menu)
{
    int i;
    for(i=0 ; i < menu.cantOpciones ; i++)
    {
        printf("\n%s", menu.descripciones[i]);
    }
    printf("\n");
}

int pedirOpcion(const eMenu menu)
{
    int retorno;
    int i;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    mostrarMenu(menu);
    printf("\nElija un n�mero de opci�n del men�: ");
    scanf("%d", &retorno);

//printf("menu.cantOpciones %d",menu.codigos[4]);

    while(buscarEnArrayInt(retorno, menu.codigos, menu.cantOpciones) == -1)
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        mostrarMenu(menu);
        //armo lista de opciones en el rengl�n por si el usuario se equivoca muchas veces
        //y el men� queda fuera de vista
        for(i = 0 ; i < menu.cantOpciones ; i++)
        {
            if(i == 0)
            {
                printf("\nOpci�n %d no v�lida.\nElija una opci�n de men� de la lista\n(%d", retorno, menu.codigos[i]);
            }
            else
            {
                if(i < (menu.cantOpciones)-1)
                {
                    printf("-%d", menu.codigos[i]);
                }
                else
                {
                    printf("-%d): ", menu.codigos[i]);
                }
            }
        }//for
        fflush(stdin);
        scanf("%d", &retorno);
    }

    return retorno;
}
