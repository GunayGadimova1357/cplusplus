#include <iostream>

class Vehicle {
protected:
    char* _brand;
    char* _model;
    int _speed;

public:
    Vehicle(const char* brand, const char* model, int speed) : _speed(speed) {
        _brand = new char[std::strlen(brand) + 1];
        strcpy(_brand, brand);

        _model = new char[std::strlen(model) + 1];
        strcpy(_model, model);
    }

    virtual ~Vehicle() {
        delete[] _brand;
        delete[] _model;
    }

    virtual void displayInfo() {
        std::cout << "Brand: " << _brand << ", Model: " << _model << ", Speed: " << _speed << " km/h" << std::endl;
    }

    void*  pointerUndefined = nullptr;
};

class Car : public Vehicle {
private:
    int _doors;
    bool _hasAC;

public:
    Car(const char* brand, const char* model, int speed, int doors, bool ac)
        : Vehicle(brand, model, speed), _doors(doors), _hasAC(ac) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        std::cout << "Doors: " << _doors << ", Air Conditioning: " << (_hasAC ? "Yes" : "No") << std::endl;
    }

    Vehicle* toVehicle() {
        return static_cast<Vehicle*>(this);
    }
};

class Motorcycle : public Vehicle {
private:
    char* _handleType;

public:
    Motorcycle(const char* brand, const char* model, int speed, const char* ht)
        : Vehicle(brand, model, speed) {
        _handleType= new char[std::strlen(ht) + 1];
        std::strcpy(_handleType, ht);
    }

    ~Motorcycle() {
        delete[] _handleType;
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        std::cout << "Handlebars Type: " << _handleType << std::endl;
    }
};

void displayCarInfo(Vehicle* vehicle) {
    Car* car = dynamic_cast<Car*>(vehicle);
    if (car) {
        car->displayInfo();
    } else {
        std::cout << "This vehicle is not a car." << std::endl;
    }
}

void displayUsingReinterpretCast(Vehicle* vehicle) {
    Car* car = reinterpret_cast<Car*>(vehicle->pointerUndefined);
    if (car) {
        car->displayInfo();
    } else {
        std::cout << "reinterpret_cast failed, the object is not a Car." << std::endl;
    }
}

int main() {

    Car car("Toyota", "Corolla", 180, 4, true);
    Motorcycle motorcycle("Harley-Davidson", "Sportster", 120, "Sport");

    std::cout << "Created a car:" << std::endl;
    car.displayInfo();
    std::cout << "Created a motorcycle:" << std::endl;
    motorcycle.displayInfo();
    std::cout << std::endl;

    std::cout << "Checking if it's a car:" << std::endl;
    displayCarInfo(&car);
    displayCarInfo(&motorcycle);
    std::cout << std::endl;

    std::cout << "Using static_cast:" << std::endl;
    Vehicle* vehiclePtr = car.toVehicle();
    vehiclePtr->displayInfo();
    std::cout << std::endl;

    std::cout << "Using reinterpret_cast:" << std::endl;
    vehiclePtr->pointerUndefined = &car;
    displayUsingReinterpretCast(vehiclePtr);

    return 0;
}
