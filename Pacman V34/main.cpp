#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <ctime>
#include <chrono>
#include <vector>
#include <sstream>
#include <fstream>

#include "Images.h"

using namespace std;

// if want console, R-click project, properties, build target, release, type: GUI -> type: console


struct near {

    int Pac;
    int Red,Orange,Pink,Blue;

};
near Close;

struct Difference {

    std::vector< int > Pac_X, Pac_Y;
    std::vector< int > Red_X, Red_Y;
    std::vector< int > Orange_X, Orange_Y;
    std::vector< int > Pink_X, Pink_Y;
    std::vector< int > Blue_X, Blue_Y;

};
Difference Diff;

struct edible {

    bool red = false;
    bool orange = false;
    bool pink = false;
    bool blue = false;

};
edible ised;

struct ghosteyes {

    bool red = false;
    bool orange = false;
    bool pink = false;
    bool blue = false;

};
ghosteyes Deadmove;


struct WhereWall {

    bool LeftWallPos = false;
    bool RigthWallPos = false;
    bool UpWallPos = false;
    bool DownWallPos = false;

};
WhereWall Red;
WhereWall Orange;
WhereWall Blue;
WhereWall Pink;

#define Bry_Cherry 0,0,13,13
#define Bry_Strawberry 16,0,13,13
#define Bry_Peach 32,0,13,13
#define Bry_Apple 48,0,13,13
#define Bry_Lime 65,0,13,13
#define Bry_Spear 80,0,11,13
#define Bry_Bell 96,0,12,13
#define Bry_Key 114,0,7,13

#define Pac_wack1 0,2,13,9
#define Pac_wack2 15,3,15,8
#define Pac_wack3 31,5,15,6
#define Pac_wack4 47,6,15,5
#define Pac_wack5 63,7,15,5
#define Pac_wack6 79,7,15,6
#define Pac_wack7 96,8,13,6
#define Pac_wack8 114,7,9,7
#define Pac_wack9 132,7,5,7
#define Pac_wack10 150,7,1,5
#define Pac_wack11 161,5,11,11


// Pacman
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

        }
    }

    return false;

}


void PacManKeyInput(sf::Sprite &PacMan, sf::Image image, bool &LeftWallPos, bool &RigthWallPos, bool &UpWallPos, bool &DownWallPos, int &x, int &y) {


    bool Left = false;
    bool Right = false;
    bool Up = false;
    bool Down = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        if(LeftWallPos == false) {
            PacMan.setRotation(-180);
            x = -2;
            y = 0;

        } else {
            x = 0;
        }

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        if(RigthWallPos == false) {
            PacMan.setRotation(0);
            x = 2;
            y=0;

        } else {
            x = 0;
        }

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

        if(UpWallPos == false) {
            PacMan.setRotation(-90);
            y = -2;
            x = 0;

        } else {
            y = 0;
        }

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

        if(DownWallPos == false) {
            PacMan.setRotation(90);
            y = 2;
            x = 0;

        } else {
            y = 0;
        }
    }




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


}


