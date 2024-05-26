//Se desea desarrollar un sistema de inventarios, el cual implemente las siguientes funcionalidades:

//Ingresar, editar y eliminar productos.
//Listar productos ingresados.
//Los productos ingresados deberán tener mínimo las siguientes variables:

//Nombre del producto-Cantidad-Precio

#include "inventario.h"

char nombres[maxproductos][longitunombre];
int cantidades[maxproductos];
float precioUnidad[maxproductos];
float preciototal[maxproductos];
int cantidadproduc = 0;


int main() {
  int opcion;


  do {
      printf("\nSistema de control de Inventarios\n");
      printf("1. Añadir Producto:\n");
      printf(" 2. Editar Producto :\n");
      printf("3. Eliminar Producto:\n");
      printf("4. Lista de productos\n");
      printf("5. Finalizar\n");
      printf("Ingrese una opcion: ");
      scanf("%d", &opcion);

      switch (opcion) {
          case 1:
              anadir();
              break;
          case 2:
              editar();
              break;
          case 3:
              eliminar();
              break;
          case 4:
              lista();
              break;
          case 5:
              printf("Saliendo...\n");
              break;
          default:
              printf("Opcion invalida, eliga nuevamente.\n");
      }
  } while (opcion != 5);

    return 0;
  }



