#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int id_equipement;
    char date_demande[11]; // JJ/MM/AAAA + '\0'
    char type[15];         // Preventive ou corrective
    char statut[20];       // En attente, Acceptee, Refusee
    char priorite[20];     // Haute, Moyenne, Basse
} Demande;

typedef struct NoeudDemande {
    Demande val;
    struct NoeudDemande *suivant;
} NoeudDemande;

NoeudDemande* ajouterDemande(NoeudDemande *tete) {
    NoeudDemande *nouveau = (NoeudDemande*) malloc(sizeof(NoeudDemande));

    Demande d; // Variable locale de type Demande

    printf("\n\t--- AJOUTER UNE DEMANDE DE MAINTENANCE ---\n");

    printf("\tID de la demande : ");
    scanf("%d", &d.id);

    printf("\tID de l'equipement concerne : ");
    scanf("%d", &d.id_equipement);

    printf("\tDate de la demande (JJ/MM/AAAA) : ");
    scanf("%10s", d.date_demande);

    printf("\tType (Preventive / corrective) : ");
    scanf("%14s", d.type);

    strcpy(d.statut, "En attente");

    printf("\tPriorite (Haute, Moyenne, Basse) : ");
    scanf("%19s", d.priorite);
    printf("\n\t=============================================\n");
printf("\t  Demande de maintenance ajoutee avec succes !\n");
printf("\t=============================================\n");

    // Copie de la structure locale d vers le nouveau noeud
    nouveau->val = d;

    // Insertion en tete de liste
    nouveau->suivant = tete;
    return nouveau;
}




NoeudDemande* supprimerDemande(NoeudDemande *tete) {
    if (tete == NULL) {
        printf("\n\tLa liste des demandes est vide. Rien a supprimer.\n");
        return NULL;
    }

    int id_cible;
    printf("\n\t--- SUPPRIMER UNE DEMANDE DE MAINTENANCE ---\n");
    printf("\tEntrez l'ID de la demande a supprimer : ");
    scanf("%d", &id_cible);

    NoeudDemande *courant = tete;
    NoeudDemande *precedent = NULL;

    // Recherche du noeud ayant l'ID cible
    while (courant != NULL && courant->val.id != id_cible) {
        precedent = courant;
        courant = courant->suivant;
    }

    // Cas 1 : ID introuvable
    if (courant == NULL) {
        printf("\n\tAucune demande trouvee avec l'ID %d.\n", id_cible);
        return tete;
    }

    // Cas 2 : suppression en tete de liste
    if (precedent == NULL) {
        tete = courant->suivant;
    } else {
        // Cas 3 : suppression au milieu ou a la fin
        precedent->suivant = courant->suivant;
    }

    free(courant);

    printf("\n\t+---------------------------------------------+\n");
    printf("\t|   Demande  supprimee avec succes !          |\n");
    printf("\t+---------------------------------------------+\n");

    return tete;
}


void changer_Statut_Demande(NoeudDemande *tete) {
    if (tete == NULL) {
        printf("\n\tLa liste des demandes est vide.\n");
        return;
    }

    int id_cible;
    printf("\n\t--- CHANGER LE STATUT D'UNE DEMANDE ---\n");
    printf("\tEntrez l'ID de la demande : ");
    scanf("%d", &id_cible);

    NoeudDemande *courant = tete;
    while (courant != NULL && courant->val.id != id_cible) {
        courant = courant->suivant;
    }

    if (courant == NULL) {
        printf("\n\tAucune demande trouvee avec l'ID %d.\n", id_cible);
        return;
    }

    printf("\tStatut actuel : %s\n", courant->val.statut);

    int choix;
    printf("\tChoisissez le nouveau statut :\n");
    printf("\t  1. En attente\n");
    printf("\t  2. Acceptee\n");
    printf("\t  3. Refusee\n");
    printf("\tVotre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            strcpy(courant->val.statut, "En attente");
            break;
        case 2:
            strcpy(courant->val.statut, "Acceptee");
            break;
        case 3:
            strcpy(courant->val.statut, "Refusee");
            break;
        default:
            printf("\n\tChoix invalide. Le statut n'a pas ete modifie.\n");
            return;
    }

    printf("\n\t+-------------------------------------------------------+\n");
    printf("\t|   Statut de la demande  mis a jour avec succes     |\n");
    printf("\t+-------------------------------------------------------+\n");
}



void rechercherDemande(NoeudDemande *tete) {
    if (tete == NULL) {
        printf("\n\tLa demande n'existe pas (la liste des demandes est vide).\n");
        return;
    }

    int id_cible;
    printf("\n\t--- RECHERCHER UNE DEMANDE DE MAINTENANCE ---\n");
    printf("\tEntrez l'ID de la demande a rechercher : ");
    scanf("%d", &id_cible);

    NoeudDemande *courant = tete;
    while (courant != NULL && courant->val.id != id_cible) {
        courant = courant->suivant;
    }

    if (courant == NULL) {
        printf("\n\t+-----------------------------------------------------+\n");
        printf("\t|          La demande  n'existe pas.                  |\n");
        printf("\t+-----------------------------------------------------+\n");
        return;
    }

    printf("\n\t+-----------------------------------------------------+\n");
    printf("\t|           La demande  existe !                      |\n" );
    printf("\t+-----------------------------------------------------+\n");
    printf("\t  ID demande     : %d\n", courant->val.id);
    printf("\t  ID equipement  : %d\n", courant->val.id_equipement);
    printf("\t  Date demande   : %s\n", courant->val.date_demande);
    printf("\t  Type           : %s\n", courant->val.type);
    printf("\t  Statut         : %s\n", courant->val.statut);
    printf("\t  Priorite       : %s\n", courant->val.priorite);
    printf("\t+-----------------------------------------------------+\n");
}





