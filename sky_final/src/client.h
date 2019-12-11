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
