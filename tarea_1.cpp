#include <iostream>
#include <string>
#include <random>
#include <algorithm>

// SE CREA LA ESTRUCTURA PERSONA PARA GUARDAR LOS DATOS DE CADA PERSONA;
struct Persona {
    std::string nombre, correo;
    int edad{}, puntaje{}, naipe[10];
};

/*
FUNCION PARA GENERAR LOS NUMEROS ALEATORIOS QUE SE USARAN PARA RECORRER LOS ARRAYS CON LOS NUMEROS DE LAS CARTAS
Y ADEMAS DE ESO EL PALO AL QUE PERTENECEN;
*/
int generar_numero_aleatorio(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distribucion(min, max);

    return distribucion(gen);
}

// SE CREAN LOS ARREGLOS DEL NOMBRE DE LAS CARTAS Y EL DE LOS PALOS CORRESPONDIENTE A LA BARAJA DE NAIPES;
std::string nombres[13] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jota", "Reina", "Rey"};
std::string palos[4] = {"Picas", "Corazones", "Tréboles", "Diamantes"};

// FUNCION DEL EJERCICIO #2;
void Ejercicio2(){
    std::cout << "\nEJERCICIO #2: \n";
    int spaceBar, nMas, filas = 10;
    for (int i = 1; i <= filas; i++) {
        // SE IDENTIFICA UN PATRON, SI ES PAR NO TIENE ESPACIOS Y TIENE 12 '+';
        if (i % 2 == 0) {
            spaceBar = 0;
            nMas = 12;
        }
        // SI ES IMPAR TIENE 6 ESPACIOS Y 1 '+';
        else {
            spaceBar = 6;
            nMas = 1;
        }
        // SE IMPRIMEN LA CANTIDAD DE ESPACIOS DE ACUERDO A LO ANTERIOR;
        for (int j = 0; j < spaceBar; j++) {
            std::cout << " ";
        }
        // ACA SE IMPRIMEN LOS SIMBOLOS '+';
        for (int x = 1; x <= nMas; x++) {
            // SE TOMA LA DECISION DE SI SE HA LLEGADO A 6, ENTONCES HAY QUE IMPRIMIR 3 ESPACIOS;
            if (x == 6) {
                for (int k = 1; k <= 3; k++) {
                    std::cout << " ";
                }
            }
            else {
                std::cout << "+";
            }
        }
        std::cout << "\n";
    }
}

