#include <stdio.h>
#include <gtk/gtk.h>

GtkEntry *ler;
GtkLabel *escreva;

void button_Clicked(GtkWidget *widget, gpointer data){

  printf("\n\tBotão clicado\n");
}

void on_TelaP_destroy(){
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){
  GtkBuilder *arquivo;
  GtkWidget *tela1;

  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("IU.glade");
  tela1 = GTK_WIDGET(gtk_builder_get_object(arquivo, "TelaP"));

  gtk_builder_add_callback_symbols(arquivo, "on_butao_clicked", G_CALLBACK(button_Clicked), "on_TelaP_destroy", G_CALLBACK(on_TelaP_destroy), NULL);

  gtk_builder_connect_signals(arquivo, NULL);

  gtk_widget_show(tela1);

  gtk_main();
}
