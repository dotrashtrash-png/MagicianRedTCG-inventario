// =====================================================================
// MagicianRed TCG S.A.S. - Sistema de inventario y ventas
// Proyecto final - Fundamentos de Programacion 2026-2
// Universidad de San Buenaventura Cali - Prof. Giovanny Hidalgo
// Integrantes: Miguel Angel Cano, [Cadavid - nombre completo], [Miller - nombre completo]
// =====================================================================
//
// ESQUELETO: cada funcion ya existe pero esta vacia ("PENDIENTE").
// Asi el archivo compila desde el primer dia. Cada uno reemplaza el
// cuerpo de SUS funciones, dentro de SU zona, sin tocar las de los demas.
//
// Compilar:  g++ inventario.cpp -o magicianred.exe
// Ejecutar:  .\magicianred.exe   (Windows)     ./magicianred.exe   (Linux)

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constantes: lo unico global que se permite
const int MAX = 50;                 // maximo de productos
const int SEMANAS = 4;              // columnas de la matriz de ventas
const int STOCK_MIN = 3;            // alerta de stock bajo
const double IVA = 0.19;
const double DESCUENTO = 0.10;      // productos en promocion
const double PRECIO_SOBRE = 30000;  // precio del sobre sorpresa
const string ARCHIVO = "inventario.txt";
const string HISTORIAL = "historial_ventas.txt";

// ---------------------------------------------------------------------
// Prototipos (el "contrato": nadie los cambia sin avisar en el grupo)
// ---------------------------------------------------------------------

// Miller
bool iniciarSesion();
int leerEntero(string mensaje, int minimo, int maximo);
int cargarInventario(int codigo[], string nombre[], string categoria[], double precio[],
                     int stock[], bool promo[], int ventas[][SEMANAS]);
void guardarInventario(int codigo[], string nombre[], string categoria[], double precio[],
                       int stock[], bool promo[], int ventas[][SEMANAS], int n);
void guardarHistorial(string detalle);
void sobreSorpresa(string nombre[], string categoria[], int stock[],
                   int ventas[][SEMANAS], int n);

// Cadavid
int buscarProducto(int codigo[], int n, int codigoBuscado);
void registrarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                       int stock[], bool promo[], int ventas[][SEMANAS], int &n);
void listarProductos(int codigo[], string nombre[], string categoria[], double precio[],
                     int stock[], bool promo[], int n);
void actualizarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                        int stock[], bool promo[], int n);
void eliminarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                      int stock[], bool promo[], int ventas[][SEMANAS], int &n);
void venderProducto(int codigo[], string nombre[], double precio[], int stock[],
                    bool promo[], int ventas[][SEMANAS], int n);

// Miguel
void mostrarVentas(int codigo[], string nombre[], int ventas[][SEMANAS], int n);
int totalVendido(int ventas[][SEMANAS], int fila);
double calcularIngresos(double precio[], int ventas[][SEMANAS], int n);
int productoMasVendido(int ventas[][SEMANAS], int n);
int semanaConMasVentas(int ventas[][SEMANAS], int n);
void reporteStockBajo(int codigo[], string nombre[], int stock[], int n);
void graficoVentas(string nombre[], int ventas[][SEMANAS], int n);

// ---------------------------------------------------------------------
// main (Miller): solo llama funciones
// ---------------------------------------------------------------------
int main_original() {
    int codigo[MAX];
    string nombre[MAX];
    string categoria[MAX];
    double precio[MAX];
    int stock[MAX];
    bool promo[MAX];
    int ventas[MAX][SEMANAS];
    int n;

    srand(time(0));

    // PENDIENTE (Miller): login, menu con while + switch y submenu de reportes
    n = cargarInventario(codigo, nombre, categoria, precio, stock, promo, ventas);
    cout << "Esqueleto de MagicianRed TCG compilando. Productos cargados: " << n << endl;

    return 0;
}

// =====================================================================
// ===== ZONA MILLER ===================================================
// =====================================================================

// Pide usuario y contrasena; maximo 3 intentos. Retorna true si entra.
bool iniciarSesion() {
    // PENDIENTE
    return true;
}

// Pide un entero entre minimo y maximo y repite hasta que sea valido.
int leerEntero(string mensaje, int minimo, int maximo) {
    // PENDIENTE
    return minimo;
}

// Lee inventario.txt y llena arreglos y matriz. Retorna cuantos productos leyo.
int cargarInventario(int codigo[], string nombre[], string categoria[], double precio[],
                     int stock[], bool promo[], int ventas[][SEMANAS]) {
    // PENDIENTE
    return 0;
}

// Escribe arreglos y matriz en inventario.txt.
void guardarInventario(int codigo[], string nombre[], string categoria[], double precio[],
                       int stock[], bool promo[], int ventas[][SEMANAS], int n) {
    // PENDIENTE
}

// Agrega una linea al final de historial_ventas.txt.
void guardarHistorial(string detalle) {
    // PENDIENTE
}

