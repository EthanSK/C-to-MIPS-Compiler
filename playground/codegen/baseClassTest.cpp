#include <iostream>
#include <vector>

class A
{
public:
  int aa;

  virtual void func() = 0; //must define here
};

class B : public A
{
public:
  // B();
  int bb;
  void func() override {std::cout << "B func imple\n";};
};

class Z
{
public:
  static std::vector<A*> lol()
  {
    B beeb;
    beeb.bb = 5;
    beeb.aa = 2349;
    std::vector<A*> troll;
    troll.push_back(&beeb);
    return troll;
  }
};

int main()
{
  auto poo = Z::lol();
  for(size_t i = 0; i < poo.size(); i++)
  {
    poo[i]->func(); 
  }
  
}