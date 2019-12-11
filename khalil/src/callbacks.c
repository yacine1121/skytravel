#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"
#include "agent.h"


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *window4;
window1=lookup_widget(objet,"window1");
gtk_widget_destroy(window1);
window4=create_window4();
gtk_widget_show(window4);
}


void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *window3;
window1=lookup_widget(objet,"window1");
gtk_widget_destroy(window1);
window3=create_window3();
gtk_widget_show(window3);
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
GtkWidget *window2, *window4;
window2=lookup_widget(objet,"window2");
gtk_widget_destroy(window2);
window4=create_window4();
gtk_widget_show(window4);
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
a=verification1(login,password);
switch (a)
{case 1:
if(verification1(login,password)==1)
	{user=lookup_widget(objet,"window10");
        
	user=create_window10();
	gtk_widget_hide_all(window3);
	gtk_widget_show(user);}
break;
case 3:
	user=lookup_widget(objet,"window5");
	user=create_window5();
	gtk_widget_hide_all(window3);
	gtk_widget_show(user);
break;
case 2:
	window3=lookup_widget(objet,"window3");
	user=create_window25();
	gtk_widget_hide_all(window3);
	gtk_widget_show(user);
break; 
default:
	{GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL(output),"verifier vos donnees");}
break;

}
}




void
on_button10_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3, *window1;
window3=lookup_widget(objet,"window3");
gtk_widget_destroy(window3);
window1=create_window1();
gtk_widget_show(window1);
}


void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window4, *window1;
window4=lookup_widget(objet,"window4");
gtk_widget_destroy(window4);
window1=create_window1();
gtk_widget_show(window1);
}


void
on_button18_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5, *window9;
window5=lookup_widget(objet,"window5");
gtk_widget_destroy(window5);
window9=create_window9();
gtk_widget_show(window9);
}


void
on_button30_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window9, *window5;
window9=lookup_widget(objet,"window9");
gtk_widget_destroy(window9);
window5=create_window5();
gtk_widget_show(window5);
}


void
on_button29_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window9, *window3;
window9=lookup_widget(objet,"window9");
gtk_widget_destroy(window9);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button31_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
char error[100]; int v=0; char succes[100]; int t=0,t1=0,t3=0,length,i;
char login[30],password[30];

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;

GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;

GtkWidget *window9;

output= lookup_widget(objet, "label17");//alerte al kol
output1= lookup_widget(objet, "label159");//Ancien mot de passe
output2= lookup_widget(objet, "label160");//nouveau tel
output3= lookup_widget(objet, "label143");//login

//fflush(stdin);
gtk_label_set_text(GTK_LABEL (output), "");
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");


window9=lookup_widget(objet,"window9");


input1=lookup_widget(objet,"entry11");//login
strcpy(c.login,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry48");//ancient mod de passe
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"entry42");//nouveau nom
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet,"entry43");//nouveau prenom
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet,"entry13");//nouveau num tel
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet,"entry12");//nouveau mod de passe
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(input6)));

strcpy(login,c.login);

length = strlen (c.tel);
if((length>8) || (length<8))
{
t1=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(c.tel[i])==0)
        {
            t1=1;break;
        }}}
if ((strcmp(c.nom,"")==0) || (strcmp(c.prenom,"")==0) || (strcmp(password,"")==0)  || (strcmp(c.login,"")==0) || (strcmp(c.password,"")==0) || (strcmp(c.tel,"")==0))
{v=1;
strcpy(error,"veuillez remplir tous les champs");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), error);
}
if ((is_exist_client(c.login)!=1 )&&(strcmp(c.login,"")!=0)){
        t3=1;
	strcpy(error,"Login inexistant !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output3, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output3), error);
	} 
if ((is_exist_client(c.login)==1 )&&verifier(login,password)!=1){
        t3=1;
	strcpy(error,"Ce mot de passe ne correspond pas au login saisis");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), error);
	} 


if ((t1 == 1 )&&(strcmp(c.tel,"")!=0)) {
strcpy(error,"Le numero telephonique doit\netre un numero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}


if ((v==0) && (t1==0) && (t3==0)){
modifier_client1(&c);
modifier_user_client(login,c.password);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), "données modifiées avec succées!");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");
}

}


