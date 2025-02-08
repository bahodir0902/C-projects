#include <iostream>

using namespace std;



class Weapon //This is an abstract class
{
public:
	virtual void Shoot() = NULL;

	
};
class Gun : public Weapon
{
public:
	void Shoot() override 
	{
		cout << "BOOOM!!!" << endl;
	}
};
class MachineGun :public Gun 
{
public:
	void Shoot() override 
	{
		cout << "BOOOM BOOOM BOOOOM!!!" << endl;
	}
};  
class Bazooka : public Weapon 
{
public:
	void Shoot() override 
	{
		cout << "BABABAM!!!" << endl;
	}
};
class Knife : public Weapon 
{
public:
	void Shoot() override 
	{
		cout << "Xishing Xishing Xishing!!!" << endl;
	}
};
class Detonator : public Weapon 
{
public:
	void Shoot() override 
	{
		cout << "After 3 2 1 seconds will be BADABUMB!!!" << endl;
	}
};
class Player
{
public:
	void Shoot(Weapon &weapon) 
	{
		weapon.Shoot();
	}

};

int main(void)
{
	Knife knife;

	MachineGun machineGun;
	Player player;
	player.Shoot(knife); // ---> you can put here any object which derived from base abstract class!
	Detonator bomb;
	player.Shoot(bomb);
	
}

