/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window33 (void)
{
  GtkWidget *window33;
  GtkWidget *fixed33;
  GtkWidget *label128;
  GtkWidget *button113;
  GtkWidget *image76;
  GtkWidget *button114;
  GtkWidget *image77;
  GtkWidget *button116;
  GtkWidget *button115;

  window33 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window33), _("window33"));

  fixed33 = gtk_fixed_new ();
  gtk_widget_show (fixed33);
  gtk_container_add (GTK_CONTAINER (window33), fixed33);

  label128 = gtk_label_new (_("Facturation"));
  gtk_widget_show (label128);
  gtk_fixed_put (GTK_FIXED (fixed33), label128, 104, 32);
  gtk_widget_set_size_request (label128, 177, 40);

  button113 = gtk_button_new ();
  gtk_widget_show (button113);
  gtk_fixed_put (GTK_FIXED (fixed33), button113, 336, 32);
  gtk_widget_set_size_request (button113, 48, 32);

  image76 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image76);
  gtk_container_add (GTK_CONTAINER (button113), image76);

  button114 = gtk_button_new ();
  gtk_widget_show (button114);
  gtk_fixed_put (GTK_FIXED (fixed33), button114, 0, 248);
  gtk_widget_set_size_request (button114, 48, 24);

  image77 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image77);
  gtk_container_add (GTK_CONTAINER (button114), image77);

  button116 = gtk_button_new_with_mnemonic (_("Ajouter facture"));
  gtk_widget_show (button116);
  gtk_fixed_put (GTK_FIXED (fixed33), button116, 96, 160);
  gtk_widget_set_size_request (button116, 216, 48);

  button115 = gtk_button_new_with_mnemonic (_("Summprimer,modifier facture"));
  gtk_widget_show (button115);
  gtk_fixed_put (GTK_FIXED (fixed33), button115, 96, 96);
  gtk_widget_set_size_request (button115, 216, 56);

  g_signal_connect ((gpointer) button113, "clicked",
                    G_CALLBACK (on_button113_clicked),
                    NULL);
  g_signal_connect ((gpointer) button114, "clicked",
                    G_CALLBACK (on_button114_clicked),
                    NULL);
  g_signal_connect ((gpointer) button116, "clicked",
                    G_CALLBACK (on_button116_clicked),
                    NULL);
  g_signal_connect ((gpointer) button115, "clicked",
                    G_CALLBACK (on_button115_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window33, window33, "window33");
  GLADE_HOOKUP_OBJECT (window33, fixed33, "fixed33");
  GLADE_HOOKUP_OBJECT (window33, label128, "label128");
  GLADE_HOOKUP_OBJECT (window33, button113, "button113");
  GLADE_HOOKUP_OBJECT (window33, image76, "image76");
  GLADE_HOOKUP_OBJECT (window33, button114, "button114");
  GLADE_HOOKUP_OBJECT (window33, image77, "image77");
  GLADE_HOOKUP_OBJECT (window33, button116, "button116");
  GLADE_HOOKUP_OBJECT (window33, button115, "button115");

  return window33;
}

