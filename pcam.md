## Instrucciones de paralelimos utilizando open-mp

### Paralelizar bucles

## #pragma omp parallel for

Esta instrucción permite que varios hilos ejecuten diferentes pasos del ciclo, mientras todos comparten las mismas posiciones de memoria del proceso, es útil en diferentes etapas de nuestro proceso de construcción de la matriz de correlación, como:

        1. Centrado de datos
        2. Transpuesta de la matriz de datos centrada.
        3. Producto punto entre la matriz y su transpuesta
        4. Escalar los datos de la matriz de covarianza, para obtener la matriz de correlación.

        #pragma omp parallel for
        for (int i = 0 ; i < rows ; i++){
            ...
        }

## #pragma omp for reduction(+:suma)

Esta instrucción permite crear diferentes copias de la variable _suma_ que es compartida por los hilos, de esta forma cada hilo procesa la instrucción dentro bucle y después hace la misma operación a través de los resultados preliminares, es útil en nuestro en proceso de construcción, en:

        1. Calcular la suma para posteriormente hallar la media de un descriptor.

        #pragma omp parallel for reduction(+:suma)
        for(int j = 0; j < cols ; j++){
            ...
        }

## #pragma omp simd

Esta instrucción permite ejecutar una instrucción sobre múltiples registros en memoria, es util cuando:

        1. Queremos calcular el producto de la matriz centrada y su transpuesta.

        #pragma omp simd
        for(int j = 0; j < cols ; j++){
            ...
        }

## Proceso PCAM

El proceso PCAM, openmpi para hallar la matriz de correlación se describe a continuación

![Gráfica](/images/pcam.png)
