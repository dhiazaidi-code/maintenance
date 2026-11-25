#include<stdio.h>
#include<stdlib.h>

typedef struct Equipement{
    int id;
    
    char etat[];
}Equipement;

/*void gestion_equipements(){
    int a;
    int valide; 
    system("color 2A");// Change la couleur : 0 = Fond Noir, B = Texte Cyan clair

    printf("\n\n");
    printf("\t====================================================================\n");
    printf("\t|                                                                  |\n");
    printf("\t|  [1] Ajouter des équipements                                     |\n");
    printf("\t|  [2] Supprimer des équipements                                   |\n");
    printf("\t|  [3] Modifier des équipements                                    |\n");
    printf("\t|  [4] Affichier les éequipements                                  |\n");
    printf("\t|  [5] Trouver un équipement                                       |\n");
    printf("\t|  [6] Retour                                                      |\n");
    printf("\t|                                                                  |\n");
    printf("\t====================================================================\n\n");
    do {
        printf("\t>>> Choisissez le numéro correspondant à la gestion souhaitée (1-5) : ");
        valide = scanf("%d", &a);


        if (valide != 1 || a < 1 || a > 6) {
            printf("\n\t[!] Choix non valide.\n");
        }

    } while (valide != 1 || a < 1 || a > 6);

    if (a=1)
    {
        ajouter_equipement();
    }
    else if(a=2){
        supprimer_equipement();
    }
    else if(a=3){
        modifier_equipement();
    }
    else if(a=4){
        afficher_equipement();
    }
    else if (a=5)
    {
        trouver_equipement();
    }
    else {retour();}
    
    
}

Equipement Equipements[50];

/*void sousmenu(){

    if (choix=1)
    {
        gestion_equipement();
    }
    else if(choix=2){
        gestion_deamndes();
    }
    else if(choix=3){
        gestion_File();
    }
    else if(choix=4){
        gestion_operation();
    }
    else {
        Historique();
    }
    
}*/
/*void gestion_des_demandes_maintenance(){
    int a;
    int valide; 
    system("color 8");

    printf("\n\n");
    printf("\t====================================================================\n");
    printf("\t|                                                                  |\n");
    printf("\t|  [1] Ajouter une deman                                           |\n");
    printf("\t|  [2] Modifier une demande                                        |\n");
    printf("\t|  [3] Supprimer les demande                                       |\n");
    printf("\t|  [4] Afficher les demandes                                       |\n");
    printf("\t|  [5] Retourner                                                   |\n");
    printf("\t|                                                                  |\n");
    printf("\t====================================================================\n\n");
    do {
        printf("\t>>> Choisissez le numéro correspondant à la gestion souhaitée (1-4) : ");
        valide = scanf("%d", &a);


        if (valide != 1 || a < 1 || a > 4) {
            printf("\n\t[!] Choix non valide.\n");
        }

    } while (valide != 1 || a < 1 || a > 4);
    if (a=1)
    {ajouter_demande();}
    else if (a=2){modifier_demande();}
    else if (a=3){supprimer_demande();}
    else if (a=4){afficher_demande();}
    else {retour();}
    
}*/
void menu(){
    int a;
    int valide; 
    system("color 0B");

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

 
}



int main(){
    menu();
    return 0;
}