//Orange
bool OrangeghostCheck(sf::Sprite OrangeGhost, sf::Image image, WhereWall &Orange) {


    const sf::Color wallcolor(33, 33, 255);

    int tempx = 0, tempy = 0, tempxx = 0, tempyy = 0,tempxxx = 0, tempyyy = 0,tempxxxx = 0, tempyyyy = 0;

    bool onceTrue = false;

    for (int a = 14; a > 0; a--) {
        for (int b = 14; b > 0; b--) {

            tempx = OrangeGhost.getPosition().x+a;
            tempy = OrangeGhost.getPosition().y+b;

            tempxx = OrangeGhost.getPosition().x-a;
            tempyy = OrangeGhost.getPosition().y-b;

            tempxxx = OrangeGhost.getPosition().x+a;
            tempyyy = OrangeGhost.getPosition().y-b;

            tempxxxx = OrangeGhost.getPosition().x-a;
            tempyyyy = OrangeGhost.getPosition().y+b;


            if (image.getPixel(tempx, tempy) == wallcolor) {


                if (image.getPixel(OrangeGhost.getPosition().x+7, tempy) == wallcolor) {

                    Orange.DownWallPos = true;
                    Orange.UpWallPos = false;
                } else {

                    Orange.DownWallPos = false;

                }


                if (image.getPixel(tempx, OrangeGhost.getPosition().y+7) == wallcolor) {

                    Orange.RigthWallPos = true;
                    Orange.LeftWallPos = false;
                } else {

                    Orange.RigthWallPos = false;

                }

                onceTrue = true;
            }

            if (image.getPixel(tempxx, tempyy) == wallcolor) {


                if (image.getPixel(OrangeGhost.getPosition().x-7, tempyy) == wallcolor) {

                    Orange.UpWallPos = true;
                    Orange.DownWallPos = false;

                } else {
                    Orange.UpWallPos = false;
                }

                if (image.getPixel(tempxx, OrangeGhost.getPosition().y-7) == wallcolor) {

                    Orange.LeftWallPos = true;
                    Orange.RigthWallPos = false;
                } else {
                    Orange.LeftWallPos = false;
                }

                onceTrue = true;

            }

            if (image.getPixel(tempxxx, tempyyy) == wallcolor) {

                if (image.getPixel(OrangeGhost.getPosition().x+7, tempyyy) == wallcolor) {

                    Orange.UpWallPos = true;
                    Orange.DownWallPos = false;
                } else {
                    Orange.UpWallPos = false;
                }

                if (image.getPixel(tempxxx, OrangeGhost.getPosition().y-7) == wallcolor) {

                    Orange.RigthWallPos = true;
                    Orange.LeftWallPos = false;

                } else {
                    Orange.RigthWallPos = false;
                }

                onceTrue = true;
            }


            if (image.getPixel(tempxxxx, tempyyyy) == wallcolor) {


                if (image.getPixel(OrangeGhost.getPosition().x-7, tempyyyy) == wallcolor) {

                    Orange.DownWallPos = true;
                    Orange.UpWallPos = false;
                } else {
                    Orange.DownWallPos = false;
                }

                if (image.getPixel(tempxxxx, OrangeGhost.getPosition().y+7) == wallcolor) {

                    Orange.LeftWallPos = true;
                    Orange.RigthWallPos = false;
                } else {
                    Orange.LeftWallPos = false;
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


void OrangeGhost_Nav_Basic(sf::Sprite OrangeGhost,sf::Sprite PacMan, WhereWall Orange, bool &OrangeDown, bool &OrangeUp, bool &OrangeLeft, bool &OrangeRight) {

    if(PacMan.getPosition().y >OrangeGhost.getPosition().y && Orange.DownWallPos == false) {

        OrangeDown = true;
        OrangeUp = false;
    }


    if(PacMan.getPosition().y <OrangeGhost.getPosition().y && Orange.UpWallPos == false) {

        OrangeUp = true;
        OrangeDown = false;

    }

    if(PacMan.getPosition().x >OrangeGhost.getPosition().x && Orange.RigthWallPos == false) {

        OrangeRight = true;
        OrangeLeft = false;

    }

    if(PacMan.getPosition().x <OrangeGhost.getPosition().x && Orange.LeftWallPos == false) {

        OrangeLeft = true;
        OrangeRight = false;

    }

}


void OrangeGhost_Nav_Advan(sf::Sprite OrangeGhost,sf::Sprite PacMan, WhereWall &Orange, bool &OrangeDown, bool &OrangeUp, bool &OrangeLeft, bool &OrangeRight, bool &OrangeUpOnce, bool &OrangeDownOnce, bool &OrangeLeftOnce, bool &OrangeRightOnce) {

    if(PacMan.getPosition().y >OrangeGhost.getPosition().y && Orange.DownWallPos == true && OrangeDown == true) {

        OrangeUpOnce = true;
    }


    if(PacMan.getPosition().y <OrangeGhost.getPosition().y && Orange.UpWallPos == true && OrangeUp == true) {

        OrangeDownOnce = true;
    }

    if(PacMan.getPosition().x >OrangeGhost.getPosition().x && Orange.RigthWallPos == true && OrangeRight == true) {

        OrangeLeftOnce = true;
    }

    if(PacMan.getPosition().x <OrangeGhost.getPosition().x && Orange.LeftWallPos == true && OrangeLeft == true) {

        OrangeRightOnce = true;

    }


    if(OrangeUpOnce == true) {

        OrangeUp = true;
        OrangeDown = false;
    }

    if(OrangeDownOnce == true) {

        OrangeUp = false;
        OrangeDown = true;
    }

    if(OrangeLeftOnce == true) {

        OrangeRight = false;
        OrangeLeft = true;
    }

    if(OrangeRightOnce == true) {

        OrangeLeft = false;
        OrangeRight = true;
    }

}


void OrangeGhost_Move(sf::Sprite OrangeGhost,sf::Sprite PacMan, WhereWall &Orange, sf::Image image, bool OrangeDown, bool OrangeUp, bool OrangeLeft, bool OrangeRight, bool &OrangeUpOnce, bool &OrangeDownOnce, bool &OrangeLeftOnce, bool &OrangeRightOnce, double &OrangeX, double &OrangeY) {

    if(OrangeUp == true) {

        OrangeY = -1;
    } else {

        OrangeY = 1;
    }

    if(OrangeLeft == true) {
        OrangeX = -1;
    } else {
        OrangeX = 1;
    }


    if(OrangeghostCheck(OrangeGhost,image, Orange)) {


        if(Orange.UpWallPos == true && OrangeUp == true) {

            OrangeY = 0;
            OrangeUpOnce = false;
        }

        if (Orange.DownWallPos == true && OrangeDown == true) {

            OrangeY = 0;
            OrangeDownOnce = false;
        }

        if(Orange.LeftWallPos == true && OrangeLeft == true) {

            OrangeX = 0;
            OrangeLeftOnce = false;
        }

        if(Orange.RigthWallPos == true && OrangeRight == true) {

            OrangeX = 0;
            OrangeRightOnce = false;
        }

    } else {
        Orange.LeftWallPos = false;
        Orange.RigthWallPos = false;
        Orange.UpWallPos = false;
        Orange.DownWallPos = false;
    }

}



//Red
bool RedghostCheck(sf::Sprite RedGhost, sf::Image image, WhereWall &Red) {


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

                    Red.DownWallPos = true;
                    Red.UpWallPos = false;
                } else {

                    Red.DownWallPos = false;

                }


                if (image.getPixel(tempx, RedGhost.getPosition().y+7) == wallcolor) {

                    Red.RigthWallPos = true;
                    Red.LeftWallPos = false;
                } else {

                    Red.RigthWallPos = false;

                }

                onceTrue = true;
            }

            if (image.getPixel(tempxx, tempyy) == wallcolor) {


                if (image.getPixel(RedGhost.getPosition().x-7, tempyy) == wallcolor) {

                    Red.UpWallPos = true;
                    Red.DownWallPos = false;

                } else {
                    Red.UpWallPos = false;
                }

                if (image.getPixel(tempxx, RedGhost.getPosition().y-7) == wallcolor) {

                    Red.LeftWallPos = true;
                    Red.RigthWallPos = false;
                } else {
                    Red.LeftWallPos = false;
                }

                onceTrue = true;

            }

            if (image.getPixel(tempxxx, tempyyy) == wallcolor) {

                if (image.getPixel(RedGhost.getPosition().x+7, tempyyy) == wallcolor) {

                    Red.UpWallPos = true;
                    Red.DownWallPos = false;
                } else {
                    Red.UpWallPos = false;
                }

                if (image.getPixel(tempxxx, RedGhost.getPosition().y-7) == wallcolor) {

                    Red.RigthWallPos = true;
                    Red.LeftWallPos = false;

                } else {
                    Red.RigthWallPos = false;
                }

                onceTrue = true;
            }


            if (image.getPixel(tempxxxx, tempyyyy) == wallcolor) {


                if (image.getPixel(RedGhost.getPosition().x-7, tempyyyy) == wallcolor) {

                    Red.DownWallPos = true;
                    Red.UpWallPos = false;
                } else {
                    Red.DownWallPos = false;
                }

                if (image.getPixel(tempxxxx, RedGhost.getPosition().y+7) == wallcolor) {

                    Red.LeftWallPos = true;
                    Red.RigthWallPos = false;
                } else {
                    Red.LeftWallPos = false;
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


void RedGhost_Nav_Basic(sf::Sprite RedGhost, sf::Sprite PacMan, WhereWall Red, bool &RedDown, bool &RedUp, bool &RedLeft, bool &RedRight) {

    if(PacMan.getPosition().y >RedGhost.getPosition().y && Red.DownWallPos == false) {

        RedDown = true;
        RedUp = false;
    }


    if(PacMan.getPosition().y <RedGhost.getPosition().y && Red.UpWallPos == false) {

        RedUp = true;
        RedDown = false;
    }

    if(PacMan.getPosition().x >RedGhost.getPosition().x && Red.RigthWallPos == false) {

        RedRight = true;
        RedLeft = false;
    }

    if(PacMan.getPosition().x <RedGhost.getPosition().x && Red.LeftWallPos == false) {

        RedLeft = true;
        RedRight = false;
    }


}


void RedGhost_Nav_Advan(sf::Sprite RedGhost,sf::Sprite PacMan, WhereWall &Red, bool &RedDown, bool &RedUp, bool &RedLeft, bool &RedRight, bool &RedUpOnce, bool &RedDownOnce, bool &RedLeftOnce, bool &RedRightOnce) {

    if(Red.UpWallPos == true && RedUp == true) {


        RedDownOnce = true;
    }

    if(Red.RigthWallPos == true && RedRight == true) {


        RedLeftOnce = true;
    }

    if(Red.DownWallPos == true && RedDown == true) {

        RedUpOnce = true;
    }

    if(Red.LeftWallPos == true && RedLeft == true) {

        RedRightOnce = true;

    }

    if(RedUpOnce == true) {

        RedUp = true;
        RedDown = false;
    }

    if(RedDownOnce == true) {
        RedUp = false;
        RedDown = true;
    }

    if(RedLeftOnce == true) {
        RedRight = false;
        RedLeft = true;
    }

    if(RedRightOnce == true) {
        RedLeft = false;
        RedRight = true;
    }

}


void RedGhost_Move(sf::Sprite RedGhost,sf::Sprite PacMan, WhereWall &Red, sf::Image image, bool &RedDown, bool &RedUp, bool &RedLeft, bool &RedRight, bool &RedUpOnce, bool &RedDownOnce, bool &RedLeftOnce, bool &RedRightOnce, double &RedX, double &RedY) {

    if(RedUp == true) {

        RedY = -1.1;
    }
    if(RedDown == true) {

        RedY = 1.1;
    }
    if(RedLeft == true) {

        RedX = -1.1;
    }
    if(RedRight == true) {

        RedX = 1.1;
    }

    if(RedghostCheck(RedGhost, image, Red)) {

        if(Red.UpWallPos == true && RedUp == true) {

            RedY = 0;
            RedUpOnce = false;
        }

        if (Red.DownWallPos == true && RedDown == true) {

            RedY = 0;
            RedDownOnce = false;
        }

        if(Red.LeftWallPos == true && RedLeft == true) {

            RedX = 0;
            RedLeftOnce = false;
        }

        if(Red.RigthWallPos == true && RedRight == true) {

            RedX = 0;
            RedRightOnce = false;
        }


    } else {
        Red.LeftWallPos = false;
        Red.RigthWallPos = false;
        Red.UpWallPos = false;
        Red.DownWallPos = false;
    }

}



// Blue
bool BlueghostCheck(sf::Sprite BlueGhost, sf::Image image,WhereWall &Blue) {

    const sf::Color wallcolor(33, 33, 255);

    int tempx = 0, tempy = 0, tempxx = 0, tempyy = 0,tempxxx = 0, tempyyy = 0,tempxxxx = 0, tempyyyy = 0;

    bool onceTrue = false;

    for (int a = 14; a > 0; a--) {
        for (int b = 14; b > 0; b--) {

            tempx = BlueGhost.getPosition().x+a;
            tempy = BlueGhost.getPosition().y+b;

            tempxx = BlueGhost.getPosition().x-a;
            tempyy = BlueGhost.getPosition().y-b;

            tempxxx = BlueGhost.getPosition().x+a;
            tempyyy = BlueGhost.getPosition().y-b;

            tempxxxx = BlueGhost.getPosition().x-a;
            tempyyyy = BlueGhost.getPosition().y+b;


            if (image.getPixel(tempx, tempy) == wallcolor) {


                if (image.getPixel(BlueGhost.getPosition().x+7, tempy) == wallcolor) {

                    Blue.DownWallPos = true;
                    Blue.UpWallPos = false;
                } else {

                    Blue.DownWallPos = false;

                }


                if (image.getPixel(tempx, BlueGhost.getPosition().y+7) == wallcolor) {

                    Blue.RigthWallPos = true;
                    Blue.LeftWallPos = false;
                } else {

                    Blue.RigthWallPos = false;

                }

                onceTrue = true;
            }

            if (image.getPixel(tempxx, tempyy) == wallcolor) {


                if (image.getPixel(BlueGhost.getPosition().x-7, tempyy) == wallcolor) {

                    Blue.UpWallPos = true;
                    Blue.DownWallPos = false;

                } else {
                    Blue.UpWallPos = false;
                }

                if (image.getPixel(tempxx, BlueGhost.getPosition().y-7) == wallcolor) {

                    Blue.LeftWallPos = true;
                    Blue.RigthWallPos = false;
                } else {
                    Blue.LeftWallPos = false;
                }

                onceTrue = true;

            }

            if (image.getPixel(tempxxx, tempyyy) == wallcolor) {

                if (image.getPixel(BlueGhost.getPosition().x+7, tempyyy) == wallcolor) {

                    Blue.UpWallPos = true;
                    Blue.DownWallPos = false;
                } else {
                    Blue.UpWallPos = false;
                }

                if (image.getPixel(tempxxx, BlueGhost.getPosition().y-7) == wallcolor) {

                    Blue.RigthWallPos = true;
                    Blue.LeftWallPos = false;

                } else {
                    Blue.RigthWallPos = false;
                }

                onceTrue = true;
            }


            if (image.getPixel(tempxxxx, tempyyyy) == wallcolor) {


                if (image.getPixel(BlueGhost.getPosition().x-7, tempyyyy) == wallcolor) {

                    Blue.DownWallPos = true;
                    Blue.UpWallPos = false;
                } else {
                    Blue.DownWallPos = false;
                }

                if (image.getPixel(tempxxxx, BlueGhost.getPosition().y+7) == wallcolor) {

                    Blue.LeftWallPos = true;
                    Blue.RigthWallPos = false;
                } else {
                    Blue.LeftWallPos = false;
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


void BlueGhost_Nav_Basic(sf::Sprite BlueGhost, sf::Sprite PacMan, WhereWall &Blue, bool &BlueDown, bool &BlueUp, bool &BlueLeft, bool &BlueRight) {


    if(PacMan.getPosition().y >BlueGhost.getPosition().y && Blue.DownWallPos == false) {

        BlueDown = true;
        BlueUp = false;
    }


    if(PacMan.getPosition().y <BlueGhost.getPosition().y && Blue.UpWallPos == false) {

        BlueUp = true;
        BlueDown = false;
    }

    if(PacMan.getPosition().x >BlueGhost.getPosition().x && Blue.RigthWallPos == false) {

        BlueRight = true;
        BlueLeft = false;
    }

    if(PacMan.getPosition().x <BlueGhost.getPosition().x && Blue.LeftWallPos == false) {

        BlueLeft = true;
        BlueRight = false;
    }
}


void BlueGhost_Nav_Advan(sf::Sprite BlueGhost, sf::Sprite PacMan, WhereWall &Blue, bool &BlueDown, bool &BlueUp, bool &BlueLeft, bool &BlueRight, bool &BlueUpOnce, bool &BlueDownOnce, bool &BlueLeftOnce, bool &BlueRightOnce) {

    if(Blue.UpWallPos == true && BlueUp == true) {


        BlueDownOnce = true;
    }

    if(Blue.RigthWallPos == true && BlueRight == true) {


        BlueLeftOnce = true;
    }

    if(Blue.DownWallPos == true && BlueDown == true) {

        BlueUpOnce = true;
    }

    if(Blue.LeftWallPos == true && BlueLeft == true) {

        BlueRightOnce = true;

    }

    if(BlueUpOnce == true) {

        BlueUp = true;
        BlueDown = false;
    }

    if(BlueDownOnce == true) {
        BlueUp = false;
        BlueDown = true;
    }

    if(BlueLeftOnce == true) {
        BlueRight = false;
        BlueLeft = true;
    }

    if(BlueRightOnce == true) {
        BlueLeft = false;
        BlueRight = true;
    }

}


void BlueGhost_Move(sf::Sprite BlueGhost, sf::Sprite PacMan, WhereWall &Blue, sf::Image image, bool &BlueDown, bool &BlueUp, bool &BlueLeft, bool &BlueRight, bool &BlueUpOnce, bool &BlueDownOnce, bool &BlueLeftOnce, bool &BlueRightOnce, double &BlueX, double &BlueY) {

    if(BlueUp == true) {

        BlueY = -0.9;
    }
    if(BlueDown == true) {

        BlueY = 0.9;
    }
    if(BlueLeft == true) {

        BlueX = -0.9;
    }
    if(BlueRight == true) {

        BlueX = 0.9;
    }

    if(BlueghostCheck(BlueGhost, image, Blue)) {

        if(Blue.UpWallPos == true && BlueUp == true) {

            BlueY = 0;
            BlueUpOnce = false;
        }

        if (Blue.DownWallPos == true && BlueDown == true) {

            BlueY = 0;
            BlueDownOnce = false;
        }

        if(Blue.LeftWallPos == true && BlueLeft == true) {

            BlueX = 0;
            BlueLeftOnce = false;
        }

        if(Blue.RigthWallPos == true && BlueRight == true) {

            BlueX = 0;
            BlueRightOnce = false;
        }

    } else {
        Blue.LeftWallPos = false;
        Blue.RigthWallPos = false;
        Blue.UpWallPos = false;
        Blue.DownWallPos = false;
    }

}



// Pink
bool PinkghostCheck(sf::Sprite PinkGhost, sf::Image image,WhereWall &Pink) {

    const sf::Color wallcolor(33, 33, 255);

    int tempx = 0, tempy = 0, tempxx = 0, tempyy = 0,tempxxx = 0, tempyyy = 0,tempxxxx = 0, tempyyyy = 0;

    bool onceTrue = false;

    for (int a = 14; a > 0; a--) {
        for (int b = 14; b > 0; b--) {

            tempx = PinkGhost.getPosition().x+a;
            tempy = PinkGhost.getPosition().y+b;

            tempxx = PinkGhost.getPosition().x-a;
            tempyy = PinkGhost.getPosition().y-b;

            tempxxx = PinkGhost.getPosition().x+a;
            tempyyy = PinkGhost.getPosition().y-b;

            tempxxxx = PinkGhost.getPosition().x-a;
            tempyyyy = PinkGhost.getPosition().y+b;


            if (image.getPixel(tempx, tempy) == wallcolor) {


                if (image.getPixel(PinkGhost.getPosition().x+7, tempy) == wallcolor) {

                    Pink.DownWallPos = true;
                    Pink.UpWallPos = false;
                } else {

                    Pink.DownWallPos = false;

                }


                if (image.getPixel(tempx, PinkGhost.getPosition().y+7) == wallcolor) {

                    Pink.RigthWallPos = true;
                    Pink.LeftWallPos = false;
                } else {

                    Pink.RigthWallPos = false;
                }

                onceTrue = true;
            }

            if (image.getPixel(tempxx, tempyy) == wallcolor) {


                if (image.getPixel(PinkGhost.getPosition().x-7, tempyy) == wallcolor) {

                    Pink.UpWallPos = true;
                    Pink.DownWallPos = false;

                } else {
                    Pink.UpWallPos = false;
                }

                if (image.getPixel(tempxx, PinkGhost.getPosition().y-7) == wallcolor) {

                    Pink.LeftWallPos = true;
                    Pink.RigthWallPos = false;
                } else {
                    Pink.LeftWallPos = false;
                }

                onceTrue = true;

            }

            if (image.getPixel(tempxxx, tempyyy) == wallcolor) {

                if (image.getPixel(PinkGhost.getPosition().x+7, tempyyy) == wallcolor) {

                    Pink.UpWallPos = true;
                    Pink.DownWallPos = false;
                } else {
                    Pink.UpWallPos = false;
                }

                if (image.getPixel(tempxxx, PinkGhost.getPosition().y-7) == wallcolor) {

                    Pink.RigthWallPos = true;
                    Pink.LeftWallPos = false;

                } else {
                    Pink.RigthWallPos = false;
                }

                onceTrue = true;
            }


            if (image.getPixel(tempxxxx, tempyyyy) == wallcolor) {


                if (image.getPixel(PinkGhost.getPosition().x-7, tempyyyy) == wallcolor) {

                    Pink.DownWallPos = true;
                    Pink.UpWallPos = false;
                } else {
                    Pink.DownWallPos = false;
                }

                if (image.getPixel(tempxxxx, PinkGhost.getPosition().y+7) == wallcolor) {

                    Pink.LeftWallPos = true;
                    Pink.RigthWallPos = false;
                } else {
                    Pink.LeftWallPos = false;
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


void PinkGhost_Nav_Basic(sf::Sprite PinkGhost, sf::Sprite PacMan, WhereWall &Pink, bool &PinkDown, bool &PinkUp, bool &PinkLeft, bool &PinkRight) {

    if(PacMan.getPosition().y >PinkGhost.getPosition().y && Pink.DownWallPos == false) {

        PinkDown = true;
        PinkUp = false;
    }


    if(PacMan.getPosition().y <PinkGhost.getPosition().y && Pink.UpWallPos == false) {

        PinkUp = true;
        PinkDown = false;
    }

    if(PacMan.getPosition().x >PinkGhost.getPosition().x && Pink.RigthWallPos == false) {

        PinkRight = true;
        PinkLeft = false;
    }

    if(PacMan.getPosition().x <PinkGhost.getPosition().x && Pink.LeftWallPos == false) {

        PinkLeft = true;
        PinkRight = false;
    }

}


void PinkGhost_Nav_Advan(sf::Sprite PinkGhost, sf::Sprite PacMan, WhereWall &Pink,  bool &PinkDown, bool &PinkUp, bool &PinkLeft, bool &PinkRight, bool &PinkUpOnce, bool &PinkDownOnce, bool &PinkLeftOnce, bool &PinkRightOnce) {

    if(Pink.UpWallPos == true && PinkUp == true) {


        PinkDownOnce = true;
    }

    if(Pink.RigthWallPos == true && PinkRight == true) {


        PinkLeftOnce = true;
    }

    if(Pink.DownWallPos == true && PinkDown == true) {

        PinkUpOnce = true;
    }

    if(Pink.LeftWallPos == true && PinkLeft == true) {

        PinkRightOnce = true;

    }

    if(PinkUpOnce == true) {

        PinkUp = true;
        PinkDown = false;
    }

    if(PinkDownOnce == true) {
        PinkUp = false;
        PinkDown = true;
    }

    if(PinkLeftOnce == true) {
        PinkRight = false;
        PinkLeft = true;
    }

    if(PinkRightOnce == true) {
        PinkLeft = false;
        PinkRight = true;
    }

}


void PinkGhost_Move(sf::Sprite PinkGhost, sf::Sprite PacMan, WhereWall &Pink, sf::Image image, bool &PinkDown, bool &PinkUp, bool &PinkLeft, bool &PinkRight, bool &PinkUpOnce, bool &PinkDownOnce, bool &PinkLeftOnce, bool &PinkRightOnce, double &PinkX, double &PinkY) {

    if(PinkUp == true) {

        PinkY = -1;
    }
    if(PinkDown == true) {

        PinkY = 1;
    }
    if(PinkLeft == true) {

        PinkX = -1;
    }
    if(PinkRight == true) {

        PinkX = 1;
    }

    if(PinkghostCheck(PinkGhost, image, Pink)) {

        if(Pink.UpWallPos == true && PinkUp == true) {

            PinkY = 0;
            PinkUpOnce = false;
        }

        if (Pink.DownWallPos == true && PinkDown == true) {

            PinkY = 0;
            PinkDownOnce = false;
        }

        if(Pink.LeftWallPos == true && PinkLeft == true) {

            PinkX = 0;
            PinkLeftOnce = false;
        }

        if(Pink.RigthWallPos == true && PinkRight == true) {

            PinkX = 0;
            PinkRightOnce = false;
        }

    } else {
        Pink.LeftWallPos = false;
        Pink.RigthWallPos = false;
        Pink.UpWallPos = false;
        Pink.DownWallPos = false;
    }
}





void SaveHS(int &highscore, int &score,string &HSString,sf::Text &NewHS) {

    ifstream readFile;
    readFile.open("Assets/Other/High_Score.txt");

    if(readFile.is_open()) {

        while(!readFile.eof()) {

            readFile >> highscore;
        }

    }
    readFile.close();

    ofstream writeFile("Assets/Other/High_Score.txt");
    if(writeFile.is_open()) {

        stringstream ss3;
        ss3<<highscore;
        ss3>>HSString;

        if(score>highscore) {

            highscore = score;

            NewHS.setPosition(522/2, 400);
        }

        writeFile<< highscore;

    }
    writeFile.close();
}


void PlaceDots(std::vector<sf::RectangleShape> &Dot, sf::Image image) {

    int tempx = 30;
    int tempy = 30;

    const sf::Color wallcolor(33, 33, 255);
    const sf::Color wallcolor2(1,0,0);

    for (int i = 0; i < Dot.size(); i++) {


        if (image.getPixel(tempx, tempy) != wallcolor &&image.getPixel(tempx, tempy) != wallcolor2 ) {

            Dot[i].setPosition(tempx,tempy);

        } else {

            i -=1;
        }

        tempx +=30;

        if(tempx == 270) {

            tempx = 263;
        }

        if(tempx == 383) {

            tempx = 375;
        }


        if(tempx == 353) {

            tempx = 346;
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
}


void PlaceLives(std::vector<sf::Sprite> &PacLife) {

    int temp;

    for(int i = 0; i<PacLife.size(); i++) {

        temp = 400 + i*50;

        PacLife[i].setOrigin(15,15);
        PacLife[i].setPosition(temp,600);

    }
}


void PowerPelletAni(std::vector<sf::CircleShape> &PowerUp,int &Pwr_ani_frame, int &glowTimer) {

    if(glowTimer == 2*Pwr_ani_frame) {

        for(int i = 0; i<PowerUp.size(); i++) {
            PowerUp[i].setOutlineThickness(-11+Pwr_ani_frame);
        }

        Pwr_ani_frame ++;
    }

    if (glowTimer > 24) {

        Pwr_ani_frame = 1;
        glowTimer = 0;
    }
}


bool Teleport(sf::Sprite &PacMan, sf::Sprite &OrangeGhost, sf::Sprite &RedGhost, sf::Sprite &PinkGhost, sf::Sprite &BlueGhost) {

    bool temp = false;


    if(PacMan.getPosition().x >510) {

        PacMan.setPosition(0,270);
        temp = true;
    }

    if(PacMan.getPosition().x<0) {

        PacMan.setPosition(510,270);
        temp = true;
    }


    if(OrangeGhost.getPosition().x >510) {

        OrangeGhost.setPosition(0,270);
        temp = true;
    }

    if(OrangeGhost.getPosition().x<0) {

        OrangeGhost.setPosition(510,270);
        temp = true;
    }


    if(RedGhost.getPosition().x >510) {

        RedGhost.setPosition(0,270);
        temp = true;
    }

    if(RedGhost.getPosition().x<0) {

        RedGhost.setPosition(510,270);
        temp = true;
    }


    if(BlueGhost.getPosition().x >510) {

        BlueGhost.setPosition(0,270);
        temp = true;
    }

    if(BlueGhost.getPosition().x<0) {

        BlueGhost.setPosition(510,270);
        temp = true;
    }

    if(PinkGhost.getPosition().x >510) {

        PinkGhost.setPosition(0,270);
        temp = true;
    }

    if(PinkGhost.getPosition().x<0) {

        PinkGhost.setPosition(510,270);
        temp = true;
    }

    if(temp == true)
        return true;
    else
        return false;

}


bool DeadEye(sf::Sprite sprite, double &spriteX, double &spriteY,int DestX, int DestY) {

    if(sprite.getPosition().x > DestX)
        spriteX = -1;

    if(sprite.getPosition().x < DestX)
        spriteX = 1;

    if(sprite.getPosition().y < DestY)
        spriteY = 1;

    if(sprite.getPosition().y > DestY)
        spriteY = -1;

    if((sprite.getPosition().x > (DestX-10) && sprite.getPosition().x < (DestX+10)) && (sprite.getPosition().y > (DestY-5) && sprite.getPosition().y < (DestY+5))) {
        return true;
    } else {

        return false;
    }

}


void DeadMover(bool &Dead, sf::Sprite &sprite, double &spriteX, double &spriteY, int &close, int DestX, int DestY, sf::Texture &texture) {

    if(Dead == true) {

        if(DeadEye(sprite, spriteX, spriteY, DestX, DestY)) {

            Dead = false;
            sprite.setTexture(texture);
            sprite.setPosition(DestX,DestY);
            close = 23;
        }
    }
}


void PowerStop(int powerUpTimer, sf::Sprite &OrangeGhost, sf::Sprite &RedGhost, sf::Sprite &PinkGhost, sf::Sprite &BlueGhost, sf::Texture &texture4, sf::Texture &texture5, sf::Texture &texture6, sf::Texture &texture7, sf::Texture &texture8, sf::Texture &texture8_2, edible &ised, ghosteyes &Deadmove) {


    if(powerUpTimer <480) {

        if(ised.orange == true)
            OrangeGhost.setTexture(texture8);
        if(ised.red == true)
            RedGhost.setTexture(texture8);
        if(ised.pink == true)
            PinkGhost.setTexture(texture8);
        if(ised.blue == true)
            BlueGhost.setTexture(texture8);
    }


    if(powerUpTimer == 480) {

        if(ised.orange == true)
            OrangeGhost.setTexture(texture8_2);
        if(ised.red == true)
            RedGhost.setTexture(texture8_2);
        if(ised.pink == true)
            PinkGhost.setTexture(texture8_2);
        if(ised.blue == true)
            BlueGhost.setTexture(texture8_2);
    }

    if(powerUpTimer == 510) {

        if(ised.orange == true)
            OrangeGhost.setTexture(texture8);
        if(ised.red == true)
            RedGhost.setTexture(texture8);
        if(ised.pink == true)
            PinkGhost.setTexture(texture8);
        if(ised.blue == true)
            BlueGhost.setTexture(texture8);
    }

    if(powerUpTimer == 540) {

        if(ised.orange == true)
            OrangeGhost.setTexture(texture8_2);
        if(ised.red == true)
            RedGhost.setTexture(texture8_2);
        if(ised.pink == true)
            PinkGhost.setTexture(texture8_2);
        if(ised.blue == true)
            BlueGhost.setTexture(texture8_2);
    }

    if(powerUpTimer == 570) {

        if(ised.orange == true)
            OrangeGhost.setTexture(texture8);
        if(ised.red == true)
            RedGhost.setTexture(texture8);
        if(ised.pink == true)
            PinkGhost.setTexture(texture8);
        if(ised.blue == true)
            BlueGhost.setTexture(texture8);
    }


    if(powerUpTimer ==600) {

        ised.red = false;
        ised.orange = false;
        ised.blue = false;
        ised.pink = false;

        if(Deadmove.orange == false)
            OrangeGhost.setTexture(texture4);

        if(Deadmove.red == false)
            RedGhost.setTexture(texture5);

        if(Deadmove.pink == false)
            PinkGhost.setTexture(texture6);

        if(Deadmove.blue == false)
            BlueGhost.setTexture(texture7);
    }
}


void PacAni(sf::Sprite &PacMan, sf::Texture &texture2, sf::Texture &texture3, int &timer) {

    if(timer == 10)
        PacMan.setTexture(texture3);


    if(timer == 20) {

        PacMan.setTexture(texture2);
        timer = 0;
    }
}


bool PacDeathAni(sf::Sprite &PacDeath, sf::Sprite PacMan, int death_ani_Timer) {

    if(death_ani_Timer==5) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack1));
        PacDeath.setOrigin(7.5,4);
    }


    if(death_ani_Timer==10) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack2));
        PacDeath.setOrigin(7.5,3);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==15) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack3));
        PacDeath.setOrigin(7.5,2.5);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==20) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack4));
        PacDeath.setOrigin(7.5,2.5);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==25) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack5));
        PacDeath.setOrigin(7.5,2.5);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==30) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack6));
        PacDeath.setOrigin(7.5,3);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==35) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack7));
        PacDeath.setOrigin(6.5,3);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==40) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack8));
        PacDeath.setOrigin(4.5,3.5);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==45) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack9));
        PacDeath.setOrigin(2.5,3.5);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==50) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack10));
        PacDeath.setOrigin(1,1);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }
    if(death_ani_Timer==60) {

        PacDeath.setTextureRect(sf::IntRect(Pac_wack11));
        PacDeath.setOrigin(5.5,5.5);
        PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
    }

    if(death_ani_Timer==75) {
        return true;
    } else {
        return false;
    }

}


