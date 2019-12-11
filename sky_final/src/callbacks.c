#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"
#include "reclamation.h"


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input11;
GtkWidget *input22;
GtkWidget *output;
GtkWidget *window3;
GtkWidget *window10;
GtkWidget *user;
FILE *f;
char login[30];
char password[30];
int a;
input11=lookup_widget(objet,"entry2");
strcpy(login,gtk_entry_get_text(GTK_ENTRY(input11)));
input22=lookup_widget(objet,"entry3");
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input22)));
output=lookup_widget(objet,"label4");
window3=lookup_widget(objet,"window3");

f=fopen("historique","a+");
fprintf(f,"%s \n",login);
fclose(f);
a=verification(login,password);
switch (a)
{case 1:
if(verification(login,password)==1)
	{user=lookup_widget(objet,"window10");
        
	user=create_window10();
	gtk_widget_hide_all(window3);
	gtk_widget_show(user);}
break;
case 2:
	user=lookup_widget(objet,"window5");
	user=create_window5();
	gtk_widget_hide_all(window3);
	gtk_widget_show(user);
break;
/*case 3:
	window3=lookup_widget(objet,"window3");
	user=create_agent();
	gtk_widget_hide_all(window3);
	gtk_widget_show(user);
break; */
default:
	gtk_label_set_text(GTK_LABEL(output),"verifier vos donnees");
break;

}}


void
on_button10_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button18_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button30_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button29_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button31_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button33_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button35_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button34_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data){
GtkWidget *window20;
GtkWidget *window10;
GtkWidget *treeview5;

window10=lookup_widget(objet,"window10");
gtk_widget_destroy(window10);
window20=lookup_widget(objet,"window20");
window20 = create_window20 ();
//gtk_widget_hide(window8);


treeview5=lookup_widget(window20,"treeview5");
afficher_reclamation(treeview5);
gtk_widget_show (window20);



}


void
on_button36_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button39_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button38_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button40_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button37_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button41_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button43_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button42_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button44_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button47_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button46_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button45_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button49_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button50_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button48_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button51_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button53_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button52_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button57_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button56_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button55_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button54_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button58_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button59_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button60_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button62_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button63_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button61_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button66_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button64_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button65_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}





void
on_button82_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button83_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button89_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button88_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f;
reclamation r;
GtkWidget *window8;
GtkWidget *window500;
GtkWidget *output1;
char tamp[500];
char user[30];
int i;
f=fopen("historique","r");
while(fscanf(f,"%s \n",user)!=EOF)
{fscanf(f,"%s \n",user);}
fclose (f);
f=fopen("reclamation.txt","r");
while(fscanf(f,"%s %s %s %s",r.numero,r.login,r.type,r.etat)!=EOF){
if(strcmp(r.login,user)==0)
break;}

fclose(f);
//integration login1

window8=lookup_widget(objet,"window8");
gtk_widget_destroy(window8);
window500=lookup_widget(objet,"window500");
output1=lookup_widget(objet,"label128");
window500 = create_window500 ();
gtk_widget_show (window500);
//gtk_widget_hide(window8);

if(strcmp(r.etat,"traitee")==0){
f=fopen(r.numero,"r");
fgets(tamp,500,f);
fclose(f);}
else 
strcpy(tamp,"non_traitee");
gtk_label_set_text(GTK_LABEL(output1),tamp);



}


void
on_button90_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_buttonAfficher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button19_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{ GtkWidget *window5,*window8;
window8=lookup_widget(objet,"window8");
window8 = create_window8 ();
//gtk_widget_hide(window5);
gtk_widget_show (window8);  
window5=lookup_widget(objet,"window5");
gtk_widget_destroy(window5);
}


void
on_button28_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget  *window8,*window5;
window8=lookup_widget(objet,"window8");
gtk_widget_destroy(window8);
window5=lookup_widget(objet,"window5");
window5 = create_window5 ();
//gtk_widget_hide(window8);
gtk_widget_show (window5);

}


void
on_button26_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window3,*window8;
window8=lookup_widget(objet,"window8");
gtk_widget_destroy(window8);
window3=lookup_widget(objet,"window3");
window3 = create_window3 ();
//gtk_widget_hide(window8);
gtk_widget_show (window3);
}


void
on_button27_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window5,*window8,*comboboxentry1,*input1entry10,*windowmessage;
 reclamation r,tmp;
 int i=1;
