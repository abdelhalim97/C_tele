#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Importation.h"
void saisie_voix(int Voix[24][8],int l,int c,char* NomFichierVoix){
    int i,j;
//    int Voix[24][8];
    importerDonnees(Voix, "voix.txt");
   /* for(i=0; i<24;i++)
    {
        printf("\n");
        for(j=0;j<8;j++)
             printf(" %d ", Voix[i][j]);
    }*/
}
void init_sieges(int Sieges[24][8],int l,int c){

}
void init_quotient(int quotient_electoral[24],int c){

}
void calculQuotient(int Voix[24][8],int l,int c,int quotient_electoral[24]){//filling quotient_electoral
    int sum=0;
    for (int i=0;i<7;i++){
       sum= sum +Voix[l][i];
       //printf("sum %d ", sum);
    }
    //printf("sum %d ", sum);
    //printf("%d ", Voix[l][7]);
    quotient_electoral[l]= sum/Voix[l][7];// declaration l should be a variable
    //printf("%d ", quotient_electoral[l]);
}
int nbSieges(int nbVoix,int electoral){
    return nbVoix/electoral;
}
void affectation(int Voix[24][8],int l,int c,int Sieges[24][8],int quotient_electoral[24]){//reste

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
//printf("%d  ", Voix[0][7]);
            if(j<7 && Voix[i][j]>quotient_electoral[i]){
                int ns = nbSieges(Voix[i][j],quotient_electoral[i]);
                //int ns = Voix[i][j]/quotient_electoral[i];
                //Sieges[i][j]=nbSieges(Voix[i][j],quotient_electoral[j]);
                Sieges[i][j]=ns;
                Voix[i][j]-=ns*quotient_electoral[i];
                //printf("%d  ", Sieges[i][j]);
            }
            else if(j<7 && Voix[i][j]<quotient_electoral[i]){
                Sieges[i][j]=0;
                //printf("%d  ", Sieges[i][j]);
            }
            else if (j==7){
                Sieges[i][7] = Voix[i][7];
                //printf("%d  ", Sieges[i][j]);
            }
        }
        printf("\n  ");
    }
}
int max1(int t[24][8],int n,int l){
    int max0=t[l][0];/*
    for(int i=0;i<l;i++){
        printf("\n ");
        for(int j=0;j<8;j++){printf("%d  ", t[i][j]);}}*/
    int j=0;
    if(n!=1){
        for(int i=1;i<n;i++){
            if(t[l][i]>max0){

                max0=t[l][i];
                j=i;
            }
        }
    }
    return j;
}
void mettreAjour(int Voix[24][8],int l,int c,int Sieges[24][8],int quotient_electoral[24]){
    for(int i=0;i<l;i++){
            int sum=0;
        for(int j=0;j<c-1;j++){
            sum= sum +Sieges[i][j];
    }
        while(sum<Voix[i][7]){
        int k=0;
            k=max1(Voix,7,i);
            Sieges[i][k]++;
            sum++;
            Voix[i][k]=0;
        }
        //printf("Voix[i][k]=%d  ",Voix[i][k]);
    }
    printf("\n  ");
    }

void tp4(){
    void saisie_voix(int Voix[24][8],int l,int c,char* NomFichierVoix),init_sieges(int Sieges[24][8],int l,int c)
    ,init_quotient(int quotient_electoral[24],int c),calculQuotient(int Voix[24][8],int l,int c,int quotient_electoral[24]),
    affectation(int Voix[24][8],int l,int c,int Sieges[24][8],int quotient_electoral[24]),mettreAjour(int Voix[24][8],int l,int c,int Sieges[24][8],int quotient_electoral[24]);
    int l=24 ,c=8,Voix[24][8],t[24][8],electoral;
    int nbSieges(int nbVoix,int electoral),max1(int t[24][8],int n,int l);
    char NomFichierVoix;
    int Sieges[24][8]={0};
    int quotient_electoral[24]={1};
    int nbVoix=0;
    saisie_voix(Voix,l,c,NomFichierVoix);
    printf("\n");
    for (int j=0;j<l;j++){
       calculQuotient(Voix,j,c,quotient_electoral);
    }
    printf("\n");
    affectation(Voix,l,c,Sieges,quotient_electoral);
    /*
    for(int i=0;i<l;i++){
        printf("\n ");
        for(int j=0;j<c;j++){printf("%d  ", Voix[i][j]);}}*/
    mettreAjour(Voix,l,c,Sieges,quotient_electoral);
    printf("Annahtha  TAILLAR  UDL  FrontP  JOMH  PDM  AFEK \n");
    for(int i=0;i<l;i++){
        printf("\n ");
        for(int j=0;j<c;j++){
                printf("%d  ", Sieges[i][j]);
        }}

}

int tp4Parti()
{
void saisie_voix(int Voix[24][8],int l,int c,char* NomFichierVoix),init_sieges(int Sieges[24][8],int l,int c)
    ,init_quotient(int quotient_electoral[24],int c),calculQuotient(int Voix[24][8],int l,int c,int quotient_electoral[24]),
    affectation(int Voix[24][8],int l,int c,int Sieges[24][8],int quotient_electoral[24]),mettreAjour(int Voix[24][8],int l,int c,int Sieges[24][8],int quotient_electoral[24]);
    int l=24 ,c=8,Voix[24][8],t[24][8],electoral;
    int nbSieges(int nbVoix,int electoral),max1(int t[24][8],int n,int l);
    char NomFichierVoix;
    int Sieges[24][8]={0};
    int quotient_electoral[24]={1};
    int nbVoix=0;
    saisie_voix(Voix,l,c,NomFichierVoix);
    for (int j=0;j<l;j++){
       calculQuotient(Voix,j,c,quotient_electoral);
    }
    printf("\n");
    affectation(Voix,l,c,Sieges,quotient_electoral);
    mettreAjour(Voix,l,c,Sieges,quotient_electoral);
    int Annahtha=0, TAILLAR=0,  UDL=0, FrontP=0, JOMH=0, PDM=0, AFEK=0;
    int  parti[7]={
        Annahtha, TAILLAR, UDL,  FrontP, JOMH, PDM,  AFEK};
    for(int i=0;i<l;i++){
        for(int j=0;j<c-1;j++)
            {
                parti[j]+=Sieges[i][j];
            }}
            printf(" Annahtha  TAILLAR  UDL  FrontP  JOMH  PDM  AFEK \n");
            for(int j=0;j<c-1;j++)
                {
                    printf(" %d  ", parti[j]);
                }
}
#endif // TP4_H_INCLUDED
