#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include <Images2.h>

using namespace std;

bool PacManCheck(sf::Sprite PacMan, sf::Image image, bool &LeftWallPos, bool &RigthWallPos, bool &UpWallPos, bool &DownWallPos) {


    const sf::Color wallcolor(33, 33, 255);

    int tempx = 0, tempy = 0, tempxx = 0, tempyy = 0,tempxxx = 0, tempyyy = 0,tempxxxx = 0, tempyyyy = 0;

    bool onceTrue = false;

    for (int a = 14; a > 0; a--) {
        for (int b = 14; b > 0; b--) {

            tempx = PacMan.getPosition().x+a;
            tempy = PacMan.getPosition().y+b;

            tempxx = PacMan.getPosition().x-a;
            tempyy = PacMan.getPosition().y-b;

            tempxxx = PacMan.getPosition().x+a;
            tempyyy = PacMan.getPosition().y-b;

            tempxxxx = PacMan.getPosition().x-a;
            tempyyyy = PacMan.getPosition().y+b;


            if (image.getPixel(tempx, tempy) == wallcolor) {


                if (image.getPixel(PacMan.getPosition().x+7, tempy) == wallcolor) {

                    DownWallPos = true;
                    UpWallPos = false;
                } else {

                    DownWallPos = false;

                }


                if (image.getPixel(tempx, PacMan.getPosition().y+7) == wallcolor) {

                    RigthWallPos = true;
                    LeftWallPos = false;
                } else {

                    RigthWallPos = false;

                }

                onceTrue = true;
            }

            if (image.getPixel(tempxx, tempyy) == wallcolor) {


                if (image.getPixel(PacMan.getPosition().x-7, tempyy) == wallcolor) {

                    UpWallPos = true;
                    DownWallPos = false;

                } else {
                    UpWallPos = false;
                }

                if (image.getPixel(tempxx, PacMan.getPosition().y-7) == wallcolor) {

                    LeftWallPos = true;
                    RigthWallPos = false;
                } else {
                    LeftWallPos = false;
                }

                onceTrue = true;

            }

            if (image.getPixel(tempxxx, tempyyy) == wallcolor) {

                if (image.getPixel(PacMan.getPosition().x+7, tempyyy) == wallcolor) {

                    UpWallPos = true;
                    DownWallPos = false;
                } else {
                    UpWallPos = false;
                }

                if (image.getPixel(tempxxx, PacMan.getPosition().y-7) == wallcolor) {

                    RigthWallPos = true;
                    LeftWallPos = false;

                } else {
                    RigthWallPos = false;
                }

                onceTrue = true;
            }


            if (image.getPixel(tempxxxx, tempyyyy) == wallcolor) {


                if (image.getPixel(PacMan.getPosition().x-7, tempyyyy) == wallcolor) {

                    DownWallPos = true;
                    UpWallPos = false;
                } else {
                    DownWallPos = false;
                }

                if (image.getPixel(tempxxxx, PacMan.getPosition().y+7) == wallcolor) {

                    LeftWallPos = true;
                    RigthWallPos = false;
                } else {
                    LeftWallPos = false;
                }

                onceTrue = true;
            }


            if(onceTrue == true) {

                return true;
            }

////////////
            /*
            //up
            if(image.getPixel(PacMan.getPosition().x+b, PacMan.getPosition().y-6) == wallcolor){

            UpWallPos = true;
            DownWallPos = false;
            onceTrue = true;
            }
            //down
            if(image.getPixel(PacMan.getPosition().x+b, PacMan.getPosition().y+6) == wallcolor){

            DownWallPos = true;
            UpWallPos = false;
             onceTrue = true;
            }
            //Left
            if(image.getPixel(PacMan.getPosition().x-6,PacMan.getPosition().y+b) == wallcolor){

            LeftWallPos = true;
            RigthWallPos = false;
            onceTrue = true;
            }
            //Right
            if(image.getPixel(PacMan.getPosition().x+6,PacMan.getPosition().y+b) == wallcolor){

            RigthWallPos = true;
            LeftWallPos = false;
             onceTrue = true;
            }

            if(onceTrue == true) {

                return true;
            }

            */
////////////
        }
    }

    return false;

}


