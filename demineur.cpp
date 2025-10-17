#include <iostream>
#include <random>
#include <windows.h>

int getRandomNumber(int min, int max) // Prise Random d'un nombre
{
    std::random_device m_rd;
    std::mt19937 m_gen(m_rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(m_gen);
}

void BombPlacement(int Bomb, int* New_Tab, int Max) {
    std::cout << "\nInitialisation des bombes\n \n";
    for (int I = 0; I < Bomb; I++ ) {
        int rdm = getRandomNumber(0, Max-1);
        while (New_Tab[rdm] == -1) {
            rdm = getRandomNumber(0, Max-1);
        }
        New_Tab[rdm] = -1;
        std::cout << "Bombes Numero : " << I+1 << " / " << Bomb << "\n";
    }
}

int CalculNombreAutour(int* Tab, int Size) {
    for (int Y = 0; Y < Size; Y++) {
        for (int X = 0; X < Size; X++) {
            int Index = Y * Size + X;

            if (Tab[Index] != 1) {
                int TotalBombe = 0;

                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dx == 0 && dy == 0) {
                            continue;
                        }
                        int ny = Y + dy;
                        int nx = X + dx;

                        if (nx >= 0 && nx < Size && ny >= 0 && ny < Size) {
                            int VoisinIndex = ny * Size + nx;
                            if (Tab[VoisinIndex] == 1) {
                                TotalBombe++;
                            }
                        }
                    }
                }
                return TotalBombe;
            }
        }
    }
}

void ChoixCoordoonnee(int* Tab,int Size) {
    int x, y, verif, verification;
    verif = 1;
    while (verif == 1) {
        verification = 1;
        while (verification == 1) {
            std::cout << "\nCoordonnee X ( 0 a " << Size - 1 << ") : ";
            std::cin >> x;
            if (x >= 0 && x <= Size - 1) {
                verification = 0;
            }
            else {
                std::cout << "Non Accepter merci de recommencer \n";
            }
        }
        verification = 1;
        while (verification == 1) {
            std::cout << "\nCoordonnee y ( 0 a " << Size - 1 << ") : ";
            std::cin >> y;
            if (y >= 0 && y <= Size - 1) {
                verification = 0;
            }

            else {
                std::cout << "Non Accepter merci de recommencer \n";
            }
        }
        if (x >= 0 && x < Size && y >= 0 && y < Size) { // Verification coordonnée correcte
            Tab[y * Size + x] = true;
            break;
        }
        else {
            std::cout << "Coordonnees invalides. \n";
        }
    }
}


void Affichage(int* Tab, int Taille, int Longueur) {
    for (int i = 0; i < Taille; i++) {
        if (i % Longueur == 0) {
            std::cout << "\n";
        }
        if (Tab[i] == -1) {
            std::cout << "X ";
        }
        else {
            std::cout << ". ";
        }
    }
    std::cout << "\n";
}

int main()
{
    int Size,Bomb;
    int BombVoisin = 0;
    bool Verification = 1;
    bool Victoire, Defaite = 0;
    while (Verification == 1) {
        std::cout << "Taille de la grille ( entre 10 et +... ) : ";
        std::cin >> Size;
        if (Size >= 10) {
            std::cout << "Taille accepter \n";
            Verification = 0;
        }
        else {
            std::cout << "Non Accepter merci de recommencer \n";
        }
    }

    Verification = 1;
    while (Verification == 1) {
        std::cout << "Nombre de bombe ( entre 1 et " << (Size*Size)-1 <<" ) : ";
        std::cin >> Bomb;
        if (Bomb >= 1 && Bomb<=(Size*Size)-1) {
            std::cout << "Nombre de bombe accepter \n";
            Verification = 0;
        }
        else {
            std::cout << "Non Accepter merci de recommencer \n";
        }
    }
    int* Player_Grid = new int[Size * Size] {0};

    int* Bomb_Grid = new int[Size * Size] {0};

    // 
    //          Affichage des Grille vierge (Verification)
    // 

    std::cout << "\nGrid du joueur : \n";
    Affichage(Player_Grid, Size * Size, Size);
    std::cout << "\nGrid des bombes : \n";
    Affichage(Bomb_Grid, Size * Size, Size);
    
    // Position Joueur Initial

    std::cout << "\nPlacement des bombes \n";
    BombPlacement(Bomb, Bomb_Grid, Size*Size); // Mise en place des Bombes
    std::cout << "\nLes Bombes sont placer \n";

    // 
    //          Affichage des Grille Remplie (Verification)
    // 

    std::cout << "\nGrid du joueur : \n";
    Affichage(Player_Grid, Size * Size, Size);
    std::cout << "\nGrid des bombes : \n";
    Affichage(Bomb_Grid, Size * Size, Size);

    BombVoisin=CalculNombreAutour(Bomb_Grid, Size);
    if (BombVoisin == 1) {
        std::cout << "1 Bombe Voisine";
    }
    if (BombVoisin == 2) {
        std::cout << "2 Bombe Voisine";
    }
    if (BombVoisin == 3) {
        std::cout << "3 Bombe Voisine";
    }
    if (BombVoisin == 4) {
        std::cout << "4 Bombe Voisine";
    }
    if (BombVoisin == 5) {
        std::cout << "5 Bombe Voisine";
    }
    if (BombVoisin == 6) {
        std::cout << "6 Bombe Voisine";
    }
    if (BombVoisin == 7) {
        std::cout << "7 Bombe Voisine";
    }
    if (BombVoisin == 8) {
        std::cout << "8 Bombe Voisine";
    }

    ChoixCoordoonnee(Player_Grid, Size);

    delete[] Bomb_Grid;
    Bomb_Grid = nullptr;

    delete[] Player_Grid;
    Player_Grid = nullptr;
}