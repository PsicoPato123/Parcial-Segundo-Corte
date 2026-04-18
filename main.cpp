#include <iostream>
#include <string>
#include <ctime> //conocida por Web y ChatGPT
#include "color.h"

struct carro{
    std::string placa;
    time_t entrada;
    int fila, columna;
    bool ocupado;
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
                    if(mapa[i][j] == "Calle"){
                        //declaración de espacios de parqueo
                        if(mapa[i][j-1] == "V" || mapa[i][j+1] == "V" ||
                    mapa[i-1][j] == "V" || mapa[i+1][j] == "V"){
                    mapa[i][j] = "P";
                }}} }
        // Entrada y salida
            mapa[2][3] = "Entrada";
            mapa[fila-2][columna-4] = "Salida";
}

    //Creación de función que haga visible el mapa
    void MostrarMapa(std::string** mapa, int fila, int columna){
        for (int i = 0; i < fila; i++){
            for(int j = 0; j < columna; j++){

            //Brinda color al mapa segun el área
                if(mapa[i][j] == "Pared"){
                    std::cout<<RED<<"P"<<RESET;
                } else if(mapa[i][j] == "Via"){
                    std::cout<<GREEN<<"V"<<RESET;
                } else if(mapa[i][j] == "P"){
                    std::cout<<YELLOW<<"P"<<RESET;
                } else if(mapa[i][j] == "Entrada"){
                    std::cout<<BLUE<<"E"<<RESET;
                } else if(mapa[i][j] == "Salida"){
                    std::cout<<MAGENTA<<"S"<<RESET;
                }
        //Define la división del mapa             
        std::cout << "\n   ";
            for(int j = 0; j < columna; j++){
            std::cout << j+1 << " ";  //número de columnas
            }
            std::cout << std::endl;

            for(int i = 0; i < fila; i++){
            char letra = 'A' + i; //Conversión de la letra conforme avanza (ChatGPT)
            std::cout << letra << "  ";
                for(int j = 0; j < columna; j++){
                std::cout << mapa[i][j] << " ";
        }
        std::cout << std::endl;
    }
}}}

   
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

