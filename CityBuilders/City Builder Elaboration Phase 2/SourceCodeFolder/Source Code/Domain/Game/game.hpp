//Game interface
//Game Package from Domain Layer in Package Diagram(Logical View)

class Game
{
    public:
    Game(){}
    ~Game(){}
    virtual void tellWinner(int playerNumber)= 0;
    virtual void createGame()=0;
};
//fleshed out simple game, a class from the game interface. Is at the top of the hierarchy.
class SimpleGame: Game
{
// instance of Information expert: houses all the information for the system
    public:
    void tellWinner( int playerNumber)
    {
        cout<< "Player number " <<playerNumber << " is the Winner!"<<endl;
    }
//instance of Controller: handles how the information is changed and manipulated through the //system

    // the meat of the program. creates instances of players and plays the actual game calling all //the classes in proper order


//Package Diagram layers applied, used, and either defined or intervened. 
//Domain layer has Game packages utilize player packages, and administrator packages to //uphold game state. 
//UI layers Command Line package is utilized in all retrieving data scenarios to advance. 
//Player Packages dependency on Technical Services packages utilizes command line to //choose an option to play the game.
// As seen on our SAD document under Logical View Section login Requires Name/ID and //passwords. For whenever a player is added to our Player package then a business logic layers //of buildings and high scores are attached to the Domain layers utilized by the player packages, //administrator packages, and defined by the Game package. 

