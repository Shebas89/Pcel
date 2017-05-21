/*****************************************************************************
* PROGRAMA modular.c                                                         *
******************************************************************************
* PROPOSITO : Ejemplo Archivos Binarios.								     *
*                                                                            *
* AUTOR(ES) : Jaime Humberto López                                           *
* FECHA     : 24 de noviembre de 2008                                           *
* ASIGNATURA: PCEL - 8                                                       *
*****************************************************************************/
/*****************************************************************************
* ENCABEZADO DE LAS BIBLIOTECAS                                              *
*****************************************************************************/
#include <stdio.h>  /* Funciones estandar de entrada y salida */
#include <stdlib.h>

/*****************************************************************************
* CONSTANTES                                                                 *
*****************************************************************************/

#define MAX_EST             2
#define MAX_STR             30


/*****************************************************************************
* ESTRUCTURAS Y TIPOS DE DATOS                                               *
*****************************************************************************/

struct estudiante
{
        char nombre[MAX_STR];
        char carrera[MAX_STR];
        float promedio;
};

typedef struct estudiante estudiante;

/*****************************************************************************
* PROTOTIPOS DE LOS SUBPROGRAMAS                                             *
*****************************************************************************/

void pedirDatosEstudiante(estudiante *, int);
int guardarEstudiantes(estudiante [], int );
int cargarEstudiantes(estudiante [], int );
void imprimirDatosEstudiante(estudiante est, int n_est);


/*****************************************************************************
* PROGRAMA PRINCIPAL                                                         *
*****************************************************************************/

main ()
{
    system ("color F1");
    getchar();
	estudiante estudiantes[MAX_EST], e[MAX_EST];
	int i;
    if(!cargarEstudiantes(e,MAX_EST))
			printf("\nSe generaron errores al cargar del archivo");
    else
    {
        printf("\nSe cargaron satisfactoriamente los alumnos\n");
        for(i=0; i < MAX_EST;i++)
            imprimirDatosEstudiante(e[i], i+1);
    }
	for(i=0; i < MAX_EST;i++)
		pedirDatosEstudiante(&estudiantes[i], i+1);

	if(!guardarEstudiantes(estudiantes,MAX_EST))
			printf("\nLos estudiantes no se almacenaron!!");
	else
	{
		if(!cargarEstudiantes(e,MAX_EST))
			printf("\nSe generaron errores al cargar del archivo");
		else
		{
			printf("\nSe cargaron satisfactoriamente los alumnos\n");
			for(i=0; i < MAX_EST;i++)
				imprimirDatosEstudiante(e[i], i+1);
		}
	}
}


void pedirDatosEstudiante(estudiante *est, int n_est)
{

	printf("\n*** DATOS ESTUDIANTE %d ***", n_est);
	printf("\n\nNombre: ");
	gets(est->nombre);
	printf("\nCarrera: ");
	gets(est->carrera);
	printf("\nPromedio: ");
	scanf("%f%*c",&est->promedio);

}

void imprimirDatosEstudiante(estudiante est, int n_est)
{

	printf("\n\n*** DATOS ESTUDIANTE %d ***", n_est);
	printf("\n\nNombre: %s", est.nombre);
	printf("\nCarrera: %s", est.carrera);
	printf("\nPromedio: %f", est.promedio);

}

int guardarEstudiantes(estudiante est[], int n_est)
{
	FILE *fp;
	int i;

	fp = fopen("prueba.est","wb");

	if (fp != NULL)
	{
		for(i=0; i < MAX_EST;i++)
			fwrite(&est[i],sizeof(estudiante),1,fp);

		fclose(fp);
	}

	return (fp==NULL? 0:1);
}

int cargarEstudiantes(estudiante est[], int n_est)
{
	FILE *fp;
	int i, ret=1;

	fp = fopen("prueba.est","rb");

	if (fp != NULL)
	{
		for(i=0; i < MAX_EST;i++)
			if (fread(&est[i],sizeof(estudiante),1,fp) != 1)
				ret = 0;

		fclose(fp);
	}

	return (fp==NULL||ret==0? 0:1);
}
