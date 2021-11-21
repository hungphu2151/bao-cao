#include <iostream>
using namespace std;

enum class FactionName
{
	Melee,
	Spellcasters
};

class Character
{
private:
	int abilityPoints{};
	int healthPoints{};
	FactionName faction{};
	int level{};
	string name{};
public:
	void AbilityPoints(int abilityPoints)
	{
		this->abilityPoints = abilityPoints;
		if (abilityPoints < 0 || abilityPoints > 100) cout << "Out of range" << endl;
		else cout << "AbilityPoints: " << this->abilityPoints << endl;
	}
	void Faction(FactionName faction)
	{
		this->faction = faction;
		cout << "Faction      : " << ((int)(FactionName)faction) << endl;
	}
	void HealthPoints(int healthPoints)
	{
		this->healthPoints = healthPoints;
		if (healthPoints < 0 || healthPoints > 100) cout << "Out of range" << endl;
		else cout << "HealthPoints : " << this->healthPoints << endl;
	}
	void Level(int level)
	{
		this->level = level;
		if (level < 0) cout << "Out of range" << endl;
		else cout << "Level        : " << this->level << endl;
	}
	void Name(string name)
	{
		this->name = name;
		if (name.length() < 3) cout << "Out of range" << endl;
		else cout << "Name         : " << this->name << endl;
	}
	virtual void Attack() = 0;
	virtual void SpecialAttack() = 0;
	virtual void Defend() = 0;
};
class Warrior : public Character
{
public:
	Warrior()
	{
		cout << "**********Warrior**********\n";
		AbilityPoints(40);
		HealthPoints(100);
		Faction(FactionName::Melee);
		Level(1);
		Name("Warrior");
	}
	void Attack() {
		cout << "Attack       : " << "Skill Strike\n";
	}
	void SpecialAttack() {
		cout << "SpecialAttack: " << "Skill Execute\n";
	}
	void Defend() {
		cout << "Defend       : " << "Skill SkinHarden\n";
	}
};
int main()
{
	Warrior* warrior = new Warrior();
	warrior->Attack();
	warrior->Defend();
	warrior->SpecialAttack();
	return 0;
}