/*
1D particle system 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int start_array[10] = {0,0,1,0,1,0,0,1,0,0};
    int next_array[10];

    srand(time(NULL));

    printf("Time 0 : ");
    for (int j = 0; j < 10; j++) {
        printf("%d ", start_array[j]);
    }
    printf("\n");

    for (int t = 1; t < 100; t++) {

        // next_array auf 0 setzen
        for (int i = 0; i < 10; i++) {
            next_array[i] = 0;
        }

        // Alle 1er bewegen
        for (int i = 0; i < 10; i++) {

            if (start_array[i] == 1) {

                int direction = rand() % 2; // 0 = links, 1 = rechts
                int new_pos = i;

                if (direction == 0 && i > 0) {
                    new_pos = i - 1;
                } else if (direction == 1 && i < 9) {
                    new_pos = i + 1;
                }

                // Pointer auf Zielposition
                int *p_new = &next_array[new_pos];

                // Kollision prüfen
                if (*p_new == 1) {
                    printf("Kollision bei Position %d in Time %d\n", new_pos, t)
                }

                // Wert setzen
                *p_new = 1;
            }
        }

        // next_array → start_array kopieren
        for (int i = 0; i < 10; i++) {
            start_array[i] = next_array[i];
        }

        // Ausgabe
        printf("Time %d : ", t);
        for (int j = 0; j < 10; j++) {
            printf("%d ", start_array[j]);
        }
        printf("\n");
    }

    return 0;
}