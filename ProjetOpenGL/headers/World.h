#ifndef WORLD_CLASS_H
#define WORLD_CLASS_H

#include<string>
#include<vector>
using namespace std;

#include"Globals.h"
#include"Shape.h"
#include"Quad.h"
#include"Cube.h"
#include"shaderClass.h"
#include"Entity.h"
#include"Snowman.h"
#include"Camera.h"
#include"Player.h"
#include"GameOverlay.h"
#include"MenuOverlay.h"
#include"ScheduleBoard.h"

class World
{
    //variables statiques
    private:
        vector<Entity*> entities; 

        vector<Entity*> entityBoards;

        vector<Shape*> shapes;

    public:
        Player* player;
        Camera* camera;
        GameOverlay* gameOverlay;
        MenuOverlay* menuOverlay;

        World();

        void updateWorld();
        void doEntityBehaviors();
        void render();
        void renderActive3DShapes();
        void renderActiveEntities();
        void renderOverlays();
        void checkCameraCollidingAnyOverlay(glm::vec3 &mousePos);
        vector<int> checkCameraCollidingAnyShape(glm::vec3 &oldPos, glm::vec3 &newPos);
        bool isAnyColliding(vector<int> &collisionLog);
        void addShape(Shape* shape);
        void deleteAllShapes();

    //méthodes pour initialiser le monde
    private:
        void setupEntities();
        void setup3DShapes();

};
#endif