void BerryPlace(sf::Sprite &Berry, int Berrytimer) {


    if(Berrytimer == 1200) {

        int randtemp = rand()%7;

        if(randtemp == 0)
            Berry.setTextureRect(sf::IntRect(Bry_Cherry));

        if(randtemp == 1)
            Berry.setTextureRect(sf::IntRect(Bry_Strawberry));

        if(randtemp == 2)
            Berry.setTextureRect(sf::IntRect(Bry_Peach));

        if(randtemp == 3)
            Berry.setTextureRect(sf::IntRect(Bry_Apple));

        if(randtemp == 4)
            Berry.setTextureRect(sf::IntRect(Bry_Lime));

        if(randtemp == 5)
            Berry.setTextureRect(sf::IntRect(Bry_Spear));

        if(randtemp == 6)
            Berry.setTextureRect(sf::IntRect(Bry_Bell));

        if(randtemp == 7)
            Berry.setTextureRect(sf::IntRect(Bry_Key));

        Berry.setScale(2.f, 2.f);
        Berry.setPosition(522/2,620/2);
    }

}


void DieHit(bool &PacDead, bool Sound_Ef, sf::Sound &Dead, sf::Sound &BackG_Pizza, sf::Sound &BackG_Subwooder, sf::Sound &BackG_Sweden, int &death_ani_Timer, sf::Sprite &PacDeath, sf::Sprite PacMan) {

    PacDead = true;

    if(Sound_Ef == true) {
        Dead.play();
    }
    BackG_Pizza.pause();
    BackG_Subwooder.pause();
    BackG_Sweden.pause();

    death_ani_Timer = 0;
    PacDeath.setTextureRect(sf::IntRect(Pac_wack1));
    PacDeath.setOrigin(7.5,4);
    PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
}


