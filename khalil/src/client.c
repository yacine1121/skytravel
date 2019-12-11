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
f=fopen("client.txt","a+");
if (f!=NULL)
{strcpy(cl->role,"3");
fprintf(f,"%s %s %s %s %s %s %s\n",cl->nom,cl->prenom,cl->cin,cl->tel,cl->login,cl->password,cl->role);
}
fclose(f);
}
////////////////////////////
void afficher_client(GtkWidget *treeview1)
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char cin[10];
char telephone[10];
char login[20];
char password[20];
char role[20];
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
	while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,prenom,cin,telephone,login,password,role)!=EOF)
		{gtk_list_store_append(store,&iter);
		 gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,TELEPHONE,telephone,-1);
		}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
/////////////////////////////////////
int is_exist_client(char login[100])
{int test=0;
client cl;
FILE *f;
f=fopen("user.txt","r+");
if(f!=NULL)
    {
	while(fscanf(f,"%s %s %s\n",cl.login,cl.password,cl.role)!= EOF)
        {

            if(strcmp(login,cl.login)==0)
            {
		
			test=1;
	    }
	}
   }
return test;
}
/////////////////////////////////////////
int is_exist1_client(char cin[100])
{int test=0;
client cl;
FILE *f;
f=fopen("client.txt","r+");
if(f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s %s %s\n",cl.nom,cl.prenom,cl.cin,cl.tel,cl.login,cl.password,cl.role)!= EOF)
        {

            if(strcmp(cin,cl.cin)==0)
            {
		
			test=1;
	    }
	}
   }


return test;
}
////////////////////////
void enregistrer_client(client *cl)
{
FILE *f=NULL;
    f=fopen("user.txt","a+");
    if(f!=NULL)
{ strcpy(cl->role,"3");
fprintf(f,"%s %s %s \n",cl->login,cl->password,cl->role);
}
fclose(f);
}
//////////////////////////////
int supprimer_client(char CIN[])
{FILE *f=NULL,*ftemp=NULL;
client c1;
client c2;
char COMP[10];
int a=0,b=0;
f=fopen("client.txt","r+");
 ftemp=fopen("client.txt.temp","a+");
if (f!=NULL)
{while (fscanf(f,"%s%s%s%s%s%s%s",c1.nom,c1.prenom,c1.cin,c1.tel,c1.login,c1.password,c1.role)!=EOF)
	{if (strcmp(CIN,c1.cin)!=0)
	fprintf(ftemp,"%s %s %s %s %s %s %s\n",c1.nom,c1.prenom,c1.cin,c1.tel,c1.login,c1.password,c1.role);
	else if(strcmp(CIN,c1.cin)==0)
		{a=1;
		 strcpy(COMP,c1.login);
		}
		
	}
}

fclose(f);
fclose(ftemp);
remove("client.txt");
rename("client.txt.temp","client.txt");

f=fopen("user.txt","r+");
ftemp=fopen("user.txt.temp","a+");
if (f!=NULL)
{while (fscanf(f,"%s%s%s",c2.login,c2.password,c2.role)!=EOF)
{
if (strcmp(COMP,c2.login)!=0)
fprintf(ftemp,"%s %s %s\n",c2.login,c2.password,c2.role);
else if(strcmp(COMP,c2.login)!=0)
b=1;
}
}
fclose(f);
fclose(ftemp);
remove("user.txt");
rename("user.txt.temp","user.txt");
return (a);
}
int modifier_client(client *cl)
{FILE *f=NULL,*ftemp=NULL;
client c1;
int a=0;
f=fopen("client.txt","r+");
 ftemp=fopen("client.txt.temp","a+");
if (f!=NULL)
{while (fscanf(f,"%s%s%s%s%s%s%s",c1.nom,c1.prenom,c1.cin,c1.tel,c1.login,c1.password,c1.role)!=EOF)
	{if (strcmp(cl->cin,c1.cin)!=0)
	fprintf(ftemp,"%s %s %s %s %s %s %s\n",c1.nom,c1.prenom,c1.cin,c1.tel,c1.login,c1.password,c1.role);
	else if(strcmp(cl->cin,c1.cin)==0)
		{fprintf(ftemp,"%s %s %s %s %s %s %s\n",c1.nom,c1.prenom,c1.cin,cl->tel,c1.login,c1.password,c1.role);
		a=1;}
}
fclose(ftemp);
fclose(f);
remove("client.txt");
rename("client.txt.temp","client.txt");
return (a);
}
}
///////////////
int verifier(char login[], char password[])
{client cv;
int test=0;

FILE *f;
f=fopen("client.txt","r+");
if(f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s %s %s\n",cv.nom,cv.prenom,cv.cin,cv.tel,cv.login,cv.password,cv.role)!= EOF)
        {if  ((strcmp(login,cv.login)==0) && (strcmp(password,cv.password)==0))
		test=1;
	}
     }
fclose(f);
return test;
}
//////////
int modifier_client1(client *cl)
{FILE *f=NULL,*ftemp=NULL;
client c1;
int a=0;
f=fopen("client.txt","r+");
 ftemp=fopen("client.txt.temp","a+");
if (f!=NULL)
{while (fscanf(f,"%s%s%s%s%s%s%s",c1.nom,c1.prenom,c1.cin,c1.tel,c1.login,c1.password,c1.role)!=EOF)
	{if (strcmp(cl->login,c1.login)!=0)
	fprintf(ftemp,"%s %s %s %s %s %s %s\n",c1.nom,c1.prenom,c1.cin,c1.tel,c1.login,c1.password,c1.role);
	else if(strcmp(cl->login,c1.login)==0)
		{fprintf(ftemp,"%s %s %s %s %s %s %s\n",cl->nom,cl->prenom,c1.cin,cl->tel,c1.login,cl->password,c1.role);
		a=1;}
}
fclose(ftemp);
fclose(f);
remove("client.txt");
rename("client.txt.temp","client.txt");
return (a);
}
}
//////////
void modifier_user_client(char login[],char password[])
{
char log[30],pass[30],role[5];
FILE *f=NULL;
FILE *ftemp=NULL;
    f=fopen("user.txt","r+");
    ftemp=fopen("user.txt.temp","a+");
    if(f!=NULL)
{while(fscanf(f,"%s%s%s",log,pass,role)!=EOF)
	{if(strcmp(login,log)!=0)
		fprintf(ftemp,"%s %s %s\n",log,pass,role);
	else if (strcmp(login,log)==0)
		fprintf(ftemp,"%s %s %s\n",login,password,role);
	}
}
fclose(ftemp);
fclose(f);
remove("user.txt");
rename("user.txt.temp","user.txt");
}
