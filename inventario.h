#include <stdio.h>
#include <string.h>

#define maxproductos 10
#define longitunombre 25

extern char nombres[maxproductos][longitunombre];
extern int cantidades[maxproductos];
extern float precioUnidad[maxproductos];
extern float preciototal[maxproductos];
extern int cantidadproduc;

void calcularpreciototal(int a) {
  preciototal[a] = cantidades[a] * precioUnidad[a];
}

void anadir() {
  if (cantidadproduc >= maxproductos) {
      printf("No hay más espacio\n");
      return;
  }

  printf("Ingrese el nombre del producto: ");
  scanf(" %25[^\n]", nombres[cantidadproduc]);

  for (int i = 0; i < cantidadproduc; i++) {
      if (strcmp(nombres[i], nombres[cantidadproduc]) == 0) {
          printf("Ese producto ya existe\n");
          return;
      }
  }

  printf("Ingrese la cantidad: ");
  if (scanf("%d", &cantidades[cantidadproduc]) < 1) {
      printf("Cantidad inválida.\n");
      return;
  }

  printf("Ingrese el precio unitario: ");
  if (scanf("%f", &precioUnidad[cantidadproduc]) < 1) {
      printf("Precio inválido.\n");
      return;
  }

  calcularpreciototal(cantidadproduc);
  cantidadproduc++;
  printf("Producto añadido correctamente.\n");
}

void editar() {
  char nombre[longitunombre];
  printf("Ingrese el nombre del producto a editar: ");
  scanf(" %25[^\n]", nombre);

  for (int i = 0; i < cantidadproduc; i++) {
      if (strcmp(nombres[i], nombre) == 0) {
          printf("Ingrese la nueva cantidad: ");
          if (scanf("%d", &cantidades[i]) != 1) {
              printf("Cantidad inválida.\n");
              return;
          }

          printf("Ingrese el nuevo precio unitario: ");
          if (scanf("%f", &precioUnidad[i]) != 1) {
              printf("Precio inválido.\n");
              return;
          }

          calcularpreciototal(i);
          printf("Producto editado correctamente.\n");
          return;
      }
  }

  printf("Producto no encontrado\n");
}

void eliminar() {
  char nombre[longitunombre];
  printf("Ingrese el nombre del producto a eliminar: ");
  scanf(" %24[^\n]", nombre); 

  for (int i = 0; i < cantidadproduc; i++) {
      if (strcmp(nombres[i], nombre) == 0) {
          for (int j = i; j < cantidadproduc - 1; j++) {
              strcpy(nombres[j], nombres[j + 1]);
              cantidades[j] = cantidades[j + 1];
              precioUnidad[j] = precioUnidad[j + 1];
              preciototal[j] = preciototal[j + 1];
          }
          cantidadproduc--;
          printf("Producto eliminado correctamente.\n");
          return;
      }
  }

  printf("Producto no encontrado\n");
}

void lista() {
  if (cantidadproduc == 0) {
      printf("No hay productos en el inventario.\n");
      return;
  }

  printf("Lista de productos:\n\n");
  printf("| %-20s | %-10s | %-15s | %-15s |\n", "Nombre", "Cantidad", "Precio Unitario", "Precio Total");
  printf("|----------------------|------------|------------------|------------------|\n");
  for (int i = 0; i < cantidadproduc; i++) {
      printf("| %-20s | %-10d | $%-15.2f | $%-15.2f |\n",
             nombres[i], cantidades[i], precioUnidad[i], preciototal[i]);
  }
}