void
on_button33_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window10, *window11;
window10=lookup_widget(objet,"window10");
gtk_widget_destroy(window10);
window11=create_window11();
gtk_widget_show(window11);
GtkWidget *treeview1;
treeview1=lookup_widget(window11,"treeview3");
afficher_agent(treeview1);
}


void
on_button35_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window10, *window16;

window10=lookup_widget(objet,"window10");
gtk_widget_destroy(window10);
window16=create_window16();
gtk_widget_show(window16);
GtkWidget *treeview1;
treeview1=lookup_widget(window16,"treeview4");
afficher_client(treeview1);
}


void
on_button34_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button36_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window10, *window24;
window10=lookup_widget(objet,"window10");
gtk_widget_destroy(window10);
window24=create_window24();
gtk_widget_show(window24);
}


void
on_button39_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window11, *window12;
window11=lookup_widget(objet,"window11");
gtk_widget_destroy(window11);
window12=create_window12();
gtk_widget_show(window12);
}


void
on_button38_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window11, *window14;
window11=lookup_widget(objet,"window11");
gtk_widget_destroy(window11);
window14=create_window14();
gtk_widget_show(window14);
}


void
on_button40_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window11, *window10;
window11=lookup_widget(objet,"window11");
gtk_widget_destroy(window11);
window10=create_window10();
gtk_widget_show(window10);
}


void
on_button37_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window11, *window3;
window11=lookup_widget(objet,"window11");
gtk_widget_destroy(window11);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button41_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window11, *window15;
window11=lookup_widget(objet,"window11");
gtk_widget_destroy(window11);
window15=create_window15();
gtk_widget_show(window15);
}


void
on_button43_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char error[100]; int v=0; char succes[100]; int t=0,t1=0,t3=0,length,i;
agent a;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;


GtkWidget *window12;


GtkWidget *comboboxentry2;


GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;

window12=lookup_widget(objet,"window12");
input1=lookup_widget(objet,"entry17");
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry16");
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"entry15");
strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet,"entry18");
strcpy(a.tel,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet,"entry14");
strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet,"entry19");
strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(input6)));


comboboxentry2= lookup_widget(objet, "comboboxentry2");
strcpy(a.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));


output= lookup_widget(objet, "label127");
output1= lookup_widget(objet, "label137");//CIN
output2= lookup_widget(objet, "label138");//tel
output3= lookup_widget(objet, "label139");//login


gtk_label_set_text(GTK_LABEL (output), "");
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");


length = strlen (a.cin);
if((length>8) ||(length<8 ))
{
t=1;   
} else 
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(a.cin[i])==0)
        {
            t=1;break;
        }}}
length = strlen (a.tel);
if((length>8) || (length<8))
{
t1=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(a.tel[i])==0)
        {
            t1=1;break;
        }}}
if ((strcmp(a.nom,"")==0) || (strcmp(a.prenom,"")==0) || (strcmp(a.cin,"")==0)  || (strcmp(a.login,"")==0) || (strcmp(a.password,"")==0) || (strcmp(a.tel,"")==0)||(strcmp(a.role,"")==0))
{v=1;
strcpy(error,"veuillez remplir tous les champs");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), error);
}
if (is_exist_agent(a.login)==1 ){
        t3=1;
	strcpy(error,"Login existe deja !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output3, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output3), error);
	} 
if (t == 1 ) {
strcpy(error,"Le numero C.I.N doit etre un \nnumero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output1), error);
}
if (is_exist1_agent(a.cin)==1 ){
        t=1;
	strcpy(error,"CIN deja existant !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), error);
	strcpy(succes,"");
	gtk_label_set_text(GTK_LABEL (output2), succes);
}
if (t1 == 1 ) {
strcpy(error,"Verifier votre numero \ntelephonique");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}

if (strcmp(a.role,"Admin")==0)
strcpy(a.role,"1");
else if (strcmp(a.role,"Agent")==0)
strcpy(a.role,"2");
if ((t==0) && (v==0) && (t1==0) && (t3==0)){
ajouter_agent(&a);
enregistrer_agent(&a);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), "Agent ajouté avec succées");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");
}

}


