#include <iostream>
#include <memory>
#include <string>

// Abstract Handler class
class Handler {
protected:
    std::shared_ptr<Handler> nextHandler;

public:
    virtual ~Handler() = default;

    void setNext(std::shared_ptr<Handler> next) {
        nextHandler = next;
    }
    // forward to the next handler if there any
    virtual void handleRequest(const std::string& issue) {
        if (nextHandler) {
            nextHandler->handleRequest(issue);
        } else {
            std::cout << "No department can handle this issue.\n";
        }
    }
};

// Concrete Handler: CustomerService
class CustomerService : public Handler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "general") {
            std::cout << "Customer service handling the issue.\n";
        } else {
            Handler::handleRequest(issue);
        }
    }
};

// Concrete Handler: TechnicalSupport
class TechnicalSupport : public Handler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "technical") {
            std::cout << "Technical support handling the issue.\n";
        } else {
            Handler::handleRequest(issue);
        }
    }
};

// Concrete Handler: BillingSupport
class BillingSupport : public Handler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "billing") {
            std::cout << "Billing team handling the issue.\n";
        } else {
            Handler::handleRequest(issue);
        }
    }
};

// Client code
int main() {
    // Create handlers
    auto billing = std::make_shared<BillingSupport>();
    auto technical = std::make_shared<TechnicalSupport>();
    auto customerService = std::make_shared<CustomerService>();

    // Build the chain: customerService -> technical -> billing
    customerService->setNext(technical);
    technical->setNext(billing);

    // Start processing requests
    // customer service -> handler -> technical
    customerService->handleRequest("technical"); // Technical support handling the issue.
    // customer service -> handler -> technical -> handler -> billing
    customerService->handleRequest("billing"); // Billing team handling the issue.
    // customer service -> handler -> technical -> handler -> billing -> handler
    customerService->handleRequest("other"); // No department can handle this issue.

    return 0;
}