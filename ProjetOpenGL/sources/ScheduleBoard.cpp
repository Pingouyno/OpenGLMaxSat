#include"../headers/ScheduleBoard.h"

vec3 ScheduleBoard::basePos = vec3(0, 0, 0);
const float ScheduleBoard::quadWidth = 4.0f;
const float ScheduleBoard::quadHeight = 1.0f;
const int ScheduleBoard::boardWidth = 5;
const int ScheduleBoard::boardHeight = 20;
const float ScheduleBoard::spaceBetweenBoards = 6.0f;
const float ScheduleBoard::spaceBetweenX = 0.5f;
const float ScheduleBoard::spaceBetweenY = 0.1f;
const Quad::Axis ScheduleBoard::boardAxis = Quad::Axis::Z;

void ScheduleBoard::initScheduleBoard(json &schedule)
{
    Shape* teacherShape = new Quad(getPos() + vec3(3, 1, 0), TextManager::getTextTexture("teacher"), 9, Quad::Axis::Z);
    addShape(teacherShape);
    string teacherName = (string)schedule["Teacher"];
    int teacherNum = teacherName[teacherName.length() - 1] - '0';
    addShape(new Quad(teacherShape->pos + vec3(teacherShape->width/2, 0, 0.03f), TextManager::getNumberTexture(teacherNum), 1, Quad::Axis::Z));
    vector<int> occupiedIndices = {};

    for (auto event : schedule["events"])
    {
        for (auto dates : event)
        {
            vec3 uniqueColor = getUniqueColor(event.begin().key());

            for (int date : dates)
            {
                addShape(new Quad(getPosFormula(date), quadWidth, quadHeight, uniqueColor, Quad::Axis::Z));
                addEntity(new TextEntity(getPosFormula(date) + vec3(0, 0, 0.1f), quadWidth, event.begin().key()));
                occupiedIndices.push_back(date);
            }
        }
    
    }

    for (int date = 0; date < boardHeight * boardWidth ; date++)
    {
        if (std::find(occupiedIndices.begin(), occupiedIndices.end(), date) == occupiedIndices.end())
        {
            addShape(new Quad(getPosFormula(date), quadWidth, quadHeight, vec3(0, 0, 0), Quad::Axis::Z));
        }
    }
}

ScheduleBoard::ScheduleBoard(vec3 pos, json &schedule) : Entity(pos)
{
    //insérer le titre du professeur
    ScheduleBoard::basePos = pos;
    setDestination(pos);

    initScheduleBoard(schedule);
}

vec3 ScheduleBoard::getPosFormula(int date)
{
    return getPos() + vec3((date / boardHeight) * (quadWidth + spaceBetweenX), -(date % boardHeight + 1) * (quadHeight + spaceBetweenY), 0);
}

void ScheduleBoard::setDestination(vec3 destination)
{
    this->destination = destination;
    setBehavior(getDefaultClassBehavior());
}

function <void(void)> ScheduleBoard::getDefaultClassBehavior()
{
    const vec3 nextPos = vec3((this->destination - this->getPos()) / 60.0f);
    int* num = new int[1]{0};
    int* cpt = &num[0];

    return [this, cpt, nextPos]()
    {
        if (*cpt < 60)
        {
            this->moveTo(this->getPos() + nextPos);
        }
        *cpt += 1;
    };  
}

vec3 ScheduleBoard::getUniqueColor(string s)
{
    if (s.length() < 9)
    {
        cout << "\n\n**ERREUR : ScheduleBoard::getUniqueColor() - longueur < 9!**\n\n";
        throw 1;
    }
    string hash = to_string(std::hash<std::string>()(s));

    float r = (100 + std::stoi(hash.substr(0, 3)) % 156) / 256.0f;
    float g = (100 + std::stoi(hash.substr(3, 6)) % 156) / 256.0f;
    float b = (100 + std::stoi(hash.substr(6, 9)) % 156) / 256.0f;

    return vec3(r, g, b);
}
