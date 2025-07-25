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

//par chatgpt
void wait_for_enter() {
    int c;

    // Clear leftover input until newline or EOF
    while ((c = getchar()) != '\n' && c != EOF);

    // Wait for the actual Enter key
    printf("Press Enter to continue...");
    while ((c = getchar()) != '\n' && c != EOF);
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
        printf("Des taches existent !\n");
        for (int i = 0; i < task_nb; i++)
        {
            printf("%s\n", tasks[i].description);
        }
        wait_for_enter();
    }
    else
    {
        printf("Aucune tache n'existe\n");
        Task task1;
        strcpy(task1.description, "test");
        tasks[task_nb] = task1;
        task_nb++;
    }
};

void DisplayMenu(){
    printf("1 - Ajouter une tâche\n");
    printf("2 - Supprimer une tâche\n");
    printf("3 - Afficher les tâches\n");
    printf("4 - Quitter\n\n");

    printf("Choisissez une option:\n> ");

}

int main()
{
    int running = 1;
    printf("Bienvenue sur le système de planning :)\n");
    while (running){
        DisplayMenu();
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
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
        else
        {
            running = 0;
            printf("Au revoir.\n");
        }
    }




    return 0;
}