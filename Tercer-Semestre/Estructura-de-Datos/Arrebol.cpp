/* 
 * File:   main.cpp
 * Author: zerhogie
 *
 * Created on 5 de noviembre de 2015, 12:54
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int* generar(int r[], int num){
    srand(time(NULL));
    for(int i=0; i<num; i++){
        r[i]=rand()%101;
    }
    return r;
}
void mostrarDatos(int r[], int num){
    cout << "\nDatos: ";
    for(int i=0; i<num; i++){
        cout << r[i] << " ";
    }
    cout << "\n";
}
void mostrarArbol(int r[], int num, int niv){
    cout << "\nArbol: \n";
    int m=num, nv=1;
    int t=1, pos=0;
    while(nv<=niv && pos<num){
        if(nv>1){
            t*=2;
        }
        for(int i=0; i<m/2; i++)
            cout <<"  ";
        if(pos<num){
            cout << r[pos]; 
            pos++;
        }
        for(int i=t; i>1; i--){
            for(int j=0; j<m; j++)
                cout <<"  ";
            if(pos<num){
                cout << r[pos]; 
                pos++;
            }
        }
        cout << "\n";
        nv++;
        m=m/2;
    }
    
}
void mostrarHijosDe(int x, int r[], int num){
    int i=0;
    while(i<num && r[i]!=x)
        i++;
    cout << "i= "<< i << "\n";
    if(i==num)
        cout << "No está el número en el ArrBol.";
    else
        if((i+i+1)>=num)
            cout << "No tiene hijos";
        else{
            cout << "Los hijos es(son): " <<r[i+i+1];
            if(i+i+2<num)
                cout << " y " << r[i+i+2];
        }
}

int niveles(int num){
    int c=0, n=num;
    while(n!=0){
        n=n/2;
        c++;
    }
    return c;
}
int main(int argc, char** argv) {
    int num, n;
    cout << "¿Cuantos números?  ";
    cin >> num;
    int r[num];
    generar(r, num);
    mostrarDatos(r, num);
    mostrarArbol(r, num, niveles(num));
    cout << "\n¿Que numero quieres saber sus hijos?  ";
    cin >> n;
    mostrarHijosDe(n, r, num);
    return 0;
}
