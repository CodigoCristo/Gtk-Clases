//Funciones para usar hoja de estilos con CSS y GTK

#include <gtk/gtk.h>


static void load_css ( void )
{
	//Elementos de GTK con su nombre de variable
    GtkCssProvider  *provider;
    GdkDisplay      *display;
    GdkScreen       *screen;

    //const gchar *css_style_file = "style.css";  Metodo 1

    //Definimos ruta de nuestra hoja de estilos.
    GFile   *css_fp             = g_file_new_for_path( "./style-clase2.css" );
    GError  *error              = 0;

    provider = gtk_css_provider_new ();
    display  = gdk_display_get_default();
    screen   = gdk_display_get_default_screen( display );

    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION );
    gtk_css_provider_load_from_file (provider, css_fp, &error);

    g_object_unref( provider );
}



int main (int argc, char **argv)
{

	gtk_init (&argc, &argv);

	GtkWidget	*ventana_principal; //ventana principal
	GdkPixbuf 	*iconoApp;			//icono
	GtkWidget 	*boton;				//Boton nuevo


	gtk_init(NULL,NULL);

	//Cargamos las funciones para CSS
	load_css();

	ventana_principal 		= gtk_window_new 	(GTK_WINDOW_TOPLEVEL);
	iconoApp 				= gdk_pixbuf_new_from_file("./logo.svg", NULL);

	gtk_window_set_title 		(GTK_WINDOW (ventana_principal), "Arch Linux");

	//Definimos su nombre para luego llamarlo en CSS = style.css
	gtk_widget_set_name 		(ventana_principal, "ventana_principal");

	gtk_window_set_icon			(GTK_WINDOW(ventana_principal), iconoApp);

	gtk_window_set_default_size	(GTK_WINDOW (ventana_principal), 800, 600);
	gtk_window_set_position		(GTK_WINDOW (ventana_principal), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width	(GTK_CONTAINER (ventana_principal), 20);

	g_signal_connect (ventana_principal, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	//Boton
	boton = gtk_button_new_with_label ( "Salir de App" ); //Definimos el texto a mostrar
	//Definimos su nombre para luego llamarlo en CSS = style.css
	gtk_widget_set_name (boton, "boton");

	//Agregamos el boton a la ventana principal
	gtk_container_add ( GTK_CONTAINER (ventana_principal), boton);

	//Al recibir la señal de "clicked" entra la funcion de gtk_main_quit
	//lo cual cerrará la App
	g_signal_connect ( boton, "clicked", gtk_main_quit, NULL);
	

	gtk_widget_show_all (ventana_principal);
	gtk_main();


}
