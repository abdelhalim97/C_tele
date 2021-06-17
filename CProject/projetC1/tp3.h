#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
void transfere (int T1[100], int taille1,  int T2[100]);

int symetrique (int T1[100], int taille1);
void inverse (int T1[100], int taille1);

void rotationCase(int T1[100], int taille1);
void rotationCirculaire (int T1[100], int taille1, int k);
void insertion (int T1[100],int taille1);
int appartient(int T1[100],int taille1, int val); /*vérifie si val appartient au tableau*/
int fusion(int T1[100], int taille1,  int T2[100], int taille2, int V1[200]);
void afficher (int T[100], int taille);

int ex17()
{
 int T1[100]={1,2,3,4,5};
 int T2[100]={7,8,3,2,9,10,11};
 int V1[200];
 int taille;
 afficher(T1,5);
 afficher(T2,7);
 taille= fusion(T1, 5, T2, 7, V1);
 afficher(V1,taille);
return 0;
}

void afficher (int T[100], int taille)
{
    int i;
    printf("\n [");
    for(i=0; i<taille;i++)
        printf (" %d ", T[i]);
    printf("] \n");
}

void transfere (int T1[100], int taille1,  int T2[100])
{
int i,j,k;
j=0; k= taille1-1;
for(i=0;i<taille1;i++)
  if (i%2==0)
{
    T2[j]= T1[i];
    j++;
}
else
{
    T2[k]= T1[i];
    k--;
}
}

int symetrique (int T1[100], int taille1)
{
    int estSymetrique=1;
    int i=0;
    while (estSymetrique && i<taille1/2)
    {
        if (T1[i]!=T1[taille1-i-1])
            estSymetrique=0;
        i++;
    }
    return estSymetrique;
}

void inverse (int T1[100], int taille1)
{
    int i=0;
    int aux;
    while (i<taille1/2)
     { aux= T1[i];
       T1[i]=T1[taille1-i-1];
       T1[taille1-i-1] = aux;
       i++;
    }
}


void rotationCase(int T1[100], int taille1)
{
    int first = T1[0];
    int i;
    for (i=0; i<taille1-1; i++)
        T1[i]=T1[i+1];

    T1[taille1-1]=first;
}

void rotationCirculaire (int T1[100], int taille1, int k)
{int i;
  for(i=1; i<=k; i++)
    rotationCase(T1,taille1);
}

void insertion (int T1[100],int taille1)
{ /* on suppose que pos de 1 à taille1*/
    int i, val, pos;

    do{
    printf("Donner la position"); scanf("%d", &pos);
    }while (pos<1|| pos>taille1);

    printf("Donner la valeur"); scanf("%d", &val);

    for (i=taille1; i>=pos; i--)
        T1[i]=T1[i-1];
    T1[pos-1] = val;
}


int appartient(int T1[100],int taille1, int val)
{
    int i=0;
    int trouve = 0;
    while(!trouve && i<taille1)
    {
      if (T1[i]==val)
        trouve=1;
      i++;
    }
    return trouve;
}


int fusion(int T1[100], int taille1,  int T2[100], int taille2, int V1[200])
{int i, taille=0;
    for (i=0; i<taille1; i++)
    {
        if (!appartient(V1,taille,T1[i]))
           { V1[taille]= T1[i]; taille++;}

    }

     for (i=0; i<taille2; i++)
    {
        if (!appartient(V1,taille,T2[i]))
            {V1[taille]= T2[i]; taille++;}

    }
return taille;
}
void elementsSup(int T1[100], int taille1, int val);
void minElementSup (int T1[100], int taille1, int val);
int nbOccurence (int T1[100], int taille1, int val);
void apparaitLePlus(int T1[100], int taille1);
void PlateauMaximal(int T1[100], int taille1);
int ex18()
{ int val;
  int T1[100]={1,2,2,2,2,2,5,5,6,6};
  printf(" donner une valeur"); scanf("%d", &val);
  elementsSup(T1,10,val);
  minElementSup (T1,10,val);
  apparaitLePlus(T1, 10);
  PlateauMaximal(T1,10);
  return 0;
}

void elementsSup(int T1[100], int taille1, int val)
{
    int i;
    printf(" \n les elements superieurs a %d sont : ", val);
    for(i=0; i<taille1; i++)
    {
        if (T1[i]>val)
            printf (" %d ", T1[i]);
    }

}