FILE *f=NULL;




comboboxentry1=lookup_widget(objet, "comboboxentry1");
strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
input1entry10=lookup_widget(objet,"entry10");
strcpy(r.cont,gtk_entry_get_text(GTK_ENTRY(input1entry10)));
strcpy(r.etat,"non_traitee");
char user[30];
f=fopen("historique","r");
while(fscanf(f,"%s ",user)!=EOF)
{fscanf(f,"%s \n",user);}
fclose (f);
strcpy(r.login,user);


f=fopen("reclamation.txt","r");
while (fscanf(f,"%s %s %s %s ",tmp.numero,tmp.login,tmp.type,tmp.etat)!=EOF)
i++;
fclose(f);
sprintf(r.numero,"%d",i);

f=fopen("reclamation.txt","a+");



if(f!=NULL)
fprintf(f,"%s %s %s %s \n",r.numero,r.login,r.type,r.etat);

fclose(f);

f=fopen(r.numero,"a+");
if(f!=NULL)
fprintf(f,"%s",r.cont);
fclose(f);


window5=lookup_widget(objet,"window5");
windowmessage=lookup_widget(objet,"windowmessage");
windowmessage=create_windowmessage();
window8=lookup_widget(objet,"window8");
gtk_widget_show (windowmessage);
window5 = create_window5 ();
gtk_widget_destroy(window8);
gtk_widget_show (window5);

}


void
on_button67_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window3,*window20;
window20=lookup_widget(objet,"window20");
gtk_widget_destroy(window20);
window3=lookup_widget(objet,"window3");
window3 = create_window3 ();
//gtk_widget_hide(window20);
gtk_widget_show (window3);

}


void
on_button68_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window22,*window20;
window20=lookup_widget(objet,"window20");
gtk_widget_destroy(window20);
window22=lookup_widget(objet,"window22");
window22 = create_window22 ();
//gtk_widget_hide(window20);
gtk_widget_show (window22);

}


void
on_button69_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window10,*window20;
window20=lookup_widget(objet,"window20");
gtk_widget_destroy(window20);
window10=lookup_widget(objet,"window10");
window10 = create_window10 ();
//gtk_widget_hide(window20);
gtk_widget_show (window10);



}



void
on_button75_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window20,*window22;
GtkWidget *treeview5;

window22=lookup_widget(objet,"window22");
gtk_widget_destroy(window22);
window20=lookup_widget(objet,"window20");
window20 = create_window20 ();
//gtk_widget_hide(window8);


treeview5=lookup_widget(window20,"treeview5");
afficher_reclamation(treeview5);
gtk_widget_show (window20);

}
//mazel 
//
//
//
//
//
//
void
on_button71_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window22,*input,*output1,*output2,*output3;
//char *p;

char num[20];
FILE *f=NULL;
//GtkTextBuffer *pBuffer=NULL;
char buffer[500];
reclamation r,tmp;
		input=lookup_widget(objet,"entry26");
		output1=lookup_widget(objet,"label555");
		output2=lookup_widget(objet,"label577");
		output3=lookup_widget(objet,"label1311");


strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));

   

  
remove("recherchereclamation");
f=fopen("recherchereclamation","a+");
fprintf(f,"%s",num);
fclose(f);


f=fopen("reclamation.txt","r");

while (fscanf(f,"%s %s %s %s ",r.numero,r.login,r.type,r.etat)!=EOF)
if(strcmp(num,r.numero)==0)
break;
fclose(f);
f=fopen(num,"r");
if(f!=NULL){
fgets(buffer,500,f);
fclose(f);


gtk_label_set_text(GTK_LABEL(output1),r.login);
gtk_label_set_text(GTK_LABEL(output2),r.type);
gtk_label_set_text(GTK_LABEL(output3),buffer);
}


}


void
on_button73_clicked      (GtkWidget       *objet,      

                gpointer         user_data)
{GtkWidget *window3,*window22;
window22=lookup_widget(objet,"window22");
gtk_widget_destroy(window22);
window3=lookup_widget(objet,"window3");
window3 = create_window3 ();

gtk_widget_show (window3);

}
                     
             
void on_button74_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *windowverificationsupp;
windowverificationsupp=lookup_widget(objet,"windowverificationsupp");
windowverificationsupp = create_windowverificationsupp ();
gtk_widget_show (windowverificationsupp);



}


