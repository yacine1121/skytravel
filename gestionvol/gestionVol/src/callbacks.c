#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"treeView.h"
#include"crud.h"


void
on_Acceuilgestion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *acceuil;
GtkWidget *window;
acceuil=lookup_widget(button,"acceuil");
gtk_widget_destroy (acceuil);
gtk_widget_hide (acceuil);
window = create_window ();


gtk_widget_show (window);

}


void
on_gestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion_vol;
GtkWidget *window; 

gestion_vol=lookup_widget(button,"gestion_vol"); 
gtk_widget_destroy(gestion_vol);
window=create_window();
gtk_widget_show(window);
}


void
on_Ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cal1;
GtkWidget *cal2;
GtkWidget *comboboxDepart;
GtkWidget *comboboxDestination;
GtkWidget *comboboxCompanie;

GtkWidget *labelid;
GtkWidget *labelsuccess;
GtkWidget *labelComboDepart;
GtkWidget *labelComboDestination;
GtkWidget *labelComboCompanie;
GtkWidget *labelExist;
FILE*f=NULL;
vol v;
int jj1,mm1,aa1,jj2,mm2,aa2,b=1;

labelid=lookup_widget(gestion_vol,"label12");
labelComboDepart=lookup_widget(gestion_vol,"label13");
labelComboDestination=lookup_widget(gestion_vol,"label43");
labelComboCompanie=lookup_widget(gestion_vol,"label46");
labelExist=lookup_widget(gestion_vol,"label11");
labelsuccess=lookup_widget(gestion_vol,"label14");



comboboxDepart=lookup_widget(gestion_vol,"combobox1");
comboboxDestination=lookup_widget(gestion_vol,"combobox4");
comboboxCompanie=lookup_widget(gestion_vol,"combobox6");



cal1=lookup_widget(gestion_vol,"calendar1");
cal2=lookup_widget(gestion_vol,"calendar2");
           gtk_widget_hide (labelsuccess);

strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry1"))));

if(strcmp(v.id,"")==0){
                gtk_widget_show (labelid);
b=0;

}else
{
           gtk_widget_hide (labelid);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxDepart))==-1){
                gtk_widget_show (labelComboDepart);
b=0;
}
else{

           gtk_widget_hide (labelComboDepart);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxDestination))==-1){
                gtk_widget_show (labelComboDestination);
b=0;
}
else{

           gtk_widget_hide (labelComboDestination);
}


if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxCompanie))==-1){
                gtk_widget_show (labelComboCompanie);
b=0;
}
else{

           gtk_widget_hide (labelComboCompanie);
}


if(b==1){

v.nbVols =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton1")));
v.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton2")));
strcpy(v.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxDepart)));
strcpy(v.destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxDestination)));
strcpy(v.companie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxCompanie)));

gtk_calendar_get_date (GTK_CALENDAR(cal1),
                       &aa1,
                       &mm1,
                       &jj1);
gtk_calendar_get_date (GTK_CALENDAR(cal2),
                       &aa2,
                       &mm2,
   
                    &jj2);