// Vende un sobre sorpresa: 3 cartas al azar con stock.
void sobreSorpresa(string nombre[], string categoria[], int stock[],
                   int ventas[][SEMANAS], int n) {
    // PENDIENTE
}

// =====================================================================
// ===== ZONA CADAVID ==================================================
// =====================================================================

// Retorna la posicion del producto con ese codigo, o -1 si no existe.
int buscarProducto(int codigo[], int n, int codigoBuscado) {
    // PENDIENTE
    return -1;
}

// Agrega un producto nuevo (valida espacio y codigo repetido).
void registrarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                       int stock[], bool promo[], int ventas[][SEMANAS], int &n) {
    // PENDIENTE
}

// Muestra todos los productos en una tabla.
void listarProductos(int codigo[], string nombre[], string categoria[], double precio[],
                     int stock[], bool promo[], int n) {
    // PENDIENTE
}

// Cambia los datos de un producto existente.
void actualizarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                        int stock[], bool promo[], int n) {
    // PENDIENTE
}

// Elimina un producto y corre los demas (arreglos y matriz).
void eliminarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                      int stock[], bool promo[], int ventas[][SEMANAS], int &n) {
    // PENDIENTE
}

// Registra una venta e imprime la factura.
void venderProducto(int codigo[], string nombre[], double precio[], int stock[],
                    bool promo[], int ventas[][SEMANAS], int n) {
    // PENDIENTE
}

// =====================================================================
// ===== ZONA MIGUEL ===================================================
// =====================================================================

// Muestra la matriz de ventas: una fila por producto, una columna por
// semana, el total de cada producto al final de su fila y el total de
// cada semana en la ultima fila.
// Recibe: codigos, nombres, matriz de ventas y cantidad de productos.
// No retorna nada (void).
void mostrarVentas(int codigo[], string nombre[], int ventas[][SEMANAS], int n) {
    int i;
    int j;
    int totalSemana;
    int totalGeneral;

    if (n == 0) {
        cout << "No hay productos registrados." << endl;
    } else {
        cout << endl << "=== VENTAS DEL MES (unidades) ===" << endl;

        // Encabezado: Codigo, Producto, S1, S2, ... y Total
        cout << left << setw(8) << "Codigo" << setw(30) << "Producto";
        for (j = 0; j < SEMANAS; j++) {
            cout << "   S" << j + 1;
        }
        cout << right << setw(8) << "Total" << endl;

        // Una fila por producto: el for de afuera recorre productos (filas)
        // y el de adentro recorre las semanas (columnas) de ese producto.
        for (i = 0; i < n; i++) {
            cout << left << setw(8) << codigo[i] << setw(30) << nombre[i];
            for (j = 0; j < SEMANAS; j++) {
                cout << right << setw(5) << ventas[i][j];
            }
            cout << right << setw(8) << totalVendido(ventas, i) << endl;
        }

        // Ultima fila: total de cada semana. Aqui se invierte el orden:
        // el for de afuera recorre semanas y el de adentro suma los productos.
        totalGeneral = 0;
        cout << left << setw(38) << "Total por semana";
        for (j = 0; j < SEMANAS; j++) {
            totalSemana = 0;
            for (i = 0; i < n; i++) {
                totalSemana = totalSemana + ventas[i][j];
            }
            totalGeneral = totalGeneral + totalSemana;
            cout << right << setw(5) << totalSemana;
        }
        cout << right << setw(8) << totalGeneral << endl;
    }
}

// Suma las unidades que vendio un producto en todas las semanas del mes.
// Recibe: la matriz de ventas y la fila (posicion) del producto.
// Retorna: el total de unidades vendidas de ese producto (int).
int totalVendido(int ventas[][SEMANAS], int fila) {
    int j;
    int suma;

    suma = 0;
    for (j = 0; j < SEMANAS; j++) {
        suma = suma + ventas[fila][j];
    }
    return suma;
}

// Calcula los ingresos del mes a precio de lista:
// precio de cada producto x unidades que vendio en el mes.
// Recibe: precios, matriz de ventas y cantidad de productos.
// Retorna: el total de ingresos en pesos (double).
double calcularIngresos(double precio[], int ventas[][SEMANAS], int n) {
    int i;
    double total;

    total = 0;
    for (i = 0; i < n; i++) {
        total = total + precio[i] * totalVendido(ventas, i);
    }
    return total;
}

// Busca el producto que mas unidades vendio en el mes.
// Recibe: matriz de ventas y cantidad de productos.
// Retorna: la posicion de ese producto, o -1 si no hay productos.
int productoMasVendido(int ventas[][SEMANAS], int n) {
    int i;
    int posMayor;

    if (n == 0) {
        posMayor = -1;
    } else {
        posMayor = 0;   // suponemos que el primero es el mayor...
        for (i = 0; i < n; i++) {
            // ...y si encontramos uno que vendio mas, ese pasa a ser el mayor
            if (totalVendido(ventas, i) > totalVendido(ventas, posMayor)) {
                posMayor = i;
            }
        }
    }
    return posMayor;
}

