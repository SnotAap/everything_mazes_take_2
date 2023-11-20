#include "Header.h"

std::vector<std::shared_ptr<Object>> renderList;
std::vector<std::pair<std::shared_ptr<Robot>, bool>> robotList;

bool solve = false;
int state = 0;
int sizeX = 20;
int sizeY = 20;

microTime currentTime;
microTime lastTime;
microTime deltaTime;

sf::Mouse myMouse;
sf::Font font;

int main()
{    
    QueryPerformanceFrequency(&frequency);
    srand((unsigned int)getMicroTime());    
    Grid grid(sizeX, sizeY);
    
    UI myUI(grid, font, renderList);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mazes!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
                    
            if (event.type == sf::Event::Closed)
                window.close();
        }        
        window.clear(sf::Color::White);
        //
        currentTime = getMicroTime();
        deltaTime = currentTime - lastTime;
        myUI.mousePressed(event);
        myUI.checkButtonsPressed(myMouse);
        myUI.checkButtonsHoverd(myMouse);  
              
        int action = myUI.checkButtonsPressed(myMouse);
        myUI.buttonAction(font, state, action, grid, renderList, robotList, solve);
        //myUI.ButtonManager(state);
        //
        switch (state)
        {
        case startState:
            myUI.activeButtons.clear();
            myUI.activeButtons.emplace_back(myUI.buttons[0]);
            myUI.activeButtons.emplace_back(myUI.buttons[1]);
            myUI.activeButtons.emplace_back(myUI.buttons[2]);
            myUI.activeButtons.emplace_back(myUI.buttons[3]);
            myUI.activeButtons.emplace_back(myUI.buttons[4]);
            myUI.activeButtons.emplace_back(myUI.buttons[5]);
            myUI.activeButtons.emplace_back(myUI.buttons[6]);
            myUI.activeButtons.emplace_back(myUI.buttons[7]);
            myUI.activeButtons.emplace_back(myUI.buttons[8]);
            myUI.activeButtons.emplace_back(myUI.buttons[9]);
            myUI.activeButtons.emplace_back(myUI.buttons[10]);

            break;
        case generateChoiseState:
            myUI.activeButtons.clear();
            myUI.activeButtons.emplace_back(myUI.buttons[11]);
            myUI.activeButtons.emplace_back(myUI.buttons[12]);

            break;
        case generateState:
            myUI.activeButtons.clear();
            myUI.activeButtons.emplace_back(myUI.buttons[13]);

            if (grid.removeWalls(deltaTime))
            {
                state++;
            }
            break;
        case solveState:
            myUI.activeButtons.clear();
            myUI.activeButtons.emplace_back(myUI.buttons[14]);
            myUI.activeButtons.emplace_back(myUI.buttons[15]);
            myUI.activeButtons.emplace_back(myUI.buttons[16]);
            myUI.activeButtons.emplace_back(myUI.buttons[17]);

            break;
        case solvingState:
            myUI.activeButtons.clear();
            myUI.activeButtons.emplace_back(myUI.buttons[18]);

            for (int i = 0; i < robotList.size(); i++)
            {
                if (robotList[i].second)
                {
                    robotList[i].first->movement(grid, deltaTime, renderList);                                            
                }
            }
            break;
        }
        for (int i = 0; i < renderList.size(); i++)
        {            
            renderList[i]->draw(&window);             
        }
        
        for (int i = 0; i < myUI.activeButtons.size(); i++)
        {
            myUI.activeButtons[i]->draw(&window);
        }
        for (int i = 0; i < robotList.size(); i++)
        {
            if (robotList[i].second)
            {
                robotList[i].first->draw(&window);
            }
        }
        for (int i = 0; i < grid.depthList.size(); i++)
        {
            grid.depthList[i]->draw(&window);
        }
        
        window.display();
        lastTime = currentTime;
        myUI.lastLeftMousePressed = myUI.LeftMousePressed;
    }
    return 0;
}




