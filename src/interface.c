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
create_gcolor2 (void)
{
  GtkWidget *gcolor2;
  GdkPixbuf *gcolor2_icon_pixbuf;
  GtkWidget *vbox1;
  GtkWidget *colorselection;
  GtkWidget *expander;
  GtkWidget *hbox1;
  GtkWidget *empty_space;
  GtkWidget *vbox2;
  GtkWidget *hbuttonbox2;
  GtkWidget *delete_button;
  GtkWidget *save_button;
  GtkWidget *scrolledwindow1;
  GtkWidget *treeview;
  GtkWidget *expander_label;
  GtkWidget *hseparator1;
  GtkWidget *hbuttonbox3;
  GtkWidget *about_button;
  GtkWidget *alignment1;
  GtkWidget *hbox2;
  GtkWidget *image3;
  GtkWidget *label5;
  GtkWidget *quit_button;
  GtkTooltips *tooltips;

  tooltips = gtk_tooltips_new ();

  gcolor2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (gcolor2), 1);
  gtk_window_set_title (GTK_WINDOW (gcolor2), _("gcolor2"));
  gtk_window_set_resizable (GTK_WINDOW (gcolor2), FALSE);
  gcolor2_icon_pixbuf = create_pixbuf ("icon.png");
  if (gcolor2_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (gcolor2), gcolor2_icon_pixbuf);
      gdk_pixbuf_unref (gcolor2_icon_pixbuf);
    }

  vbox1 = gtk_vbox_new (FALSE, 3);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (gcolor2), vbox1);
  gtk_container_set_border_width (GTK_CONTAINER (vbox1), 10);

  colorselection = gtk_color_selection_new ();
  gtk_widget_show (colorselection);
  gtk_box_pack_start (GTK_BOX (vbox1), colorselection, FALSE, TRUE, 0);
  gtk_color_selection_set_has_opacity_control (GTK_COLOR_SELECTION (colorselection), TRUE);

  expander = gtk_expander_new (NULL);
  gtk_widget_show (expander);
  gtk_box_pack_start (GTK_BOX (vbox1), expander, FALSE, FALSE, 0);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (expander), hbox1);

  empty_space = gtk_label_new ("");
  gtk_widget_show (empty_space);
  gtk_box_pack_start (GTK_BOX (hbox1), empty_space, FALSE, FALSE, 5);

  vbox2 = gtk_vbox_new (FALSE, 4);
  gtk_widget_show (vbox2);
  gtk_box_pack_start (GTK_BOX (hbox1), vbox2, TRUE, TRUE, 0);
  gtk_widget_set_size_request (vbox2, -1, 220);
  gtk_container_set_border_width (GTK_CONTAINER (vbox2), 5);

  hbuttonbox2 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox2);
  gtk_box_pack_start (GTK_BOX (vbox2), hbuttonbox2, FALSE, FALSE, 0);

  delete_button = gtk_button_new_from_stock ("gtk-delete");
  gtk_widget_show (delete_button);
  gtk_container_add (GTK_CONTAINER (hbuttonbox2), delete_button);
  gtk_widget_set_sensitive (delete_button, FALSE);
  GTK_WIDGET_SET_FLAGS (delete_button, GTK_CAN_DEFAULT);
  gtk_tooltips_set_tip (tooltips, delete_button, _("Delete the selected color. You can only delete those you saved yourself."), NULL);

  save_button = gtk_button_new_from_stock ("gtk-save");
  gtk_widget_show (save_button);
  gtk_container_add (GTK_CONTAINER (hbuttonbox2), save_button);
  GTK_WIDGET_SET_FLAGS (save_button, GTK_CAN_DEFAULT);
  gtk_tooltips_set_tip (tooltips, save_button, _("Save the color selected in the colorwheel"), NULL);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (vbox2), scrolledwindow1, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (scrolledwindow1), 1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_SHADOW_OUT);

  treeview = gtk_tree_view_new ();
  gtk_widget_show (treeview);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), treeview);
  gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (treeview), TRUE);

  expander_label = gtk_label_new_with_mnemonic (_("_Show saved colors"));
  gtk_widget_show (expander_label);
  gtk_expander_set_label_widget (GTK_EXPANDER (expander), expander_label);

  hseparator1 = gtk_hseparator_new ();
  gtk_widget_show (hseparator1);
  gtk_box_pack_start (GTK_BOX (vbox1), hseparator1, FALSE, FALSE, 0);
  gtk_widget_set_size_request (hseparator1, -1, 10);

  hbuttonbox3 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox3);
  gtk_box_pack_start (GTK_BOX (vbox1), hbuttonbox3, FALSE, TRUE, 0);

  about_button = gtk_button_new ();
  gtk_widget_show (about_button);
  gtk_container_add (GTK_CONTAINER (hbuttonbox3), about_button);
  GTK_WIDGET_SET_FLAGS (about_button, GTK_CAN_DEFAULT);
  gtk_tooltips_set_tip (tooltips, about_button, _("About gcolor2"), NULL);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (about_button), alignment1);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox2);

  image3 = create_pixmap (gcolor2, "about_icon.png");
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox2), image3, FALSE, FALSE, 0);

  label5 = gtk_label_new_with_mnemonic (_("_About"));
  gtk_widget_show (label5);
  gtk_box_pack_start (GTK_BOX (hbox2), label5, FALSE, FALSE, 0);

  quit_button = gtk_button_new_from_stock ("gtk-quit");
  gtk_widget_show (quit_button);
  gtk_container_add (GTK_CONTAINER (hbuttonbox3), quit_button);
  GTK_WIDGET_SET_FLAGS (quit_button, GTK_CAN_DEFAULT);
  gtk_tooltips_set_tip (tooltips, quit_button, _("Exit the program"), NULL);

  g_signal_connect ((gpointer) gcolor2, "destroy",
                    G_CALLBACK (on_gcolor2_destroy),
                    NULL);
  g_signal_connect ((gpointer) colorselection, "color_changed",
                    G_CALLBACK (on_colorselection_color_changed),
                    NULL);
  g_signal_connect ((gpointer) delete_button, "clicked",
                    G_CALLBACK (on_delete_button_clicked),
                    NULL);
  g_signal_connect ((gpointer) save_button, "clicked",
                    G_CALLBACK (on_save_button_clicked),
                    NULL);
  g_signal_connect ((gpointer) treeview, "button_press_event",
                    G_CALLBACK (on_treeview_button_press_event),
                    NULL);
  g_signal_connect ((gpointer) treeview, "popup_menu",
                    G_CALLBACK (on_treeview_popup_menu),
                    NULL);
  g_signal_connect ((gpointer) about_button, "clicked",
                    G_CALLBACK (on_about_button_clicked),
                    NULL);
  g_signal_connect ((gpointer) quit_button, "clicked",
                    G_CALLBACK (on_quit_button_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (gcolor2, gcolor2, "gcolor2");
  GLADE_HOOKUP_OBJECT (gcolor2, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (gcolor2, colorselection, "colorselection");
  GLADE_HOOKUP_OBJECT (gcolor2, expander, "expander");
  GLADE_HOOKUP_OBJECT (gcolor2, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (gcolor2, empty_space, "empty_space");
  GLADE_HOOKUP_OBJECT (gcolor2, vbox2, "vbox2");
  GLADE_HOOKUP_OBJECT (gcolor2, hbuttonbox2, "hbuttonbox2");
  GLADE_HOOKUP_OBJECT (gcolor2, delete_button, "delete_button");
  GLADE_HOOKUP_OBJECT (gcolor2, save_button, "save_button");
  GLADE_HOOKUP_OBJECT (gcolor2, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (gcolor2, treeview, "treeview");
  GLADE_HOOKUP_OBJECT (gcolor2, expander_label, "expander_label");
  GLADE_HOOKUP_OBJECT (gcolor2, hseparator1, "hseparator1");
  GLADE_HOOKUP_OBJECT (gcolor2, hbuttonbox3, "hbuttonbox3");
  GLADE_HOOKUP_OBJECT (gcolor2, about_button, "about_button");
  GLADE_HOOKUP_OBJECT (gcolor2, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (gcolor2, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (gcolor2, image3, "image3");
  GLADE_HOOKUP_OBJECT (gcolor2, label5, "label5");
  GLADE_HOOKUP_OBJECT (gcolor2, quit_button, "quit_button");
  GLADE_HOOKUP_OBJECT_NO_REF (gcolor2, tooltips, "tooltips");

  return gcolor2;
}

GtkWidget*
create_save_dialog (void)
{
  GtkWidget *save_dialog;
  GdkPixbuf *save_dialog_icon_pixbuf;
  GtkWidget *dialog_vbox1;
  GtkWidget *save_label;
  GtkWidget *save_entry;
  GtkWidget *dialog_action_area1;
  GtkWidget *save_cancel;
  GtkWidget *save_ok;
  GtkTooltips *tooltips;

  tooltips = gtk_tooltips_new ();

  save_dialog = gtk_dialog_new ();
  gtk_container_set_border_width (GTK_CONTAINER (save_dialog), 10);
  gtk_window_set_title (GTK_WINDOW (save_dialog), _("gcolor2 - Save a Color"));
  gtk_window_set_position (GTK_WINDOW (save_dialog), GTK_WIN_POS_CENTER_ON_PARENT);
  gtk_window_set_modal (GTK_WINDOW (save_dialog), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (save_dialog), FALSE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (save_dialog), TRUE);
  save_dialog_icon_pixbuf = create_pixbuf ("icon.png");
  if (save_dialog_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (save_dialog), save_dialog_icon_pixbuf);
      gdk_pixbuf_unref (save_dialog_icon_pixbuf);
    }
  gtk_window_set_type_hint (GTK_WINDOW (save_dialog), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox1 = GTK_DIALOG (save_dialog)->vbox;
  gtk_widget_show (dialog_vbox1);

  save_label = gtk_label_new ("");
  gtk_widget_show (save_label);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), save_label, FALSE, FALSE, 3);
  gtk_label_set_justify (GTK_LABEL (save_label), GTK_JUSTIFY_CENTER);
  gtk_label_set_line_wrap (GTK_LABEL (save_label), TRUE);

  save_entry = gtk_entry_new ();
  gtk_widget_show (save_entry);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), save_entry, FALSE, FALSE, 5);
  gtk_tooltips_set_tip (tooltips, save_entry, _("Enter a name for the color you selected"), NULL);
  gtk_entry_set_activates_default (GTK_ENTRY (save_entry), TRUE);

  dialog_action_area1 = GTK_DIALOG (save_dialog)->action_area;
  gtk_widget_show (dialog_action_area1);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area1), GTK_BUTTONBOX_END);

  save_cancel = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (save_cancel);
  gtk_dialog_add_action_widget (GTK_DIALOG (save_dialog), save_cancel, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (save_cancel, GTK_CAN_DEFAULT);

  save_ok = gtk_button_new_from_stock ("gtk-save");
  gtk_widget_show (save_ok);
  gtk_dialog_add_action_widget (GTK_DIALOG (save_dialog), save_ok, GTK_RESPONSE_OK);
  gtk_widget_set_sensitive (save_ok, FALSE);
  GTK_WIDGET_SET_FLAGS (save_ok, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) save_entry, "changed",
                    G_CALLBACK (on_save_entry_changed),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (save_dialog, save_dialog, "save_dialog");
  GLADE_HOOKUP_OBJECT_NO_REF (save_dialog, dialog_vbox1, "dialog_vbox1");
  GLADE_HOOKUP_OBJECT (save_dialog, save_label, "save_label");
  GLADE_HOOKUP_OBJECT (save_dialog, save_entry, "save_entry");
  GLADE_HOOKUP_OBJECT_NO_REF (save_dialog, dialog_action_area1, "dialog_action_area1");
  GLADE_HOOKUP_OBJECT (save_dialog, save_cancel, "save_cancel");
  GLADE_HOOKUP_OBJECT (save_dialog, save_ok, "save_ok");
  GLADE_HOOKUP_OBJECT_NO_REF (save_dialog, tooltips, "tooltips");

  gtk_widget_grab_focus (save_entry);
  gtk_widget_grab_default (save_ok);
  return save_dialog;
}

GtkWidget*
create_popup_menu (void)
{
  GtkWidget *popup_menu;
  GtkWidget *copy_color_to_clipboard;
  GtkWidget *image5;
  GtkWidget *separator1;
  GtkWidget *show_system_colors;

  popup_menu = gtk_menu_new ();

  copy_color_to_clipboard = gtk_image_menu_item_new_with_mnemonic (_("Copy color to clipboard"));
  gtk_widget_show (copy_color_to_clipboard);
  gtk_container_add (GTK_CONTAINER (popup_menu), copy_color_to_clipboard);

  image5 = gtk_image_new_from_stock ("gtk-copy", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image5);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (copy_color_to_clipboard), image5);

  separator1 = gtk_separator_menu_item_new ();
  gtk_widget_show (separator1);
  gtk_container_add (GTK_CONTAINER (popup_menu), separator1);
  gtk_widget_set_sensitive (separator1, FALSE);

  show_system_colors = gtk_check_menu_item_new_with_mnemonic (_("Show system colors"));
  gtk_widget_show (show_system_colors);
  gtk_container_add (GTK_CONTAINER (popup_menu), show_system_colors);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (show_system_colors), TRUE);

  g_signal_connect ((gpointer) copy_color_to_clipboard, "activate",
                    G_CALLBACK (on_copy_color_to_clipboard_activate),
                    NULL);
  g_signal_connect ((gpointer) show_system_colors, "activate",
                    G_CALLBACK (on_show_system_colors_activate),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (popup_menu, popup_menu, "popup_menu");
  GLADE_HOOKUP_OBJECT (popup_menu, copy_color_to_clipboard, "copy_color_to_clipboard");
  GLADE_HOOKUP_OBJECT (popup_menu, image5, "image5");
  GLADE_HOOKUP_OBJECT (popup_menu, separator1, "separator1");
  GLADE_HOOKUP_OBJECT (popup_menu, show_system_colors, "show_system_colors");

  return popup_menu;
}

