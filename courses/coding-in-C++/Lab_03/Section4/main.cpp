#include "Character.hpp"
#include <iostream>

int main()
{
    Warrior w("Bjorn", 100, 1, 0);
    Mage m("Merlin", 80, 1, 0);
    Healer h("Aeris", 70, 1, 0);
    Thief t("Shadow", 60, 1, 0);

    w.getInventory().addItem("Potion");
    w.getInventory().addItem("Iron");

    m.getInventory().addItem("Mana Potion");

    w.display();
    m.display();

    w.regenerate_skill(5);
    m.regenerate_mana(10);

    h.heal(w);
    h.heal(m);

    t.steal(w);

    w.addExperience(20);
    w.levelUp();

    w.levelUp();
    w.display();

    return 0;
}
