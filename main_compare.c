#include <time.h>
#include <stdio.h>
#include "biblioH.h"
#include "biblioLC.h"
#include "entreeSortieH.h"
#include "entreeSortieLC.h"

#define FICHIER_TEST "GdeBiblio.txt"

void compare(FILE *finit, FILE *fnum, FILE *ftitre, FILE *fauteur, int n) {
    /*
    On initialise et appelle les differentes fonctions de recherche pour BiblioLC et BiblioH,
    tout en notant le temps pris à l'execution.
    */
    clock_t init1=clock();
    Biblio* b1=charger_n_entrees(FICHIER_TEST, n);
    clock_t init2=clock();

    clock_t init3=clock();
    BiblioH* b2=charger_n_entrees_h(FICHIER_TEST, n);
    clock_t init4=clock();

    clock_t cherche_num1=clock();
    Livre *l1=rechercher_num(b1, n-797);
    clock_t cherche_num2=clock();
    
    clock_t cherche_num3=clock();
    LivreH *l2=rechercher_num_h(b2, n-797);
    clock_t cherche_num4=clock();
    
    clock_t cherche_titre1=clock();
    Livre *l3=rechercher_titre(b1->L, "cmro");
    clock_t cherche_titre2=clock();
    
    clock_t cherche_titre3=clock();
    LivreH *l4=rechercher_titre_h(b2, "cmro");
    clock_t cherche_titre4=clock();
    
    clock_t cherche_auteur1=clock();
    Biblio *l5=rechercher_auteur(b1, "ESUMVN");
    clock_t cherche_auteur2=clock();
    
    clock_t cherche_auteur3=clock();
    BiblioH *l6=rechercher_auteur_h(b2, "ESUMVN");
    clock_t cherche_auteur4=clock();

    /*On écrit les différents temps pour BiblioLC et BiblioH dans chacun des fichiers correspondants*/
    fprintf(finit, "%d %.6f %.6f\n", n, (double) (init2-init1)/CLOCKS_PER_SEC, (double) (init4-init3)/CLOCKS_PER_SEC);
    fprintf(fnum, "%d %.6f %.6f\n", n, (double) (cherche_num2-cherche_num1)/CLOCKS_PER_SEC, (double) (cherche_num4-cherche_num3)/CLOCKS_PER_SEC);
    fprintf(ftitre, "%d %.6f %.6f\n", n, (double) (cherche_titre2-cherche_titre1)/CLOCKS_PER_SEC, (double) (cherche_titre4-cherche_titre3)/CLOCKS_PER_SEC);
    fprintf(fauteur, "%d %.6f %.6f\n", n, (double) (cherche_auteur2-cherche_auteur1)/CLOCKS_PER_SEC, (double) (cherche_auteur4-cherche_auteur3)/CLOCKS_PER_SEC);
    
    liberer_biblio(b1);
    liberer_biblio(l5);
    liberer_biblio_h(l6);
    liberer_biblio_h(b2);
}

int main() {
    FILE *f1, *f2, *f3, *f4;
    /*On initialise des variables FILE pour chaque fichiers de temps*/
    f1=fopen("sortie_init.txt","w");
    f2=fopen("sortie_num.txt","w");
    f3=fopen("sortie_titre.txt","w");
    f4=fopen("sortie_auteur.txt","w");
    
    
    for(int i=1; i<100; i++) {
        compare(f1,f2,f3,f4,10000+i*200);
    }
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    return 0;
}