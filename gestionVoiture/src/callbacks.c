#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"affichage.h"
#include"crud.h"

void
on_button1d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *Acceuil;
GtkWidget *window1;
Acceuil=lookup_widget(button,"Acceuil");
gtk_widget_destroy(Acceuil);
gtk_widget_hide(Acceuil);
window1=create_window1();
gtk_widget_show(window1);

}


void
on_button4d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cal1;
GtkWidget *cal2;
GtkWidget *comboboxMarque;



GtkWidget *labelsuccess;
GtkWidget *labelMarque;
GtkWidget *labelCIN;
GtkWidget *labelMatricule;
GtkWidget *labelExist;
FILE*f=NULL;
voiture v;
int jj1,mm1,aa1,jj2,mm2,aa2,b=1;


labelMarque=lookup_widget(gestion_voiture,"label64d");
labelCIN=lookup_widget(gestion_voiture,"label61d");
labelMatricule=lookup_widget(gestion_voiture,"label11d");
labelExist=lookup_widget(gestion_voiture,"label10d");
labelsuccess=lookup_widget(gestion_voiture,"label9d");



comboboxMarque=lookup_widget(gestion_voiture,"combobox7d");




cal1=lookup_widget(gestion_voiture,"calendar1d");
cal2=lookup_widget(gestion_voiture,"calendar2d");
           gtk_widget_hide (labelsuccess);

strcpy(v.cin,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_voiture,"entry4d"))));
strcpy(v.matricule,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_voiture,"entry1d"))));

if(strcmp(v.cin,"")==0){
                gtk_widget_show (labelCIN);
b=0;

}else
{
           gtk_widget_hide (labelCIN);
}
if(strcmp(v.matricule,"")==0){
                gtk_widget_show (labelMatricule);
b=0;

}else
{
           gtk_widget_hide (labelMatricule);
}




if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxMarque))==-1){
                gtk_widget_show (labelMarque);
b=0;
}
else{

           gtk_widget_hide (labelMarque);
}



if(b==1){
v.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_voiture,"spinbutton2d")));
v.NbVoiture =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_voiture,"spinbutton6d")));
strcpy(v.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxMarque)));


gtk_calendar_get_date (GTK_CALENDAR(cal1),
                       &aa1,
                       &mm1,
                       &jj1);
gtk_calendar_get_date (GTK_CALENDAR(cal2),
                       &aa2,
                       &mm2,
   
                    &jj2);




if(exist_voiture(v.matricule)==1) {

                gtk_widget_show (labelExist);

}
else{
           gtk_widget_hide (labelExist);

f=fopen("voitures.txt","a+");
fprintf(f,"%s %s %s %d/%d/%d %d/%d/%d %d %d\n",v.cin,v.matricule,v.marque,jj1,mm1+1,aa1,jj2,mm2+1,aa2,v.prix,v.NbVoiture);
fclose(f);
                gtk_widget_show (labelsuccess);


//mise a jour du treeView
GtkWidget *p;
p=lookup_widget(gestion_voiture,"treeview1d");
Afficher_Voiture(p,"voitures.txt");



}

}


