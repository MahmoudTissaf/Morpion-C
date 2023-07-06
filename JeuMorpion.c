#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Vérifie si l'un des joueurs a gagné et affiche le gagnant le cas échéant
int combinaisonGagnante(int grille[3][3])
{
    int s1, s2, s3, s4, s5, s6, s7, s8;

    // Vérification des lignes
    s1 = grille[0][0] + grille[0][1] + grille[0][2];
    s2 = grille[1][0] + grille[1][1] + grille[1][2];
    s3 = grille[2][0] + grille[2][1] + grille[2][2];

    // Vérification des colonnes
    s4 = grille[0][0] + grille[1][0] + grille[2][0];
    s5 = grille[0][1] + grille[1][1] + grille[2][1];
    s6 = grille[0][2] + grille[1][2] + grille[2][2];

    // Vérification des diagonales
    s7 = grille[0][0] + grille[1][1] + grille[2][2];
    s8 = grille[0][2] + grille[1][1] + grille[2][0];

    if (s1 == 3 || s2 == 3 || s3 == 3 || s4 == 3 || s5 == 3 || s6 == 3 || s7 == 3 || s8 == 3)
    {
        printf("Le joueur X a gagne.\n");
        return 1;
    }
    else if (s1 == 0 || s2 == 0 || s3 == 0 || s4 == 0 || s5 == 0 || s6 == 0 || s7 == 0 || s8 == 0)
    {
        printf("Le joueur O a gagne.\n");
        return 1;
    }

    return 0;
}

// Vérifie s'il n'y a plus de mouvement possible et affiche "Egalite" le cas échéant
int pasDeMouvementPossible(int grille[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grille[i][j] == -1)
            {
                return 0;
            }
        }
    }

    printf("Egalite !\n");
    return 1;
}

// Affiche la grille de jeu
void afficherGrille(int grille[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", (grille[i][0] == -1) ? ' ' : (grille[i][0] == 0) ? 'O' : 'X',
                                   (grille[i][1] == -1) ? ' ' : (grille[i][1] == 0) ? 'O' : 'X',
                                   (grille[i][2] == -1) ? ' ' : (grille[i][2] == 0) ? 'O' : 'X');
        if (i < 2)
        {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int main()
{
    int grille[3][3];
    int ligne, colonne, joueur = 0;

    // Initialisation de la grille avec des cases vides
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grille[i][j] = -1;
        }
    }

    // Boucle principale du jeu
    while (!combinaisonGagnante(grille) && !pasDeMouvementPossible(grille))
    {
        afficherGrille(grille);

        // Demande au joueur de choisir une case
        printf("Joueur %d, choisissez une case (ligne colonne) : ", joueur + 1);
        scanf("%d %d", &ligne, &colonne);

        // Vérifie si la case est valide et libre
        if (ligne >= 0 && ligne < 3 && colonne >= 0 && colonne < 3 && grille[ligne][colonne] == -1)
        {
            grille[ligne][colonne] = joueur;
            joueur = (joueur + 1) % 2; // Change de joueur à chaque tour
        }
        else
        {
            printf("Case invalide. Veuillez choisir une case libre.\n");
        }
    }

    afficherGrille(grille);

    return 0;
}
