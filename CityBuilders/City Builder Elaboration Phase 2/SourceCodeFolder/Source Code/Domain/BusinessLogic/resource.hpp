//resource stub interface. Resource does not have any functions, only a constructor and destructor
//Business Logic underlies in Domain layer in Package Diagram. Dependent on Game package in Domain Layer. 

class Resource
{
    public:
    string resourceType;
    int amount;
    Resource(){}
    ~Resource(){}
};

//instance of resource interface- SimpleResource. generates a set amount of resources
//Resource package defined by game package in Domain Layer
class SimpleResource : public Resource
{
    public:
    string resourceType;
    int amount;
    SimpleResource()
    {
        resourceType = "wood";
        amount = 4;
    }
    ~SimpleResource(){}
};