GtkWidget*
create_window34 (void)
{
  GtkWidget *window34;
  GtkWidget *fixed34;
  GtkWidget *entry40;
  GtkWidget *entry43;
  GtkWidget *entry44;
  GtkWidget *label133;
  GtkWidget *label134;
  GtkWidget *button118;
  GtkWidget *image79;
  GtkWidget *label132;
  GtkWidget *label130;
  GtkWidget *label131;
  GtkWidget *label129;
  GtkObject *aj_adj;
  GtkWidget *aj;
  GtkObject *am_adj;
  GtkWidget *am;
  GtkObject *fj_adj;
  GtkWidget *fj;
  GtkObject *fm_adj;
  GtkWidget *fm;
  GtkObject *fa_adj;
  GtkWidget *fa;
  GtkWidget *label143;
  GtkWidget *label144;
  GtkWidget *label145;
  GtkWidget *label146;
  GtkWidget *label147;
  GtkWidget *label148;
  GtkWidget *button117;
  GtkWidget *image78;
  GtkWidget *button119;
  GtkWidget *alignment21;
  GtkWidget *hbox21;
  GtkWidget *image80;
  GtkWidget *label135;
  GtkWidget *button120;
  GtkObject *spinbutton7_adj;
  GtkWidget *spinbutton7;

  window34 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window34), _("window1"));

  fixed34 = gtk_fixed_new ();
  gtk_widget_show (fixed34);
  gtk_container_add (GTK_CONTAINER (window34), fixed34);

  entry40 = gtk_entry_new ();
  gtk_widget_show (entry40);
  gtk_fixed_put (GTK_FIXED (fixed34), entry40, 240, 40);
  gtk_widget_set_size_request (entry40, 216, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry40), 8226);

  entry43 = gtk_entry_new ();
  gtk_widget_show (entry43);
  gtk_fixed_put (GTK_FIXED (fixed34), entry43, 240, 136);
  gtk_widget_set_size_request (entry43, 216, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry43), 8226);

  entry44 = gtk_entry_new ();
  gtk_widget_show (entry44);
  gtk_fixed_put (GTK_FIXED (fixed34), entry44, 240, 88);
  gtk_widget_set_size_request (entry44, 216, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry44), 8226);

  label133 = gtk_label_new_with_mnemonic (_("Ajouter une facture"));
  gtk_widget_show (label133);
  gtk_fixed_put (GTK_FIXED (fixed34), label133, 256, 0);
  gtk_widget_set_size_request (label133, 177, 25);
  gtk_misc_set_alignment (GTK_MISC (label133), 0.5, 0.45);

  label134 = gtk_label_new (_("num factue"));
  gtk_widget_show (label134);
  gtk_fixed_put (GTK_FIXED (fixed34), label134, 96, 40);
  gtk_widget_set_size_request (label134, 88, 32);

  button118 = gtk_button_new ();
  gtk_widget_show (button118);
  gtk_fixed_put (GTK_FIXED (fixed34), button118, 568, 8);
  gtk_widget_set_size_request (button118, 66, 29);

  image79 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image79);
  gtk_container_add (GTK_CONTAINER (button118), image79);

  label132 = gtk_label_new (_("Cin du client"));
  gtk_widget_show (label132);
  gtk_fixed_put (GTK_FIXED (fixed34), label132, 96, 136);
  gtk_widget_set_size_request (label132, 97, 25);

  label130 = gtk_label_new (_("Montant"));
  gtk_widget_show (label130);
  gtk_fixed_put (GTK_FIXED (fixed34), label130, 96, 88);
  gtk_widget_set_size_request (label130, 80, 24);

  label131 = gtk_label_new (_("Date d'ajout:"));
  gtk_widget_show (label131);
  gtk_fixed_put (GTK_FIXED (fixed34), label131, 24, 184);
  gtk_widget_set_size_request (label131, 104, 25);

  label129 = gtk_label_new (_("Date de fin:"));
  gtk_widget_show (label129);
  gtk_fixed_put (GTK_FIXED (fixed34), label129, 16, 224);
  gtk_widget_set_size_request (label129, 121, 25);

  aj_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  aj = gtk_spin_button_new (GTK_ADJUSTMENT (aj_adj), 1, 0);
  gtk_widget_show (aj);
  gtk_fixed_put (GTK_FIXED (fixed34), aj, 248, 184);
  gtk_widget_set_size_request (aj, 60, 27);

  am_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  am = gtk_spin_button_new (GTK_ADJUSTMENT (am_adj), 1, 0);
  gtk_widget_show (am);
  gtk_fixed_put (GTK_FIXED (fixed34), am, 400, 184);
  gtk_widget_set_size_request (am, 60, 27);

  fj_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  fj = gtk_spin_button_new (GTK_ADJUSTMENT (fj_adj), 1, 0);
  gtk_widget_show (fj);
  gtk_fixed_put (GTK_FIXED (fixed34), fj, 248, 232);
  gtk_widget_set_size_request (fj, 60, 27);

  fm_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  fm = gtk_spin_button_new (GTK_ADJUSTMENT (fm_adj), 1, 0);
  gtk_widget_show (fm);
  gtk_fixed_put (GTK_FIXED (fixed34), fm, 400, 232);
  gtk_widget_set_size_request (fm, 60, 27);

  fa_adj = gtk_adjustment_new (1990, 1990, 2020, 1, 10, 10);
  fa = gtk_spin_button_new (GTK_ADJUSTMENT (fa_adj), 1, 0);
  gtk_widget_show (fa);
  gtk_fixed_put (GTK_FIXED (fixed34), fa, 560, 232);
  gtk_widget_set_size_request (fa, 60, 27);

  label143 = gtk_label_new (_("jour"));
  gtk_widget_show (label143);
  gtk_fixed_put (GTK_FIXED (fixed34), label143, 168, 184);
  gtk_widget_set_size_request (label143, 57, 25);

  label144 = gtk_label_new (_("mois"));
  gtk_widget_show (label144);
  gtk_fixed_put (GTK_FIXED (fixed34), label144, 328, 184);
  gtk_widget_set_size_request (label144, 57, 25);

  label145 = gtk_label_new (_("annee"));
  gtk_widget_show (label145);
  gtk_fixed_put (GTK_FIXED (fixed34), label145, 488, 184);
  gtk_widget_set_size_request (label145, 57, 25);

  label146 = gtk_label_new (_("jour"));
  gtk_widget_show (label146);
  gtk_fixed_put (GTK_FIXED (fixed34), label146, 168, 232);
  gtk_widget_set_size_request (label146, 56, 25);

  label147 = gtk_label_new (_("mois"));
  gtk_widget_show (label147);
  gtk_fixed_put (GTK_FIXED (fixed34), label147, 328, 232);
  gtk_widget_set_size_request (label147, 57, 25);

  label148 = gtk_label_new (_("annee"));
  gtk_widget_show (label148);
  gtk_fixed_put (GTK_FIXED (fixed34), label148, 488, 232);
  gtk_widget_set_size_request (label148, 57, 25);

  button117 = gtk_button_new ();
  gtk_widget_show (button117);
  gtk_fixed_put (GTK_FIXED (fixed34), button117, 24, 336);
  gtk_widget_set_size_request (button117, 66, 29);

  image78 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image78);
  gtk_container_add (GTK_CONTAINER (button117), image78);

  button119 = gtk_button_new ();
  gtk_widget_show (button119);
  gtk_fixed_put (GTK_FIXED (fixed34), button119, 104, 280);
  gtk_widget_set_size_request (button119, 200, 40);

  alignment21 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment21);
  gtk_container_add (GTK_CONTAINER (button119), alignment21);

  hbox21 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox21);
  gtk_container_add (GTK_CONTAINER (alignment21), hbox21);

  image80 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image80);
  gtk_box_pack_start (GTK_BOX (hbox21), image80, FALSE, FALSE, 0);

  label135 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label135);
  gtk_box_pack_start (GTK_BOX (hbox21), label135, FALSE, FALSE, 0);

  button120 = gtk_button_new_with_mnemonic (_("Consulter"));
  gtk_widget_show (button120);
  gtk_fixed_put (GTK_FIXED (fixed34), button120, 376, 280);
  gtk_widget_set_size_request (button120, 200, 40);

  spinbutton7_adj = gtk_adjustment_new (1990, 1990, 2020, 1, 10, 10);
  spinbutton7 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton7_adj), 1, 0);
  gtk_widget_show (spinbutton7);
  gtk_fixed_put (GTK_FIXED (fixed34), spinbutton7, 560, 184);
  gtk_widget_set_size_request (spinbutton7, 60, 27);

  g_signal_connect ((gpointer) button118, "clicked",
                    G_CALLBACK (on_button118_clicked),
                    NULL);
  g_signal_connect ((gpointer) button117, "clicked",
                    G_CALLBACK (on_button117_clicked),
                    NULL);
  g_signal_connect ((gpointer) button119, "clicked",
                    G_CALLBACK (on_button119_clicked),
                    NULL);
  g_signal_connect ((gpointer) button120, "clicked",
                    G_CALLBACK (on_button120_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window34, window34, "window34");
  GLADE_HOOKUP_OBJECT (window34, fixed34, "fixed34");
  GLADE_HOOKUP_OBJECT (window34, entry40, "entry40");
  GLADE_HOOKUP_OBJECT (window34, entry43, "entry43");
  GLADE_HOOKUP_OBJECT (window34, entry44, "entry44");
  GLADE_HOOKUP_OBJECT (window34, label133, "label133");
  GLADE_HOOKUP_OBJECT (window34, label134, "label134");
  GLADE_HOOKUP_OBJECT (window34, button118, "button118");
  GLADE_HOOKUP_OBJECT (window34, image79, "image79");
  GLADE_HOOKUP_OBJECT (window34, label132, "label132");
  GLADE_HOOKUP_OBJECT (window34, label130, "label130");
  GLADE_HOOKUP_OBJECT (window34, label131, "label131");
  GLADE_HOOKUP_OBJECT (window34, label129, "label129");
  GLADE_HOOKUP_OBJECT (window34, aj, "aj");
  GLADE_HOOKUP_OBJECT (window34, am, "am");
  GLADE_HOOKUP_OBJECT (window34, fj, "fj");
  GLADE_HOOKUP_OBJECT (window34, fm, "fm");
  GLADE_HOOKUP_OBJECT (window34, fa, "fa");
  GLADE_HOOKUP_OBJECT (window34, label143, "label143");
  GLADE_HOOKUP_OBJECT (window34, label144, "label144");
  GLADE_HOOKUP_OBJECT (window34, label145, "label145");
  GLADE_HOOKUP_OBJECT (window34, label146, "label146");
  GLADE_HOOKUP_OBJECT (window34, label147, "label147");
  GLADE_HOOKUP_OBJECT (window34, label148, "label148");
  GLADE_HOOKUP_OBJECT (window34, button117, "button117");
  GLADE_HOOKUP_OBJECT (window34, image78, "image78");
  GLADE_HOOKUP_OBJECT (window34, button119, "button119");
  GLADE_HOOKUP_OBJECT (window34, alignment21, "alignment21");
  GLADE_HOOKUP_OBJECT (window34, hbox21, "hbox21");
  GLADE_HOOKUP_OBJECT (window34, image80, "image80");
  GLADE_HOOKUP_OBJECT (window34, label135, "label135");
  GLADE_HOOKUP_OBJECT (window34, button120, "button120");
  GLADE_HOOKUP_OBJECT (window34, spinbutton7, "spinbutton7");

  return window34;
}

