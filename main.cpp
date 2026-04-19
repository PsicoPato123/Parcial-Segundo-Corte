#include <iostream>
#include <string>
#include <ctime> //conocida por Web y ChatGPT
#include "color.h"

struct carro{
    std::string placa;
    time_t entrada;
    int fila, columna;
};

void EstructuraMapa(std::string** mapa, int fila, int columna){
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            // Bordes conocidos como paredes
            mapa[i][j] = "Pared";
        }}
            // Calles verticales
            for(int j = 2; j < columna; j += 4){
                for(int i = 1; i < fila-1; i++){
                mapa[i][j] = "Via";
            }}
            //Calles horizontales 
            for(int i= 3; i < fila; i+=4){
                for(int j = 1; j < columna-1; j ++){      
                mapa[i][j] = "Via";
            }}

            // Espacio de parqueaderos
            for(int i = 1; i < fila-1; i++){
                for(int j = 1; j < columna-1; j++){
                    if(mapa[i][j] == "Pared"){
                        //declaración de espacios de parqueo
                    if(mapa[i][j-1] == "Via" || mapa[i][j+1] == "Via" ||
                    mapa[i-1][j] == "Via" || mapa[i+1][j] == "Via"){
                    mapa[i][j] = "Parqueadero";
                }}} }

        // Entrada y salida
            mapa[2][3] = "Entrada";
            mapa[fila-2][columna-4] = "Salida";
}
    //Creación de función que haga visible el mapa
    void MostrarMapa(std::string** mapa, int fila, int columna){
        //Se define la estructura y división del mapa
        std::cout << "\n   ";
            for(int j = 0; j < columna; j++){
            std::cout << j+1 << " ";  //número de columnas
            }
            std::cout << std::endl;

            for(int i = 0; i < fila; i++){
            char letra = 'A' + i; //Conversión de la letra conforme avanza (ChatGPT)
            std::cout << letra << "  ";

                for(int j = 0; j < columna; j++){
            //Brinda color al mapa segun el área
                if(mapa[i][j] == "Pared"){
                    std::cout<<RED<<"Pared "<<RESET;
                } else if(mapa[i][j] == "Via"){
                    std::cout<<GREEN<<"Via"<<RESET;
                } else if(mapa[i][j] == "Parqueadero"){
                    std::cout<<YELLOW<<"Parqueadero "<<RESET;
                } else if(mapa[i][j] == "Entrada"){
                    std::cout<<BLUE<<"Entrada"<<RESET;
                } else if(mapa[i][j] == "Salida"){
                    std::cout<<MAGENTA<<"Salida"<<RESET;
                }}
        std::cout << std::endl;
}}
//Función para contar los espacios disponibles 
void Disponible (std::string** mapa, int fila, int columna){ 
    int libre = 0, ocupado= 0; 
    for(int i = 0; i < fila; i++){ 
        for(int j = 0; j < columna; j++){
             if(mapa[i][j] == "Parqueadero") libre++; 
             if(mapa[i][j] == "O") ocupado++; } 
            }
            std::cout << "\nDisponibles: " << libre;
            std::cout << "\nOcupados: " << ocupado << std::endl;
        }
