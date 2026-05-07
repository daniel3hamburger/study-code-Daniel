#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Inventory;
class Weapon;
class Mage;
class Healer;

class Character
{
    friend class Mage;
    friend class Healer;

private:
    int health_points;

protected:
    std::string name;
    int level;
    const int MAXLEVEL = 10;
    int experience_points;
    Weapon* current_weapon;
    Inventory* inventory;

public:
    Character(const std::string& name, int health_points, int level, int experience_points);
    virtual ~Character();

    void regernerate_health(int health);
    Inventory& getInventory();
    void levelUp();
    int getHealth() const;
    void addExperience(int xp);
    virtual void display() = 0;
};

class Inventory
{
private:
    static const int MAXITEMS = 10;
    std::string items[MAXITEMS];

public:
    int getItemCount();
    bool addItem(std::string item);
    bool isEmpty();
    bool isFull();
    bool removeLastItem(std::string& Item);
};

class Weapon
{
private:
    std::string name;
    int damage_value;

public:
    Weapon(const std::string& name, int damage_value);
    std::string getName() const;
    int getDamage() const;
};

class Warrior : public Character
{
private:
    int skill_points;

public:
    Warrior(const std::string& name, int health_points, int level, int experience_points);
    void regenerate_skill(int skill_points);
    void display() override;
    virtual ~Warrior() {}

};

class Thief : public Warrior
{
public:
    Thief(const std::string& name, int health_points, int level, int experience_points);
    Thief& steal(Character& target);
    virtual ~Thief() {}

};

class Mage : public Character
{
private:
    int mana_points;

public:
    Mage(const std::string& name, int health_points, int level, int experience_points);
    void regenerate_mana(int mana_points);
    void display() override;
    virtual ~Mage() {}

};

class Healer : public Mage
{
public:
    Healer(const std::string& name, int health_points, int level, int experience_points);
    Healer& heal(Character& target);
    virtual ~Healer() {}

};

#endif