void scoreUpdate(sf::Text &HsDis, sf::Text &scoreDis, int score, int highscore, string &scoreShow, string &HSString) {
    stringstream ss;
    ss<<score;
    ss>>scoreShow;

    scoreDis.setString("Score: "+scoreShow);

    stringstream ss2;
    ss2<<highscore;
    ss2>>HSString;

    HsDis.setString("HS: "+HSString);
}


bool isSpriteHover(sf::FloatRect Button, sf::Vector2f mp) {

    if (Button.contains(mp)) {
        return true;
    }

    return false;
}


void findSmallestElement(int &PacClose,near &Close,Difference &Diff) {


    //Pacman
    int temp = Diff.Pac_X[0];
    int temp2 = Diff.Pac_Y[0];

    for(int i=0; i<Diff.Pac_X.size(); i++) {
        if(temp>Diff.Pac_X[i]) {
            temp=Diff.Pac_X[i];
        }

        if(temp2>Diff.Pac_Y[i]) {
            temp2=Diff.Pac_Y[i];
        }
    }
    for(int i=0; i<Diff.Pac_X.size(); i++) {

        if(temp == Diff.Pac_X[i] &&temp2 == Diff.Pac_Y[i] ) {

            PacClose = i;
            Close.Pac = i;
        }
    }

    //Red

    temp = Diff.Red_X[0];
    temp2 = Diff.Red_Y[0];

    for(int i=0; i<Diff.Red_X.size(); i++) {
        if(temp>Diff.Red_X[i]) {
            temp=Diff.Red_X[i];
        }

        if(temp2>Diff.Red_Y[i]) {
            temp2=Diff.Red_Y[i];
        }
    }
    for(int i=0; i<Diff.Red_X.size(); i++) {

        if(temp == Diff.Red_X[i] &&temp2 == Diff.Red_Y[i] ) {

            Close.Red = i;
        }
    }
    ////


    //cout<<"Pac is close to Node: "<<Close.Pac<<endl;
    // cout<<"Red is close to Node: "<<Close.Red<<endl;


    Diff.Red_X.clear();
    Diff.Red_Y.clear();
    Diff.Pac_X.clear();
    Diff.Pac_Y.clear();
}


void paths(int &PacClose,near &Close,sf::Sprite PacMan,std::vector<sf::RectangleShape> &Node,std::vector<sf::RectangleShape> &lineArr,sf::Sprite RedGhost,sf::Image image) {

//start at a Node
//get end Node
//calculate shortest distance using nodes

//start == PacClose
//end == Node[0];

    const sf::Color wallcolor(33, 33, 255);

    int dest = Close.Red;

//start
    Node[PacClose].getPosition().x;
    Node[PacClose].getPosition().y;

//end
    Node[dest].getPosition().x;
    Node[dest].getPosition().y;


//lineArr[1].setPosition(PacMan.getPosition().x,PacMan.getPosition().y);



    for (int i = 0; i < lineArr.size(); i++) {

        lineArr[i].setSize(sf::Vector2f(5, 0));
        lineArr[i].setPosition(1000,1000);
    }




    int Pacxline, Pacyline;
    int Redxline, Redyline;

    vector<int> path;

    lineArr[0].setPosition(sf::Vector2f(PacMan.getPosition().x, PacMan.getPosition().y));
    Pacxline = Node[PacClose].getPosition().x-PacMan.getPosition().x;
    Pacyline = Node[PacClose].getPosition().y-PacMan.getPosition().y;

    if(Pacyline > 0)
        lineArr[0].setSize(sf::Vector2f(Pacxline+5, Pacyline+5));


    if(Pacyline <0)
        lineArr[0].setSize(sf::Vector2f(Pacxline-5, Pacyline-5));



    lineArr[1].setPosition(sf::Vector2f(RedGhost.getPosition().x, RedGhost.getPosition().y));
    Redxline = Node[Close.Red].getPosition().x-RedGhost.getPosition().x;
    Redyline = Node[Close.Red].getPosition().y-RedGhost.getPosition().y;

    if(Redyline > 0)
        lineArr[1].setSize(sf::Vector2f(Redxline+2, Redyline+2));


    if(Redyline <0)
        lineArr[1].setSize(sf::Vector2f(Redxline-2, Redyline-2));






    int num = Close.Red;
    int lastnum = Close.Red;
    int lineArrInt = 2;
    int state = 1;



    bool wall = false;
    int LineX;
    int LineY;
    bool tryup = true;
    bool once = true;
    int NodeUpStart = 42;
    int nextNode = 0;

    bool oncegoing = true;
    bool onceoncegoing = false;
    bool pathfound = false;

    bool goingright = true;
    bool wallRight = false;
    bool wallLeft = false;
    int stop = 0;

    int algorState = 0;

    bool onSameLine = false;

    int rightInter = 1;
    int leftInter = 1;

    //vector< vector<int> > VertLines(12);
    //VertLines[0,0].push_back(0);



    while(pathfound == false) {

        if(stop == 100) {
            pathfound = true;
        }

        stop++;

        if(Node[lastnum].getPosition().x == Node[num].getPosition().x) {

            if(Node[lastnum].getPosition().y<Node[num].getPosition().y) {

                for(int j = Node[lastnum].getPosition().y; j<Node[num].getPosition().y; j++) {

                    if (image.getPixel(Node[lastnum].getPosition().x, j) == wallcolor) {

                        wall = true;

                    } else {

                        if(wall == false) {

                            wall = false;
                        }

                    }

                }
            } else if(Node[lastnum].getPosition().y>Node[num].getPosition().y) {

                for(int j = Node[num].getPosition().y; j<Node[lastnum].getPosition().y; j++) {

                    if (image.getPixel(Node[lastnum].getPosition().x, j) == wallcolor) {

                        wall = true;

                    } else {

                        if(wall == false) {

                            wall = false;
                        }

                    }

                }

            }


        } else if(Node[lastnum].getPosition().y == Node[num].getPosition().y) {


            if(Node[num].getPosition().x<Node[lastnum].getPosition().x) {

                for(int j = Node[num].getPosition().x; j<Node[lastnum].getPosition().x; j++) {

                    if (image.getPixel(j, Node[lastnum].getPosition().y) == wallcolor) {

                        wall = true;
                        wallRight = true;
                        wallLeft = true;

                    } else {

                        if(wall == false) {
                            wall = false;
                        }


                        if(goingright == true && wallRight == false) {

                            wallRight = false;
                        }



                    }


                }
            } else if(Node[num].getPosition().x>Node[lastnum].getPosition().x) {

                for(int j = Node[lastnum].getPosition().x; j<Node[num].getPosition().x; j++) {

                    if (image.getPixel(j, Node[lastnum].getPosition().y) == wallcolor) {

                        wall = true;
                        wallRight = true;
                        wallLeft = true;

                    } else {

                        if(wall == false) {
                            wall = false;
                        }

                        if(goingright == true && wallRight == false) {

                            wallRight = false;
                        }



                    }


                }


            }
        }


        if(wall == false) {

            lineArr[lineArrInt].setPosition(sf::Vector2f(Node[num].getPosition().x, Node[num].getPosition().y));


            if((Node[lastnum].getPosition().x-Node[num].getPosition().x) > 0) {

                LineX = Node[lastnum].getPosition().x-Node[num].getPosition().x;
                LineY = Node[lastnum].getPosition().y-Node[num].getPosition().y;

            } else {
                LineX = Node[num].getPosition().x-Node[lastnum].getPosition().x;
                LineY = Node[num].getPosition().y-Node[lastnum].getPosition().y;
            }


            if(num != PacClose) {



                if(LineX > 0) {
                    lineArr[lineArrInt].setSize(sf::Vector2f(LineX+2, LineY+2));

                } else if(LineY <0) {
                    lineArr[lineArrInt].setSize(sf::Vector2f(LineX-2, LineY-2));
                }

                lineArrInt++;
            }


        }



        lastnum = num;


        if(algorState == 0) {

            //  if(wall == false) {


            if(goingright == true && (Node[Close.Red].getPosition().y == Node[Close.Red+rightInter].getPosition().y)) {

                onSameLine = true;

            }



            if(goingright == true && wallRight == false && onSameLine == true) {

                num = Close.Red+rightInter;
                //cout<<Close.Red+rightInter<<endl;
                onSameLine = false;
                wallRight = false;
                rightInter++;
            }
            if(wallRight == true) {
                rightInter = 1;
                goingright = false;
            }



            // }
        }





        wall = false;

        /*

        if(state == 1) {
            if(num>dest) {

                if(num >0) {
                    num--;
                    goingleft = true;
                }
            } else if(num<dest) {

                if(num< Node.size()) {
                    num++;
                    goingleft = false;
                }
            } else {


                if(oncegoing == false){
                lastnum = PacClose;
                num = lastnum;
                state = 2;
                }


                if(goingleft == true){

                num--;
                oncegoing = false;
                }
                if(goingleft == false){

                num--;
                oncegoing = true;
                }

            }

        } else if (state >= 2) {




            if(tryup==true){

                lastnum = NodeUpStart;
                num = lastnum;
                state = 2;
             tryup = false;
            }

        nextNode++;


                        if(nextNode == 20){
                        state = 3;
                        nextNode = 0;
                        }


                if(state !=3){
                for(int j = num; j<Node.size(); j++) {



                    if(Node[num].getPosition().x == Node[j].getPosition().x && Node[num].getPosition().y != Node[j].getPosition().y) {

                        num = j;

                        break;
                    }

                }
                }else{


                for(int j = num; j>0; j--) {


                if(j == 1){
                            if(NodeUpStart <52){

                            NodeUpStart++;
                            lastnum = NodeUpStart;
                            num = NodeUpStart;
                            state = 2;
                             nextNode = 0;
                            }
                }

                    if(Node[num].getPosition().x == Node[j].getPosition().x && Node[num].getPosition().y != Node[j].getPosition().y) {

                        num = j;


                        break;
                    }

                }
                }


        }

        */


    }



    //start == pacclose
    //end == dest

    int startpoint = PacClose;
    int endpoint = dest;
    int currentpoint = 0;
    vector<int> score;






    // path.push_back(Node[i].getPosition().x + Node[j].getPosition().x - Node[PacClose].getPosition().x);




}







