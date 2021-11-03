#include<iostream>
using namespace std;
class Characters
{
private:
	int abilityPoints{};
	string faction{};
	int healthPoints{};
	int level{};
	string name{};
public:
	void AbilityPoints(int abilityPoints);
	void Faction(string faction);
	void HealthPoints(int healthPoints);
	void Level(int level);
	void Name(string name);
	void BleedToDeath();
	void Suvival();
};
void Characters::AbilityPoints(int abilityPoints)
{
	this->abilityPoints = abilityPoints;
	if (abilityPoints < 0 || abilityPoints > 100) cout << "Out of range" << endl;
	else cout << this->abilityPoints << endl;
}
void Characters::Faction(string faction)
{
	this->faction = faction;
	if (faction.length() < 3) cout << "Out of range" << endl;
	else cout << this->faction;

}
void Characters::HealthPoints(int healthPoints)
{
	this->healthPoints = healthPoints;
	if (healthPoints < 0 || healthPoints > 100) cout << "Out of range" << endl;
	else cout << this->healthPoints << endl;
}
void Characters::Level(int level)
{
	this->level = level;
	if (level < 0) cout << "Out of range" << endl;
	else cout << this->level << endl;
}
void Characters::Name(string name)
{
	this->name = name;
	if (name.length() < 3) cout << "Out of range" << endl;
	else cout << this->name;
}
void Characters::BleedToDeath()
{
	cout << "Bleed To Death" << endl;
}
void Characters::Suvival()
{
	cout << "Suvival" << endl;
}
class LightLeatherVest
{
private:
	int armorPoints;
public:
	void ArmorPoints(int armorPoints);
	void BleedToDeath();
};
void LightLeatherVest::ArmorPoints(int armorPoints)
{
	this->armorPoints = armorPoints;
	if (armorPoints < 0) cout << "Out of range" << endl;
	else cout << this->armorPoints << endl;
}
void LightLeatherVest::BleedToDeath()
{
	cout << "Bleed To Death LLV" << endl;
}
class Warrior : public Characters, public LightLeatherVest
{
public:
	void BleedToDeath()
	{
		Characters::BleedToDeath();
	}
	void Suvival();
};
void Warrior::Suvival()
{
	cout << "Su sinh ton" << endl;
}
int main()
{
	Warrior warrior;
	warrior.BleedToDeath();
	return 0;
}