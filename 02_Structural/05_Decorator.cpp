#include <iostream>
#include <string>

// Abstract Component
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
};

// Concrete Component
class BasicCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Basic Coffee";
    }
    double getCost() const override {
        return 5.0;
    }
};

// Base Decorator
class CoffeeDecorator : public Coffee {
protected:
    const Coffee& wrappedCoffee; // Reference to the wrapped object
public:
    CoffeeDecorator(const Coffee& coffee) : wrappedCoffee(coffee) {}
};

// Concrete Decorator: Milk
class Milk : public CoffeeDecorator {
public:
    Milk(const Coffee& coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return wrappedCoffee.getDescription() + " + Milk";
    }

    double getCost() const override {
        return wrappedCoffee.getCost() + 1.0;
    }
};

// Concrete Decorator: Sugar
class Sugar : public CoffeeDecorator {
public:
    Sugar(const Coffee& coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return wrappedCoffee.getDescription() + " + Sugar";
    }

    double getCost() const override {
        return wrappedCoffee.getCost() + 0.5;
    }
};

// Concrete Decorator: Ice
class Ice : public CoffeeDecorator{
public:
    Ice(const Coffee& coffee) : CoffeeDecorator(coffee){}

    std::string getDescription() const override {
        return wrappedCoffee.getDescription() + " + Ice";
    }

    double getCost() const override {
        return wrappedCoffee.getCost() + 0.3;
    }
};

// Client Code
int main() {
    BasicCoffee coffee;                                     // Basic coffee
    Milk coffeeWithMilk(coffee);                            // Add milk
    Sugar coffeeWithMilkAndSugar(coffeeWithMilk);           // Add sugar
    Ice iceCoffeeWithMilkAndSugar(coffeeWithMilkAndSugar);  // ice

    std::cout << iceCoffeeWithMilkAndSugar.getDescription() << " --> $"
     << iceCoffeeWithMilkAndSugar.getCost() << std::endl;

    return 0;
}
