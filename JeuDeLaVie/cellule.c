#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"
#define N 2

/** \brief Mise en place du
 *
 * \param int matrice[][]
 * \return le cycle de départ de mon tableau avec initialiser au hasard
 *
 */

void init(int matrice [][MATRICE_SUR ])
{
   int nI,nJ;
   for(nI=0; nI<MATRICE_SUR; nI++)
   {
      for(nJ=0; nJ<MATRICE_SUR; nJ++)
        {
            matrice[nI][nJ]=rand()%N;
        }
   }
}
/** \brief Calcul du nombre de voisins vivants
 *
 * \param int matrice[][]
 * \param int ligne
 * \param int nCol
 * \return nombre de voisins vivant
 *
 */

int nombre_voisins (int matrice[][MATRICE_SUR ], int ligne, int nCol)
{

   int compte=0; /* compteur de cellules */
   int nI,nJ;
/* On additionne les 9 cellules centrées en ligne,nCol */
   for (nI=ligne-1;nI<=ligne+1;nI++)
      for(nJ=nCol-1;nJ<=nCol+1;nJ++)
         compte=compte+matrice[nI][nJ];

         /* Puis on retire celle du milieu... */
         compte -= matrice[ligne][nCol];
         return compte;
}


 /** \brief Creation du prochain cycle
  *
  * \param int matrice[ ][MATRICE_SUR ]
  * \return cycle suivant
  *
  */

void mise_a_jour(int matrice[ ][MATRICE_SUR ])
{

   int nI,nJ;
   int nbr_voisins;
   int matrice_densite[MATRICE_SOUS][MATRICE_SOUS];
   /* matrice qui comptabilise le nombre de voisins */
   /* et cela, case par case */
   for(nI=0; nI< MATRICE_SOUS; nI++)
         for(nJ=0; nJ< MATRICE_SOUS; nJ++)
            matrice_densite[nI][nJ]=nombre_voisins(matrice,nI+1,nJ+1);
      /* i+1 et j+1 car on passe de la SOUS_MATRICE à la MATRICE   */

   for(nI=0; nI< MATRICE_SOUS; nI++)
      for(nJ=0; nJ< MATRICE_SOUS; nJ++) {
            nbr_voisins=matrice_densite[nI][nJ];
            if(nbr_voisins==2)
                  matrice[nI+1][nJ+1]=1;
            else if (nbr_voisins==0 || nbr_voisins==4)
                  matrice[nI+1][nJ+1]=0;
   }
}

void ligne(int largeur) {
   int nI;
   for(nI=0; nI<largeur; nI++)
      printf("+-");
   printf("+\n");
}

/** \brief Affichage à l'écran des cellules vivantes
 *
 * \param int matrice[][]
 * \param FILE *pFile
 * \return affichage sur le console d'un cycle
 *
 */

void affiche_matrice(int matrice[ ][MATRICE_SUR ], FILE * pFile) {

   int nI,nJ;

   if ((pFile=fopen("Cellules.txt", "a"))==NULL)
    {
        perror("Erreur de creation de fichier\n");
        //fprintf(stdrr,"Erreur de creation de fichier",
    }
    else
    {
        for(nI=1; nI<=MATRICE_SOUS; nI++)
        {
          ligne(7);
          for(nJ=1; nJ<= MATRICE_SOUS; nJ++)
            if (matrice[nI][nJ]==1)
            {
                printf("|%c",'o');
                fputs("1 ", pFile);
            }
             else
             {
                 printf("|%c",'x');
                 fputs("0 ", pFile);
             }
//
          printf("|\n");
          fputc('\n', pFile);
       }
        ligne(MATRICE_SOUS);
        fclose(pFile);
    }
       /**for(nI=1; nI<=MATRICE_SOUS; nI++)
        {
          ligne(7);
          for(nJ=1; nJ<= MATRICE_SOUS; nJ++)
             if (matrice[nI][nJ]==1)
                printf("|%c",'o');

             else
                printf("|%c",'x');
          printf("|\n");
       }**/
    ligne(MATRICE_SOUS);
}

