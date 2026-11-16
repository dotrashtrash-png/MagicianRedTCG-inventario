# MagicianRed TCG: instrucciones para Claude

Proyecto final de Fundamentos de Programación (USB Cali, 2026-2). Equipo: Miguel, Cadavid y Miller. Somos principiantes en C++.

## Cómo ayudarnos

- Explica antes de escribir código. Primero pistas y preguntas; la solución completa solo si la pedimos.
- En la sustentación a cada uno le preguntan cualquier línea, así que el código lo escribimos nosotros. Tú explicas, revisas y encuentras errores.
- Cada integrante tiene su zona en `inventario.cpp` (ZONA MILLER, ZONA CADAVID, ZONA MIGUEL). No toques la zona de otro.
- No cambies los prototipos ni las constantes sin que lo pidamos: los tres dependemos de ellos.
- No hagas commit ni push si no lo pedimos.

## Reglas del código (las pide el profe)

- Un solo archivo `inventario.cpp` que compile con `g++` en Windows y en Linux.
- Sin variables globales: solo constantes `const`. Todo pasa por parámetros.
- Variables declaradas al inicio de cada función, nunca a mitad.
- `if/else` anidados, no `else if`.
- Recorrer arreglos de 0 a `n-1`, nunca hasta `MAX`.
- Arreglos paralelos y una matriz: nada de `vector`, `struct`, clases ni punteros.
- Sin tildes ni ñ en el código ni en los textos que se imprimen.
- Comentario arriba de cada función: qué hace, qué recibe y qué retorna.

## Archivo de datos

`inventario.txt`: primera línea = cantidad de productos. Luego una línea por producto:
`codigo nombre categoria precio stock promo v1 v2 v3 v4` (nombres sin espacios, promo 1 o 0, v1..v4 = ventas por semana).
`inventario_original.txt` es la copia limpia: no se modifica.

## Compilar y correr

```
g++ inventario.cpp -o magicianred.exe
./magicianred.exe
```
