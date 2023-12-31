#include "Header.h"

std::vector<std::shared_ptr<Object>> renderList;
std::vector<std::pair<std::shared_ptr<Robot>, bool>> robotList;

bool solve = false;


int state = 0;
int sizeX = 20;
int sizeY = 20;

microTime currentTime = 0;
microTime lastTime = 0;
microTime deltaTime = 0;

sf::Mouse myMouse;
sf::Font font;



int main()
{    
    QueryPerformanceFrequency(&frequency);
    srand((unsigned int)getMicroTime());    
    Console myConsole;
    myConsole.pollDataCommands();
    myConsole.excecuteDataInstructions();
    myConsole.returnStats();
    Grid grid(sizeX, sizeY);
    UI myUI(grid, font, renderList);
    myConsole.pollLoopCommands(myUI);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mazes!");
    lastTime = getMicroTime();

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

        if (myUI.loop)
        {
            myConsole.excecuteLoopInstructions(deltaTime, font, state, grid, robotList, solve, myUI);
        }
        
        int action = myUI.checkButtonsPressed(myMouse);
        myUI.buttonAction(font, state, action, grid, robotList, solve);
        //myUI.ButtonManager(state);
        //
        

        myUI.activeButtons.clear();
        if (myConsole.loopCommandGiven && !myUI.loop)
        {
            myUI.activeButtons.emplace_back(myUI.buttons[22]);
        }
        switch (state)
        {
        case startState:
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
            myUI.activeButtons.emplace_back(myUI.buttons[23]);

            break;
        case generateChoiseState:
            myUI.activeButtons.emplace_back(myUI.buttons[11]);
            myUI.activeButtons.emplace_back(myUI.buttons[12]);
            myUI.activeButtons.emplace_back(myUI.buttons[21]);
            myUI.activeButtons.emplace_back(myUI.buttons[24]);
            break;
        case generateState:
            myUI.activeButtons.emplace_back(myUI.buttons[13]);
            myUI.activeButtons.emplace_back(myUI.buttons[14]);
            myUI.activeButtons.emplace_back(myUI.buttons[21]);
            myUI.activeButtons.emplace_back(myUI.buttons[25]);
            
            if (grid.removeWalls(deltaTime))
            {
                state++;
                myUI.resumeloop = true;
            }
            break;
        case solveState:
            myUI.activeButtons.emplace_back(myUI.buttons[15]);
            myUI.activeButtons.emplace_back(myUI.buttons[16]);
            myUI.activeButtons.emplace_back(myUI.buttons[17]);
            myUI.activeButtons.emplace_back(myUI.buttons[18]);
            myUI.activeButtons.emplace_back(myUI.buttons[26]);
            break;
        case solvingState:
            myUI.activeButtons.emplace_back(myUI.buttons[19]);
            myUI.activeButtons.emplace_back(myUI.buttons[20]);
            myUI.activeButtons.emplace_back(myUI.buttons[27]);
            

            for (int i = 0; i < robotList.size(); i++)
            {
                if (robotList[i].second && robotList[i].first->gridPos != grid.startAndEndCords.second)
                {
                    robotList[i].first->movement(grid, deltaTime, renderList); 
                }
                if (myUI.loop && robotList[i].second && robotList[i].first->gridPos == grid.startAndEndCords.second)
                {
                    myUI.resumeloop = true;
                    myUI.buttonAction(font, state, 20, grid, robotList, solve);
                }
            }
            break;
        case solvedState:
            myUI.activeButtons.emplace_back(myUI.buttons[19]);
            
            break; 
        }
        for (int i = 0; i < renderList.size(); i++)
        {            
            renderList[i]->draw(&window);             
        }
        grid.display(&window);
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




