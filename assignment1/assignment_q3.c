#include <stdio.h>
#include <string.h>

#define SIZE 5


struct Employee {
    int empid;
    char name[50];
};


void searchByEmpid(struct Employee employees[], int empid) {
    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (employees[i].empid == empid) {
            printf("\nEmployee found:\n");
            printf("ID: %d\nName: %s\n", employees[i].empid, employees[i].name);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nEmployee with ID %d not found.\n", empid);
}


void searchByName(struct Employee employees[], char name[]) {
    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("\nEmployee found:\n");
            printf("ID: %d\nName: %s\n", employees[i].empid, employees[i].name);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nEmployee with name %s not found.\n", name);
}

int main() {
    // Static array of employees
    struct Employee employees[SIZE] = {
        {101, "abc"},
        {102, "san"},
        {103, "kat"},
        {104, "kus"},
        {105, "lau"}
    };

    int choice;

    while (1) {
        printf("\nEmployee Search Menu\n");
        printf("1. Search by Employee ID\n");
        printf("2. Search by Name\n");
        printf("3. Exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id;
            printf("enter Employee ID: ");
            scanf("%d", &id);
            searchByEmpid(employees, id);
        } else if (choice == 2) {
            char name[50];
            printf("enter Employee Name: ");
            scanf("%s", name);  
            searchByName(employees, name);
        } else if (choice == 3) {
            printf("exiting program.\n");
            break;
        } else {
            printf("invalid choice. Try again.\n");
        }
    }

    return 0;
}