int main() {

    int timer = 0;
    int glowTimer = 0;
    int powerUpTimer = 0;
    int Berrytimer = 5000;
    int death_ani_Timer = 90;
    int death_timer = 0;
    int PauseTimer = 0;

    int score = 0;
    int highscore;

    int PacClose = 32;
    int lives = 2;
    int dotsEaten = 0;
    int Pwr_ani_frame = 1;
    int Track = 1;
    int State = 1;

    int x = 0,y = 0;
    double OrangeX = 0, OrangeY = 0;
    double RedX = 0, RedY = 0;
    double PinkX = 0, PinkY = 0;
    double BlueX = 0, BlueY = 0;


    bool LeftWallPos = false, RigthWallPos = false, UpWallPos = false, DownWallPos = false;

    bool OrangeLeft = false, OrangeRight = false, OrangeUp = false, OrangeDown = false;
    bool OrangeUpOnce = false,OrangeDownOnce = false, OrangeLeftOnce = false, OrangeRightOnce = false;

    bool RedLeft = false, RedRight = false, RedUp = false, RedDown = false;
    bool RedUpOnce = false,RedDownOnce = false, RedLeftOnce = false, RedRightOnce = false;

    bool BlueLeft = false, BlueRight = false, BlueUp = false, BlueDown = false;
    bool BlueUpOnce = false,BlueDownOnce = false, BlueLeftOnce = false, BlueRightOnce = false;

    bool PinkLeft = false, PinkRight = false, PinkUp = false, PinkDown = false;
    bool PinkUpOnce = false,PinkDownOnce = false, PinkLeftOnce = false, PinkRightOnce = false;


    bool killonce = true;
    bool PacDead = false;
    bool start_game = true;
    bool Game_over = true;
    bool deathTimerOnce = true;
    bool PauseGame = false;
    bool In_Settings = false;
    bool OneFree = true;
    bool Music = true;
    bool Sound_Ef = true;
    bool Master_Vol = true;

    srand (time(NULL));

    string Help_Text = "\t\t\t\t\t\t\t\t HELP \n \n \nMove is Arrow keys \nIf you eat all the dots on the board more will spawn. \nIf a ghost hits you and is not Blue, YOU. WILL. DIE! \nTo make a ghost blue you must eat a power pellet,\nthere are 4 accros the map.\nYou Have 3 lives,\nif you beat the High score You get a free life.\n\n\t\tBy. Nicholas Parise";
    string Settings_Text = "Master Audio: \n\n\n Music: \n\n\n Sound Effects: \n\n\n\n Music Track:";
    string scoreShow;
    string HSString;



    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //sf::RenderWindow window(sf::VideoMode(522, 620), "Pac Man", sf::Style::Fullscreen,settings);
    sf::RenderWindow window(sf::VideoMode(522, 620), "Pac Man", sf::Style::Default,settings);
    window.setFramerateLimit(60);
    sf::View view(sf::FloatRect(0.f, 0.f, window.getSize().x, window.getSize().y));

    //----------------Load Assets----------------

    sf::Image icon;
    icon.loadFromFile("Assets/Sprite/Pacman.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Image image;
    image.loadFromFile("Assets/Sprite/PacMan_background.png");

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Texture texture2;
    texture2.loadFromFile("Assets/Sprite/PacMan_open.png");

    sf::Texture texture3;
    texture3.loadFromFile("Assets/Sprite/PacMan_closed.png");

    sf::Texture texture4;
    texture4.loadFromFile("Assets/Sprite/OrangeGhostRight.png");

    sf::Texture texture5;
    texture5.loadFromFile("Assets/Sprite/RedGhostRight.png");

    sf::Texture texture6;
    texture6.loadFromFile("Assets/Sprite/PinkGhostRight.png");

    sf::Texture texture7;
    texture7.loadFromFile("Assets/Sprite/BlueGhostRight.png");

    sf::Texture texture8;
    texture8.loadFromFile("Assets/Sprite/DeadGhost.png");

    sf::Texture texture8_2;
    texture8_2.loadFromFile("Assets/Sprite/WhiteDeadGhost.png");

    sf::Texture texture9;
    texture9.loadFromFile("Assets/Other/PacMan-Start.png");

    sf::Texture texture10;
    texture10.loadFromFile("Assets/Sprite/Berry_Sprite_Sheet.png");

    sf::Texture texture11;
    texture11.loadFromFile("Assets/Other/Solid_black.png");

    sf::Texture texture12;
    texture12.loadFromFile("Assets/Sprite/Pac-Death-SpriteSheet.png");

    sf::Texture texture13;
    texture13.loadFromFile("Assets/Sprite/eyes.png");

    sf::Texture texture14;
    texture14.loadFromFile("Assets/Sprite/pause.png");

    sf::Texture texture15;
    texture15.loadFromFile("Assets/Buttons/Settings_1.png");

    sf::Texture texture16;
    texture16.loadFromFile("Assets/Buttons/Settings_2.png");

    sf::Texture texture17;
    texture17.loadFromFile("Assets/Buttons/Return_1.png");

    sf::Texture texture18;
    texture18.loadFromFile("Assets/Buttons/Return_2.png");

    sf::Texture texture19;
    texture19.loadFromFile("Assets/Buttons/Help_1.png");

    sf::Texture texture20;
    texture20.loadFromFile("Assets/Buttons/Help_2.png");

    sf::Texture texture21;
    texture21.loadFromFile("Assets/Buttons/Yes_1.png");

    sf::Texture texture22;
    texture22.loadFromFile("Assets/Buttons/Yes_2.png");

    sf::Texture texture23;
    texture23.loadFromFile("Assets/Buttons/No_1.png");

    sf::Texture texture24;
    texture24.loadFromFile("Assets/Buttons/No_2.png");

    sf::Texture texture25;
    texture25.loadFromFile("Assets/Buttons/1_1.png");

    sf::Texture texture26;
    texture26.loadFromFile("Assets/Buttons/1_2.png");

    sf::Texture texture27;
    texture27.loadFromFile("Assets/Buttons/2_1.png");

    sf::Texture texture28;
    texture28.loadFromFile("Assets/Buttons/2_2.png");

    sf::Texture texture29;
    texture29.loadFromFile("Assets/Buttons/3_1.png");

    sf::Texture texture30;
    texture30.loadFromFile("Assets/Buttons/3_2.png");

    sf::Font font;
    font.loadFromFile("Assets/Other/Arial.ttf");

    sf::SoundBuffer sound1;
    sound1.loadFromFile("Assets/Audio/Music/Pizza_Theme.wav");

    sf::SoundBuffer sound2;
    sound2.loadFromFile("Assets/Audio/Music/Wii_Menu.wav");

    sf::SoundBuffer sound3;
    sound3.loadFromFile("Assets/Audio/Effect/Mac_Startup.wav");

    sf::SoundBuffer sound4;
    sound4.loadFromFile("Assets/Audio/Effect/XP_Dots.wav");

    sf::SoundBuffer sound5;
    sound5.loadFromFile("Assets/Audio/Effect/XP_Start.wav");

    sf::SoundBuffer sound6;
    sound6.loadFromFile("Assets/Audio/Effect/XP_Teleport.wav");

    sf::SoundBuffer sound7;
    sound7.loadFromFile("Assets/Audio/Effect/XP_End.wav");

    sf::SoundBuffer sound8;
    sound8.loadFromFile("Assets/Audio/Effect/Click_Button.wav");

    sf::SoundBuffer sound9;
    sound9.loadFromFile("Assets/Audio/Effect/Select_Button.wav");

    sf::SoundBuffer sound10;
    sound10.loadFromFile("Assets/Audio/Effect/Death.wav");

    sf::SoundBuffer sound11;
    sound11.loadFromFile("Assets/Audio/Effect/PowerUp.wav");

    sf::SoundBuffer sound12;
    sound12.loadFromFile("Assets/Audio/Effect/XP_Yay.wav");

    sf::SoundBuffer sound13;
    sound13.loadFromFile("Assets/Audio/Music/SubwooferLullaby.ogg");

    sf::SoundBuffer sound14;
    sound14.loadFromFile("Assets/Audio/Music/Sweden.ogg");

    sf::SoundBuffer sound15;
    sound15.loadFromFile("Assets/Audio/Effect/Fortnite_Clap.wav");

//----------------Sounds----------------

    sf::Sound BackG_Pizza;
    BackG_Pizza.setBuffer(sound1);

    sf::Sound BackG_Wii;
    BackG_Wii.setBuffer(sound2);

    sf::Sound Mac_start;
    Mac_start.setBuffer(sound3);

    sf::Sound XP_Tele;
    XP_Tele.setBuffer(sound4);

    sf::Sound XP_start;
    XP_start.setBuffer(sound5);

    sf::Sound XP_Dot;
    XP_Dot.setBuffer(sound6);

    sf::Sound XP_End;
    XP_End.setBuffer(sound7);

    sf::Sound Button_click;
    Button_click.setBuffer(sound8);

    sf::Sound Button_select;
    Button_select.setBuffer(sound9);

    sf::Sound Dead;
    Dead.setBuffer(sound10);

    sf::Sound PowerSound;
    PowerSound.setBuffer(sound11);

    sf::Sound Yay;
    Yay.setBuffer(sound12);

    sf::Sound BackG_Subwooder;
    BackG_Subwooder.setBuffer(sound13);

    sf::Sound BackG_Sweden;
    BackG_Sweden.setBuffer(sound14);

    sf::Sound Fortnite_Clap;
    Fortnite_Clap.setBuffer(sound15);


    BackG_Wii.play();
    BackG_Wii.setLoop(true);
    BackG_Pizza.setLoop(true);
    BackG_Subwooder.setLoop(true);
    BackG_Sweden.setLoop(true);

    BackG_Wii.setVolume(60.f);
    XP_Tele.setVolume(50.f);
    Mac_start.setVolume(50.f);
    BackG_Pizza.setVolume(10.f);
    PowerSound.setVolume(30.f);

    //----------------Text----------------

    sf::Text scoreDis("", font);
    scoreDis.setCharacterSize(30);
    scoreDis.setStyle(sf::Text::Bold);
    scoreDis.setFillColor(sf::Color::White);
    scoreDis.setOrigin(15,15);
    scoreDis.setPosition(30,590);


    sf::Text HsDis("", font);
    HsDis.setCharacterSize(30);
    HsDis.setStyle(sf::Text::Bold);
    HsDis.setFillColor(sf::Color::White);
    HsDis.setOrigin(15,15);
    HsDis.setPosition(250, 590);

    sf::Text NewHS("NEW HIGHSCORE!!", font);
    NewHS.setCharacterSize(30);
    NewHS.setStyle(sf::Text::Bold);
    NewHS.setFillColor(sf::Color::Red);
    NewHS.setOrigin(150,15);
    NewHS.setPosition(1000, 1000);

    SaveHS(highscore,score,HSString,NewHS);


    sf::Text PreStart("Push Space To Start", font);
    PreStart.setCharacterSize(30);
    PreStart.setStyle(sf::Text::Bold);
    PreStart.setFillColor(sf::Color::White);
    PreStart.setOrigin(142,15);
    PreStart.setPosition(522/2, 620/2);

    sf::Text GameDone("GAME OVER", font);
    GameDone.setCharacterSize(30);
    GameDone.setStyle(sf::Text::Bold);
    GameDone.setFillColor(sf::Color::Red);
    GameDone.setOrigin(95,15);
    GameDone.setPosition(1000, 1000);


    sf::Text Help_text_sprite(Help_Text, font);
    Help_text_sprite.setCharacterSize(20);
    Help_text_sprite.setStyle(sf::Text::Bold);
    Help_text_sprite.setFillColor(sf::Color::White);
    Help_text_sprite.setPosition(1000, 1000);


    sf::Text Settings_text_sprite(Settings_Text, font);
    Settings_text_sprite.setCharacterSize(30);
    Settings_text_sprite.setStyle(sf::Text::Bold);
    Settings_text_sprite.setFillColor(sf::Color::White);
    Settings_text_sprite.setPosition(1000, 1000);


//----------------Sprite----------------

    sf::Sprite Background;
    Background.setTexture(texture);
    Background.setPosition(sf::Vector2f(0, 0));

    sf::IntRect rectSourceSprite(Bry_Cherry);
    sf::Sprite Berry(texture10,rectSourceSprite);
    Berry.setScale(2.f, 2.f);
    Berry.setPosition(1000,1000);

    sf::IntRect rectSourceSprite2(Pac_wack11);
    sf::Sprite PacDeath(texture12,rectSourceSprite2);
    PacDeath.setScale(2.5f, 2.5f);
    PacDeath.setPosition(1000,1000);

    sf::Sprite PacMan;
    PacMan.setTexture(texture2);
    PacMan.setPosition(sf::Vector2f(266, 326));
    PacMan.setOrigin(15,15);

    sf::Sprite OrangeGhost;
    OrangeGhost.setTexture(texture4);
    OrangeGhost.setPosition(sf::Vector2f(226, 266));
    OrangeGhost.setOrigin(15,15);
    Close.Orange = 23;

    sf::Sprite RedGhost;
    RedGhost.setTexture(texture5);
    RedGhost.setPosition(sf::Vector2f(246, 266));
    RedGhost.setOrigin(15,15);
    Close.Red = 23;

    sf::Sprite PinkGhost;
    PinkGhost.setTexture(texture6);
    PinkGhost.setPosition(sf::Vector2f(266, 266));
    PinkGhost.setOrigin(15,15);
    Close.Pink = 23;

    sf::Sprite BlueGhost;
    BlueGhost.setTexture(texture7);
    BlueGhost.setPosition(sf::Vector2f(300, 266));
    BlueGhost.setOrigin(15,15);
    Close.Blue = 23;

    sf::Sprite StartImage;
    StartImage.setTexture(texture9);
    StartImage.setPosition(sf::Vector2f(266, 150));
    StartImage.setOrigin(225,51);

    sf::Sprite Menu;
    Menu.setTexture(texture11);
    Menu.setPosition(sf::Vector2f(0, 0));
    Menu.setOrigin(0,0);
    Menu.setScale(10.f, 10.f);

    sf::Sprite Paused;
    Paused.setTexture(texture14);
    Paused.setPosition(sf::Vector2f(0, 0));
    Paused.setOrigin(25,31);
    Paused.setScale(1.f,1.f);
    Paused.setPosition(1000,1000);

    sf::Sprite Setting;
    Setting.setTexture(texture15);
    Setting.setOrigin(312,47);
    Setting.setPosition(sf::Vector2f(522/2.f,388.f));
    Setting.setScale(.7f,.7f);

    sf::Sprite Return;
    Return.setTexture(texture17);
    Return.setOrigin(136,47);
    Return.setPosition(sf::Vector2f(1000,1000));
    Return.setScale(.6f,.6f);

    sf::Sprite Help;
    Help.setTexture(texture19);
    Help.setOrigin(111,47);
    Help.setPosition(sf::Vector2f(522/2.f,488.f));
    Help.setScale(.6f,.6f);

    sf::Sprite Track1;
    Track1.setTexture(texture26);
    Track1.setOrigin(65,47);
    Track1.setPosition(sf::Vector2f(1000,1000));
    Track1.setScale(.6f,.6f);

    sf::Sprite Track2;
    Track2.setTexture(texture27);
    Track2.setOrigin(65,47);
    Track2.setPosition(sf::Vector2f(1000,1000));
    Track2.setScale(.6f,.6f);

    sf::Sprite Track3;
    Track3.setTexture(texture29);
    Track3.setOrigin(65,47);
    Track3.setPosition(sf::Vector2f(1000,1000));
    Track3.setScale(.6f,.6f);

//----------------Sprite Vectors----------------

    std::vector<sf::Sprite> YorN(3, sf::Sprite(texture21));

    for(int i = 0; i<3; i++) {

        YorN[i].setScale(.7f,.7f);
        YorN[i].setPosition(1000,1000);
    }


    std::vector<sf::Sprite> PacLife(3, sf::Sprite(texture2));
    PlaceLives(PacLife);


    std::vector<sf::RectangleShape> Dot(183);

    for (int i = 0; i < Dot.size(); i++) {

        Dot[i].setFillColor(sf::Color::White);
        Dot[i].setSize(sf::Vector2f(5, 5));
        Dot[i].setOrigin(2.5,2.5);
    }
    PlaceDots(Dot,image);


    std::vector<sf::RectangleShape> lineArr (700);

    for (int i = 0; i < lineArr.size(); i++) {

        lineArr[i].setFillColor(sf::Color::White);
    }


    std::vector<sf::CircleShape> PowerUp(4);

    for (int i = 0; i < PowerUp.size(); i++) {

        PowerUp[i].setFillColor(sf::Color::White);
        PowerUp[i].setRadius(10);
        PowerUp[i].setOrigin(10,10);
        PowerUp[i].setOutlineColor(sf::Color(250, 150, 100));
    }

    PowerUp[0].setPosition(30,30);
    PowerUp[2].setPosition(30,495);
    PowerUp[1].setPosition(495,30);
    PowerUp[3].setPosition(495,495);


    std::vector<sf::RectangleShape> Node(66);

    for (int i = 0; i < Node.size(); i++) {

        Node[i].setFillColor(sf::Color::White);
        Node[i].setSize(sf::Vector2f(10, 10));
        Node[i].setOrigin(5,5);
    }

    Node[0].setPosition(30,30);
    Node[1].setPosition(120,30);
    Node[2].setPosition(240,30);
    Node[3].setPosition(290,30);
    Node[4].setPosition(400,30);
    Node[5].setPosition(490,30);

    Node[6].setPosition(30,100);
    Node[7].setPosition(120,100);
    Node[8].setPosition(180,100);
    Node[9].setPosition(240,100);
    Node[10].setPosition(290,100);
    Node[11].setPosition(350,100);
    Node[12].setPosition(400,100);
    Node[13].setPosition(490,100);

    Node[14].setPosition(30,160);
    Node[15].setPosition(120,160);
    Node[16].setPosition(180,160);
    Node[17].setPosition(240,160);
    Node[18].setPosition(290,160);
    Node[19].setPosition(350,160);
    Node[20].setPosition(400,160);
    Node[21].setPosition(490,160);

    Node[22].setPosition(180,215);
    Node[23].setPosition(240,215);
    Node[24].setPosition(290,215);
    Node[25].setPosition(350,215);

    Node[26].setPosition(30,270);
    Node[27].setPosition(120,270);
    Node[28].setPosition(180,270);
    Node[29].setPosition(350,270);
    Node[30].setPosition(400,270);
    Node[31].setPosition(490,270);

    Node[32].setPosition(180,330);
    Node[33].setPosition(350,330);

    Node[34].setPosition(30,380);
    Node[35].setPosition(120,380);
    Node[36].setPosition(180,380);
    Node[37].setPosition(240,380);
    Node[38].setPosition(290,380);
    Node[39].setPosition(350,380);
    Node[40].setPosition(400,380);
    Node[41].setPosition(490,380);

    Node[42].setPosition(30,440);
    Node[43].setPosition(70,440);
    Node[44].setPosition(120,440);
    Node[45].setPosition(180,440);
    Node[46].setPosition(240,440);
    Node[47].setPosition(290,440);
    Node[48].setPosition(350,440);
    Node[49].setPosition(400,440);
    Node[50].setPosition(460,440);
    Node[51].setPosition(490,440);

    Node[52].setPosition(30,490);
    Node[53].setPosition(70,490);
    Node[54].setPosition(120,490);
    Node[55].setPosition(180,490);
    Node[56].setPosition(240,490);
    Node[57].setPosition(290,490);
    Node[58].setPosition(350,490);
    Node[59].setPosition(400,490);
    Node[60].setPosition(460,490);
    Node[61].setPosition(490,490);

    Node[62].setPosition(30,550);
    Node[63].setPosition(240,550);
    Node[64].setPosition(290,550);
    Node[65].setPosition(490,550);


    sf::Clock clock;
    while (window.isOpen()) {

        sf::Event event;


        //cout<<clock.getElapsedTime().asSeconds()<<endl;
        //float dt = clock.restart().asSeconds();
        //float dt = 1;


        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                SaveHS(highscore,score,HSString,NewHS);

                window.close();
                return 69;
            }

            if (event.type == sf::Event::Resized) {
                /*
                                sf::Vector2f size = static_cast<sf::Vector2f>(window.getSize());

                                if(size.x > 800) {
                                    size.x = 522*1.6;
                                }

                                if(size.y > 800) {
                                    size.y = 620*1.6;
                                }

                                window.setSize(static_cast<sf::Vector2u>(size));
                */


                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));


            }

