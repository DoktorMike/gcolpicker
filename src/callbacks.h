#include <gtk/gtk.h>

#define USER_COLOR         "user"
#define SYSTEM_COLOR       "system"
#define FILE_ERROR         "An error occurred trying to open file \"%s\" for %s access!\n\n" \
                           "Please check the file permissions and try again."
#define FILE_READ          "read"
#define FILE_WRITE         "write"

/* possible locations of the rgb file */
#define SYSTEM_FILE_1      "/usr/X11R6/lib/X11/rgb.txt"
#define SYSTEM_FILE_2      "/usr/lib/X11/rgb.txt"
#define SYSTEM_FILE_3      "/etc/X11/rgb.txt"
#define SYSTEM_FILE_4      "/usr/openwin/lib/X11/rgb.txt"

/* about dialog text */
#define ABOUT_CREDITS_TEXT "Developer:\n" \
                           "Justin Spadea <justin@j-z-s.com>\n\n" \
                           "Special Thanks To:\n" \
                           "Eugenia Loli-Queru <eloli@hotmail.com>\n" \
                           "\t\302\267 Insight on the UI design\n" \
                           "\t\302\267 Provided the icon\n" \
                           "Ricardo Veguilla <veguilla@hpcf.upr.edu>\n" \
                           "\t\302\267 Provided spec file\n\n" \
                           "Official Website:\n" \
                           "http://gcolor2.sourceforge.net"
#define ABOUT_NOTES_TEXT   "Known Issues:\n" \
                           "For some colors, you may notice the hex value " \
                           "displayed in the color selector is slightly " \
                           "different than the hex value that is saved. This " \
                           "has to do with the color selector adding " \
                           "(unnecessary) rounding math to the display; " \
                           "the color is essentially the same.\n\n" \
                           "Changes In This Release:\n" \
                           "\302\267 Color list columns now sortable\n" \
                           "\302\267 Color list uses alternate colored rows\n" \
                           "\302\267 Typeahead searching on color list " \
                           "uses 'Name' column instead of hex color\n" \
                           "\302\267 Look in multiple locations for X11 " \
                           "rgb.txt file\n" \
                           "\302\267 Usability / user interface enhancements\n" \
                           "\302\267 Code cleanup"

GtkWidget *gcolor2;
GtkWidget *menu;
GdkColor   colorvalue;

enum
{
	COLOR,
	COLOR_VALUE,
	COLOR_NAME,
	COLOR_TYPE,
	N_COLUMNS
};

gchar* get_user_file();

void show_file_error (gchar* message);

void destroy_aboutdialog (GtkObject *object, gpointer user_data);

void on_about_button_clicked (GtkButton *button, gpointer user_data);

void on_colorselection_color_changed (GtkColorSelection *colorselection, gpointer user_data);
										
void on_save_entry_changed (GtkEditable *editable, gpointer user_data);

void on_list_selection_changed (GtkTreeSelection *selection, gpointer user_data);

void on_copy_color_to_clipboard_activate (GtkMenuItem *menuitem, gpointer user_data);

void on_show_system_colors_activate (GtkMenuItem *menuitem, gpointer user_data);

void show_popup_menu (GtkWidget *treeview, GdkEventButton *event, gpointer user_data);

gboolean on_treeview_button_press_event (GtkWidget *widget, GdkEventButton *event,
                                         gpointer user_data);

gboolean on_treeview_popup_menu (GtkWidget *widget, gpointer user_data);

void on_save_button_clicked (GtkButton *button, gpointer user_data);

void add_color_to_treeview ();
										
gboolean save_selected_color ();

void on_delete_button_clicked (GtkButton *button, gpointer user_data);

gboolean delete_color (gchar* color_name, gchar* color_value);

void on_gcolor2_destroy (GtkObject *object, gpointer user_data);

void on_quit_button_clicked (GtkButton *button, gpointer user_data);

gchar* hex_value (GdkColor color);
