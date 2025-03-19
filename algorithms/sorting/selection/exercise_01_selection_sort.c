#include <stdio.h>

struct Card {   
    char suit[20];
    int rank;
} typedef Card;

void selectionSort(Card cards[], int array_size){
    
    int i, j, min;
    Card temp;

    for(i = 0; i < array_size -1; i++){
        min = i;
        for(j = i + 1; j < array_size; j++){
            if(cards[j].rank < cards[min].rank){
                min = j;
            }
        }

        if(min != i){
            temp = cards[i];
            cards[i] = cards[min];
            cards[min] = temp;
        }

    }


}

void printCards(Card cards[], int array_size){
    for (int i = 0; i < array_size; i++) {
        printf("Suit: %s, Rank: %d\n", cards[i].suit, cards[i].rank);
    }
}

int main (){

    Card cards[] = {{"Hearts", 7}, {"Jack of Dimonds", 4}, {"Spades", 2}, {"Hearts", 3}};
    int array_size = sizeof(cards)/sizeof(cards[0]);

    selectionSort(cards, array_size);

    printCards(cards, array_size);



    return 0;
}