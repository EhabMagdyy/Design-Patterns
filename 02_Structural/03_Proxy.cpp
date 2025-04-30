#include <iostream>
#include <string>
#include <memory>

// Real Subject
class RealImage {
    std::string filename;

public:
    RealImage(const std::string& file) : filename(file) {
        std::cout << "Loading image: " << filename << std::endl;
    }

    void display() {
        std::cout << "Displaying image: " << filename << std::endl;
    }
};

// Proxy
class ProxyImage {
    std::string filename;
    std::unique_ptr<RealImage> realImage;

public:
    ProxyImage(const std::string& file) : filename(file) {}

    void display() {
        if (!realImage) {
            realImage = std::make_unique<RealImage>(filename);
        }
        realImage->display();
    }
};

// Main
int main() {
    ProxyImage img("photo.png");

    std::cout << "Image created, not loaded yet.\n";
    img.display();  // Loads and displays
    img.display();  // Only displays (no reload)

    return 0;
}
