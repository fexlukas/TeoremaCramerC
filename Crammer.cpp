#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/*
  Name: Crammer
  Copyright: 
  Author: Fernando Lucas
  Date: 24/03/13 18:55
  Description: Algoritmo que calcula Determinantes e incognitas utilizando o 
teorema de Crammer.  
*/

/*Legenda:
                a[3][4]= matriz caso o usuário escolha 3x3
                b[2][3]= matriz caso o usuário escolha 2x2
                c[4][5]= matriz caso o usuário escolha 4x4
                dg= diagonal, ou seja, para calcular uma matriz 3x3 usa-se 
      3 diagonais para cima e 3 diagonais para baixo, por isso estão numeradas 
      dg1 até dg6
                Ds= determinante do sistema
                Dx= determinante de x, e assim por diante:Dy,Dz,Dw
                op= opção, quando o usuário digita qual sistema ele quer cal-
      cular(no caso só existe 3 opções 2x2 ou 3x3 ou 4x4)
               dg1x= diagonal 1 de x
               dg2x= diagonal 2 de x 
               dg1y= diagonal 1 de y ... E assim sucessivamente até dg6z
               cont= contador
               R= resposta, utilizado quando o programa pergunta ao usuário se 
      deseja inserir outro sistema.
               Ds1 até Ds4= quando usa-se matriz 4x4 calcula-se 4 matrizes 3x3 
      para descobrir o determinante, o mesmo procedimento serve para Dx,Dz,Dw
      */

/*FUNÇÃO QUE IMPRIME UMA LINHA NA TELA*/
int linha()
{
       int j;
       for(j=1;j<=62;j++)
       printf("\xCD");
}

