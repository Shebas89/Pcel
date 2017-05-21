/*+**************
*  BIBLIOTECAS  *
**************+*/
#include <stdio.h>
/*+*********************************
*  PROTOTIPOS DE LOS SUBPROGRAMAS  *
*********************************+*/
void sera_impar (int num,int*resp);
main()
/*+********************
*  PROGRAMA PRINCIPAL *
********************+*/
{
    int num,resp;
    printf("HOLA.\nESTE PROGRAMA TE DICE SI UN NUMERO QUE TU INGRESASTE ES PAR O IMPAR.\n");
    printf("\nDIGITE EL VALOR QUE QUIERE QUE EVALUE:\n\n\t");
    scanf("%d%*c",&num);
    sera_impar(num,&resp);
    if(resp==1)
        printf("\nEL NUMERO DIGITADO ES IMPAR.\n");
    else if(resp==0)
        printf("\nEL NUMERO DIGITADO ES PAR.\n");
    printf("\n'GRACIAS POR UTILIZAR ESTE PROGRAMA'\n");
}
/*+***************
*  SUBPROGRAMAS  *
***************+*/
void sera_impar (int num,int*resp)
{
    if(num%2==0)
        *resp=0;
    else
        *resp=1;
}
