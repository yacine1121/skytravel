#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<gtk/gtk.h>
#include "reclamation.h"

void ajouter_reclamation()
{
reclamation r,tmp;
char med[100];
fflush(stdin);
FILE *f=NULL;
int i=1;

f=fopen("reclamation.txt","r");
while (fscanf(f,"%s %s %s %s ",tmp.numero,tmp.login,tmp.type,tmp.etat)!=EOF)
i++;

fclose(f);
f=fopen("reclamation.txt","a+");
if(f!=NULL)
{printf("saisissez le login ");
scanf("%s",r.login);

printf("saisissez le type "); 
scanf("%s",r.type);
printf("saisissez le cont ");
fgets(med,100,stdin);
printf("%s",med);
strcpy(r.cont,med);
strcpy(r.etat,"non_traitee ");
sprintf(r.numero,"%d",i);


fprintf(f,"%s %s %s %s \n",r.numero,r.login,r.type,r.etat);



}
fclose(f);
char fich[30];
strcat(r.numero,".txt");
strcpy(fich,r.numero);

printf("%s",fich);
f=fopen(fich,"a+");
fprintf(f,"%s",r.cont);
fclose(f);

};

void afficher_reclamation(GtkWidget *treeview1)
{
reclamation r;
FILE *f=NULL;



GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL;


//fflush(stdin);
store=gtk_tree_view_get_model(treeview5);

if (store!=NULL)
{renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("r.numero",renderer, "text",numero,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview5),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("r.login",renderer, "text",login,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview5),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("r.type",renderer, "text",type,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview5),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("r.etat",renderer, "text",etat,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview5),column);
}
//
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);
f=fopen("reclamation.txt","r");
if(f!=NULL)
{f=fopen("reclamation.txt","a+");
	while(fscanf(f,"%s %s %s %s \n",r.numero,r.login,r.type,r.etat)!=EOF)
	{
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,numero,r.numero,login,r.login,type,r.type,etat,r.etat,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview5), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
//
}
int supprimer_reclamation(char numero[])
{FILE *f=NULL,*ftmp=NULL;
reclamation tmp;
fflush(stdin);
int a=0;
int i=1;
char nouvnum[20];
f=fopen("reclamation.txt","r+");
 ftmp=fopen("rectmp.txt","a+");
if (f!=NULL)
{while (fscanf(f,"%s %s %s %s",tmp.numero,tmp.login,tmp.type,tmp.etat)!=EOF)
	{if (strcmp(numero,tmp.numero)!=0){
	sprint(nouvnum,"%d",i);
	strcat(nouvnum,".txt");
	fprintf(ftmp,"%s %s %s %s\n",nouvnum,tmp.login,tmp.type,tmp.etat);
	strcat(tmp.numero,".txt");
	rename(tmp.numero,nouvnum);
	i++;}
	else{strcat(tmp.numero,".txt");
		remove(tmp.numero);
		a=1;}

}
fclose(ftmp);
fclose(f);
remove("reclamation.txt");
rename("rectmp.txt","reclamation.txt");


return (a);
}
};
int modifier_reclamation(char numero[],char nouvcont[] )
{FILE *f=NULL; 
fflush(stdin);
int a=0;
strcat(numero,".txt");
remove(numero);
f=fopen(numero,"a+");
if(f!=NULL){
fprintf(f"%s ",nouvcont);
a=1;
}
fclose(f);
}
return (a);

};
void recherche(char numero[])
{ FILE *f;

remove(recherche.txt)
 f=fopen("recherche.txt","a+");
 fprintf(f,"%s",numero);
fclose(f);
}



