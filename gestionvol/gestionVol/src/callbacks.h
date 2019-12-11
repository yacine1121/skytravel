#include <gtk/gtk.h>
typedef struct vol vol;
struct vol{
char id[30];
char depart[30];
char destination[30];
char companie[30];
char date_depart[30];
char date_retour[30];
int nbVols;
int prix;
};
  int i,j;
  GtkWidget *acceuil;
  GtkWidget *gestion_vol;

void
on_Acceuilgestion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Reserver_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Confirmer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_ChercherVol_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
