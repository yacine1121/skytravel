#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include "facture.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_button113_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window33");
gtk_widget_destroy(fenetre_afficher);
}


void
on_button116_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window33");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_window34();
gtk_widget_show(fenetre_ajout);
}


void
on_button114_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button115_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"window33");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"window38");
fenetre_afficher=create_window38();
gtk_widget_show(fenetre_afficher);
}


void
on_button120_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"window34");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"window35");
fenetre_afficher=create_window35();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview9");
afficher_facture(treeview1);
}


void
on_button119_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
facturee p;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_ajout=lookup_widget(objet,"window34");
input1=lookup_widget(objet,"entry40");
strcpy(p.nf,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry44");
strcpy(p.mont,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"entry43");
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));


input4=lookup_widget(objet,"aj");
p.da.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input4));
input5=lookup_widget(objet,"am");
p.da.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input5));
input6=lookup_widget(objet,"aa");
p.da.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input6));

input7=lookup_widget(objet,"fj");
p.df.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input7));
input8=lookup_widget(objet,"fm");
p.df.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input8));
input9=lookup_widget(objet,"fa");
p.df.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input9));


ajouter_facturee(p);
}


void
on_button117_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window34");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_window33();
gtk_widget_show(fenetre_ajout);
}


void
on_button118_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window34");
gtk_widget_destroy(fenetre_afficher);
}


void
on_button122_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window35");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_window34();
gtk_widget_show(fenetre_ajout);
}


void
on_button123_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
fenetre_ajout=lookup_widget(objet,"window35");
gtk_widget_destroy(fenetre_ajout);
}


void
on_button125_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"window36");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"window37");
fenetre_afficher=create_window37();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview10");
afficher_facture(treeview1);
}


void
on_button126_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{facturee p;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;
GtkWidget *input10;
char num[30];

GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_ajout=lookup_widget(objet,"window36");
input1=lookup_widget(objet,"entry45");
strcpy(p.nf,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry47");
strcpy(p.mont,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"entry46");
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));

input4=lookup_widget(objet,"spinbutton1");
p.da.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input4));
input5=lookup_widget(objet,"spinbutton2");
p.da.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input5));
input6=lookup_widget(objet,"spinbutton3");
p.da.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input6));

input7=lookup_widget(objet,"spinbutton4");
p.df.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input7));
input8=lookup_widget(objet,"spinbutton5");
p.df.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input8));
input9=lookup_widget(objet,"spinbutton6");
p.df.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input9));


ajouter_facturee(p);

}


void
on_button127_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window36");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_window38();
gtk_widget_show(fenetre_ajout);
}


void
on_button128_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window36");
gtk_widget_destroy(fenetre_afficher);
}

void
on_button129_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window37");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_window36();
gtk_widget_show(fenetre_ajout);
}

void
on_button134_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char num[30];
int x;
GtkWidget *fenetre_ajout, *fenetre_afficher;
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *window2;
fenetre_afficher=lookup_widget(objet_graphique,"window38");
input1=lookup_widget(objet_graphique,"entry48");
output1=lookup_widget(objet_graphique,"label165");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
x=exist_facture(num);
if (x==1)
{
supprimer_facture(num);
window2 = create_window36();
gtk_widget_show (window2);

}
else
{
gtk_label_set_text(GTK_LABEL(output1),"Wrong informations ! repeat again please.");
}
}

void
on_button131_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
fenetre_ajout=lookup_widget(objet,"window38");
gtk_widget_destroy(fenetre_ajout);
}


void
on_button130_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window37");
gtk_widget_destroy(fenetre_afficher);
}


void
on_button135_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char num[30];
int x;
GtkWidget *fenetre_ajout, *fenetre_afficher;
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *window2;
fenetre_afficher=lookup_widget(objet_graphique,"window38");
input1=lookup_widget(objet_graphique,"entry48");
output1=lookup_widget(objet_graphique,"label165");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
x=exist_facture(num);
if (x==1)
{
supprimer_facture(num);
gtk_label_set_text(GTK_LABEL(output1),"facture suprimee");
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"Wrong informations ! repeat again please.");
}
}


void
on_button132_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"window38");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_window33();
gtk_widget_show(fenetre_ajout);
}