void
on_button42_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window11, *window3;
window11=lookup_widget(objet,"window11");
gtk_widget_destroy(window11);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button44_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window11, *window12;
window12=lookup_widget(objet,"window12");
gtk_widget_destroy(window12);
window11=create_window11();
gtk_widget_show(window11);
GtkWidget *treeview1;
treeview1=lookup_widget(window11,"treeview3");
afficher_agent(treeview1);
}




void
on_button49_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char error[100];
agent ag;
int length,i,t=0,t1=0,t2=0,v=0;
GtkWidget *input1;
GtkWidget *input2;

GtkWidget *output3;
GtkWidget *output1;
GtkWidget *output2;


GtkWidget *window14;
window14=lookup_widget(objet,"window14");

input1=lookup_widget(objet,"entry40");
strcpy(ag.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry21");
strcpy(ag.tel,gtk_entry_get_text(GTK_ENTRY(input2)));

output1= lookup_widget(objet, "label144");//cin
output2= lookup_widget(objet, "label39");//alerte
output3= lookup_widget(objet, "label163");//tel

strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);


length=strlen(ag.cin);
if((length>8) || (length<8))
{
t=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(ag.cin[i])==0)
        {
            t=1;break;
        }}}
length = strlen (ag.tel);
if((length>8) || (length<8))
{
t2=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(ag.tel[i])==0)
        {
            t2=1;break;
        }}}
if ((strcmp(ag.tel,"")==0)||(strcmp(ag.cin,"")==0))
{v=1;
strcpy(error,"veuillez remplir tous les champs");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}

if ((is_exist1_agent(ag.cin)!=1 )&&(v==0)&&(t==0)){
        t1=1;
	strcpy(error,"Agent non existant");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), error);
}

if ((t2 == 1 )&&(v==0)) {
strcpy(error,"le numero telephonique doit etre un\nnumero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output3, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output3), error);
}
if ((t == 1 )&&(v==0)) {
strcpy(error,"le numero CIN doit etre un\nnumero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output1), error);
}
if ((t==0) && (v==0) && (t1==0) && (t2==0)){
modifier_agent(&ag);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), "Succées de la modification");
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");
}
}


void
on_button50_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window14, *window11;
window14=lookup_widget(objet,"window14");
gtk_widget_destroy(window14);
window11=create_window11();
gtk_widget_show(window11);
GtkWidget *
treeview1;
treeview1=lookup_widget(window11,"treeview3");
afficher_agent(treeview1);
}


void
on_button48_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window14, *window3;
window14=lookup_widget(objet,"window14");
gtk_widget_destroy(window14);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button51_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window15, *window3;
window15=lookup_widget(objet,"window15");
gtk_widget_destroy(window15);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button53_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char CIN[10],error[100];
int a=0;
int length,t=0,t1=0,i,v=0;
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *window15;
window15=lookup_widget(objet,"window15");
input1=lookup_widget(objet,"entry22");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
output1= lookup_widget(objet, "label162");
output2= lookup_widget(objet, "label42");

strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);


length = strlen (CIN);
if((length>8) ||(length<8 ))
{
t=1;   
} else 
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(CIN[i])==0)
        {
            t=1;break;
        }}}
if ((strcmp(CIN,"")==0))
{v=1;
strcpy(error,"veuillez saisir le numero de la CIN");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output1), error);
}

if ((t == 1 )&&(v==0)) {
strcpy(error,"CIN invalide");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}
if ((is_exist1_agent(CIN)!=1)&&(strcmp(CIN,"")!=0)&&(t==0)){
        t=1;
	strcpy(error,"Agent non existant !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output2), error);
	
}


if ((t==0) && (v==0)){
supprimer_agent(CIN);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output1), "succées de la suppression");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
}
}


void
on_button52_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window15, *window11;
window15=lookup_widget(objet,"window15");
gtk_widget_destroy(window15);
window11=create_window11();
gtk_widget_show(window11);
GtkWidget *treeview1;
treeview1=lookup_widget(window11,"treeview3");
afficher_agent(treeview1);
}


