#include <iostream>
using namespace std;

class Character
{
public:
	virtual void Attack() = 0;
	virtual void SpecialAttack() = 0;
	virtual void Defend() = 0;
};

class Warrior : public Character
{
public:
	void Attack() {
		cout << "Skill Strike" << endl;
	}
	void SpecialAttack() {
		cout << "Skill Execute" << endl;
	}
	void Defend() {
		cout << "Skill SkinHarden" << endl;
	}
};
class Assassin : public Character
{
public:
	void Attack() {
		cout << "Skill Raze" << endl;
	}
	void SpecialAttack() {
		cout << "Skill BleedToDeath" << endl;
	}
	void Defend() {
		cout << "Skill Suvival" << endl;
	}
};

class Knight : public Character
{
public:
	void Attack()
	{
		cout << "Skill HolyBlow" << endl;
	}
	void SpecialAttack()
	{
		cout << "Skill PurifySoul" << endl;
	}
	void Defend()
	{
		cout << "Skill RighteousWings" << endl;
	}
};

int main()
{
	Character* k = new Knight();
	Character* a = new Assassin();
	Character* w = new Warrior();
	k->Attack();
	a->Attack();
	w->Attack();
	return 0;
}