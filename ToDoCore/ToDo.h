//
// Created by micha on 27.09.16.
//

#ifndef CMAKE_TEST_TODO_H
#define CMAKE_TEST_TODO_H

#include <string>
#include <vector>

namespace ToDoCore {

class ToDo {
public:
  ToDo();

  ~ToDo();

  size_t size() const;

  void addTask(const std::string &task);

  std::string getTask(size_t index) const;

private:
  std::vector<std::string> this_tasks;
};

} // namespace ToDoCore

#endif //CMAKE_TEST_TODO_H