void
on_button57_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window16, *window19;
window16=lookup_widget(objet,"window16");
gtk_widget_destroy(window16);
window19=create_window19();
gtk_widget_show(window19);
}


void
on_button56_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window16, *window18;
window16=lookup_widget(objet,"window16");
gtk_widget_destroy(window16);
window18=create_window18();
gtk_widget_show(window18);
}


void
on_button55_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window16, *window10;
window16=lookup_widget(objet,"window16");
gtk_widget_destroy(window16);
window10=create_window10();
gtk_widget_show(window10);
}


void
on_button54_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window16, *window3;
window16=lookup_widget(objet,"window16");
gtk_widget_destroy(window16);
window3=create_window3();
gtk_widget_show(window3);
}






void
on_button62_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char error[100];
client ct;
int length,i,t=0,t1=0,t2=0,v=0;
GtkWidget *input1;
GtkWidget *input2;

GtkWidget *output3;
GtkWidget *output1;
GtkWidget *output2;


GtkWidget *window18;
window18=lookup_widget(objet,"window18");

input1=lookup_widget(objet,"entry41");
strcpy(ct.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry24");
strcpy(ct.tel,gtk_entry_get_text(GTK_ENTRY(input2)));

output1= lookup_widget(objet, "label145");//cin
output2= lookup_widget(objet, "label48");//alerte
output3= lookup_widget(objet, "label157");//tel

strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);


length=strlen(ct.cin);
if((length>8) || (length<8))
{
t=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(ct.cin[i])==0)
        {
            t=1;break;
        }}}
length = strlen (ct.tel);
if((length>8) || (length<8))
{
t2=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(ct.tel[i])==0)
        {
            t2=1;break;
        }}}
if ((strcmp(ct.tel,"")==0)||(strcmp(ct.cin,"")==0))
{v=1;
strcpy(error,"veuillez remplir tous les champs");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}

if ((is_exist1_client(ct.cin)!=1 )&&(v==0)&&(t==0)){
        t1=1;
	strcpy(error,"Client non existant");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), error);
}

if ((t2 == 1 )&&(v==0)) {
strcpy(error,"le numero telephonique doit etre un\nnumero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output3, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output3), error);
}
if ((t == 1 )&&(v==0)) {
strcpy(error,"le numero CIN doit etre un\nnumero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output1), error);
}
if ((t==0) && (v==0) && (t1==0) && (t2==0)){
modifier_client(&ct);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), "Succées de la modification");
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");
}

}


void
on_button63_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window18, *window16;
window18=lookup_widget(objet,"window18");
gtk_widget_destroy(window18);
window16=create_window16();
gtk_widget_show(window16);
GtkWidget *treeview1;
treeview1=lookup_widget(window16,"treeview4");
afficher_client(treeview1);
}


void
on_button61_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window18, *window3;
window18=lookup_widget(objet,"window18");
gtk_widget_destroy(window18);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button66_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window19, *window16;
window19=lookup_widget(objet,"window19");
gtk_widget_destroy(window19);
window16=create_window16();
gtk_widget_show(window16);
GtkWidget *treeview1;
treeview1=lookup_widget(window16,"treeview4");
afficher_client(treeview1);
}


void
on_button64_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window19, *window3;
window19=lookup_widget(objet,"window19");
gtk_widget_destroy(window19);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button65_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char CIN[10],error[100];
int a=0;
int length,t=0,t1=0,i,v=0;
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *window19;
window19=lookup_widget(objet,"window19");
input1=lookup_widget(objet,"entry25");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
output1= lookup_widget(objet, "label49");
output2= lookup_widget(objet, "label155");

strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);


length = strlen (CIN);
if((length>8) ||(length<8 ))
{
t=1;   
} else 
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(CIN[i])==0)
        {
            t=1;break;
        }}}
if ((strcmp(CIN,"")==0))
{v=1;
strcpy(error,"veuillez saisir le numero de la CIN");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output1), error);
}

if ((t == 1 )&&(v==0)) {
strcpy(error,"CIN invalide");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}
if ((is_exist1_client(CIN)!=1)&&(strcmp(CIN,"")!=0)&&(t==0)){
        t=1;
	strcpy(error,"Client non existant !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output2), error);
	
}


if ((t==0) && (v==0)){
supprimer_client(CIN);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output1), "succées de la suppression");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
}




}


