#include <string>
#include <utility>

#include "gtest/gtest.h"

// Class with support of structured binding
class Person {
 public:
  Person(std::string name, std::string surname, int age)
      : name_{std::move(name)}, surname_{std::move(surname)}, age_{age} {}

  const std::string& getName() const { return name_; }
  const std::string& getSurname() const { return surname_; }
  int getAge() const { return age_; }

  std::string& getName() { return name_; }
  std::string& getSurname() { return surname_; }
  int& getAge() { return age_; }

 private:
  std::string name_;
  std::string surname_;
  int age_;
};

// Number of elements for binding
template <>
struct std::tuple_size<Person> {
  static constexpr int value = 3;
};

// Type of the element with index 2
template <>
struct std::tuple_element<2, Person> {
  using type = int;
};

// Type of other elements
template <std::size_t Index>
struct std::tuple_element<Index, Person> {
  using type = std::string;
};

// Getters for corresponding elements
template <std::size_t Index, typename PersonT>
decltype(auto) get(PersonT&& person) {
  static_assert(Index < std::tuple_size<Person>::value);
  static_assert(
      std::is_same<Person, typename std::decay<decltype(person)>::type>::value);

  if constexpr (Index == 0)
    return person.getName();
  else if constexpr (Index == 1)
    return person.getSurname();
  else
    return person.getAge();
}

TEST(structured_bindings, enable_in_class_ref) {
  Person person{"Chuck", "Norris", 81};
  auto& [name, surname, age] = person;
  name = "Lando";
  age = 22;
  ASSERT_EQ(person.getAge(), 22);
  ASSERT_EQ(person.getName(), "Lando");
}

TEST(structured_bindings, enable_in_class_value) {
  Person person{"Chuck", "Norris", 81};
  auto [name, surname, age] = person;
  name = "Lando";
  age = 22;
  ASSERT_EQ(person.getAge(), 81);
  ASSERT_EQ(person.getName(), "Chuck");
}