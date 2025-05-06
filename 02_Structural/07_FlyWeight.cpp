#include <iostream>
#include <unordered_map>
#include <memory>

// Flyweight: shared tree model
class TreeType {
    std::string name;
    std::string texture;

public:
    TreeType(const std::string& name, const std::string& texture)
        : name(name), texture(texture) {}

    void draw(int x, int y) const {
        std::cout << "Drawing " << name << " at (" << x << ", " << y << ") with texture " << texture << "\n";
    }
};

// Flyweight Factory
class TreeFactory {
    std::unordered_map<std::string, std::shared_ptr<TreeType>> types;

public:
    std::shared_ptr<TreeType> getTreeType(const std::string& name, const std::string& texture) {
        std::string key = name + "_" + texture;
        if (types.find(key) == types.end()) {
            types[key] = std::make_shared<TreeType>(name, texture);
        }
        return types[key];
    }
};

// Context: stores extrinsic state (position)
class Tree {
    int x, y;
    std::shared_ptr<TreeType> type;

public:
    Tree(int x, int y, std::shared_ptr<TreeType> type) : x(x), y(y), type(type) {}

    void draw() const {
        type->draw(x, y);
    }
};

// Client Code
int main() {
    TreeFactory factory;

    // Shared type
    auto pineType = factory.getTreeType("Pine", "pine_texture.png");

    // Each tree has unique position, but same type
    Tree tree1(10, 20, pineType);
    Tree tree2(30, 40, pineType);
    Tree tree3(50, 60, pineType);

    tree1.draw();
    tree2.draw();
    tree3.draw();

    return 0;
}
