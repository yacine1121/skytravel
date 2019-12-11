#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct client{
		char nom[30];
		char prenom[30];
		char cin[10];
		char login[20];
		char password[20];
		char tel[10];
		char role[5];
		}client;
void ajouter_client(client *cl);
void afficher_client(GtkWidget *treeview1);
int is_exist_client(char login[100]);
int is_exist1_client(char cin[100]);
void enregistrer_client(client *cl);
int supprimer_client(char CIN[]);
int modifier_client(client *cl);
int verifier(char login[], char password[]);
int modifier_client1(client *cl);
void modifier_user_client(char login[],char password[]);
