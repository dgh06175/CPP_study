#include<iostream>
using namespace std;
#include "cat.h"
#include "dog.h"
#include "duck.h"
#include "goldFish.h"

int main()  // class Adapter pattern 
{
	Cat cat("æﬂøÀ¿Ã", Pet::MAMMAL, 2);
	Dog dog("∏€∏€¿Ã", Pet::MAMMAL, 5);
	Duck duck("µµ≥ŒµÂ", Pet::BIRDS, 1);
	GoldFish goldFish("¥œ∏", Pet::FISH, 2);

	/*cout << "\n** Cat∞¥√º ≈◊Ω∫∆Æ **" << endl;
	cat.eat();
	cat.creep();
	cat.view();

	cout << "\n** Dog∞¥√º ≈◊Ω∫∆Æ **" << endl;
	dog.eat();
	dog.creep();
	dog.view();

	cout << "\n** Duck∞¥√º ≈◊Ω∫∆Æ **" << endl;
	duck.eat();
	duck.creep();
	duck.swim();
	duck.view();

	cout << "\n** GoldFish∞¥√º ≈◊Ω∫∆Æ **" << endl;
	goldFish.eat();
	goldFish.swim();
	goldFish.view();*/


	Pet *petAry[4] = { 
		new Cat("æﬂøÀ¿Ã", Pet::MAMMAL, 2),
		new Dog("∏€∏€¿Ã", Pet::MAMMAL, 5),
		new Duck("µµ≥ŒµÂ", Pet::BIRDS, 1),
		new GoldFish("¥œ∏", Pet::FISH, 2)
	};
	for (int i = 0; i < sizeof(petAry) / sizeof(petAry[0]); i++) {
		petAry[i]->eat();
		if (dynamic_cast<Cat*>(petAry[i]) != NULL) { dynamic_cast<Cat*>(petAry[i])->creep(); }
		if (dynamic_cast<Dog*>(petAry[i]) != NULL) { dynamic_cast<Dog*>(petAry[i])->creep(); }
		if (dynamic_cast<Duck*>(petAry[i]) != NULL) { dynamic_cast<Duck*>(petAry[i])->creep(); }
		if (dynamic_cast<Duck*>(petAry[i]) != NULL) { dynamic_cast<Duck*>(petAry[i])->swim(); }
		if (dynamic_cast<GoldFish*>(petAry[i]) != NULL) { dynamic_cast<GoldFish*>(petAry[i])->swim(); }
		petAry[i]->view();
		cout << '\n';
	}
	for (int i = 0; i < sizeof(petAry) / sizeof(petAry[0]); i++) {
		delete petAry[i];
	}
	return 0;
}