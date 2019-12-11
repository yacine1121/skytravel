#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reclamation.h"
#include<gtk/gtk.h>

enum 
{	NUMERO,
	LOGIN,
	TYPE,
	ETAT,
	COLUMNS
};

void ajouter_reclamation()
{
reclamation r,tmp;
char med[30];
char fich[30];
fflush(stdin);
FILE *f=NULL;
int i=1;


f=fopen("reclamation.txt","r");
while (fscanf(f,"%s %s %s %s ",tmp.numero,tmp.login,tmp.type,tmp.etat)!=EOF)
i++;

fclose(f);
/*f=fopen("reclamation.txt","a+");
if(f!=NULL)*/
printf("saisissez le login ");
scanf("%s",r.login);

printf("saisissez le type "); 
scanf("%s",r.type);
printf("saisissez le cont ");
fgets(med,100,stdin);
printf("%s",med);
strcpy(r.cont,med);
strcpy(r.etat,"non_traitee ");
sprintf(r.numero,"%d",i);
printf("saisissez le cont ");
fgets(r.cont,100,stdin);
strcpy(r.etat,"non_traitee ");
sprintf(r.numero,"%d",i);
f=fopen("reclamation.txt","a+");



if(f!=NULL)
fprintf(f,"%s %s %s %s \n",r.numero,r.login,r.type,r.etat);

fclose(f);

//

//
strcat(r.numero,".txt");
strcpy(fich,r.numero);


printf("%s",fich);
f=fopen(fich,"a+");
if(f!=NULL)
fprintf(f,"%s",r.cont);
fclose(f);

}




void afficher_reclamation(GtkWidget *treeview5)
{

 GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char numero[30];
char login[30];
char etat[30];
char type[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview5);
if (store==NULL)
{renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" numero",renderer, "text",NUMERO,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview5),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" login",renderer, "text",LOGIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview5),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" type",renderer, "text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview5),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" etat",renderer, "text",ETAT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(treeview5),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
f=fopen("reclamation.txt","r");
if(f==NULL)
{return;}
else
{f=fopen("reclamation.txt","a+");
	while(fscanf(f,"%s %s %s %s \n",numero,login,type,etat)!=EOF)
	{
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,NUMERO,numero,LOGIN,login,TYPE,type,ETAT,etat,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview5), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}




int supprimer_reclamation(char numero[])
{FILE *f=NULL,*ftmp=NULL;
reclamation tmp;
char tamp[20];
fflush(stdin);
int a=0,i=0;

f=fopen("reclamation.txt","r+");
 ftmp=fopen("rectmp.txt","a+");
if (f!=NULL)
{while (fscanf(f,"%s %s %s %s",tmp.numero,tmp.login,tmp.type,tmp.etat)!=EOF)
	{i++;
	if (strcmp(numero,tmp.numero)!=0){
	
	fprintf(ftmp,"%d %s %s %s\n",i,tmp.login,tmp.type,tmp.etat);
		sprintf(tamp,"%d",i);
      		rename(tmp.numero,tamp);}
	else{remove(numero);
		a=1; i--;}
	
}
fclose(ftmp);
fclose(f);
remove("reclamation.txt");

rename("rectmp.txt","reclamation.txt");


return (a);
}
}
int modifier_reclamation(char numero[],char nouvcont[] )
{FILE *f=NULL; 

int a=0;
remove(numero);

f=fopen(numero,"a+");
if(f!=NULL){
fprintf(f,"%s",nouvcont);
fclose(f);
a=1;}
return (a);

}
int verification(char login[],char password[])
{
FILE *f;
char log[30];
char pass[30];
int role;
f=fopen("users.txt","r");
        if (f!=NULL)
	{
             while(fscanf(f,"%s %s %d \n",log,pass,&role)!=EOF)   
		{
		 if ((strcmp(login,log)==0)&&(strcmp(password,pass)==0))
			break;
		else role=0;
		}
	}   
fclose(f);    
         
return(role);
     
 }





