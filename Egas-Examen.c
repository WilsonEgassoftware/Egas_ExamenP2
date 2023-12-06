#include <stdio.h>

#define NUM_ALUMNOS 23//definimos la cantidad de estudiantes de nuestro ejercicio
#define NUM_PROGRESOS 3//definimos los progresos del ejercicio

// Prototipos de funciones
float calcularPromedioAlumno(float notas[NUM_PROGRESOS]);//delcaramos las funciones decimales que obtendremos de los datos decimales
float calcularPromedioGrupo(float notas[NUM_ALUMNOS][NUM_PROGRESOS], int progreso);//declaramos el promedio, los datos decimales y el progreso en valor entero
int encontrarMejorAlumno(float notas[NUM_ALUMNOS][NUM_PROGRESOS]);//encontrar el mejor dato para poder encontrar el promedio final

float calcularPromedioAlumno(float notas[NUM_PROGRESOS]) {//calcumaos el promedio y declaramos en decimal
    float suma = 0;
    for (int i = 0; i < NUM_PROGRESOS; i++) {//verifcamos con el ciclo for con cada dato ingresado
        suma += notas[i];
    }
    return suma / NUM_PROGRESOS;//pedimos el regreso de la division de la suma entre el numeero de progresos
}
// Inicializar la variable suma para acumular las notas
float calcularPromedioGrupo(float notas[NUM_ALUMNOS][NUM_PROGRESOS], int progreso) {
    float suma = 0;
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        suma += notas[i][progreso];
    } // Calcular el promedio dividiendo la suma total por el número de progresos
    return suma / NUM_ALUMNOS;
}
  // Iterar a través de los progresos para sumar las notas
int encontrarMejorAlumno(float notas[NUM_ALUMNOS][NUM_PROGRESOS]) {
    int mejorAlumno = 0;
    float mejorPromedio = calcularPromedioAlumno(notas[0]);

    for (int i = 1; i < NUM_ALUMNOS; i++) {//se verifica la condicion de la cantidad de alumno y el numero de progresos
        float promedioActual = calcularPromedioAlumno(notas[i]);
        if (promedioActual > mejorPromedio) {
            mejorPromedio = promedioActual;
            mejorAlumno = i;
        }
    }

    return mejorAlumno;//pedimos regresar al dato ddel mejor alumno que sale de la división de datos
}
int main() {
    float notas[NUM_ALUMNOS][NUM_PROGRESOS];//declaramos de manera decimal las notas

    //Pedimos el ingreso de las notas y la cantidad de progresos
    printf("Ingrese las notas para cada alumno y progreso:\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        printf("Alumno %d:\n", i + 1);
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            printf("Progreso %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    // Realizamos el calcular promedio del grupo para cada progreso
    printf("\nPromedio del grupo para cada progreso:\n");
    for (int j = 0; j < NUM_PROGRESOS; j++) {
        printf("Progreso %d: %.2f\n", j + 1, calcularPromedioGrupo(notas, j));
    }
    // Realizamos el calculo para saber el mejor alumno y su promedio
    int mejorAlumno = encontrarMejorAlumno(notas);
    printf("\nEl alumno con el mejor promedio es el Alumno %d\n", mejorAlumno + 1);
    return 0;
}


