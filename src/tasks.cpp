#include "tasks.h"
#include <stdexcept>

int reverse(int number) {
  int rev_num = 0;

  while (number != 0) {
    rev_num = rev_num * 10 + number % 10;
    number /= 10;
  }

  return rev_num;
}

char* prefix(char** a, int size) {
  int f = -2, flag = 0, k = 0;

  for (int i = 0; a[0][i] != 0; i++) {
    k = i;
    char c = a[0][i];
    for (int j = 0; j < size; j++)
      if (a[j][i] != c) {
        f = i - 1;
        flag = 1;
        break;
      }
    if (f != -2)
      break;
  }

  char* prefix = new char[k + 1];

  if (flag == 1) {
    for (int i = 0; i <= f; i++)
      prefix[i] = a[0][i];
    prefix[f + 1] = 0;
  } else {
    for (int i = 0; a[0][i] != 0; i++)
      prefix[i] = a[0][i];
  }

  return prefix;
}

void reverse_pair(CNode* list) {
  if (list != 0)
    while ((list != 0) && (list->next != 0)) {
      int c = list->data;
      list->data = list->next->data;
      list->next->data = c;
      list = list->next->next;
    }
  else
    throw std::logic_error("List is empty");
}

Pairs* search_pair(int* a, int sum, int size) {
  int count = 0;
  Pairs* list_of_pairs = NULL;
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 1; j < size; ++j)
      if ((a[j] != -100000) && (i != j) && ((a[i] + a[j] == sum))) {
        count++;
        list_of_pairs = (Pairs*)realloc(list_of_pairs, sizeof(Pairs)*count);
        list_of_pairs[count - 1].a = a[i];
        list_of_pairs[count - 1].b = a[j];
      }
    a[i] = -100000;
  }
  if (list_of_pairs == NULL) 
    throw std::logic_error("The original array doesn't have pairs");
  else
    return list_of_pairs;
}
