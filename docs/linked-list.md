# Linked-Lists

## Singly Linked-list
### Files
- Header file: [dtst.h](../src/dtst/dtst.h)
- Source file: [list.c](../src/dtst/list.c)

### Definitions

### Functions

### Macros

**Usage:**
```c
#include "src/dtst/dtst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task structure
typedef struct Task_ {
    char name[50];
    int priority;
} Task;

// Callback
void destroy_task(void *data) {
    free(data);
}

int main() {
    List task_list;
    list_init(&task_list, destroy_task);

    Task *task1 = malloc(sizeof(Task));
    strcpy(task1->name, "Task 1");
    task1->priority = 1;

    Task *task2 = malloc(sizeof(Task));
    strcpy(task2->name, "Task 2");
    task2->priority = 2;

    if (list_ins_next(&task_list, NULL, task1) != 0) {
        fprintf(stderr, "Error inserting task1\n");
        return 1;
    }

    if (list_ins_next(&task_list, list_head(&task_list), task2) != 0) {
        fprintf(stderr, "Error inserting task2\n");
        return 1;
    }

    ListElem *elem = list_head(&task_list);
    while (elem != NULL) {
        Task *task = (Task *)list_data(elem);
        printf("Task Name: %s, Priority: %d\n", task->name, task->priority);
        elem = list_next(elem);
    }
    list_destroy(&task_list);

    return 0;
}
```

**Output:**
```plaintext
Task Name: Task 1, Priority: 1
Task Name: Task 2, Priority: 2
```

## Doubly Linked-List

## Circular Linked-List
