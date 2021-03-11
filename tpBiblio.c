// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

int menu()
{
	int choix;
// au programme du TP6 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP7 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- lister les livres disponibles "); 
// printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}



int main()
{
int reponse,chx;
T_Bibliotheque B; 
init( &B );

chargement(&B);

do
{
chx= menu();
switch(chx)
	{
	case  1 : reponse = ajouterLivre(   &B  );
				if (reponse==1)
					printf(" ajout reussi !!");
					else
					printf("impossible d ajouter (bibliotheque pleine)");
			break;

	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide");

			break;	

	case 3 : reponse = rechercherTitre(&B);
			if(reponse!=0){
				printf("Il y a %i livre(s) avec ce titre disponible",reponse);
			}
			else{
				printf("Aucun Livre avec ce titre disponible");
			}
			break;

	case 4 : reponse = rechercherAuteur(&B);
			if (reponse==1){
				printf("Voici la liste d'ouvrage(s) de cet auteur");
			}
			else{
				printf("La bibliothèque ne contient aucun livre de cet auteur");
			}
			break;

	case 5 : reponse = supprimerLivre(&B);
			if (reponse==1){
				printf("Un seul Livre a été supprimé");
			}
			if (reponse==2){
				printf("Tous les livres avec le nom sélectionné ont été supprimés");
			}
			if (reponse==0){
				printf("Echec de la suppresion");
			}
			break;

	case 6 : reponse = emprunterLivre(&B);
			if (reponse==0){
				printf("Echec de l'emprunt");
			}
			if (reponse==1){
				printf("L'emprunt a réussi");
			}
			
			break;

	case 7 : reponse = rendreLivre(&B);
			if (reponse==0){
				printf("Echec de la restitution livre(s)");
			}
			if (reponse==1){
				printf("La restitution livre(s) a réussi");
			}
			
			break;

	case 8 : tri_titre (&B);
			printf("On trie les livres par titre...");
			
			break;

	case 9 : tri_auteur (&B);
			printf("on trie les livres par auteur...");
			
			break;

	case 10 : tri_annee (&B);
			printf("On trie les livres pas année...");

			break;
	}

}while(chx!=0);


sauvegarde(&B);



return 0;

}