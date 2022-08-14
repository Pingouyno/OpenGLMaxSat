#include"../headers/World.h"

World::World()
{
	this->player = new Player(glm::vec3(0.0f, 0.0f, 0.2f));
	this->camera = this->player->camera;
    setupEntities();
    setup3DShapes();
	this->score = 0;

    //Pour blend les endroits vides des png
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    this->gameOverlay = new GameOverlay(camera);
    this->menuOverlay = new MenuOverlay(camera);
}

//mettre à jour différentes choses du monde, dépendamment des globales
void World::updateWorld()
{
	//render seulement le board actif
	int activeIndex = activeBoardNum % entityBoards.size();
	for (int i = 0 ; i < entityBoards.size(); i++)
	{
		if (i == activeIndex) entityBoards[i]->active = true;
		else entityBoards[i]->active = false;
	}
}

void World::doEntityBehaviors()
{
	for (Entity* ptrEntity : entities)
	{
		if (ptrEntity->active)
		{
			ptrEntity->doBehavior();
		}
	}
}

void World::render()
{
    glEnable(GL_DEPTH_TEST);
	//glDisable(GL_BLEND);         //TODO: remettre potentiellement
	renderActive3DShapes();
	renderActiveEntities();

    shaderProgram2D -> Activate();
    glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

	World::renderOverlays();

    shouldReloadArrays = false;
}


//Render toutes les entités, et désactive "newShapeCreated"
void World::renderActive3DShapes()
{
    for (Shape* ptrShape : shapes)
    {
        if ((*ptrShape).active)
        {
            (*ptrShape).render();
        }
    }
}

void World::renderActiveEntities()
{
	for (Entity* ptrEntity : entities)
    {
        if (ptrEntity->active)
        {
            ptrEntity->render();
        }
    }
}

void World::renderOverlays()
{
    gameOverlay->render();
    if (worldState == WorldState::MENU)
	{
		menuOverlay->render();
	}
}

void World::checkCameraCollidingAnyOverlay(glm::vec3 &mousePos)
{
    if (worldState == MENU)
	{
		menuOverlay->checkCollisions(mousePos);
	}
}

vector<int> World::checkCameraCollidingAnyShape(glm::vec3 &oldPos, glm::vec3 &newPos)
{
    vector<int> collisionLog({0, 0, 0});
    for (Shape* ptrShape : shapes)
    {
        if ((*ptrShape).active && (*ptrShape).isColliding(newPos))
            (*ptrShape).reportCollision(collisionLog, oldPos, newPos);
    }
    return collisionLog;
}

bool World::isAnyColliding(vector<int> &collisionLog)
{
    return collisionLog[0] != 0 || collisionLog[1] != 0 || collisionLog[2] != 0;
}

void World::addShape(Shape* shape)
{   
    shapes.push_back(shape);    
}


void World::deleteAllShapes()
{
	//supprimer les formes
    int i = shapes.size() - 1;
    while(i >= 0)
    {
        shapes.erase(shapes.begin() + i);
        i--;
    }
    vertices.clear();
    indices.clear();
    shouldReloadArrays = true;
}


//fonctions reliées à la logique de monde dynamique_____________________________________


//fin fonctions dynamiques______________________________________________________________

//méthodes privées

void World::setupEntities()
{
	vec3 pos(-30, 0, -30);

	//addShape(new Quad(pos + vec3(7 * (ScheduleBoard::spaceBetweenBoards + ScheduleBoard::boardWidth*ScheduleBoard::quadWidth)/2.0f, ScheduleBoard::spaceBetweenBoards, 0), TextManager::getTextTexture("professors"), 10, ScheduleBoard::boardAxis));

	for (auto schedule : satJson["Schedule"])
	{
		entityBoards.push_back(new ScheduleBoard(pos, schedule));
		//pos.x += ScheduleBoard::quadWidth * ScheduleBoard::boardWidth + ScheduleBoard::spaceBetweenBoards;
	}
	entities.insert(entities.end(), entityBoards.begin(), entityBoards.end());	
}

void World::setup3DShapes()
{

}