GtkWidget*
create_window35 (void)
{
  GtkWidget *window35;
  GtkWidget *fixed35;
  GtkWidget *treeview9;
  GtkWidget *label142;
  GtkWidget *button123;
  GtkWidget *image82;
  GtkWidget *button122;
  GtkWidget *image81;

  window35 = gtk_window_new (GTK_WINDOW_POPUP);
  gtk_window_set_title (GTK_WINDOW (window35), _("window2"));

  fixed35 = gtk_fixed_new ();
  gtk_widget_show (fixed35);
  gtk_container_add (GTK_CONTAINER (window35), fixed35);

  treeview9 = gtk_tree_view_new ();
  gtk_widget_show (treeview9);
  gtk_fixed_put (GTK_FIXED (fixed35), treeview9, 48, 56);
  gtk_widget_set_size_request (treeview9, 300, 200);

  label142 = gtk_label_new (_("factures"));
  gtk_widget_show (label142);
  gtk_fixed_put (GTK_FIXED (fixed35), label142, 144, 8);
  gtk_widget_set_size_request (label142, 160, 24);

  button123 = gtk_button_new ();
  gtk_widget_show (button123);
  gtk_fixed_put (GTK_FIXED (fixed35), button123, 344, 8);
  gtk_widget_set_size_request (button123, 66, 29);

  image82 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image82);
  gtk_container_add (GTK_CONTAINER (button123), image82);

  button122 = gtk_button_new ();
  gtk_widget_show (button122);
  gtk_fixed_put (GTK_FIXED (fixed35), button122, 336, 280);
  gtk_widget_set_size_request (button122, 66, 29);

  image81 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image81);
  gtk_container_add (GTK_CONTAINER (button122), image81);

  g_signal_connect ((gpointer) button123, "clicked",
                    G_CALLBACK (on_button123_clicked),
                    NULL);
  g_signal_connect ((gpointer) button122, "clicked",
                    G_CALLBACK (on_button122_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window35, window35, "window35");
  GLADE_HOOKUP_OBJECT (window35, fixed35, "fixed35");
  GLADE_HOOKUP_OBJECT (window35, treeview9, "treeview9");
  GLADE_HOOKUP_OBJECT (window35, label142, "label142");
  GLADE_HOOKUP_OBJECT (window35, button123, "button123");
  GLADE_HOOKUP_OBJECT (window35, image82, "image82");
  GLADE_HOOKUP_OBJECT (window35, button122, "button122");
  GLADE_HOOKUP_OBJECT (window35, image81, "image81");

  return window35;
}

