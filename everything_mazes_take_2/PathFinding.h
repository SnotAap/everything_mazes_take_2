#pragma once


double distance(cordinates start, cordinates end);
//^ a function to calculate the distance between to cordinates

std::vector<cordinates> pathSolvingAStar(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList);
//^ a algorithm which solves a maze using the A* algorithm

std::map<cordinates, std::shared_ptr<Node>> setupNodes(Grid& grid, std::map<cordinates, int>& floodedMaze, std::list<std::shared_ptr<Node>>& queue);
//^ a function which sets up nodes required for the flood fill algorithm

bool pathSolvingFloodFill(sf::Font& font, std::map<cordinates, std::shared_ptr<Node>>& nodes, std::map<cordinates, int>& floodedMaze, int& depth, std::vector<std::shared_ptr<Node>>& toBeRemoved, std::vector<std::shared_ptr<Node>>& toBeAdded, Grid& grid, std::list<std::shared_ptr<Node>>& queue);
//^ a function which runs a single set op a floodfill algorithm every time it gets executed