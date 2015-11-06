/* 
 * File:   Ordenamiento.cpp
 * Author: zerhogie
 *
 * Created on 29 de octubre de 2015, 8:55
 */

#include <iostream>
#include <cstdlib>

using namespace std;
void mostrar(int numeros[],int n){
    for(int i=0; i<n; i++){
        cout <<numeros[i] <<" ";
    }
}
void burbuja(int numeros[], int n){
    int aux;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(numeros[i]>numeros[j]){
                aux=numeros[j];
                numeros[j]=numeros[i];
                numeros[i]=aux;
            }
        }
    }
    cout <<"\nOrdenamiento burbuja: \n";
    mostrar(numeros, n);
}
void seleccionDirecta(int numeros[], int n){
    int aux, menor, c=0;
    for(int i=0; i<n; i++){
        menor=i;
        for(int j=i+1; j<n; j++){
            if(numeros[j]<numeros[menor]){
                menor=j;
                c++;
            }
        }
        if(menor!=i){
            aux=numeros[i];
            numeros[i]=numeros[menor];
            numeros[menor]=aux;
        }
    }
    cout <<"\nOrdenamiento de seleccion directa:\n";
    mostrar(numeros, n);
    cout << "\nCambios: " << c;
}
void desordenar(int num[], int n){
    int aux, ran;
    srand(time(NULL));    
    for(int i=0;i<n; i++){
        aux=num[i];
        ran=rand()%n-1;
        if(ran>i || i==n-1){
            num[i]=num[ran];
            num[ran]=aux;
        }
    }
    cout <<"\nDesordenando... Desordenado:\n";
    mostrar(num, n);
}

void lq(int num[], int n){
    int aux;
    for(int i=n-1;i>n/2;i--){
        for(int j=0;j<n-1;j++){
            if(num[j]>num[i]){
                aux=num[j];
                num[j]=num[i];
                num[i]=aux;
            }
        }
    }
    cout << "\nOrdenamiento por LQ: \n";
    mostrar(num, n);
}
void insersion(int num[], int n){
    int aux; int j;
    for(int i=1;i<n;i++) 
    { 
        j=i; 
        aux=num[i]; 
        while(j>0 && aux<num[j-1]) 
        { 
            num[j]=num[j-1]; 
            j--; 
        } 
    num[j]=aux; 
    } 
    cout << "\nMétodo por insersión: \n";
    mostrar(num, n);
}
void insercion(int numero[], int n)
{
	int aux, j;
	for (int i= 1; i < n; i++){
		j = i;
		aux = numero[i];
		while (j > 0 && aux < numero[j-1]){
			numero[j] = numero[j-1];
			j--;
		}
		numero[j] = aux;
	}
}

void shell(int numero[], int n)
{
    int j, inc, aux;
    while (inc > 0){
        for (int i = inc; i < n; i++){
            j = i;
            aux=numero[i];
            while ((j>=inc)&&(numero[j-inc])>aux){
                numero[j] = numero[j-inc];
                j=j-inc;
            }
            numero[j]=aux;
        }
        inc/= 2;
    }
    cout << "\nMétodo shell: \n";
    mostrar(numero, n);
}

int main(int argc, char** argv) {
    int n, x;
    cout <<"Cuantos numeros desea ingresar?  ";
    cin >>n;
    int numeros[n];
    for (int i=0; i<n; i++){
        cout <<"Numero " <<i+1 <<": ";
        cin >>numeros[i];
    }
    cout <<"\nNumeros desordenados:\n";
    mostrar(numeros, n);
    while(1){
        cout << "\n1) Burbuja\n2) Selección Directa\n3)Metodo LQ\n4) Insersión\n5) QuickSort\n6) Shell \n7) Salir \nElección: ";
        cin >> x;
        switch(x){
            case 1:
                burbuja(numeros, n);
                break;
            case 2:
                seleccionDirecta(numeros, n);
                break;
            case 3:
                lq(numeros, n);
                break;
            case 4:
                insersion(numeros, n);
                break;
            case 5:
                break;
            case 6:
                shell(numeros, n);
                break;
            case 7:
                cout << "\nHasta Pronto\n";
                exit(1);
                break;
            default:
                cout << "\nOpción invalida";
        }
        desordenar(numeros, n);
    }
    return 0;
}
