#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED
#include <locale.h>


#endif // TP1_H_INCLUDED
int ex2()
{
    int x; float y;
    printf("donner x:");
    scanf("%d",&x);
    printf("donner y:");
    scanf("%f",&y);

    printf("%3d\n",x);
    printf("%10f\n",y);
  return 0;
}
int ex3()
{
    int i,j,n;
    i=0; n=i++;
    printf("A: i=%d n=%d \n",i,n);

    i=10; n=++i;
    printf("B: i=%d n=%d \n",i,n);

    i=20;j=5; n=i++*++j;
    printf("C: i=%d j=%d n=%d \n",i,j,n);

    i=15; n=i+=3;
     printf("D: i=%d n=%d \n",i,n);

    i=3;j=5; n=i+=--j;
    printf("E: i=%d j=%d n=%d \n",i,j,n);

    return 0;
}
int ex4()
{

int a,b,c;
int max;
printf("donner la valeur de a"); scanf("%d",&a);
printf("donner la valeur de b"); scanf("%d",&b);
printf("donner la valeur de c"); scanf("%d",&c);


if(b>a)
    max=b;
else
    max=a;
if (c>max)
    max=c;
printf(" le maximum est %d",max);
}
int ex5()
{ int Q;
  float PU;
  float tauxRemise, remise, montantTVA, montantTTC, montantHT, montantNet;
  const float TVA=0.18;
    setlocale (LC_ALL,"");
    printf("donner la quantité commandée: "); scanf("%d",&Q);
    printf("donner le prix unitaire: "); scanf("%f",&PU);

    montantHT = Q*PU;
    montantTVA = montantHT*TVA;
    montantTTC = montantHT+montantTVA;

    if (montantTTC <1000.0)
       tauxRemise = 0.1;
    else
        if (montantTTC <5000.0)
           tauxRemise = 0.15;
         else
            if (montantTTC <10000.0)
               tauxRemise = 0.2;
            else
               tauxRemise = 0.3;

    remise = montantTTC*tauxRemise;
    montantNet = montantTTC - remise;

    printf("+*******************************************************+\n");
    printf("Montant HT                       :%.3f Dinars\n", montantHT);
    printf("Montant TVA                      :%.3f Dinars\n", montantTVA);
    printf("Montant TTC                      :%.3f Dinars\n", montantTTC);
    printf("Remise                           :%.3f Dinars\n", remise);
    printf("+*******************************************************+\n");
    printf("Net à payer                      :%.3f Dinars\n", montantNet);

    return 0;
}

int ex6()
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




int ex7()
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


