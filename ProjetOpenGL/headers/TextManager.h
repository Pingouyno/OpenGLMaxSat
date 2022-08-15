#ifndef TEXTMANAGER_CLASS_H
#define TEXTMANAGER_CLASS_H

#include<string>
#include<vector>
using namespace std;

#include"Texture.h"
#include"shaderClass.h"
#include"Globals.h"

//regader : https://seotoolscentre.com/text-to-image-generator

class TextManager
{
    private:
        static string TEXT_PATH;
        static vector<Texture*> numbers2D;
    
    public:
        static void initTextures();
        static void init();
        static Texture* getNumberTexture(int number);
        static Texture* getTextTexture(string textFileName);
        static Texture* getTextTexture(char character);
};
#endif