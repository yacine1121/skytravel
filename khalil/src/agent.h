#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct agent{
	char nom[20];
	char prenom[20];
	char cin[20];
	char login[20];
	char password[20];
	char tel[10];
	char role[20];
	}agent;
void ajouter_agent(agent *ag);
void afficher_agent(GtkWidget *treeview1);
int is_exist_agent(char login[100]);
int is_exist1_agent(char cin[100]);
void enregistrer_agent(agent *ag);
int supprimer_agent(char CIN[]);
int modifier_agent(agent *ag);
int verifier_agent(char login[], char password[]);
int modifier_agent1(agent *ag);
void modifier_user_agent(char login[],char password[]);
int verification1(char login[], char password[]);
