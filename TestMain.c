#include "TestLib_C.h"

int main()
{
  TestLibFoo* foo = TestLibCreateFoo();

  double arg;
  TestLibFooDoSomething1(foo);
  TestLibFooDoSomething2(foo, &arg);

  TestLibBar *bar1 = TestLibFooCreateBar(foo, "b1");
  TestLibBarDoSomethingElse1(bar1);
  double b1Result;
  TestLibBarDoSomethingElse2(bar1, "Things", &b1Result);

  TestLibBar *bar2 = TestLibFooCreateBar(foo, "b2");
  TestLibBarDoSomethingElse1(bar2);
  double b2Result;
  TestLibBarDoSomethingElse2(bar2, "Stuff", &b2Result);

  TestLibDestroyFoo(foo);
}