if(exist_vol(v.id)==1) {

                gtk_widget_show (labelExist);

}
else{
           gtk_widget_hide (labelExist);

f=fopen("vols.txt","a+");
fprintf(f,"%s %s %s %s %d/%d/%d %d/%d/%d %d %d\n",v.id,v.depart,v.destination,v.companie,jj1,mm1+1,aa1,jj2,mm2+1,aa2,v.nbVols,v.prix);
fclose(f);
                gtk_widget_show (labelsuccess);


//mise a jour du treeView
GtkWidget *p;
p=lookup_widget(gestion_vol,"treeview1");
Voltree(p,"vols.txt");



}

}



}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

 	gchar *id;
        gchar *depart;
        gchar *destination;
        gchar *companie;
        gchar *date_depart;
        gchar *date_retour;
        gint prix;
        gint nbVols;

        gint x1=0,x2=0,x3;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion_vol,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&id,1,&depart,2,&destination,3,&companie,4,&date_depart,5,&date_retour,6,&nbVols,7,&prix,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry2")),date_depart);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry3")),date_retour);

                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_vol,"spinbutton3")),nbVols);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_vol,"spinbutton4")),prix);


                 if(strcmp(depart,"Tunisie")==0)	x1=0;		
                if(strcmp(depart,"Djerba")==0) x1=1;                
                if(strcmp(depart,"Monastir")==0)  x1=2 ;             

                if(strcmp(destination,"Marroc")==0) x2=0;                 
                if(strcmp(destination,"Paris")==0) x2=1;                
                if(strcmp(destination,"Newyork")==0)  x2=2;               

                if(strcmp(companie,"Airfrance")==0)  x3=0;              
                if(strcmp(companie,"Tunisair")==0)       x3=1;        		  
        		  




                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox2")),x1);
                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox5")),x2);
                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox7")),x3);





		GtkWidget* msg=lookup_widget(gestion_vol,"label24");
                gtk_label_set_text(GTK_LABEL(msg),id);
		


                gtk_widget_show(lookup_widget(gestion_vol,"button6"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(gestion_vol,"label26"); 
        gtk_widget_hide(msg1);//cacher "vol modifié avec succes"


}





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
        gchar* id;
        label=lookup_widget(gestion_vol,"label25");
        p=lookup_widget(gestion_vol,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la selection
        {  gtk_tree_model_get (model,&iter,0,&id,-1);//recuperer l id du treeView selectionné 
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_vol(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }




}


void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
      	vol v;
        strcpy(v.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label24"))));
        strcpy(v.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox2"))));
        strcpy(v.destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox5"))));
        strcpy(v.companie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox7"))));
        strcpy(v.date_depart,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry2"))));
        strcpy(v.date_retour,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry3"))));
        v.nbVols =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton3")));
        v.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton4")));

        supprimer_vol(v.id);
        ajouter_vol(v);
        Voltree(lookup_widget(gestion_vol,"treeview1"),"vols.txt");
        GtkWidget* msg=lookup_widget(gestion_vol,"label26");
        gtk_widget_show(msg);


}


void
on_Reserver_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
	GtkWidget *labelsuccess;
 	gchar *id;
        gchar *depart;
        gchar *destination;
        gchar *companie;
        gchar *date_depart;
        gchar *date_retour;
        gint prix;
        gint nbVols;
	char nombreVol[30];
	char prix1[30];

	labelsuccess=lookup_widget(gestion_vol,"label57");
        label=lookup_widget(gestion_vol,"label25");
        p=lookup_widget(gestion_vol,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
           gtk_tree_model_get (model,&iter,0,&id,1,&depart,2,&destination,3,&companie,4,&date_depart,5,&date_retour,6,&nbVols,7,&prix,-1);//recuperer les information de la ligne selectionneé


		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_vol,"label51")),id);
		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_vol,"label29")),depart);
		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_vol,"label31")),destination);
		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_vol,"label33")),companie);
		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_vol,"label35")),date_depart);
		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_vol,"label37")),date_retour);

    		sprintf(nombreVol, "%d", nbVols); 

    		sprintf(prix1, "%d", prix); 

		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_vol,"label52")),nombreVol);
		gtk_label_set_text(GTK_LABEL(lookup_widget(gestion_vol,"label54")),prix1);

		gtk_widget_hide(labelsuccess);
           gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(gestion_vol,"notebook1")));//redirection vers la page suivante	
           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }




}


void
on_Confirmer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

vol v;
GtkWidget *labelInvalide;
GtkWidget *labelsuccess;

char nbVolDispo[30];  
char prix[30];
int  nbVol;

labelInvalide=lookup_widget(gestion_vol,"label56");
labelsuccess=lookup_widget(gestion_vol,"label57");



