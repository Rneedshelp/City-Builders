//Player interface
//Player Package of Domain layer
class Player
{
    //example of high cohesion: each player class is specific to one player
    // also example of low coupling: Player only connects to resources and login, does not conslut the building class
    public:
    int resources;
    int buildings;
    int points;
    string loginInfo;

    Player()
    {}
    ~Player()
    {}
    
    virtual bool gatherResource() =0;

    //updates point totals and building numbers for the player
    virtual void buildBuilding( int cost, int pointValue) = 0;
    
    //checks to see if end condition met
    virtual bool endGame() = 0;

    //checks to see if it is a valid user.
    virtual void validate()= 0;
    virtual void quitGame(int playerNumber) = 0;
};

//Simple Player class. Has implemented finalized versions of most functions.
//Domain Layer defines player package and its dependency to the login in packages, and high //sore packages of Technical Services layers. 
class SimplePlayer: Player
{
    //example of high cohesion: each player class is specific to one player
    // also example of low coupling: Player only connects to resources and login, does not conslut the building class
    public:
    int resources;
    int buildings;
    int points;
    string loginInfo;

    SimplePlayer()
    {
        resources = 0;
        buildings= 0;
        points = 0;
    }
    ~SimplePlayer()
    {}
    
    bool gatherResource()
    {
        char answer;
            SimpleResource gatherResource;
            cout << "You are about to gather " << gatherResource.amount << " resources" << endl;
            cout << "Do you wish to continue with this action or cancel? Y or N\n";
            while (true)
        {
                    cin >> answer;
                    if (toupper(answer) == 'Y')
                    {
                        resources += gatherResource.amount;
                        cout << "Player has gathered " << resources << " total resources." << endl;
                        return true;
                    }
                    if (toupper(answer) == 'N')
                    {
                        return false;
                    }

        }


    }

    //updates point totals and building numbers for the player
//Bulding package instances defined 
    void buildBuilding( int cost, int pointValue)
    {
        resources -= cost;
        points+= pointValue;
        buildings++;
        cout<< "Current resources: " << resources <<endl <<"Current Points: " <<points <<endl <<"Current Buildings: " <<buildings<<endl;
    }
    
    //checks to see if end condition met
    bool endGame()
    {
        if( buildings >= 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //checks to see if it is a valid user. Currently, always returns true
    void validate()
    {
        string username, password;
        cout<< "Enter username: ";
        cin>>username;
        cout<< "Enter password: ";
        cin>>password;
        SimpleLogin newLogin;
        bool isValid=newLogin.signIn(username, password);
        if(isValid)
        {
            cout<< "User Validated"<<endl;
        }
        else
        {
            cout<< "User not Authenticated"<<endl;
        }
    }
    // informs the player that they have quit the game. destruction of the player class is handled elsewhere due to the need for the player instances to exist
    void quitGame(int playerNumber)
    {
        cout<< "Player Number " << playerNumber<< " Has quit the game." <<endl;
    }
};