main()
{
      int op,R;
      int a[3][4],b[2][3],c[4][5],cont,cont1;
      int dg1, dg2, dg3, dg4, dg5, dg6;
      int dg1x, dg2x, dg3x, dg4x, dg5x, dg6x;
      int dg1y, dg2y, dg3y, dg4y, dg5y, dg6y;
      int dg1z, dg2z, dg3z, dg4z, dg5z, dg6z;
      int Ds1,Ds2,Ds3,Ds4,Dx1,Dx2,Dx3,Dx4;
      int Dy1,Dy2,Dy3,Dy4,Dz1,Dz2,Dz3,Dz4,Dw1,Dw2,Dw3,Dw4;      
      float x,y,z,w,Ds,Dx,Dy,Dz,Dw;
      
      printf("\xC9");
      linha();
      printf("\xBB\n");
      printf("\xBA....................TEOREMA DE CRAMMER........................\xBA\n");
      printf("\xBA Obs: este programa so aceita numeros inteiros!               \xBA\n");
      do{
      
      printf("\xCC");
      linha();
      printf("\xB9\n");
      printf("\xBA Menu de Opcoes                                               \xBA\n");
      printf("\xBA Digite 1 para um sistema 2x2                                 \xBA\n");
      printf("\xBA Digite 2 para um sistema 3x3                                 \xBA\n");
      printf("\xBA Digite 3 para um sistema 4x4                                 \xBA\n");
      printf("\xBA R:");
      scanf("%d",&op);
      
      switch(op)
       {
         
        case 1:
         printf("\xCC");
         linha();
         printf("\xBC\n");
         printf("\xBA Atencao digite apenas os numeros, pois as incognitas (x,y)\n");
         printf("\xBA serao adicionadas automaticamente.\n");
         
         /*LOOP PARA POPULAR A MATRIZ 2x2*/
         for(cont=1;cont<3;cont++)
         {
          printf("\xBA\n\xBA *** %d\xA6 equacao ***\n",cont);
           for(cont1=1;cont1<4;cont1++)
           {
             if(cont1==3)
              {
                printf("\xBA Informe o termo independente:");
                scanf("%d",&b[cont][3]);
               }
             else
              {
                printf("\xBA Informe o valor da %d incognita:",cont1);
                scanf("%d",&b[cont][cont1]);
              }
           }
          }
         /*DEVOLVE A MATRIZ*/
         printf("\xCC");
         linha();
         printf("\xCD\n");
         printf("\xBA O sistema que voce informou foi:\n");
         printf("\xBA %dx %dy = %d \n",b[1][1],b[1][2],b[1][3]);
         printf("\xBA %dx %dy = %d \n\xBA\n",b[2][1],b[2][2],b[2][3]);
         
         /*CALCULA O DETERMINANTE DO SISTEMA*/
         dg1=b[1][1]*b[2][2];
         dg2=b[2][1]*b[1][2]*(-1);
         Ds=dg1+dg2;
           
         /*CALCULA O DETERMINANTE DE X E DIVIDE PELO DETERMINANTE DO SISTEMA*/
         dg1x=b[1][3]*b[2][2];
         dg2x=b[2][3]*b[1][2]*(-1);
         Dx=dg1x+dg2x;
         x=Dx/Ds;
         
         /*CALCULA O DETERMINANTE DE Y E DIVIDE PELO DETERMINANTE DO SISTEMA*/           
         dg1y=b[1][1]*b[2][3];
         dg2y=b[2][1]*b[1][3]*(-1);
         Dy=dg1y+dg2y;
         y=Dy/Ds;
         
         /*DEVOLVE OS RESULTADOS*/
         /*SE DETERMINANTE FOR IGUAL A ZERO SISTEMA IMPOSSÍVEL*/         
         if(Ds==0)
         {
           printf("\xBA Sistema Impossivel!!!\n");       
           printf("\xBA O determinante do sistema vale 0.\n");
         }
         else 
         {
           printf("\xBA ***RESULTADOS:***\n");
           printf("\xBA Determinante do sistema: %.2f\n",Ds);
           printf("\xBA valor de x = %.2f\n",x);
           printf("\xBA valor de y = %.2f\n",y);
         }  
         break;
         
         case 2:
         printf("\xCC");
         linha();
         printf("\xBC\n");                  
         printf("\xBA Atencao digite apenas os numeros, pois as incognitas (x,y,z)\n");
         printf("\xBA serao adicionadas automaticamente.\n");
      
      /*PEDE AO USUÁRIO PREENCHER A MATRIZ 3x3*/
      for(cont=1;cont<4;cont++)
      {
       printf("\xBA\n\xBA *** %d\xA6 equacao ***\n",cont);
        for(cont1=1;cont1<5;cont1++)
        {
           if(cont1==4)
           {
               printf("\xBA Informe o termo independente:");
               scanf("%d",&a[cont][4]);
           }
           else
           {
             printf("\xBA Informe o valor da %d incognita:",cont1);
             scanf("%d",&a[cont][cont1]);
           }
        }
      }   
      /*DEVOLVE A MATRIZ*/
      printf("\xCC");
      linha();
      printf("\xCD\n");
      printf("\xBA O sistema que voce informou foi:\n");
      printf("\xBA %dx %dy %dz = %d \n",a[1][1],a[1][2],a[1][3],a[1][4]);
      printf("\xBA %dx %dy %dz = %d \n",a[2][1],a[2][2],a[2][3],a[2][4]);
      printf("\xBA %dx %dy %dz = %d \n\xBA\n",a[3][1],a[3][2],a[3][3],a[3][4]);

      /*CALCULA O DETERMINANTE DO SISTEMA*/
      dg1=a[1][1]*a[2][2]*a[3][3];
      dg2=a[1][2]*a[2][3]*a[3][1];
      dg3=a[1][3]*a[2][1]*a[3][2];
      dg4=a[3][1]*a[2][2]*a[1][3]*(-1);
      dg5=a[3][2]*a[2][3]*a[1][1]*(-1);
      dg6=a[3][3]*a[2][1]*a[1][2]*(-1);
      Ds=dg1+dg2+dg3+dg4+dg5+dg6;
      
      /*CALCULA O DETERMINANTE DE X E DIVIDE PELO DETERMINANTE DO SISTEMA*/
      dg1x=a[1][4]*a[2][2]*a[3][3];
      dg2x=a[1][2]*a[2][3]*a[3][4];
      dg3x=a[1][3]*a[2][4]*a[3][2];
      dg4x=a[3][4]*a[2][2]*a[1][3]*(-1);
      dg5x=a[3][2]*a[2][3]*a[1][4]*(-1);
      dg6x=a[3][3]*a[2][4]*a[1][2]*(-1);
      Dx=dg1x+dg2x+dg3x+dg4x+dg5x+dg6x;
      x=Dx/Ds;
         
      /*CALCULA O DETERMINANTE DE Y E DIVIDE PELO DETERMINANTE DO SISTEMA*/
      dg1y=a[1][1]*a[2][4]*a[3][3];
      dg2y=a[1][4]*a[2][3]*a[3][1];
      dg3y=a[1][3]*a[2][1]*a[3][4];
      dg4y=a[3][1]*a[2][4]*a[1][3]*(-1);
      dg5y=a[3][4]*a[2][3]*a[1][1]*(-1);
      dg6y=a[3][3]*a[2][1]*a[1][4]*(-1);
      Dy=dg1y+dg2y+dg3y+dg4y+dg5y+dg6y;
      y=Dy/Ds;
      
      /*CALCULA O DETERMINANTE DE Z E DIVIDE PELO DETERMINANTE DO SISTEMA*/
      dg1z=a[1][1]*a[2][2]*a[3][4];
      dg2z=a[1][2]*a[2][4]*a[3][1];
      dg3z=a[1][4]*a[2][1]*a[3][2];
      dg4z=a[3][1]*a[2][2]*a[1][4]*(-1);
      dg5z=a[3][2]*a[2][4]*a[1][1]*(-1);
      dg6z=a[3][4]*a[2][1]*a[1][2]*(-1);
      Dz=dg1z+dg2z+dg3z+dg4z+dg5z+dg6z;
      z=Dz/Ds;
      
      /*DEVOLVE OS RESULTADOS*/
      /*SE DETERMINANTE FOR IGUAL A ZERO SISTEMA IMPOSSÍVEL*/
      if(Ds==0)
       {
        printf("\xBA Sistema Impossivel!!!\n");       
        printf("\xBA O determinante do sistema vale 0.\n");
       }
      else 
      {
       printf("\xBA ***RESULTADOS:***\n");
       printf("\xBA Determinante do sistema: %.2f\n",Ds);
       printf("\xBA valor de x = %.2f\n",x);
       printf("\xBA valor de y = %.2f\n",y);
       printf("\xBA valor de z = %.2f\n",z);
      } 
      break;
      
      case 3:
         printf("\xCC");
         linha();
         printf("\xBC\n");
         printf("\xBA Atencao digite apenas os numeros, pois as incognitas \n");
         printf("\xBA (x,y,z,w) serao adicionadas automaticamente.\n");
      
      /*PEDE AO USUÁRIO PREENCHER A MATRIZ 4x4*/
      for(cont=1;cont<5;cont++)
      {
       printf("\xBA\n\xBA *** %d\xA6 equacao ***\n",cont);
        for(cont1=1;cont1<6;cont1++)
        {
           if(cont1==5)
           {
               printf("\xBA Informe o termo independente:");
               scanf("%d",&c[cont][5]);
           }
           else
           {
             printf("\xBA Informe o valor da %d incognita:",cont1);
             scanf("%d",&c[cont][cont1]);
           }
        }
      }   
      
      /*DEVOLVE A MATRIZ*/
      printf("\xCC");
      linha();
      printf("\xCD\n");      
      printf("\xBA O sistema que voce informou foi:\n");
      printf("\xBA %dx %dy %dz %dw = %d \n",c[1][1],c[1][2],c[1][3],c[1][4],c[1][5]);
      printf("\xBA %dx %dy %dz %dw = %d \n",c[2][1],c[2][2],c[2][3],c[2][4],c[2][5]);
      printf("\xBA %dx %dy %dz %dw = %d \n",c[3][1],c[3][2],c[3][3],c[3][4],c[3][5]);
      printf("\xBA %dx %dy %dz %dw = %d \n\xBA\n",c[4][1],c[4][2],c[4][3],c[4][4],c[4][5]);      

      /*CALCULA O DETERMINANTE DO SISTEMA 4x4*/
      Ds1=(c[2][2]*c[3][3]*c[4][4])+(c[2][3]*c[3][4]*c[4][2])+(c[2][4]*c[3][2]*c[4][3])+(c[4][2]*c[3][3]*c[2][4]*(-1))+(c[4][3]*c[3][4]*c[2][2]*(-1))+(c[4][4]*c[3][2]*c[2][3]*(-1));
      
      Ds2=(c[1][2]*c[3][3]*c[4][4])+(c[1][3]*c[3][4]*c[4][2])+(c[1][4]*c[3][2]*c[4][3])+(c[4][2]*c[3][3]*c[1][4]*(-1))+(c[4][3]*c[3][4]*c[1][2]*(-1))+(c[4][4]*c[3][2]*c[1][3]*(-1));
      
      Ds3=(c[1][2]*c[2][3]*c[4][4])+(c[1][3]*c[2][4]*c[4][2])+(c[1][4]*c[2][2]*c[4][3])+(c[4][2]*c[2][3]*c[1][4]*(-1))+(c[4][3]*c[2][4]*c[1][2]*(-1))+(c[4][4]*c[2][2]*c[1][3]*(-1));
      
      Ds4=(c[1][2]*c[2][3]*c[3][4])+(c[1][3]*c[2][4]*c[3][2])+(c[1][4]*c[2][2]*c[3][3])+(c[3][2]*c[2][3]*c[1][4]*(-1))+(c[3][3]*c[2][4]*c[1][2]*(-1))+(c[3][4]*c[2][2]*c[1][3]*(-1));            
      
      Ds=(c[1][1]*Ds1)+(c[2][1]*(-1)*Ds2)+(c[3][1]*Ds3)+(c[4][1]*(-1)*Ds4);
      
      /*CALCULA O DETERMINANTE DE X E DIVIDE PELO DETERMINANTE DO SISTEMA*/
      Dx1=(c[2][2]*c[3][3]*c[4][4])+(c[2][3]*c[3][4]*c[4][2])+(c[2][4]*c[3][2]*c[4][3])+(c[4][2]*c[3][3]*c[2][4]*(-1))+(c[4][3]*c[3][4]*c[2][2]*(-1))+(c[4][4]*c[3][2]*c[2][3]*(-1));
      
      Dx2=(c[1][2]*c[3][3]*c[4][4])+(c[1][3]*c[3][4]*c[4][2])+(c[1][4]*c[3][2]*c[4][3])+(c[4][2]*c[3][3]*c[1][4]*(-1))+(c[4][3]*c[3][4]*c[1][2]*(-1))+(c[4][4]*c[3][2]*c[1][3]*(-1));
      
      Dx3=(c[1][2]*c[2][3]*c[4][4])+(c[1][3]*c[2][4]*c[4][2])+(c[1][4]*c[2][2]*c[4][3])+(c[4][2]*c[2][3]*c[1][4]*(-1))+(c[4][3]*c[2][4]*c[1][2]*(-1))+(c[4][4]*c[2][2]*c[1][3]*(-1));
      
      Dx4=(c[1][2]*c[2][3]*c[3][4])+(c[1][3]*c[2][4]*c[3][2])+(c[1][4]*c[2][2]*c[3][3])+(c[3][2]*c[2][3]*c[1][4]*(-1))+(c[3][3]*c[2][4]*c[1][2]*(-1))+(c[3][4]*c[2][2]*c[1][3]*(-1));            
      
      Dx=(c[1][5]*Dx1)+(c[2][5]*(-1)*Dx2)+(c[3][5]*Dx3)+(c[4][5]*(-1)*Dx4);
      x=Dx/Ds;
      
      /*CALCULA O DETERMINANTE DE Y E DIVIDE PELO DETERMINANTE DO SISTEMA*/
      Dy1=(c[2][5]*c[3][3]*c[4][4])+(c[2][3]*c[3][4]*c[4][5])+(c[2][4]*c[3][5]*c[4][3])+(c[4][5]*c[3][3]*c[2][4]*(-1))+(c[4][3]*c[3][4]*c[2][5]*(-1))+(c[4][4]*c[3][5]*c[2][3]*(-1));
      
      Dy2=(c[1][5]*c[3][3]*c[4][4])+(c[1][3]*c[3][4]*c[4][5])+(c[1][4]*c[3][5]*c[4][3])+(c[4][5]*c[3][3]*c[1][4]*(-1))+(c[4][3]*c[3][4]*c[1][5]*(-1))+(c[4][4]*c[3][5]*c[1][3]*(-1));
      
      Dy3=(c[1][5]*c[2][3]*c[4][4])+(c[1][3]*c[2][4]*c[4][5])+(c[1][4]*c[2][5]*c[4][3])+(c[4][5]*c[2][3]*c[1][4]*(-1))+(c[4][3]*c[2][4]*c[1][5]*(-1))+(c[4][4]*c[2][5]*c[1][3]*(-1));
      
      Dy4=(c[1][5]*c[2][3]*c[3][4])+(c[1][3]*c[2][4]*c[3][5])+(c[1][4]*c[2][5]*c[3][3])+(c[3][5]*c[2][3]*c[1][4]*(-1))+(c[3][3]*c[2][4]*c[1][5]*(-1))+(c[3][4]*c[2][5]*c[1][3]*(-1));            
      
      Dy=(c[1][1]*Dy1)+(c[2][1]*(-1)*Dy2)+(c[3][1]*Dy3)+(c[4][1]*(-1)*Dy4);      
      y=Dy/Ds;
      
      /*CALCULA O DETERMINANTE DE Z E DIVIDE PELO DETERMINANTE DO SISTEMA*/
      Dz1=(c[2][2]*c[3][5]*c[4][4])+(c[2][5]*c[3][4]*c[4][2])+(c[2][4]*c[3][2]*c[4][5])+(c[4][2]*c[3][5]*c[2][4]*(-1))+(c[4][5]*c[3][4]*c[2][2]*(-1))+(c[4][4]*c[3][2]*c[2][5]*(-1));
      
      Dz2=(c[1][2]*c[3][5]*c[4][4])+(c[1][5]*c[3][4]*c[4][2])+(c[1][4]*c[3][2]*c[4][5])+(c[4][2]*c[3][5]*c[1][4]*(-1))+(c[4][5]*c[3][4]*c[1][2]*(-1))+(c[4][4]*c[3][2]*c[1][5]*(-1));
      
      Dz3=(c[1][2]*c[2][5]*c[4][4])+(c[1][5]*c[2][4]*c[4][2])+(c[1][4]*c[2][2]*c[4][5])+(c[4][2]*c[2][5]*c[1][4]*(-1))+(c[4][5]*c[2][4]*c[1][2]*(-1))+(c[4][4]*c[2][2]*c[1][5]*(-1));
      
      Dz4=(c[1][2]*c[2][5]*c[3][4])+(c[1][5]*c[2][4]*c[3][2])+(c[1][4]*c[2][2]*c[3][5])+(c[3][2]*c[2][5]*c[1][4]*(-1))+(c[3][5]*c[2][4]*c[1][2]*(-1))+(c[3][4]*c[2][2]*c[1][5]*(-1));            
      
      Dz=(c[1][1]*Dz1)+(c[2][1]*(-1)*Dz2)+(c[3][1]*Dz3)+(c[4][1]*(-1)*Dz4);            
      z=Dz/Ds;
      
      /*CALCULA O DETERMINANTE DE W E DIVIDE PELO DETERMINANTE DO SISTEMA*/
      Dw1=(c[2][2]*c[3][3]*c[4][5])+(c[2][3]*c[3][5]*c[4][2])+(c[2][5]*c[3][2]*c[4][3])+(c[4][2]*c[3][3]*c[2][5]*(-1))+(c[4][3]*c[3][5]*c[2][2]*(-1))+(c[4][5]*c[3][2]*c[2][3]*(-1));
      
      Dw2=(c[1][2]*c[3][3]*c[4][5])+(c[1][3]*c[3][5]*c[4][2])+(c[1][5]*c[3][2]*c[4][3])+(c[4][2]*c[3][3]*c[1][5]*(-1))+(c[4][3]*c[3][5]*c[1][2]*(-1))+(c[4][5]*c[3][2]*c[1][3]*(-1));
      
      Dw3=(c[1][2]*c[2][3]*c[4][5])+(c[1][3]*c[2][5]*c[4][2])+(c[1][5]*c[2][2]*c[4][3])+(c[4][2]*c[2][3]*c[1][5]*(-1))+(c[4][3]*c[2][5]*c[1][2]*(-1))+(c[4][5]*c[2][2]*c[1][3]*(-1));
      
      Dw4=(c[1][2]*c[2][3]*c[3][5])+(c[1][3]*c[2][5]*c[3][2])+(c[1][5]*c[2][2]*c[3][3])+(c[3][2]*c[2][3]*c[1][5]*(-1))+(c[3][3]*c[2][5]*c[1][2]*(-1))+(c[3][5]*c[2][2]*c[1][3]*(-1));            
      
      Dw=(c[1][1]*Dw1)+(c[2][1]*(-1)*Dw2)+(c[3][1]*Dw3)+(c[4][1]*(-1)*Dw4);
      w=Dw/Ds;
      
      /*DEVOLVE OS RESULTADOS*/
      /*SE DETERMINANTE FOR IGUAL A ZERO SISTEMA IMPOSSÍVEL*/
      if(Ds==0)
       {
        printf("\xBA Sistema Impossivel!!!\n");       
        printf("\xBA O determinante do sistema vale 0.\n");
       }
      else 
      {
       printf("\xBA ***RESULTADOS:***\n");
       printf("\xBA Determinante do sistema: %.2f\n",Ds);
       printf("\xBA valor de x = %.2f\n",x);
       printf("\xBA valor de y = %.2f\n",y);
       printf("\xBA valor de z = %.2f\n",z);
       printf("\xBA valor de w = %.2f\n",w);       
      }
      break;           
      
      /*CASO O USUÁRIO NÃO DIGITE '1' NEM '2' NEM '3' */      
      default:
      printf("\xBA Opcao Invalida                                             \n");
      break;
      
      }
      printf("\xCC");
      linha();
      printf("\xBB\n");
      printf("\xBA Deseja inserir um novo sistema?                              \xBA");
      printf("\n\xBA Digite 1 se sim ou                                           \xBA\n");
      printf("\xBA Digite qualquer outro numero se deseja encerrar o programa.  \xBA\n");
      printf("\xBA R:");
      scanf("%d",&R);
      }
      while(R==1);  /*ENQUANTO 'R' FOR IGUAL A 1 O PROGRAMA VOLTARÁ PARA O MENU 
      DE OPÇÕES, CASO CONTRÁRIO SERÁ ENCERRADO */

      printf("\xC8");
      linha();
      printf("\xBC\n");
      printf("\nFim\n");
      
getch();
}
      

