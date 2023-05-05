
#include <iostream>
using namespace std;
int posicion_random(int num) {
    return rand() % num;
}
void agregar_obstáculos(char** matriz,int obstáculos,int filas,int columnas) {
    bool flag = false;
    for (int i = 0; i < obstáculos; i++)  {
        
        do {
            int fila = posicion_random(filas);
            int columna = posicion_random(columnas);
            if (matriz[fila][columna] != '#') {
                matriz[fila][columna] = '#';
                flag = false;
            }
            else {
                flag = true;
            }
        } while (flag);
    }
}
char** Llenar_Matriz(int fil,int col) {
        char** matriz = new char* [fil];
        for (int i = 0; i < fil; i++) {
            matriz[i] = new char[col];
            for (int j = 0; j < col; j++) {
                matriz[i][j] = '-';
            }
        }
        return matriz;
}
void imprimir_matriz(char** matriz,int filas,int col) {
    for (int i = 0; i < filas; i++) {
        cout << '|';
        for (int j = 0; j < col; j++) {
            cout << " '" << matriz[i][j] << "' ";
        }
        cout << '|';
        cout << endl;
    }
}
void DiscoX0R() {
    int salir = 0;
    while (salir != 4) {
        int disco1[8];
        int disco2[8];
        int XOR[8];
        cout << "\n 1. Guardar datos en XOR\n 2. Obtener datos de disco 1\n 3. Obtener datos de disco 2\n 4. Salir\nIngrese la opcion: ";
        cin >> salir;
        switch (salir) {
        case 1:
            //Ingresa disco 1
            cout << "\nIngrese datos de DISCO 1\n";
            for (int i = 0; i < 8; i++)            {
                cout << "Disco 1 [" << i << "]: ";
                cin >> disco1[i];
            }
            //ingresa disco 2
            cout << "\nIngrese datos de DISCO 2\n";
            for (int i = 0; i < 8; i++) {
                cout << "Disco 2 [" << i << "]: ";
                cin >> disco2[i];
            }
            //calcula e imprime disco XOR
            cout << "\nDisco XOR: [ ";
            for (int i = 0; i < 8; i++)            {
                if (disco1[i] == disco2[i])
                    XOR[i] = 0;
                else
                    XOR[i] = 1;
                cout << XOR[i] << " ";
            }
            cout << "]\n";
            break;
        case 2:
            //IMprime disco XOR
            cout << "\nDisco XOR: [ ";
            for (int i = 0; i < 8; i++) {
                cout << XOR[i] << " ";
            }
            cout << "]\n";
            //IMprime disco 2
            cout << "\nDisco 2: [ ";
            for (int i = 0; i < 8; i++) {
                cout << disco2[i] << " ";
            }
            cout << "]\n";
            //Calcula e imprime disco 1
            cout << "\nDatos calculados del disco 1: [ ";
            for (int i = 0; i < 8; i++) {
                if (disco2[i] == XOR[i])
                    disco1[i] = 0;
                else
                    disco1[i] = 1;
                cout << disco1[i] << " ";
            }
            cout << "]\n";
            break;
        case 3:
            //IMprime disco XOR
            cout << "\nDisco XOR: [ ";
            for (int i = 0; i < 8; i++) {
                cout << XOR[i] << " ";
            }
            cout << "]\n";
            //IMprime disco 1
            cout << "\nDisco 1: [ ";
            for (int i = 0; i < 8; i++) {
                cout << disco1[i] << " ";
            }
            cout << "]\n";
            //Calcula e imprime disco 2
            cout << "\nDatos calculados del disco 2: [ ";
            for (int i = 0; i < 8; i++) {
                if (disco1[i] == XOR[i])
                    disco2[i] = 0;
                else
                    disco2[i] = 1;
                cout << disco2[i] << " ";
            }
            cout << "]\n";
            break;
        }
    }
}
void matrizObs() {
    int filas = 0, col = 0, obs = 0;
    cout << "\n --Matriz con Obstaculos--\n";
    do {
        cout << "Ingrese filas: ";
        cin >> filas;
    } while (filas < 5);
    do{
    cout << "Ingrese columnas: ";
    cout << "Ingrese columnas: ";
    cin >> col;
    } while (col < 5);
    do{
    cout << "Ingrese obstaculos: ";
    cin >> obs;
    } while (obs < 1 || obs > (col*filas)-1);//lo repite hasta que ingrese un numero mayor a 1 y menor a columnas*filas-1

    char** matriz = Llenar_Matriz(filas, col);
    agregar_obstáculos(matriz, obs, filas, col);
    imprimir_matriz(matriz, filas, col);
}

int main() {
    int salir = 0;
    while (salir != 2) {
        cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = =  " << endl << "0) Disco XOR     1) Matriz con Obstáculos        2) Salir\n-> ";
        cin >> salir;
        if (salir){
            matrizObs();
        }
        else {
            DiscoX0R();
        }
    }
    return 0;
}