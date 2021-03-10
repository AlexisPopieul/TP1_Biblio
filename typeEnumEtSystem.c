#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ce programme illustre l'utilisation des types Ã©numÃ©rÃ©s
//la structure T_Emp mÃ©morise maintenant la date de l'emprunt 
// Cette date peut Ãªtre saisie par l''opÃ©rateur
// mais la date systÃ¨me peut etre rÃ©cupÃ©rÃ©e


# define MAX 20
# define MAX_TITRE 60
# define MAX_CODE 6

# define K_MaxTit MAX_TITRE
# define K_MaxEmp MAX

typedef char T_Titre[K_MaxTit];

typedef enum  {lundi,mardi,mercredi,jeudi,vendredi,samedi,dimanche} T_Jour; //lundi=0 mardi=1 etc...
typedef enum  {janvier,fevrier,mars,avril,mai,juin,juillet,aout,septembre,octobre,novembre,decembre} T_Mois;

typedef struct
{
char nomemprunteur[MAX];
T_Jour lejour;
int ladate;
T_Mois lemois;
int lannee;
}   T_Emp ;


typedef struct
{
//T_Code code; // code de reference du livre dans la biblio. 
// Attention il peut y avoir pluieurs livres de mÃªme titre (le code diffÃ¨rent dans ce cas)
T_Titre titre; // Titre du livre
// T_Aut auteur; // Nom de l'auteur
//T_Edit editeur; // Nom de l'editeur
//T_annee annee; // Annee de l'edition
T_Emp emprunteur; // Nom de l'emprunteur et date d'emprunt
}  T_livre;

//prototype
void lireDateSysteme(T_Emp *E);
void afficherLivre(T_livre *);

//////////////////////////////////////////////////////////////////////////////////////////////////////// main  
int main()
{
int i;
//pour le TP Bibliotheque, utilisation d'un type Ã©numÃ©rÃ© (pour la saisie de la date de l'emprunt
T_livre unlivre;

printf("\n veuillez saisir le titre du livre :");
scanf("%[^\n]s",unlivre.titre);getchar();

printf("\n veuillez saisir l emprunteur :");
scanf("%[^\n]s",unlivre.emprunteur.nomemprunteur);getchar();

/////////////////////////// saisie de la date en 4 temps
//1
/*
printf("\n quel est le jour de cet emprunt (0=lundi 1=mardi 2=mercredi 3=jeudi 4=vendredi 5 =samedi 6=dimanche)");
scanf("%d",&i);
unlivre.emprunteur.lejour=i;
//2
printf("\n quel est la date de cet emprunt :");
scanf("%d",&(unlivre.emprunteur.ladate));//getchar();
//3
printf("\n quel est le mois de cet emprunt : (0=janvier 1=fevrier 2=mars 3=avril 4=mai 5=juin .... 11=decembre)");
scanf("%d",&i);//getchar();
unlivre.emprunteur.lemois=i;
//4
printf("\n quel est l annee de cet emprunt :");
scanf("%d",&(unlivre.emprunteur.lannee));//getchar();
////////////////////////////////////////////////////////////// fin de la saisie de la date d'emprunt


*/

// ou encore :
 lireDateSysteme(&unlivre.emprunteur);



afficherLivre(&unlivre);

	

//lireDateSysteme();

printf("\n\n\n fin");
return 0;
}


void afficherLivre(T_livre *L)
{

char jour[13],mois[13];

printf("\n titre du livre : %s",L->titre);

printf("\n emprunteur du livre : %s",L->emprunteur.nomemprunteur);

printf("\n  emprunt realise le : ");
switch(L->emprunteur.lejour)
{
case 0 :  strcpy(jour,"lundi");break;
case 1 :  strcpy(jour,"mardi");break;
case 2 :  strcpy(jour,"mercredi");break;
case 3 :  strcpy(jour,"jeudi");break;
case 4 :  strcpy(jour,"vendredi");break;
case 5 :  strcpy(jour,"samedi");break;
case 6 :  strcpy(jour,"dimanche");break;

default : strcpy(jour,"jour inconnu");break;
}
printf("%s ",jour);

printf("%d ",L->emprunteur.ladate);


switch(L->emprunteur.lemois)
{
case 0 :  strcpy(mois,"janvier");break;
case 1 :  strcpy(mois,"fevrier");break;
case 2 :  strcpy(mois,"mars");break;
case 3 :  strcpy(mois,"avril");break;
case 4 :  strcpy(mois,"mai");break;
case 5 :  strcpy(mois,"juin");break;
case 6 :  strcpy(mois,"juillet");break;
case 7 :  strcpy(mois,"aout");break;
case 8 :  strcpy(mois,"septembre");break;
case 	9 :  strcpy(mois,"octobre");break;
case 10 :  strcpy(mois,"novembre");break;
case 11 :  strcpy(mois,"decembre");break;

default : strcpy(jour,"mois inconnu");break;
}
printf("%s ",mois);

printf("%d ",L->emprunteur.lannee);


}

void lireDateSysteme(T_Emp *E)
{
char j[9],m[10],h[9],mer[11],vir[2];
int d,a;


system("date > ladate"	);
FILE * fic=NULL;  // pointeur de fichier
fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

//ici , si fic vaut NULL, alors le fopen a indiquÃ©
//que le fichier ladate n'est pas accessible
if (fic!=NULL)
	{
	while(!feof(fic))	
		{
		fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);		
		if (!feof(fic)) 
			printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);		

		}
	fclose(fic);
	
if (strcmp(j,"lundi")==0) E->lejour=lundi;
if (strcmp(j,"mardi")==0) E->lejour=mardi;
if (strcmp(j,"mercredi")==0) E->lejour=mercredi;
if (strcmp(j,"jeudi")==0) E->lejour=jeudi;
if (strcmp(j,"vendredi")==0) E->lejour=vendredi;
if (strcmp(j,"samedi")==0) E->lejour=samedi;
if (strcmp(j,"dimanche")==0) E->lejour=dimanche;

E->ladate=d;

if (strcmp(m,"janvier")==0) E->lemois=janvier;
if (strcmp(m,"fevrier")==0) E->lemois=fevrier;
if (strcmp(m,"mars")==0) E->lemois=mars;
if (strcmp(m,"avril")==0) E->lemois=avril;
if (strcmp(m,"mai")==0) E->lemois=mai;
if (strcmp(m,"juin")==0) E->lemois=juin;
if (strcmp(m,"juillet")==0) E->lemois=juillet;
if (strcmp(m,"aout")==0) E->lemois=aout;
if (strcmp(m,"septembre")==0) E->lemois=septembre;
if (strcmp(m,"octobre")==0) E->lemois=octobre;
if (strcmp(m,"novembre")==0) E->lemois=novembre;
if (strcmp(m,"decembre")==0) E->lemois=decembre;


E->lannee=a;
	}
	else
	{
		printf("n souci avec la date systeme !!");
		
		//on range une date irrÃ©elle 
		E->lejour=dimanche;
		E->ladate=99;
		E->lemois=decembre;
		E->lannee=-999;


	}

}







