<div align="center">

# 🃏 MagicianRed TCG

### Sistema de inventario y ventas para una tienda de cartas coleccionables

![C++](https://img.shields.io/badge/C%2B%2B-consola-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Estado](https://img.shields.io/badge/estado-terminado-8B0000?style=for-the-badge)
![USB Cali](https://img.shields.io/badge/USB%20Cali-2026--2-1a1a1a?style=for-the-badge)

*Proyecto final · Fundamentos de Programación · Universidad de San Buenaventura Cali*

</div>

---

## ✨ Qué hace

**MagicianRed TCG S.A.S.** es una tienda (ficticia) de Cali que vende sobres, cajas, mazos, cartas sueltas y accesorios de **Pokémon TCG**, **Magic: The Gathering**, **Yu-Gi-Oh!** y **One Piece Card Game**. Antes llevaba todo en un cuaderno; este programa lo reemplaza.

| | Función | Detalle |
| :-: | --- | --- |
| 🔐 | **Inicio de sesión** | Usuario y contraseña, máximo 3 intentos |
| 📦 | **Inventario** | Registrar, ver, buscar, actualizar y eliminar productos |
| 🧾 | **Ventas con factura** | Descuento del 10 % si hay promoción e IVA del 19 % |
| 🎴 | **Sobre sorpresa** | 3 cartas al azar del inventario por $30.000 + IVA |
| 📊 | **Reportes** | Ventas por semana, ingresos del mes, producto más vendido, mejor semana, stock bajo y gráfico |
| 💾 | **Guardado automático** | Todo queda en `inventario.txt`, aunque cierres el programa |

## 👀 Así se ve

```
   #   #  ###   #### ###  #### ###  ###  #   #     ####  ##### ####
   ## ## #   # #      #  #      #  #   # ##  #     #   # #     #   #
   # # # ##### #  ##  #  #      #  ##### # # #     ####  ####  #   #
   #   # #   # #   #  #  #      #  #   # #  ##     #  #  #     #   #
   #   # #   #  ###  ###  #### ### #   # #   #     #   # ##### ####

   ==========[  T R A D I N G   C A R D   G A M E S  ]==========

      .---------.  .---------.  .---------.  .---------.
      |*        |  |+        |  |<>       |  |$        |
      | POKEMON |  |  MAGIC  |  |YU-GI-OH!|  |ONE PIECE|
      |   TCG   |  |   THE   |  |         |  |  CARD   |
      |        *|  |GATHERING|  |       <>|  |  GAME  $|
      '---------'  '---------'  '---------'  '---------'

          Tienda de cartas coleccionables  *  Cali, Colombia
```

<table>
<tr>
<td>

```
  +==================================================+
  |        MAGICIANRED TCG  *  MENU PRINCIPAL        |
  +==================================================+
  |  INVENTARIO                                      |
  |    [1] Registrar producto                        |
  |    [2] Ver inventario                            |
  |    [3] Buscar producto                           |
  |    [4] Actualizar producto                       |
  |    [5] Eliminar producto                         |
  |                                                  |
  |  CAJA                                            |
  |    [6] Registrar venta                           |
  |    [7] Abrir sobre sorpresa                      |
  |                                                  |
  |  ANALISIS                                        |
  |    [8] Reportes                                  |
  +--------------------------------------------------+
  |    [0] Guardar y salir                           |
  +==================================================+
```

</td>
<td>

```
  +========================================+
  |         MAGICIANRED TCG S.A.S.         |
  |     Cartas coleccionables  -  Cali     |
  |            FACTURA DE VENTA            |
  +========================================+
  | Producto    Caja_Booster_Magic         |
  | Cantidad    1                          |
  | Semana      2                          |
  |----------------------------------------|
  | Subtotal    $                520000.00 |
  | Descuento   -$                52000.00 |
  | IVA 19%     $                 88920.00 |
  +========================================+
  | TOTAL       $                556920.00 |
  +========================================+
  |    Gracias por tu compra, duelista!    |
  |  Que el corazon de las cartas te guie  |
  +========================================+
```

</td>
</tr>
</table>

```
  ~ ~ ~   Abriendo sobre sorpresa...   ~ ~ ~

     .------------------------------.
     | CARTA 1 de 3                 |
     |                              |
     | Carta_Pikachu                |
     '------------------------------'
     .------------------------------.
     | CARTA 2 de 3                 |
     |                              |
     | Carta_Luffy_Lider            |
     '------------------------------'
```

---

## ▶️ Cómo ejecutarlo

No necesitas saber programar ni usar GitHub. Escoge **una** de las opciones.

> [!IMPORTANT]
> **Para entrar al programa** (no es tu usuario de INGInious ni de la universidad):
>
> | Usuario | Contraseña |
> | :-: | :-: |
> | `admin` | `tcg2026` |
>
> Todo en minúsculas.

### Opción A · En INGInious (la plataforma del curso) 🎓

Si eres estudiante de Fundamentos de Programación de la USB Cali, esta es la forma recomendada.

1. Entra a **[inginious.usbcali.edu.co/console](https://inginious.usbcali.edu.co/console)** con tu cuenta de la universidad.
2. En **Nueva carpeta**, escribe `MagicianRedTCG` y presiona el botón verde de la carpeta. El programa y su archivo de datos **tienen que estar en la misma carpeta**.
3. **Crear el programa:** en el formulario de abajo escribe el nombre `MagicianRedTCG`, deja el lenguaje en **C++**, escoge la carpeta `MagicianRedTCG` y presiona **+ Crear**.
4. Aquí en GitHub abre **`inventario.cpp`**, presiona el ícono de **copiar** (arriba a la derecha del código), vuelve a INGInious, pega todo en **Código fuente** y presiona **Guardar**.
5. **Crear el archivo de datos:** en el mismo formulario escribe el nombre `inventario.txt`, escoge el lenguaje **Texto (.txt)** y la misma carpeta. Presiona **+ Crear**.
6. Copia el contenido de **`inventario.txt`** de aquí, pégalo en INGInious y presiona **Guardar**.
7. Vuelve a abrir el archivo **MagicianRedTCG**. Debajo del código debe decir *"Este programa puede abrir: inventario.txt"*.
8. Activa **Usar terminal interactiva** y presiona **Ejecutar**. El programa corre abajo y puedes escribir como en una consola normal.

> 💡 El programa guarda los cambios en `inventario.txt` cuando termina. Si quieres volver a los datos de fábrica, pega otra vez el contenido de `inventario_original.txt` en ese archivo.

### Opción B · Sin cuenta (en el navegador) 🌐

La más fácil. Funciona en cualquier computador.

1. En esta página, abre el archivo **`inventario.cpp`**, haz clic en el ícono de **copiar** (arriba a la derecha del código) y déjalo copiado.
2. Entra a **[onlinegdb.com](https://www.onlinegdb.com/online_c++_compiler)**.
3. Borra lo que trae el editor y **pega** el código.
4. Haz clic en el ícono de **hoja con +** (*New file*, arriba del editor) y llama al archivo `inventario.txt`.
5. Vuelve a esta página, abre **`inventario.txt`**, cópialo y **pégalo** en ese archivo nuevo.
6. Presiona el botón verde **Run**. El programa aparece abajo.

### Opción C · En tu computador 💻

**Paso 1 · Descargar el proyecto**

En esta página: botón verde **`<> Code`** → **Download ZIP**. Busca el `.zip` en tu carpeta de Descargas, haz clic derecho → **Extraer todo**.

**Paso 2 · Instalar el compilador (solo la primera vez)**

<details>
<summary><b>🪟 Windows</b></summary>

1. Descarga e instala **MSYS2** desde [msys2.org](https://www.msys2.org/). Dale *Next* a todo, sin cambiar nada.
2. Al terminar se abre una ventana negra. Pega esto (clic derecho → *Paste*) y presiona Enter:
   ```
   pacman -S --needed mingw-w64-ucrt-x86_64-gcc
   ```
   Cuando pregunte `[Y/n]`, escribe `Y` y Enter.
3. Tecla Windows → escribe **variables de entorno** → *Editar las variables de entorno de esta cuenta* → selecciona **Path** → **Editar** → **Nuevo** → pega `C:\msys64\ucrt64\bin` → **Aceptar** en todo.

</details>

<details>
<summary><b>🍎 Mac</b></summary>

Abre la app **Terminal**, escribe esto y presiona Enter. Acepta la instalación que aparece:
```
xcode-select --install
```

</details>

**Paso 3 · Compilar y abrir**

<details>
<summary><b>🪟 Windows</b></summary>

1. Abre la carpeta que extrajiste (la que tiene `inventario.cpp`).
2. Haz clic en la **barra de dirección** de arriba, escribe `cmd` y presiona Enter. Se abre una ventana negra en esa carpeta.
3. Escribe estas dos líneas, presionando Enter después de cada una:
   ```
   g++ inventario.cpp -o magicianred.exe
   magicianred.exe
   ```

> Si usas la terminal de **VS Code** o **PowerShell**, la segunda línea va con `.\` adelante: `.\magicianred.exe`

</details>

<details>
<summary><b>🍎 Mac</b></summary>

1. Abre **Terminal**, escribe `cd ` (con un espacio al final) y **arrastra** la carpeta del proyecto a la ventana. Presiona Enter.
2. Escribe estas dos líneas, presionando Enter después de cada una:
   ```
   g++ inventario.cpp -o magicianred.exe
   ./magicianred.exe
   ```

</details>

Cuando abra, entra con usuario `admin` y contraseña `tcg2026`.

> 💡 **¿Quieres empezar con los datos de fábrica?** El programa va guardando los cambios en `inventario.txt`. Para volver al inicio, copia el contenido de `inventario_original.txt` dentro de `inventario.txt`.

---

## 📁 Archivos

| Archivo | Qué es |
| --- | --- |
| `inventario.cpp` | El programa |
| `inventario.txt` | Los productos y sus ventas (el programa lo lee y lo actualiza) |
| `inventario_original.txt` | Copia de los datos de prueba, para empezar de cero |

## 👥 Equipo

<div align="center">

| Miguel Ángel Cano Zapata | Juan Sebastián Cadavid | Juan Guillermo Miller Domínguez |
| :-: | :-: | :-: |
| Matriz de ventas y reportes | Inventario (CRUD) y facturación | Archivos, inicio de sesión y menú |

<br>

*Hecho en Cali* 🇨🇴

</div>
