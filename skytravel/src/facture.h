#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
int jour;
int mois;
int annee;
}Datea;
typedef struct 
{
int jour;
int mois;
int annee;
}Datef;

typedef struct {
		char nf[20];
		char mont[20];
		char cin[30];
		Datea da;
		Datef df;
		}facturee;

void ajouter_facturee(facturee p);
void afficher_facture(GtkWidget *treeview1);
int exist_facture(char*num);
void supprimer_facture(char*num);
void modifier_facture(char*num,facturee p);
int exist_voiture(char*num);
