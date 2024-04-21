#include <stdio.h>
#include <gtk/gtk.h>

GtkEntry *ler;
GtkLabel *escreva;
GtkWidget *pressione;

void button_Clicked(GtkWidget *widget, gpointer data){

  printf("\n\tBotão clicado\n");
}

void on_TelaP(GtkWidget *widget){
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){
  GtkBuilder *arquivo;
  GtkWidget *tela1;

  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("IU.glade");
  tela1 = GTK_WIDGET(gtk_builder_get_object(arquivo, "TelaP"));
  pressione = GTK_WIDGET(gtk_builder_get_object(arquivo, "butao"));

  g_signal_connect(tela1, "destroy", G_CALLBACK(on_TelaP), NULL);

  g_signal_connect(pressione, "clicked", G_CALLBACK(button_Clicked), NULL);

  gtk_widget_show(tela1);

  gtk_main();
}
