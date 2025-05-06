#include <iostream>

// Subsystem classes
class Projector {
public:
    void on() { std::cout << "Projector On\n"; }
    void off() { std::cout << "Projector On\n"; }
    void setInput() { std::cout << "Projector input set to HDMI\n"; }
};

class Screen {
public:
    void down() { std::cout << "Screen goes down\n"; }
    void up() { std::cout << "Screen goes up\n"; }
};

class Speakers {
public:
    void on() { std::cout << "Speakers On\n"; }
    void off() { std::cout << "Speakers Off\n"; }
};

// Facade
class HomeTheaterFacade {
    Projector& projector;
    Screen& screen;
    Speakers& speakers;

public:
    HomeTheaterFacade(Projector& p, Screen& s, Speakers& sp)
        : projector(p), screen(s), speakers(sp) {}

    void watchMovie() {
        std::cout << "Get ready to watch a movie...\n";
        screen.down();
        projector.on();
        projector.setInput();
        speakers.on();
    }

    void shutdown() {
        std::cout << "Shutting down...\n";
        screen.up();
        projector.off();
        speakers.off();
    }
};

// Client
int main() {
    Projector projector;
    Screen screen;
    Speakers speakers;

    HomeTheaterFacade theater(projector, screen, speakers);
    theater.watchMovie();  // All setup steps in one call!
    theater.shutdown();

    return 0;
}
