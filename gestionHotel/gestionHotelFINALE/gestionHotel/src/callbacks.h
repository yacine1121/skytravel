#include <gtk/gtk.h>

typedef struct hotel hotel;
struct hotel{
char nom[30];
char typeChambre[30];
char dateAdmission[30];
char dateSortie[30];
int nbChambre;
int prix;
};

int i,j;
  GtkWidget *acceuil;
  GtkWidget *gestion;
  GtkWidget *window1;
  GtkWidget *window2;

void
on_Acceuilgestion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_combobox3_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_ReserverHotel_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_ChercherHotel_clicked               (GtkButton       *button,
                                        gpointer         user_data);



void
on_buttonAgent_clicked                 (GtkButton       *button,
                                        gpointer         user_data);




void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button34_clicked                    (GtkButton       *button,
                                        gpointer         user_data);


void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