void
on_button8d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

  GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *labelSelection;
        GtkWidget *labelInvalid;
        GtkWidget *labelsuccess;
        gchar* matricule;
        gchar* marque;
        gchar* date_location;
        gchar* date_retour;
        int prix,x1,nbVoiture,nbV;
        gchar* cin;
	voiture v;
        labelSelection=lookup_widget(gestion_voiture,"label77d");
        labelInvalid=lookup_widget(gestion_voiture,"label78d");
        labelsuccess=lookup_widget(gestion_voiture,"label81d");
        p=lookup_widget(gestion_voiture,"treeview1d");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
                gtk_tree_model_get (model,&iter,0,&cin,1,&matricule,2,&marque,3,&date_location,4,&date_retour,5,&prix,6,&nbVoiture,-1);//recuperer les information de la ligne selectionneé
		//remplissage du structure Voiture
		strcpy(v.cin,cin);
		strcpy(v.matricule,matricule);
		strcpy(v.marque,marque);
		strcpy(v.date_location,date_location);
		strcpy(v.date_retour,date_retour);
		v.prix=prix;
		v.NbVoiture=nbVoiture;
		nbV =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_voiture,"spinbutton5")));



		if(v.NbVoiture<nbV){

		gtk_widget_show (labelInvalid);

		}else
		{
		gtk_widget_hide(labelInvalid);


		louer_voiture(v,nbV);
		gtk_widget_show (labelsuccess);
		supprimer_voiture(v.matricule);
		v.NbVoiture-=nbV;
		ajouter_voiture( v);
		//mise a jour du treeView
		Afficher_Voiture(lookup_widget(gestion_voiture,"treeview1d"),"voitures.txt");



	 	gtk_widget_hide (labelSelection); }

	}else{

                gtk_widget_show (labelSelection);
        }

}


void
on_button5d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* matricule;
        gchar* cin;
        label=lookup_widget(gestion_voiture,"label77d");
        p=lookup_widget(gestion_voiture,"treeview1d");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&cin,1,&matricule,-1);//recuperer les infos de la ligne selectionnée
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_voiture(matricule);// supprimer la ligne du fichier

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }
}


void
on_button6d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{ GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        GtkWidget *labelsuccess;
        gchar* matricule;
        gchar* marque;
        gchar* date_location;
        gchar* date_retour;
        int prix,x1,nbVoiture;
        gchar* cin;
        label=lookup_widget(gestion_voiture,"label77d");
        labelsuccess=lookup_widget(gestion_voiture,"label33d");
        p=lookup_widget(gestion_voiture,"treeview1d");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
                gtk_tree_model_get (model,&iter,0,&cin,1,&matricule,2,&marque,3,&date_location,4,&date_retour,5,&prix,6,&nbVoiture,-1);//recuperer les information de la ligne selectionneé

		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_voiture,"label30d")),matricule);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_voiture,"entry5d")),cin);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_voiture,"entry2d")),date_location);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_voiture,"entry3d")),date_retour);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_voiture,"spinbutton4d")),prix);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_voiture,"spinbutton7d")),nbVoiture);
		/* comparer la valeur du marque et sauvegarder lindice du combobox pour l'activer (1er choix ==> indice 0)*/
	   	if(strcmp(marque,"BMW")==0)	x1=0;		
                if(strcmp(marque,"Audi")==0) x1=1;                
                if(strcmp(marque,"Chevrolet")==0)  x1=2 ; 
                if(strcmp(marque,"Citroen")==0)  x1=3 ; 
                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_voiture,"combobox8d")),x1);
           	gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(gestion_voiture,"notebook1d")));//redirection vers la page suivante
                gtk_widget_show(lookup_widget(gestion_voiture,"button7d"));//afficher le bouton confirmer
	gtk_widget_hide (labelsuccess);
           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }

}


void
on_button7d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

	voiture v;
        strcpy(v.matricule,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_voiture,"label30d"))));
        strcpy(v.cin,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_voiture,"entry5d"))));
        strcpy(v.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_voiture,"combobox8d"))));
        strcpy(v.date_location,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_voiture,"entry2d"))));
        strcpy(v.date_retour,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_voiture,"entry3d"))));
        v.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_voiture,"spinbutton4d")));
        v.NbVoiture =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_voiture,"spinbutton7d")));

        supprimer_voiture(v.matricule);
        ajouter_voiture(v);
        Afficher_Voiture(lookup_widget(gestion_voiture,"treeview1dd"),"voitures.txt");
        GtkWidget* msg=lookup_widget(gestion_voiture,"label33d");
        gtk_widget_show(msg);
}


