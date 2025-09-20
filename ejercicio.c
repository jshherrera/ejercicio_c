
#include <stdio.h>

#define MAX_PROD 4
#define MAX_SUB 4
#define MAX_CARRITO 30

// Categorías
char categorias[MAX_PROD][20] = {"Pizza", "Hamburguesa","Empanada", "Bebida"};

// Submenús
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
// Carrito
char carrito_nombres[MAX_CARRITO][30];
float carrito_precios[MAX_CARRITO];
int carrito_cant[MAX_CARRITO];
int numItems = 0;

// Mostrar categorías
void verCategorias() {
    int i;
    printf("\n--- CATEGORIAS ---\n");
    for (i = 0; i < MAX_PROD; i++) {
        printf("%d. %s\n", i + 1, categorias[i]);
    }
}

// Mostrar submenú
void verSubmenu(int cat) {
    int i;
    printf("\n--- %s ---\n", categorias[cat]);
    for (i = 0; i < MAX_SUB; i++) {
        printf("%d. %s - $%.2f\n", i + 1, subnombres[cat][i], subprecios[cat][i]);
    }
}

// Agregar producto con submenú
void agregarAlCarrito() {
    int cat, sub, cant, i;

    verCategorias();
    printf("\nSeleccione una categoria: ");
    if (scanf("%d", &cat) != 1) {
        printf("Entrada inválida.\n");
        while (getchar() != '\n'); // limpiar buffer
        return;
    }
    cat--;

    if (cat < 0 || cat >= MAX_PROD) {
        printf("Categoria inválida.\n");
        return;
    }

    verSubmenu(cat);
    printf("\nSeleccione una opción: ");
    if (scanf("%d", &sub) != 1) {
        printf("Entrada inválida.\n");
        while (getchar() != '\n'); // limpiar buffer
        return;
    }
    sub--;

    if (sub < 0 || sub >= MAX_SUB) {
        printf("Opción inválida.\n");
        return;
    }

    printf("Ingrese la cantidad: ");
    if (scanf("%d", &cant) != 1) {
        printf("Entrada inválida.\n");
        while (getchar() != '\n'); // limpiar buffer
        return;
    }

    if (cant <= 0) {
         printf("Cantidad inválida.\n");
        return;
    }

    for (i = 0; i < 30 && subnombres[cat][sub][i] != '\0'; i++) {
    carrito_nombres[numItems][i] = subnombres[cat][sub][i];
    }
    carrito_nombres[numItems][i] = '\0';

    carrito_precios[numItems] = subprecios[cat][sub];
    carrito_cant[numItems] = cant;
    numItems++;

    printf("%s agregado al carrito.\n", subnombres[cat][sub]);
}

// Ver carrito
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

// Confirmar pedido
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

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida.\n");
            while (getchar() != '\n'); // limpiar buffer
            opcion = 0; // fuerza repetir menú
        }

        switch (opcion) {
            case 1: verCategorias(); break;
            case 2: agregarAlCarrito(); break;
            case 3: verCarrito(); break;
            case 4: confirmarPedido(); break;
            case 5: printf("Saliendo...\n"); break;
            default: if (opcion != 0) printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}