//Función para ingresar un vehículo al parqueadero
void ingresovehiculo(std::string** mapa,carro* lista, int fila, int columna, int& total){
    std::string placa, pos;
    std::cout << "Ingrese la placa del paticarro: ";
    std::cin >> placa;
    std::cout << "Ingrese la posición de parqueo (Ejemplo: A1): ";
    std::cin >> pos;

    std::string letra = pos.substr(0, 1); // Extracción de la letra
    int numero = std::stoi(pos.substr(1)); // Extracción del número

    int filas = letra[0] - 'A'; // Conversión de letra a índice
    int columnas = numero - 1; // Conversión del número a índice

    if(filas < 0 || filas >= fila || columnas < 0 || columnas >= columna){
        std::cout << "Posicion invalida\n";
        return;
    }
    if(mapa[filas][columnas] != "Parqueadero"){
        std::cout << "No disponible :c\n";
        return;
    }

    //registro del vehiculo en el sistema
    mapa[filas][columnas] = "Ocupado"; // Marca el espacio como ocupado
    lista[total].placa = placa;
    lista[total].entrada = time(0);
    lista[total].fila = filas;
    lista[total].columna = columnas;
    total++; 
    std::cout << "Paticarro registrado con éxito :D" << std::endl;
}
//función para calcular la tarifa de acuerdo al tiempo de parqueo
int calcularTarifa(std::string** mapa, carro* lista, int fila, int columna, int total){
    time_t salida = time(0); 
    for(int i = 0; i < total; i++){
        if(lista[i].fila == fila && lista[i].columna == columna){
            double horas = difftime(salida, lista[i].entrada) / 3600; // Conversión a horas
            int tarifa = (horas * 6000); // Tarifa de $6000 por hora
            return tarifa;
        }
    }
    return 0; // Si no se encuentra el vehículo, no se cobra
}
//función para retirar un vehículo del parqueadero y cobro de tarifa 
void retirovehiculo(std::string** mapa, carro* lista, int fila, int columna, int& total){
    std::string placa;
    std::cout << "Ingrese la placa del paticarro a retirar: ";
    std::cin >> placa;
    bool encontrado = false;
    // Cálculo de tarifa

    for(int i = 0; i < total; i++){
        if(lista[i].placa == placa){
            int f = lista[i].fila;
            int c = lista[i].columna;

            int costo = calcularTarifa (mapa, lista, f, c, total);
            
            mapa[f][c] = "Parqueadero"; // Hace que el espacio se vuelva disponible
            std::cout << "Paticarro de placa " << placa << " retirado del parqueadero." << std::endl;
        
            std::cout << "Paticarro" << placa << " salió.\n";
            std::cout << "Valor a pagar: $" << costo << "\n";
            
            lista[i] = lista[total - 1]; 
            total--; // Reduce el total de vehículos registrados
        }}
        if(!encontrado){
            std::cout << "Paticarro con placa " << placa << " no encontrado en el parqueadero." << std::endl;
        }}
//Creación de menú
void menu(std::string** mapa, int fila, int columna,carro* lista){
    int opt;
    int total = 0; // Contador de vehículos registrados
    std::cout<<"Bienvenido a tu Pati-adero Cuack"<<std::endl; 
    std::cout<<"1. Ingresar Pati-vehiculo"<<std::endl;
    std::cout<<"2. Retirar Pati-vehiculo"<<std::endl;
    std::cout<<"3. Ver Pati-espacios"<<std::endl;
    std::cout<<"4. Mostrar Pati-mapa"<<std::endl;
    std::cout<<"5. Pati-salida\n";
    std::cout<<"Selecciona una Pati-opcion: \n";
    std::cin>>opt;

    do{ 
        switch (opt){
    case 1:
    ingresovehiculo(mapa,lista,fila, columna, total);
        break;
    case 2: 
    retirovehiculo(mapa, lista, fila, columna, total);
        break;
    case 3:
    Disponible(mapa, fila, columna);
        break;
    case  4:
    MostrarMapa(mapa, fila, columna);
        break;
    default:
        break;
    }}while (opt !=5);
}

int main (){  
    //Creación del mapa dinámico
    int fila =18; 
    int columna=16;
    std::string** mapa = new std::string*[fila];
    carro* lista = new carro[fila*columna]; // Lista para registrar los vehículos, tamaño máximo igual al número de espacios
    for(int i = 0; i < fila; i++){
        mapa[i] = new std::string[columna];
    }
    //Aplicación de funciones
    EstructuraMapa(mapa,fila, columna);
    menu(mapa, fila, columna, lista);

    return 0;
}
