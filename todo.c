#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    char *title;
    char *description;
    int  deadline[3];
    char *status;
} Task;

void get_user_choice(int *user_choice)
{
    int choice;
    printf("\n===========================================\n");
    printf("            Application Menu\n");
    printf("===========================================\n\n");
    printf("[1] Add task\n");
    printf("[2] Display tasks\n");
    printf("[3] Modify task\n");
    printf("[4] Delete data\n");
    printf("[5] Search task\n");
    printf("[6] Display statistics\n");
    printf("[7] Quit\n");
    printf("\nEnter your choice [1-7]:\n");
    scanf("%d", &choice);
    *user_choice = choice;
}

void sub_menu(int *sub_choice)
{
     int choice;
    printf("Choose an operation:\n");
    printf("1. Min\n");
    printf("2. Max\n");
    printf("3. Average\n");
    printf("4. Back\n");
    scanf("%d", &choice);
    *sub_choice = choice;
}


int main ()
{
    int user_choice;
    int sub_choice;
    get_user_choice(&user_choice);
    do {
        switch (user_choice)
        {
            case 1:

            get_user_choice(&user_choice);
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
    } while(user_choice != 7);
    printf("----End of Program----");
    return 0;
}