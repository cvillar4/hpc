# Estimación de la matriz de covarianza para el análisis de correlación en datos de covid-19 en el mundo.

La matriz de covarianza es muy importante en el álgebra lineal, el aprendizaje automático y el análisis de datos, pues su representación captura información relevante sobre los datos de entrada, la podemos encontrar en diferentes aplicaciones, como análisis de componentes principales, descomposición de matrices, estimación de valores y vectores propios, correlación entre variables.

Esta última es nuestro caso de estudio, pues queremos identificar a través de la matriz de correlación,  las variables que influyen en el número de afectados por covid-19 en el mundo, además con esta matriz podemos empezar a sacar conclusiones del análisis descriptivo de los datos.

## Dependencias

- ICPC
- C++ 11
- qopenmp

## Proceso de compilación

Dentro del proyecto se encuentra un archivo makefile, el cual facilita el proceso de compilación desde la terminal.

Para su ejecución, debemos lanzar el siguiente comando desde la terminal:

$ make

icpc -xMIC-AVX512 -qopenmp -mkl -std=c++11 -qopt-report=5 -o "app" "paralelo.cc"

## Proceso de ejecución

Si el archivo no se encuentra en la raíz, debemos ejecutar el siguiente comando:

$ echo "cd <directory>; ./app" | qsub

donde <directory> es la dirección del folder donde se encuentra el ejecutable.

Sin embargo, si el archivo no se encuentra en la raíz, el usuario debe ejecutar el siguiente comando:

$ echo ./app | qsub

Si todo sale bien, se deberían generar dos archivos de salida:

1. STDIN.o<id_del_proceso>
2. STDIN.e<id_del_proceso>

El archivo STDIN.e<id_del_proceso> debería estar vacío si no hubo problemas durante el proceso de ejecución.

El archivo STDIN.o<id_del_proceso> muestra el tiempo de ejecución que tomó el archivo.

## Análisis de resultados - Versión serial vs Versión paralela

Estimación de matriz de Correlación | Tiempo (s) (Media 6 Iteraciones) Paralelo | Tiempo(Media 6 Iteraciones) Serial
------------ | ------------- | -------------
A = 1000 x 3 | 0.001333 | 0.000554
A = 10.000 x 200 | 0.233868 | 0.608901
A = 100.000 x 200 | 1.978789 | 5.340000
A = 200.000 x 200 | 4.003732 | 10.580788
A = 400.000 x 200 | 6.209250 | 21.079382
A = 400.000 x 300 | 10.342588 | 44.705713
A = 400.000 x 400 | 17.881473 | 72.440418
