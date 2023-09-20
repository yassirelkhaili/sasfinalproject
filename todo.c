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
    printf("[4] Delete task\n");
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
    Task tasks[100];
    get_user_choice(&user_choice);
    do {
        char title[50];
        char description[50];
        char status[20];
        int day = 0;
        int month = 0;
        int year = 0;
        int index = 0;
        switch (user_choice)
        {
            case 1:
            printf("Enter the title:\n");
            scanf("%s", title);
            printf("Enter the description:\n");
            getchar();
            scanf("%s", description);
            printf("Enter the deadline:\n");
            printf("Day:");
            scanf("%d", &day);
            printf("Month:");
            scanf("%d", &month);
            printf("Year:");
            scanf("%d", &year);
            strcpy(status, "Todo");
            tasks[index].title = title;
            tasks[index].description = description;
            tasks[index].status = status;
            tasks[index].deadline[0] = day;
            tasks[index].deadline[1] = month;
            tasks[index].deadline[2] = year;
            index++;
            printf("Task has been added successfully.");
            get_user_choice(&user_choice);
            break;
            case 2:
            
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
    } while(user_choice != 7);
    printf("----End of Program----");
    return 0;
}