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
int main() {
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

// Pide usuario y contrasena; da maximo 3 intentos.
// No recibe parametros.
// Retorna: true si el usuario entro, false si se acabaron los intentos.
bool iniciarSesion() {
    string usuario;
    string clave;
    const string USER_CORRECTO = "admin";
    const string PASS_CORRECTA = "tcg2026";
    int intento;

    for (intento = 1; intento <= 3; intento++) {
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

// Pide un numero entero y repite la pregunta hasta que sea valido.
// Recibe: el mensaje a mostrar y el rango permitido (minimo y maximo).
// Retorna: el numero que escribio el usuario, ya validado.
int leerEntero(string mensaje, int minimo, int maximo) {
    int valor;

    cout << mensaje;
    cin >> valor;
    // cin.fail() es verdadero si escribieron letras en vez de un numero
    while (cin.fail() || valor < minimo || valor > maximo) {
        cin.clear();             // quita el estado de error de cin
        cin.ignore(1000, '\n');  // descarta lo que quedo escrito
        cout << "Error. Ingrese un numero entre " << minimo << " y " << maximo << ": ";
        cin >> valor;
    }
    cin.ignore(1000, '\n');      // limpia el Enter que quedo pendiente
    return valor;
}

// Lee inventario.txt y llena los arreglos y la matriz de ventas.
// Recibe: los arreglos de productos y la matriz de ventas (aqui se llenan).
// Retorna: cuantos productos leyo (0 si el archivo no existe).
int cargarInventario(int codigo[], string nombre[], string categoria[], double precio[],
                     int stock[], bool promo[], int ventas[][SEMANAS]) {
    ifstream archivo(ARCHIVO);
    int n;
    int i;
    int j;

    if (!archivo.is_open()) {
        cout << "No se encontro inventario.txt. Se empieza con el inventario vacio." << endl;
        return 0;
    }

    n = 0;
    archivo >> n;
    if (n > MAX) {      // no se pueden cargar mas productos de los que caben
        n = MAX;
    }

    for (i = 0; i < n; i++) {
        archivo >> codigo[i] >> nombre[i] >> categoria[i] >> precio[i] >> stock[i] >> promo[i];
        for (j = 0; j < SEMANAS; j++) {
            archivo >> ventas[i][j];
        }
    }

    archivo.close();
    return n;
}

// Escribe todos los productos y sus ventas en inventario.txt (reemplaza el archivo).
// Recibe: los arreglos de productos, la matriz de ventas y la cantidad n.
// No retorna nada (void).
void guardarInventario(int codigo[], string nombre[], string categoria[], double precio[],
                       int stock[], bool promo[], int ventas[][SEMANAS], int n) {
    ofstream archivo(ARCHIVO);
    int i;
    int j;

    if (!archivo.is_open()) {
        cout << "ERROR: no se pudo abrir " << ARCHIVO << " para guardar." << endl;
        return;
    }

    archivo << n << "\n";
    archivo << fixed << setprecision(0);   // precios enteros, sin notacion 1.25e+06

    for (i = 0; i < n; i++) {
        archivo << codigo[i] << " " << nombre[i] << " " << categoria[i] << " "
                << precio[i] << " " << stock[i] << " " << promo[i];
        for (j = 0; j < SEMANAS; j++) {
            archivo << " " << ventas[i][j];
        }
        archivo << "\n";
    }

    archivo.close();    // se cierra una sola vez, despues de escribir todos
}

// Agrega una linea al final de historial_ventas.txt sin borrar lo anterior.
// Recibe: el texto que se va a guardar.
// No retorna nada (void).
void guardarHistorial(string detalle) {
    ofstream archivo(HISTORIAL, ios::app);   // ios::app = agregar al final

    if (!archivo.is_open()) {
        cout << "ERROR: no se pudo abrir " << HISTORIAL << "." << endl;
        return;
    }

    archivo << detalle << "\n";
    archivo.close();
}

// Vende un sobre sorpresa: escoge al azar 3 cartas distintas con stock,
// les descuenta 1 unidad y suma la venta en la semana que diga el usuario.
// Recibe: nombres, categorias, stock, matriz de ventas y cantidad de productos.
// No retorna nada (void).
void sobreSorpresa(string nombre[], string categoria[], int stock[],
                   int ventas[][SEMANAS], int n) {
    int disponibles;
    int semana;
    int elegidos[3];
    int encontrados;
    int idx;
    int pos;
    int i;
    int k;
    bool repetido;
    double ivaSobre;
    double totalSobre;
    string resumenCartas;

    // Contar cuantas cartas distintas tienen stock
    disponibles = 0;
    for (i = 0; i < n; i++) {
        if (categoria[i] == "Carta" && stock[i] > 0) {
            disponibles++;
        }
    }

    if (disponibles < 3) {
        cout << "No hay suficientes cartas con stock para armar un sobre (se necesitan 3)." << endl;
        return;
    }

    semana = leerEntero("Ingrese la semana de la venta (1 a " + to_string(SEMANAS) + "): ",
                        1, SEMANAS);

    // Sacar posiciones al azar hasta tener 3 cartas distintas con stock.
    // El ciclo siempre termina porque arriba se verifico que hay al menos 3.
    encontrados = 0;
    while (encontrados < 3) {
        idx = rand() % n;               // posicion al azar entre 0 y n-1
        repetido = false;
        for (k = 0; k < encontrados; k++) {
            if (elegidos[k] == idx) {
                repetido = true;
            }
        }
        if (!repetido && categoria[idx] == "Carta" && stock[idx] > 0) {
            elegidos[encontrados] = idx;
            encontrados++;
        }
    }

    ivaSobre = PRECIO_SOBRE * IVA;
    totalSobre = PRECIO_SOBRE + ivaSobre;

    cout << "\n=== FACTURA SOBRE SORPRESA ===" << endl;
    cout << "Cartas obtenidas:" << endl;

    resumenCartas = "";
    for (k = 0; k < 3; k++) {
        pos = elegidos[k];
        stock[pos]--;
        ventas[pos][semana - 1]++;
        cout << "  " << (k + 1) << ". " << nombre[pos] << endl;
        resumenCartas += nombre[pos];
        if (k < 2) {
            resumenCartas += ", ";
        }
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

// Pide un codigo y muestra todos los datos del producto y sus ventas por semana.
void verProducto(int codigo[], string nombre[], string categoria[], double precio[],
                 int stock[], bool promo[], int ventas[][SEMANAS], int n) {
    // PENDIENTE
}

// Cambia los datos de un producto existente (incluida su fila de ventas).
void actualizarProducto(int codigo[], string nombre[], string categoria[], double precio[],
                        int stock[], bool promo[], int ventas[][SEMANAS], int n) {
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
