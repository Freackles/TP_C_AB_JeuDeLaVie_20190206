#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED
#pragma once

//Macros
#define MATRICE_SOUS 7
#define MATRICE_SUR 9

//prototypes
extern void init(int matrice [][MATRICE_SUR ]);
extern int nombre_voisins (int matrice [][MATRICE_SUR ],int ligne, int colonne);
extern void mise_a_jour(int matrice[][MATRICE_SUR ]);
extern void affiche_matrice(int matrice [][MATRICE_SUR ], FILE * pFile);
extern void ligne(int largeur);
#endif // CELLULE_H_INCLUDED
