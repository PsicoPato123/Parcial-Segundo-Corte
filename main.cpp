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
            // Bordes conocidos como paredes
            mapa[i][j] = 'Pared';
            // Calles verticales
            for(int j = 2; j < columna; j += 4){
                for(int i = 1; i < fila-1; i++){
                mapa[i][j] = 'Via';
            }
            for(int i= 3; i < fila; i+=4){
                for(int j = 1; j < columna-1; j ++){      
                mapa[i][j] = 'Via';
            }
            // Espacio de parqueaderos
            for(int i = 1; i < fila-1; i++){
                for(int j = 1; j < columna-1; j++){
                    if(mapa[i][j] != 'Via'){
                        mapa[i][j] = 'Parqueadero';
                    } }}   
        }}

    // Entrada y salida
    mapa[2][3] = 'Entrada';
    mapa[fila-1][columna-2] = 'Salida';
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

