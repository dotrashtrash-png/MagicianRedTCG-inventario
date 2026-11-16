# MagicianRedTCG-inventario

Sistema de inventario y ventas en C++ para **MagicianRed TCG S.A.S.**, una comercializadora (ficticia) de artículos coleccionables en Cali.

Proyecto final de Fundamentos de Programación, Universidad de San Buenaventura Cali, 2026-2.

**Equipo:** Miguel Ángel Cano · Cadavid · Miller

## Qué hace

- Inicio de sesión con 3 intentos
- Registrar, listar, buscar, actualizar y eliminar productos
- Ventas con factura (promoción e IVA)
- Sobre sorpresa con cartas al azar
- Reportes: matriz de ventas por semana, ingresos, producto más vendido, semana con más ventas, stock bajo y gráfico de barras
- Los datos se guardan en `inventario.txt`

## Archivos

| Archivo | Para qué |
| --- | --- |
| `inventario.cpp` | El programa oficial (lo que se entrega) |
| `inventario.txt` | Datos de prueba; el programa los modifica |
| `inventario_original.txt` | Copia limpia de los datos: no se toca |
| `prueba_<nombre>.cpp` | Archivo de pruebas de cada integrante |
| `CLAUDE.md` | Reglas del proyecto para Claude Code |

## Compilar y correr

```
g++ inventario.cpp -o magicianred.exe
```

Windows: `.\magicianred.exe` · Linux: `./magicianred.exe`
