#ifndef SCHEDULE_BOARD_CLASS_H
#define SCHEDULE_BOARD_CLASS_H

#include"Entity.h"
#include"Quad.h"
#include"TextManager.h"
#include"TextEntity.h"
#include"../libraries/include/nlohmann/json.hpp"

class ScheduleBoard : public Entity
{
    private:
        void initScheduleBoard(json &schedule);

    public:
        vec3 destination;
        static vec3 basePos;
        const static float quadWidth;
        const static float quadHeight;
        const static int boardWidth;
        const static int boardHeight;
        const static float spaceBetweenBoards;
        const static float spaceBetweenX;
        const static float spaceBetweenY;
        const static Quad::Axis boardAxis;

        ScheduleBoard(vec3 pos, json &schedule);
        vec3 getPosFormula(int date);
        void setDestination(vec3 destination);

        function <void(void)> getDefaultClassBehavior();

        static vec3 getUniqueColor(string s);

};
#endif