void
on_button81_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
agent a;
char error[100]; int v=0; char succes[100]; int t=0,t1=0,t3=0,length,i;
char login[30],password[30];

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;

GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;

GtkWidget *window24;

output= lookup_widget(objet, "label59");//alerte al kol
output1= lookup_widget(objet, "label168");//Ancien mot de passe
output2= lookup_widget(objet, "label169");//nouveau tel
output3= lookup_widget(objet, "label148");//login

//fflush(stdin);
gtk_label_set_text(GTK_LABEL (output), "");
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");


window24=lookup_widget(objet,"window24");


input1=lookup_widget(objet,"entry30");//login
strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry50");//ancient mod de passe
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"entry44");//nouveau nom
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet,"entry45");//nouveau prenom
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet,"entry29");//nouveau num tel
strcpy(a.tel,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet,"entry28");//nouveau mod de passe
strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(input6)));

strcpy(login,a.login);

length = strlen (a.tel);
if((length>8) || (length<8))
{
t1=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(a.tel[i])==0)
        {
            t1=1;break;
        }}}
if ((strcmp(a.nom,"")==0) || (strcmp(a.prenom,"")==0) || (strcmp(password,"")==0)  || (strcmp(a.login,"")==0) || (strcmp(a.password,"")==0) || (strcmp(a.tel,"")==0))
{v=1;
strcpy(error,"veuillez remplir tous les champs");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), error);
}
if ((is_exist_agent(a.login)!=1 )&&(strcmp(a.login,"")!=0)){
        t3=1;
	strcpy(error,"Login inexistant !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output3, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output3), error);
	} 
if ((is_exist_agent(a.login)==1 )&&verifier_agent(login,password)!=1){
        t3=1;
	strcpy(error,"Ce mot de passe ne correspond pas au login saisis");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), error);
	} 


if ((t1 == 1 )&&(strcmp(a.tel,"")!=0)) {
strcpy(error,"Le numero telephonique doit\netre un numero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}


if ((v==0) && (t1==0) && (t3==0)){
modifier_agent1(&a);
modifier_user_agent(login,a.password);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), "données modifiées avec succées!");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");
}
}


void
on_button80_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window24, *window10;
window24=lookup_widget(objet,"window24");
gtk_widget_destroy(window24);
window10=create_window10();
gtk_widget_show(window10);
}


void
on_button82_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window24, *window3;
window24=lookup_widget(objet,"window24");
gtk_widget_destroy(window24);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button83_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window25, *window26;
window25=lookup_widget(objet,"window25");
gtk_widget_destroy(window25);
window26=create_window26();
gtk_widget_show(window26);
}


void
on_button89_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
agent a;
char error[100]; int v=0; char succes[100]; int t=0,t1=0,t3=0,length,i;
char login[30],password[30];

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;

GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;

GtkWidget *window26;

output= lookup_widget(objet, "label66");//alerte al kol
output1= lookup_widget(objet, "label165");//Ancien mot de passe
output2= lookup_widget(objet, "label166");//nouveau tel
output3= lookup_widget(objet, "label153");//login

//fflush(stdin);
gtk_label_set_text(GTK_LABEL (output), "");
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");


window26=lookup_widget(objet,"window26");


input1=lookup_widget(objet,"entry31");//login
strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry49");//ancient mod de passe
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"entry47");//nouveau nom
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet,"entry46");//nouveau prenom
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet,"entry33");//nouveau num tel
strcpy(a.tel,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet,"entry32");//nouveau mod de passe
strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(input6)));

strcpy(login,a.login);

length = strlen (a.tel);
if((length>8) || (length<8))
{
t1=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(a.tel[i])==0)
        {
            t1=1;break;
        }}}
