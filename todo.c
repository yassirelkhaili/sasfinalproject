#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int id;
    char *title;
    char *description;
    int  deadline[3];
    int status;
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

void get_display_menu(int *display_choice)
{
    int choice;
    printf("\nChoose a display method:\n");
    printf("[1] By alphabetical order\n");
    printf("[2] By deadline\n");
    printf("[3] By urgency\n");
    printf("[4] Back\n");
    printf("\nEnter your choice [1-4]:\n");
    scanf("%d", &choice);
    *display_choice = choice;
}


int main ()
{
    int user_choice;
    int display_choice;
    int index = 0;
    Task tasks[100];
    get_user_choice(&user_choice);
    do {
        char title[50];
        char description[300];
        int status = 1;
        int day = 0;
        int month = 0;
        int year = 0;
        switch (user_choice)
        {
            case 1:
            printf("Enter the title:\n");
            getchar();
            fgets(title, sizeof(title), stdin);
            title[strlen(title) - 1] = '\0';
            printf("Enter the description:\n");
            fgets(description, sizeof(description), stdin);
            description[strlen(description) - 1] = '\0';
            printf("Enter the deadline:\n");
            printf("Day:\n");
            scanf("%d", &day);
            printf("Month:\n");
            scanf("%d", &month);
            printf("Year:\n");
            scanf("%d", &year);
            tasks[index].id = index;
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
            get_display_menu(&display_choice);
            printf("%d\n", display_choice);
            switch (display_choice)
            {
                case 1:
                if(index == 0)
                {
                    printf("No tasks have been added\n");
                }
                else
                {
                for (size_t i = 0; i < index; i++)
                {
                    printf("\n****** Task %d ******:\n", (i + 1));
                    printf("Title: %s\n", tasks[i].title);
                    printf("Description: %s\n", tasks[i].description);
                    printf("Deadline: %02d-%02d-%04d\n", tasks[i].deadline[0], tasks[i].deadline[1], tasks[i].deadline[2]);
                    switch (tasks[i].status)
                    {
                        case 1:
                        printf("Status: Todo\n");
                        break;
                        case 2:
                        printf("Status: Doing\n");
                        break;
                        case 3:
                        printf("Status: Done\n");
                        break;
                        default:
                        printf("Status: Unknown\n");
                        break;
                    }
                }
                }
                break;
                default:
                printf("Invalid choice\n");
                break;
            }
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