bool RedAlienCheck(sf::Sprite RedGhost, sf::Image image, bool &REDLeftWallPos, bool &REDRigthWallPos, bool &REDUpWallPos, bool &REDDownWallPos) {


    const sf::Color wallcolor(33, 33, 255);

    int tempx = 0, tempy = 0, tempxx = 0, tempyy = 0,tempxxx = 0, tempyyy = 0,tempxxxx = 0, tempyyyy = 0;

    bool onceTrue = false;

    for (int a = 14; a > 0; a--) {
        for (int b = 14; b > 0; b--) {

            tempx = RedGhost.getPosition().x+a;
            tempy = RedGhost.getPosition().y+b;

            tempxx = RedGhost.getPosition().x-a;
            tempyy = RedGhost.getPosition().y-b;

            tempxxx = RedGhost.getPosition().x+a;
            tempyyy = RedGhost.getPosition().y-b;

            tempxxxx = RedGhost.getPosition().x-a;
            tempyyyy = RedGhost.getPosition().y+b;


            if (image.getPixel(tempx, tempy) == wallcolor) {


                if (image.getPixel(RedGhost.getPosition().x+7, tempy) == wallcolor) {

                    REDDownWallPos = true;
                    REDUpWallPos = false;
                } else {

                    REDDownWallPos = false;

                }


                if (image.getPixel(tempx, RedGhost.getPosition().y+7) == wallcolor) {

                    REDRigthWallPos = true;
                    REDLeftWallPos = false;
                } else {

                    REDRigthWallPos = false;

                }

                onceTrue = true;
            }

            if (image.getPixel(tempxx, tempyy) == wallcolor) {


                if (image.getPixel(RedGhost.getPosition().x-7, tempyy) == wallcolor) {

                    REDUpWallPos = true;
                    REDDownWallPos = false;

                } else {
                    REDUpWallPos = false;
                }

                if (image.getPixel(tempxx, RedGhost.getPosition().y-7) == wallcolor) {

                    REDLeftWallPos = true;
                    REDRigthWallPos = false;
                } else {
                    REDLeftWallPos = false;
                }

                onceTrue = true;

            }

            if (image.getPixel(tempxxx, tempyyy) == wallcolor) {

                if (image.getPixel(RedGhost.getPosition().x+7, tempyyy) == wallcolor) {

                    REDUpWallPos = true;
                    REDDownWallPos = false;
                } else {
                    REDUpWallPos = false;
                }

                if (image.getPixel(tempxxx, RedGhost.getPosition().y-7) == wallcolor) {

                    REDRigthWallPos = true;
                    REDLeftWallPos = false;

                } else {
                    REDRigthWallPos = false;
                }

                onceTrue = true;
            }


            if (image.getPixel(tempxxxx, tempyyyy) == wallcolor) {


                if (image.getPixel(RedGhost.getPosition().x-7, tempyyyy) == wallcolor) {

                    REDDownWallPos = true;
                    REDUpWallPos = false;
                } else {
                    REDDownWallPos = false;
                }

                if (image.getPixel(tempxxxx, RedGhost.getPosition().y+7) == wallcolor) {

                    REDLeftWallPos = true;
                    REDRigthWallPos = false;
                } else {
                    REDLeftWallPos = false;
                }

                onceTrue = true;
            }


            if(onceTrue == true) {

                return true;
            }

        }
    }

    return false;

}



