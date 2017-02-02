#include "TestLib.h"

int main(int argc, char **argv)
{
  TestLib::Foo foo;

  double arg;
  foo.DoSomething1();
  foo.DoSomething2(arg);

  TestLib::Bar &bar1 = foo.CreateBar("b1");
  bar1.DoSomethingElse1();
  double b1Result = bar1.DoSomethingElse2("Things");

  TestLib::Bar &bar2 = foo.CreateBar("b2");
  bar2.DoSomethingElse1();
  double b2Result = bar2.DoSomethingElse2("Stuff");
}

