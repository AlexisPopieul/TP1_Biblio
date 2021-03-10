#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("EDITEUR :", (ptrL->editeur ), MAX);
lireChaine("EMPRUNTEUR :", (ptrL->emprunteur ), MAX);
lireChaine("CODE :", (ptrL->code ), MAX_CODE);
printf("ANNEE : ");
scanf("%d" , &(ptrL->annee));
getchar();
}

void afficherLivre(const T_livre *ptrL)
{
printf("\n");
printf("********************");
printf("\n");
afficherChaine("TITRE :", (ptrL->titre));
printf("\n");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf("\n");
afficherChaine("EDITEUR :", (ptrL->editeur ));
printf("\n");
afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur ));
printf("\n");
afficherChaine("CODE :", (ptrL->code ));
printf("\n");
printf("ANNEE : %d",(ptrL->annee));
printf("\n");
printf("********************");
printf("\n");
}

