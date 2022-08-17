#include"../headers/TextManager.h"

string TextManager::TEXT_PATH = "ProjetOpenGL/resources/textSamples/";
vector<Texture*> TextManager::numbers2D({});

void TextManager::initTextures()
{
    for (int i = 0 ; i < 10 ; i++)
    {
        string s = (TEXT_PATH + "text_" + to_string(i) + ".png");
        Texture* number_png = new Texture(s.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
        number_png->texUnit(*shaderProgram2D, "tex0", 0);
        numbers2D.push_back(number_png);
    }
}

void TextManager::init()
{
    initTextures();
}

Texture* TextManager::getNumberTexture(int number)
{
    return numbers2D[number]; 
}

Texture* TextManager::getTextTexture(string textFileName)
{
    if (textFileName.length() == 1) return getTextTexture(textFileName[0]);

    string s = (TEXT_PATH + "text_" + textFileName + ".png");
    Texture* text_png = new Texture(s.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    text_png->texUnit(*shaderProgram2D, "tex0", 0);
    return text_png;
}

Texture* TextManager::getTextTexture(char character)
{
    //TODO : remplacer par de VRAIES lettres
    if (character >= 'a' && character <= 'z') character = character - ('a' - 'A');

    string s = (TEXT_PATH + "text_" + character + ".png");
    Texture* text_png = new Texture(s.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    text_png->texUnit(*shaderProgram2D, "tex0", 0);
    return text_png;
}