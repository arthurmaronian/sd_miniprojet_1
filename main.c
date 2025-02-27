#include "biblioLC.h"
#include "entreeSortieLC.h"
#include <stdio.h>

void menu(){
    printf("0-sortie du programme\n");
    printf("1-Affichage\n");
    printf("2-Inserer ouvrage\n"); 
    printf("3-Recherche ouvrage par numéro\n");  
    printf("4-Recherche ouvrage par titre\n"); 
    printf("5-Recherche tous les livres même auteur\n");
    printf("6-Supprimer ouvrage\n");
    printf("7-Recherche ouvrage même exemplaire\n"); 
}


int main(int argc, char** argv) {
    Biblio* b = creer_biblio();
    Biblio* b2 = NULL;
    Livre* l = NULL;
    int buf = -1;
    while(buf!=0){
        char b1[100];
        int numero;
        char titre[100];
        char auteur[100];
        char saisie[20];
        menu();
        fgets(saisie, 20, stdin);
        sscanf(saisie, "%d", &buf);
        switch(buf){
        case 1:
            affichage_biblio(b);
            break;
        case 2:
            printf("Veuillez entrer un numéro, un titre et un auteur : ");

            fgets(b1, 100, stdin);
            sscanf(b1, "%d %s %s", &numero,titre, auteur);
            inserer_en_tete(b, numero, titre, auteur);
            printf("Insertion avec succès !\n");
            break;
        case 3:
            printf("Veuillez entrer un numéro : ");
            fgets(b1, 100, stdin);
            sscanf(b1, "%d", &numero);
            l = rechercher_num(b, numero);
            if(l){
                affichage_livre(l);
            }else{
                printf("Livre non trouvé\n");
            }
            break;
        case 4:
            printf("Veuillez entrer un titre : ");
            fgets(b1, 100, stdin);
            sscanf(b1, "%s", titre);
            l = rechercher_titre(b->L, titre);
            if(l){
                affichage_livre(l);
            }else{
                printf("Livre non trouvé\n");
            }
            break;
        case 5:
            printf("Veuillez entrer un auteur : ");
            fgets(b1, 100, stdin);
            sscanf(b1, "%s", auteur);
            b2 = rechercher_auteur(b, auteur);
            if(b2 && b2->L != NULL){
                affichage_biblio(b2);
            }else{
                printf("Auteur non trouvé\n");
            }
            break;

        case 6:
            printf("Veuillez entrer un numéro, un titre et un auteur : ");
            fgets(b1, 100, stdin);
            sscanf(b1, "%d %s %s", &numero,titre, auteur);
            b = supprimer_livre(b, numero, titre, auteur);
            break;
        case 7:
            b2 = recherche_multiples(b);
            affichage_biblio(b2);
            break;
        }


    }
    return 0;
}