//recuperation du donneé du label avec nbVol et prix des chaines juste car la fonction gtk_label_get_text  retourne une chaine
strcpy(v.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label51"))));
strcpy(v.depart,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label29"))));
strcpy(v.destination,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label31"))));
strcpy(v.companie,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label33"))));
strcpy(v.date_depart,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label35"))));
strcpy(v.date_retour,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label37"))));
strcpy(nbVolDispo,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label52"))));
strcpy(prix,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label54"))));
//convertir les chaines en int
sscanf(nbVolDispo, "%d", &v.nbVols); 
sscanf(prix, "%d", &v.prix); 



nbVol =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton5")));

if(v.nbVols<nbVol){

gtk_widget_show (labelInvalide);

}else
{
gtk_widget_hide(labelInvalide);


reserver_vol(v,nbVol);
gtk_widget_show (labelsuccess);
supprimer_vol(v.id);
v.nbVols-=nbVol;
ajouter_vol( v);
//mise a jour du treeView
Voltree(lookup_widget(gestion_vol,"treeview1"),"vols.txt");


}


}


void
on_ChercherVol_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelCompanie;
GtkWidget *nbResultat;
GtkWidget *message;
char companie[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion_vol,"entry4");
labelCompanie=lookup_widget(gestion_vol,"label56");
p1=lookup_widget(gestion_vol,"treeview2");

strcpy(companie,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(companie,"")==0){
  gtk_widget_show (labelCompanie);b=0;
}else{
b=1;
gtk_widget_hide (labelCompanie);}

if(b==0){return;}else{

nb=ChercherVolTree(p1,"vols.txt",companie);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestion_vol,"label62");
message=lookup_widget(gestion_vol,"label61");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);




}

















}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
vol v;
window=lookup_widget(button,"window");
gtk_widget_destroy (window);
gtk_widget_hide (acceuil);
gestion_vol = create_gestion_vol ();
p=lookup_widget(gestion_vol,"treeview1");
p1=lookup_widget(gestion_vol,"treeview2");
i=0;
j=0;

Voltree(p,"vols.txt");
Voltree2(p1,"vols.txt");
gtk_widget_show (gestion_vol);
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1, *window;
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
vol v;
window=lookup_widget(button,"window");
gtk_widget_destroy (window);

window1 = create_window1 ();

p=lookup_widget(window1,"treeview3");

//p1=lookup_widget(window1,"treeview2");
i=0;
//j=0;

Voltree(p,"vols.txt");
//Voltree2(p1,"vols.txt");
gtk_widget_show (window1);

}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
	GtkWidget *labelsuccess;
 	gchar *id;
        gchar *depart;
        gchar *destination;
        gchar *companie;
        gchar *date_depart;
        gchar *date_retour;
        gint prix;
        gint nbVols;
	char nombreVol[30];
	char prix1[30];

	labelsuccess=lookup_widget(button,"label110");
        label=lookup_widget(button,"label88");
        p=lookup_widget(button,"treeview3");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
           gtk_tree_model_get (model,&iter,0,&id,1,&depart,2,&destination,3,&companie,4,&date_depart,5,&date_retour,6,&nbVols,7,&prix,-1);//recuperer les information de la ligne selectionneé


		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label109")),id);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label102")),depart);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label103")),destination);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label104")),companie);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label105")),date_depart);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label106")),date_retour);

    		sprintf(nombreVol, "%d", nbVols); 

    		sprintf(prix1, "%d", prix); 

		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label107")),nombreVol);
		gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label108")),prix1);

		gtk_widget_hide(labelsuccess);

           gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button,"notebook2")));//redirection vers la page suivante	
           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }


}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
vol v;
GtkWidget *labelInvalide;
GtkWidget *labelsuccess;

char nbVolDispo[30];  
char prix[30];
int  nbVol;
labelInvalide=lookup_widget(button,"label100");
labelsuccess=lookup_widget(button,"label110");



//recuperation du donneé du label avec nbVol et prix des chaines juste car la fonction gtk_label_get_text  retourne une chaine
strcpy(v.id,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label109"))));
strcpy(v.depart,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label102"))));
strcpy(v.destination,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label103"))));
strcpy(v.companie,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label104"))));
strcpy(v.date_depart,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label105"))));
strcpy(v.date_retour,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label106"))));
strcpy(nbVolDispo,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label107"))));
strcpy(prix,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label108"))));
//convertir les chaines en int
sscanf(nbVolDispo, "%d", &v.nbVols); 
sscanf(prix, "%d", &v.prix); 



nbVol =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(button,"spinbutton6")));

if(v.nbVols<nbVol){

gtk_widget_show (labelInvalide);

}else
{
gtk_widget_hide(labelInvalide);


reserver_vol(v,nbVol);
gtk_widget_show (labelsuccess);
supprimer_vol(v.id);
v.nbVols-=nbVol;
ajouter_vol( v);
//mise a jour du treeView
Voltree(lookup_widget(button,"treeview3"),"vols.txt");

}
}


void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *acceuil;
GtkWidget *window; 

window=lookup_widget(button,"window"); 
gtk_widget_destroy(window);
acceuil=create_acceuil();
gtk_widget_show(acceuil);
}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window1;
GtkWidget *window; 

window1=lookup_widget(button,"window1"); 
gtk_widget_destroy(window1);
window=create_window();
gtk_widget_show(window);
}

