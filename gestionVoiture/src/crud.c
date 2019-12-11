#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>
#include"crud.h"

void ajouter_voiture( voiture v){
FILE*f=NULL;
f=fopen("voitures.txt","a+");
fprintf(f,"%s %s %s %s %s %d %d\n",v.cin,v.matricule,v.marque,v.date_location,v.date_retour,v.prix,v.NbVoiture);
fclose(f);
}

int exist_voiture(char*matricule){
FILE*f=NULL;
 voiture v;
f=fopen("voitures.txt","r");
while(fscanf(f,"%s %s %s %s %s %d %d\n",v.cin,v.matricule,v.marque,v.date_location,v.date_retour,&v.prix,&v.NbVoiture)!=EOF)
{
if(strcmp(matricule,v.matricule)==0)return 1;
}
fclose(f);
return 0;
}


void supprimer_voiture(char*matricule){
FILE*f=NULL;
FILE*f1=NULL;
 voiture v;
f=fopen("voitures.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %d %d\n",v.cin,v.matricule,v.marque,v.date_location,v.date_retour,&v.prix,&v.NbVoiture)!=EOF)
{
if(strcmp(matricule,v.matricule)!=0)fprintf(f1,"%s %s %s %s %s %d %d\n",v.cin,v.matricule,v.marque,v.date_location,v.date_retour,v.prix,v.NbVoiture);
}
fclose(f);
fclose(f1);
remove("voitures.txt");
rename("ancien.txt","voitures.txt");
}

void louer_voiture( voiture v,int nbV){

FILE*f=NULL;
f=fopen("location_voitures.txt","a+");
fprintf(f,"%s %s %s %s %s %d %d\n",v.cin,v.matricule,v.marque,v.date_location,v.date_retour,v.prix,nbV);
fclose(f);


}


