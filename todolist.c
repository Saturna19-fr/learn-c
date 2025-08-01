#include <stdio.h>
#include <string.h>
#define MAX_TASKS 100
#define MAX_DESC_LENGTH 100

typedef struct
{
    char description[MAX_DESC_LENGTH];
} Task;

Task tasks[MAX_TASKS];
int task_nb = 0;

void CleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // vide le buffer jusqu'à la fin de ligne
}


//par chatgpt

void wait_for_enter() {
    int c;

    // Clear leftover input until newline or EOF
    CleanBuffer();

    // Wait for the actual Enter key
    printf("Press Enter to continue...");
    CleanBuffer();
}


/// @brief Returns an integer between 0 and 1 if the MAX_TASK is reached
/// @return int[0,1]
int IsMaxTaskReached()
{
    if (task_nb == MAX_TASKS)
    {
        return 1;
    }
    return 0;
}

int AnyTaskAlreadyRegistred()
{

    if (task_nb > 0)
    {
        return 1;
    }
    return 0;
}

void PrintAllTasks()
{
    int taskAlreadyExists = AnyTaskAlreadyRegistred();
    if (taskAlreadyExists == 1)
    {
        printf("exists !\n");
        for (int i = 0; i < task_nb; i++)
        {
            printf("%s\n", tasks[i].description);
        }
        wait_for_enter();
    }
    else
    {
        printf("No tasks existing\n");
        Task task1;
        strcpy(task1.description, "test");
        tasks[task_nb] = task1;
        task_nb++;
    }
};

void AddTask() {

    printf("Select a name for the task\n> ");
    char task_name[MAX_DESC_LENGTH];
    fgets(task_name, sizeof(task_name), stdin);
    // On crée une task.
    Task new_task;
    strcpy(new_task.description, task_name);
    tasks[task_nb] = new_task;
    task_nb++;

};

void DisplayMenu(){
    printf("1 - Add a task\n");
    printf("2 - Delete a task\n");
    printf("3 - Display tasks\n");
    printf("4 - Leave\n\n");

    printf("Choose an option:\n> ");

}

int main()
{
    int running = 1;
    printf("Welcome in the todolist system :)\n");
    while (running){
        DisplayMenu(); // Shows the menu (1 to 4)
        char buff[5];
        fgets(buff, sizeof(buff), stdin);
        int choice = atoi(buff);
        if (choice == 1)
        {
            AddTask();
            printf("Not implemented yet.\n");
        }
        else if (choice == 2)
        {
            printf("Not implemented yet\n");
        }
        else if (choice == 3)
        {
            PrintAllTasks();
            main();
        }
        /*else
        {
            running = 0;
            printf("Au revoir.\n");
        }*/
    }




    return 0;
}