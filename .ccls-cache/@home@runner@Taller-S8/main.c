//Se desea desarrollar un sistema de inventarios, el cual implemente las siguientes funcionalidades:

//Ingresar, editar y eliminar productos.
//Listar productos ingresados.
//Los productos ingresados deberán tener mínimo las siguientes variables:

//Nombre del producto-Cantidad-Precio

#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 10
#define LONG_NOMBRE 25

char names[MAX_PRODUCTS][LONG_NOMBRE];
int quantities[MAX_PRODUCTS];
float unitPrices[MAX_PRODUCTS];
float totalPrices[MAX_PRODUCTS];
int productCount = 0;

void calculateTotalPrice(int index) {
    totalPrices[index] = quantities[index] * unitPrices[index];
}

/*void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}*/

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    printf("Enter product name: ");
    fgets(names[productCount], LONG_NOMBRE, stdin);
    names[productCount][strcspn(names[productCount], "\n")] = '\0'; // Remove newline character

    // Check for duplicate product name
    for (int i = 0; i < productCount; i++) {
        if (strcmp(names[i], names[productCount]) == 0) {
            printf("Product already exists.\n");
            return;
        }
    }

    printf("Enter quantity: ");
    if (scanf("%d", &quantities[productCount]) != 1) {
        printf("Invalid input for quantity.\n");
        clearInputBuffer();
        return;
    }
    printf("Enter unit price: ");
    if (scanf("%f", &unitPrices[productCount]) != 1) {
        printf("Invalid input for unit price.\n");
        clearInputBuffer();
        return;
    }

    calculateTotalPrice(productCount);

    productCount++;
    printf("Product added successfully.\n");
    clearInputBuffer();
}

void editProduct() {
    char name[LONG_NOMBRE];
    printf("Enter the name of the product to edit: ");
    fgets(name, LONG_NOMBRE, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < productCount; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Enter new quantity: ");
            if (scanf("%d", &quantities[i]) != 1) {
                printf("Invalid input for quantity.\n");
                clearInputBuffer();
                return;
            }
            printf("Enter new unit price: ");
            if (scanf("%f", &unitPrices[i]) != 1) {
                printf("Invalid input for unit price.\n");
                clearInputBuffer();
                return;
            }

            calculateTotalPrice(i);
            printf("Product updated successfully.\n");
            clearInputBuffer();
            return;
        }
    }

    printf("Product not found.\n");
}

void deleteProduct() {
    char name[LONG_NOMBRE];
    printf("Enter the name of the product to delete: ");
    fgets(name, LONG_NOMBRE, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < productCount; i++) {
        if (strcmp(names[i], name) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                strcpy(names[j], names[j + 1]);
                quantities[j] = quantities[j + 1];
                unitPrices[j] = unitPrices[j + 1];
                totalPrices[j] = totalPrices[j + 1];
            }
            productCount--;
            printf("Product deleted successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("Product List:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Name: %s, Quantity: %d, Unit Price: %.2f, Total Price: %.2f\n",
               names[i], quantities[i], unitPrices[i], totalPrices[i]);
    }
}

int main() {
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Edit Product\n");
        printf("3. Delete Product\n");
        printf("4. List Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer(); // Clear buffer after reading choice

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                listProducts();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
