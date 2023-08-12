#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#define n 5
#define m 7

// CREATE ARRAY AND MATRIZ;
int array[n], matriz[n][m];
char arrayChar[m];
std::string stringArray[n][m];

// INSTRUCTION #1;
void displayArray(){
    std::cout << "\nMostrando el array rellenado con numeros random..." << std::endl;
    for(int i = 0; i < n; i++){
        std::cout << "|" << array[i]; std::cout << "|";
    }
    std::cout << "\n";
}

void fillArrayRandomNumber(){
    for(int i = 0; i < n; i++){
        array[i] = rand() % 100 + 1;
    }

    // DISPLAY THE ARRAY GENERATED WITH RANDOM NUMBER;
    displayArray();
}

// INSTRUCTION #2;
void displayArrayChar(){
    std::cout << "\nMostrando el array con los characteres ingresados por el usuario..." << std::endl;
    for(int i = 0; i < m; i++){
        std::cout << "|" << arrayChar[i]; std::cout << "|";
    }
    std::cout << "\n";
}

void fillArrayChar(){
    std::cout << "\nRellenando el array char con los elementos del usuario: " << std::endl;
    for(int i = 0; i < m; i++){
        std::cout << "Digite el elemento de la posicion [" << i << "]: ";
        std::cin >> arrayChar[i];
    }

    // DISPLAY THE CHAR ARRAY, CHAR INTRODUCED BY THE USER;
    displayArrayChar();
}

// INSTRUCTION #3;
void displayMatrizWithArray(){
    std::cout << "\nMostrando la matriz rellenada por el array de numeros random..." << std::endl;
    for(int i = 0; i < n; i++){
        for(int j =  0; j < m; j++){
            std::cout << "|" << matriz[i][j]; std::cout << "|";
        }
        std::cout << "\n";
    }
}

void fillMatrizWithArray() {
    int arrayIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = array[arrayIndex];
            arrayIndex = (arrayIndex + 1) % n; // RETURN TO THE BEGINNING OF THE ARRAY;
        }
    }

    // DISPLAY THE ARRAY WITH THE ARRAY STARTING WITH RANDOM NUMBER;
    displayMatrizWithArray();
}

// INSTRUCTION #4;
void fillStringMatriz(){
    std::cout << "\nRellenando la matriz de string con los elementos del usuario: " << std::endl;
    std::cin.ignore();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << "Digite los characteres que guste en la posicion [" << i << "][" << j << "]: ";
            if (i != 0 || j != 0) {
                std::cin.ignore();
            }
            getline(std::cin, stringArray[i][j]);
        }
    }

    std::cout << "\nAgregado correctamente\n";
}

// INSTRUCTION #5;

// arrayChar[n]
// stringArray[i][j]

void fillMatrizWithChar() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::string chain = stringArray[i][j];
            std::cout << "\nEn la posicion [" << i << "][" << j << "]: \n";

            for (int x = 0; x < m; x++) { // LOOP TROUGH THE LETTERS OF THE ARRAYCHAR
                char character = std::toupper(arrayChar[x]);
                int cont = 0;

                for (int k = 0; k < chain.length(); k++) { // LOOP TROUGH CHARACTERS IN CELL
                    if (std::toupper(chain[k]) == character) {
                        cont++;
                    }
                }

                std::cout << "La letra " << character << " se repite " << cont << " veces. \n";
            }
            std::cout << std::endl;
        }
    }
}


// INSTRUCTION #6;
void mostrarMenu(){
    int option;
    bool exit = false;

    do{
        std::cout << "\n\t.:MENU:." << std::endl;
        std::cout << "1. Mostrar el array de numeros random." << std::endl;
        std::cout << "2. Mostrar y solicitar el array de characteres." << std::endl;
        std::cout << "3. Mostrar la matriz de numeros random." << std::endl;
        std::cout << "4. Solicitar la matriz de string." << std::endl;
        std::cout << "5. Mostrar la matriz de string y comparar con el array de char." << std::endl;
        std::cout << "6. Salir." << std::endl;
        std::cout << "Digite la option que desea: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            fillArrayRandomNumber();
            break;
        case 2:
            fillArrayChar();
            break;
        case 3:
            fillMatrizWithArray();
            break;
        case 4:
            fillStringMatriz();
            break;
        case 5:
            fillMatrizWithChar();
            break;
        case 6:
            std::cout << "Saliendo del programa..." << std::endl;
            exit = true;
            break;
        default:
            std::cout << "option no valida, intente de nuevo." << std::endl;
            break;
        }
    } while (exit == false);
}

// MAIN FUNCTION;
int main() {
    srand(time(0));
    mostrarMenu();
    return 0;
}