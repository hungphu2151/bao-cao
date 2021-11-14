#include <iostream>
using namespace std;

class IDruid
{
	virtual void Moonfire() = 0;
	virtual void Starburst() = 0;
	virtual void OneWithTheNature() = 0;
};
class IMage
{
	virtual void AcaneWrath() = 0;
	virtual void Firewall() = 0;
	virtual void Meditation() = 0;
};
class INecromancer
{
	virtual void ShadowRaze() = 0;
	virtual void VampireTouch() = 0;
	virtual void BoneShield() = 0;
};
class Druid : public IDruid
{
public:
	void Moonfire()
	{
		cout << "Skill Moonfire" << endl;
	}
	void Starburst()
	{
		cout << "Skill Starburst" << endl;
	}
	void OneWithTheNature()
	{
		cout << "Skill OneWithTheNature" << endl;
	}
};
class Mage : public IMage
{
public:
	void AcaneWrath()
	{
		cout << "Skill AcaneWrath" << endl;
	}
	void Firewall()
	{
		cout << "Skill Firewall" << endl;
	}
	void Meditation()
	{
		cout << "Skill Meditation" << endl;
	}
};
class Necromancer : public INecromancer
{
public:
	void ShadowRaze()
	{
		cout << "Skill ShadowRaze" << endl;
	}
	void VampireTouch()
	{
		cout << "Skill VampireTouch" << endl;
	}
	void BoneShield()
	{
		cout << "Skill BoneShield" << endl;
	}
};

int main()

{
	Mage mage;
	mage.Meditation();
	return 0;
}