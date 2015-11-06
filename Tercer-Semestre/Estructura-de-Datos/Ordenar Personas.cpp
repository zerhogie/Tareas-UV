/* 
 * File:   Persona.cpp
 * Author: zerhogie
 * Created on 3 de noviembre de 2015, 8:45
 */
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

class Persona{
private:
    string nom;
    string tel;
    string fnac;
    friend class Agenda;    
};
class Agenda{
private:
    Persona x[10];
    int fin;
public:
    Agenda();
    void mostrar();
    void almacenar();
    void ordenar();
    void menu();
};
Agenda::Agenda(){
    fin=0;
}
void Agenda::mostrar(){
    if(fin==0)
        cout << "No hay Datos\n \n";
    else
        for(int i=0; i<fin; i++){
            cout << "Nombre: " << x[i].nom << "\n";
            cout << "Teléfono: " << x[i].tel << "\n";
            cout << "Fecha de Nacimiento: " << x[i].fnac << "\n\n";
        }
}
void Agenda::almacenar(){
    if(fin<10){
        cout << "\nNombre: ";
        cin >> x[fin].nom;
        cout << "Telefono: ";
        cin >> x[fin].tel;
        cout << "Fecha de Nacimiento (dd/mm/aaaa): ";
        cin >> x[fin].fnac;
        fin++;
    }
    else
        cout << "\n ¡Ya se llenó la agenda! \n";
}
void Agenda::ordenar(){
    Persona aux; 
    int j;
    for(int i=1;i<fin;i++) 
    { 
        j=i; 
        aux=x[i]; 
        while(j>0 && aux.nom<x[j-1].nom) 
        { 
            x[j]=x[j-1]; 
            j--; 
        } 
    x[j]=aux; 
    }
}
void Agenda::menu(){
    int des;
    cout << "1) Mostrar\n2) Almacenar\n3) Ordenar \n4) Salir \nDecisión: ";
    cin >>des;
    switch(des){
        case 1:
            mostrar();
            break;
        case 2:
            almacenar();
            break;
        case 3:
            ordenar();
            break;
        case 4:
            cout << "Hasta Pronto";
            exit(1);
            break;
        default:
            cout << "Opción invalida";
    }    
}
int main(int argc, char** argv) {
    Agenda x;
    while(1)
        x.menu();
}