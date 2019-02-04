//(Package Diagram) Game Package from Domain Layer starts up software
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#include "TechnicalServices/Login/login.hpp"
#include "TechnicalServices/HighScore/highScore.hpp"
#include "Domain/BusinessLogic/resource.hpp"
#include "Domain/BusinessLogic/building.hpp"
#include "Domain/Player/player.hpp"
#include "Domain/Game/game.hpp"
int main()
{
    SimpleGame newGame;
    newGame.createGame();
}  
