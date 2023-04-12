#include <iostream>

using namespace std;

class Beverage
{
private:
    string description;
    bool milk;
    bool soy;
    double milkCost;
    double soyCost;

public:
    Beverage(string description)
    {
        this->description = description;
        milk = false;
        soy = false;
        milkCost = 0.10;
        soyCost = 0.15;
    }

    string getDescription()
    {
        return description;
    }

    bool getMilk()
    {
        return milk;
    }

    bool getSoy()
    {
        return soy;
    }

    void setMilk(bool hasMilk)
    {
        milk = hasMilk;
    }

    void setSoy(bool hasSoy)
    {
        soy = hasSoy;
    }

    double cost()
    {
        double condimentCost = 0.0;
        if (milk)
        {
            condimentCost += milkCost;
        }
        if (soy)
        {
            condimentCost += soyCost;
        }
        return condimentCost;
    }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast() : Beverage("Most Outstanding Dark Roast") {}

    double cost()
    {
        return 1.99 + Beverage::cost();
    }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend() : Beverage("Most Excellent House Blend") {}

    double cost()
    {
        return 0.89 + Beverage::cost();
    }
};

int main()
{
    DarkRoast a;
    a.setMilk(true);
    a.setSoy(true);

    cout << "Dark Roast"
         << "| Description: " << a.getDescription()
         << "| Cost: " << a.cost() << endl;

    HouseBlend b;
    b.setSoy(true);

    cout << "House Blend"
         << "| Description: " << b.getDescription()
         << "| Cost: " << b.cost() << endl;
    
    HouseBlend c;
    c.setSoy(true);
    c.setMilk(true);

    cout << "House Blend"
         << "| Description: " << c.getDescription()
         << "| Cost: " << c.cost() << endl;


    return 0;
}
