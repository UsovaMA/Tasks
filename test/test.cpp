#include <gtest/gtest.h>
#include "tasks.h"

TEST(Reverse, can_reverse) {
  int a = 123;
  EXPECT_EQ(321, reverse(a));
}

TEST(Reverse, can_reverse_negative) {
  int a = -456;
  EXPECT_EQ(-654, reverse(a));
}

TEST(Reverse, can_reverse_one_digit) {
  int a = 2;
  EXPECT_EQ(2, reverse(a));
}

TEST(Reverse, can_reverse_0) {
  int a = 0;
  EXPECT_EQ(0, reverse(a));
}

TEST(Prefix, can_find_prefix) {
  char *strs[3] = { "abcd", "ab6c", "acbd" };
  char a[2] = "a";
  char *ans = prefix(strs, 3);

  for (int i = 0; a[i] != 0; i++)
    EXPECT_EQ(a[i], ans[i]);
}

TEST(Prefix, can_find_prefix_in_same_strings) {
  char *strs[3] = { "abcd", "abcd", "abcd" };
  char a[5] = "abcd";
  char *ans = prefix(strs, 3);

  for (int i = 0; a[i] != 0; i++)
    EXPECT_EQ(a[i], ans[i]);
}

TEST(Prefix, can_find_empty_prefix) {
  char *strs[] = { "abcd", "abcd", "bacd" };
  char *ans = prefix(strs, 3);

  EXPECT_EQ(0, *ans);
}


TEST(PeversePair, can_reverse_pair) {
  CNode List[] = { 1, 2, 3, 4 };
  CNode newList[] = { 2, 1, 4, 3 };
  for (int i = 0; i < 3; i++) {
    List[i].next = &List[i + 1];
    newList[i].next = &newList[i + 1];
  }
  reverse_pair(List);

  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(List[i].data, newList[i].data);
  }
}

TEST(PeversePair, throw_when_empty_list) {
  CNode *list = 0;

  ASSERT_ANY_THROW(reverse_pair(list));
}

TEST(PeversePair, can_reverse_one_element_at_list) {
  CNode *List = new CNode(1);

  reverse_pair(List);

  EXPECT_EQ(1, List->data);
}

TEST(PeversePair, can_reverse_when__odd_number_of_elements_at_list) {
  CNode List[] = { 1, 2, 3, 4, 5 };
  CNode newList[] = { 2, 1, 4, 3, 5 };
  for (int i = 0; i < 4; i++) {
    List[i].next = &List[i + 1];
    newList[i].next = &newList[i + 1];
  }
  reverse_pair(List);

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(List[i].data, newList[i].data);
  }
}

TEST(SearchOfPairs, can_find_one_pair) {
  const int sum = 3, size = 6;
  int a[size] = { 1, 6, 0, 3, -5, 1 };
  int flag = 0;
  Pairs* res = search_pair(a, sum, size);
  Pairs* exp = new Pairs[1];
  exp[0].a = 0;
  exp[0].b = 3;
  if ((exp[0].a == (*res).a) && (exp[0].b = (*res).b))
    flag = 1;
  EXPECT_EQ(1, flag);
}

TEST(SearchOfPairs, can_find_several_pairs) {
  const int sum = 3, size = 6;
  int a[size] = { 1, 6, 0, 3, -5, 2 };
  int flag = 0;
  Pairs* res = search_pair(a, sum, size);
  Pairs* exp = new Pairs[2];
  exp[0].a = 1;
  exp[0].b = 2;
  exp[1].a = 0;
  exp[1].b = 3;
  if ((exp[0].a == res[0].a) && (exp[0].b = res[0].b) &&
    (exp[1].a == res[1].a) && (exp[1].b = res[1].b))
    flag = 1;
  EXPECT_EQ(1, flag);
}

TEST(SearchOfPairs, ThrowsWhenPairDoesntExist) {
  int a[] = { 1, 6, 0, 7, -5, 9 };
  int sum = 3;

  ASSERT_ANY_THROW(search_pair(a, sum, 6));
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
