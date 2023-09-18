#include <iostream>
#include <string>

using namespace std;

struct USB {
    char nombre[50];
    int capacidad;
    int uso;
    char sistemaArchivos[10];
};

void formatear(USB* m, char* sistArch, char* nuevoNombre){
    strcpy(m->nombre, nuevoNombre);
    m->capacidad = 0;
    m->uso = 0;
    strcpy(m->sistemaArchivos, sistArch);
}

void mostrarPropiedades(USB m){
    cout << "Nombre: " << m.nombre << endl;
    cout << "Capacidad: " << m.capacidad << " GB" << endl;
    cout << "En uso: " << m.uso << " GB" << endl;
    cout << "Sistema de archivos: " << m.sistemaArchivos << endl;
}

void cambiarNombre(char* nuevoNombre, USB* m){
    strcpy(m->nombre, nuevoNombre);
}

int main(){
    USB memoria;
    strcpy(memoria.nombre, "USB1");
    memoria.capacidad = 32;
    memoria.uso = 10;
    strcpy(memoria.sistemaArchivos, "FAT");
    
    cout << "Propiedades de la USB inicial: " << endl;
    mostrarPropiedades(memoria);
    
    formatear(&memoria, "NTFS", "USB2");
    
    cout << "\nPropiedades de la USB después de formatear: " << endl;
    mostrarPropiedades(memoria);
    
    cambiarNombre("USB3", &memoria);
    
    cout << "\nPropiedades de la USB después de cambiar el nombre: " << endl;
    mostrarPropiedades(memoria);
    
    return 0;
}