void
on_button76_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window22,*window23;
window22=lookup_widget(objet,"window22");
gtk_widget_destroy(window22);
window23=lookup_widget(objet,"window23");
window23 = create_window23 ();
//gtk_widget_hide(window22);
gtk_widget_show (window23);

}


void
on_button78_clicked      (GtkWidget       *objet,      

                gpointer         user_data)
{GtkWidget *window23,*window3;
window23=lookup_widget(objet,"window23");
gtk_widget_destroy(window23);
window3=lookup_widget(objet,"window3");
window3 = create_window3 ();
gtk_widget_show (window3);


}


void
on_button79_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *windowmessage;
GtkWidget *window23;
FILE*f=NULL;
FILE*f1=NULL;
reclamation r,tmp;
GtkWidget *input111;
input111=lookup_widget(objet,"entry27");
strcpy(r.cont,gtk_entry_get_text(GTK_ENTRY(input111)));

f=fopen("recherchereclamation","a+");
fscanf(f,"%s",r.numero);
fclose(f);
strcpy(r.etat,"traitee");
//dhib


f1=fopen("reclamation1.txt","a+");
f=fopen("reclamation.txt","r");
while (fscanf(f,"%s %s %s %s ",tmp.numero,tmp.login,tmp.type,tmp.etat)!=EOF)
{
if(strcmp(r.numero,tmp.numero)==0)
fprintf(f1,"%s %s %s %s \n",tmp.numero,tmp.login,tmp.type,r.etat);
else
fprintf(f1,"%s %s %s %s \n",tmp.numero,tmp.login,tmp.type,tmp.etat);
}

fclose(f1);
fclose(f);
remove("reclamation.txt");
rename("reclamation1.txt","reclamation.txt");

remove(r.numero);
f=fopen(r.numero,"a+");
fprintf(f,r.cont);
fclose(f);


//dhib


window23=lookup_widget(objet,"window23");
windowmessage=lookup_widget(objet,"windowmessage");
windowmessage = create_windowmessage ();
gtk_widget_show (windowmessage);
}


void
on_button77_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window23,*window22;
window22=lookup_widget(objet,"window23");
gtk_widget_destroy(window23);
window22=lookup_widget(objet,"window22");
window22 = create_window22 ();
//gtk_widget_hide(window23);
gtk_widget_show (window22);


}

void
on_button80_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *windowmessage,*window20,*window23;
char nv[20];
char numero[20];
FILE *f;

f=fopen("recherchereclamation","r");
fscanf(f,"%s",numero);
fclose(f);
remove(numero);
rename("tmpmodification",numero);

window23=lookup_widget(objet,"window23");
window20=lookup_widget(objet,"window20");
windowmessage=lookup_widget(objet,"windowmessage");



//modifier_reclamation(numero,nv);


windowmessage = create_windowmessage ();
gtk_widget_show (windowmessage);

GtkWidget *treeview5;


gtk_widget_destroy(window23);

window20 = create_window20 ();

treeview5=lookup_widget(window20,"treeview5");
afficher_reclamation(treeview5);
gtk_widget_show (window20);
}



void
on_button81_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *windowmessage,*window22,*window20;

char numero[20];
FILE*f;


f=fopen("recherchereclamation","r");
while(fscanf(f,"%s",numero)!=EOF);
fclose(f);

supprimer_reclamation(numero);
windowmessage=lookup_widget(objet,"windowmessage");
windowmessage = create_windowmessage ();
gtk_widget_show (windowmessage);

GtkWidget *treeview5;

window22=lookup_widget(objet,"window22");
gtk_widget_destroy(window22);
window20=lookup_widget(objet,"window20");
window20 = create_window20 ();

treeview5=lookup_widget(window20,"treeview5");
afficher_reclamation(treeview5);
gtk_widget_show (window20);
}


void
on_button85_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window8;
GtkWidget *window500;

window500=lookup_widget(objet,"window500");
gtk_widget_destroy(window500);
window8=lookup_widget(objet,"window8");
window8 = create_window8 ();
//gtk_widget_hide(window8);


gtk_widget_show (window8);


}


void
on_button84_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window3;
GtkWidget *window500;

window500=lookup_widget(objet,"window500");
gtk_widget_destroy(window500);
window3=lookup_widget(objet,"window3");
window3 = create_window3 ();
//gtk_widget_hide(window3);


gtk_widget_show (window3);


}