void minElementSup(int T1[100], int taille1, int val)
{
    int i;
    int existe = 0;
    int min;
    for(i=0; i<taille1; i++)
    {
        if (T1[i]>val && !existe)
        {
            existe=1;
            min =T1[i];

        }
        if (existe)
           if (T1[i]>val && T1[i]<min)
               min = T1[i];
    }
    if (existe)
    printf ("\n la plus petite valeur supérieure à %d est %d",val,  min);
    else
        printf ("\n pas de valeur supérieure à  %d", val);

}

int nbOccurence (int T1[100], int taille1, int val)
{
    int occ=0;
    int i;
    for(i=0; i<taille1; i++)
        if (T1[i] == val)
            occ++;
    return occ;
}


void apparaitLePlus(int T1[100], int taille1)
{
    int elemMax, nbOccMax=0, nbOcc,i;
    for(i=0; i<taille1; i++)
    {
        nbOcc= nbOccurence(T1,taille1, T1[i]);
        if (nbOcc > nbOccMax)
         {
           elemMax = T1[i];
            nbOccMax = nbOcc;
         }
    }
    printf ("\n l'element qui apparait le plus est %d  il apparait %d fois", elemMax, nbOccMax);
}



void PlateauMaximal(int T1[100], int taille1)
{
    int debutPlateau=0, finPlateau=0, tailleMax=0,taillePlateau, DebutPlateauMax, finPlateauMax;

    while (finPlateau < taille1)
    { taillePlateau = 0;
        debutPlateau = finPlateau;
        while (T1[finPlateau]== T1[debutPlateau])
        {
            finPlateau++;
            taillePlateau++;
        }

        if ((taillePlateau) > tailleMax)
        {
           tailleMax=taillePlateau;
           DebutPlateauMax=debutPlateau;
           finPlateauMax= finPlateau-1;
        }

    }
 printf ("\n  \n le plateau max est de taille %d il commence à l'indice %d et il se termine à l'indice %d", tailleMax,DebutPlateauMax,finPlateauMax  );
}

int maximum(int T[100], int taille);
void Trier (int T[100], int taille, int B[100]);
void afficher1 (int T[100], int taille);
int ex19()
{
    int T[100]={5,6,9,8,2,15,27};
    int B[100];
    int taille = 7;
    Trier (T, taille, B);
    return 0;
}


void afficher1 (int T[100], int taille)
{
    int i;
    printf("\n [");
    for(i=0; i<taille;i++)
        printf (" %d ", T[i]);
    printf("] \n");
}
int maximum(int T[100], int taille)
{
    int i, max=-1, indiceMax;
    for (i=0;i<taille;i++)
    {
        if(T[i] > max)
            {
            max=T[i];
            indiceMax = i;
            }
    }
    return indiceMax;
}

void Trier (int T[100], int taille, int B[100])
{
    int i,indiceMax;
    afficher1(T,taille);
    for (i=0;i<taille; i++)
    {   indiceMax = maximum(T,taille);
        B[i]=T[indiceMax];
        T[indiceMax] = -1;
    }
    afficher1(B,taille);
}

int premierDiviseurPremier1(int X);
int nbreDiviseursPremiers(int X);
/*retourne le premier nombre premier qui divise X;*/
int KPP(int X, int k);
/*verifie si X est KPP */
int ex20()
{
  int T[20]={32,219,685,698,988,785};
  int taille = 6;
  int i,k;

  do
  {
    printf("Donne la valeur de k entre 2 et 5");
    scanf("%d",&k);
  }while (k>5 || k<2);

  for (i=0;i<taille; i++)
  {
      if (KPP(T[i], k))
        printf ("\n   %d  est %d-PP", T[i],k);
  }
    system("pause");
   return 0;
}


int premierDiviseurPremier1(int X)
{ int n,i,estPremier;
    //on genere les nombres  n jusqu'à ce que X%n==0 le premier diviseur sera surement premier
      n=2;
      while (n <= X)
      {
           if (X%n==0)
            return n;
        else
            n++;
      }
}
int nbreDiviseursPremiers(int X)
{
   int nbDiviseursPremiers = 0,n;

do
   {
        n=premierDiviseurPremier1(X);
        if (X==n) //pour eviter le * superflu à la fin
           printf("  %d     ////",n);
        else
           printf("   %d * ",n);
        nbDiviseursPremiers++;
        X=X/n;
    }while(X>1);
 return nbDiviseursPremiers;
}


