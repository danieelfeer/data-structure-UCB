#include <stdio.h>

struct Product {
    char name[10];
    int quantity;
    float price;
    char brand[10];

} typedef Product;

void scanProduct(int quantityOfProducts, Product *products){
    printf("Add products:\n");

    for (int i = 0; i < quantityOfProducts; i++){
        printf("Product number %d\n", i+1);

        printf("Name: ");
        scanf("%s", &products[i].name);

        printf("quantity: ");
        scanf("%d", &products[i].quantity);

        printf("Price: ");
        scanf("%f", &products[i].price);

        printf("Brand: ");
        scanf("%s", &products[i].brand);

        printf("\n");
    }
}

void printListOfProducts(int quantityOfProducts, Product *products){
    printf("list:\n");
    for(int i = 0; i < 1; i++){

        printf("Product %d\n", i+1);
        printf("%s\n", products[i].name);
        printf("%d\n", products[i].quantity);
        printf("%.2f\n", products[i].price);
        printf("%s\n", products[i].brand);
        printf("\n");
    }
}

int main(){

    int quantityOfProducts = 4;

    Product products[quantityOfProducts];

    scanProduct(quantityOfProducts, &products);
    printListOfProducts(quantityOfProducts, &products);
   

    return 0;
}