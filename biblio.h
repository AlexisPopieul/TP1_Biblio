#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque
#define zouzou 3

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherTitre(const T_Bibliotheque *ptrB);
int rechercherAuteur(const T_Bibliotheque *ptrB);
int supprimerLivre ( T_Bibliotheque *ptrB);

void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);

int emprunterLivre (T_Bibliotheque *ptrB);
int rendreLivre (T_Bibliotheque *ptrB);

void tri_titre(T_Bibliotheque  *ptrB);
void tri_auteur(T_Bibliotheque  *ptrB);
void tri_annee(T_Bibliotheque  *ptrB);
void passerEnMaj ( char* src, char*dest);

#endif