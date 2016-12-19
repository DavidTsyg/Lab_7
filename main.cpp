#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Computer
{
    char Processor[64];
    char Clock_Signal[64];
    char Ram[64];
    char HDD_Volume[64];
    char Graphics_Card[64];
};

struct List
{
    struct List *next;
    struct Computer Computer;

};

void push(struct List **head, struct Computer p) {
    struct List *tmp = (List*)malloc(sizeof(List));
    tmp->Computer = p;
    tmp->next = (*head);
    *head = tmp;
}
void clear(List *head) {

    while (head != NULL) {
        List * t = head->next;
        free(head);
        head = t;
    }
}


int main() {
    FILE *pF;
    struct List *head = NULL;
    int n(0);
    pF = fopen("/home/david/ClionProjects/Lab7(1 part)/cmake-build-debug/MyProgram.txt", "rb");
    if (pF == 0)
    {
        printf("Error, file not found");
        return 1;
    }
    fread(&n, sizeof(int), 1, pF);
    for (unsigned int i = 0 ; i < n; ++i) {
        struct Computer *p = (Computer *)malloc(sizeof(Computer));
        fread(p, sizeof(Computer), 1, pF);
        push(&head, *p);

    }
    fclose(pF);
    for (List *pi = head; pi; pi = pi->next) {
        cout << pi->Computer.Processor << " ___ " << pi->Computer.Clock_Signal << " ___ " << pi->Computer.Ram << " ___ " << pi->Computer.HDD_Volume << " ___ " << pi->Computer.Graphics_Card << endl;
    }
    clear(head);


    return 0;
}