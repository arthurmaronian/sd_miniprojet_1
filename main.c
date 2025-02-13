#include "biblioLC.h"
#include "entreeSortieLC.h"
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
    int buf = -1;
    while(buf!=0){
        menu();
        scanf("%d", &buf);
        switch(buf){
        case 1:
            affichage_biblio(b);
            break;
        case 2:
            printf("Veuillez entrer un numéro, un titre et un auteur : ");
            int numero;
            char b1[100];
            char nom[100];
            
            char auteur[100];
            
            while(*(fgets(b1, 100, stdin))!='\n') {}
            sscanf(b1, "%s %d %s", nom, &numero, auteur);
            inserer_en_tete(b, numero, nom, auteur);
        
        }
    }
    return 0;
}