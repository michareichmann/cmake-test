//
// Created by micha on 27.09.16.
//

#include "iostream"
#include "ToDoCore/ToDo.h"
#include "stdint.h"

using namespace std;
using ToDoCore::ToDo;

#define EXPECT_EQUAL(test, expect) equalityTest(test, expect, #test, #expect, __FILE__, __LINE__)

template <typename T1, typename T2>
int equalityTest(const T1, const T2, const string, const string, const string, const int);


int main(int, char**) {

  int result = 0;

  ToDo list;

  list.addTask("write code");
  list.addTask("compile");
  list.addTask("test");

  result |= EXPECT_EQUAL(list.size(), uint16_t(3));
  result |= EXPECT_EQUAL(list.getTask(0), "write code");
  result |= EXPECT_EQUAL(list.getTask(1), "compile");
  result |= EXPECT_EQUAL(list.getTask(2), "test");

  if (result == 0){
    cout << "Test Passed!" << endl;
  }

  return result;
}

template <typename T1, typename T2>
int equalityTest(const T1 testValue, const T2 expectedValue, const string testName, const string expectedName, const string fileName, const int lineNumber){

  if (testValue != expectedValue){
    cerr << fileName << ":" << lineNumber << ": " << "Expected" << testName << " "
             << "to equal " << expectedName << " (" << expectedValue << ") "
             << "but it was (" << testValue << ")" << endl;
    return 1;
  }
  else
    return 0;
}
