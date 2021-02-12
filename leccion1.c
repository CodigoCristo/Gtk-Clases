//Funciones básicas para crear una ventana en GTK

#include <gtk/gtk.h>


int main (int argc, char **argv)
{

	gtk_init (&argc, &argv);

	//Llame a esta función antes de usar cualquier 
	//otra función GTK + en sus aplicaciones GUI. 
	//Inicializará todo lo necesario para operar 
	//el kit de herramientas y analizará algunas 
	//opciones estándar de la línea de comandos.

	//Aunque se espera que pase los parámetros 
	//argc, argv de main () a esta función, 
	//es posible pasar NULL si 
	//argv no está disponible o 
	//no se requiere el manejo de la línea de comandos.

	// Ejemplo
	//			int main(void)
	//			{
	//				gtk_init(NULL,NULL);
	//			}
	
	//La función gtk_init () inicializa GTK + y analiza algunas opciones estándar de la línea de comandos. 
	//Esta función debe llamarse antes de usar cualquier otra función GTK +.
	//  ------------------


	GtkWidget	*ventana_principal;
	GdkPixbuf 	*iconoApp;
	// muestra una ventana básica en la pantalla que le ponemos de nombre *ventana...
	// hay muchos tipos de widgets que deben ir siendo declarados con su nombre antes de trabajar con ellos
	//  ------------------

	//Definimos ruta y nombre Icono a usar en App
	iconoApp = gdk_pixbuf_new_from_file("./logo.svg", NULL);

	ventana_principal = gtk_window_new 	(GTK_WINDOW_TOPLEVEL);
	//La función gtk_window_new () crea una nueva GtkWindow, que es una ventana 
	//de nivel superior que puede contener otros widgets. 
	//El tipo de ventana es GTK_WINDOW_TOPLEVEL; Las ventanas de nivel superior 
	//tienen una barra de título y un borde. Son administrados por el administrador de ventanas.
	//  ------------------

	//  ------------------

	//Titulo de App
	gtk_window_set_title 		(GTK_WINDOW (ventana_principal), "Código Cristo");

	//Tamaño de App
	gtk_window_set_default_size	(GTK_WINDOW (ventana_principal), 800, 600);

	//Posición al abrir App
	gtk_window_set_position		(GTK_WINDOW (ventana_principal), GTK_WIN_POS_CENTER);

	//Borde de espacio de nuestra App [opcional]
	gtk_container_set_border_width	(GTK_CONTAINER (ventana_principal), 20);

	//Icono de App
  	gtk_window_set_icon(GTK_WINDOW(ventana_principal), iconoApp);

 	// Evitamos que sea redimensionable [opcional]
 	gtk_window_set_resizable(GTK_WINDOW(ventana_principal),FALSE);

	//  ------------------


	gtk_widget_show_all (ventana_principal);
	//Marca que todos los widget se muestren. 
	//  ------------------


	g_signal_connect (ventana_principal, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	//La función g_signal_connect () conecta una función de devolución de llamada 
	//a una señal para un objeto en particular. La ventana no reacciona a 
	//la señal de destroy por defecto. Debemos terminar explícitamente 
	//la aplicación conectando la señal de destroy a la función 
	//incorporada gtk_main_quit (), que termina la aplicación.
	//  ------------------


	gtk_main();
	//Este código ingresa al bucle principal GTK +. 
	//A partir de este punto, la aplicación se sienta y espera a que sucedan los eventos.

}