    void createGame()
    {
        //instance of creator: creates the player classes
        SimplePlayer player1;
        SimplePlayer player2;
        SimplePlayer player3;
        player1.validate();
        player2.validate();
        player3.validate();
        //GameBoard currentGameboard;
        //currentGameboard.GenerateBuilding();
        bool foundWinner= false;
        int currentPlayer =0;
        bool firstPlayer = true;
        bool secondPlayer = true;
        bool thirdPlayer = true;
        int totalPlayers= 3;
        char input;
        // loop that runs the game
        while(!foundWinner)
        {
            // done using innefficent ways, but was fast and accurate.
           //UI layer in package Diagram utilizes Domain layer to retrieve action called
 if(currentPlayer%3+1 == 1)
            {
                if(firstPlayer)  
                {
                    cout<< "Player " <<currentPlayer%3 +1 << " choose gather resource (g), build building (b),end game (e), or quit game(q): " ;
            cin>> input;
                if(input == 'g') //
                {
                    if(player1.gatherResource())
                    {
                    currentPlayer++;
                    }
                }
                else if(input == 'b')
                {
                    cout<< "Player " << currentPlayer%3+1 << " choose SkyScraper (t), School (s), House (h), or Bridge (b): ";
                    cin>> input;
                    if( input == 't')
                    {
                        SkyScraper newSkyScraper;
                        newSkyScraper.assignPoints();
                        if(player1.resources< newSkyScraper.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player1.buildBuilding(newSkyScraper.cost, newSkyScraper.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 's')
                    {
                        School newSchool;
                        newSchool.assignPoints();
                        if(player1.resources< newSchool.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player1.buildBuilding(newSchool.cost, newSchool.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 'h')
                    {
                        House newHouse;
                        newHouse.assignPoints();
                        if(player1.resources< newHouse.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player1.buildBuilding(newHouse.cost, newHouse.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 'b') //Business Logic layer under Domain Layer
                    {
                        Bridge newBridge;
                        newBridge.assignPoints();
                        if(player1.resources< newBridge.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player1.buildBuilding(newBridge.cost, newBridge.pointValue);
                            currentPlayer++;
                        }
                    }
                
                }
                else if(input == 'e')
                {
                    bool test= player1.endGame();
                    if(test)
                    {
                        foundWinner=true;
                    }
                    else
                    {
                        cout<< "You cannot end the game. " <<endl;
                    }
                }
                else if (input== 'q') //UI layer
                {
                    player1.quitGame(1);
                    firstPlayer=false;
                    currentPlayer++;
                }
                }
                else
                {
                    currentPlayer++;
                }
            }
            else if(currentPlayer%3+1== 2)
            {
                if(secondPlayer)
                {
                    cout<< "Player " <<currentPlayer%3 +1 << " choose gather resource (g), build building (b),end game (e), or quit game(q): " ;
                    cin>> input;
                if(input == 'g')
                {
                    if(player2.gatherResource())
                    {
                    currentPlayer++;
                    }
                }
                else if(input == 'b')
                {
                    cout<< "Player " << currentPlayer%3+1 << " choose SkyScraper (t), School (s), House (h), or Bridge (b): ";
                    cin>> input;
                    if( input == 't')
                    {
                        SkyScraper newSkyScraper;
                        newSkyScraper.assignPoints();
                        if(player2.resources< newSkyScraper.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player2.buildBuilding(newSkyScraper.cost, newSkyScraper.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 's')
                    {
                        School newSchool;
                        newSchool.assignPoints();
                        if(player2.resources< newSchool.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player2.buildBuilding(newSchool.cost, newSchool.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 'h')
                    {
                        House newHouse;
                        newHouse.assignPoints();
                        if(player2.resources< newHouse.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player2.buildBuilding(newHouse.cost, newHouse.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 'b')
                    {
                        Bridge newBridge;
                        newBridge.assignPoints();
                        if(player2.resources< newBridge.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player1.buildBuilding(newBridge.cost, newBridge.pointValue);
                            currentPlayer++;
                        }
                    }
                }
                else if(input == 'e') //Technical Services utilizes High Score Package
                {
                    bool test= player2.endGame();
                    if(test)
                    {
                        foundWinner=true;
                    }
                    else
                    {
                        cout<< "You cannot end the game. " <<endl;
                    }
                }
                else if (input== 'q')
                {
                    player2.quitGame(2);
                    secondPlayer=false;
                }
                }
                else
                {
                    currentPlayer++;
                }
            }
            else if(currentPlayer%3+1== 3)
            {
                if(thirdPlayer)
                {
                    cout<< "Player " <<currentPlayer%3 +1 << " choose gather resource (g), build building (b),end game (e), or quit game(q): " ;
                    cin>> input;
                if(input == 'g')
                {
                    if(player3.gatherResource())
                    {
                    currentPlayer++;
                    }
                }
                else if(input == 'b')
                {
                    cout<< "Player " << currentPlayer%3+1 << " choose SkyScraper (t), School (s), House (h), or Bridge (b): ";
                    cin>> input;
                    if( input == 't')
                    {
                        SkyScraper newSkyScraper;
                        newSkyScraper.assignPoints();
                        if(player3.resources< newSkyScraper.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player3.buildBuilding(newSkyScraper.cost, newSkyScraper.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 's')
                    {
                        School newSchool;
                        newSchool.assignPoints();
                        if(player3.resources< newSchool.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player3.buildBuilding(newSchool.cost, newSchool.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 'h')
                    {
                        House newHouse;
                        newHouse.assignPoints();
                        if(player3.resources< newHouse.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player3.buildBuilding(newHouse.cost, newHouse.pointValue);
                            currentPlayer++;
                        }
                    }
                    else if( input == 'b')
                    {
                        Bridge newBridge;
                        newBridge.assignPoints();
                        if(player3.resources< newBridge.cost)
                        {
                            cout<< "Unable to build with current resources" <<endl;
                        }
                        else
                        {
                            player3.buildBuilding(newBridge.cost, newBridge.pointValue);
                            currentPlayer++;
                        }
                    }
                }
                else if(input == 'e')
                {
                    bool test= player3.endGame();
                    if(test)
                    {
                        foundWinner=true;
                    }
                    else
                    {
                        cout<< "You cannot end the game. " <<endl;
                    }
                }
                else if (input== 'q')
                {
                    player3.quitGame(3);
                    thirdPlayer=false;
                }
                }
                else
                {
                    currentPlayer++;
                }
            }
        }
        //checks to see who the winner is
        ScoreFactory * newFactory = new LocalScoreFactory;
        HighScore * newHighScore = newFactory->generateScore(22,18,14,10);
        if(player1.points> player2.points)
        {
            if(player1.points> player3.points)
            {
                tellWinner(1);
                newHighScore->compareScore(player1.points);
            }
        }
        else if ( player2.points>player3.points)
        {
            tellWinner(2);
            newHighScore->compareScore(player2.points);
        }
        else
        {
            tellWinner(3);
            newHighScore->compareScore(player3.points);
        }
        delete newHighScore;
    }
};
