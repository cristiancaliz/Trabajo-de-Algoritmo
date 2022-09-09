#include <iostream>
#include <fstream>
using namespace std;
//Punto 1
void enviar (int t[], int r[],double pe[],int cliente, string c[] ,string p[]){
    const int peso {13000};
    int filas {120};
    int s {0}; 
    int dim {5};
    double re[dim] {};
    cout << c[cliente] << ": " ;
    while (s < dim){
        int cant {0};
        for (int x = 0; x < filas; x++){//
            r[x] == s && t[x] == cliente ? re[s] += pe[x] : 0;
        }
        if (re[s] > peso){
            cout << p[s] << " " ;
        }
        s++;
    }
    cout << endl;
}
//Punto 2
void recorrido (double re[],string p[]){
    for (int y= 0; y < 5; y++){
        cout << p[y] << ": " << re[y] << endl;
    }
}
//Punto 3 el mayor
int maior (double re[], int dim){
    int valor {0};
    double max = re[valor];
    for (int i = 1; i < dim; ++i){ //Es 1 porque el primer elemento se le modifico el nombre antes.
        if (re[i] > max){
            max = re[i];
            valor = i;
        }
    }
    return valor;
}

int main(){
    ifstream archilec;
    archilec.open ("Datos.txt");
    if (!archilec){
        cout << "Error al abrir el archivo DATOS." << endl;
        return 1;
    }
    ifstream archiname;
    archiname.open ("Nombres.txt");
    if (!archiname){
        cout << "Error al abrir el archivo NOMBRES." << endl;
        archilec.close ();
        return 1;
    }
    //Nombres
    string c[8];
    string p[5];
    int k {0};
    for (int i = 0; i < 13; i++){
        if (i < 8){
            archiname >> c[i];
        }else{
            archiname >> p[k];
            k++;
        }
    }
    //Datos
    int filas {120};
    int columnas {4};
    double f[filas][columnas];
    float pes;
    float dis;
    for (int a = 0; a < filas; a++){
        for (int b = 0; b < columnas; b++){
            archilec >> f[a][b];
        }
    }
    //Punto 1 Mayor que 13000
    int kva {120};
    int t[kva]; //clientes
    int r[kva]; //productos
    double pe[kva];
    for (int d = 0; d < 120; d++){
        t[d] = f[d][0];
        r[d] = f[d][1];
        pe[d] = f[d][2];
    }
    //Punto 2 Recorrido.
    int dim {5};
    double re[dim] {};
    int s {0}; //bi cliente
    while (s < dim){
        for (int x = 0; x < filas; x++){//
            f[x][1] == s && f[x][0] == 1 ? re[s] += f[x][3] : 0;
        }
        s++;
    }
    //Punto 3 Conteo
    int cant {0};
    int lugar = maior(re,s);
    for (int j = 0; j < filas; j++){
        f[j][1] == lugar ? cant++ : 0;
    }
    //Mostrar
    cout << "Listado por clientes, de los tipos de productos que superan los 13000 kg acumulados: " << endl;
    for (int ult = 0; ult < 8; ult++){
        enviar (t,r,pe,ult,c,p);
    }
    cout << endl;
    cout << "Listado de km recorridos por tipo de producto(ascendente): " << endl;
    recorrido (re,p);//funcion
    cout << endl;
    cout << "Cantidad de entregas para el tipo de producto " ; 
    cout << p[lugar] << ": " << cant << endl;
    archilec.close ();
    archiname.close ();
    return 0;
}