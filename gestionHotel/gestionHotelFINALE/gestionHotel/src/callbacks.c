#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"crud.h"


void
on_Acceuilgestion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuil;
GtkWidget *window1;

acceuil=lookup_widget(button,"acceuil");
gtk_widget_destroy (acceuil); 


window1=create_window1() ; 

gtk_widget_show(window1);






}


void
on_gestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window1,*gestion;
	gestion=lookup_widget(button,"gestion");
        gtk_widget_destroy (gestion);
 	window1=create_window1();

        gtk_widget_show (window1);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

 	gchar *nom;
        gchar *typeChambre;
        gchar *dateAdmission;
        gchar *dateSortie;
        gint prix;
        gint nbChambre;

        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&nom,1,&typeChambre,2,&dateAdmission,3,&dateSortie,4,&nbChambre,5,&prix,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry3")),dateAdmission);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry4")),dateSortie);

                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion,"spinbutton4")),prix);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion,"spinbutton3")),nbChambre);

                if(strcmp(typeChambre,"Simple")==0) x=0;
                if(strcmp(typeChambre,"Double")==0) x=1;




                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion,"combobox2")),x);
		GtkWidget* msg=lookup_widget(gestion,"label48");
                gtk_label_set_text(GTK_LABEL(msg),nom);
		


                gtk_widget_show(lookup_widget(gestion,"button5"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(gestion,"label50");
        gtk_widget_hide(msg1);

}




}




void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
         hotel h;
        strcpy(h.nom,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"label48"))));
        strcpy(h.typeChambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion,"combobox2"))));
        strcpy(h.dateAdmission,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry3"))));
        strcpy(h.dateSortie,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry4"))));
        h.nbChambre =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion,"spinbutton3")));
        h.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion,"spinbutton4")));

        supp(h.nom);
        ajout(h);
        Hoteltree(lookup_widget(gestion,"treeview1"),"hotels.txt");
        GtkWidget* msg=lookup_widget(gestion,"label50");
        gtk_widget_show(msg);

}


void
on_combobox3_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
hotel h;
FILE*f=NULL;   
char nom[30];  
char nbChambre[30];  
char prix[30];  
strcpy(nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion,"combobox3"))));
f=fopen("hotels.txt","r");
while(fscanf(f,"%s %s %s %s %s %s\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,nbChambre,prix)!=EOF){//recuperation du donneé du fichier avec nbChambre et prix des chaines juste car la fonction gtk_label_set_text  accepte que chaine
if(strcmp(h.nom,nom)==0)
{
gtk_label_set_text(GTK_LABEL(lookup_widget(gestion,"label40")),h.typeChambre);
gtk_label_set_text(GTK_LABEL(lookup_widget(gestion,"label41")),h.dateAdmission);
gtk_label_set_text(GTK_LABEL(lookup_widget(gestion,"label42")),h.dateSortie);
gtk_label_set_text(GTK_LABEL(lookup_widget(gestion,"label43")),nbChambre);
gtk_label_set_text(GTK_LABEL(lookup_widget(gestion,"label44")),prix);

break;
}

}
fclose(f);





}


void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{


        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* nom;
        label=lookup_widget(gestion,"label49");
        p=lookup_widget(gestion,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&nom,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supp(nom);// supprimer la ligne du fichier

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }





}


void
on_Ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *cal1;
GtkWidget *cal2;
GtkWidget *combobox;
GtkWidget *labelNom;
GtkWidget *labelsuccess;
GtkWidget *labelCombo;
GtkWidget *labelExist;
FILE*f=NULL;
hotel h;
int jj1,mm1,aa1,jj2,mm2,aa2,b=1;

labelNom=lookup_widget(gestion,"label22");
labelCombo=lookup_widget(gestion,"label23");
labelExist=lookup_widget(gestion,"label14");
labelsuccess=lookup_widget(gestion,"label51");
combobox=lookup_widget(gestion,"combobox1");
cal1=lookup_widget(gestion,"calendar1");
cal2=lookup_widget(gestion,"calendar2");
           gtk_widget_hide (labelsuccess);

strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry1"))));
// saisie controlé
if(strcmp(h.nom,"")==0){
                gtk_widget_show (labelNom);
b=0;

}else
{
           gtk_widget_hide (labelNom);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(combobox))==-1){
                gtk_widget_show (labelCombo);
b=0;
}
else{

           gtk_widget_hide (labelCombo);
}
if(b==1){

h.nbChambre =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion,"spinbutton1")));
h.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion,"spinbutton2")));
strcpy(h.typeChambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

gtk_calendar_get_date (GTK_CALENDAR(cal1),
                       &aa1,
                       &mm1,
                       &jj1);
gtk_calendar_get_date (GTK_CALENDAR(cal2),
                       &aa2,
                       &mm2,
                       &jj2);
if(exist(h.nom)==1) {

                gtk_wicdget_show (labelExist);

}
else{
           gtk_widget_hide (labelExist);
f=fopen("hotels.txt","a+");
fprintf(f,"%s %s %d/%d/%d %d/%d/%d %d %d\n",h.nom,h.typeChambre,jj1,mm1+1,aa1,jj2,mm2+1,aa2,h.nbChambre,h.prix);
fclose(f);
                gtk_widget_show (labelsuccess);


/*mise a jour du treeView*/
GtkWidget *p;
p=lookup_widget(gestion,"treeview1");
Hoteltree(p,"hotels.txt");



}
}


}

void
on_ReserverHotel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

hotel h;
GtkWidget *labelInvalide;
GtkWidget *labelsuccess;

char nbChambreDispo[30];  
char prix[30];
int  nbChambre;

labelInvalide=lookup_widget(gestion,"label52");
labelsuccess=lookup_widget(gestion,"label53");
gtk_widget_hide(labelsuccess);

strcpy(h.nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion,"combobox3"))));

//recuperation du donneé du label avec nbChambre et prix des chaines juste car la fonction gtk_label_get_text  retourne une chaine
strcpy(h.typeChambre,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"label40"))));
strcpy(h.dateAdmission,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"label41"))));
strcpy(h.dateSortie,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"label42"))));
strcpy(nbChambreDispo,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"label43"))));
strcpy(prix,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"label44"))));

sscanf(nbChambreDispo, "%d", &h.nbChambre); 
sscanf(prix, "%d", &h.prix); 



nbChambre =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion,"spinbutton5")));

if(h.nbChambre<nbChambre){

gtk_widget_show (labelInvalide);

}else
{
gtk_widget_hide(labelInvalide);


reserver_hotel(h,nbChambre);
gtk_widget_show (labelsuccess);
supp(h.nom);
h.nbChambre-=nbChambre;
ajout( h);
//mise a jour du treeView
Hoteltree(lookup_widget(gestion,"treeview1"),"hotels.txt");










}




}


void
on_ChercherHotel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelType;
GtkWidget *nbResultat;
GtkWidget *message;
char type[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion,"entry5");
labelType=lookup_widget(gestion,"label56");
p1=lookup_widget(gestion,"treeview2");

strcpy(type,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(type,"")==0){
  gtk_widget_show (labelType);b=0;
}else{
b=1;
gtk_widget_hide (labelType);}

if(b==0){return;}else{

nb=ChercherHotelTree(p1,"hotels.txt",type);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestion,"label57");
message=lookup_widget(gestion,"label58");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);//set_text n'accepte que chaine de caractere 

gtk_widget_show (nbResultat);
gtk_widget_show (message);




}

}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}






void
on_buttonAgent_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *window1; 

/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
FILE*f1=NULL;
GtkWidget *Combonom;
hotel h;
window1=lookup_widget(button,"window1");
gtk_widget_destroy (window1);

