# include "biblio.h"

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
	
	
return 0;
	
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i])  );
			
			}


		
		return 1;
		}
}


int rechercherTitre(const T_Bibliotheque *ptrB){

	T_Titre Reche;
	lireChaine("TITRE RECHERCHE : ", Reche, MAX_TITRE );

	int i;
	int nbTitre=0;
	for (i=0;i<=ptrB->nbLivres;i++){
		if ( (strcmp(Reche,ptrB->etagere[i].titre)) == 0){ 
			afficherLivre( &(ptrB->etagere[i]));
			nbTitre=nbTitre+1;
		}
	}

	return nbTitre;
}


int rechercherAuteur(const T_Bibliotheque *ptrB){

	T_Aut Reche;
	lireChaine("AUTEUR RECHERCHE : ", Reche , MAX);

	int i;
	for (i=0;i<=ptrB->nbLivres;i++){
		if ( (strcmp(Reche,ptrB->etagere[i].auteur)) == 0){ 
			afficherLivre( &(ptrB->etagere[i]));
			return 1;
		}
	}
	return 0;
}


int supprimerLivre ( T_Bibliotheque *ptrB){

	T_Titre Reche;
	lireChaine("TITRE DU LIVRE A SUPPRIMER : ", Reche, MAX_TITRE);

	int i;
	int j;
	int y;
	int posSup[CAPACITE_BIBLIO];
	int rangP=0;
	int rep=-2;


	//Compte le nombre de livres trouvés et affiche les positions + affiche les livres
	printf("Livres trouvés : \n");
	for (i=0;i<=ptrB->nbLivres;i++){
		if ( (strcmp(Reche,ptrB->etagere[i].titre)) == 0){ 
			printf("pos - %d -",i);
			afficherLivre( &(ptrB->etagere[i]));
			posSup[rangP] = i;
			rangP++;
		}
	}

	//Si on trouve qu un seul livre on le supprime et on sort de la fonction
	if(rangP==1){
			for(j=posSup[rangP-1];j<ptrB->nbLivres;j++){
				ptrB->etagere[j] = ptrB->etagere[j+1];
			}
			ptrB->nbLivres--;
			return 1;

	}

	//choix de l utilisateur pour savoir quoi supprimer
	printf("Quel livre supprimer ? Taper -1 pour tout supprimer \n");
	scanf("%d",&rep);
	if (rep>=0){
		if(ptrB->nbLivres>0){
			for(j=rep;j<ptrB->nbLivres;j++){
				ptrB->etagere[j] = ptrB->etagere[j+1];
			}
			ptrB->nbLivres--;
			return 1;
		}
	}
	if (rep==-1){
		//printf("rangP vaut %d" , rangP);
		if (ptrB->nbLivres>0){
			for (i=0;i<rangP;i++){
				printf("valeur de posSup : %d \n" , posSup[i]);

				for(j=posSup[i];j<ptrB->nbLivres;j++){
					ptrB->etagere[j] = ptrB->etagere[j+1];
				}

				for(y=0;y<rangP;y++){
					posSup[y]=posSup[y]-1;
				}
			ptrB->nbLivres--;
			}
		}
		return 2;
	}
	return 0;
}


//Fonction supprimer qui marche
/*
int supprimerLivre ( T_Bibliotheque *ptrB){

	T_Titre Reche;
	lireChaine("TITRE DU LIVRE A SUPPRIMER : ", Reche, MAX_TITRE);

	int i;
	int j;
	int posSup=-1;

	for (i=0;i<=ptrB->nbLivres;i++){
		if ( (strcmp(Reche,ptrB->etagere[i].titre)) == 0){ 
			posSup = i;
		}
	}


	if(ptrB->nbLivres>0 && posSup>=0){
		for(j=posSup;j<=ptrB->nbLivres;j++){
			strcpy((ptrB->etagere[j].titre),(ptrB->etagere[j+1].titre));
			strcpy((ptrB->etagere[j].auteur),(ptrB->etagere[j+1].auteur));
		}
		ptrB->nbLivres--;
		return 1;

	}


	return 0;
}
*/


void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");



	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}



void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}


int emprunterLivre (T_Bibliotheque *ptrB){


	T_Titre LivreEmp;
	T_Emp NomEmp;
	T_Code RepCode;

	lireChaine("TITRE DU LIVRE A EMPRUNTER : ", LivreEmp, MAX_TITRE);

	int i;
	int rangP=0;
	int posSup[CAPACITE_BIBLIO];


	//Compte le nombre de livres trouvés et affiche les positions + affiche les livres
	printf("Livres trouvés : \n");
	for (i=0;i<=ptrB->nbLivres;i++){
		if ( (strcmp(LivreEmp,ptrB->etagere[i].titre)) == 0){ 
			printf("pos - %d -",i);
			afficherLivre( &(ptrB->etagere[i]));
			posSup[rangP] = i;
			rangP++;
		}
	}


	if (rangP==0){
		printf("La bibliothèque ne contient pas de livre avec ce titre");
		return 0;
	}

	if (rangP==1){
		lireChaine("NOM DE L EMPRUNTEUR : ", NomEmp, MAX);
		strcpy(ptrB->etagere[posSup[rangP-1]].emprunteur,NomEmp);
		return 1;

	}

	if (rangP>1){
		lireChaine("CODE DU LIVRE A EMPRUNTER", RepCode,MAX_CODE);
		lireChaine("NOM DE L EMPRUNTEUR : ", NomEmp, MAX);

		for (i=0;i<ptrB->nbLivres;i++){
			if (strcmp(ptrB->etagere[i].code,RepCode)==0)
			strcpy(ptrB->etagere[i].emprunteur,NomEmp);
		}

	}
	
	// if (strcmp(ptrB->etagere[rep].emprunteur,"")==0){
	// 	printf("vous pouvez emprunter le livre");

	// }



return 1;

}