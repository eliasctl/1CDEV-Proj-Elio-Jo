#include <stdio.h>
#include <stdlib.h>

// tableau du jeu {valeur(-1 vide / 0 start / nb Valeur), couleur(1 bleu / 2 rouge)}

int niveau1()
{
    printf("Niveau 1\n");
    int bjeu[1][4][2] = {{{0, 1}, {1, 0}, {1, 0}, {1, 0}}};
    int jeu[1][4][2] = {{{0, 1}, {1, 0}, {1, 0}, {1, 0}}};
    int x = 1;
    int y = 4;
    int posx = 0;
    int posy = 0;
    int bpx = posx;
    int bpy = posy;
    int possible = 0;
    int fin = 0;
    int couleurs = 1;
    int couleur = 1;
    int dxc2 = 0;
    int dyc2 = 0;
    while (fin == 0)
    {
        // affichage du jeu
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {   
                // affichage en couleur
                if (jeu[i][j][1] == 1)
                {
                    printf("\033[1;34m");
                }
                else if (jeu[i][j][1] == 2)
                {
                    printf("\033[1;31m");
                }
                //affichage de parenthèse si c'est la case actuelle
                if (i == posx && j == posy)
                {
                    printf("(");
                }
                else
                {
                    printf(" ");
                }
                // affichage des valeurs
                if (jeu[i][j][0] == 0)
                {
                    printf("S");
                }
                else if (jeu[i][j][0] == -1)
                {
                    printf(" ");
                }
                else
                {
                    printf("%d", jeu[i][j][0]);
                }
                //fin valeur
                if (i == posx && j == posy)
                {
                    printf(")");
                }
                else
                {
                    printf(" ");
                }
                // fin parenthèse
                printf("\033[0m");
                // fin couleur
            }
            printf("\n\n");
        }
        // fin affichage
        // Déplacements possibles
        printf("Pour vous déplacer, utilisez les touches Z, Q, S, D\n");
        printf("Pour quitter le jeu faites [ctl]+[C]\n");
        printf("Pour recommencer le niveau appuillez sur R\n");
        printf("Pour changer de chaine de couleur C\n");
        printf("Pour valider votre choix, appuyez sur [entrée]\n");
        char c;
        scanf("%c", &c);
        printf("\n");


        switch (c)
        {
        case 'z':
            if (posx - 1 >= 0)
            {
                if (jeu[posx - 1][posy][0] > 0)
                {
                    if (jeu[posx - 1][posy][0] >= jeu[posx][posy][0]){
                        if (jeu[posx - 1][posy][1] == 0){
                            possible = 1;
                        }
                    }
                }
            }
            if (possible == 1)
            {
                jeu[posx - 1][posy][1] = jeu[posx][posy][1];
                posx--;
            } else {
                printf("Déplacement impossible\n");
            }
            break;
        case 'q':
            if (posy - 1 >= 0)
            {
                if (jeu[posx][posy - 1][0] > 0)
                {
                    if (jeu[posx][posy - 1][0] >= jeu[posx][posy][0]){
                        if (jeu[posx][posy - 1][1] == 0){
                            possible = 1;
                        }
                    }
                }
            }
            if (possible == 1)
            {
                jeu[posx][posy - 1][1] = jeu[posx][posy][1];
                posy--;
            } else {
                printf("Déplacement impossible\n");
            }
            break;
        case 's':
            if (posx + 1 < x)
            {
                if (jeu[posx + 1][posy][0] > 0)
                {
                    if (jeu[posx + 1][posy][0] >= jeu[posx][posy][0]){
                        if (jeu[posx + 1][posy][1] == 0)
                        {
                            possible = 1;
                        }
                    }
                }
            }
            if (possible == 1)
            {
                jeu[posx + 1][posy][1] = jeu[posx][posy][1];
                posx++;
            } else {
                printf("Déplacement impossible\n");
            }
            break;
        case 'd':
            if (posy + 1 < y)
            {
                if (jeu[posx][posy + 1][0] > 0)
                {
                    if (jeu[posx][posy + 1][0] >= jeu[posx][posy][0]){
                        if (jeu[posx][posy + 1][1] == 0)
                        {
                            possible = 1;
                        }
                    }
                }
            }
            if (possible == 1)
            {
                jeu[posx][posy + 1][1] = jeu[posx][posy][1];
                posy++;
            } else {
                printf("Déplacement impossible\n");
            }
            break;
        case 'r':
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    jeu[i][j][0] = bjeu[i][j][0];
                    jeu[i][j][1] = bjeu[i][j][1];
                }
            }
            posx = bpx;
            posy = bpy;
            printf("recommencer\n");
            break;
        case 'c':
            if (couleur == 1 && couleurs ==2)
            {
                couleur = 2;
                posx = dxc2;
                posy = dyc2;
            }
            else
            {
                printf("Vous ne pouvez pas changer de couleur\n");
            }
            break;
        }
        c = '0';
        possible = 0;
        // fin déplacements
        // fin du jeu
        fin = 1;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (jeu[i][j][0] > 0)
                {
                    if (jeu[i][j][1] == 0)
                    {
                        fin = 0;
                    }
                }
            }
        }
    }
    return 0;
}

