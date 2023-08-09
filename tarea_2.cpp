#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#define n 5
#define m 7

// CREATE ARRAY AND MATRIZ;
int array[n], matriz[n][m];
char arrayChar[n];
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
    std::cout << "\nMostrando el array con los caracteres ingresados por el usuario..." << std::endl;
    for(int i = 0; i < n; i++){
        std::cout << "|" << arrayChar[i]; std::cout << "|";
    }
    std::cout << "\n";
}

void fillArrayChar(){
    std::cout << "\nRellenando el array char con los elementos del usuario: " << std::endl;
    for(int i = 0; i < n; i++){
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
void displayStringMatriz(){
    std::cout << "\nMostrando la matriz de string introducidos por el usuario..." << std::endl;
    for(int i = 0; i < n; i++){
        for(int j =  0; j < m; j++){
            std::cout << "|" << stringArray[i][j]; std::cout << "|";
        }
        std::cout << "\n";
    }
}

void fillStringMatriz(){
    std::cout << "\nRellenando la matriz de string con los elementos del usuario: " << std::endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << "Digite los caracteres que guste en la posicion [" << i << "][" << j << "]: ";
            getline(std::cin, stringArray[i][j]);
            std::cin.ignore();
        }
    }
}

// INSTRUCTION #5;

// arrayChar[n]
// stringArray[i][j]

void fillMatrizWithChar(){
    int maxCharRow = -1, maxCharColumn = -1, maxCharCount = 0;
    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < m; ++column) {

            int charCount = 0;
            for (char c : stringArray[row][column]) {
                for (int i = 0; i < n; ++i) {
                    if (c == arrayChar[i]) {
                        charCount++;
                        break;
                    }
                }
            }

            if (charCount > maxCharCount) {
                maxCharCount = charCount;
                maxCharRow = row;
                maxCharColumn = column;
            }
        }
    }

    // Imprimir la respuesta
    if (maxCharRow != -1 && maxCharColumn != -1) {
        std::cout << "La celda " << maxCharRow << "," << maxCharColumn << " tiene " << maxCharCount
        << " char de los que aparecen en el arreglo." << std::endl;
    } else {
        std::cout << "No se encontró ninguna celda con caracteres coincidentes." << std::endl;
    }
}

// INSTRUCTION #6;
void mostrarMenu(){
    int opcion;
    bool salir = false;

    do{
        std::cout << "\n\t.:MENU:." << std::endl;
        std::cout << "1. Mostrar el array de numeros random." << std::endl;
        std::cout << "2. Mostrar y solicitar el array de caracteres." << std::endl;
        std::cout << "3. Mostrar la matriz de numeros random." << std::endl;
        std::cout << "4. Solicitar y mostrar la matriz de string." << std::endl;
        std::cout << "5. Mostrar la matriz de string y comparar con el array de char." << std::endl;
        std::cout << "6. Salir." << std::endl;
        std::cout << "Digite la opcion que desea: ";
        std::cin >> opcion;

        switch (opcion)
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
            fillMatrizWithChar();  // Usar la función para mostrar, no llenar
            break;
        case 6:
            std::cout << "Saliendo del programa..." << std::endl;
            salir = true;
            break;
        default:
            break;
        }
    } while (!salir);
}

// MAIN FUNCTION;
int main() {
    srand(time(0));
    mostrarMenu();
    return 0;
}