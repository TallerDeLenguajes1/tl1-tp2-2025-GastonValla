#include<stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu { 
int velocidad;      // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
int anio;           // Año de fabricación (valor entre 2015 y 2024) 
int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
char *tipo_cpu;     // Tipo de procesador (apuntador a cadena de caracteres) 
}; 
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main()
{
    srand(time(NULL));
    struct compu pcs[5];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; 
    int i;

    for(i = 0; i < 5; i++) 
    {
        pcs[i].velocidad = (rand()%3) + 1;
        pcs[i].anio = (rand()%10) + 2015;
        pcs[i].cantidad_nucleos = (rand()%8)+1;
        pcs[i].tipo_cpu = tipos[rand()%6];
    }
    listarPCs(pcs, 5);
    mostrarMasVieja(pcs, 5);
    mostrarMasVeloz(pcs, 5);

return 0;
}

void listarPCs(struct compu pcs[], int cantidad)
{
    for(int i = 0; i < cantidad; i++) {
        printf("PC numero %d:\n", i+1);
        printf(" Velocidad: %d GHz\n", pcs[i].velocidad);
        printf(" Anio: %d\n", pcs[i].anio);
        printf(" Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf(" Tipo de CPU: %s\n \n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad) 
{
    int j = 0, i;

    for(int i = 1; i < cantidad; i++) 
    {
        if(pcs[i].anio < pcs[j].anio)
        {j = i;}
    }

printf("PC más vieja: La numero %d\n", j);
printf(" Velocidad: %d GHz\n", pcs[j].velocidad);
printf(" Anio: %d\n", pcs[j].anio);
printf(" Cantidad de nucleos: %d\n", pcs[j].cantidad_nucleos);
printf(" Tipo de CPU: %s\n \n", pcs[j].tipo_cpu);
}

void mostrarMasVeloz(struct compu pcs[], int cantidad)
{
int j = 0;
for(int i = 1; i < cantidad; i++) {
    if(pcs[i].velocidad > pcs[j].velocidad) 
    {j = i;}
}
printf("PC más veloz: La numero %d\n", j);
printf(" Velocidad: %d GHz\n", pcs[j].velocidad);
printf(" Anio: %d\n", pcs[j].anio);
printf(" Cantidad de nucleos: %d\n", pcs[j].cantidad_nucleos);
printf(" Tipo de CPU: %s\n \n", pcs[j].tipo_cpu);
}