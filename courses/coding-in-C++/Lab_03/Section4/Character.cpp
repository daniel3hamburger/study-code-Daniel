#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name, int health_points, int level, int experience_points)
    : name(name), health_points(health_points), level(level), experience_points(experience_points), current_weapon(nullptr)
{
    inventory = new Inventory();
}

Character::~Character()
{
    delete inventory;
}

void Character::regernerate_health(int health)
{
    if (health > 0)
        health_points += health;
}

Inventory& Character::getInventory()
{
    return *inventory;
}

void Character::levelUp()
{
    if (experience_points > 10 && level < MAXLEVEL)
        level++;
}

int Character::getHealth() const
{
    return health_points;
}

void Character::addExperience(int xp)
{
    experience_points += xp;
}


int Inventory::getItemCount()
{
    int count = 0;
    for (const auto& item : items)
        if (!item.empty())
            count++;
    return count;
}

bool Inventory::addItem(std::string item)
{
    if (isFull())
        return false;
    for (auto& slot : items)
        if (slot.empty())
        {
            slot = item;
            return true;
        }
    return false;
}

bool Inventory::isEmpty()
{
    return getItemCount() == 0;
}

bool Inventory::isFull()
{
    return getItemCount() >= MAXITEMS;
}

bool Inventory::removeLastItem(std::string& Item)
{
    for (int i = MAXITEMS - 1; i >= 0; --i)
        if (!items[i].empty())
        {
            Item = items[i];
            items[i].clear();
            return true;
        }
    return false;
}

Weapon::Weapon(const std::string& name, int damage_value)
    : name(name), damage_value(damage_value)
{
}

std::string Weapon::getName() const
{
    return name;
}

int Weapon::getDamage() const
{
    return damage_value;
}

Warrior::Warrior(const std::string& name, int health_points, int level, int experience_points)
    : Character(name, health_points, level, experience_points), skill_points(0)
{
}

void Warrior::regenerate_skill(int skill_points)
{
    this->skill_points += skill_points;
}

void Warrior::display()
{
    std::cout << "Warrior " << name << " HP: " << getHealth() << " Level: " << level << " Skill: " << skill_points << "\n";
}

Thief::Thief(const std::string& name, int health_points, int level, int experience_points)
    : Warrior(name, health_points, level, experience_points)
{
}

Thief& Thief::steal(Character& target)
{
    std::string stolen;
    if (target.getInventory().removeLastItem(stolen))
        getInventory().addItem(stolen);
    return *this;
}

Mage::Mage(const std::string& name, int health_points, int level, int experience_points)
    : Character(name, health_points, level, experience_points), mana_points(0)
{
}

void Mage::regenerate_mana(int mana_points)
{
    this->mana_points += mana_points;
}

void Mage::display()
{
    std::cout << "Mage " << name << " HP: " << getHealth() << " Level: " << level << " Mana: " << mana_points << "\n";
}

Healer::Healer(const std::string& name, int health_points, int level, int experience_points)
    : Mage(name, health_points, level, experience_points)
{
}

Healer& Healer::heal(Character& target)
{
    target.health_points += 20;
    return *this;
}
