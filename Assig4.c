#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

struct ToDoListManager{
    char tasks[MAX_TASKS][100];
    int numTasks;
};
void addTask(struct ToDoListManager *manager, const char *task) {
    if (manager->numTasks < MAX_TASKS) {
        strcpy(manager->tasks[manager->numTasks], task);
        manager->numTasks++;
        printf("Task added: %s\n", task);
    } else {
        printf("Task list is full.\n");
    }
}
void viewTask(struct ToDoListManager* manager){
    if(manager->numTasks==0){
        printf("No Task Found.\n");
    }else{
        printf("Task:\n");
        for(int i=0;i<manager->numTasks;i++){
            printf("%d . %s\n",i+1,manager->tasks);
        }
    }

}
void deleteTask(struct ToDoListManager* manager,int taskId){
    if(taskId>=1 && taskId<=manager->numTasks){
        printf("Task Deleted: %s\n",manager->tasks[taskId-1]);
        for(int i=taskId-1;i<manager->numTasks-1;i++){
            strcpy(manager->tasks[i],manager->tasks[i+1]);
        }
        manager->numTasks--;
    }else{
        printf("Invalid task Index\n");
    }
}

int main(){
    struct ToDoListManager todoManager;
    todoManager.numTasks=0;

    int choice;
    char task[100];
    int taskId;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add task\n");
        printf("2. View tasks\n");
        printf("3. Delete task\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task: ");
                scanf(" %[^\n]", task);
                addTask(&todoManager, task);
                break;
            case 2:
                viewTask(&todoManager);
                break;
            case 3:
                viewTask(&todoManager);
                printf("Enter the task index to delete: ");
                scanf("%d", &taskId);
                deleteTask(&todoManager, taskId);
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
