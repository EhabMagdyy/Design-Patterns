#include <iostream>
#include <vector>
#include <memory>

// Component - interface class
class FileSystemItem {
public:
    virtual void display() const = 0;
    virtual ~FileSystemItem() {}
};

// Leaf - derived class
class File : public FileSystemItem {
    std::string name;
public:
    File(const std::string& n) : name(n) {}
    void display() const override {
        std::cout << "File: " << name << std::endl;
    }
};

// Composite - derived class
class Folder : public FileSystemItem {
    std::string name;
    std::vector<std::shared_ptr<FileSystemItem>> items; // vector of items
public:
    Folder(const std::string& n) : name(n) {}
    // add files/folders (FileSystemItem)
    void add(const std::shared_ptr<FileSystemItem>& item) {
        items.push_back(item);
    }

    void display() const override {
        std::cout << "Folder: " << name << std::endl;
        for (const auto& item : items) {
            item->display();
        }
    }
};

// Main
int main() {
    auto file1 = std::make_shared<File>("hello.txt");
    auto file2 = std::make_shared<File>("world.txt");
    auto file3 = std::make_shared<File>("readme.md");

    auto folder1 = std::make_shared<Folder>("Documents");
    folder1->add(file1);
    folder1->add(file2);

    auto folder2 = std::make_shared<Folder>("Workspace");
    folder2->add(folder1); // Add folder1 inside folder2
    folder2->add(file3);   // Workspace - Documents - hello.txt - world.txt - readme.md

    folder2->display();
    return 0;
}
