#include <stdio.h>

extern int question_1_main();
extern int question_2_main();
extern int question_3_main();

int main() {
    int choice;
    printf("Enter the number of the task you want to execute:\n");
    printf("1. Task 1\n");
    printf("2. Task 2\n");
    printf("3. Task 3\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            question_1_main();
            break;
        case 2:
            question_2_main();
            break;
        case 3:
            question_3_main();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}