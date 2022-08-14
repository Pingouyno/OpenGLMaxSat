#include"../headers/MenuOverlay.h"

//la classe parent contient déjà toutes les instructions nécessaires
MenuOverlay::MenuOverlay(Camera* camera) : Overlay(camera){
	setupOverlay();
}


void MenuOverlay::setupOverlay()
{
	Texture* up_png = Texture::get2DImgTexture("up.png");
    Texture* down_png = Texture::get2DImgTexture("down.png");
	Texture* square_png = Texture::get2DImgTexture("square.png");

	//background noir
	addStaticShape(new Quad2D(glm::vec3(-1.0f, -1.0f, 0.0f), screenWidth, screenHeight, square_png));

	//Bouton créatif, on veut que la texture fasse 128 pixels de large peu importe les dimensions de l'écran
	float pixelSize = 128.0f; 
	Quad2D* upButton = new Quad2D(vec2(0.6f, 0.1f), pixelSize, pixelSize, up_png);
	Quad2D* downButton = new Quad2D(vec2(0.6f, - (0.1f + Shape::toYRatio(pixelSize))), pixelSize, pixelSize, down_png);
	
	upButton->clickLogic = [this, upButton, downButton](){activeBoardNum++;};
	downButton->clickLogic = [this, upButton, downButton](){activeBoardNum--;};

	addClickShape(upButton);
	addClickShape(downButton);
}
