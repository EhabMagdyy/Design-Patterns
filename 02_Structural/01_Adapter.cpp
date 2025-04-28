#include <iostream>
#include <memory>

// Target interface (what the system expects)
class IPrinter {
public:
    virtual void printDocument() const = 0;
    virtual ~IPrinter() = default;
};

// Adaptee (incompatible interface)
class OldPrinter {
public:
    void oldPrint() const {
        std::cout << "OldPrinter: Printing via oldPrint() method." << std::endl;
    }
};

// Adapter (makes OldPrinter compatible with IPrinter)
class PrinterAdapter : public IPrinter {
private:
    std::shared_ptr<OldPrinter> oldPrinter;
public:
    PrinterAdapter(std::shared_ptr<OldPrinter> op) : oldPrinter(op) {}

    void printDocument() const override {
        oldPrinter->oldPrint();  // Translate the call
    }
};

// Main client
int main() {
    std::shared_ptr<OldPrinter> legacyPrinter = std::make_shared<OldPrinter>();
    std::unique_ptr<IPrinter> printer = std::make_unique<PrinterAdapter>(legacyPrinter);

    printer->printDocument();  // OldPrinter: Printing via oldPrint() method.

    return 0;
}
