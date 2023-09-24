#pragma once


double distance(cordinates start, cordinates end);

std::vector<cordinates> pathSolvingAStar(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList);