#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include"facture.h"
enum 
{	NUM,
	MONTANT,
	CIN,
	DAJ,
	DAM,
	DAA,
	DFJ,
	DFM,
	DFA,
	COLUMNS
};

void ajouter_facturee(facturee p)
{FILE *f;
f=fopen("facture.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %s %d %d %d %d %d %d \n",p.nf,p.mont,p.cin,p.da.jour,p.da.mois,p.da.annee,p.df.jour,p.df.mois,p.df.annee);
fclose(f);
}
}

void afficher_facture(GtkWidget *treeview1)
{
 GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char num[30];
char montant[30];
char cin[30];
int daj;
int dam;
int daa;
int dfj;
int dfm;
int dfa;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview1);
if (store==NULL)
{renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" num",renderer, "text",NUM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" daj",renderer, "text",DAJ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" dam",renderer, "text",DAM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" daa",renderer, "text",DAA,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" dfj",renderer, "text",DFJ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" dfm",renderer, "text",DFM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" dfa",renderer, "text",DFA,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen("facture.txt","r");
if(f==NULL)
{return;}
else
{f=fopen("facture.txt","a+");
	while(fscanf(f,"%s %s %s %d %d %d %d %d %d \n",num,montant,cin,&daj,&dam,&daa,&dfj,&dfm,&dfa)!=EOF)
	{
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,NUM,num,MONTANT,montant,CIN,cin,DAJ,daj,DAM,dam,DAA,daa,DFJ,dfj,DFM,dfm,DFA,dfa,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}
void supprimer_facture(char*num){
FILE*f=NULL;
FILE*f1=NULL;
 facturee v;
f=fopen("facture.txt","r");

f1=fopen("facture1.txt","w+");
while(fscanf(f,"%s %s %s %d %d %d %d %d %d \n",v.nf,v.mont,v.cin,&v.da.jour,&v.da.mois,&v.da.annee,&v.df.jour,&v.df.mois,&v.df.annee)!=EOF)
{
if(strcmp(num,v.nf)!=0)
fprintf(f1,"%s %s %s %d %d %d %d %d %d \n",v.nf,v.mont,v.cin,v.da.jour,v.da.mois,v.da.annee,v.df.jour,v.df.mois,v.df.annee);
}
fclose(f);
fclose(f1);
remove("facture.txt");
rename("facture1.txt","facture.txt");
}
void modifier_facture(char*num,facturee p){
FILE*f=NULL;
FILE*f1=NULL;
 facturee v;
f=fopen("facture.txt","r");

f1=fopen("facture1.txt","w+");
while(fscanf(f,"%s %s %s %d %d %d %d %d %d \n",v.nf,v.mont,v.cin,&v.da.jour,&v.da.mois,&v.da.annee,&v.df.jour,&v.df.mois,&v.df.annee)!=EOF)
{
if(strcmp(num,v.nf)!=0)
fprintf(f1,"%s %s %s %d %d %d %d %d %d \n",v.nf,v.mont,v.cin,v.da.jour,v.da.mois,v.da.annee,v.df.jour,v.df.mois,v.df.annee);
else
fprintf(f1,"%s %s %s %d %d %d %d %d %d \n",p.nf,p.mont,p.cin,p.da.jour,p.da.mois,p.da.annee,p.df.jour,p.df.mois,p.df.annee);
}
fclose(f);
fclose(f1);
remove("facture.txt");
rename("facture1.txt","facture.txt");

}


int exist_facture(char*num){
 FILE*f=NULL;
 facturee v;
int k;
k=0;
f=fopen("facture.txt","r");
while(fscanf(f,"%s %s %s %d %d %d %d %d %d \n",v.nf,v.mont,v.cin,&v.da.jour,&v.da.mois,&v.da.annee,&v.df.jour,&v.df.mois,&v.df.annee)!=EOF)
{
if(strcmp(num,v.nf)==0) k=1; 
}
return (k);
fclose(f);
}

