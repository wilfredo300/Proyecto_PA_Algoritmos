# Proyecto de Algoritmos y Análisis de Rendimiento

## Objetivos
- Implementar y comparar el rendimiento de algoritmos de ordenamiento (Cocktail Sort y Merge Sort) sobre listas de diferentes tamaños y patrones (aleatorio, ordenado, decreciente).
- Medir tiempos, comparaciones e intercambios para cada algoritmo y analizar los resultados.
- Automatizar la generación de listas, ejecución de benchmarks y recolección de datos para su análisis.

## Cómo compilar

1. Abre una terminal en la carpeta raíz del proyecto.
2. Compila los generadores de listas (opcional).
    El repositorio tiene ya generadas las listas exactas que se usaron al momento de la medición. Si deseas generar otras listas, puedes seguir los pasos de la sección "Compilar y ejecutar generadores de listas".
3. Compila y ejecuta los algoritmos a medir (mergeSort.cpp, cocktailSort.cpp)

### Compilar y ejecutar generadores de listas
```sh
# Compilar generadores de listas 
cd generadores_de_listas   #asegurate de entrar a la carpeta que los contiene)
 g++ generadorAle.cpp -o generadorAle.exe   
 g++ generadorDec.cpp -o generadorDec.exe
 g++ generadorOrd.cpp -o generadorOrd.exe

# Generar los archivos de listas (esto sobrescribe los .h)
 ./generadorAle.exe
 ./generadorDec.exe
 ./generadorOrd.exe


```

## Cómo ejecutar la medición (benchmarks)

Desde la raíz del proyecto, ejecuta:

```sh
# Volver a la raíz (si es necesario)
cd ..
# Compilar los algoritmos
g++ cocktailSort.cpp -o cocktailSort.exe
 g++ mergeSort.cpp -o mergeSort.exe
# Ejecutar los algoritmos ya compilados
./cocktailSort.exe
./mergeSort.exe
```

Esto generará los archivos `datos_de_medicion/datosCocktailSort.csv` y `datos_de_medicion/datosMergeSort.csv` con los resultados de las pruebas.

## Cómo regenerar tablas y figuras

1. Borra o mueve los archivos en `algoritmos_y_listas/` que comiencen con `listasAleatorias`, `listasOrdenadas` y `listasDecrecientes` si deseas listas nuevas.
2. Ejecuta los generadores de listas como se indica arriba.
3. Vuelve a compilar los algoritmos si cambiaste los .h.
4. Ejecuta los benchmarks para obtener nuevos datos.
5. Usa tu herramienta favorita (Excel, Python, etc.) para graficar los resultados a partir de los archivos CSV generados.

## Versiones de compilador y SO
- **Compilador:** g++ (MinGW.org GCC-6.3.0-1) 6.3.0
- **Sistema Operativo:** Microsoft Windows 10 Pro, versión 10.0.19045

## Semillas utilizadas
- En todos los generadores de listas aleatorias se usó `srand(0);` para garantizar reproducibilidad.
- El campo `semilla` en los CSV es 0.
- Cabe mencionar que el código genera 0 en el csv en el campo semilla aun con las listas no aleatorias, pero en realidad no se ha usado ninguna semilla para generar las listas ordenadas y ascendentes ni descendentes

## Commit hash de la versión final
- `aaabf00adf5d855745781a059774bc7104c7e29a`

---

**Autor:** [Wilfredo Junior Valdivia Vera]
**Fecha:** Octubre 2025