if ((strcmp(a.nom,"")==0) || (strcmp(a.prenom,"")==0) || (strcmp(password,"")==0)  || (strcmp(a.login,"")==0) || (strcmp(a.password,"")==0) || (strcmp(a.tel,"")==0))
{v=1;
strcpy(error,"veuillez remplir tous les champs");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), error);
}
if ((is_exist_agent(a.login)!=1 )&&(strcmp(a.login,"")!=0)){
        t3=1;
	strcpy(error,"Login inexistant !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output3, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output3), error);
	} 
if ((is_exist_agent(a.login)==1 )&&verifier_agent(login,password)!=1){
        t3=1;
	strcpy(error,"Ce mot de passe ne correspond pas au login saisis");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), error);
	} 


if ((t1 == 1 )&&(strcmp(a.tel,"")!=0)) {
strcpy(error,"Le numero telephonique doit\netre un numero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}


if ((v==0) && (t1==0) && (t3==0)){
modifier_agent1(&a);
modifier_user_agent(login,a.password);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), "données modifiées avec succées!");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");
}
}


void
on_button88_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window26, *window25;
window26=lookup_widget(objet,"window26");
gtk_widget_destroy(window26);
window25=create_window25();
gtk_widget_show(window25);
}


void
on_button90_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window26, *window3;
window26=lookup_widget(objet,"window26");
gtk_widget_destroy(window26);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_buttonAfficher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2, *window3;
window2=lookup_widget(objet,"window2");
gtk_widget_destroy(window2);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button14_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
char error[100]; int v=0; char succes[100]; int t=0,t1=0,t3=0,length,i;

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;

GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;

GtkWidget *window4;

output= lookup_widget(objet, "label130");
output1= lookup_widget(objet, "label134");//CIN
output2= lookup_widget(objet, "label136");//tel
output3= lookup_widget(objet, "label135");//login


gtk_label_set_text(GTK_LABEL (output), "");
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");


window4=lookup_widget(objet,"window4");


input1=lookup_widget(objet,"entry4");
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry5");
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"entry6");
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet,"entry9");
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet,"entry7");
strcpy(c.login,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet,"entry8");
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(input6)));


length = strlen (c.cin);
if((length>8) ||(length<8 ))
{
t=1;   
} else 
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(c.cin[i])==0)
        {
            t=1;break;
        }}}
length = strlen (c.tel);
if((length>8) || (length<8))
{
t1=1;   
} else
 	{
         for (i=0;i<length; i++)		
	{
        if (isdigit(c.tel[i])==0)
        {
            t1=1;break;
        }}}
if ((strcmp(c.nom,"")==0) || (strcmp(c.prenom,"")==0) || (strcmp(c.cin,"")==0)  || (strcmp(c.login,"")==0) || (strcmp(c.password,"")==0) || (strcmp(c.tel,"")==0))
{v=1;
strcpy(error,"veuillez remplir tous les champs");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), error);
}
if (is_exist_client(c.login)==1 ){
        t3=1;
	strcpy(error,"Login existe deja !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output3, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output3), error);
	} 
if (t == 1 ) {
strcpy(error,"Le numero C.I.N doit etre un \nnumero de 8 chiffres");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output1), error);
}
if (is_exist1_client(c.cin)==1 ){
        t=1;
	strcpy(error,"CIN deja existant !!");
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), error);
	strcpy(succes,"");
	gtk_label_set_text(GTK_LABEL (output2), succes);
}
if (t1 == 1 ) {
strcpy(error,"Verifier votre numero \ntelephonique");
GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output2), error);
}


if ((t==0) && (v==0) && (t1==0) && (t3==0)){
ajouter_client(&c);
enregistrer_client(&c);
strcpy(error,"");
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL (output), "Compte crée avec succées");
gtk_label_set_text(GTK_LABEL (output1), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output2), error);
strcpy(error,"");
gtk_label_set_text(GTK_LABEL (output3), error);
strcpy(error,"");
}

}


void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5, *window3;
window5=lookup_widget(objet,"window5");
gtk_widget_destroy(window5);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window4, *window3;
window4=lookup_widget(objet,"window4");
gtk_widget_destroy(window4);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button32_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window10, *window3;
window10=lookup_widget(objet,"window10");
gtk_widget_destroy(window10);
window3=create_window3();
gtk_widget_show(window3);
}


void
on_button87_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window25, *window3;
window25=lookup_widget(objet,"window25");
gtk_widget_destroy(window25);
window3=create_window3();
gtk_widget_show(window3);
}