//------------------Buttons------------------

// get the current mouse position in the window
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
// convert it to world coordinates
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

            /*
            if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {
                cout<<worldPos.x<<" "<<worldPos.y<<endl;
            }
            */
            //  if(isSpriteHover(Setting.getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
            if(isSpriteHover(Setting.getGlobalBounds(), sf::Vector2f(worldPos.x, worldPos.y)) == true) {

                Setting.setTexture(texture16);

                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    In_Settings = true;

                    if(Sound_Ef == true) {
                        Button_click.play();
                    }

                    Help.setPosition(1000, 1000);
                    Setting.setPosition(1000, 1000);
                    StartImage.setPosition(1000, 1000);
                    PreStart.setPosition(1000,1000);

                    Settings_text_sprite.setPosition(100, 10);
                    Track1.setPosition(sf::Vector2f(150.f,450.f));
                    Track2.setPosition(sf::Vector2f(250.f,450.f));
                    Track3.setPosition(sf::Vector2f(350.f,450.f));
                    Return.setPosition(sf::Vector2f(522/2.f,550.f));

                    for(int i = 0; i<3; i++) {
                        YorN[i].setPosition(400,i*90+10);
                    }
                }
            } else {

                Setting.setTexture(texture15);
            }


            if(isSpriteHover(Return.getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {

                Return.setTexture(texture18);

                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    In_Settings = false;

                    Return.setPosition(1000, 1000);
                    Help.setPosition(sf::Vector2f(522/2.f,488.f));
                    StartImage.setPosition(sf::Vector2f(266, 150));
                    PreStart.setPosition(522/2, 620/2);
                    Setting.setPosition(sf::Vector2f(522/2.f,388.f));
                    Help_text_sprite.setPosition(1000, 1000);
                    Settings_text_sprite.setPosition(1000, 1000);
                    Track1.setPosition(sf::Vector2f(1000,1000));
                    Track2.setPosition(sf::Vector2f(1000,1000));
                    Track3.setPosition(sf::Vector2f(1000,1000));

                    if(Sound_Ef == true) {
                        Button_click.play();
                    }

                    for(int i = 0; i<3; i++) {
                        YorN[i].setPosition(1000,1000);
                    }
                }
            } else {

                Return.setTexture(texture17);
            }


            if(isSpriteHover(Help.getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {

                Help.setTexture(texture20);
                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    In_Settings = true;

                    if(Sound_Ef == true) {
                        Button_click.play();
                    }

                    Return.setPosition(sf::Vector2f(522/2.f,550.f));
                    Help.setPosition(1000, 1000);
                    Setting.setPosition(1000, 1000);
                    StartImage.setPosition(1000, 1000);
                    PreStart.setPosition(1000,1000);
                    Help_text_sprite.setPosition(0, 100);

                }
            } else {
                Help.setTexture(texture19);
            }

            if(isSpriteHover(YorN[0].getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {


                if(Master_Vol == false) {
                    YorN[0].setTexture(texture24);
                } else {
                    YorN[0].setTexture(texture22);
                }

                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    if(Sound_Ef == true) {
                        Button_click.play();
                    }

                    if(Master_Vol == true) {

                        Master_Vol = false;
                        Music = false;
                        Sound_Ef = false;

                        BackG_Wii.stop();
                        YorN[0].setTexture(texture23);
                        YorN[1].setTexture(texture23);
                        YorN[2].setTexture(texture23);

                    } else {
                        Master_Vol = true;
                        YorN[0].setTexture(texture21);
                    }
                }
            } else {

                if(Master_Vol == false) {
                    YorN[0].setTexture(texture23);
                } else {
                    YorN[0].setTexture(texture21);
                }
            }

            if(isSpriteHover(YorN[1].getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {

                if(Music == false) {
                    YorN[1].setTexture(texture24);
                } else {
                    YorN[1].setTexture(texture22);
                }
                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    if(Sound_Ef == true) {
                        Button_click.play();
                    }
                    if(Master_Vol == true && Music == false) {

                        YorN[1].setTexture(texture21);
                        Music = true;
                        BackG_Wii.play();

                    } else if(Master_Vol == true && Music == true) {

                        Music = false;
                        BackG_Wii.stop();
                        YorN[1].setTexture(texture23);
                    }
                }
            } else {

                if(Music == false) {
                    YorN[1].setTexture(texture23);
                } else {
                    YorN[1].setTexture(texture21);
                }
            }

            if(isSpriteHover(YorN[2].getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(Sound_Ef == false) {
                    YorN[2].setTexture(texture24);
                } else {
                    YorN[2].setTexture(texture22);
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    if(Master_Vol == true) {
                        Button_click.play();
                    }
                    if(Master_Vol == true && Sound_Ef == false) {

                        YorN[2].setTexture(texture21);
                        Sound_Ef = true;

                    } else if(Master_Vol == true && Sound_Ef == true) {

                        Sound_Ef = false;
                        YorN[2].setTexture(texture23);
                    }
                }
            } else {
                if(Sound_Ef == false) {
                    YorN[2].setTexture(texture23);
                } else {
                    YorN[2].setTexture(texture21);
                }
            }

            if(isSpriteHover(Track1.getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {

                Track1.setTexture(texture26);

                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    Track = 1;
                    Track2.setTexture(texture27);
                    Track3.setTexture(texture29);
                    if(Sound_Ef == true) {
                        Button_click.play();
                    }
                }
            } else {
                if(Track != 1) {
                    Track1.setTexture(texture25);
                }
            }

            if(isSpriteHover(Track2.getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {

                Track2.setTexture(texture28);

                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    Track = 2;

                    Track1.setTexture(texture25);
                    Track3.setTexture(texture29);
                    if(Sound_Ef == true) {
                        Button_click.play();
                    }
                }
            } else {

                if(Track != 2) {
                    Track2.setTexture(texture27);
                }
            }


            if(isSpriteHover(Track3.getGlobalBounds(), sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {

                Track3.setTexture(texture30);

                if(Sound_Ef == true) {
                    Button_select.play();
                }

                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                    Track = 3;

                    Track1.setTexture(texture25);
                    Track2.setTexture(texture27);
                    if(Sound_Ef == true) {
                        Button_click.play();
                    }
                }
            } else {

                if(Track != 3) {
                    Track3.setTexture(texture29);
                }
            }
        }

// ------------------Start Game------------------

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& start_game == true && In_Settings == false) {

            State = 0;

            start_game = false;
            Game_over = false;
            deathTimerOnce = true;

            ised.red = false;
            ised.blue = false;
            ised.orange = false;
            ised.pink = false;

            Deadmove.red = false;
            Deadmove.orange = false;
            Deadmove.blue = false;
            Deadmove.pink = false;

            dotsEaten = 0;
            x = 0,y = 0;
            score = 0;
            Berrytimer = 0;
            lives = 2;
            powerUpTimer = 601;

            BackG_Wii.stop();

            if(Sound_Ef == true) {
                Button_click.play();
                Mac_start.play();
            }

            OneFree = true;

            if(Music == true) {

                if(Track == 1) {
                    BackG_Pizza.play();
                }
                if(Track == 2) {
                    BackG_Subwooder.play();
                }
                if(Track == 3) {
                    BackG_Sweden.play();
                }
            }

            PowerUp[0].setPosition(30,30);
            PowerUp[2].setPosition(30,495);
            PowerUp[1].setPosition(495,30);
            PowerUp[3].setPosition(495,495);

            Setting.setPosition(1000, 1000);
            Help.setPosition(1000, 1000);
            StartImage.setPosition(1000, 1000);
            PreStart.setPosition(1000,1000);

            PlaceLives(PacLife);
            PlaceDots(Dot,image);

        }

//------------------Pause------------------

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

            if(PauseGame == false && start_game == false && PauseTimer >20) {

                PauseGame = true;
                Paused.setPosition(261,288);
                BackG_Pizza.pause();
                BackG_Subwooder.pause();
                BackG_Sweden.pause();
            }

            else if(PauseGame == true && start_game == false && PauseTimer > 50) {

                PauseTimer = 0;
                PauseGame = false;
                Paused.setPosition(1000,1000);

                if(Music == true) {

                    if(Track == 1) {

                        BackG_Pizza.play();
                    }
                    if(Track == 2) {

                        BackG_Subwooder.play();
                    }

                    if(Track == 3) {

                        BackG_Sweden.play();
                    }
                }
            }
        }


// -------------------PacMan -------------------

// Wall check
        PacManCheck(PacMan, image, LeftWallPos, RigthWallPos, UpWallPos, DownWallPos);

//Key input & movement

        PacManKeyInput(PacMan, image, LeftWallPos, RigthWallPos, UpWallPos, DownWallPos, x, y);


// -------------------Orange ghost -------------------

// Wall check

        OrangeghostCheck(OrangeGhost,image, Orange);

//basic Navigation

        OrangeGhost_Nav_Basic(OrangeGhost, PacMan, Orange, OrangeDown, OrangeUp, OrangeLeft, OrangeRight);

//Advanced Navigation

        OrangeGhost_Nav_Advan(OrangeGhost, PacMan, Orange, OrangeDown, OrangeUp, OrangeLeft, OrangeRight, OrangeUpOnce, OrangeDownOnce, OrangeLeftOnce, OrangeRightOnce);

//Move

        OrangeGhost_Move(OrangeGhost, PacMan, Orange, image, OrangeDown, OrangeUp, OrangeLeft, OrangeRight, OrangeUpOnce, OrangeDownOnce, OrangeLeftOnce, OrangeRightOnce, OrangeX, OrangeY);


//-------------- Red ghost -------------------

// Wall check

        RedghostCheck(RedGhost, image, Red);

//basic Navigation

        RedGhost_Nav_Basic(RedGhost, PacMan, Red, RedDown, RedUp, RedLeft, RedRight);

//Advanced Navigation

        RedGhost_Nav_Advan(RedGhost, PacMan, Red, RedDown,RedUp,RedLeft, RedRight, RedUpOnce, RedDownOnce, RedLeftOnce, RedRightOnce);

//Move

        RedGhost_Move(RedGhost, PacMan, Red, image, RedDown,RedUp,RedLeft, RedRight, RedUpOnce, RedDownOnce, RedLeftOnce, RedRightOnce, RedX, RedY);


// -------------------BLUE ghost -------------------

// Wall check

        BlueghostCheck(BlueGhost, image, Blue);

//basic Navigation

        BlueGhost_Nav_Basic(BlueGhost, PacMan, Blue, BlueDown, BlueUp, BlueLeft, BlueRight);

//Advanced Navigation

        BlueGhost_Nav_Advan(BlueGhost, PacMan, Blue, BlueDown, BlueUp, BlueLeft, BlueRight, BlueUpOnce, BlueDownOnce, BlueLeftOnce, BlueRightOnce);

//Move

        BlueGhost_Move(BlueGhost, PacMan, Blue, image, BlueDown, BlueUp, BlueLeft, BlueRight, BlueUpOnce, BlueDownOnce, BlueLeftOnce, BlueRightOnce, BlueX, BlueY);


//-------------------PINK ghost-------------------

// Wall check

        PinkghostCheck(PinkGhost, image, Pink);

//basic Navigation

        PinkGhost_Nav_Basic(PinkGhost, PacMan,Pink, PinkDown, PinkUp,PinkLeft, PinkRight);

//Advanced Navigation

        PinkGhost_Nav_Advan(PinkGhost, PacMan, Pink, PinkDown, PinkUp, PinkLeft, PinkRight, PinkUpOnce, PinkDownOnce, PinkLeftOnce, PinkRightOnce);

//Move

        PinkGhost_Move(PinkGhost, PacMan, Pink, image, PinkDown, PinkUp, PinkLeft, PinkRight, PinkUpOnce, PinkDownOnce, PinkLeftOnce, PinkRightOnce, PinkX, PinkY);

// -------------------

// teleport

        if(Teleport(PacMan, OrangeGhost, RedGhost, PinkGhost, BlueGhost)) {
            if(Sound_Ef == true) {
                XP_Tele.play();
            }
        }


// Power Pellet animation

        PowerPelletAni(PowerUp, Pwr_ani_frame, glowTimer);


//stop Power pellet Effect

        PowerStop(powerUpTimer, OrangeGhost, RedGhost, PinkGhost, BlueGhost, texture4, texture5, texture6, texture7, texture8, texture8_2, ised, Deadmove);


// create berry

        if(start_game == false) {
            BerryPlace(Berry, Berrytimer);
        }

// Score Update

        scoreUpdate(HsDis, scoreDis, score, highscore, scoreShow, HSString);


//PacMan animation

        PacAni(PacMan, texture2,texture3, timer);



// -------------------Hittest-------------------

// --Dot Hittest--

        for (int i = 0; i < Dot.size(); i++) {
            if(PacMan.getGlobalBounds().intersects(Dot[i].getGlobalBounds())) {
// deletes itself then Adds 5 to score
                Dot[i].setPosition(1000,1000);
                if(Sound_Ef == true) {
                    XP_Dot.play();
                }
                dotsEaten ++;
                score +=5;
            }
        }

// --Berry Hittest--

        if(PacMan.getGlobalBounds().intersects(Berry.getGlobalBounds())) {

            if(Sound_Ef == true) {
                Fortnite_Clap.play();
            }

            Berry.setPosition(1000,1000);
            score +=200;
        }


// --Power Up hittest--

        for (int i = 0; i < PowerUp.size(); i++) {
            if(PacMan.getGlobalBounds().intersects(PowerUp[i].getGlobalBounds())) {
// If a ghost is not dead it will become edible
                powerUpTimer = 0;
                score +=10;
                PowerUp[i].setPosition(1000,1000);

                if(Sound_Ef == true) {
                    PowerSound.play();
                }

                if(ised.orange == false&& Deadmove.orange == false) {
                    OrangeGhost.setTexture(texture8);
                    ised.orange= true;
                }

                if(ised.red == false && Deadmove.red == false) {
                    RedGhost.setTexture(texture8);
                    ised.red = true;
                }

                if(ised.pink == false && Deadmove.pink == false) {
                    PinkGhost.setTexture(texture8);
                    ised.pink = true;
                }

                if(ised.blue == false && Deadmove.blue == false) {
                    BlueGhost.setTexture(texture8);
                    ised.blue = true;
                }
            }
        }

// --Red Ghost Hittest--

        if(Deadmove.red == false) {
// If the ghost is not dead

            if(PacMan.getGlobalBounds().intersects(RedGhost.getGlobalBounds())&& ised.red == false) {
// if you can't kill the ghost
                if(killonce == true) {

                    DieHit(PacDead, Sound_Ef, Dead, BackG_Pizza, BackG_Subwooder, BackG_Sweden, death_ani_Timer, PacDeath, PacMan);

                    killonce = false;
                }
            }

            if(PacMan.getGlobalBounds().intersects(RedGhost.getGlobalBounds())&& ised.red == true) {
// if you can kill the ghost
                if(Sound_Ef == true) {
                    Yay.play();
                }
                Deadmove.red = true;
                score +=100;
                ised.red = false;
                RedGhost.setTexture(texture13);
            }
        }


// --Orange Ghost Hittest--

        if(Deadmove.orange == false) {

            if(PacMan.getGlobalBounds().intersects(OrangeGhost.getGlobalBounds())&& ised.orange == false) {

                if(killonce == true) {

                    DieHit(PacDead, Sound_Ef, Dead, BackG_Pizza, BackG_Subwooder, BackG_Sweden, death_ani_Timer, PacDeath, PacMan);

                    killonce = false;
                }
            }

            if(PacMan.getGlobalBounds().intersects(OrangeGhost.getGlobalBounds())&& ised.orange == true) {

                if(Sound_Ef == true) {
                    Yay.play();
                }
                Deadmove.orange = true;
                score +=100;
                ised.orange = false;
                OrangeGhost.setTexture(texture13);
            }
        }


// --Pink Ghost Hittest--

        if(Deadmove.pink == false) {

            if(PacMan.getGlobalBounds().intersects(PinkGhost.getGlobalBounds())&& ised.pink == false) {

                if(killonce == true) {

                    PacDead = true;

                    DieHit(PacDead, Sound_Ef, Dead, BackG_Pizza, BackG_Subwooder, BackG_Sweden, death_ani_Timer, PacDeath, PacMan);

                    killonce = false;
                }
            }

            if(PacMan.getGlobalBounds().intersects(PinkGhost.getGlobalBounds())&& ised.pink == true) {

                if(Sound_Ef == true) {
                    Yay.play();
                }
                Deadmove.pink = true;
                score +=100;
                ised.pink = false;
                PinkGhost.setTexture(texture13);

            }
        }


// --Blue Ghost Hittest--

        if(Deadmove.blue == false) {

            if(PacMan.getGlobalBounds().intersects(BlueGhost.getGlobalBounds())&& ised.blue == false) {

                if(killonce == true) {

                    PacDead = true;

                    DieHit(PacDead, Sound_Ef, Dead, BackG_Pizza, BackG_Subwooder, BackG_Sweden, death_ani_Timer, PacDeath, PacMan);

                    killonce = false;
                }
            }

            if(PacMan.getGlobalBounds().intersects(BlueGhost.getGlobalBounds())&& ised.blue == true) {

                if(Sound_Ef == true) {
                    Yay.play();
                }
                Deadmove.blue = true;
                score +=100;
                ised.blue = false;
                BlueGhost.setTexture(texture13);

            }
        }


// -------------------death animation and code to reset game -------------------


        if(PacDeathAni(PacDeath, PacMan, death_ani_Timer)) {

            //After the Pacman Death animation plays the game resets back to normal ->
            killonce = true;
            PacDead = false;

            ised.red = false;
            ised.orange = false;
            ised.blue = false;
            ised.pink = false;

            Close.Red = 23;
            Close.Orange = 23;
            Close.Blue = 23;
            Close.Pink = 23;

            x = 0;
            y = 0;
            Close.Pac = 32;
            PacLife[lives].setPosition(1000,1000);
            lives--;

            PacDeath.setPosition(1000,1000);
            PacMan.setPosition(sf::Vector2f(266, 326));
            OrangeGhost.setPosition(sf::Vector2f(226, 266));
            RedGhost.setPosition(sf::Vector2f(246, 266));
            PinkGhost.setPosition(sf::Vector2f(266, 266));
            BlueGhost.setPosition(sf::Vector2f(300, 266));

            OrangeGhost.setTexture(texture4);
            RedGhost.setTexture(texture5);
            PinkGhost.setTexture(texture6);
            BlueGhost.setTexture(texture7);

            if(Music == true) {

                if(Track == 1) {
                    BackG_Pizza.play();
                }
                if(Track == 2) {
                    BackG_Subwooder.play();

                }
                if(Track == 3) {
                    BackG_Sweden.play();
                }
            }
        }


// -------------------eye code-------------------

// calls a function that moves the ghosts back to spawn

        DeadMover(Deadmove.red, RedGhost, RedX, RedY, Close.Red, 246, 267, texture5);
        DeadMover(Deadmove.orange, OrangeGhost, OrangeX, OrangeY, Close.Orange, 226, 267, texture4);
        DeadMover(Deadmove.blue, BlueGhost, BlueX, BlueY, Close.Blue, 267, 267, texture7);
        DeadMover(Deadmove.pink, PinkGhost, PinkX, PinkY, Close.Pink, 300, 267, texture6);


// -------------------Next Level-------------------

        if(dotsEaten == 183) {


            OrangeGhost.setPosition(sf::Vector2f(226, 266));
            RedGhost.setPosition(sf::Vector2f(246, 266));
            PinkGhost.setPosition(sf::Vector2f(266, 266));
            BlueGhost.setPosition(sf::Vector2f(300, 266));

            Close.Red = 23;
            Close.Orange = 23;
            Close.Blue = 23;
            Close.Pink = 23;

            Deadmove.red = false;
            Deadmove.orange = false;
            Deadmove.blue = false;
            Deadmove.pink = false;


            PacMan.setPosition(sf::Vector2f(266, 326));
            x = 0;
            y = 0;
            Close.Pac = 32;
            dotsEaten = 0;
            Berrytimer = 0;
            powerUpTimer = 601;

            if(Sound_Ef == true) {
                Mac_start.play();
            }

            PowerUp[0].setPosition(30,30);
            PowerUp[2].setPosition(30,495);
            PowerUp[1].setPosition(495,30);
            PowerUp[3].setPosition(495,495);

            ised.red = false;
            ised.orange = false;
            ised.blue = false;
            ised.pink = false;

            OrangeGhost.setTexture(texture4);
            RedGhost.setTexture(texture5);
            PinkGhost.setTexture(texture6);
            BlueGhost.setTexture(texture7);

            PlaceDots(Dot,image);
        }


//-------------------Pacman free life-------------------

        if((score> highscore) &&(lives < 3) && (OneFree == true)) {

            OneFree = false;
            lives+=1;
        }

//-------------------Game Over-------------------

        if(lives < 0 && deathTimerOnce == true) {

            State = 1;

            deathTimerOnce = false;
            death_timer = 0;
            GameDone.setPosition(522/2, 322);

            SaveHS(highscore,score,HSString,NewHS);

            BackG_Pizza.stop();
            BackG_Subwooder.stop();
            BackG_Sweden.stop();

            if(Sound_Ef == true) {
                XP_End.play();
            }

            Game_over = true;
            death_timer = 0;
        }


// -------------------Back to Main Menu-------------------

        if(Game_over == true && start_game == false &&death_timer == 120) {

            start_game = true;

            if(Music == true) {

                BackG_Wii.play();
            }

            NewHS.setPosition(1000,1000);
            GameDone.setPosition(1000, 1000);
            Help.setPosition(sf::Vector2f(522/2.f,488.f));
            StartImage.setPosition(sf::Vector2f(266, 150));
            PreStart.setPosition(522/2, 620/2);
            Setting.setPosition(sf::Vector2f(522/2.f,388.f));
        }


// This code  would have origonaly used the Breadth First Search Algorithm to make the ghosts better, unfortunatly I was unable to get this done in time, but I though you might want to see my attempt's to implement it.
// what it currently does is put a line to which every node Pacman and the red ghost is closest to. I would then have found a way to make a path between those two nodes, but like I said I didn't have time.

        //PacMan
        for(int i = 0; i<Node.size(); i++) {
            if(PacMan.getPosition().x - Node[i].getPosition().x > 0) {
                Diff.Pac_X.push_back(PacMan.getPosition().x - Node[i].getPosition().x);
            } else {
                Diff.Pac_X.push_back(Node[i].getPosition().x- PacMan.getPosition().x);
            }
            if(PacMan.getPosition().y - Node[i].getPosition().y > 0) {
                Diff.Pac_Y.push_back(PacMan.getPosition().y - Node[i].getPosition().y);
            } else {
                Diff.Pac_Y.push_back(Node[i].getPosition().y- PacMan.getPosition().y);
            }
        }
        //Red Ghost
        for(int i = 0; i<Node.size(); i++) {
            if(RedGhost.getPosition().x - Node[i].getPosition().x > 0) {
                Diff.Red_X.push_back(RedGhost.getPosition().x - Node[i].getPosition().x);
            } else {
                Diff.Red_X.push_back(Node[i].getPosition().x- RedGhost.getPosition().x);
            }
            if(RedGhost.getPosition().y - Node[i].getPosition().y > 0) {
                Diff.Red_Y.push_back(RedGhost.getPosition().y - Node[i].getPosition().y);
            } else {
                Diff.Red_Y.push_back(Node[i].getPosition().y - RedGhost.getPosition().y);
            }
        }
       // findSmallestElement(PacClose,Close,Diff);
      //  paths(PacClose,Close,PacMan,Node,lineArr, RedGhost, image);









        PauseTimer++;

        if(PauseGame == false) {

            timer++;
            death_timer ++;
            powerUpTimer ++;
            death_ani_Timer ++;
            Berrytimer++;
            glowTimer++;

            //Move
            if(Game_over == false && PacDead == false) {

                PacMan.move(x,y);
                OrangeGhost.move(OrangeX, OrangeY);
                RedGhost.move(RedX, RedY);
                PinkGhost.move(PinkX, PinkY);
                BlueGhost.move(BlueX, BlueY);
            }
        }


        // Draw

        window.clear();

        window.setView(view);

        if(State == 0) {

            window.draw(Background);

            for (int i = 0; i < Dot.size(); i++) {

                window.draw(Dot[i]);
            }

            for (int i = 0; i < PowerUp.size(); i++) {

                window.draw(PowerUp[i]);
            }

            for(int i = 0; i<PacLife.size(); i++) {

                window.draw(PacLife[i]);
            }


            for(int i = 0; i <Node.size(); i++) {

                window.draw(Node[i]);
            }

            for(int i = 0; i <lineArr.size(); i++) {

                window.draw(lineArr[i]);
            }





            window.draw(scoreDis);
            window.draw(HsDis);
            window.draw(Berry);


            if(PacDead == false)
                window.draw(PacMan);

            window.draw(OrangeGhost);
            window.draw(RedGhost);
            window.draw(PinkGhost);
            window.draw(BlueGhost);

            window.draw(PacDeath);

            window.draw(Paused);
        }

        if(State == 1) {

            window.draw(Menu);

            window.draw(NewHS);

            for(int i = 0; i<3; i++) {
                window.draw(YorN[i]);
            }

            window.draw(Setting);
            window.draw(Return);
            window.draw(Help);
            window.draw(Help_text_sprite);
            window.draw(Settings_text_sprite);

            window.draw(Track1);
            window.draw(Track2);
            window.draw(Track3);

            window.draw(StartImage);
            window.draw(PreStart);
            window.draw(GameDone);
        }

        sf::View currentView = window.getView();

        window.display();
    }

    return 0;
}
