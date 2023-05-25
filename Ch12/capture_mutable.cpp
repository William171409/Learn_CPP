#include <iostream>

int main()
{
  int ammo{ 10 };

  auto shoot{
    // Added mutable after the parameter list.
    [ammo] ()mutable {
      // We're allowed to modify ammo now
      --ammo;

      std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }
  };

  shoot();
  shoot();

  std::cout << ammo << " shot(s) left\n";

  return 0;
}