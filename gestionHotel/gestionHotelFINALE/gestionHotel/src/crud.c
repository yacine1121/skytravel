#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>


void ajout( hotel h){
FILE*f=NULL;
f=fopen("hotels.txt","a+");
fprintf(f,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,h.nbChambre,h.prix);
fclose(f);

}

int exist(char*nom){
FILE*f=NULL;
 hotel h;
f=fopen("hotels.txt","r");
while(fscanf(f,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,&h.nbChambre,&h.prix)!=EOF){
if(strcmp(h.nom,nom)==0)return 1;
}
fclose(f);
return 0;
}


void supp(char*nom){
FILE*f=NULL;
FILE*f1=NULL;
 hotel h;
f=fopen("hotels.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,&h.nbChambre,&h.prix)!=EOF){
if(strcmp(nom,h.nom)!=0)fprintf(f1,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,h.nbChambre,h.prix);
}
fclose(f);
fclose(f1);
remove("agents.txt");
rename("ancien.txt","hotels.txt");
}
void reserver_hotel( hotel h,int nbChambre){

FILE*f=NULL;
f=fopen("reservations.txt","a+");
fprintf(f,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,nbChambre,h.prix);
fclose(f);





}
