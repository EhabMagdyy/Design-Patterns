#include <iostream>
#include <memory>
#include <string>

// Prototype interface class
class Monster {
public:
    virtual std::unique_ptr<Monster> clone() const = 0; // clone method
    virtual void roar() const = 0;
    virtual ~Monster() = default;
};

// derived Concrete prototype 1
class Dragon : public Monster {
public:
    std::unique_ptr<Monster> clone() const override {
        return std::make_unique<Dragon>(*this); // deep copy (creats new Dragon & give it all the data that prototype has)
    }

    void roar() const override {
        std::cout << "Dragon: ROAAAR! 🔥" << std::endl;
    }
};

// derived Concrete prototype 2
class Goblin : public Monster {
public:
    std::unique_ptr<Monster> clone() const override {
        return std::make_unique<Goblin>(*this);
    }

    void roar() const override {
        std::cout << "Goblin: Grrr! 👹" << std::endl;
    }
};

int main() {
    std::unique_ptr<Monster> dragonPrototype = std::make_unique<Dragon>();
    std::unique_ptr<Monster> goblinPrototype = std::make_unique<Goblin>();

    // Clone them
    auto dragon1 = dragonPrototype->clone();
    auto dragon2 = dragonPrototype->clone();
    auto goblin1 = goblinPrototype->clone();

    dragon1->roar();  // Dragon: ROAAAR! 🔥
    dragon2->roar();  // Dragon: ROAAAR! 🔥
    goblin1->roar();  // Goblin: Grrr! 👹

    return 0;
}