GtkWidget*
create_window36 (void)
{
  GtkWidget *window36;
  GtkWidget *fixed36;
  GtkWidget *entry45;
  GtkWidget *entry46;
  GtkWidget *entry47;
  GtkWidget *label150;
  GtkWidget *label152;
  GtkWidget *label153;
  GtkWidget *label154;
  GtkWidget *label155;
  GtkObject *spinbutton1_adj;
  GtkWidget *spinbutton1;
  GtkObject *spinbutton2_adj;
  GtkWidget *spinbutton2;
  GtkObject *spinbutton3_adj;
  GtkWidget *spinbutton3;
  GtkObject *spinbutton4_adj;
  GtkWidget *spinbutton4;
  GtkObject *spinbutton5_adj;
  GtkWidget *spinbutton5;
  GtkObject *spinbutton6_adj;
  GtkWidget *spinbutton6;
  GtkWidget *label156;
  GtkWidget *label157;
  GtkWidget *label158;
  GtkWidget *label159;
  GtkWidget *label160;
  GtkWidget *label161;
  GtkWidget *label149;
  GtkWidget *button126;
  GtkWidget *button127;
  GtkWidget *image84;
  GtkWidget *button128;
  GtkWidget *image85;
  GtkWidget *button125;

  window36 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window36), _("window1"));

  fixed36 = gtk_fixed_new ();
  gtk_widget_show (fixed36);
  gtk_container_add (GTK_CONTAINER (window36), fixed36);

  entry45 = gtk_entry_new ();
  gtk_widget_show (entry45);
  gtk_fixed_put (GTK_FIXED (fixed36), entry45, 240, 40);
  gtk_widget_set_size_request (entry45, 216, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry45), 8226);

  entry46 = gtk_entry_new ();
  gtk_widget_show (entry46);
  gtk_fixed_put (GTK_FIXED (fixed36), entry46, 240, 136);
  gtk_widget_set_size_request (entry46, 216, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry46), 8226);

  entry47 = gtk_entry_new ();
  gtk_widget_show (entry47);
  gtk_fixed_put (GTK_FIXED (fixed36), entry47, 240, 88);
  gtk_widget_set_size_request (entry47, 216, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry47), 8226);

  label150 = gtk_label_new (_("num factue"));
  gtk_widget_show (label150);
  gtk_fixed_put (GTK_FIXED (fixed36), label150, 96, 40);
  gtk_widget_set_size_request (label150, 88, 32);

  label152 = gtk_label_new (_("Cin du client"));
  gtk_widget_show (label152);
  gtk_fixed_put (GTK_FIXED (fixed36), label152, 96, 136);
  gtk_widget_set_size_request (label152, 97, 25);

  label153 = gtk_label_new (_("Montant"));
  gtk_widget_show (label153);
  gtk_fixed_put (GTK_FIXED (fixed36), label153, 96, 88);
  gtk_widget_set_size_request (label153, 80, 24);

  label154 = gtk_label_new (_("Date d'ajout:"));
  gtk_widget_show (label154);
  gtk_fixed_put (GTK_FIXED (fixed36), label154, 24, 184);
  gtk_widget_set_size_request (label154, 104, 25);

  label155 = gtk_label_new (_("Date de fin:"));
  gtk_widget_show (label155);
  gtk_fixed_put (GTK_FIXED (fixed36), label155, 16, 224);
  gtk_widget_set_size_request (label155, 121, 25);

  spinbutton1_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  spinbutton1 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton1_adj), 1, 0);
  gtk_widget_show (spinbutton1);
  gtk_fixed_put (GTK_FIXED (fixed36), spinbutton1, 248, 184);
  gtk_widget_set_size_request (spinbutton1, 60, 27);

  spinbutton2_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton2 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton2_adj), 1, 0);
  gtk_widget_show (spinbutton2);
  gtk_fixed_put (GTK_FIXED (fixed36), spinbutton2, 400, 184);
  gtk_widget_set_size_request (spinbutton2, 60, 27);

  spinbutton3_adj = gtk_adjustment_new (1990, 1990, 2020, 1, 10, 10);
  spinbutton3 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton3_adj), 1, 0);
  gtk_widget_show (spinbutton3);
  gtk_fixed_put (GTK_FIXED (fixed36), spinbutton3, 560, 184);
  gtk_widget_set_size_request (spinbutton3, 60, 27);

  spinbutton4_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  spinbutton4 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton4_adj), 1, 0);
  gtk_widget_show (spinbutton4);
  gtk_fixed_put (GTK_FIXED (fixed36), spinbutton4, 248, 232);
  gtk_widget_set_size_request (spinbutton4, 60, 27);

  spinbutton5_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  spinbutton5 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton5_adj), 1, 0);
  gtk_widget_show (spinbutton5);
  gtk_fixed_put (GTK_FIXED (fixed36), spinbutton5, 400, 232);
  gtk_widget_set_size_request (spinbutton5, 60, 27);

  spinbutton6_adj = gtk_adjustment_new (1990, 1990, 2020, 1, 10, 10);
  spinbutton6 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton6_adj), 1, 0);
  gtk_widget_show (spinbutton6);
  gtk_fixed_put (GTK_FIXED (fixed36), spinbutton6, 560, 232);
  gtk_widget_set_size_request (spinbutton6, 60, 27);

  label156 = gtk_label_new (_("jour"));
  gtk_widget_show (label156);
  gtk_fixed_put (GTK_FIXED (fixed36), label156, 168, 184);
  gtk_widget_set_size_request (label156, 57, 25);

  label157 = gtk_label_new (_("mois"));
  gtk_widget_show (label157);
  gtk_fixed_put (GTK_FIXED (fixed36), label157, 328, 184);
  gtk_widget_set_size_request (label157, 57, 25);

  label158 = gtk_label_new (_("annee"));
  gtk_widget_show (label158);
  gtk_fixed_put (GTK_FIXED (fixed36), label158, 488, 184);
  gtk_widget_set_size_request (label158, 57, 25);

  label159 = gtk_label_new (_("jour"));
  gtk_widget_show (label159);
  gtk_fixed_put (GTK_FIXED (fixed36), label159, 168, 232);
  gtk_widget_set_size_request (label159, 56, 25);

  label160 = gtk_label_new (_("mois"));
  gtk_widget_show (label160);
  gtk_fixed_put (GTK_FIXED (fixed36), label160, 328, 232);
  gtk_widget_set_size_request (label160, 57, 25);

  label161 = gtk_label_new (_("annee"));
  gtk_widget_show (label161);
  gtk_fixed_put (GTK_FIXED (fixed36), label161, 488, 232);
  gtk_widget_set_size_request (label161, 57, 25);

  label149 = gtk_label_new_with_mnemonic (_("Modifier facture"));
  gtk_widget_show (label149);
  gtk_fixed_put (GTK_FIXED (fixed36), label149, 256, 0);
  gtk_widget_set_size_request (label149, 177, 25);
  gtk_misc_set_alignment (GTK_MISC (label149), 0.5, 0.45);

  button126 = gtk_button_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (button126);
  gtk_fixed_put (GTK_FIXED (fixed36), button126, 72, 280);
  gtk_widget_set_size_request (button126, 224, 40);

  button127 = gtk_button_new ();
  gtk_widget_show (button127);
  gtk_fixed_put (GTK_FIXED (fixed36), button127, 24, 336);
  gtk_widget_set_size_request (button127, 66, 29);

  image84 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image84);
  gtk_container_add (GTK_CONTAINER (button127), image84);

  button128 = gtk_button_new ();
  gtk_widget_show (button128);
  gtk_fixed_put (GTK_FIXED (fixed36), button128, 568, 8);
  gtk_widget_set_size_request (button128, 66, 29);

  image85 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image85);
  gtk_container_add (GTK_CONTAINER (button128), image85);

  button125 = gtk_button_new_with_mnemonic (_("Consulter"));
  gtk_widget_show (button125);
  gtk_fixed_put (GTK_FIXED (fixed36), button125, 344, 280);
  gtk_widget_set_size_request (button125, 256, 40);

  g_signal_connect ((gpointer) button126, "clicked",
                    G_CALLBACK (on_button126_clicked),
                    NULL);
  g_signal_connect ((gpointer) button127, "clicked",
                    G_CALLBACK (on_button127_clicked),
                    NULL);
  g_signal_connect ((gpointer) button128, "clicked",
                    G_CALLBACK (on_button128_clicked),
                    NULL);
  g_signal_connect ((gpointer) button125, "clicked",
                    G_CALLBACK (on_button125_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window36, window36, "window36");
  GLADE_HOOKUP_OBJECT (window36, fixed36, "fixed36");
  GLADE_HOOKUP_OBJECT (window36, entry45, "entry45");
  GLADE_HOOKUP_OBJECT (window36, entry46, "entry46");
  GLADE_HOOKUP_OBJECT (window36, entry47, "entry47");
  GLADE_HOOKUP_OBJECT (window36, label150, "label150");
  GLADE_HOOKUP_OBJECT (window36, label152, "label152");
  GLADE_HOOKUP_OBJECT (window36, label153, "label153");
  GLADE_HOOKUP_OBJECT (window36, label154, "label154");
  GLADE_HOOKUP_OBJECT (window36, label155, "label155");
  GLADE_HOOKUP_OBJECT (window36, spinbutton1, "spinbutton1");
  GLADE_HOOKUP_OBJECT (window36, spinbutton2, "spinbutton2");
  GLADE_HOOKUP_OBJECT (window36, spinbutton3, "spinbutton3");
  GLADE_HOOKUP_OBJECT (window36, spinbutton4, "spinbutton4");
  GLADE_HOOKUP_OBJECT (window36, spinbutton5, "spinbutton5");
  GLADE_HOOKUP_OBJECT (window36, spinbutton6, "spinbutton6");
  GLADE_HOOKUP_OBJECT (window36, label156, "label156");
  GLADE_HOOKUP_OBJECT (window36, label157, "label157");
  GLADE_HOOKUP_OBJECT (window36, label158, "label158");
  GLADE_HOOKUP_OBJECT (window36, label159, "label159");
  GLADE_HOOKUP_OBJECT (window36, label160, "label160");
  GLADE_HOOKUP_OBJECT (window36, label161, "label161");
  GLADE_HOOKUP_OBJECT (window36, label149, "label149");
  GLADE_HOOKUP_OBJECT (window36, button126, "button126");
  GLADE_HOOKUP_OBJECT (window36, button127, "button127");
  GLADE_HOOKUP_OBJECT (window36, image84, "image84");
  GLADE_HOOKUP_OBJECT (window36, button128, "button128");
  GLADE_HOOKUP_OBJECT (window36, image85, "image85");
  GLADE_HOOKUP_OBJECT (window36, button125, "button125");

  return window36;
}

