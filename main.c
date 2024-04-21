#include <stdio.h>
#include <gtk/gtk.h>

GtkEntry *ler;
GtkLabel *escreva;
//GtkButton *pressione;

void button_Clicked(GtkWidget *widget, gpointer data){

  g_print("\n\tBotão clicado\n");
}

void on_TelaP_destroy(GtkWidget *widget){
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){
  GtkBuilder *arquivo;
  GtkWidget *tela1;

  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("IU.glade");
  tela1 = GTK_WIDGET(gtk_builder_get_object(arquivo, "TelaP"));

  gtk_builder_add_callback_symbol(arquivo, "on_butao_clicked", G_CALLBACK(button_Clicked));

  gtk_builder_connect_signals(arquivo, NULL);

  g_signal_connect(tela1, "destroy", G_CALLBACK(on_TelaP_destroy), NULL);

  gtk_widget_show(tela1);

  gtk_main();
}
