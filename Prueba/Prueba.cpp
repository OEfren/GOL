// Prueba.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// https://bitstorm.org/gameoflife/
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

int** generaMatriz(int numRows, int numCols) 
{
	int **matriz = new int*[numRows];
	for (int index = 0; index < numCols; index++)
	{
		matriz[index] = new int[numCols];
	}

	return matriz;
}

void mostrarMatriz(int** matriz, int numRows, int numCols)
{
	for (int i = 0; i < numRows; i++) 
	{
		for (int j = 0; j < numCols; j++)
		{
			cout << matriz[i][j] << " ";
		}	
		cout << endl;
	}
}

void limpiarMatriz(int** matriz, int numRows, int numCols)
{
	for (int index = 0; index < numRows; index++)
		for (int j = 0; j < numCols; j++)
			matriz[index][j] = 0;
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

void crearMatrizUno(int** matriz, int numRows, int numCols)
{
	// activamos las celulas
	// x, y
	matriz[5][5] = 1;
	matriz[5][6] = 1;
	matriz[5][7] = 1;
	matriz[5][8] = 1;
	matriz[5][9] = 1;
	matriz[5][10] = 1;
	matriz[5][11] = 1;
	matriz[5][12] = 1;
	matriz[5][13] = 1;
	matriz[5][14] = 1;
}

int contarVecinos(int **matriz, int x, int y, int numRows, int numCols)
{
	int contador = 0;
	// 12 hrs
	if (x - 1 >= 0 && matriz[x - 1][y] == 1)
		contador += 1;

	// 1.30 hrs
	if (x - 1 >= 0 && y + 1 < numCols && matriz[x - 1][y + 1] == 1)
		contador += 1;

	// 3 hrs
	if (y + 1 < numCols && matriz[x][y + 1] == 1)
		contador += 1;

	// 4.5 hrs
	if (x + 1 < numRows && y + 1 < numCols && matriz[x + 1][y + 1] == 1)
		contador += 1;

	// 6 hrs
	if (x + 1 < numRows && matriz[x + 1][y] == 1)
		contador += 1;

	// 7.30 hrs
	if (x + 1 < numRows && y - 1 >= 0 && matriz[x + 1][y - 1] == 1)
		contador += 1;

	// 9 hrs
	if (y - 1 >= 0 && matriz[x][y - 1] == 1)
		contador += 1;

	// 9.30 hrs
	if (x - 1 >= 0 && y - 1 >= 0 && matriz[x - 1][y - 1] == 1)
		contador += 1;

	return contador;
}

int** evaluarMatriz(int** matriz, int numRows, int numCols)
{
	int **newMatriz = generaMatriz(numRows, numCols);
	limpiarMatriz(newMatriz, numRows, numCols);

	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			int vecinos = contarVecinos(matriz, row, col, numRows, numCols);

			if (matriz[row][col] == 0 && vecinos == 3) {
				newMatriz[row][col] = 1;
			}
			else if (vecinos == 2 || vecinos == 3 )
			{
				newMatriz[row][col] = 1;
			}
			else if (vecinos > 3)
			{
				newMatriz[row][col] = 0;
			}
			
		}
	}
	return newMatriz;
}



/*
void colocarHoras(int **matriz,  int x, int y, int numRows, int numCols) 
{
	int contador = 0;
	// 12 hrs
	if (x - 1 >= 0 )
		matriz[x - 1][y] = 1;

	// 1.30 hrs
	if (x - 1 >= 0 && y + 1 < numCols)
		matriz[x - 1][y + 1] = 1;

	// 3 hrs
	if (y + 1 < numCols)
		matriz[x][y + 1] = 1;

	// 4.5 hrs
	if (x + 1 < numRows && y + 1 < numCols)
		matriz[x + 1][y + 1] = 1;

	// 6 hrs
	if (x + 1 < numRows)
		matriz[x + 1][y] = 1;

	// 7.30 hrs
	if (x + 1 < numRows && y - 1 >= 0)
		matriz[x + 1][y - 1] = 1;

	// 9 hrs
	if (y - 1 >= 0)
		matriz[x][y - 1] = 1;

	// 9.30 hrs
	if (x - 1 >= 0 && y - 1 >= 0)
		matriz[x - 1][y - 1] = 1;
}
*/


int main() 
{
	int filasColumnas = 0;
	cout << "Ingrese numero de filas y columnas deseadas:" << endl;
	cin >> filasColumnas;
	
	int **matriz = generaMatriz(filasColumnas, filasColumnas);
	limpiarMatriz(matriz, filasColumnas, filasColumnas);
	crearMatrizUno(matriz, filasColumnas, filasColumnas);
	mostrarMatriz(matriz, filasColumnas, filasColumnas);

	int salir = 0;
	cout << "Imprmir siguiente matriz (1) Si (0) No: " << endl;
	cin >> salir;

	while (salir == 1)
	{

		matriz = evaluarMatriz(matriz, filasColumnas, filasColumnas);
		mostrarMatriz(matriz, filasColumnas, filasColumnas);

		cout << "Imprmir siguiente matriz (1) Si (0) No: " << endl;
		cin >> salir;
	}

	return 0;
}
