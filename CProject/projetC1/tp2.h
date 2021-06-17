#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED
#include <stdlib.h>
#include<math.h>
#include <stdio.h>

int ex8 ( )
{
long int n,i , s=0,a ;
do
{
printf ( "Donner un entier > 0 : " ) ;
scanf ("%ld",&n ) ;
}while ( !(n>0));

 while (n!=0)
{
a= n%10;
s=s*10+a ;
n=n/10;
}
/*
for (i=n; i!=0; i/=10)
{
 a= n%10;
 s=s*10+a ;
 n=n/10;
}



do
{
a= n%10;
s=s*10+a ;
n=n/10;
}while (n!=0);
*/

printf("Le resultat = %ld", s) ;
/* ce programme inverse le nombre */
return 0;
}


int ex9()
{
    int n,i;
    float s=0.0;
    do
    {
      printf("donner un entier ");
      scanf("%d",&n);
    }while(n<=2);
    for (i=1; i<=n; i++)
    {
       if(i%2==1)
       {
        if(i==n)
           printf("1/%d  ",i*i);
        else
           printf("1/%d - ",i*i);
        s= s + (1.0/(i*i));
       }
       else
       {
          if(i==n)
           printf("1/%d  ",i*i);
        else
           printf("1/%d + ",i*i);
        s= s - (1.0/(i*i));
       }
    }
    printf(" \n la somme = %f  ",s);
    return 0;
}

int ex10()
{
   int n,i, k=1;
    float s=0.0;
    do
    {
      printf("donner un entier ");
      scanf("%d",&n);
    }while(n<=2);

    for (i=1; i<=n; i++)
    {
        if (i>1)
        {
        if(k>0)
         printf("+ 1/%d  ",i*i);
        else
         printf("- 1/%d  ",i*i);
        }
        else
           printf(" 1/%d  ",i*i);

        s= s+ k*(1.0/(i*i));
        k=k*(-1);
    }
    printf(" \n la somme = %f  ",s);

    return 0;
}

int ex11()
{ int N,i=1,x ,unite, dizaine, centaine,milliers, nbreEntiersValables=0;
   do{
        printf("Donner le nombre d'entiers à saisir");
        scanf("%d",&N);
     }while(N<=1);

   while(i<=N)
   {
           do{
               printf("donner l'entier de 4 chiffres numero %d   ",i);
               scanf("%d",&x);
             }while(x<1000 || x>9999);

            unite = x%10;
            dizaine= (x/10)%10;
            centaine= (x/100)%10;
            milliers=(x/1000)%10;
            if ( (unite%milliers==0) && (dizaine%milliers==0) && (centaine%milliers==0))
                 nbreEntiersValables++;
           i++;
   }
    printf("il y a %d entiers valables dans la suite",nbreEntiersValables);
    system("pause");

    return 0;
}

int premierDiviseurPremier(int X);
/*retourne le premier nombre premier qui divise X;*/

int ex12()
{
    int X,n,estPremier;

   do{
        printf("Donner un entier >1   ");
        scanf("%d",&X);
     }while(X<=1);

   printf("%d =",X);
   do
   {
        n=premierDiviseurPremier(X);
        if (X==n) //pour eviter le * superflu à la fin
           printf("%d ",n);
        else
           printf("%d * ",n);
        X=X/n;
    }while(X>1);
    system("pause");
   return 0;
}


int premierDiviseurPremier(int X)
{ int n,i,estPremier;
    //on genere les nombres premiers n jusqu'à ce que X%n==0
      n=2;
      while (n <= X)
      {
        //vérifier si n est premier
         estPremier=1;
         i=2;
         while(i<=n/2 && estPremier )
           {
             if (n%i==0)
                estPremier=0;
             i++;
           }

        if (estPremier && X%n==0)
            return n;
        else
            n++;
      }



}

int ex13()
{
   int jour, mois, annee;
   int jour1,mois1, annee1;
   int nbJoursMois;
   setlocale (LC_ALL,"");
   printf("donner le jour, le mois et l'année");
   scanf("%d%d%d",&jour,&mois,&annee);
   printf("%d/%d/%d \n",jour,mois,annee);

   switch(mois)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:nbJoursMois = 31;
                break;
        case 4:
        case 6:
        case 9:
        case 11:nbJoursMois = 30;
                break;
        case 2: /* bissextile divisible par 4 mais pas par 100 ou divisible par 400 */
                if ((annee%4==0 && annee%100 !=0)||(annee%400 == 0))
                    nbJoursMois = 29;
                else
                    nbJoursMois = 28;
                break;

        default: printf("mois non valide");
    }

    if (jour >0 && jour <= nbJoursMois  && mois>0  && mois <= 12 && annee >0)
    {
      jour1 = (jour+1)% nbJoursMois;
      if (jour1==1)
          mois1= (mois+1)%12;
      else
          mois1= mois;

      if(mois1 == 1 && jour1==1)
         annee1= annee+1;
    else
         annee1= annee;
      printf(" date suivante %d/%d/%d \n",jour1,mois1,annee1);
    }
    else
        printf("\n date invalide");

   return 0;
}

