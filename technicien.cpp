#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nom[30];
    char prenom[30];
    char specialite[50];
    char telephone[15];
    int disponibilite; // 1 : Disponible, 0 : Indisponible
} Technicien;

typedef struct NoeudTechnicien {
    Technicien val;
    struct NoeudTechnicien *suivant;
} NoeudTechnicien;

void ajouterTechnicien(NoeudTechnicien **tete) {
    NoeudTechnicien *nouveau, *courant;

    nouveau = (NoeudTechnicien*)malloc(sizeof(NoeudTechnicien));
    if (nouveau == NULL) {
        printf("\n[Erreur] Allocation memoire impossible !\n");
        return;
    }

    printf("\n--- Ajout d'un technicien ---\n");
    printf("Entrez l'ID du technicien : ");
    scanf("%d", &nouveau->val.id);

    printf("Entrez le nom : ");
    scanf("%29s", nouveau->val.nom);

    printf("Entrez le prenom : ");
    scanf("%29s", nouveau->val.prenom);

    printf("Entrez la specialite : ");
    scanf("%49s", nouveau->val.specialite);

    printf("Entrez le telephone : ");
    scanf("%14s", nouveau->val.telephone);

    nouveau->val.disponibilite = 1;
    nouveau->suivant = NULL;

    if (*tete == NULL) {
        *tete = nouveau;
    } else {
        courant = *tete;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = nouveau;
    }

    printf("\n[Succes] Le technicien est ajoute avec succes !\n");
}

void afficherTechniciens(NoeudTechnicien *tete) {
    NoeudTechnicien *courant = tete;

    if (tete == NULL) {
        printf("\n[Info] Aucun technicien enregistre pour le moment.\n");
        return;
    }

    printf("\n=== Liste des techniciens ===\n");
    while (courant != NULL) {
        printf("\nID           : %d", courant->val.id);
        printf("\nNom          : %s", courant->val.nom);
        printf("\nPrenom       : %s", courant->val.prenom);
        printf("\nSpecialite   : %s", courant->val.specialite);
        printf("\nTelephone    : %s", courant->val.telephone);
        printf("\nDisponibilite: %s\n",
               courant->val.disponibilite == 1 ? "Disponible" : "Indisponible");
        printf("----------------------------------\n");
        courant = courant->suivant;
    }
}

void rechercherTechnicien(NoeudTechnicien *tete) {
    NoeudTechnicien *courant = tete;
    int id;

    if (tete == NULL) {
        printf("\n[Info] Aucun technicien enregistre.\n");
        return;
    }

    printf("\n--- Recherche d'un technicien ---\n");
    printf("Entrez l'ID du technicien a rechercher : ");
    scanf("%d", &id);

    while (courant != NULL) {
        if (courant->val.id == id) {
            printf("\n[Succes] Technicien trouve :\n");
            printf("ID           : %d\n", courant->val.id);
            printf("Nom          : %s\n", courant->val.nom);
            printf("Prenom       : %s\n", courant->val.prenom);
            printf("Specialite   : %s\n", courant->val.specialite);
            printf("Telephone    : %s\n", courant->val.telephone);
            printf("Disponibilite: %s\n",
                   courant->val.disponibilite == 1 ? "Disponible" : "Indisponible");
            return;
        }
        courant = courant->suivant;
    }

    printf("\n[Attention] Aucun technicien trouve avec l'ID %d.\n", id);
}

void modifierTechnicien(NoeudTechnicien *tete) {
    NoeudTechnicien *courant = tete;
    int id;

    if (tete == NULL) {
        printf("\n[Info] Aucun technicien enregistre.\n");
        return;
    }

    printf("\n--- Modification d'un technicien ---\n");
    printf("Entrez l'ID du technicien a modifier : ");
    scanf("%d", &id);

    while (courant != NULL && courant->val.id != id) {
        courant = courant->suivant;
    }

    if (courant == NULL) {
        printf("\n[Attention] Aucun technicien trouve avec l'ID %d.\n", id);
        return;
    }

    printf("Entrez le nouveau nom : ");
    scanf("%29s", courant->val.nom);

    printf("Entrez le nouveau prenom : ");
    scanf("%29s", courant->val.prenom);

    printf("Entrez la nouvelle specialite : ");
    scanf("%49s", courant->val.specialite);

    printf("Entrez le nouveau telephone : ");
    scanf("%14s", courant->val.telephone);

    printf("\n[Succes] Le technicien est modifie avec succes !\n");
}

