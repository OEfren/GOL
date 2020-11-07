// Prueba.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
*/

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void GeneradorMatriz1(int numRows, int numColumns)
{
	int *rows = new int[numRows];
	
	for (int index = 0; index < sizeof(rows); index++)
	{
		//rows[index] = new int[numColumns];
		cout << "Salida de texto " << numRows  ;
	}
	

	cout << "The size of the array is: " << sizeof(rows);
}

void printMatriz(int** rows) {
	/*
	for (int index = 0; index < rows.count; index++) 
	{

	}
	*/
}

/*
int main()
{
	//srand(time(NULL));
	int filas_columnas = 0;
	cout << "Ingrese numero de filas y columnas deseadas: ";
	cin >> filas_columnas;
	GeneradorMatriz1(filas_columnas, filas_columnas);
	

	int salir = 0;
	do  {
		cout << "¿Desea salir del progra? 1 = Si, 0 = No: ";
		cin >> salir;

	} while (salir == 0);	
}
*/

int** generaMatriz(int numRows, int numCols) 
{
	int **matriz = new int*[numRows];
	for (int index = 0; index < numCols; index++)
	{
		matriz[index] = new int[numCols];
	}
	return matriz;
}

void mostrarMatriz(int** matriz, int rows, int columns) 
{
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matriz[i][j] << " ";
		}	
		cout << endl;
	}
}

int pruebaUno() {
	int i, j, f, c;
	cout << "Introduce el numero de filas" << endl;
	cin >> f;
	cout << "Introduce el numero de columnas" << endl;
	cin >> c;

	// creamos la matriz !
	int **M = generaMatriz(f, c);

	// Comprobamos
	if (!M) {
		cout << "No se puede reservar el espacio" << endl;
		return 1;
	}

	cout << "Introduzca la matriz" << endl;
	for (i = 0; i < f; i++)
		for (j = 0; j < c; j++)
			cin >> M[i][j];

	cout << "Mostrar la matriz" << endl;
	mostrarMatriz(M, i, c);
	delete[] M;
	return 0;
}

int main() 
{
	int filasColumnas = 0;
	cout << "Ingrese numero de filas y columnas deseadas:" << endl;
	cin >> filasColumnas;
	
	int salir = 0;
	do 
	{


		cout << "Salir del programa (1) Si (0) No: " << endl;
		cin >> salir;
	} while (salir == 0);	
}
