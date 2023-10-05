#include "Header.h"

std::vector<std::shared_ptr<Object>> renderList;
std::vector<cordinates> expressedwallMap;

std::vector<cordinates> path;
int sizeX = 30;
int sizeY = 30;

#define generateState 0
#define solveState 1
#define solvedState 2
int state = 0;

microTime currentTime;
microTime lastTime;
microTime deltaTime;
sf::Mouse myMouse;

int main()
{
    QueryPerformanceFrequency(&frequency);
    lastTime = getMicroTime();
    srand((unsigned int)getMicroTime());
    UI myUI(renderList);
    Grid grid(sizeX, sizeY);
    grid.setup(renderList);


    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mazes!");

    grid.recursiveBacktrackingMaze();
    //grid.primsMaze();


    std::shared_ptr<BaseRobot> robot0 = std::make_shared<BaseRobot>(grid);
    renderList.emplace_back(robot0);
    std::shared_ptr<Robot0> robot1 = std::make_shared<Robot0>(grid);
    renderList.emplace_back(robot1);

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
        //
        switch (state)
        {
        case generateState:
            
            if (grid.removeWalls(deltaTime))
            {                
                state++;
            } 
            //if (grid.devRemoveWalls())
            //{
            //    state++;
            //}
            
            break;
        case solveState:
            
            if (robot0->gridPos != grid.startAndEndCords.second)
            {
                robot0->movement(grid, deltaTime);
            }            
            if (robot1->gridPos != grid.startAndEndCords.second)
            {
                robot1->movement(grid, deltaTime);
            }
            else
            {
               pathSolvingAStar(grid, renderList);
               state++;
            }

            break;
        case solvedState:
            
            
            break;


        }
        //
        for (int i = 0; i < renderList.size(); i++)
        {
            renderList[i]->draw(&window);
        }
        //
        window.display();
        lastTime = currentTime;
    }
    return 0;
}




