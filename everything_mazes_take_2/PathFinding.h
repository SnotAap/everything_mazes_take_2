#pragma once


double distance(cordinates start, cordinates end);

std::vector<cordinates> pathSolvingAStar(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList);

std::map<cordinates, std::shared_ptr<Node>> setupNodes(Grid& grid, std::map<cordinates, int>& floodedMaze, std::list<std::shared_ptr<Node>>& queue);

bool pathSolvingFloodFill(sf::Font& font, std::map<cordinates, std::shared_ptr<Node>>& nodes, std::map<cordinates, int>& floodedMaze, int& depth, std::vector<std::shared_ptr<Node>>& toBeRemoved, std::vector<std::shared_ptr<Node>>& toBeAdded, Grid& grid, std::list<std::shared_ptr<Node>>& queue);