int main() {

    int x = 0,y = 0;
    int RedX = 0, Redy = 0;
    int timer = 0;

    int stopTimer = 0;

    bool Left = false;
    bool Right = false;
    bool Up = false;
    bool Down = false;

    bool RedLeft = false;
    bool RedRight = false;
    bool RedUp = false;
    bool RedDown = false;

    bool LeftWallPos = false;
    bool RigthWallPos = false;
    bool UpWallPos = false;
    bool DownWallPos = false;

    bool REDLeftWallPos = false;
    bool REDRigthWallPos = false;
    bool REDUpWallPos = false;
    bool REDDownWallPos = false;




    int score = 0;

    sf::RenderWindow window(sf::VideoMode(522, 677), "Pac Man!");
    window.setFramerateLimit(60);



    sf::Image image;
    if (!image.loadFromFile("Assets/PacMan_background.png"))
        return 0;

    sf::Texture texture;

    if (!texture.loadFromImage(image))
        return 0;


    sf::Sprite Background;
    Background.setTexture(texture);
    Background.setPosition(sf::Vector2f(0, 0));


    sf::Texture texture2;
    if (!texture2.loadFromFile("Assets/PacMan_open.png"))
        return -1;

    sf::Texture texture3;
    if (!texture3.loadFromFile("Assets/PacMan_closed.png"))
        return -1;

    sf::Texture texture4;
    if (!texture4.loadFromFile("Assets/RedGhostRight.png"))
        return -1;


    sf::Sprite PacMan;
    PacMan.setTexture(texture2);
    PacMan.setPosition(sf::Vector2f(256, 326));
    PacMan.setOrigin(15,15);

    sf::Sprite RedGhost;
    RedGhost.setTexture(texture4);
    RedGhost.setPosition(sf::Vector2f(256, 256));
    RedGhost.setOrigin(15,15);




    std::vector<sf::RectangleShape> Dot(340);

    for (int i = 0; i < Dot.size(); i++) {
        Dot[i].setFillColor(sf::Color::White);
        Dot[i].setSize(sf::Vector2f(5, 5));
        Dot[i].setOrigin(2.5,2.5);
    }


    int tempx = 30;
    int tempy = 30;

    const sf::Color wallcolor(33, 33, 255);
    const sf::Color wallcolor2(1,0,0);

    for (int i = 0; i < Dot.size(); i++) {

        cout<<tempx<<endl;


        if (image.getPixel(tempx, tempy) != wallcolor &&image.getPixel(tempx, tempy) != wallcolor2 ) {

            Dot[i].setPosition(tempx,tempy);

        }

        tempx +=30;

        if(tempx == 270) {
            tempx = 263;
        }

        if(tempx == 383) {

            tempx =375;
        }


        if(tempx > 500) {

            tempy +=25;
            tempx = 30;

            if(tempy == 205) {
                tempy = 215;
            }

            if(tempy == 315) {

                tempy = 320;
            }

            if(tempy == 370) {

                tempy = 375;
            }
            if(tempy == 425) {

                tempy = 432;
            }

            if(tempy == 482) {

                tempy = 490;
            }

            if(tempy == 540) {

                tempy = 550;
            }
        }
    }



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {


                cout<<"mouse X = "<<sf::Mouse::getPosition(window).x<<" Mouse Y = "<<sf::Mouse::getPosition(window).y<<endl;

            }
        }

        PacManCheck(PacMan,image, LeftWallPos, RigthWallPos, UpWallPos, DownWallPos);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

            if(LeftWallPos == false) {
                PacMan.setRotation(-180);
                x = -2;
                y=0;

            } else {
                x = 0;

            }

            //  Left = true;
            //        Right = false;
            //      Up = false;
            //    Down = false;

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

            if(RigthWallPos == false) {
                PacMan.setRotation(0);
                x = 2;
                y=0;

            } else {
                x = 0;

            }

            // Left = false;
            //   Right = true;
            //   Up = false;
            //   Down = false;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

            if(UpWallPos == false) {
                PacMan.setRotation(-90);
                y= -2;
                x=0;


            } else {

                y = 0;
            }
            //  Left = false;
            //  Right = false;
            //  Up = true;
            //  Down = false;

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {



            if(DownWallPos == false) {
                PacMan.setRotation(90);
                y = 2;
                x=0;

            } else {

                y = 0;
            }

            //  Left = false;
            //  Right = false;
            //   Up = false;
            //   Down = true;

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

            x = 0;
            y = 0;
        }

        Left = false;
        Right = false;
        Up = false;
        Down = false;


        if(x == -2) {
            Left = true;

        }
        if(x == 2) {

            Right = true;
        }
        if(y == -2) {
            Up = true;

        }
        if(y == 2) {

            Down = true;
        }


        if(timer == 10) {

            PacMan.setTexture(texture3);

        }

        if(timer == 20) {

            PacMan.setTexture(texture2);
            timer = 0;

        }

        if(timer != 10 || timer !=20) {

            timer++;
        }



        if(PacManCheck(PacMan,image, LeftWallPos, RigthWallPos, UpWallPos, DownWallPos)) {



            if(UpWallPos == true && Up == true) {

                y = 0;
            }

            if (DownWallPos == true && Down == true) {

                y = 0;
            }

            if(LeftWallPos == true && Left == true) {

                x = 0;

            }

            if(RigthWallPos == true && Right == true) {
                x = 0;
            }

        } else {

            LeftWallPos = false;
            RigthWallPos = false;
            UpWallPos = false;
            DownWallPos = false;

        }


        if(UpWallPos == true) {
            cout<<"Wall is up"<<endl;
        }

        if(DownWallPos == true) {
            cout<<"Wall is down"<<endl;
        }

        if(RigthWallPos == true) {
            cout<<"Wall is Right"<<endl;
        }
        if(LeftWallPos == true) {
            cout<<"Wall is left"<<endl;
        }

///////////
//red alien stuff

        if(PacMan.getPosition().y >RedGhost.getPosition().y && REDDownWallPos == false) {

            RedDown = true;
            RedUp = false;

        }

        if(PacMan.getPosition().y <RedGhost.getPosition().y && REDUpWallPos == false) {

            RedUp = true;
            RedDown = false;
        }

        if(PacMan.getPosition().x >RedGhost.getPosition().x && REDRigthWallPos == false) {

            RedRight = true;
            RedLeft = false;

        }

        if(PacMan.getPosition().x <RedGhost.getPosition().x && REDLeftWallPos == false) {

            RedLeft = true;
            RedRight = false;
        }


        if(RedUp == true) {

            Redy = -1;
        } else {

            Redy = 1;
        }

        if(RedLeft == true) {
            RedX = -1;
        } else {
            RedX = 1;
        }



        if(PacManCheck(RedGhost,image, REDLeftWallPos, REDRigthWallPos, REDUpWallPos, REDDownWallPos)) {


            if(REDUpWallPos == true && RedUp == true) {

                Redy = 0;
            }

            if (REDDownWallPos == true && RedDown == true) {

                Redy = 0;
            }

            if(REDLeftWallPos == true && RedLeft == true) {

                RedX = 0;

            }

            if(REDRigthWallPos == true && RedRight == true) {
                RedX = 0;
            }


            cout<<"yup"<<endl;

        } else {
            REDLeftWallPos = false;
            REDRigthWallPos = false;
            REDUpWallPos = false;
            REDDownWallPos = false;

        }



////////

        if(PacMan.getPosition().x >510) {

            PacMan.setPosition(0,270);
        }

        if(PacMan.getPosition().x<0) {

            PacMan.setPosition(510,270);
        }


        for (int i = 0; i < Dot.size(); i++) {
            if(PacMan.getGlobalBounds().intersects(Dot[i].getGlobalBounds())) {

                Dot[i].setPosition(1000,1000);
                score ++;

            }
        }


        cout<<score<<endl;


        PacMan.move(x,y);
        RedGhost.move(RedX,Redy);


        window.clear();
        window.draw(Background);
        window.draw(PacMan);
        window.draw(RedGhost);

        for (int i = 0; i < Dot.size(); i++) {

            window.draw(Dot[i]);

        }

        // window.draw(map);
        window.display();
    }

    return 0;
}