GtkWidget*
create_window37 (void)
{
  GtkWidget *window37;
  GtkWidget *fixed37;
  GtkWidget *treeview10;
  GtkWidget *label162;
  GtkWidget *button129;
  GtkWidget *image86;
  GtkWidget *button130;
  GtkWidget *image87;

  window37 = gtk_window_new (GTK_WINDOW_POPUP);
  gtk_window_set_title (GTK_WINDOW (window37), _("window2"));

  fixed37 = gtk_fixed_new ();
  gtk_widget_show (fixed37);
  gtk_container_add (GTK_CONTAINER (window37), fixed37);

  treeview10 = gtk_tree_view_new ();
  gtk_widget_show (treeview10);
  gtk_fixed_put (GTK_FIXED (fixed37), treeview10, 48, 56);
  gtk_widget_set_size_request (treeview10, 300, 200);

  label162 = gtk_label_new (_("factures"));
  gtk_widget_show (label162);
  gtk_fixed_put (GTK_FIXED (fixed37), label162, 144, 8);
  gtk_widget_set_size_request (label162, 160, 24);

  button129 = gtk_button_new ();
  gtk_widget_show (button129);
  gtk_fixed_put (GTK_FIXED (fixed37), button129, 336, 280);
  gtk_widget_set_size_request (button129, 66, 29);

  image86 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image86);
  gtk_container_add (GTK_CONTAINER (button129), image86);

  button130 = gtk_button_new ();
  gtk_widget_show (button130);
  gtk_fixed_put (GTK_FIXED (fixed37), button130, 344, 8);
  gtk_widget_set_size_request (button130, 66, 29);

  image87 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image87);
  gtk_container_add (GTK_CONTAINER (button130), image87);

  g_signal_connect ((gpointer) button129, "clicked",
                    G_CALLBACK (on_button129_clicked),
                    NULL);
  g_signal_connect ((gpointer) button130, "clicked",
                    G_CALLBACK (on_button130_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window37, window37, "window37");
  GLADE_HOOKUP_OBJECT (window37, fixed37, "fixed37");
  GLADE_HOOKUP_OBJECT (window37, treeview10, "treeview10");
  GLADE_HOOKUP_OBJECT (window37, label162, "label162");
  GLADE_HOOKUP_OBJECT (window37, button129, "button129");
  GLADE_HOOKUP_OBJECT (window37, image86, "image86");
  GLADE_HOOKUP_OBJECT (window37, button130, "button130");
  GLADE_HOOKUP_OBJECT (window37, image87, "image87");

  return window37;
}

