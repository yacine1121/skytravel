#include <gtk/gtk.h>



typedef struct reclamation{
	char numero[20];
	char login[20];
	char type[20];
	char cont[500];
	char etat[20];
	
	}reclamation;
void ajouter_reclamation();
void recherche(char numero[]);
void afficher_reclamation(GtkWidget *treeview5);
void afficher_une_reclamation(char numero[]);
int supprimer_reclamation(char numero[]);
int modifier_reclamation(char numero[],char nouvcont[] );
int verification(char login[],char password[]);


