#ifndef __TASKS_H__
#define __TASKS_H__

struct CNode {
  int data;
  CNode* next;

  CNode(int a) {
    data = a;
    next = 0;
  }
};

struct Pairs {
  int a;
  int b;
};

int reverse(int number);
char* prefix(char** a, int size);
void reverse_pair(CNode* list);
Pairs* search_pair(int *a, int sum, int size);

#endif