gestion = create_gestion ();
p=lookup_widget(gestion,"treeview1");
p1=lookup_widget(gestion,"treeview2");
i=0;
j=0;
Hoteltree(p,"hotels.txt");
Hoteltree2(p1,"hotels.txt");

gtk_widget_show (gestion);

/*preparation du combobox du reservation */
Combonom=lookup_widget(gestion, "combobox3");
gtk_list_store_clear(GTK_LIST_STORE (gtk_combo_box_get_model(GTK_COMBO_BOX(Combonom))));
f1 = fopen("hotels.txt","r");
while(fscanf(f1,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,&h.nbChambre,&h.prix)!=EOF){

gtk_combo_box_append_text(GTK_COMBO_BOX(Combonom),h.nom);

}
}





void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window2;
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
	GtkWidget *labelsuccess;
 	gchar *nom;
	gchar *typeChambre; 
        gchar *dateAdmission;
        gchar *dateSortie;
        
        
        gint prix;
        gint nbChambre;
	char nombreChambre[30];
	char prix1[30];

	labelsuccess=lookup_widget(button,"label240");
        label=lookup_widget(button,"label228");
        p=lookup_widget(button,"treeview5");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
           gtk_tree_model_get (model,&iter,0,&nom,1,&typeChambre,2,&dateAdmission,3,&dateSortie,4,&nbChambre,5,&prix,-1);//recuperer les information de la ligne selectionneé


		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label268")),nom);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label243")),typeChambre);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label245")),dateAdmission);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label247")),dateSortie);
		

    		sprintf(nombreChambre, "%d", nbChambre); 

    		sprintf(prix1, "%d", prix); 

		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label249")),nombreChambre);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label251")),prix1);

		gtk_widget_hide(labelsuccess);

           gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button,"notebook2")));//redirection vers la page suivante	
           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }
}



void
on_button34_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

hotel h;
GtkWidget *labelInvalide;
GtkWidget *labelsuccess;

char nbChambreDispo[30];  
char prix[30];
int  nbChambre;

labelInvalide=lookup_widget(button,"label253");
labelsuccess=lookup_widget(button,"label240");
gtk_widget_hide(labelsuccess);



//recuperation du donneé du label avec nbChambre et prix des chaines juste car la fonction gtk_label_get_text  retourne une chaine

strcpy(h.nom,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label268"))));
strcpy(h.typeChambre,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label243"))));
strcpy(h.dateAdmission,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label245"))));
strcpy(h.dateSortie,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label247"))));
strcpy(nbChambreDispo,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label249"))));
strcpy(prix,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label251"))));

sscanf(nbChambreDispo, "%d", &h.nbChambre); 
sscanf(prix, "%d", &h.prix); 



nbChambre =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(button,"spinbutton6")));

if(h.nbChambre<nbChambre){

gtk_widget_show (labelInvalide);

}else
{
gtk_widget_hide(labelInvalide);


reserver_hotel(h,nbChambre);
gtk_widget_show (labelsuccess);
supp(h.nom);
h.nbChambre-=nbChambre;
ajout( h);
//mise a jour du treeView
Hoteltree(lookup_widget(button,"treeview5"),"hotels.txt");










}


}



void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
 GtkWidget *window2; 

/*preparation du treeView*/
GtkWidget *p;
window1=lookup_widget(button,"window1");
gtk_widget_destroy (window1);

window2 = create_window2 ();

p=lookup_widget(window2,"treeview5");
//p1=lookup_widget(gestion,"treeview2");
i=0;
//j=0;
Hoteltree(p,"hotels.txt");
//Hoteltree2(p1,"hotels.txt");

gtk_widget_show (window2);
}





void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window2=lookup_widget(button,"window2");
        gtk_widget_destroy (window2);
 	window1=create_window1();

        gtk_widget_show (window1);

 
}


void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*acceuil;
	window1=lookup_widget(button,"window1");
        gtk_widget_destroy (window1);
 	acceuil=create_acceuil();

        gtk_widget_show (acceuil);

}

