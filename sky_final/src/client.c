#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "client.h"

enum
{	NOM,
	PRENOM,
	CIN,
	TELEPHONE,
	COLUMNS
};
void ajouter_client(client *cl)
{FILE *f=NULL;
FILE *fu=NULL;
f=fopen("client.txt","a+");
fu=fopen("user.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %s %s %s %s\n",cl->nom,cl->prenom,cl->cin,cl->tel,cl->login,cl->password);
strcpy(cl->role,"3");
}
if (fu!=NULL)
fprintf(fu,"%s %s %s \n",cl->login,cl->password,cl->role);
fclose(f);
fclose(fu);
}
void afficher_client(GtkWidget *treeview1)
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char cin[10];
char telephone[10];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview1);
if (store==NULL)
{renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" telephone",renderer, "text",TELEPHONE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview1),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("client.txt","r");
if (f==NULL)
{return;}
else
{f=fopen("client.txt","a+");
	while(fscanf(f,"%s %s %s %s\n",nom,prenom,cin,telephone)!=EOF)
		{gtk_list_store_append(store,&iter);
		 gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,TELEPHONE,telephone,-1);
		}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
