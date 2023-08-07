#include <iostream>
#include <stdlib.h>
#include <time.h>

#define n 5
#define m 7

int array[n], matriz[n][m];
char arrayChar[n];

// INSTRUCCION #1;
void LlenarNumerosRandom(){
    for(int i = 0; i < n; i++){
        array[i] = rand() % 100 + 1;
    }
}

// INSTRUCCION #2;
void llenarArreglo(){
    for(int i = 0; i < n; i++){
        std::cout << "Digite el elemento de la posicion [" << i << "]: ";
        std::cin >> arrayChar[i];
    }
}

// INSTRUCCION #3;
void mostrarMatrizWithArray(){
    std::cout << "\nMostrando la matriz..." << std::endl;
    for(int i = 0; i < n; i++){
        for(int j =  0; j < m; j++){
            std::cout << "|" << matriz[i][j]; std::cout << "|";
        }
        std::cout << "\n";
    }
}

void llenarMatrizWithArray(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matriz[i][j] = array[i];
        }
    }

    mostrarMatrizWithArray();
}

void mostrarArray(){
    std::cout << "\nMostrando el array..." << std::endl;
    for(int i = 0; i < n; i++){
        std::cout << "|" << array[i]; std::cout << "|";
    }
    std::cout << "\n";
}

int main() {
    LlenarNumerosRandom();
    mostrarArray();
    llenarArreglo();
    llenarMatrizWithArray();
    return 0;
}