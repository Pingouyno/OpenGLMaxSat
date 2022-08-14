#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H

#include<vector>
using namespace std;

#include"shaderClass.h"

#include"../libraries/include/nlohmann/json.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

enum WorldState : int {GAME = 0, MENU = 1};
enum GameMode : int {SURVIVAL = 0, CREATIVE = 1};

extern int activeBoardNum;

// Vertices coordinates
extern std::vector<float> vertices;
extern std::vector<int> indices;

extern json satJson;
extern const int LAB_SIZE;
extern vector<int> labyrinth;
extern bool shouldReloadArrays;
extern Shader* shaderProgram2D;
extern Shader* shaderProgram3D;
extern float screenWidth;
extern float screenHeight;
extern WorldState worldState;
extern GameMode gameMode;

#endif