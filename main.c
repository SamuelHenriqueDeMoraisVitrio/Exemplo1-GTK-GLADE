#include <stdio.h>
#include <gtk/gtk.h>

void quit(){
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){
  gtk_init(&numArgs, &nomArgs);

  quit();

  gtk_main();
}