void Ejercicio3(){
    std::cout << "\nEJERCICIO #3: \n";
    std::string cadena;
    short int cont_a = 0, cont_e = 0, cont_i = 0, cont_o = 0, cont_u = 0;
    char letra;

    std::cout << "Ingrese una frase, la que usted guste: \n";
    getline(std::cin, cadena);

    for (int i = 0; i < cadena.length(); i++) { // ACA SE USA EL METODO LENGTH PARA SABER LA LONGITUD DE LA CADENA INGRESADA;
        letra = cadena[i];

        // SE USA SWITCH-CASE DEBIDO A QUE VENIAN EN LAS DIAPOSITIVAS DE LA SEMANA #1;
        switch (letra)
        {

        // SE IDENTIFICAN LOS CASOS POSIBLES EN LOS QUE EL USUARIO PUEDE INGRESAR LAS VOCALES (MAYUSCULAS Y MINUSCULAS);
        case 'a':
        case 'A': cont_a++;
            break;
        case 'e':
        case 'E': cont_e++;
            break;
        case 'i':
        case 'I': cont_i++;
            break;
        case 'o':
        case 'O': cont_o++;
            break;
        case 'u':
        case 'U': cont_u++;
            break;
        default:
            break;
        }
    }

    // COMO SE INICIALIZA EN 0 LOS CONTADORES, SE MUESTRAN LAS VECES QUE APARECEN LAS VOCALES, EN CASO DE NO HABER UNA VOCAL SE MUESTRA 0;
    std::cout << "\nLa cantidad de vocales son: \n"
        "Cantidad de vocal a: " << cont_a <<
        "\nCantidad de vocal e: " << cont_e <<
        "\nCantidad de vocal i: " << cont_i <<
        "\nCantidad de vocal o: " << cont_o <<
        "\nCantidad de vocal u: " << cont_u << std::endl;
}
int main() {
    std::cout << "NOTA: Profe algunas palabras escritas estan en mayuscula pero no es por gritar es porque se ve mejor esteticamente :)";
    std::cout << "TAREA #1:" << std::endl;
    /* EJERCICIO 1: Realice una función para simular un juego con 5 personas, de las cuales se debe solicitar
        a.	Nombre completo.
        b.	Edad.
        c.	Correo electrónico.
        A cada persona se le asignaran 10 cartas de naipe al azar, sin repetirse ninguna carta.
        Una vez repartidas las cartas, por ronda cada participante tira una carta, la carta más alta lanzada por la persona gana un punto. Indicar las cartas lanzadas y la persona que gana el punto.
        Así hasta completar 10 rondas. Al finalizar se debe mostrar el orden de las personas con mayor puntaje obtenido a menor puntaje.
    */
    std::cout << "EJERCICIO #1:\n";
    Persona persona[5];

    // INGRESAR INFORMACION DE LAS PERSONAS;
    for (int i = 0; i < 5; i++) {
        std::cout << "Ingrese el nombre de la persona #" << (i + 1) << ": ";
        getline(std::cin, persona[i].nombre);
        std::cout << "Ingrese la edad de la persona #" << (i + 1) << ": ";
        std::cin >> persona[i].edad;
        std::cin.ignore();
        std::cout << "Ingrese el correo de la persona #" << (i + 1) << ": ";
        getline(std::cin, persona[i].correo);
        std::cout << std::endl;
    }

    // INFORMACION INGRESADA;
    std::cout << "Informacion Ingresada: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Nombre: " << persona[i].nombre << std::endl;
        std::cout << "Edad: " << persona[i].edad << std::endl;
        std::cout << "Correo: " << persona[i].correo << "@gmail.com" << std::endl; // SE USA TERMINACION GMAIL, DARLE MAS ESTILO
        std::cout << std::endl;
    }

    // GENERAR CARTAS ALEATORIAS PARA CADA PERSONA;
    int cartasAsignadas[52] = {0}; // ARRAY PARA CONTROLAR LAS CARTAS ASIGNADAS;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            int carta, palo, naipe;
            bool repetido;

            do {
                carta = generar_numero_aleatorio(0, 12); // SE GENERA EL NUMERO ALEATORIO DE CARTA;
                palo = generar_numero_aleatorio(0, 3); // SE GENERA EL NUMERO ALEATORIO DEL PALO;
                naipe = (carta * 4) + palo; // SE CREA LA CARTA CON EL NUMERO + EL PALO;

                repetido = false;
                for (int k = 0; k < 10 * i + j; k++) {
                    if (naipe == cartasAsignadas[k]) { // SE PREGUNTA SI EL NAIPE YA SE ENCUENTRA EN EL ARRAY DE LAS CARTAS;
                        repetido = true; // SI ESTA REPETIDO SE PARA EL CICLO Y SE VUELVE A INICIAR;
                        break;
                    }
                }

                if (!repetido) {
                    persona[i].naipe[j] = naipe;
                    cartasAsignadas[10 * i + j] = naipe; // AGREGA LA CARTA AL ARRAY;
                    break;  // CUANDO SE ASIGNA UNA CARTA NO REPETIDA SE SALE DEL CICLO;
                }
            } while (repetido);
        }
    }

    // MOSTRAR LAS CARTAS DE CADA PERSONA TIRADAS POR RONDAS;
    // Dentro del bucle de la ronda
    for (int ronda = 0; ronda < 10; ronda++) {
        std::cout << "Ronda " << ronda + 1 << std::endl;

        int cartaMasAlta = -1, indiceGanador = -1;

        // CADA PERSONA ARROJA UNA CARTA;
        for (int i = 0; i < 5; i++) {
            int cartaTirada = persona[i].naipe[ronda];
            int numeroCarta = cartaTirada / 4;
            int paloCarta = cartaTirada % 4;
            std::cout << "Persona " << persona[i].nombre << " tira la carta: " << nombres[numeroCarta] << " de " << palos[paloCarta] << std::endl;

            if (cartaTirada > cartaMasAlta) {
                cartaMasAlta = cartaTirada;
                indiceGanador = i;
            }
        }

        // SE ASIGNA EL PUNTO AL GANADOR DE LA RONDA;
        persona[indiceGanador].puntaje++;
        std::cout << "El ganador de la ronda es Persona " << persona[indiceGanador ].nombre << std::endl;
        std::cout << std::endl;
    }

    // SE ORDENA LOS GANADORES DE ACUERDO AL PUNTAJE;
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (persona[j].puntaje < persona[j + 1].puntaje) {
                // ORDENAMIENTO BURBUJA;
                Persona temp = persona[j];
                persona[j] = persona[j + 1];
                persona[j + 1] = temp;
            }
        }
    }

    // SE MUESTRA EN PANTALLA LOS GANADORES EN ORDEN;
    std::cout << "Orden de las personas segun el puntaje obtenido:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Puesto #" << (i + 1) << ": " << persona[i].nombre << " - Puntos: " << persona[i].puntaje << std::endl;
    }

    /* EJERCICIO 2: Realice la siguiente figura utilizando ciclos, solo podrá escribir un carácter a la vez.
                +
	     ++++++   ++++++
		        +
         ++++++   ++++++
	            +
         ++++++   ++++++ 	así sucesivamente hasta completar 10 filas.
    */

   // SE LLAMA LA FUNCION EJERCICIO 2;
    Ejercicio2();

    /* EJERCICIO 3: Realice una función que lea una frase, calcule e imprima el número de repeticiones de cada vocal.  */
    Ejercicio3();
    return 0;
}