void
on_button9d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelMarque;
GtkWidget *nbResultat;
GtkWidget *message;
char marque[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion_voiture,"entry6d");
labelMarque=lookup_widget(gestion_voiture,"label72d");
p1=lookup_widget(gestion_voiture,"treeview2");

strcpy(marque,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(marque,"")==0){
  gtk_widget_show (labelMarque);b=0;
}else{
b=1;
gtk_widget_hide (labelMarque);}

if(b==0){return;}else{

nb=ChercherVoiture(p1,"voitures.txt",marque);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestion_voiture,"label73d");
message=lookup_widget(gestion_voiture,"label74d");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);


}


}


void
on_button2d_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *gestion_voiture;
GtkWidget *window1;
gestion_voiture=lookup_widget(button,"gestion_voiture");
gtk_widget_destroy(window1);
window1=create_window1();
gtk_widget_show(window1);

}




void
on_button10d_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
{GtkWidget *window1;
GtkWidget *p;
GtkWidget *p1;
voiture v;
window1=lookup_widget(button,"window1");
gtk_widget_destroy(window1);
gtk_widget_hide (Acceuil);
gestion_voiture = create_gestion_voiture ();
p=lookup_widget(gestion_voiture,"treeview1d");
p1=lookup_widget(gestion_voiture,"treeview2d");

i=0;
j=0;

Afficher_Voiture(p,"voitures.txt");
Afficher_Voiture2(p1,"voitures.txt");
gtk_widget_show (gestion_voiture);
}


void
on_button11d_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1, *window2;

GtkWidget *p ;
//GTKWidget *p1;
voiture v;
window1=lookup_widget(button,"window1");
gtk_widget_destroy(window1);
window2=create_window2();
p=lookup_widget(window2,"treeview3d");
i=0;
Afficher_Voiture(p,"voitures.txt");
gtk_widget_show(window2);
}


void
on_button12d_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *Acceuil;
window1=lookup_widget(button,"window1");
gtk_widget_destroy(window1);
Acceuil=create_Acceuil();
gtk_widget_show(Acceuil)

}


void
on_button18d_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *labelSelection;
        GtkWidget *labelInvalid;
        GtkWidget *labelsuccess;
        gchar* matricule;
        gchar* marque;
        gchar* date_location;
        gchar* date_retour;
        int prix,x1,nbVoiture,nbV;
        gchar* cin;
	voiture v;
        labelSelection=lookup_widget(button,"label102d");
        labelInvalid=lookup_widget(button,"label104d");
        labelsuccess=lookup_widget(button,"label103d");
        p=lookup_widget(button,"treeview3d");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
                gtk_tree_model_get (model,&iter,0,&cin,1,&matricule,2,&marque,3,&date_location,4,&date_retour,5,&prix,6,&nbVoiture,-1);//recuperer les information de la ligne selectionneé
		//remplissage du structure Voiture
		strcpy(v.cin,cin);
		strcpy(v.matricule,matricule);
		strcpy(v.marque,marque);
		strcpy(v.date_location,date_location);
		strcpy(v.date_retour,date_retour);
		v.prix=prix;
		v.NbVoiture=nbVoiture;
		nbV =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(button,"spinbutton10d")));



		if(v.NbVoiture<nbV){

		gtk_widget_show (labelInvalid);

		}else
		{
		gtk_widget_hide(labelInvalid);


		louer_voiture(v,nbV);
		gtk_widget_show (labelsuccess);
		supprimer_voiture(v.matricule);
		v.NbVoiture-=nbV;
		ajouter_voiture( v);
		//mise a jour du treeView
		Afficher_Voiture(lookup_widget(button,"treeview3d"),"voitures.txt");



	 	gtk_widget_hide (labelSelection); }

	}else{

                gtk_widget_show (labelSelection);
        }




	

}


void
on_button13d_enter                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window2;
window2=lookup_widget(button,"window2");
gtk_widget_destroy(window2);
window1=create_window1();
gtk_widget_show(window1);

}

