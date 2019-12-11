#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "agent.h"
enum
{	NOM,
	PRENOM,
	CIN,
	TELEPHONE,
	COLUMNS
};
void ajouter_agent(agent *ag)
{FILE *f=NULL;
f=fopen("agent.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %s %s %s %s %s\n",ag->nom,ag->prenom,ag->cin,ag->tel,ag->login,ag->password,ag->role);
}
fclose(f);
}
///////////////
void afficher_agent(GtkWidget *treeview1)
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
char role[10];
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
f=fopen("agent.txt","r");
if (f==NULL)
{return;}
else
{f=fopen("agent.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,prenom,cin,telephone,login,password,role)!=EOF)
		{gtk_list_store_append(store,&iter);
		 gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,TELEPHONE,telephone,-1);
		}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
/////////////////
void enregistrer_agent(agent *ag)
{
FILE *f=NULL;
    f=fopen("user.txt","a+");
    if(f!=NULL)
{fprintf(f,"%s %s %s \n",ag->login,ag->password,ag->role);
}
fclose(f);
}
///////////////////
int is_exist_agent(char login[100])
{int test=0;
agent ag;
FILE *f;
f=fopen("user.txt","r+");
if(f!=NULL)
    {
	while(fscanf(f,"%s %s %s \n",ag.login,ag.password,ag.role)!= EOF)
        {

            if(strcmp(login,ag.login)==0)
            {
		
			test=1;
	    }
	}
   }
return test;
}
////////////////////////
int is_exist1_agent(char cin[100])
{int test=0;
agent ag;
FILE *f;
f=fopen("agent.txt","r+");
if(f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s %s %s\n",ag.nom,ag.prenom,ag.cin,ag.tel,ag.login,ag.password,ag.role)!= EOF)
        {

            if(strcmp(cin,ag.cin)==0)
            {
		
			test=1;
	    }
	}
   }


return test;
}
////////////
int supprimer_agent(char CIN[])
{FILE *f=NULL,*ftemp=NULL;
agent a1;
agent a2;
char COMP[10];
int a=0,b=0;
f=fopen("agent.txt","r+");
 ftemp=fopen("agent.txt.temp","a+");
if (f!=NULL)
{while (fscanf(f,"%s%s%s%s%s%s%s",a1.nom,a1.prenom,a1.cin,a1.tel,a1.login,a1.password,a1.role)!=EOF)
	{if (strcmp(CIN,a1.cin)!=0)
	fprintf(ftemp,"%s %s %s %s %s %s %s\n",a1.nom,a1.prenom,a1.cin,a1.tel,a1.login,a1.password,a1.role);
	else if(strcmp(CIN,a1.cin)==0)
		{a=1;
		 strcpy(COMP,a1.login);
		}
		
	}
}

fclose(f);
fclose(ftemp);
remove("agent.txt");
rename("agent.txt.temp","agent.txt");

f=fopen("user.txt","r+");
ftemp=fopen("user.txt.temp","a+");
if (f!=NULL)
{while (fscanf(f,"%s%s%s",a2.login,a2.password,a2.role)!=EOF)
{
if (strcmp(COMP,a2.login)!=0)
fprintf(ftemp,"%s %s %s\n",a2.login,a2.password,a2.role);
else if(strcmp(COMP,a2.login)!=0)
b=1;
}
}
fclose(f);
fclose(ftemp);
remove("user.txt");
rename("user.txt.temp","user.txt");
return (a);
}
///////////////////////
int modifier_agent(agent *ag)
{FILE *f=NULL,*ftemp=NULL;
agent a1;
int a=0;
f=fopen("agent.txt","r+");
 ftemp=fopen("agent.txt.temp","a+");
if (f!=NULL)
{while (fscanf(f,"%s%s%s%s%s%s%s",a1.nom,a1.prenom,a1.cin,a1.tel,a1.login,a1.password,a1.role)!=EOF)
	{if (strcmp(ag->cin,a1.cin)!=0)
	fprintf(ftemp,"%s %s %s %s %s %s %s\n",a1.nom,a1.prenom,a1.cin,a1.tel,a1.login,a1.password,a1.role);
	else if(strcmp(ag->cin,a1.cin)==0)
		{fprintf(ftemp,"%s %s %s %s %s %s %s\n",a1.nom,a1.prenom,a1.cin,ag->tel,a1.login,a1.password,a1.role);
		a=1;}
}
fclose(ftemp);
fclose(f);
remove("agent.txt");
rename("agent.txt.temp","agent.txt");
return (a);
}
}
////////////////////
int verifier_agent(char login[], char password[])
{agent av;
int test=0;

FILE *f;
f=fopen("agent.txt","r+");
if(f!=NULL)
    {
	while(fscanf(f,"%s %s %s %s %s %s %s\n",av.nom,av.prenom,av.cin,av.tel,av.login,av.password,av.role)!= EOF)
        {if  ((strcmp(login,av.login)==0) && (strcmp(password,av.password)==0))
		test=1;
	}
     }
fclose(f);
return test;
}
////////////////////////
int modifier_agent1(agent *ag)
{FILE *f=NULL,*ftemp=NULL;
agent a1;
int a=0;
f=fopen("agent.txt","r+");
 ftemp=fopen("agent.txt.temp","a+");
if (f!=NULL)
{while (fscanf(f,"%s%s%s%s%s%s%s",a1.nom,a1.prenom,a1.cin,a1.tel,a1.login,a1.password,a1.role)!=EOF)
	{if (strcmp(ag->login,a1.login)!=0)
	fprintf(ftemp,"%s %s %s %s %s %s %s\n",a1.nom,a1.prenom,a1.cin,a1.tel,a1.login,a1.password,a1.role);
	else if(strcmp(ag->login,a1.login)==0)
		{fprintf(ftemp,"%s %s %s %s %s %s %s\n",ag->nom,ag->prenom,a1.cin,ag->tel,a1.login,ag->password,a1.role);
		a=1;}
}
fclose(ftemp);
fclose(f);
remove("agent.txt");
rename("agent.txt.temp","agent.txt");
return (a);
}
}
//////////
void modifier_user_agent(char login[],char password[])
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
//////////////////////
int verification1(char login[],char password[])
{
FILE *f;
char log[30];
char pass[30];
int role;
f=fopen("user.txt","r");
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