// Busca la semana del mes en la que se vendieron mas unidades en total.
// Recorre la matriz por columnas: para cada semana suma todos los productos.
// Recibe: matriz de ventas y cantidad de productos.
// Retorna: el numero de columna de esa semana (0 = semana 1), o -1 si no hay productos.
int semanaConMasVentas(int ventas[][SEMANAS], int n) {
    int i;
    int j;
    int sumaSemana;
    int mayor;
    int semanaMayor;

    if (n == 0) {
        semanaMayor = -1;
    } else {
        mayor = -1;
        semanaMayor = 0;
        for (j = 0; j < SEMANAS; j++) {          // afuera: cada semana (columna)
            sumaSemana = 0;
            for (i = 0; i < n; i++) {            // adentro: cada producto (fila)
                sumaSemana = sumaSemana + ventas[i][j];
            }
            if (sumaSemana > mayor) {
                mayor = sumaSemana;
                semanaMayor = j;
            }
        }
    }
    return semanaMayor;
}

// Muestra los productos que hay que volver a pedir (stock <= STOCK_MIN).
// Recibe: codigos, nombres, stock y cantidad de productos.
// No retorna nada (void).
void reporteStockBajo(int codigo[], string nombre[], int stock[], int n) {
    int i;
    int contador;

    contador = 0;
    cout << endl << "=== PRODUCTOS CON STOCK BAJO (" << STOCK_MIN << " o menos) ===" << endl;
    for (i = 0; i < n; i++) {
        if (stock[i] <= STOCK_MIN) {
            cout << left << setw(8) << codigo[i] << setw(30) << nombre[i]
                 << "quedan " << stock[i] << endl;
            contador = contador + 1;
        }
    }

    if (contador == 0) {
        if (n == 0) {
            cout << "No hay productos registrados." << endl;
        } else {
            cout << "Todos los productos tienen stock suficiente." << endl;
        }
    } else {
        cout << contador << " producto(s) por reabastecer." << endl;
    }
}

// Dibuja un grafico de barras: una fila de * por producto,
// un asterisco por cada unidad vendida en el mes.
// Recibe: nombres, matriz de ventas y cantidad de productos.
// No retorna nada (void).
void graficoVentas(string nombre[], int ventas[][SEMANAS], int n) {
    int i;
    int k;
    int total;

    if (n == 0) {
        cout << "No hay productos registrados." << endl;
    } else {
        cout << endl << "=== GRAFICO DE VENTAS DEL MES (* = 1 unidad) ===" << endl;
        for (i = 0; i < n; i++) {
            total = totalVendido(ventas, i);
            cout << left << setw(30) << nombre[i] << "| ";
            for (k = 0; k < total; k++) {        // tantos * como unidades vendidas
                cout << "*";
            }
            cout << " " << total << endl;
        }
    }
}

// ---- main de prueba de Miguel: lee inventario.txt directo (solo para probar)
// ---- y llama a todos los reportes. El main oficial es main_original (Miller).
int main() {
    int codigo[MAX]; string nombre[MAX]; string categoria[MAX];
    double precio[MAX]; int stock[MAX]; bool promo[MAX]; int ventas[MAX][SEMANAS];
    int n, i, j, pos, sem;
    ifstream f("inventario.txt");
    f >> n;
    for (i = 0; i < n; i++) {
        f >> codigo[i] >> nombre[i] >> categoria[i] >> precio[i] >> stock[i] >> promo[i];
        for (j = 0; j < SEMANAS; j++) f >> ventas[i][j];
    }
    mostrarVentas(codigo, nombre, ventas, n);
    cout << "\ntotalVendido(fila 0) = " << totalVendido(ventas, 0) << endl;
    cout << fixed << setprecision(2) << "calcularIngresos = $" << calcularIngresos(precio, ventas, n) << endl;
    pos = productoMasVendido(ventas, n);
    cout << "productoMasVendido = " << pos << " (" << nombre[pos] << ", " << totalVendido(ventas, pos) << " unidades)" << endl;
    sem = semanaConMasVentas(ventas, n);
    cout << "semanaConMasVentas = columna " << sem << " (semana " << sem + 1 << ")" << endl;
    reporteStockBajo(codigo, nombre, stock, n);
    graficoVentas(nombre, ventas, n);
    cout << "\n--- casos borde: n = 0 ---" << endl;
    mostrarVentas(codigo, nombre, ventas, 0);
    cout << "productoMasVendido(n=0) = " << productoMasVendido(ventas, 0) << endl;
    cout << "semanaConMasVentas(n=0) = " << semanaConMasVentas(ventas, 0) << endl;
    reporteStockBajo(codigo, nombre, stock, 0);
    graficoVentas(nombre, ventas, 0);
    return 0;
}
