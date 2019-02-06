#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"

int main()
{
    int nBr;

    FILE * pFile;
   int nCycle;
   int matrice[MATRICE_SUR] [MATRICE_SUR ];
   char s[2];
   printf("Nombre de cycles : ");
   scanf("%i",&nCycle);
   init(matrice);
   printf("La population au d�part : \n");
   if ((pFile=fopen("Cellules.txt", "w"))==NULL)
    {
        perror("Erreur de creation de fichier\n");

    }
    else
    {
        fprintf(pFile, "La population au d�part : \n");
        fclose(pFile);
   }
   affiche_matrice(matrice, pFile);
   printf("Pressez sur ENTER pour continuer...\n");
   gets(s);
   for(nBr=0; nBr<nCycle; nBr++) {
      mise_a_jour (matrice);
      printf("La population apr�s %d cycles: \n", nBr+1);
      if ((pFile=fopen("Cellules.txt", "a"))==NULL)
      {
        perror("Erreur de creation de fichier\n");

      }
      else
      {
        fprintf(pFile, "La population apr�s %d cycles: \n", nBr+1);
        fclose(pFile);
      }
      affiche_matrice (matrice, pFile);
      printf("Pressez sur ENTER pour continuer...\n");
      gets(s);
   }
}
