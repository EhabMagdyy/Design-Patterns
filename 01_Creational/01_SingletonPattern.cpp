#include <iostream>

class GameSettings {
private:
    int volume;

    // private constructor so nobody can use "new" from outside
    GameSettings() {
        volume = 50; // default volume
    }

public:
    // preventing copying: delete copy constructor & assignment operator to avoid duplicates
    GameSettings(const GameSettings&) = delete;
    GameSettings& operator=(const GameSettings&) = delete;

    // static method to return a reference to the one object
    static GameSettings& getInstance() {
        static GameSettings instance; // the one and only instance
        return instance;
    }

    void setVolume(int v) {
        volume = v;
    }

    int getVolume() {
        return volume;
    }
};

int main() {
    // Get the one and only settings instance
    GameSettings& settings1 = GameSettings::getInstance();
    settings1.setVolume(75);

    GameSettings& settings2 = GameSettings::getInstance();
    std::cout << "Volume: " << settings2.getVolume() << std::endl; // 75

    // Both settings1 and settings2 point to the same object!
    return 0;
}
