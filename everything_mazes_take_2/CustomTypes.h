#pragma once

typedef std::pair<int, int> cordinates;
typedef std::shared_ptr<Wall> walls[4];

typedef __int64 microTime;

microTime getMicroTime();
extern LARGE_INTEGER frequency;


#define North 0
#define East 1
#define South 2
#define West 3