#include <iostream>
using namespace std;

class IWarrior
{
	virtual void Strike() = 0;
	virtual void Execute() = 0;
	virtual void SkinHarden() = 0;
};
class IKnight
{
	virtual void HolyBlow() = 0;
	virtual void PurifySoul() = 0;
	virtual void RighteousWings() = 0;
};
class IAssassin
{
	virtual void Raze() = 0;
	virtual void BleedToDeath() = 0;
	virtual void Suvival() = 0;
};
class Warrior : public IWarrior
{
public:
	void Strike() {
		cout << "Skill Strike" << endl;
	}
	void Execute() {
		cout << "Skill Execute" << endl;
	}
	void SkinHarden() {
		cout << "Skill SkinHarden" << endl;
	}
};
class Assassin : public IAssassin
{
public:
	void Raze() {
		cout << "Skill Raze" << endl;
	}
	void BleedToDeath() {
		cout << "Skill BleedToDeath" << endl;
	}
	void Suvival() {
		cout << "Skill Suvival" << endl;
	}
};
class Knight : public IKnight
{
public:
	void HolyBlow()
	{
		cout << "Skill HolyBlow" << endl;
	}
	void PurifySoul()
	{
		cout << "Skill PurifySoul" << endl;
	}
	void RighteousWings()
	{
		cout << "Skill RighteousWings" << endl;
	}
};

int main()
{
	Knight k1;
	k1.HolyBlow();
	Warrior w1;
	w1.Execute();
	Assassin a1;
	a1.BleedToDeath();
	return 0;
}
