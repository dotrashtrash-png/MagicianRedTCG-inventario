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
void verProducto(int codigo[], string nombre[], string categoria[], double precio[],
                 int stock[], bool promo[], int ventas[][SEMANAS], int n);
void actualizarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                        int stock[], bool promo[], int ventas[][SEMANAS], int n);
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
    int n, opcion = -1, opcionReporte, pos, sem;

    srand(time(0));
if (!iniciarSesion()) {
        cout << "Acceso bloqueado." << endl;
        return 0;
    }

    n = cargarInventario(codigo, nombre, categoria, precio, stock, promo, ventas);
    cout << "Productos cargados: " << n << endl;

    while (opcion != 0) {
        cout << "\n=== MAGICIANRED TCG ===" << endl;
        cout << "1. Registrar producto" << endl;
        cout << "2. Ver inventario" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Actualizar producto" << endl;
        cout << "5. Eliminar producto" << endl;
        cout << "6. Registrar venta" << endl;
        cout << "7. Sobre sorpresa" << endl;
        cout << "8. Reportes" << endl;
        cout << "0. Salir" << endl;

        opcion = leerEntero("Opcion: ", 0, 8);

        switch (opcion) {
            case 1:
                registrarProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                guardarInventario(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                break;

            case 2:
                listarProductos(codigo, nombre, categoria, precio, stock, promo, n);
                break;

            case 3:
                verProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                break;

            case 4:
                actualizarProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                guardarInventario(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                break;

            case 5:
                eliminarProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                guardarInventario(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                break;

            case 6:
                venderProducto(codigo, nombre, precio, stock, promo, ventas, n);
                guardarInventario(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                break;

            case 7:
                sobreSorpresa(nombre, categoria, stock, ventas, n);
                guardarInventario(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                break;

            case 8:
                cout << "\n--- REPORTES ---" << endl;
                cout << "1. Mostrar ventas" << endl;
                cout << "2. Calcular ingresos del mes" << endl;
                cout << "3. Producto mas vendido" << endl;
                cout << "4. Semana con mas ventas" << endl;
                cout << "5. Reporte de stock bajo" << endl;
                cout << "6. Grafico de ventas" << endl;

                opcionReporte = leerEntero("Opcion de reporte: ", 1, 6);

                switch (opcionReporte) {
                    case 1:
                        mostrarVentas(codigo, nombre, ventas, n);
                        break;
                    case 2:
                        cout << fixed << setprecision(2) << "Ingresos del mes: $"
                             << calcularIngresos(precio, ventas, n) << endl;
                        break;
                    case 3:
                        pos = productoMasVendido(ventas, n);
                        if (pos == -1) {
                            cout << "No hay productos." << endl;
                        } else {
                            cout << "Mas vendido: " << nombre[pos] << " ("
                                 << totalVendido(ventas, pos) << " unidades)" << endl;
                        }
                        break;
                    case 4:
                        sem = semanaConMasVentas(ventas, n);
                        if (sem == -1) {
                            cout << "No hay productos." << endl;
                        } else {
                            cout << "Semana con mas ventas: " << sem + 1 << endl;
                        }
                        break;
                    case 5:
                        reporteStockBajo(codigo, nombre, stock, n);
                        break;
                    case 6:
                        graficoVentas(nombre, ventas, n);
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                        break;
                }
                break;

            case 0:
                guardarInventario(codigo, nombre, categoria, precio, stock, promo, ventas, n);
                cout << "Hasta luego." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }

    return 0;
}


// =====================================================================
// ===== ZONA MILLER ===================================================
// =====================================================================

// Pide usuario y contrasena; maximo 3 intentos. Retorna true si entra.
bool iniciarSesion() {  
    string usuario, clave;
    const string USER_CORRECTO = "admin";
    const string PASS_CORRECTA = "tcg2026";

    for (int intento = 1; intento <= 3; intento++) {
        cout << "\n=== INICIO DE SESION (Intento " << intento << " de 3) ===" << endl;
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Contrasena: ";
        cin >> clave;
        cin.ignore(1000, '\n');

        if (usuario == USER_CORRECTO && clave == PASS_CORRECTA) {
            cout << "Bienvenido al sistema MagicianRed TCG." << endl;
            return true;
        } else {
            cout << "Usuario o contrasena incorrectos." << endl;
        }
    }

    return false;
}

// Pide un entero entre minimo y maximo y repite hasta que sea valido.
int leerEntero(string mensaje, int minimo, int maximo) {
    int valor;
    cout << mensaje;
    cin >> valor;   
        while (cin.fail()||valor < minimo || valor > maximo) {
            cin.clear();
            cin.ignore(1000, '\n');  // limpia el buffer de entrada
            cout << "Error. Ingrese un numero entre " << minimo << " y " << maximo << ": ";
            cin >> valor;
        }
        cin.ignore(1000, '\n');  // limpia el buffer de entrada
    return valor;
}

// Lee inventario.txt y llena arreglos y matriz. Retorna cuantos productos leyo.
int cargarInventario(int codigo[], string nombre[], string categoria[], double precio[],
                     int stock[], bool promo[], int ventas[][SEMANAS]) {
    ifstream archivo(ARCHIVO);
    if (!archivo.is_open()) {
        cout << "No se encontro inventario.txt. Se empieza con el inventario vacio.\n";
        return 0;
    }
    int n = 0;
    archivo >> n;

    for(int i = 0; i < n; i++){
        archivo >> codigo[i] >> nombre[i] >> categoria[i] >> precio[i] >> stock[i] >> promo[i];
        for (int j = 0; j < SEMANAS; j++) {
            archivo >> ventas[i][j];
        }
    }
    archivo.close();
    return n;
}

// Escribe arreglos y matriz en inventario.txt.
void guardarInventario(int codigo[], string nombre[], string categoria[], double precio[],
                       int stock[], bool promo[], int ventas[][SEMANAS], int n) {
            ofstream archivo(ARCHIVO);
            if (!archivo.is_open()){
                cout << "ERROR: no se pudo abrir " << ARCHIVO << " para guardar. \n";
                return;
            }
            archivo << n << "\n";
            archivo << fixed << setprecision(0);

            for(int i= 0; i < n; i++){
                archivo << codigo[i] << " "
                        << nombre[i] <<  " "
                        << categoria[i] << " "
                        << precio [i] << " "
                        << stock [i] << " "
                        << promo [i];
            
            for (int j = 0; j < SEMANAS; j++) {
            archivo << " " << ventas[i][j];
        }
    
        archivo << "\n";

    archivo.close();
    }                      
}

// Agrega una linea al final de historial_ventas.txt.
void guardarHistorial(string detalle) {
    ofstream archivo(HISTORIAL, ios::app);
    if (!archivo.is_open()) {
        cout << "ERROR: no se pudo abrir " << HISTORIAL << ".\n";
        return;
    }

    archivo << detalle << "\n";
    archivo.close();
}


// Vende un sobre sorpresa: 3 cartas al azar con stock.
void sobreSorpresa(string nombre[], string categoria[], int stock[],
                   int ventas[][SEMANAS], int n) {
        int disponibles = 0;
    for (int i = 0; i < n; i++) {
        if (stock[i] > 0) {
            disponibles++;
        }
    }

    if (disponibles < 3) {
        cout << "No hay suficientes productos con stock disponible (se requieren al menos 3).\n";
        return;
    }

    int semana = leerEntero("Ingrese la semana de la venta (1 a 4): ", 1, SEMANAS);
    int elegidos[3] = {-1, -1, -1};
    int encontrados = 0;

    while (encontrados < 3) {
        int idx = rand() % n;
        bool repetido = false;

        for (int k = 0; k < encontrados; k++) {
            if (elegidos[k] == idx) {
                repetido = true;
            }
        }

        if (!repetido && stock[idx] > 0) {
            elegidos[encontrados] = idx;
            encontrados++;
        }
    }

    double ivaSobre = PRECIO_SOBRE * IVA;
    double totalSobre = PRECIO_SOBRE + ivaSobre;

    cout << "\n=== FACTURA SOBRE SORPRESA ===" << endl;
    cout << "Cartas obtenidas:" << endl;

    string resumenCartas = "";
    for (int k = 0; k < 3; k++) {
        int pos = elegidos[k];
        stock[pos]--;
        ventas[pos][semana - 1]++;
        cout << "  " << (k + 1) << ". " << nombre[pos] << " [" << categoria[pos] << "]" << endl;

        resumenCartas += nombre[pos];
        if (k < 2) resumenCartas += ", ";
    }

    cout << fixed << setprecision(0);
    cout << "Subtotal: $" << PRECIO_SOBRE << endl;
    cout << "IVA (19%): $" << ivaSobre << endl;
    cout << "Total a pagar: $" << totalSobre << endl;

    guardarHistorial("Sobre Sorpresa (Semana " + to_string(semana) + "): " +
                     resumenCartas + " | Total: $" + to_string((int)totalSobre));
}


// =====================================================================
// ===== ZONA CADAVID ==================================================
// =====================================================================

// Retorna la posicion del producto con ese codigo, o -1 si no existe.
int buscarProducto(int codigo[], int n, int codigoBuscado) {
    int i;
    int pos;

    pos = -1;
    for (i = 0; i < n; i++) {
        if (codigo[i] == codigoBuscado) {
            pos = i;
        }
    }
    return pos;
}

// Agrega un producto nuevo (valida espacio y codigo repetido).
void registrarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                       int stock[], bool promo[], int ventas[][SEMANAS], int &n) {
    int nuevoCodigo;
    int opcionCategoria;
    double nuevoPrecio;
    int j;

    if (n == MAX) {
        cout << "Inventario lleno." << endl;
    } else {
        nuevoCodigo = leerEntero("Codigo: ", 1, 99999);
        if (buscarProducto(codigo, n, nuevoCodigo) != -1) {
            cout << "Ese codigo ya existe." << endl;
        } else {
            codigo[n] = nuevoCodigo;

            cout << "Nombre (use _ en vez de espacios): ";
            cin >> nombre[n];
            cin.ignore(1000, '\n');

            cout << "1. Sobre  2. Caja  3. Mazo  4. Carta  5. Accesorio" << endl;
            opcionCategoria = leerEntero("Categoria: ", 1, 5);
            if (opcionCategoria == 1) {
                categoria[n] = "Sobre";
            } else {
                if (opcionCategoria == 2) {
                    categoria[n] = "Caja";
                } else {
                    if (opcionCategoria == 3) {
                        categoria[n] = "Mazo";
                    } else {
                        if (opcionCategoria == 4) {
                            categoria[n] = "Carta";
                        } else {
                            categoria[n] = "Accesorio";
                        }
                    }
                }
            }

            nuevoPrecio = 0;
            while (nuevoPrecio <= 0) {
                cout << "Precio: ";
                cin >> nuevoPrecio;
                if (cin.fail()) {
                    cin.clear();
                    nuevoPrecio = 0;
                }
                cin.ignore(1000, '\n');
                if (nuevoPrecio <= 0) {
                    cout << "Valor invalido. El precio debe ser mayor que 0." << endl;
                }
            }
            precio[n] = nuevoPrecio;

            stock[n] = leerEntero("Stock: ", 0, 10000);
            promo[n] = (leerEntero("Promocion (1 = si, 0 = no): ", 0, 1) == 1);

            for (j = 0; j < SEMANAS; j++) {
                ventas[n][j] = 0;
            }
            n++;
            cout << "Producto registrado." << endl;
        }
    }
}

// Muestra todos los productos en una tabla.
void listarProductos(int codigo[], string nombre[], string categoria[], double precio[],
                     int stock[], bool promo[], int n) {
     int i;
    if (n == 0) {
        cout << "No hay productos registrados." << endl;
    } else {
        cout << endl << "=== INVENTARIO ===" << endl;
        cout << left << setw(8) << "Codigo" << setw(30) << "Producto"
             << setw(12) << "Categoria" << right << setw(10) << "Precio"
             << setw(7) << "Stock" << setw(7) << "Promo" << endl;
        cout << fixed << setprecision(0);
        for (i = 0; i < n; i++) {
            cout << left << setw(8) << codigo[i] << setw(30) << nombre[i]
                 << setw(12) << categoria[i] << right << setw(10) << precio[i]
                 << setw(7) << stock[i] << setw(7) << (promo[i] ? "Si" : "No") << endl;
        }
    }
}

// Pide un codigo y muestra todos los datos del producto y sus ventas por semana.
void verProducto(int codigo[], string nombre[], string categoria[], double precio[],
                 int stock[], bool promo[], int ventas[][SEMANAS], int n) {
    int codigoBuscado;
    int pos;
    int j;

    codigoBuscado = leerEntero("Codigo a buscar: ", 1, 99999);
    pos = buscarProducto(codigo, n, codigoBuscado);
    if (pos == -1) {
        cout << "No existe un producto con ese codigo." << endl;
    } else {
        cout << endl << "=== PRODUCTO " << codigo[pos] << " ===" << endl;
        cout << "Nombre:    " << nombre[pos] << endl;
        cout << "Categoria: " << categoria[pos] << endl;
        cout << fixed << setprecision(0);
        cout << "Precio:    $" << precio[pos] << endl;
        cout << "Stock:     " << stock[pos] << endl;
        cout << "Promocion: " << (promo[pos] ? "Si" : "No") << endl;
        cout << "Ventas por semana:" << endl;
        for (j = 0; j < SEMANAS; j++) {
            cout << "  Semana " << j + 1 << ": " << ventas[pos][j] << endl;
        }
        cout << "Total del mes: " << totalVendido(ventas, pos) << " unidades" << endl;
    }
}

// Cambia los datos de un producto existente (incluida su fila de ventas).
void actualizarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                        int stock[], bool promo[], int ventas[][SEMANAS], int n) {
    int codigoBuscado;
    int pos;
    int opcion;
    int semana;
    double nuevoPrecio;

    codigoBuscado = leerEntero("Codigo a actualizar: ", 1, 99999);
    pos = buscarProducto(codigo, n, codigoBuscado);
    if (pos == -1) {
        cout << "No existe un producto con ese codigo." << endl;
    } else {
        cout << "1. Nombre  2. Precio  3. Stock  4. Promocion  5. Ventas de una semana" << endl;
        opcion = leerEntero("Que desea cambiar: ", 1, 5);
        switch (opcion) {
            case 1:
                cout << "Nuevo nombre (use _ en vez de espacios): ";
                cin >> nombre[pos];
                cin.ignore(1000, '\n');
                break;
            case 2:
                nuevoPrecio = 0;
                while (nuevoPrecio <= 0) {
                    cout << "Nuevo precio: ";
                    cin >> nuevoPrecio;
                    if (cin.fail()) {
                        cin.clear();
                        nuevoPrecio = 0;
                    }
                    cin.ignore(1000, '\n');
                    if (nuevoPrecio <= 0) {
                        cout << "Valor invalido. El precio debe ser mayor que 0." << endl;
                    }
                }
                precio[pos] = nuevoPrecio;
                break;
            case 3:
                stock[pos] = leerEntero("Nuevo stock: ", 0, 10000);
                break;
            case 4:
                promo[pos] = (leerEntero("Promocion (1 = si, 0 = no): ", 0, 1) == 1);
                break;
            case 5:
                semana = leerEntero("Semana (1-4): ", 1, SEMANAS);
                ventas[pos][semana - 1] = leerEntero("Unidades vendidas: ", 0, 10000);
                break;
        }
        cout << "Producto actualizado." << endl;
    }
}

// Elimina un producto y corre los demas (arreglos y matriz).
void eliminarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                      int stock[], bool promo[], int ventas[][SEMANAS], int &n) {
    int codigoBuscado;
    int pos;
    int confirmar;
    int i;
    int j;

    codigoBuscado = leerEntero("Codigo a eliminar: ", 1, 99999);
    pos = buscarProducto(codigo, n, codigoBuscado);
    if (pos == -1) {
        cout << "No existe un producto con ese codigo." << endl;
    } else {
        cout << "Se eliminara: " << nombre[pos] << endl;
        confirmar = leerEntero("Confirma (1 = si, 0 = no): ", 0, 1);
        if (confirmar == 1) {
            for (i = pos; i < n - 1; i++) {
                codigo[i] = codigo[i + 1];
                nombre[i] = nombre[i + 1];
                categoria[i] = categoria[i + 1];
                precio[i] = precio[i + 1];
                stock[i] = stock[i + 1];
                promo[i] = promo[i + 1];
                for (j = 0; j < SEMANAS; j++) {
                    ventas[i][j] = ventas[i + 1][j];
                }
            }
            n--;
            cout << "Producto eliminado." << endl;
        } else {
            cout << "Eliminacion cancelada." << endl;
        }
    }
}

// Registra una venta e imprime la factura.
void venderProducto(int codigo[], string nombre[], double precio[], int stock[],
                    bool promo[], int ventas[][SEMANAS], int n) {
    int codigoBuscado;
    int pos;
    int cantidad;
    int semana;
    double subtotal;
    double descuento;
    double iva;
    double total;

    codigoBuscado = leerEntero("Codigo a vender: ", 1, 99999);
    pos = buscarProducto(codigo, n, codigoBuscado);
    if (pos == -1) {
        cout << "No existe un producto con ese codigo." << endl;
    } else {
        if (stock[pos] == 0) {
            cout << "Producto agotado." << endl;
        } else {
            cantidad = leerEntero("Cantidad: ", 1, stock[pos]);
            semana = leerEntero("Semana (1-4): ", 1, SEMANAS);

            subtotal = precio[pos] * cantidad;
            descuento = promo[pos] ? subtotal * DESCUENTO : 0;
            iva = (subtotal - descuento) * IVA;
            total = subtotal - descuento + iva;

            stock[pos] = stock[pos] - cantidad;
            ventas[pos][semana - 1] = ventas[pos][semana - 1] + cantidad;

            cout << endl << "===== FACTURA =====" << endl;
            cout << fixed << setprecision(2);
            cout << left << setw(12) << "Producto:" << nombre[pos] << endl;
            cout << left << setw(12) << "Cantidad:" << cantidad << endl;
            cout << left << setw(12) << "Subtotal:" << right << setw(14) << subtotal << endl;
            cout << left << setw(12) << "Descuento:" << right << setw(14) << descuento << endl;
            cout << left << setw(12) << "IVA 19%:" << right << setw(14) << iva << endl;
            cout << left << setw(12) << "TOTAL:" << right << setw(14) << total << endl;

            guardarHistorial("Venta: " + to_string(cantidad) + " x " + nombre[pos]);
        }
    }
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
int main() {
    int codigo[MAX]; string nombre[MAX]; string categoria[MAX];
    double precio[MAX]; int stock[MAX]; bool promo[MAX]; int ventas[MAX][SEMANAS];
    int n, i, j;

    ifstream f("inventario.txt");
    f >> n;
    for (i = 0; i < n; i++) {
        f >> codigo[i] >> nombre[i] >> categoria[i] >> precio[i] >> stock[i] >> promo[i];
        for (j = 0; j < SEMANAS; j++) f >> ventas[i][j];
    }
    f.close();

    listarProductos(codigo, nombre, categoria, precio, stock, promo, n);
    cout << "buscar 105 = " << buscarProducto(codigo, n, 105) << endl;
    cout << "buscar 999 = " << buscarProducto(codigo, n, 999) << endl;
    listarProductos(codigo, nombre, categoria, precio, stock, promo, 0);
    registrarProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
    listarProductos(codigo, nombre, categoria, precio, stock, promo, n);
    verProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
    actualizarProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
    verProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
    eliminarProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
    listarProductos(codigo, nombre, categoria, precio, stock, promo, n);
    verProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
    venderProducto(codigo, nombre, precio, stock, promo, ventas, n);
    verProducto(codigo, nombre, categoria, precio, stock, promo, ventas, n);
    return 0;
}