#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

#define hash(key) key % SIZE
#define probe(key, i) (hash(key) + i) % SIZE

typedef struct entry{
    int key;
    char value[20];
}entry_t;


entry_t table[SIZE];

void add_entry(int key, char *value){

    int slot = hash(key);
    int i= 1;

    while(i<SIZE && table[slot].key != 0){
      
        if(key == table[slot].key)
        {
        strcpy(table[slot].value, value);
        return;
        }
        slot = probe(key, i++);
    }
    table[slot].key = key;
    strcpy(table[slot].value,value);
}

char *search_entry(int key){
    int slot = hash(key);
    int i = 1;

    while(i < SIZE && table[slot].key != 0){
        if(key == table[slot].key){
            return table[slot].value;
        }
        slot = probe(key, i++);
    }
    return NULL;
}
int search_mode(int key) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (table[i].key == key) {
            count++;
        }
    }
    return count; 
}
int mode(void) {
    int mode = 0;

    for (int i = 0; i < SIZE; i++) {
        if (table[i].value == NULL) continue; 

        int count = 0;

        for (int j = 0; j < SIZE; j++) {
            if (table[j].value == NULL) continue;

            if (strcmp(table[i].value, table[j].value) == 0) {
                count++;
            }
        }

        if (count > mode)
            mode = count;
    }

    return mode;
}

void display_table(void)
{
    printf("Hash Table: \n");
    for(int slot= 0; slot < SIZE; slot++){
        printf("[%d] %d-%s\n",slot, table[slot].key, table[slot].value);
    }
}

int main(void){
    add_entry(8, "v1");
    add_entry(3, "v2");
    add_entry(10, "v3");
    add_entry(4, "v4");
    add_entry(6, "v5");
    add_entry(13, "v8");
    add_entry(23, "v8");
    add_entry(26, "v8");
  

    display_table();

    char *value = search_entry(23);
    if(value != NULL)
        printf("Key is found value : %s\n", value);
    else
        printf("Key is not found\n");
    
    printf("Mode:%d\n",mode());

    return 0;
}