void supprimerTechnicien(NoeudTechnicien **tete) {
    NoeudTechnicien *courant = *tete;
    NoeudTechnicien *precedent = NULL;
    int id;

    if (*tete == NULL) {
        printf("\n[Info] Aucun technicien enregistre.\n");
        return;
    }

    printf("\n--- Suppression d'un technicien ---\n");
    printf("Entrez l'ID du technicien a supprimer : ");
    scanf("%d", &id);

    while (courant != NULL && courant->val.id != id) {
        precedent = courant;
        courant = courant->suivant;
    }

    if (courant == NULL) {
        printf("\n[Attention] Aucun technicien trouve avec l'ID %d.\n", id);
        return;
    }

    if (precedent == NULL) {
        *tete = courant->suivant;
    } else {
        precedent->suivant = courant->suivant;
    }

    free(courant);
    printf("\n[Succes] Le technicien est supprime avec succes !\n");
}

void afficherTechniciensDisponibles(NoeudTechnicien *tete) {
    NoeudTechnicien *courant = tete;
    int trouve = 0;

    printf("\n=== Techniciens disponibles ===\n");
    while (courant != NULL) {
        if (courant->val.disponibilite == 1) {
            printf("\nID         : %d", courant->val.id);
            printf("\nNom        : %s %s", courant->val.nom, courant->val.prenom);
            printf("\nSpecialite : %s\n", courant->val.specialite);
            printf("----------------------------------\n");
            trouve = 1;
        }
        courant = courant->suivant;
    }

    if (trouve==0) {
        printf("[Info] Aucun technicien disponible pour le moment.\n");
    }
}

void changerDisponibilite(NoeudTechnicien *tete) {
    NoeudTechnicien *courant = tete;
    int id;

    if (tete == NULL) {
        printf("\n[Info] Aucun technicien enregistre.\n");
        return;
    }

    printf("\n--- Changement de disponibilite ---\n");
    printf("Entrez l'ID du technicien : ");
    scanf("%d", &id);

    while (courant != NULL && courant->val.id != id) {
        courant = courant->suivant;
    }

    if (courant == NULL) {
        printf("\n[Attention] Aucun technicien trouve avec l'ID %d.\n", id);
        return;
    }

    courant->val.disponibilite = !courant->val.disponibilite;
    printf("\n[Succes] Disponibilite mise a jour : %s !\n",
           courant->val.disponibilite == 1 ? "Disponible" : "Indisponible");
}

void menuTechniciens(NoeudTechnicien **tete) {
    int choix;

    system("color 0B");

    do {
        printf("\n\t+====================================================+\n");
        printf("\t|             GESTION DES TECHNICIENS                |\n");
        printf("\t+====================================================+\n");
        printf("\t|  1. Ajouter un technicien                          |\n");
        printf("\t|  2. Afficher tous les techniciens                  |\n");
        printf("\t|  3. Rechercher un technicien par ID                |\n");
        printf("\t|  4. Modifier un technicien                         |\n");
        printf("\t|  5. Supprimer un technicien                        |\n");
        printf("\t|  6. Afficher les techniciens disponibles           |\n");
        printf("\t|  7. Changer la disponibilite d'un technicien       |\n");
        printf("\t|  0. Retour au menu principal                       |\n");
        printf("\t+====================================================+\n");

        do {
            printf("\n\tVotre choix : ");
            scanf("%d", &choix);
            if (choix < 0 || choix > 7) {
                printf("\n\t[!] Choix non valide.\n");
            }
        } while (choix < 0 || choix > 7);

        switch (choix) {
            case 1:
                ajouterTechnicien(tete);
                break;
            case 2:
                afficherTechniciens(*tete);
                break;
            case 3:
                rechercherTechnicien(*tete);
                break;
            case 4:
                modifierTechnicien(*tete);
                break;
            case 5:
                supprimerTechnicien(tete);
                break;
            case 6:
                afficherTechniciensDisponibles(*tete);
                break;
            case 7:
                changerDisponibilite(*tete);
                break;
            case 0:
                printf("\n\tRetour au menu principal...\n");
                break;
        }
    } while (choix != 0);
}


int main() {

    NoeudTechnicien *teteTechnicien = NULL;

    menuTechniciens(&teteTechnicien);

    return 0;
}
