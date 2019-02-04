//Bulding stub class. generates 1 type of building for use
//Building Package of business logic layer defined by Game Package of the Domain Layer
class Building
{
    public:
    string type;
    int pointValue;
    int cost;
    Building(){}
    ~Building(){}
    virtual void assignPoints()=0;
};

//instance of polymorphism: Different Buildings
// House is an instance of the building class
//Type of bulding instance created by Game Package
class House: public Building
{
    public:
    House(){}
    ~House(){}
    void  assignPoints() override
    {
        type = "House";
        pointValue = 3;
        cost = 2;
    }
};


// bridge is an instance of the building class
//Type of building instance created by Game Package
class Bridge: public Building
{
    public:
    Bridge(){}
    ~Bridge(){}
    void assignPoints() override
    {
        type = "Bridge";
        pointValue= 5;
        cost = 4;
    }
};

//Skyscraper is an instance of the building class
//Type of building instance created by Game Package
class SkyScraper: public Building
{
    public:
    SkyScraper(){}
    ~SkyScraper(){}
    void assignPoints() override
    {
        type = "SkyScraper";
        pointValue = 15;
        cost= 10;
    }
};

// School is an instance of the building class
//Type of building instance created by Game Package

class School: public Building
{
    public:
    School(){}
    ~School(){}
    void assignPoints() override
    {
        type = "School";
        pointValue= 8;
        cost = 6;
    }
};
//Gameboard class was removed, replaced with the polymorphic Building Interface
