#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>

#include "interface.h"
#include "support.h"
#include "callbacks.h"

GtkListStore *liststore;
GdkWindow    *gdkwin;
gchar        *user_filename;
gchar        *sys_filename;


void set_user_file ()
{
	user_filename = g_strdup_printf ("%s/.rgb.txt", getenv ("HOME"));
}

gchar* get_user_file ()
{
	return user_filename;
}

gboolean set_system_file ()
{
	/* try a couple locations to find rgb.txt */
	if (g_file_test (SYSTEM_FILE_1, G_FILE_TEST_EXISTS))
		sys_filename = SYSTEM_FILE_1;
	else if (g_file_test (SYSTEM_FILE_2, G_FILE_TEST_EXISTS))
		sys_filename = SYSTEM_FILE_2;
	else if (g_file_test (SYSTEM_FILE_3, G_FILE_TEST_EXISTS))
		sys_filename = SYSTEM_FILE_3;
	else if (g_file_test (SYSTEM_FILE_4, G_FILE_TEST_EXISTS))
		sys_filename = SYSTEM_FILE_4;
	else
		return FALSE;
	return TRUE;
}

gchar* get_system_file ()
{
	return sys_filename;
}

void add_list_color (gchar *spec, gchar *name, gchar *type, gboolean is_new_color)
{
	GdkPixmap   *pixmap;
	GdkBitmap   *mask;
	GdkPixbuf   *buf;
	GtkTreeIter  iter;
	
	gchar * swatchxpm[] =
	{
		"16 14 1 1",
		".      c #FFFFFF",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................",
		"................"
	};
	gchar colorline[] = ".      c #FFFFFF";
	
	g_sprintf (colorline, ".      c %s", spec);
	swatchxpm[1] = colorline;
	buf = gdk_pixbuf_new_from_xpm_data ((gchar const **)swatchxpm);

	/* setting where to insert will only take effect if user
	   didn't sort either of the columns yet */
	if (is_new_color)
		gtk_list_store_prepend (liststore, &iter);
	else
		gtk_list_store_append (liststore, &iter);
	gtk_list_store_set (liststore, &iter, COLOR, buf, COLOR_VALUE, spec,
	                    COLOR_NAME, name, COLOR_TYPE, type, -1);
	if (is_new_color)
	{
		/* when adding a new user color, select it in the treeview */
		gtk_tree_selection_select_iter (
			gtk_tree_view_get_selection (
				GTK_TREE_VIEW (lookup_widget (gcolor2, "treeview"))
			), &iter);
	}
}

void add_rgb_file (gchar *filename, gchar *type)
{
	FILE  *fp;
	gchar *p;
	gchar *name;
	gchar  buffer[512];
	gchar  spec[8];
	gint   r, g, b, lr, lg, lb;
	
	fp = fopen (filename, "r");
	if (!fp)
		return; /* silently fail */
	
	while ((p = fgets (buffer, sizeof buffer, fp)) != NULL)
	{
		if (buffer[0] == '!')
			continue;
		r = g_ascii_strtoull (p, &p, 10);
		g = g_ascii_strtoull (p, &p, 10);
		b = g_ascii_strtoull (p, &p, 10);
		p += strspn (p, " \t");
		/* X11 rgb.txt file contains duplicates; allow dupes from the user file though */
		if (!strcmp (type, SYSTEM_COLOR) && lr == r && lg == g && lb == b)
			continue;
		else
		{
			lr = r;
			lg = g;
			lb = b;
		}
		g_sprintf (spec, "#%.2X%.2X%.2X", r, g, b);
		name = g_strchomp (g_strdup (p));
		add_list_color (spec, name, type, FALSE);
	}
	fclose (fp);
}

gint main (gint argc, gchar *argv[])
{

	GtkCellRenderer   *renderer;
	GtkTreeViewColumn *column;
	GtkWidget         *treeview;
	GtkTreeSelection  *select;
	gchar             *buf;
	
#ifdef ENABLE_NLS
	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
#endif

	gtk_set_locale ();
	gtk_init (&argc, &argv);
	
	add_pixmap_directory (PACKAGE_DATA_DIR "/pixmaps/" PACKAGE);

	gcolor2 = create_gcolor2 ();
	gtk_widget_show (gcolor2);
	gtk_window_set_policy (GTK_WINDOW (gcolor2), FALSE, FALSE, TRUE);
	
	/* setup the tree view widget */
	liststore = gtk_list_store_new (N_COLUMNS, GDK_TYPE_PIXBUF, G_TYPE_STRING,
	                                G_TYPE_STRING, G_TYPE_STRING);
	treeview = lookup_widget (GTK_WIDGET (gcolor2), "treeview");
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (liststore));
	
	column = gtk_tree_view_column_new ();
	gtk_tree_view_column_set_title (column, "Color");
	
	renderer = gtk_cell_renderer_pixbuf_new ();
	gtk_tree_view_column_pack_start (column, renderer, FALSE);
	gtk_tree_view_column_set_attributes (column, renderer, "pixbuf", COLOR, NULL);
	
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_start (column, renderer, TRUE);
	gtk_tree_view_column_set_attributes (column, renderer, "text", COLOR_VALUE, NULL);
	
	gtk_tree_view_column_set_sort_column_id (column, COLOR_VALUE);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
	
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes ("Name", renderer,
													   "text", COLOR_NAME, NULL);
	gtk_tree_view_column_set_sort_column_id (column, COLOR_NAME);
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
	
	/* enable searching on Name column */
	gtk_tree_view_set_search_column (GTK_TREE_VIEW (treeview), COLOR_NAME);
	

	/* setup the selection handler */
	select = gtk_tree_view_get_selection (GTK_TREE_VIEW (treeview));
	gtk_tree_selection_set_mode (select, GTK_SELECTION_SINGLE);
	g_signal_connect (G_OBJECT (select), "changed",
	                  G_CALLBACK (on_list_selection_changed), NULL);
	

	/* setup the popup menu */
	menu = create_popup_menu ();
	
	/* set the filenames we will be using. if can't find sys file, disable menu item */
	set_user_file ();
	if (!set_system_file ())
	{
		GtkWidget *menuitem = lookup_widget (menu, "show_system_colors");
		gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (menuitem), FALSE);
		gtk_widget_set_sensitive (menuitem, FALSE);
	}
	
	/* init the GdkColorValue to white */
	colorvalue.red = colorvalue.green = colorvalue.blue = 65535;

	/* show first before setting gdkwin */
	gtk_widget_show (gcolor2);
	gdkwin = GTK_WIDGET (gcolor2)->window;
	
	/* fill with system and user-saved values */
	add_rgb_file (get_user_file (), USER_COLOR);
	add_rgb_file (get_system_file (), SYSTEM_COLOR);

	
	gtk_main ();
	return 0;
}
