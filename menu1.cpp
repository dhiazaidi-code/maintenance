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
/*void gestion_file_intervention(){
    int a;
    int valide; 
    system("color 2A");// Change la couleur : 0 = Fond Noir, B = Texte Cyan clair

    printf("\n\n");
    printf("\t====================================================================\n");
    printf("\t|                                                                  |\n");
    printf("\t|  [1] Ajouter dans la file selon la prioriteé                     |\n");
    printf("\t|  [2] Retirer de la file                                          |\n");
    printf("\t|  [3] Afficher la file                                            |\n");
    printf("\t|  [4] Rechercher dans la file                                     |\n");
    printf("\t|  [5] Retour                                                      |\n");
    printf("\t|                                                                  |\n");
    printf("\t====================================================================\n\n");
    do {
        printf("\t>>> Choisissez le numéro correspondant à la gestion souhaitée (1-5) : ");
        valide = scanf("%d", &a);


        if (valide != 1 || a < 1 || a > 5) {
            printf("\n\t[!] Choix non valide.\n");
        }

    } while (valide != 1 || a < 1 || a > 5);

    if (a=1)
    {
        ajouter_file_prioritaire();
    }
    else if(a=2){
        retirer_file_prioritaie();}
    else if(a=3){
        afficher_file_prioritaie();
    }
    else if(a=4){
        rechercher_dans_file();
    }
    else {retour();}
    
}*/
/*void Historiqe(){
    int a;
    int valide; 
    system("color 2A");// Change la couleur : 0 = Fond Noir, B = Texte Cyan clair

    printf("\n\n");
    printf("\t====================================================================\n");
    printf("\t|                                                                  |\n");
    printf("\t|  [1] Afficher l'historique                                       |\n");
    printf("\t|  [2] Rechercher dans l'historique                                |\n");
    printf("\t|  [3] Calculer le nombre d'intervention                           |\n");
    printf("\t|  [4] Affichier les statistiques                                  |\n");
    printf("\t|  [5] Retour                                                      |\n");
    printf("\t|                                                                  |\n");
    printf("\t====================================================================\n\n");
    do {
        printf("\t>>> Choisissez le numéro correspondant à la gestion souhaitée (1-5) : ");
        valide = scanf("%d", &a);


        if (valide != 1 || a < 1 || a > 5) {
            printf("\n\t[!] Choix non valide.\n");
        }

    } while (valide != 1 || a < 1 || a > 5);

    if (a=1)
    {
        afficher_historique();
    }
    else if(a=2){
        rechercher_historique();
    }
    else if(a=3){
        nombre_interventions();
    }
    else if(a=4){
        afficher_statistique();

    else {retour();}
    
    
}*/
/*void gestion_operation_maintenances(){
    int a;
    int valide; 
    system("color 5");// Change la couleur : 0 = Fond Noir, B = Texte Cyan clair

    printf("\n\n");
    printf("\t====================================================================\n");
    printf("\t|                                                                  |\n");
    printf("\t|  [1] Faire des interventions                                     |\n");
    printf("\t|  [2] Supprimer des interventions                                 |\n");
    printf("\t|  [3] Modifier une intervention                                   |\n");
    printf("\t|  [4] Affichier les interventions                                 |\n");
    printf("\t|  [5] Annuler l'intervention(Retour)                              |\n");
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
        faire_intervention();
    }
    else if(a=2){
        supprimer_intervention();
    }
    else if(a=3){
        modifier_intervention();
    }
    else if(a=4){
        afficher_intervention();
    }

    else {retour();}     
}
*/
/*void sous_menu(){
    int a;
    if (a==1){
        gestion_equipements();}

    else if (a==2){gestion_des_demandes_maintenance();}
    else if (a==3){gestion_file_intervention();}
    else if (a==4){gestion_operation_maintenances();}
    else {Historique();}
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
    //sous_menu();

 
}



int main(){
    menu();
    return 0;
}
