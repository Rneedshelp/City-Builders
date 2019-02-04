

//Persistence interface- High Score
//Technical Services - High Score from Package Diagram (logical view)     
class HighScore
{
    public:
    HighScore(int highScore1, int highScore2, int highScore3, int highScore4) : _highScore1(highScore1), _highScore2(highScore2), _highScore3(highScore3), _highScore4(highScore4)
    {}
    ~HighScore(){}
    virtual void compareScore(int score)= 0;
    protected:
    int _highScore1;
    int _highScore2;
    int _highScore3;
    int _highScore4;
};


//Persistence class instance of interface- LocalHighScore
//Player Package dependency from highscore Package in Technical Services, defined by //Administrator of Domain layer from Package Diagram (logical view)     

class LocalHighScore : public HighScore
{
    public:
    int highScore1, highScore2, highScore3, highScore4;
    //hardcoded high scores for comparison
    LocalHighScore(int NhighScore1, int NhighScore2 , int NhighScore3 , int NhighScore4): HighScore(highScore1, highScore2, highScore3, highScore4)
    {
        highScore1= NhighScore1;
        highScore2= NhighScore2;
        highScore3= NhighScore3;
        highScore4= NhighScore4;
        //highScore2= 25;
        //highScore3= 17;
        //highScore4= 12;
        cout<< "Created a HighScore Object"<<endl;
    }
    ~LocalHighScore(){}
    void compareScore(int score) override
    {
        cout<< "Comparing against other high Scores..." <<endl;
        if(score> highScore1)
        {
            cout<<" New high score!"<<endl;
            cout<< "Score of " <<score << "beats high score of " <<highScore1<<endl;
        }
        else if( score> highScore2)
        {
            cout<< "New second highest score!" <<endl;
        }
        else if (score> highScore3)
        {
            cout<< "New third highest score!" <<endl;
        }
        else if (score > highScore4)
        {
            cout<< "New fourth highest score!" <<endl;
        }
        else
        {
            cout<< "Score is not a new high score." <<endl;
        }    
    }
};

//Instance of Abstract Factory: Score Factory
class ScoreFactory
{
    public:
	//needs a body for some reason
    static ScoreFactory * createFactory(){}
    virtual HighScore * generateScore(int highScore1, int highScore2, int highScore3, int highScore4)= 0;
    //{
        //return new LocalHighScore(highScore1, highScore2, highScore3, highScore4);
    //}
};
//Instance of Factory Pattern: LocalScoreFactory
class LocalScoreFactory: public ScoreFactory
{
    public:
    LocalHighScore * generateScore(int highScore1, int highScore2, int highScore3, int highScore4) override
    {
        return new LocalHighScore(highScore1, highScore2, highScore3, highScore4);
    }
};
