#include "Header.h"

std::vector<std::shared_ptr<Object>> renderList;
std::vector<cordinates> expressedwallMap;

//test

std::map<cordinates, int> floodedMaze;
int depth = -1;
std::vector<std::shared_ptr<Node>> toBeRemoved;
std::vector<std::shared_ptr<Node>> toBeAdded;
std::list<std::shared_ptr<Node>> queue;
std::map<cordinates, std::shared_ptr<Node>> nodes;

//

std::vector<cordinates> path;
int sizeX = 20;
int sizeY = 20;

#define generateState 0
#define solveState 1
#define solvedState 2
#define filledState 3
int state = 0;

microTime currentTime;
microTime lastTime;
microTime deltaTime;
sf::Mouse myMouse;
sf::Font font;


int main()
{
    QueryPerformanceFrequency(&frequency);
    lastTime = getMicroTime();
    srand((unsigned int)getMicroTime());
    if (!font.loadFromFile("..\\content\\arial.ttf"))
    {

    }
    UI myUI(renderList);
    Grid grid(sizeX, sizeY);
    grid.setup(renderList);


    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mazes!");

    //grid.recursiveBacktrackingMaze();
    grid.primsMaze();
    

    //std::shared_ptr<Robot> robot = std::make_shared<Robot>(grid);
    //renderList.emplace_back(robot);
    //std::shared_ptr<Robot0> robot0 = std::make_shared<Robot0>(grid);
    //renderList.emplace_back(robot0);
    std::shared_ptr<Robot1> robot1 = std::make_shared<Robot1>(grid, font, renderList);
    renderList.emplace_back(robot1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {            
            myUI.checkButtonsPressed(myMouse, event);            
            if (event.type == sf::Event::Closed)
                window.close();
        }        
        window.clear(sf::Color::White);
        //
        currentTime = getMicroTime();
        deltaTime = currentTime - lastTime;
        myUI.checkButtonsHoverd(myMouse);                 
        //
        switch (state)
        {
        case generateState:
            
            //if (grid.removeWalls(deltaTime))
            //{        
            //    nodes = setupNodes(grid, floodedMaze, queue);
            //    state+=2;
            //} 
            if (grid.devRemoveWalls())
            {
                nodes = setupNodes(grid, floodedMaze, queue);
                state++;
            }
 
            
            break;
        case solveState:
            //
            //if (robot->gridPos != grid.startAndEndCords.second)
            //{
            //    robot->movement(grid, deltaTime);
            //}            
            //if (robot0->gridPos != grid.startAndEndCords.second)
            //{
            //    robot0->movement(grid, deltaTime);
            //}
            
            if (robot1->gridPos != grid.startAndEndCords.second)
            {
                robot1->movement(grid, deltaTime, renderList);
            }
            else
            {
               pathSolvingAStar(grid, renderList);
               state++;
            }

            break;
        case solvedState:
         
            break;
        case filledState:

            break;
        }
        //
        for (int i = 0; i < renderList.size(); i++)
        {
            renderList[i]->draw(&window);
        }
        for (int i = 0; i < grid.depthList.size(); i++)
        {
            grid.depthList[i]->draw(&window);
        }
        //
        window.display();
        lastTime = currentTime;
    }
    return 0;
}




