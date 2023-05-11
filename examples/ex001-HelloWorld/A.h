#include <string>
#include <iostream>

/** Class A that says hello.
 */
namespace NS {
class A {
public:
  A(const char* person = "World"): person_(person){}
  void say_hello() const{
    std::cout << "Hello " << person_ << "!\n";
  }
private:
  std::string person_;
};

/** Class B that says hello.
 */
class B {
public:
  B(const char* person = "World"): person_(person){}
  void say_hello() const{
    std::cout << "Hello " << person_ << "!\n";
  }
private:
  std::string person_;
};

/** Class C that says hello.
 */
class C {
public:
  C(const char* person = "World"): person_(person){}
  void say_hello() const{
    std::cout << "Hello " << person_ << "!\n";
  }
private:
  std::string person_;
};
}



