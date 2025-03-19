    #include <stdio.h>
    #include <stdbool.h>

    struct Password {
        bool priority;
        int number;
    } typedef Password;

    int main(){

        Password passwords[4] = {{false, 105}, {true, 102}, {true, 104}, {false, 101}};
        int array_size = sizeof(passwords) / sizeof(passwords[0]);
        Password key;
        int i, j;

        for(i = 1; i < array_size; i++){
            key = passwords[i];
            j = i -1;

            while (j >= 0 && (passwords[j].priority < key.priority || 
                          (passwords[j].priority == key.priority && passwords[j].number > key.number))) {
            passwords[j + 1] = passwords[j];
            j--;
        }
            passwords[j+1] = key;

        }

        for(int i = 0; i < array_size; i++){
            printf("%d - %d\n", passwords[i].priority, passwords[i].number);
        }
        


        return 0;
    }