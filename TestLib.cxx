#include "TestLib.h"

#include <iostream>

namespace TestLib
{

//*****************************************************************************

Foo::Foo()
{
  std::clog << "Foo::ctor" << std::endl;
}

Foo::~Foo()
{
  std::clog << "Foo::dtor" << std::endl;
}

int Foo::DoSomething1()
{
  std::clog << "Foo::DoSomething1" << std::endl;
  return 1;
}

void Foo::DoSomething2(double &arg)
{
  std::clog << "Foo::DoSomething2" << std::endl;
  arg = 42.0;
}

Bar& Foo::CreateBar(const std::string& name)
{
  std::clog << "Foo::CreateBar" << std::endl;
  
  auto iter = this->AllBars.find(name);
  if(iter != this->AllBars.end())
  {
    throw std::runtime_error("Bar named " + name + " already exists");
  }
  return *(this->AllBars[name] = std::make_unique<Bar>(name));
}

Bar& Foo::GetBar(const std::string& name)
{
  std::clog << "Foo::GetBar" << std::endl;
  return *this->AllBars.at(name);
}

//*****************************************************************************

Bar::Bar(const std::string &name)
: Name(name)
{
  std::clog << "Bar[" << this->Name << "]::ctor" << std::endl;
}

Bar::~Bar()
{
  std::clog << "Bar[" << this->Name << "]::dtor" << std::endl;
}

void Bar::DoSomethingElse1()
{
  std::clog << "Bar[" << this->Name << "]::DoSomethingElse1" << std::endl;
}

double Bar::DoSomethingElse2(const std::string &arg)
{
  std::clog << "Bar[" << this->Name << "]::DoSomethingElse2["
            << arg << "]" << std::endl;
  return 42.0;
}

//*****************************************************************************

} // end namespace TestLib
