#include"ListasSimples.h"
#include"DependenciasComunes.h"

void menuListasSimples() 
{
	short userOption = 0;
	struct lista* pLista = NULL;
	struct lista* pRes = NULL;
	while (userOption != 12) 
	{
		LIMPIAR_CONSOLA
		printf("\n");
		centrado("*************************");
		centrado("* TDA: Listas simples *");
		centrado("*************************");
		printf("\n");
		printf("\n\t 1.-Insertar por cabeza");
		printf("\n\t 2.-Insertar por fondo");
		printf("\n\t 3.-Buscar un elemento");
		printf("\n\t 4.-Borrar un elemento");
		printf("\n\t 5.-Imprimir la lista");
		printf("\n\t 0.-Borrar toda la lista");
		printf("\n\t 12.-Volver al menu principal");
		switch (userOption = pedir_Short(TERMINAL_OPCION)) 
		{
		case 1: // Insertar por cabeza
			insertarPorInicioListaSimple(&pLista);
			break;
		case 2: // Insertar por fondo
			insertarPorFondoListaSimple(&pLista);
			break;
		case 3: // Buscar un elemento
			pRes = buscarElementoListaSimple(pLista, pedir_Short("Introduce el numero a buscar"));
			if (pRes)
				printf("Se encontro el valor con la direccion de memoria: %p", pRes);
			else
				printf("No se encontro el valor o la lista esta vacia");
			break;
		case 4: // Borrar un elemento
			borrarElementoListaSimple(&pLista, pedir_Short("Introduce el numero a borrar:"));
			break;
		case 5: // Imprimir lista
			imprimirListaSimple(pLista);
			break;
		case 0: // Borrar toda la lista
			borrarListaSimpleCompleta(&pLista);
			break;
		case 12:
			borrarListaSimpleCompleta(&pLista);
			return;
			break;
		default:
			mostrarError(OPCION_NO_VALIDA);
			PAUSA;
			break;
		}
	}
}

/*##############################################################################################################################
									TDA -> Funciones
##############################################################################################################################*/

/*  El utilizar una funci�n para crear las listas nos evita errores por no inicializarlas correctamete, 
	esto suele pasar muy frecuentemente y generalmente nos damos cuenta cuando buscamos o insertamos*/
struct lista* crearListaSimple(int valor) 
{
	struct lista* pLista = new struct lista;
	pLista->valor = valor;
	pLista->siguiente = NULL;
	return pLista;
}

void insertarPorInicioListaSimple(struct lista** ppLista)
{
	struct lista* pLista = NULL;
	pLista = crearListaSimple(pedir_Int("Ingrese el valor"));
	pLista->siguiente = *ppLista;
	*ppLista = pLista;
}

void insertarPorFondoListaSimple(struct lista** ppLista) 
{
	struct lista* pNueva = crearListaSimple(pedir_Int("Ingrese el valor"));
	if (*ppLista)
	{
		struct lista* pLista = *ppLista;
		for (; pLista->siguiente; pLista = pLista->siguiente);
		pLista->siguiente = pNueva;
	}
	else
		*ppLista = pNueva;
}

struct lista* buscarElementoListaSimple(struct lista *pLista, int valor) 
{
	for (; pLista && pLista->valor != valor; pLista = pLista->siguiente);
	return pLista;
}

void borrarElementoListaSimple(struct lista **ppLista, int valor)
{
	struct lista* pAux = NULL;
	if(*ppLista)
		if ((*ppLista)->valor == valor)
		{
			pAux = *ppLista;
			*ppLista = (*ppLista)->siguiente;
			free(pAux);
		}
		else
		{
			struct lista* pLista = *ppLista;
			for(; pLista && pLista->siguiente; pLista = pLista->siguiente)
				if (pLista->siguiente->valor == valor) 
				{
					pAux = pLista->siguiente;
					pLista->siguiente = pAux->siguiente;
					free(pAux);
				}
		}
}

void imprimirListaSimple(struct lista* pLista) 
{
	LIMPIAR_CONSOLA
	printf("\n\tLista simple: ");
	for (; pLista; pLista = pLista->siguiente)
		printf("[%3d]->", pLista->valor);
	printf("NULL\n\n");
	PAUSA;
}

void borrarListaSimpleCompleta(struct lista **ppLista)
{
	if (*ppLista) 
	{
		borrarListaSimpleCompleta(&(*ppLista)->siguiente);
		free((*ppLista));
		(*ppLista) = NULL;
	}
}

