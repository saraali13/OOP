/*
Name:S. Sara Ali
ID: 23K-0070
*/


#include <iostream>
#include <string>
using namespace std;

class GraphicsRenderingEngine 
{
public:
	
    void render() 
	{
        cout << "Graphics Rendering Engine is Rendering graphics\n";
    }
};// end 


class InputHandler 
{
public:
	
    void handleInput() 
	{
        cout << "Input Handler is Handling input\n";
    }
};// end


class PhysicsEngine 
{
public:
    void simulatePhysics() 
	{
        cout << "Physics Engine is Simulating physics\n";
    }
};// end


class GameEngine 
{
private:
	
    GraphicsRenderingEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
	
    void run() 
	{
        cout << "Game Engine\n";
        graphicsEngine.render();
        inputHandler.handleInput();
        physicsEngine.simulatePhysics();
        cout << "Game engine has started\n";
    }
};// end

int main() 
{
    GameEngine game;
    game.run();

    return 0;
}// end main
