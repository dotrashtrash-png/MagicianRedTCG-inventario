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
int main() {
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

// Muestra la matriz de ventas con totales por producto y por semana.
void mostrarVentas(int codigo[], string nombre[], int ventas[][SEMANAS], int n) {
    // PENDIENTE
}

// Retorna cuantas unidades vendio el producto de esa fila en el mes.
int totalVendido(int ventas[][SEMANAS], int fila) {
    // PENDIENTE
    return 0;
}

// Retorna los ingresos del mes: precio x unidades vendidas de cada producto.
double calcularIngresos(double precio[], int ventas[][SEMANAS], int n) {
    // PENDIENTE
    return 0;
}

// Retorna la posicion del producto con mas unidades vendidas.
int productoMasVendido(int ventas[][SEMANAS], int n) {
    // PENDIENTE
    return 0;
}

// Retorna el numero de columna (semana) con mas unidades vendidas.
int semanaConMasVentas(int ventas[][SEMANAS], int n) {
    // PENDIENTE
    return 0;
}

// Muestra los productos con stock menor o igual a STOCK_MIN.
void reporteStockBajo(int codigo[], string nombre[], int stock[], int n) {
    // PENDIENTE
}

// Dibuja una barra de * por producto segun lo que vendio en el mes.
void graficoVentas(string nombre[], int ventas[][SEMANAS], int n) {
    // PENDIENTE
}
