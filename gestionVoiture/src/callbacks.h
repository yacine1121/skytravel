#include <gtk/gtk.h>

typedef struct voiture voiture;
struct voiture{
char cin[30];
char matricule[30];
char marque[30];
char date_location[30];
char date_retour[30];
int prix;
int NbVoiture;
};
  int i,j;
  GtkWidget *Acceuil;
  GtkWidget *gestion_voiture;
void
on_AcceuilgestionVoiture_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);


void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_ConfirmerModification_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_Louer_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_ChercherVoiture_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3d_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10d_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11d_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12d_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button18d_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13d_enter                     (GtkButton       *button,
                                        gpointer         user_data);
