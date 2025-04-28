#include <iostream>
#include <memory>

// ===== Product Interfaces =====
class Character {
public:
    virtual void speak() const = 0;
    virtual ~Character() = default;
};

class Weapon {
public:
    virtual void use() const = 0;
    virtual ~Weapon() = default;
};

// ===== Medieval Product Implementations =====
class Knight : public Character {
public:
    void speak() const override {
        std::cout << "Knight: For the king!" << std::endl;
    }
};

class Sword : public Weapon {
public:
    void use() const override {
        std::cout << "Sword slashes!" << std::endl;
    }
};

// ===== Futuristic Product Implementations =====
class Robot : public Character {
public:
    void speak() const override {
        std::cout << "Robot: Beep boop. Target acquired." << std::endl;
    }
};

class Laser : public Weapon {
public:
    void use() const override {
        std::cout << "Laser zaps!" << std::endl;
    }
};

// ===== Abstract Factory Interface =====
class GameFactory {
public:
    virtual std::unique_ptr<Character> createCharacter() const = 0;
    virtual std::unique_ptr<Weapon> createWeapon() const = 0;
    virtual ~GameFactory() = default;
};

// ===== Concrete Factories =====
class MedievalFactory : public GameFactory {
public:
    std::unique_ptr<Character> createCharacter() const override {
        return std::make_unique<Knight>();
    }

    std::unique_ptr<Weapon> createWeapon() const override {
        return std::make_unique<Sword>();
    }
};

class FuturisticFactory : public GameFactory {
public:
    std::unique_ptr<Character> createCharacter() const override {
        return std::make_unique<Robot>();
    }

    std::unique_ptr<Weapon> createWeapon() const override {
        return std::make_unique<Laser>();
    }
};

// ===== Main Function =====
int main() {
    std::unique_ptr<GameFactory> factory;

    factory = std::make_unique<MedievalFactory>();

    auto medievalCharacter = factory->createCharacter();
    auto medievalWeapon = factory->createWeapon();


    factory = std::make_unique<FuturisticFactory>();
    auto futuristicCharacter = factory->createCharacter();
    auto futuristicWeapon = factory->createWeapon();


    medievalCharacter->speak();  // Knight: For the king!
    medievalWeapon->use();       // Sword slashes!

    factory = std::make_unique<FuturisticFactory>();

    futuristicCharacter->speak();  // Robot: Beep boop. Target acquired.
    futuristicWeapon->use();       // Laser zaps!

    return 0;
}
