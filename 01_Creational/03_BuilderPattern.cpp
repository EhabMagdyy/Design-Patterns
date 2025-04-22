#include <iostream>
#include <string>
#include <memory>

// --- The Product ---
class GameCharacter {
    friend class CharacterBuilder;
  private:
    std::string name_   = "Unknown";
    std::string weapon_ = "Fists";
    std::string armor_  = "Cloth";
    int         hp_     = 100;

    GameCharacter() = default;

  public:
    void describe() const {
        std::cout
          << "Name: "   << name_
          << ", Weapon: "<< weapon_
          << ", Armor: " << armor_
          << ", HP: "    << hp_
          << "\n";
    }
};

// --- The Builder ---
class CharacterBuilder {
  private:
    std::unique_ptr<GameCharacter> character_;

  public:
    CharacterBuilder()
      : character_( std::unique_ptr<GameCharacter>( new GameCharacter() ) )
    {}

    CharacterBuilder& setName(const std::string& n) {
        character_->name_ = n;
        return *this;
    }

    CharacterBuilder& setWeapon(const std::string& w) {
        character_->weapon_ = w;
        return *this;
    }

    CharacterBuilder& setArmor(const std::string& a) {
        character_->armor_ = a;
        return *this;
    }

    CharacterBuilder& setHitPoints(int hp) {
        character_->hp_ = hp;
        return *this;
    }

    std::unique_ptr<GameCharacter> build() {
        return std::move(character_);
    }
};

// --- Client Code ---
int main() {
    auto hero = CharacterBuilder()
                  .setName("Artemis")
                  .setWeapon("Longbow")
                  .setArmor("Leather")
                  .setHitPoints(120)
                  .build();

    auto brawler = CharacterBuilder()
                     .setName("Brutus")
                     .setWeapon("Gauntlets")
                     .build();  // uses defaults for armor & HP

    hero->describe();     // Name: Artemis, Weapon: Longbow, Armor: Leather, HP: 120
    brawler->describe();  // Name: Brutus, Weapon: Gauntlets, Armor: Cloth, HP: 100

    return 0;
}