GtkWidget*
create_about_dialog (void)
{
  GtkWidget *about_dialog;
  GdkPixbuf *about_dialog_icon_pixbuf;
  GtkWidget *dialog_vbox3;
  GtkWidget *about_image;
  GtkWidget *about_label;
  GtkWidget *about_notebook;
  GtkWidget *scrolledwindow1;
  GtkWidget *about_credits_text;
  GtkWidget *about_credits_label;
  GtkWidget *scrolledwindow2;
  GtkWidget *about_notes_text;
  GtkWidget *about_notes_label;
  GtkWidget *about_label2;
  GtkWidget *dialog_action_area3;
  GtkWidget *about_close_button;

  about_dialog = gtk_dialog_new ();
  gtk_widget_set_size_request (about_dialog, 400, 350);
  gtk_container_set_border_width (GTK_CONTAINER (about_dialog), 10);
  gtk_window_set_title (GTK_WINDOW (about_dialog), _("About gcolor2"));
  gtk_window_set_resizable (GTK_WINDOW (about_dialog), FALSE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (about_dialog), TRUE);
  about_dialog_icon_pixbuf = create_pixbuf ("icon.png");
  if (about_dialog_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (about_dialog), about_dialog_icon_pixbuf);
      gdk_pixbuf_unref (about_dialog_icon_pixbuf);
    }

  dialog_vbox3 = GTK_DIALOG (about_dialog)->vbox;
  gtk_widget_show (dialog_vbox3);

  about_image = create_pixmap (about_dialog, "icon.png");
  gtk_widget_show (about_image);
  gtk_box_pack_start (GTK_BOX (dialog_vbox3), about_image, FALSE, FALSE, 0);

  about_label = gtk_label_new ("");
  gtk_widget_show (about_label);
  gtk_box_pack_start (GTK_BOX (dialog_vbox3), about_label, FALSE, FALSE, 10);

  about_notebook = gtk_notebook_new ();
  gtk_widget_show (about_notebook);
  gtk_box_pack_start (GTK_BOX (dialog_vbox3), about_notebook, TRUE, TRUE, 0);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_container_add (GTK_CONTAINER (about_notebook), scrolledwindow1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_SHADOW_IN);

  about_credits_text = gtk_text_view_new ();
  gtk_widget_show (about_credits_text);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), about_credits_text);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (about_credits_text), FALSE);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (about_credits_text), GTK_WRAP_WORD);
  gtk_text_view_set_left_margin (GTK_TEXT_VIEW (about_credits_text), 5);

  about_credits_label = gtk_label_new_with_mnemonic (_("_Credits"));
  gtk_widget_show (about_credits_label);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (about_notebook), gtk_notebook_get_nth_page (GTK_NOTEBOOK (about_notebook), 0), about_credits_label);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow2);
  gtk_container_add (GTK_CONTAINER (about_notebook), scrolledwindow2);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_SHADOW_IN);

  about_notes_text = gtk_text_view_new ();
  gtk_widget_show (about_notes_text);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), about_notes_text);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (about_notes_text), FALSE);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (about_notes_text), GTK_WRAP_WORD);
  gtk_text_view_set_left_margin (GTK_TEXT_VIEW (about_notes_text), 5);

  about_notes_label = gtk_label_new_with_mnemonic (_("_Release Notes"));
  gtk_widget_show (about_notes_label);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (about_notebook), gtk_notebook_get_nth_page (GTK_NOTEBOOK (about_notebook), 1), about_notes_label);

  about_label2 = gtk_label_new (_("Copyright \302\251 2019 Michael Green"));
  gtk_widget_show (about_label2);
  gtk_box_pack_start (GTK_BOX (dialog_vbox3), about_label2, FALSE, FALSE, 5);
  gtk_label_set_use_markup (GTK_LABEL (about_label2), TRUE);
  gtk_label_set_justify (GTK_LABEL (about_label2), GTK_JUSTIFY_CENTER);

  dialog_action_area3 = GTK_DIALOG (about_dialog)->action_area;
  gtk_widget_show (dialog_action_area3);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area3), GTK_BUTTONBOX_END);

  about_close_button = gtk_button_new_from_stock ("gtk-close");
  gtk_widget_show (about_close_button);
  gtk_dialog_add_action_widget (GTK_DIALOG (about_dialog), about_close_button, GTK_RESPONSE_CLOSE);
  GTK_WIDGET_SET_FLAGS (about_close_button, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) about_dialog, "destroy",
                    G_CALLBACK (destroy_aboutdialog),
                    NULL);
  g_signal_connect ((gpointer) about_close_button, "clicked",
                    G_CALLBACK (destroy_aboutdialog),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (about_dialog, about_dialog, "about_dialog");
  GLADE_HOOKUP_OBJECT_NO_REF (about_dialog, dialog_vbox3, "dialog_vbox3");
  GLADE_HOOKUP_OBJECT (about_dialog, about_image, "about_image");
  GLADE_HOOKUP_OBJECT (about_dialog, about_label, "about_label");
  GLADE_HOOKUP_OBJECT (about_dialog, about_notebook, "about_notebook");
  GLADE_HOOKUP_OBJECT (about_dialog, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (about_dialog, about_credits_text, "about_credits_text");
  GLADE_HOOKUP_OBJECT (about_dialog, about_credits_label, "about_credits_label");
  GLADE_HOOKUP_OBJECT (about_dialog, scrolledwindow2, "scrolledwindow2");
  GLADE_HOOKUP_OBJECT (about_dialog, about_notes_text, "about_notes_text");
  GLADE_HOOKUP_OBJECT (about_dialog, about_notes_label, "about_notes_label");
  GLADE_HOOKUP_OBJECT (about_dialog, about_label2, "about_label2");
  GLADE_HOOKUP_OBJECT_NO_REF (about_dialog, dialog_action_area3, "dialog_action_area3");
  GLADE_HOOKUP_OBJECT (about_dialog, about_close_button, "about_close_button");

  gtk_widget_grab_focus (about_close_button);
  gtk_widget_grab_default (about_close_button);
  return about_dialog;
}

GtkWidget*
create_delete_dialog (void)
{
  GtkWidget *delete_dialog;
  GdkPixbuf *delete_dialog_icon_pixbuf;
  GtkWidget *vbox3;
  GtkWidget *delete_label;
  GtkWidget *hbuttonbox4;
  GtkWidget *delete_cancel;
  GtkWidget *delete_ok;

  delete_dialog = gtk_dialog_new ();
  gtk_container_set_border_width (GTK_CONTAINER (delete_dialog), 10);
  gtk_window_set_title (GTK_WINDOW (delete_dialog), _("gcolor2 - Delete a Color"));
  gtk_window_set_position (GTK_WINDOW (delete_dialog), GTK_WIN_POS_CENTER_ON_PARENT);
  gtk_window_set_modal (GTK_WINDOW (delete_dialog), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (delete_dialog), FALSE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (delete_dialog), TRUE);
  delete_dialog_icon_pixbuf = create_pixbuf ("icon.png");
  if (delete_dialog_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (delete_dialog), delete_dialog_icon_pixbuf);
      gdk_pixbuf_unref (delete_dialog_icon_pixbuf);
    }
  gtk_window_set_type_hint (GTK_WINDOW (delete_dialog), GDK_WINDOW_TYPE_HINT_DIALOG);

  vbox3 = GTK_DIALOG (delete_dialog)->vbox;
  gtk_widget_show (vbox3);

  delete_label = gtk_label_new ("");
  gtk_widget_show (delete_label);
  gtk_box_pack_start (GTK_BOX (vbox3), delete_label, FALSE, FALSE, 3);
  gtk_label_set_justify (GTK_LABEL (delete_label), GTK_JUSTIFY_CENTER);
  gtk_label_set_line_wrap (GTK_LABEL (delete_label), TRUE);

  hbuttonbox4 = GTK_DIALOG (delete_dialog)->action_area;
  gtk_widget_show (hbuttonbox4);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox4), GTK_BUTTONBOX_END);

  delete_cancel = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (delete_cancel);
  gtk_dialog_add_action_widget (GTK_DIALOG (delete_dialog), delete_cancel, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (delete_cancel, GTK_CAN_DEFAULT);

  delete_ok = gtk_button_new_from_stock ("gtk-delete");
  gtk_widget_show (delete_ok);
  gtk_dialog_add_action_widget (GTK_DIALOG (delete_dialog), delete_ok, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (delete_ok, GTK_CAN_DEFAULT);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (delete_dialog, delete_dialog, "delete_dialog");
  GLADE_HOOKUP_OBJECT_NO_REF (delete_dialog, vbox3, "vbox3");
  GLADE_HOOKUP_OBJECT (delete_dialog, delete_label, "delete_label");
  GLADE_HOOKUP_OBJECT_NO_REF (delete_dialog, hbuttonbox4, "hbuttonbox4");
  GLADE_HOOKUP_OBJECT (delete_dialog, delete_cancel, "delete_cancel");
  GLADE_HOOKUP_OBJECT (delete_dialog, delete_ok, "delete_ok");

  gtk_widget_grab_focus (delete_cancel);
  gtk_widget_grab_default (delete_cancel);
  return delete_dialog;
}

