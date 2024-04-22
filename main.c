#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>

void button_Clicked();
void escrever_na_telaP();
void on_telaP_destroy();

GtkEntry *ler;
GtkLabel *escreva;

void button_Clicked(GtkWidget *widget, gpointer data){

  system("clear");

  escrever_na_telaP();
}

void escrever_na_telaP(){

  printf("\n\tBotão clicado\n");
  const char *textArray = gtk_entry_get_text(ler);
  gtk_label_set_text(escreva, textArray);
}

void on_TelaP_destroy(GtkWidget *widget, gpointer data){

  system("clear");
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){
  GtkBuilder *arquivo;
  GtkWidget *tela1;

  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("IU.glade");
  tela1 = GTK_WIDGET(gtk_builder_get_object(arquivo, "TelaP"));
  escreva = GTK_LABEL(gtk_builder_get_object(arquivo, "escrever"));
  ler = GTK_ENTRY(gtk_builder_get_object(arquivo, "leia"));

  gtk_builder_add_callback_symbols(arquivo, "on_butao_clicked", G_CALLBACK(button_Clicked), "on_TelaP_destroy", G_CALLBACK(on_TelaP_destroy), NULL);

  gtk_builder_connect_signals(arquivo, NULL);

  gtk_widget_show(tela1);

  gtk_main();
}
