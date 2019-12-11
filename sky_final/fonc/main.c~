#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"reclamation.h"

void main()
{
int x=0,y=0;
char numero[5];
int menu=0;
do{

printf("\nhello \n*pour ajouter tappez 1\n*pour supprimer tappez 2\n*pour modifier tappez 3\npour afficher tappez 4\npour qitter tappez 0\n");
scanf("%d",&menu);

switch(menu){
case 1:
ajouter_reclamation();
break;
case 2:
printf("saisir le numero du reclamation a supprimer ");
scanf("%s",numero);
x=supprimer_reclamation(numero);
if (x==1)
printf("reclamation supprimer\n");

else
printf("ops !!! echec \n");
case 3:
afficher_reclamation();
printf("saisir le numero du reclamation a modifier ");
scanf("%s",numero);
y=modifier_reclamation(numero);
if (y==1)
printf("reclamation modifiée\n");

else
printf("ops !!! echec\n");
break;
default :
afficher_reclamation();
break;
};
}while(menu!=0);
}

