#include <stdio.h>

#define MAX_PROD 4 
#define MAX_SUB 3 
#define MAX_CARRITO 30 


char categorias[MAX_PROD][20] = {"Pizza", "Hamburguesa", "Empanada","Bebida"};


char subnombres[MAX_PROD][MAX_SUB][30] = {
    {"Pizza hawaiana", "Pizza Pollo con champiñones", "Pizza mexicana"},
    {"Hamburguesa Sencilla", "Hamburguesa Doble", "Hamburguesa mixta"},
    {"Empanada pequeña","Empanada mediana","Maxi Empanada"},
    {"Limonada", "Jugo Natural", "Agua"}
};

float subprecios[MAX_PROD][MAX_SUB] = {
    {7500, 8000, 9000},
    {18000, 22000, 25000},
    {4000,8500,18000},
    {5000, 7000, 4000}
};


char carrito_nombres[MAX_CARRITO][30];
float carrito_precios[MAX_CARRITO];
int carrito_cant[MAX_CARRITO];
int numItems = 0;

void verCategorias() {
    int i;
    printf("\n--- CATEGORIAS ---\n");
    for (i = 0; i < MAX_PROD; i++) {
        printf("%d. %s\n", i + 1, categorias[i]);
    }
}


void verSubmenu(int cat) {
    int i;
    printf("\n--- %s ---\n", categorias[cat]);
    for (i = 0; i < MAX_SUB; i++) {
        printf("%d. %s - $%.2f\n", i + 1, subnombres[cat][i], subprecios[cat][i]);
     }
}


void agregarAlCarrito() {
    int cat, sub, cant;

    verCategorias();
    printf("\nSeleccione una categoria: ");
    scanf("%d", &cat);
    cat--;

    if (cat < 0 || cat >= MAX_PROD) {
        printf("Categoria inválida.\n");
        return;
     }

    verSubmenu(cat);
    printf("\nSeleccione una opción: ");
    scanf("%d", &sub);
    sub--;

    if (sub < 0 || sub >= MAX_SUB) {
        printf("Opción inválida.\n");
        return;
     }

    printf("Ingrese la cantidad: ");
    scanf("%d", &cant);

    if (cant <= 0) {
        printf("Cantidad inválida.\n");
        return;
     }


     int i;
     for (i = 0; i < 30 && subnombres[cat][sub][i] != '\0'; i++) {
        carrito_nombres[numItems][i] = subnombres[cat][sub][i];
    }
     carrito_precios[numItems] = subprecios[cat][sub];
     carrito_cant[numItems] = cant;
     numItems++;

     printf("%s agregado al carrito.\n", subnombres[cat][sub]);
}


void verCarrito() {
    if (numItems == 0) {
         printf("\nEl carrito está vacío.\n");
         return;
    }

    int i;
    float subtotal = 0;
    printf("\n--- CARRITO ---\n");
    for (i = 0; i < numItems; i++) {
        float totalItem = carrito_precios[i] * carrito_cant[i];
        printf("%s x%d - $%.2f\n", carrito_nombres[i], carrito_cant[i], totalItem);
        subtotal += totalItem;
    }
    printf("Subtotal: $%.2f\n", subtotal);
}


void confirmarPedido() {
    if (numItems == 0) {
        printf("\nEl carrito está vacío, no se puede confirmar.\n");
        return;
    }
    verCarrito();
    printf("\nPedido confirmado. ¡Gracias por su compra!\n");
    numItems = 0; // vaciar carrito
}

int main() {
    int opcion;
     do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ver categorías\n");
        printf("2. Agregar producto al carrito\n");
        printf("3. Ver carrito y total\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: verCategorias(); break;
            case 2: agregarAlCarrito(); break;
            case 3: verCarrito(); break;
            case 4: confirmarPedido(); break;
            case 5: printf("Saliendo...\n"); break;
        default: printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}