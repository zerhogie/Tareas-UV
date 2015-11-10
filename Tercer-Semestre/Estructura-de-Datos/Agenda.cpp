/* 
 * File:   Agenda.cpp
 * Author: zerhogie
 *
 * Created on 9 de noviembre de 2015, 8:13
 */
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <iomanip>
#include <cstdlib>
using namespace std;
/*-----------------------------*/
typedef pair<string, string> persona;

class Persona{
private:
    map<string, string> agenda;
public:
    void menu();
    void ingresar(string nom, string num);
    void borrar(string nom);
    void encontrar(string nom);
    void mostrarDir();
    void sorpresa();
};
void Persona::menu(){
    string nom, num;
    int des;
    cout << "\n1)Ingresar\n2)Borrar\n3)Encontar\n4)MostrarDir\n5)Sorpresa\n6)Salir\nOpción: ";
    cin >> des;
    switch(des){
        case 1:
            cout << "Nombre: ";
            cin >> nom;
            cout << "Teléfono: ";
            cin >> num;
            ingresar(nom, num);
            break;
        case 2:
            cout << "Dame el nombre de quien borro: ";
            cin >> nom;
            borrar(nom);
            break;
        case 3:
            cout << "¿A quien buscas? ";
            cin >> nom;
            encontrar(nom);
            break;
        case 4:
            mostrarDir();
            break;
        case 5:
            sorpresa();
            break;
        case 6:
            cout << " Gracias por usar el directorio \1 \n";
            exit(1);
            break;
        default:
            cout << "Opción inválida\n";
            break;
    }
}

void Persona::ingresar(string nom, string num){
    agenda.insert(persona(nom, num));
}

void Persona::borrar(string nom){
    map<string, string>::iterator p = agenda.find(nom);
    if(p != agenda.end())
        agenda.erase(p);
    else 
        cout << nom << " no está en el directorio.\n";
}
void Persona::encontrar(string nom){
    map<string, string>::iterator p = agenda.find(nom);
    if(p != agenda.end())
     cout << "Numero telefonico de : " << nom << " = " << p->second << endl;
    else 
     cout << nom << " no está en el directorio.\n";
}
void Persona::sorpresa(){
    srand(time(NULL));
    int c;
    cout << "\nAqui se selecciona una persona al azar y se muestra.\n";
    map<string, string>::iterator p = agenda.begin();
    while (p != agenda.end() )
    {
      p ++;
      c ++;
    }
    c=rand()%c;
    map<string, string>::iterator t = agenda.begin();
    for(int i=0; i<=c; i++)
        t++;
    cout << "La persona escogida es:  .....\n";
    cout << setw(10) << t->first << setw(12) << t->second << endl;
}
void Persona::mostrarDir(){
    map<string, string>::iterator p = agenda.begin();
    while (p != agenda.end())
    {
      cout << setw(10) << p->first << setw(12) << p->second << endl;
      p ++;
    }
}

int main(int argc, char** argv) {
    Persona x;
    while(1)
        x.menu();
}