void afficher_Demandes_Par_Statut(NoeudDemande *tete) {
    if (tete == NULL) {
        printf("\n\tLa liste des demandes est vide.\n");
        return;
    }

    char statut_cible[20];
    int choix;

    printf("\n\t--- AFFICHER LES DEMANDES PAR STATUT ---\n");
    printf("\tChoisissez le statut a afficher :\n");
    printf("\t  1. En attente\n");
    printf("\t  2. Acceptee\n");
    printf("\t  3. Refusee\n");
    printf("\t  4. Toutes les demandes\n");
    printf("\tVotre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            strcpy(statut_cible, "En attente");
            break;
        case 2:
            strcpy(statut_cible, "Acceptee");
            break;
        case 3:
            strcpy(statut_cible, "Refusee");
            break;
        case 4:
            strcpy(statut_cible, "Toutes");
            break;
        default:
            printf("\n\tChoix invalide.\n");
            return;
    }

    NoeudDemande *courant = tete;
    int compteur = 0;

    if (choix == 4) {
        printf("\n\t=== Toutes les demandes ===\n");
    } else {
        printf("\n\t=== Demandes avec le statut : %s ===\n", statut_cible);
    }

    while (courant != NULL) {
        if (choix == 4 || strcmp(courant->val.statut, statut_cible) == 0) {
            compteur++;
            printf("\n\t+-----------------------------------------------------+\n");
            printf("\t|  Demande #%d                                        |\n", courant->val.id);
            printf("\t+-----------------------------------------------------+\n");
            printf("\t  ID equipement  : %d\n", courant->val.id_equipement);
            printf("\t  Date demande   : %s\n", courant->val.date_demande);
            printf("\t  Type           : %s\n", courant->val.type);
            printf("\t  Statut         : %s\n", courant->val.statut);
            printf("\t  Priorite       : %s\n", courant->val.priorite);
            printf("\t+-----------------------------------------------------+\n");
        }
        courant = courant->suivant;
    }

    if (compteur == 0) {
        if (choix == 4) {
            printf("\n\tAucune demande trouvee.\n");
        } else {
            printf("\n\tAucune demande trouvee avec le statut \"%s\".\n", statut_cible);
        }
    } else {
        printf("\n\tTotal : %d demande(s) affichee(s).\n", compteur);
    }
}


void menu(NoeudDemande *tete);

void gestionDemandes(NoeudDemande *tete) {
    int choix;

    system("color 0B");

    do {
        printf("\n\t+====================================================+\n");
        printf("\t|        GESTION DES DEMANDES DE MAINTENANCE         |\n");
        printf("\t+====================================================+\n");
        printf("\t|  1. Ajouter une demande                            |\n");
        printf("\t|  2. Supprimer une demande                          |\n");
        printf("\t|  3. Changer le statut d'une demande                |\n");
        printf("\t|  4. Rechercher une demande par ID                  |\n");
        printf("\t|  5. Afficher les demandes                          |\n");
        printf("\t|  0. Retour au menu principal                       |\n");
        printf("\t+====================================================+\n");

        do {
            printf("\n\tVotre choix : ");
            scanf("%d", &choix);
            if (choix < 0 || choix > 5) {
                printf("\n\t[!] Choix non valide.\n");
            }
        } while (choix < 0 || choix > 5);

        switch (choix) {
            case 1:
                tete = ajouterDemande(tete);
                break;
            case 2:
                tete = supprimerDemande(tete);
                break;
            case 3:
                changer_Statut_Demande(tete);
                break;
            case 4:
                rechercherDemande(tete);
                break;
            case 5:
                afficher_Demandes_Par_Statut(tete);
                break;
            case 0:
                printf("\n\tRetour au menu principal...\n");menu(tete);
                break;
        }
    } while (choix != 0);
}


void menu(NoeudDemande *tete) {
    int a;
    int valide;
    system("color 0B"); // Fond Noir, Texte Cyan clair

    
        system("cls"); // Efface l'écran à chaque retour au menu
        printf("\n\n");
        printf("\t------------------------------------------------------------------\n");
        printf("\t|               SYSTEME DE GESTION DE LA MAINTENANCE             |\n");
        printf("\t------------------------------------------------------------------\n");
        printf("\t|                                                                |\n");
        printf("\t|  [1] Gestion des equipements                                   |\n");
        printf("\t|  [2] Gestion des demandes de maintenance                       |\n");
        printf("\t|  [3] Gestion de la file des interventions selon les priorites  |\n");
        printf("\t|  [4] Gestion des operations de maintenance                     |\n");
        printf("\t|  [5] Gestion de l'historique et des statistiques               |\n");
        printf("\t|  [6] Quitter                                                   |\n");
        printf("\t|                                                                |\n");
        printf("\t------------------------------------------------------------------\n");

        do {
            printf("\n\t>>> Choisissez le numero correspondant a la gestion souhaitee (1-6) : ");
            valide = scanf("%d", &a);
            if (valide != 1 || a < 1 || a > 6) {
                printf("\n\t[!] Choix non valide.\n");
            }
        } while (valide != 1 || a < 1 || a > 6);

        switch (a) {
            case 1:
               
                break;
            case 2:gestionDemandes(tete);
                
                break;
            case 3:
               
                break;
            case 4:
                
                break;
            case 5:
               
                break;
            case 6:
                printf("\n\tFermeture du programme. Au revoir !\n");
                break;
        }

}
    

int main() {
    NoeudDemande *tete = NULL;
    menu(tete);

    return 0;
}