int KPP(int X, int k)
{
    if ((nbreDiviseursPremiers(X))== k)
        return 1;
    else
        return 0;
}
void ex21(){
    int M[4][4]={{5,2,3,5},{2,8,9,11},{3,9,6,1},{5,11,1,10}};
    int sym1(int M[4][4],int I,int J),sym2(int M[4][4],int I,int J);
    if(sym1(M,4,4)==1){
        printf("M est sym par rapport a la pre");
    }
    else if(sym2(M,4,4)==1){
        printf("M est sym par rapport a la 2eme");
    }
    else{
        printf("M n est pas sym ");
    }
}
int sym2(int M[4][4],int I,int J){
    int i=0,j=0;
    while(i<I){
        while(j<J){
        if(M[j][i]!=M[J-j-1][I-i-1]){
            return 0;
        }
        j++;
    }
    i++;
    j=0;
    }
    return 1;
}
int sym1(int M[4][4],int I,int J){
    int i=0,j=0;
    while(i<I){
        while(j<J){
        if(M[j][i]!=M[i][j]){
            return 0;
        }
        j++;
    }
    i++;
    j=0;
    }
    return 1;
}

void  ex22(){
    int L=4,C=3,a=0,b=0;
    int M[4][3]={{4,8,5},{9,8,8},{3,4,5},{8,1,5}};
    int MaxColonne(int M[4][3],int L,int i,int j),MinLigne(int M[4][3],int C,int i,int j);
for(int i=0;i<L;i++){
    for(int j=0;j<C;j++){
           a=MinLigne(M,3,i,j);
    b=MaxColonne(M,4,i,j);
    if(a==1 && b==1){
        printf(" %d est pt col \n",M[i][j]);
    }else{
        printf("%d n est pas un pt col \n",M[i][j]);
    }
    }
    }
}
int MinLigne(int M[4][3],int C,int i,int j){
   // int min=M[0][y];
    for(int k=0;k<C;k++){
        if(M[i][k]<M[i][j]){
            return 0;
        }
    }
    return 1;
}
int MaxColonne(int M[4][3],int L,int i,int j){
   // int min=M[0][y];
    for(int l=0;l<L;i++){
        if(M[l][j]>M[i][j]){
            return 0;
        }
    }
    return 1;
}
void ex23()
{
    int l,c,i,j;
    do{
        printf("donner lenght matrice: ");
        scanf("%d",&c);
    }while(c<=0);
    int T[c][c];
    for(i=0;i<c;i++){
            printf("\n");
        for(j=0;j<c;j++){
            do{
            printf("donner l' element %d de ligne %d : ",j+1,i+1);
            scanf("%d",&T[i][j]);
            }while(T[i][j]<0);
            }
        }
    somme_diagonale1(c,T);
    somme_diagonale2(c,T);

    somme_colone(c,T);
    somme_ligne(c,T);
    if (somme_ligne(c,T)==somme_colone(c,T)&&(somme_ligne(c,T)%c==0)&&(somme_colone(c,T)%c==0) ){
            printf("matrice est  magique");
    }else{
        printf("matrice n'est pas magique");
    }
}
int somme_colone(int c,int T[][c]){
    int i,j,somme,sommee=0;
    int T1[c];
    for(i=0;i<c;i++){
            somme=0;
            for(j=0;j<c;j++){
                somme=somme+T[i][j];
            }
            T1[i]=somme;
    }
    for(i=0;i<c;i++){
        sommee=sommee+T1[i];
    }
    printf("y1= %d",sommee);
     printf("\n");
        return sommee;
}
int somme_ligne(int c,int T[][c]){
    int i,j=0,somme=0,sommee=0;
    int T1[c];
    while(j<c){
        somme=0;
        for(i=0;i<c;i++){
        somme=somme+T[i][j];
        }
        T1[j]=somme;
        j++;
    }
    printf("\n");
   ;
    for(i=0;i<c;i++){
        sommee=sommee+T1[i];
    }
    printf("y= %d",sommee);
     printf("\n");
        return sommee;
}
int somme_diagonale1(int c,int T[][c]){
    int i,j=0,somme=0,sommee=0;
    int T1[c];
    for(i=0;i<c;i++){
        somme=somme+T[i][i];
    }
    printf("somme1 :% d ",somme);
    return somme;
    }
int somme_diagonale2(int c,int T[][c]){
    int i,j=0,somme=0,sommee=0;
    int T1[c];
    for(i=c-1;i>=0;i--){
        somme=somme+T[i][i];
    }
    printf("  somme2 :% d ",somme);
    return somme;
    }

#endif // TP3_H_INCLUDED
