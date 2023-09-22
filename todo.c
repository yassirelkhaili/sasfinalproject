#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char *title;
    char *description;
    int  deadline[3];
    int status;
} Task;

int ft_strcmp(char *s1, char *s2)
{
    char ch1 = 0; 
    char ch2 = 0;
    
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }  
    if ((*s1 >= 97 && *s1 <= 122) || (*s2 >= 97 && *s2 <= 122))
    {
        if (*s1 >= 97 && *s1 <= 122)
            ch1 = *s1 - 32; 
        if (*s2 >= 97 && *s2 <= 122)
            ch2 = *s2 - 32;  
    }
    return (ch1 - ch2);
}


int ft_strlen(char *str)
{
    int strlen = 0;
    while (*str)
    {
        strlen++;
        str++;
    }
    return strlen;
}

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
    printf("[7] Add multiple tasks\n");
    printf("[8] Quit\n");
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

void get_modify_menu(int *modify_choice)
{
    int choice;
    printf("\nChoose an item to modify:\n");
    printf("[1] Description\n");
    printf("[2] Deadline\n");
    printf("[3] Status\n");
    printf("[4] Back\n");
    printf("\nEnter your choice [1-4]:\n");
    scanf("%d", &choice);
    *modify_choice = choice;
}

void get_search_menu(int *search_choice)
{
    int choice;
    printf("\nChoose an search method:\n");
    printf("[1] By id\n");
    printf("[2] By title\n");
    printf("[3] Back\n");
    printf("\nEnter your choice [1-3]:\n");
    scanf("%d", &choice);
    *search_choice = choice;
}

void get_statistics_menu(int *statistics_choice)
{
    int choice;
    printf("\nChoose a statistic to display:\n");
    printf("[1] Total number of tasks\n");
    printf("[2] Number of complete and incomplete tasks\n");
    printf("[3] Days left until Deadline\n");
    printf("[4] Back\n");
    printf("\nEnter your choice [1-4]:\n");
    scanf("%d", &choice);
    *statistics_choice = choice;
}