GtkWidget*
create_window38 (void)
{
  GtkWidget *window38;
  GtkWidget *fixed38;
  GtkWidget *label163;
  GtkWidget *entry48;
  GtkWidget *label164;
  GtkWidget *button135;
  GtkWidget *button134;
  GtkWidget *button131;
  GtkWidget *image89;
  GtkWidget *button132;
  GtkWidget *image88;
  GtkWidget *label165;

  window38 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window38), _("window38"));

  fixed38 = gtk_fixed_new ();
  gtk_widget_show (fixed38);
  gtk_container_add (GTK_CONTAINER (window38), fixed38);

  label163 = gtk_label_new (_("Authentification"));
  gtk_widget_show (label163);
  gtk_fixed_put (GTK_FIXED (fixed38), label163, 144, 24);
  gtk_widget_set_size_request (label163, 112, 24);

  entry48 = gtk_entry_new ();
  gtk_widget_show (entry48);
  gtk_fixed_put (GTK_FIXED (fixed38), entry48, 192, 104);
  gtk_widget_set_size_request (entry48, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry48), 8226);

  label164 = gtk_label_new (_("Numero de la facture"));
  gtk_widget_show (label164);
  gtk_fixed_put (GTK_FIXED (fixed38), label164, 32, 104);
  gtk_widget_set_size_request (label164, 152, 24);

  button135 = gtk_button_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (button135);
  gtk_fixed_put (GTK_FIXED (fixed38), button135, 256, 200);
  gtk_widget_set_size_request (button135, 114, 32);

  button134 = gtk_button_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (button134);
  gtk_fixed_put (GTK_FIXED (fixed38), button134, 88, 200);
  gtk_widget_set_size_request (button134, 128, 32);

  button131 = gtk_button_new ();
  gtk_widget_show (button131);
  gtk_fixed_put (GTK_FIXED (fixed38), button131, 352, 24);
  gtk_widget_set_size_request (button131, 58, 29);

  image89 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image89);
  gtk_container_add (GTK_CONTAINER (button131), image89);

  button132 = gtk_button_new ();
  gtk_widget_show (button132);
  gtk_fixed_put (GTK_FIXED (fixed38), button132, 32, 248);
  gtk_widget_set_size_request (button132, 56, 32);

  image88 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image88);
  gtk_container_add (GTK_CONTAINER (button132), image88);

  label165 = gtk_label_new ("");
  gtk_widget_show (label165);
  gtk_fixed_put (GTK_FIXED (fixed38), label165, 120, 144);
  gtk_widget_set_size_request (label165, 184, 40);

  g_signal_connect ((gpointer) button135, "clicked",
                    G_CALLBACK (on_button135_clicked),
                    NULL);
  g_signal_connect ((gpointer) button134, "clicked",
                    G_CALLBACK (on_button134_clicked),
                    NULL);
  g_signal_connect ((gpointer) button131, "clicked",
                    G_CALLBACK (on_button131_clicked),
                    NULL);
  g_signal_connect ((gpointer) button132, "clicked",
                    G_CALLBACK (on_button132_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window38, window38, "window38");
  GLADE_HOOKUP_OBJECT (window38, fixed38, "fixed38");
  GLADE_HOOKUP_OBJECT (window38, label163, "label163");
  GLADE_HOOKUP_OBJECT (window38, entry48, "entry48");
  GLADE_HOOKUP_OBJECT (window38, label164, "label164");
  GLADE_HOOKUP_OBJECT (window38, button135, "button135");
  GLADE_HOOKUP_OBJECT (window38, button134, "button134");
  GLADE_HOOKUP_OBJECT (window38, button131, "button131");
  GLADE_HOOKUP_OBJECT (window38, image89, "image89");
  GLADE_HOOKUP_OBJECT (window38, button132, "button132");
  GLADE_HOOKUP_OBJECT (window38, image88, "image88");
  GLADE_HOOKUP_OBJECT (window38, label165, "label165");

  return window38;
}

