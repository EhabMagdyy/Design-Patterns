#include <iostream>
#include <memory>

// Base Character class
class Character {
public:
    virtual void attack() const = 0;
    virtual ~Character() = default;
};

// Concrete Characters
class Warrior : public Character {
public:
    void attack() const override {
        std::cout << "Warrior swings a sword!" << std::endl;
    }
};

class Archer : public Character {
public:
    void attack() const override {
        std::cout << "Archer shoots an arrow!" << std::endl;
    }
};

class Mage : public Character {
public:
    void attack() const override {
        std::cout << "Mage casts a fireball!" << std::endl;
    }
};

// Abstract Factory
class CharacterFactory {
public:
    virtual std::unique_ptr<Character> createCharacter() const = 0;

    void action() const {
        auto character = createCharacter();
        character->attack();
    }

    virtual ~CharacterFactory() = default;
};

// Concrete Factories
class WarriorFromFactory : public CharacterFactory {
public:
    std::unique_ptr<Character> createCharacter() const override {
        return std::make_unique<Warrior>();
    }
};

class ArcherFromFactory : public CharacterFactory {
public:
    std::unique_ptr<Character> createCharacter() const override {
        return std::make_unique<Archer>();
    }
};

class MageFromFactory : public CharacterFactory {
public:
    std::unique_ptr<Character> createCharacter() const override {
        return std::make_unique<Mage>(); // Fixed this!
    }
};

// Main
int main() {
    std::unique_ptr<CharacterFactory> myArcher = std::make_unique<ArcherFromFactory>();
    std::unique_ptr<CharacterFactory> myMage = std::make_unique<MageFromFactory>();

    if(myArcher)
        myArcher->action();
    else
        std::cout << "myArcher is null" << std::endl;  // Archer shoots an arrow!

    if(myMage)
    myMage->action();
    else
        std::cout << "myMage is null" << std::endl;  // Mage casts a fireball!

    return 0;
}
