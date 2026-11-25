#include <stdio.h>
#include <stdlib.h>

int menu() {
    int a;
    int valide; 
    system("color 0B");// Change la couleur : 0 = Fond Noir, B = Texte Cyan clair

        printf("\n\n");
        printf("\t====================================================================\n");
        printf("\t|               SYSTEME DE GESTION DE LA MAINTENANCE               |\n");
        printf("\t====================================================================\n");
        printf("\t|                                                                  |\n");
        printf("\t|  [1] Gestion des équipements                                     |\n");
        printf("\t|  [2] Gestion des demandes de maintenance                         |\n");
        printf("\t|  [3] Gestion de la file des interventions selon les priorités    |\n");
        printf("\t|  [4] Gestion des opérations de maintenance                       |\n");
        printf("\t|  [5] Gestion de l'historique et des statistiques                 |\n");
        printf("\t|                                                                  |\n");
        printf("\t====================================================================\n\n");
    do {
        printf("\t>>> Choisissez le numéro correspondant à la gestion souhaitée (1-5) : ");
        valide = scanf("%d", &a);


        if (valide != 1 || a < 1 || a > 5) {
            printf("\n\t[!] Choix non valide.\n");
        }

    } while (valide != 1 || a < 1 || a > 5);

    return a; 
}

int main() {
    int c;
    c = menu();
    return 0;
}
