#include <stdio.h>
#include <gtk/gtk.h>

GtkEntry *ler;
GtkLabel *escreva;
//GtkButton *pressione;

void button_Clicked(GtkButton *pressione, gpointer data){
  g_print("\n\tBotão clicado\n");
}

void quit(){
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){
  GtkBuilder *arquivo;
  GtkWidget *tela1;

  gtk_init(&numArgs, &nomArgs);
  arquivo = gtk_builder_new_from_file("IU.glade");
  tela1 = GTK_WIDGET(gtk_builder_get_object(arquivo, "TelaP"));
  gtk_builder_add_callback_symbols(arquivo, "on_butao_clicked", G_CALLBACK(button_Clicked), NULL);

  g_signal_connect(tela1, "destroy", G_CALLBACK(quit), NULL);

  gtk_widget_show(tela1);

  gtk_main();
}
