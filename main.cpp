#include "Header.h"
#include "Backround.h"
#include "Tube.h"
#include <time.h>
#include "ground.h"
#include "Score.h"

//Names: Jonathan Banos, Jiwoo Kim, Jason Mai, Aydan Armstrong
//class: Cpts 122 summer session, PA 8
//Data: 7/30/2021
//Desc: This is a flappy bird game where the goal of the game is to press space and move the tube in between the tubes and not touch them


int main(){
    //this starts the window to render and added a title
   sf::RenderWindow window(sf::VideoMode(500, 500), "Flappy Bird Game!");
   //This sets up the textures in order to call the sprites to be able to put textures int he sprites
   sf::Texture flapTexture;
   sf::Texture backroundTexture;
   //This loads the image from a file
   flapTexture.loadFromFile("flap.png");
   backroundTexture.loadFromFile("flappyBirdBackround.png");
   //This will get the size of the backwound and window
   sf::Vector2u TextureSize = backroundTexture.getSize();
   sf::Vector2u windowSize = window.getSize();
   //we set bird and backround here
   Bird flapSprite(flapTexture);
   Backround backroundSprite(backroundTexture);
   //This helps determine the numbers we need to set up the backround 
   float scaleX = (float)windowSize.x / TextureSize.x;
   float scaleY = (float)windowSize.y / TextureSize.y;
   //This scales the bird to a certain size
   flapSprite.setScale(.125,.125);
   srand((unsigned int)time(nullptr));
   //we scale the backround to fit the window
   backroundSprite.setScale(scaleX, scaleY);
   //we set the initial position of the bird
   flapSprite.setPosition(window.getSize().x/6, window.getSize().y/5);
   
   //we call the textrure for the ground and load it from a file
   	sf::Texture grassTexture;
	grassTexture.loadFromFile("flappyBirdGround.png");
    
    //we set the textures and load the images into the pipe sprite
    vector<Pipe*>pipes;
    sf::Texture upperPipeTxt;
    sf::Texture upperPipetxt2;
    sf::Texture upperPipeTxt3;

    upperPipeTxt.loadFromFile("flappyBirdPipe.png");
    upperPipetxt2.loadFromFile("flappyBirdPipe.png");
    upperPipeTxt3.loadFromFile("flappyBirdPipe.png");

    Pipe UpperSprite(upperPipeTxt);
    Pipe UpperSprite2(upperPipetxt2);
    Pipe UpperSprite3(upperPipeTxt3);

    sf::Texture lowerPipeTxt;
    sf::Texture lowerPipe2;
    sf::Texture lowerPipe3;

    lowerPipeTxt.loadFromFile("flappyBirdPipe.png");
    Pipe LowerSprite(lowerPipeTxt);

    lowerPipe2.loadFromFile("flappyBirdPipe.png");
    Pipe LowerSprite2(lowerPipe2);

    lowerPipe3.loadFromFile("flappyBirdPipe.png");
    Pipe LowerSprite3(lowerPipe3);


    //we make clock functions to help us place pipes at a certain time
    sf::Clock* pipegenerationClock;
    sf::Clock* pipegerationClock2;
    sf::Clock* pipergenrationClock3;

    //we set the clock variables to new
    pipegenerationClock = new sf::Clock;
    pipegerationClock2 = new sf::Clock;
    pipergenrationClock3 = new sf::Clock;


    //we set the x where the pipes will be and y axis to change the pipes around
    float xaxis = (float)(window.getSize().x + upperPipeTxt.getSize().x);
    float yaxis = 100.0f + (float)(rand() % 5 - 3) * 25;

   //These repeated functions allows us to use the textures again
    UpperSprite.setRepeated(true);
    LowerSprite.setRepeated(true);



    //we scale and position the pipes all over, we have three becuase they pop up three at a time
    UpperSprite.setScale(.23, 1);

    UpperSprite.setPosition(350, yaxis +70);

    LowerSprite.setScale(.23, .6);
    LowerSprite.setPosition(290, yaxis +120);

    UpperSprite.setRotation(180);

    UpperSprite.setRepeated(true);
    LowerSprite.setRepeated(true);


    UpperSprite2.setScale(.2, 1);

    UpperSprite2.setPosition(540, yaxis +105);

    LowerSprite2.setScale(.2, 1.1);
    LowerSprite2.setPosition(485, yaxis + 140);

    UpperSprite2.setRotation(180);


    UpperSprite2.setRepeated(true);
    LowerSprite2.setRepeated(true);

    UpperSprite3.setScale(.4, 1);

    UpperSprite3.setPosition(830, yaxis + 185);

    LowerSprite3.setScale(.4, 1.1);

    LowerSprite3.setPosition(730, yaxis + 200);

    UpperSprite3.setRotation(180);

    //we repeat the teextures again
    UpperSprite3.setRepeated(true);
    LowerSprite3.setRepeated(true);
	grassTexture.setRepeated(true);

	//we intialize the ground to be able to look like it's moving
    Ground ground;
	ground.setTexture(&grassTexture);
	
    ground.setPosition(window.getSize().x/6, window.getSize().y/5+ 350);
    float grasszoom = 988 / 80;
	float grassWidth = 3227 / grasszoom;
	float coefgrasswidth = 500 * 2 / grassWidth;

	ground.setTextureRect(sf::IntRect(0, 0, 3227 * coefgrasswidth, 2000));
    
   //have some variables to help control the birds movement
    //The ground height is also used to make the bird not fall bellow the ground
   int groundHeight = window.getSize().y / 5;
   const float gravitySpeed = .14;
   const float pipeSpeed = 1;
   bool isJumping = false;
   sf::Clock time;
   //we use the font class to create fonts in order to make a start screen
   Font startFont;
   Font startFont2;
   startFont.loadFromFile("flappyBirdStartFont.ttf");
   startFont2.loadFromFile("flappyBirdStartFont.ttf");
   sf::Text startText;
   sf::Text startText2;
   //this sets the font to what we loaded in the image
   startText.setFont(startFont);
   //This changes the sieze of the characters
   startText.setCharacterSize(20);
   startText.setString("PRESS SPACE");
   startText.setPosition(scaleX + 90, scaleY +10);
   startText2.setFont(startFont2);
   startText2.setCharacterSize(20);
   startText2.setString("TO START");
   startText2.setPosition(scaleX + 130, scaleY + 40);
   //We used the standard sfml starter for main 
   //this while loop only runs while the compiler is open
   while (window.isOpen())
   {
       sf::Event event;
       //I set a movespeed
       const float moveSpeed = .14;
       //This if statement is saying that whenever we press the space the following things get called
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
           //this moves the bird and makes it go up when you jump
           flapSprite.move(0, -moveSpeed);
           flapSprite.setRotation(-20);
           isJumping = true;
           time.restart();
           //moves the text out of the window so when you press start in the game it disapears which makes a start screen
           startText.setPosition(600, 600);
           startText2.setPosition(600, 600);
           groundHeight = 398;
       }
       //this is randomize the y axis in while loop
       xaxis = (float)(window.getSize().x + upperPipeTxt.getSize().x);
        yaxis = 100.f + (float)(rand() % 5 - 3) * 25;
        //we repeat the textures
       UpperSprite.setRepeated(true);
       LowerSprite.setRepeated(true);
       //we make it move this creates the speed in which they come into the screen
       UpperSprite.move(sf::Vector2f(-.07, 0));
       LowerSprite.move(sf::Vector2f(-.07, 0));


       UpperSprite2.setRepeated(true);
       LowerSprite2.setRepeated(true);

       UpperSprite2.move(sf::Vector2f(-.07, 0));
       LowerSprite2.move(sf::Vector2f(-.07, 0));

       UpperSprite2.setRepeated(true);
       LowerSprite2.setRepeated(true);

       UpperSprite3.setRepeated(true);
       LowerSprite3.setRepeated(true);

       UpperSprite3.move(sf::Vector2f(-.07, 0));
       LowerSprite3.move(sf::Vector2f(-.07, 0));
       
       UpperSprite3.setRepeated(true);
       LowerSprite3.setRepeated(true);
       //This is an event while loop so it baiclly creates the if button released function and if window is closed then it stops
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
     
           if (sf::Event::KeyReleased) {
               flapSprite.setRotation(12);
               isJumping = false;
          }

       }

       //this makes the bird move down which is the gravity 
       if (flapSprite.getPosition().y < groundHeight && isJumping == false) {
           flapSprite.move({ 0, gravitySpeed });
       }
       //this gets sets the poition to the bottom
       if (ground.getPosition().x < -500)
		{
			ground.setPosition(0, ground.getPosition().y);
		}
       //This controls how the ground moves
        ground.move(-1, 0);

        //This is making new pipes every 3 seconds and then restarting the time so it could be every 3 secs
        //also scales and positions them
        if (pipegenerationClock->getElapsedTime().asSeconds() > 3)
        {
            pipegenerationClock->restart();
            UpperSprite.setScale(.13, 1);

            UpperSprite.setPosition(410, yaxis + 20);

            LowerSprite.setScale(.13, .9);
            LowerSprite.setPosition(370, yaxis + 50);

            UpperSprite.setRotation(180);


        }
        if (pipegerationClock2->getElapsedTime().asSeconds() > 3)
        {
            pipegerationClock2->restart();

            UpperSprite2.setScale(.2, 1);

            UpperSprite2.setPosition(640, yaxis + 80);

            LowerSprite2.setScale(.2, 1.1);
            LowerSprite2.setPosition(585, yaxis + 140);

            UpperSprite2.setRotation(180);

        }
        if (pipergenrationClock3->getElapsedTime().asSeconds() > 3)
        {
            pipergenrationClock3->restart();

            UpperSprite3.setScale(.3, 1);

            UpperSprite3.setPosition(850, yaxis + 130);

            LowerSprite3.setScale(.3, 1.1);

            LowerSprite3.setPosition(768, yaxis + 130);

            UpperSprite3.setRotation(180);

        }
        //This makes it so the bird cant go over the top of the window
        if (flapSprite.getPosition().y < 0.f) {
            flapSprite.setPosition(flapSprite.getPosition().x, 0.f);
        }

        //this clears the window and draws everything into a window
       window.clear();
       window.draw(backroundSprite);
       window.draw(startText);
       window.draw(startText2);
       window.draw(ground);
       window.draw(flapSprite);
       window.draw(UpperSprite);
       window.draw(LowerSprite);
       window.draw(UpperSprite2);
       window.draw(LowerSprite2);
       window.draw(UpperSprite3);
       window.draw(LowerSprite3);
       window.draw(ground);
        //this displays the window
       window.display();
   }
   return 0;
}


