#ifndef TestLib_h_
#define TestLib_h_

#include <unordered_map>
#include <memory>
#include <string>

namespace TestLib
{

class Bar;

class Foo
{
public:
  Foo();
  ~Foo();

  int DoSomething1();
  void DoSomething2(double &arg);

  Bar& CreateBar(const std::string &name);
  Bar& GetBar(const std::string &name);
private:
  std::unordered_map<std::string, std::unique_ptr<Bar>> AllBars;
};


class Bar
{
public:
  Bar(const std::string &name);
  ~Bar();

  void DoSomethingElse1();
  double DoSomethingElse2(const std::string &arg);

private:
  std::string Name;
};

} // end namespace TestLib

#endif