int ex14()
{

   int jour, mois, annee;
   int c,a, m,j;
   int nbJoursMois;
   setlocale (LC_ALL,"");
   printf("donner le jour, le mois et l'année");
   scanf("%d%d%d",&jour,&mois,&annee);
   printf("%d/%d/%d \n",jour,mois,annee);

   switch(mois)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:nbJoursMois = 31;
                break;
        case 4:
        case 6:
        case 9:
        case 11:nbJoursMois = 30;
                break;
        case 2: /* bissextile divisible par 4 mais pas par 100 ou divisible par 400 */
                if ((annee%4==0 && annee%100 !=0)||(annee%400 == 0))
                    nbJoursMois = 29;
                else
                    nbJoursMois = 28;
                break;

        default: printf("mois non valide");
    }

    if (jour >0 && jour <= nbJoursMois  && mois>0  && mois <= 12 && annee >1582 && annee<=9999 )
    {
        c=(14-mois)/12;
        a= annee-c;
        m=mois+12*c-2;
        j=(jour+a+ a/4 - a/100 + a/400 + (31*m)/12)%7;
        switch(j)
      {
        case 0: printf("\n dimanche"); break;
        case 1: printf("\n lundi"); break;
        case 2: printf("\n mardi"); break;
        case 3: printf("\n mercredi"); break;
        case 4: printf("\n jeudi"); break;
        case 5: printf("\n vendredi"); break;
        case 6: printf("\n samedi"); break;

      }
    }
    else
        printf("\n date invalide");

   return 0;
}

int ex15()
{ int nb,i,estPremier, n,N,M;

   do{
        printf("Donner un entier >1 ");
        scanf("%d",&nb);
     }while(nb<=1);
  i=2; estPremier=1;
  while(i<=nb/2 && estPremier)
   { if (nb%i==0)
        estPremier=0;
     i++;
   }
   if(estPremier)
     printf(" %d est un nombre premier \n",nb);
   else
     printf(" %d n est pas un nombre premier \n",nb);


   //***********************************************
   n=1;nb=2;
   printf ("les 10 premiers nombres premiers");
   while(n<=10)
   {
      i=2; estPremier=1;
      while(i<=nb/2)
        { if (nb%i==0)
            estPremier=0;
        i++;
        }
       if(estPremier)
        {
           printf(" %d ",nb);
           n++;
         }
       nb++;
   }
  //*******************************************
   do{
        printf("Donner un entier N >1 ");
        scanf("%d",&N);
     }while(N<=1);

    do{
        printf("Donner un entier M >%d ",N);
        scanf("%d",&M);
     }while(M<=N || M>1000);
     printf ("les nombres premiers compris entre %d et %d   ",N,M);
     for(nb=N;nb<=M;nb++)
     {
            i=2; estPremier=1;
            while(i<=nb/2)
              { if (nb%i==0)
                estPremier=0;
               i++;
              }
             if(estPremier)
            {
               printf(" %d ",nb);
            }
      }
   system("pause");
   return 0;

}

int sommeChiffres (int x);
int estHeureux(int x);
int ex16()
{int a,b,x;
    do{
        printf("donner un entier a");
        scanf("%d",&a);
    }while(a<50);
     do{
        printf("donner un entier b");
        scanf("%d",&b);
    }while(b<a || b>500);
    for (x=a;x<=b;x++)
    {
        if (estHeureux(x))
            printf("  %d ",x);
    }
    return 0;
}

int sommeChiffres (int x)
{ int somme=0, chiff;
    while(x>0)
    {
        chiff=x%10;
        somme = somme + chiff*chiff;
        x=x/10;
    }
    return (somme);
}


int estHeureux(int x)
{
    int somme;
    do
    {
       somme = sommeChiffres(x);
       x=somme;
    }while (x>=10);

    if (x==1)
     return 1;
    else
     return 0;
}

#endif // TP2_H_INCLUDED