int niveau2()
{
    printf("Niveau 2\n");
    int bjeu[3][3][2] = {{{-1, 0}, {-1, 0}, {1, 0}}, {{1, 0}, {1, 0}, {1, 0}},{{0, 1}, {-1, 0}, {-1, 0}}};
    int jeu[3][3][2] = {{{-1, 0}, {-1, 0}, {1, 0}}, {{1, 0}, {1, 0}, {1, 0}},{{0, 1}, {-1, 0}, {-1, 0}}};
    int x = 3;
    int y = 3;
    int posx = 2;
    int posy = 0;
    int bpx = posx;
    int bpy = posy;
    int possible = 0;
    int fin = 0;
    int couleurs = 1;
    int couleur = 1;
    int dxc2 = 0;
    int dyc2 = 0;
    while (fin == 0)
    {
        // affichage du jeu
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {   
                // affichage en couleur
                if (jeu[i][j][1] == 1)
                {
                    printf("\033[1;34m");
                }
                else if (jeu[i][j][1] == 2)
                {
                    printf("\033[1;31m");
                }
                //affichage de parenthèse si c'est la case actuelle
                if (i == posx && j == posy)
                {
                    printf("(");
                }
                else
                {
                    printf(" ");
                }
                // affichage des valeurs
                if (jeu[i][j][0] == 0)
                {
                    printf("S");
                }
                else if (jeu[i][j][0] == -1)
                {
                    printf(" ");
                }
                else
                {
                    printf("%d", jeu[i][j][0]);
                }
                //fin valeur
                if (i == posx && j == posy)
                {
                    printf(")");
                }
                else
                {
                    printf(" ");
                }
                // fin parenthèse
                printf("\033[0m");
                // fin couleur
            }
            printf("\n\n");
        }
        // fin affichage
        // Déplacements possibles
        printf("Pour vous déplacer, utilisez les touches Z, Q, S, D\n");
        printf("Pour quitter le jeu faites [ctl]+[C]\n");
        printf("Pour recommencer le niveau appuillez sur R\n");
        printf("Pour changer de chaine de couleur C\n");
        printf("Pour valider votre choix, appuyez sur [entrée]\n");
        char c;
        scanf("%c", &c);
        printf("\n");


        switch (c)
        {
        case 'z':
            if (posx - 1 >= 0)
            {
                if (jeu[posx - 1][posy][0] > 0)
                {
                    if (jeu[posx - 1][posy][0] >= jeu[posx][posy][0]){
                        if (jeu[posx - 1][posy][1] == 0){
                            possible = 1;
                        }
                    }
                }
            }
            if (possible == 1)
            {
                jeu[posx - 1][posy][1] = jeu[posx][posy][1];
                posx--;
            } else {
                printf("Déplacement impossible\n");
            }
            break;
        case 'q':
            if (posy - 1 >= 0)
            {
                if (jeu[posx][posy - 1][0] > 0)
                {
                    if (jeu[posx][posy - 1][0] >= jeu[posx][posy][0]){
                        if (jeu[posx][posy - 1][1] == 0){
                            possible = 1;
                        }
                    }
                }
            }
            if (possible == 1)
            {
                jeu[posx][posy - 1][1] = jeu[posx][posy][1];
                posy--;
            } else {
                printf("Déplacement impossible\n");
            }
            break;
        case 's':
            if (posx + 1 < x)
            {
                if (jeu[posx + 1][posy][0] > 0)
                {
                    if (jeu[posx + 1][posy][0] >= jeu[posx][posy][0]){
                        if (jeu[posx + 1][posy][1] == 0)
                        {
                            possible = 1;
                        }
                    }
                }
            }
            if (possible == 1)
            {
                jeu[posx + 1][posy][1] = jeu[posx][posy][1];
                posx++;
            } else {
                printf("Déplacement impossible\n");
            }
            break;
        case 'd':
            if (posy + 1 < y)
            {
                if (jeu[posx][posy + 1][0] > 0)
                {
                    if (jeu[posx][posy + 1][0] >= jeu[posx][posy][0]){
                        if (jeu[posx][posy + 1][1] == 0)
                        {
                            possible = 1;
                        }
                    }
                }
            }
            if (possible == 1)
            {
                jeu[posx][posy + 1][1] = jeu[posx][posy][1];
                posy++;
            } else {
                printf("Déplacement impossible\n");
            }
            break;
        case 'r':
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    jeu[i][j][0] = bjeu[i][j][0];
                    jeu[i][j][1] = bjeu[i][j][1];
                }
            }
            posx = bpx;
            posy = bpy;
            printf("recommencer\n");
            break;
        case 'c':
            if (couleur == 1 && couleurs ==2)
            {
                couleur = 2;
                posx = dxc2;
                posy = dyc2;
            }
            else
            {
                printf("Vous ne pouvez pas changer de couleur\n");
            }
            break;
        }
        c = '0';
        possible = 0;
        // fin déplacements
        // fin du jeu
        fin = 1;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (jeu[i][j][0] > 0)
                {
                    if (jeu[i][j][1] == 0)
                    {
                        fin = 0;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    niveau1();
    printf("Vous avez gagné\n");
    // suite niveau
    niveau2();
    printf("Vous avez gagné\n");


    return 0;
}
