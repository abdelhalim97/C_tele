#ifndef IMPORTATION_H_INCLUDED
#define IMPORTATION_H_INCLUDED
#endif // IMPORTATION_H_INCLUDED

void importerDonnees(int TVoix[24][8], char* nomFichier)
{
FILE *h;
int nbGouvernorats, i=0;
int nbPartis;
h= fopen(nomFichier, "r") ;
if(h==NULL)
printf("impossible d'ouvrir le fichier");
else
{
  fscanf(h,"%d",&nbGouvernorats);
  fscanf(h,"%d",&nbPartis);
  printf(" nbre gouvernorats =%d nombre partis = %d",nbGouvernorats,nbPartis);

  while (i<nbGouvernorats)
  {
    fscanf(h,"%d%d%d%d%d%d%d%d",&TVoix[i][0],&TVoix[i][1],&TVoix[i][2],&TVoix[i][3],&TVoix[i][4],&TVoix[i][5],&TVoix[i][6],&TVoix[i][7]);
    i++;
  }
 }
fclose(h);

}