int main ()
{
    int user_choice;
    int display_choice;
    int modify_choice;
    int search_choice;
    int statistics_choice;
    int num_times = 0;
    int index = 0;
    Task tasks[100]; //static size
    // printf("\033[0;34m"); sets text color to blue (optional)
    get_user_choice(&user_choice);
    do {
        char title[50];
        char description[300];
        int status = 1;
        int day = 0;
        int month = 0;
        int year = 0;
        int id = 0;
        time_t currentdate = time(NULL); //get current time
        struct tm *timestruct = localtime(&currentdate); //transform current time to struct
        switch (user_choice)
        {
            case 1:
            printf("Enter the title:\n");
            getchar();
            fgets(title, sizeof(title), stdin);
            title[ft_strlen(title) - 1] = '\0';
            printf("Enter the description:\n");
            fgets(description, sizeof(description), stdin);
            description[ft_strlen(description) - 1] = '\0';
            printf("Enter the deadline:\n");
            printf("Day:\n");
            scanf("%d", &day);
            printf("Month:\n");
            scanf("%d", &month);
            printf("Year:\n");
            scanf("%d", &year);
            tasks[index].id = index + 1;
            tasks[index].title = strdup(title);
            tasks[index].description = strdup(description);
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
                //sort tasks alphabetically using bubblesort
                for (unsigned int i = 0; i < index; i++)
                {
                    for (unsigned int j = 0; j < index - i - 1; j++)
                    {
                        if (ft_strcmp(tasks[j].title, tasks[j + 1].title) > 0)
                        {
                            Task temp = tasks[j];
                            tasks[j] = tasks[j + 1];
                            tasks[j + 1] = temp;
                        }
                    }
                }
                //display tasks
                for (unsigned int i = 0; i < index; i++)
                {
                    printf("\n****** Task %d ******\n", tasks[i].id);
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
                case 2:
                 if(index == 0)
                {
                    printf("No tasks have been added\n");
                }
                else
                {
                for (unsigned int i = 0; i < index; i++)
                {
                    for (unsigned int j = 0; j < index - i - 1; j++)
                    {
                        // Compare deadlines
                        if (tasks[j].deadline[2] < tasks[j + 1].deadline[2] ||
                            (tasks[j].deadline[2] == tasks[j + 1].deadline[2] &&
                            tasks[j].deadline[1] < tasks[j + 1].deadline[1]) ||
                            (tasks[j].deadline[2] == tasks[j + 1].deadline[2] &&
                            tasks[j].deadline[1] == tasks[j + 1].deadline[1] &&
                         tasks[j].deadline[0] < tasks[j + 1].deadline[0]))
                    {
                        Task temp = tasks[j + 1];
                        tasks[j + 1] = tasks[j];
                        tasks[j] = temp;
                    }
                }
            }
                for (unsigned int i = 0; i < index; i++)
                {
                    printf("\n****** Task %d ******:\n", tasks[i].id);
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
                case 3:
                if(index == 0)
                {
                    printf("No tasks have been added\n");
                }
                else
                {
                //display tasks with deadline less than or equal to 3 days (urgent)
                int daysleft = 0;
                int currentyear = timestruct->tm_year + 1900; //add epoch time to get currentyear
                for (unsigned int i = 0; i < index; i++)
                {
                    if (tasks[i].deadline[2] >= currentyear)
                    {
                        daysleft = (tasks[i].deadline[2] - currentyear) * 365;
                        daysleft += (tasks[i].deadline[1] - timestruct->tm_mon - 1) * 30;
                        daysleft += (tasks[i].deadline[0] - timestruct->tm_mday);
                        if (daysleft >= 0 && daysleft <= 3)
                        {
                    printf("\n****** Task %d ******\n", tasks[i].id);
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
                }
                }
                break;
                default:
                printf("Invalid choice\n");
                break;
            }
            get_user_choice(&user_choice);
            break;
case 3:
 if (index == 0)
 {
    printf("Enter the task number:\n");
 }
 else
 {
     printf("Enter the task number:\n");
    scanf("%d", &id);
    int i = 0;
    int found = 0;

    while (i < index)
    {
        if (tasks[i].id == id)
        {
            found = 1;
            printf("\n****** Task %d ******\n", tasks[i].id);
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
            get_modify_menu(&modify_choice);
            switch (modify_choice)
            {
                case 1:
                    printf("Enter the description:\n");
                    getchar();
                    fgets(description, sizeof(description), stdin);
                    description[ft_strlen(description) - 1] = '\0';
                    free(tasks[i].description); 
                    tasks[i].description = strdup(description);
                    break;
                case 2:
                    printf("Enter the deadline:\n");
                    printf("Day:\n");
                    scanf("%d", &day);
                    printf("Month:\n");
                    scanf("%d", &month);
                    printf("Year:\n");
                    scanf("%d", &year);
                    tasks[i].deadline[0] = day;
                    tasks[i].deadline[1] = month;
                    tasks[i].deadline[2] = year;
                    break;
                case 3:
                    printf("Enter the status (1 for Todo, 2 for Doing, 3 for Done):\n");
                    scanf("%d", &status);
                    while (!(status >= 1 && status <= 3))
                    {
                    printf("Invalid status\n");
                    printf("Enter the status (1 for Todo, 2 for Doing, 3 for Done):\n");
                    scanf("%d", &status);
                    }
                    tasks[i].status = status;
                    break;
                default:
                    printf("Invalid Choice\n");
                    break;
            }
            break; 
        }
        i++;
    }
    if (!found)
    {
        printf("Task not found\n");
    }
 }
    get_user_choice(&user_choice);
    break;
    case 4:
    if (index == 0)
    {
        printf("No tasks have been added\n");
    }
    else 
    {
    printf("Enter the task number:\n");
    scanf("%d", &id);
    int u = 0;
    int f = 0;
    while (u < index)
    {
        if (tasks[u].id == id)
        {
            if (index == 1)
            {
                index--;
                break;
            }
            f = 1;
            tasks[u] = tasks[index - 1];
            index--;
            break; 
        }
        u++;
    }
    if (!f)
    {
        printf("Task not found\n");
    }
    }
    get_user_choice(&user_choice);
    break;
    case 5:
    get_search_menu(&search_choice);
    switch (search_choice)
    {
    case 1:
         if (index == 0)
    {
        printf("No tasks have been added\n");
    }
    else 
    {
    printf("Enter the task number:\n");
    scanf("%d", &id);
    int u = 0;
    int f = 0;
    while (u < index)
    {
        if (tasks[u].id == id)
        {
            f = 1;
            printf("\n****** Task %d ******\n", tasks[u].id);
            printf("Title: %s\n", tasks[u].title);
            printf("Description: %s\n", tasks[u].description);
            printf("Deadline: %02d-%02d-%04d\n", tasks[u].deadline[0], tasks[u].deadline[1], tasks[u].deadline[2]);
            switch (tasks[u].status)
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
            break; 
        }
        u++;
    }
    if (!f)
    {
        printf("Task not found\n");
    }
    }
    break;
    case 2:
      if (index == 0)
    {
        printf("No tasks have been added\n");
    }
    else 
    {
    char search_title[100];
    printf("Enter the task title:\n");
    getchar();
    fgets(search_title, sizeof(search_title), stdin);
    search_title[ft_strlen(search_title) - 1] = '\0';
    int u = 0;
    int f = 0;
    while (u < index)
    {
        if (strcmp(tasks[u].title, search_title) == 0)
        {
            f = 1;
            printf("\n****** Task %d ******\n", tasks[u].id);
            printf("Title: %s\n", tasks[u].title);
            printf("Description: %s\n", tasks[u].description);
            printf("Deadline: %02d-%02d-%04d\n", tasks[u].deadline[0], tasks[u].deadline[1], tasks[u].deadline[2]);
            switch (tasks[u].status)
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
            break; 
        }
        u++;
    }
    if (!f)
    {
        printf("Task not found\n");
    }
    }
    break;
    case 3:
    break;
        break;
        default:
        printf("Invalid choice\n");
        break;
    }
    get_user_choice(&user_choice);
    break;
    case 6:
    get_statistics_menu(&statistics_choice);
    int n = 0;
    int completed = 0;
    int incomplete = 0;
    switch (statistics_choice)
    {
        case 1:
        printf("Total number of tasks: %d\n", index);
        break;
        case 2:
        while (n < index)
        {
            if (tasks[n].status == 3)
                completed++;
            n++;
        }
        incomplete = index - completed;
        printf("Completed tasks: %d\nIncomplete tasks: %d\n", completed, incomplete);
        break;
        case 3:
        if(index == 0)
                {
                    printf("No tasks have been added\n");
                }
                else
                {
                //display tasks with deadline less than or equal to 3 days (urgent)
                int daysleft = 0;
                int currentyear = timestruct->tm_year + 1900; //add epoch time to get currentyear
                for (unsigned int i = 0; i < index; i++)
                {
                    if (tasks[i].deadline[2] >= currentyear)
                    {
                        daysleft = (tasks[i].deadline[2] - currentyear) * 365;
                        daysleft += (tasks[i].deadline[1] - timestruct->tm_mon - 1) * 30;
                        daysleft += (tasks[i].deadline[0] - timestruct->tm_mday);
                    printf("\nTask %d: %d days \n", tasks[i].id, daysleft);
                    }
                }
                }
        break;
        case 4:
        break;
        default:
        printf("Invalid choice\n");
        break;
    }
    get_user_choice(&user_choice);
    break;
    case 7:
        printf("Number of tasks:\n");
        scanf("%d", &num_times);
        if (num_times <= 0)
        {
            printf("Invalid input\n");
        }
        else
        {
            for (size_t i = 0; i < num_times; i++)
        {
            printf("\nEnter the title:\n");
            getchar();
            fgets(title, sizeof(title), stdin);
            title[ft_strlen(title) - 1] = '\0';
            printf("Enter the description:\n");
            fgets(description, sizeof(description), stdin);
            description[ft_strlen(description) - 1] = '\0';
            printf("Enter the deadline:\n");
            printf("Day:\n");
            scanf("%d", &day);
            printf("Month:\n");
            scanf("%d", &month);
            printf("Year:\n");
            scanf("%d", &year);
            tasks[index].id = index + 1;
            tasks[index].title = strdup(title);
            tasks[index].description = strdup(description);
            tasks[index].status = status;
            tasks[index].deadline[0] = day;
            tasks[index].deadline[1] = month;
            tasks[index].deadline[2] = year;
            index++;
            printf("Task has been added successfully.");
        }
        }
        get_user_choice(&user_choice);
    break;
            case 8:
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
    } while(user_choice != 8);
    printf("----End of Program----");
    return 0;
}