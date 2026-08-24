#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(){
    Carrito c; 
    carrito_init(&c);
    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};
    carrito_agregar(&c,pan);
    carrito_agregar(&c,leche);
    ASSERT_IGUAL(1300,carrito_total(&c));
    printf("\nTotal de la compra %d \n",carrito_total(&c));
    ASSERT_IGUAL(1170,carrito_descuento(carrito_total(&c),10));
    printf("\nTotal de la compra con descuento %d \n",carrito_descuento(carrito_total(&c),10));
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(){
    printf("\n Agregar hasta llenar \n");
    Carrito c;
    carrito_init(&c);
    Producto p ={"Producto",200,1};
    for(int i=0;i<MAX_ITEMS;i++){
        ASSERT_IGUAL(1,carrito_agregar(&c,p));
    }
    ASSERT_IGUAL(MAX_ITEMS,carrito_contar(&c));
    ASSERT_IGUAL(0,carrito_agregar(&c,p));
    ASSERT_IGUAL(MAX_ITEMS,carrito_contar(&c));
}
 

int main(void) {
    printf("=== Tests de integracion ===");
    test_compra_con_descuento();  
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}
