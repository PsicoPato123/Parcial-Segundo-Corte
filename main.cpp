#include <iostream>
#include <string>
#include <ctime>
#include "color.h"

struct carro{
    std::string placa;
    time_t entrada;
    int fila, columna;
};

void EstructuraMapa(std::string** mapa, int fila, int columna){
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){

            // Bordes = vías
            if(i == 0 || i == fila-1 || j == 0 || j == columna-1){
                mapa[i][j] = 'Via';
            }
            // Calles internas
            else if(i == fila/2 || j == columna/2){
                mapa[i][j] = 'Via';
            }
            // Parqueaderos
            else{
                mapa[i][j] = 'Acceso';
            }
        }
    }

    // Entrada y salida
    mapa[2][3] = 'E';
    mapa[fila-1][columna-2] = 'S';
}

void menu(){
    int opt;
    std::cout<<"Bienvenido a tu Pati-adero Cuack"<<std::endl; 
    std::cout<<"1. Ingresar Pati-vehiculo"<<std::endl;
    std::cout<<"2. Retirar Pati-vehiculo"<<std::endl;
    std::cout<<"3. Ver Pati-espacios"<<std::endl;
    std::cout<<"4. Mostrar Pati-mapa"<<std::endl;
    std::cout<<"5. Pati-salida";
    std::cout<<"Selecciona una Pati-opcion: ";


}

