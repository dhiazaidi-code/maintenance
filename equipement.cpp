#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct equipement {
    int id;
    char nom[10];
    char etat[15];
} equipement;

typedef struct noeud {
    equipement eq;
    struct noeud *suiv;
} noeud;

void remplir(noeud **tete) {
    int n;
    printf("\n\t--- REMPLIR LA LISTE DES EQUIPEMENTS ---\n");
    printf("\tDonnez le nombre d'equipements : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\n\t[!] Nombre d'equipements invalide.\n");
        return;
    }

    noeud *p, *q;
    for (int i = 0; i < n; i++) {
        p = (noeud *)malloc(sizeof(noeud));
        if (p == NULL) {
            printf("\n\tErreur d'allocation memoire.\n");
            return;
        }

        printf("\n\t--- EQUIPEMENT #%d ---\n", i + 1);
        printf("\tID de l'equipement : ");
        scanf("%d", &p->eq.id);

        printf("\tNom de l'equipement : ");
        scanf("%9s", p->eq.nom);

        printf("\tEtat de l'equipement(en-marche/en-mantenaince/en-panne) : ");
        scanf("%14s", p->eq.etat);

        p->suiv = NULL;

        if (*tete == NULL) {
            *tete = p;
        } else {
            q = *tete;
            while (q->suiv != NULL) {
                q = q->suiv;
            }
            q->suiv = p;
        }
    }

    printf("\n\t=============================================\n");
    printf("\t  Equipements ajoutes avec succes !\n");
    printf("\t=============================================\n");
}

void ajouter_equipement(noeud **tete) {
    noeud *p, *q;
    p = (noeud *)malloc(sizeof(noeud));
    if (p == NULL) {
        printf("\n\tErreur d'allocation memoire.\n");
        return;
    }

    printf("\n\t--- AJOUTER UN EQUIPEMENT ---\n");
    printf("\tID de l'equipement : ");
    scanf("%d", &p->eq.id);

    printf("\tNom de l'equipement : ");
    scanf("%9s", p->eq.nom);

    printf("\tEtat de l'equipement (en-marche/en-mantenaince/en-panne) : ");
    scanf("%14s", p->eq.etat);

    p->suiv = NULL;

    if (*tete == NULL) {
        *tete = p;
    } else {
        q = *tete;
        while (q->suiv != NULL) {
            q = q->suiv;
        }
        q->suiv = p;
    }

    printf("\n\t=============================================\n");
    printf("\t  Equipement ajoute avec succes !\n");
    printf("\t=============================================\n");
}

void supprimer_equipement(noeud **tete) {
    if (tete == NULL || *tete == NULL) {
        printf("\n\tLa liste des equipements est vide. Rien a supprimer.\n");
        return;
    }

    int id;
    printf("\n\t--- SUPPRIMER UN EQUIPEMENT ---\n");
    printf("\tEntrez l'ID de l'equipement a supprimer : ");
    scanf("%d", &id);

    noeud *p = *tete;
    noeud *q = NULL;

    while (p != NULL && p->eq.id != id) {
        q = p;
        p = p->suiv;
    }

    if (p == NULL) {
        printf("\n\tAucun equipement trouve avec l'ID %d.\n", id);
        return;
    }

    if (q == NULL) {
        *tete = p->suiv;
    } else {
        q->suiv = p->suiv;
    }

    free(p);

    printf("\n\t+---------------------------------------------+\n");
    printf("\t|   Equipement supprime avec succes !         |\n");
    printf("\t+---------------------------------------------+\n");
}

void afficher_equipements(noeud *tete) {
    if (tete == NULL) {
        printf("\n\tLa liste des equipements est vide.\n");
        return;
    }

    noeud *p = tete;
    int compteur = 0;

    printf("\n\t=== Liste des equipements ===\n");

    while (p != NULL) {
        compteur++;
        printf("\n\t+-----------------------------------------------------+\n");
        printf("\t|  Equipement #%d                                      |\n", p->eq.id);
        printf("\t+-----------------------------------------------------+\n");
        printf("\t  ID   : %d\n", p->eq.id);
        printf("\t  Nom  : %s\n", p->eq.nom);
        printf("\t  Etat : %s\n", p->eq.etat);
        printf("\t+-----------------------------------------------------+\n");
        p = p->suiv;
    }

    printf("\n\tTotal : %d equipement(s) affiche(s).\n", compteur);
}

void changer_etat_equipement(noeud *tete) {
    if (tete == NULL) {
        printf("\n\tLa liste des equipements est vide.\n");
        return;
    }

    int id;
    printf("\n\t--- CHANGER L'ETAT D'UN EQUIPEMENT ---\n");
    printf("\tEntrez l'ID de l'equipement : ");
    scanf("%d", &id);

    noeud *p = tete;
    while (p != NULL && p->eq.id != id) {
        p = p->suiv;
    }

    if (p == NULL) {
        printf("\n\tAucun equipement trouve avec l'ID %d.\n", id);
        return;
    }

    printf("\tEtat actuel : %s\n", p->eq.etat);
    printf("\tEntrez le nouvel etat(en-marche/en-mantenaince/en-panne) : ");
    scanf("%14s", p->eq.etat);

    printf("\n\t+-------------------------------------------------------+\n");
    printf("\t|   Etat de l'equipement mis a jour avec succes         |\n");
    printf("\t+-------------------------------------------------------+\n");
}

void gestionequipement(noeud **tete) {
    int a;
    int valide;
    system("color 0B");

    printf("\n\n");
    printf("\t------------------------------------------------------------------\n");
    printf("\t|               SYSTEME DE GESTION DES EQUIPEMENTS               |\n");
    printf("\t------------------------------------------------------------------\n");
    printf("\t|                                                                |\n");
    printf("\t|  [1] Remplir la liste des equipements                          |\n");
    printf("\t|  [2] Ajouter un equipement                                     |\n");
    printf("\t|  [3] Supprimer un equipement                                   |\n");
    printf("\t|  [4] Afficher les equipements                                  |\n");
    printf("\t|  [5] Changer l'etat d'un equipement                            |\n");
    printf("\t|  [6] Retour au menu principal                                                   |\n");
    printf("\t|                                                                |\n");
    printf("\t------------------------------------------------------------------\n");

    do {
        printf("\n\t>>> Choisissez le numero correspondant a l'action souhaitee (1-6) : ");
        valide = scanf("%d", &a);
        if (valide != 1 || a < 1 || a > 6) {
            printf("\n\t[!] Choix non valide.\n");
        }
    } while (valide != 1 || a < 1 || a > 6);

    switch (a) {
        case 1:
            remplir(tete);
            gestionequipement(tete);
            break;
        case 2:
            ajouter_equipement(tete);
            gestionequipement(tete);
            break;
        case 3:
            supprimer_equipement(tete);
            gestionequipement(tete);
            break;
        case 4:
            afficher_equipements(*tete);
            gestionequipement(tete);
            break;
        case 5:
            changer_etat_equipement(*tete);
            gestionequipement(tete);
            break;
        case 6:
            //menu()
            break;
    }
}

int main(void) {
    noeud *tete = NULL;
    gestionequipement(&tete);
    return 0;
}
