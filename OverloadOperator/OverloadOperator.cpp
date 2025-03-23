
#include <iostream>
#include <string>
#include <vector>



class Vehicle
{
public:

    virtual std::ostream& print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& x)
    {
        return x.print(os);
    }

protected:
};

class WaterVehicle : public Vehicle
{
public:

    WaterVehicle(float a = 0) : Draught(a) {}

    std::ostream& print(std::ostream& os) const override
    {
        os << "Draught of WaterVehicle : " << GetDraught() << "\n";
        return os;
    }

    float GetDraught() const
    {
        return Draught;
    }

protected:
 
    float Draught;
};

class RoadVehicle : public Vehicle
{
public:

    RoadVehicle(float a = 0) : Clearance(a) {}

    std::ostream& print(std::ostream& os) const override
    {
        return os;
    }

    float GetClearance() const
    {
        return Clearance;
    
    }
protected:

    float Clearance;
};



class Wheel
{
public:
    Wheel(float Size = 0) : Diameter(Size) {};


    float GetDiameter() const
    {
        return Diameter;
    }
protected:

    float Diameter;
};

class Engine
{
public:
    Engine(float power = 0) : Power(power) {};

    float GetPower() const
    {
        return Power;
    }
protected:

    float Power;
};

class Car : public RoadVehicle
{
public:
    Car(const Engine& engine, const Wheel& first, const Wheel& second, const Wheel& third, const Wheel& fourth, float clearance)
    {
         DOHC = engine;
         Front1 = first;
         Front2 = second;
         Rear1 = third;
         Rear2 = fourth;
         Clearance = clearance;
    }

    std::ostream& print(std::ostream& os) const override
    {
        os << "Car Engine : " << DOHC.GetPower() << " Wheels : " << Front1.GetDiameter() << " " << Front1.GetDiameter() << " " << Front1.GetDiameter() << " " << Front1.GetDiameter() << " Ride Heght: " << GetClearance() << "\n";
        return os;
    }

    float GetPower()
    {
        return DOHC.GetPower();
    }

protected:

    Engine DOHC;

    Wheel Front1;
    Wheel Front2;
    Wheel Rear1;
    Wheel Rear2;
};

class Bicycle : public RoadVehicle
{
public:
    Bicycle(const Wheel& first, const Wheel& second, float clearance)
    {
        Front = first;
        Rear = second;
        Clearance = clearance;
    }
    std::ostream& print(std::ostream& os) const override
    {
        os << "Bycicle Wheels : " << Front.GetDiameter() << " " << Rear.GetDiameter() <<" " <<" Ride Heght: " << GetClearance() << "\n";
        return os;
    }

protected:

    Wheel Front;
    Wheel Rear;
};

void ShowAllVehicles(std::vector<Vehicle*> const &vec ) 
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        std::cout << *vec[i] << "\n";
    }
}

float GetHighestPower(std::vector<Vehicle*> const& vec)
{
    float HP = 0;
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        Car* tempCar = dynamic_cast<Car*>(vec[i]);
        
        if (tempCar)
        {
            if (tempCar->GetPower() > HP)
                HP = tempCar->GetPower();
        }
    }
    return HP;
}

void ClearAllVehicles(std::vector<Vehicle*> & vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        delete vec[i];
    }
    vec.clear();
}

// Main programme

int main()
{

    Car c(Engine(150.f), Wheel(17.f), Wheel(17.f), Wheel(18.f), Wheel(18.f), 150.f);
    std:: cout << c << "\n";

    Bicycle t(Wheel(20), Wheel(20), 300);
    std::cout << t << "\n";

    std::vector<Vehicle*> v;
    v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));

   // v.push_back(new Circle(Point(1, 2, 3), 7));

    v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));

    v.push_back(new WaterVehicle(5000));

    std::cout <<"Show all vehicles" << "\n";
    ShowAllVehicles(v);

    std::cout << "The highest power is " << GetHighestPower(v)<< "\n";

    std::cout << "Delete all vehicle" << "\n";
    ClearAllVehicles(v);

    return 0;
}

