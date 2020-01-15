#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <chrono>
#include <vector>
#include <sstream>
#include <fstream>

#include <Images.h>

using namespace std;


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

    bool LeftWallPos = false, RigthWallPos = false, UpWallPos = false, DownWallPos = false;

};
WhereWall Blue;
WhereWall Pink;


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


bool OrangeghostCheck(sf::Sprite OrangeGhost, sf::Image image, bool &OrangeLeftWallPos, bool &OrangeRigthWallPos, bool &OrangeUpWallPos, bool &OrangeDownWallPos) {


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

                    OrangeDownWallPos = true;
                    OrangeUpWallPos = false;
                } else {

                    OrangeDownWallPos = false;

                }


                if (image.getPixel(tempx, OrangeGhost.getPosition().y+7) == wallcolor) {

                    OrangeRigthWallPos = true;
                    OrangeLeftWallPos = false;
                } else {

                    OrangeRigthWallPos = false;

                }

                onceTrue = true;
            }

            if (image.getPixel(tempxx, tempyy) == wallcolor) {


                if (image.getPixel(OrangeGhost.getPosition().x-7, tempyy) == wallcolor) {

                    OrangeUpWallPos = true;
                    OrangeDownWallPos = false;

                } else {
                    OrangeUpWallPos = false;
                }

                if (image.getPixel(tempxx, OrangeGhost.getPosition().y-7) == wallcolor) {

                    OrangeLeftWallPos = true;
                    OrangeRigthWallPos = false;
                } else {
                    OrangeLeftWallPos = false;
                }

                onceTrue = true;

            }

            if (image.getPixel(tempxxx, tempyyy) == wallcolor) {

                if (image.getPixel(OrangeGhost.getPosition().x+7, tempyyy) == wallcolor) {

                    OrangeUpWallPos = true;
                    OrangeDownWallPos = false;
                } else {
                    OrangeUpWallPos = false;
                }

                if (image.getPixel(tempxxx, OrangeGhost.getPosition().y-7) == wallcolor) {

                    OrangeRigthWallPos = true;
                    OrangeLeftWallPos = false;

                } else {
                    OrangeRigthWallPos = false;
                }

                onceTrue = true;
            }


            if (image.getPixel(tempxxxx, tempyyyy) == wallcolor) {


                if (image.getPixel(OrangeGhost.getPosition().x-7, tempyyyy) == wallcolor) {

                    OrangeDownWallPos = true;
                    OrangeUpWallPos = false;
                } else {
                    OrangeDownWallPos = false;
                }

                if (image.getPixel(tempxxxx, OrangeGhost.getPosition().y+7) == wallcolor) {

                    OrangeLeftWallPos = true;
                    OrangeRigthWallPos = false;
                } else {
                    OrangeLeftWallPos = false;
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


bool RedghostCheck(sf::Sprite RedGhost, sf::Image image, bool &RedLeftWallPos, bool &RedRigthWallPos, bool &RedUpWallPos, bool &RedDownWallPos, sf::Sprite PacMan) {


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

                    RedDownWallPos = true;
                    RedUpWallPos = false;
                } else {

                    RedDownWallPos = false;

                }


                if (image.getPixel(tempx, RedGhost.getPosition().y+7) == wallcolor) {

                    RedRigthWallPos = true;
                    RedLeftWallPos = false;
                } else {

                    RedRigthWallPos = false;

                }

                onceTrue = true;
            }

            if (image.getPixel(tempxx, tempyy) == wallcolor) {


                if (image.getPixel(RedGhost.getPosition().x-7, tempyy) == wallcolor) {

                    RedUpWallPos = true;
                    RedDownWallPos = false;

                } else {
                    RedUpWallPos = false;
                }

                if (image.getPixel(tempxx, RedGhost.getPosition().y-7) == wallcolor) {

                    RedLeftWallPos = true;
                    RedRigthWallPos = false;
                } else {
                    RedLeftWallPos = false;
                }

                onceTrue = true;

            }

            if (image.getPixel(tempxxx, tempyyy) == wallcolor) {

                if (image.getPixel(RedGhost.getPosition().x+7, tempyyy) == wallcolor) {

                    RedUpWallPos = true;
                    RedDownWallPos = false;
                } else {
                    RedUpWallPos = false;
                }

                if (image.getPixel(tempxxx, RedGhost.getPosition().y-7) == wallcolor) {

                    RedRigthWallPos = true;
                    RedLeftWallPos = false;

                } else {
                    RedRigthWallPos = false;
                }

                onceTrue = true;
            }


            if (image.getPixel(tempxxxx, tempyyyy) == wallcolor) {


                if (image.getPixel(RedGhost.getPosition().x-7, tempyyyy) == wallcolor) {

                    RedDownWallPos = true;
                    RedUpWallPos = false;
                } else {
                    RedDownWallPos = false;
                }

                if (image.getPixel(tempxxxx, RedGhost.getPosition().y+7) == wallcolor) {

                    RedLeftWallPos = true;
                    RedRigthWallPos = false;
                } else {
                    RedLeftWallPos = false;
                }

                onceTrue = true;
            }
/////////



//////////

            if(onceTrue == true) {

                return true;
            }

        }
    }

    return false;

}


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


    cout<<"Pac is close to Node: "<<Close.Pac<<endl;
    cout<<"Red is close to Node: "<<Close.Red<<endl;


    Diff.Red_X.clear();
    Diff.Red_Y.clear();
    Diff.Pac_X.clear();
    Diff.Pac_Y.clear();
}


void paths(int &PacClose,near &Close,sf::Sprite PacMan,std::vector<sf::RectangleShape> &Node,std::vector<sf::RectangleShape> &lineArr,sf::Sprite RedGhost,sf::Sprite OrangeGhost) {

//start at a Node
//get end Node
//calculate shortest distance using nodes

//start == PacClose
//end == Node[0];



//start
    Node[PacClose].getPosition().x;
    Node[PacClose].getPosition().y;

//end
    Node[0].getPosition().x;
    Node[0].getPosition().y;


//lineArr[1].setPosition(PacMan.getPosition().x,PacMan.getPosition().y);



    int Pacxline, Pacyline;
    int Redxline, Redyline;

    vector<int> path;

    lineArr[0].setPosition(sf::Vector2f(PacMan.getPosition().x, PacMan.getPosition().y));
    Pacxline = Node[PacClose].getPosition().x-PacMan.getPosition().x;
    Pacyline = Node[PacClose].getPosition().y-PacMan.getPosition().y;

    if(Pacyline > 0)
        lineArr[0].setSize(sf::Vector2f(Pacxline+2, Pacyline+2));


    if(Pacyline <0)
        lineArr[0].setSize(sf::Vector2f(Pacxline-2, Pacyline-2));

    /*
    if(Node[PacClose+1].getPosition().x < Node[0].getPosition().x) {

    cout<<"this worked"<<endl;

    if(Node[PacClose-1].getPosition().x < Node[0].getPosition().x) {

        cout<<"go to node "<<PacClose-1<<endl;
    } else {
        cout<<"go to node "<<PacClose+1<<endl;
    }
    }
    */
    lineArr[1].setPosition(sf::Vector2f(RedGhost.getPosition().x, RedGhost.getPosition().y));
    Redxline = Node[Close.Red].getPosition().x-RedGhost.getPosition().x;
    Redyline = Node[Close.Red].getPosition().y-RedGhost.getPosition().y;

    if(Redyline > 0)
        lineArr[1].setSize(sf::Vector2f(Redxline+2, Redyline+2));


    if(Redyline <0)
        lineArr[1].setSize(sf::Vector2f(Redxline-2, Redyline-2));







    /*
         for(int i=0; i<Node.size(); i++) {
        for(int j=0; j<Node.size(); j++) {

       path.push_back(Node[i].getPosition().x + Node[j].getPosition().x - Node[PacClose].getPosition().x);
         }
        }
    */


}


void findPath(int &PacClose,near &Close,sf::Sprite PacMan,std::vector<sf::RectangleShape> &Node) {

    vector< vector <int>> placeholder(1);

    for(int i = 0; i < Node.size(); i++) {
        Node[i].getPosition().x;
        Node[i].getPosition().y;
    }



}


void SaveHS(int &highscore, int &score,string &HSString,sf::Text &NewHS) {

    ifstream readFile;
    readFile.open("Assets/High_Score.txt");

    if(readFile.is_open()) {

        while(!readFile.eof()) {

            readFile >> highscore;
        }

    }
    readFile.close();

    ofstream writeFile("Assets/High_Score.txt");
    if(writeFile.is_open()) {

        stringstream ss3;
        ss3<<highscore;
        ss3>>HSString;

        if(score>highscore) {

            highscore = score;

            NewHS.setPosition(522/2, 340);
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


int main() {

    int timer = 0;
    int glowTimer = 0;
    int powerUpTimer = 0;
    int Berrytimer = 0;
    int death_ani_Timer = 90;
    int death_timer = 0;

    int score = 0;
    int highscore;

    int PacClose = 32;
    int lives = 2;
    int dotsEaten = 0;
    int randtemp;
    int Pwr_ani_frame = 1;

    int x = 0,y = 0;
    int OrangeX = 0, Orangey = 0;
    int RedX = 0, RedY = 0;
    int PinkX = 0, PinkY = 0;
    int BlueX = 0, BlueY = 0;


    bool Left = false, Right = false, Up = false, Down = false;
    bool LeftWallPos = false, RigthWallPos = false, UpWallPos = false, DownWallPos = false;

    bool OrangeLeft = false, OrangeRight = false, OrangeUp = false, OrangeDown = false;
    bool OrangeLeftWallPos = false, OrangeRigthWallPos = false, OrangeUpWallPos = false, OrangeDownWallPos = false;
    bool OrangeUpOnce = false,OrangeDownOnce = false, OrangeLeftOnce = false, OrangeRightOnce = false;

    bool RedLeft = false, RedRight = false, RedUp = false, RedDown = false;
    bool RedLeftWallPos = false, RedRigthWallPos = false, RedUpWallPos = false, RedDownWallPos = false;
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

    string scoreShow;
    string HSString;

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


    srand (time(NULL));


    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(522, 620), "Pac Man", sf::Style::Default,settings);
    window.setFramerateLimit(60);

    //////
    //Load Assets

    sf::Image image;
    image.loadFromFile("Assets/PacMan_background.png");

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Texture texture2;
    texture2.loadFromFile("Assets/PacMan_open.png");

    sf::Texture texture3;
    texture3.loadFromFile("Assets/PacMan_closed.png");

    sf::Texture texture4;
    texture4.loadFromFile("Assets/OrangeGhostRight.png");

    sf::Texture texture5;
    texture5.loadFromFile("Assets/RedGhostRight.png");

    sf::Texture texture6;
    texture6.loadFromFile("Assets/PinkGhostRight.png");

    sf::Texture texture7;
    texture7.loadFromFile("Assets/BlueGhostRight.png");

    sf::Texture texture8;
    texture8.loadFromFile("Assets/DeadGhost.png");

    sf::Texture texture8_2;
    texture8_2.loadFromFile("Assets/WhiteDeadGhost.png");

    sf::Texture texture9;
    texture9.loadFromFile("Assets/PacMan-Start.png");

    sf::Texture texture10;
    texture10.loadFromFile("Assets/Berry_Sprite_Sheet.png");

    sf::Texture texture11;
    texture11.loadFromFile("Assets/Solid_black.png");

    sf::Texture texture12;
    texture12.loadFromFile("Assets/Pac-Death-SpriteSheet.png");

    sf::Texture texture13;
    texture13.loadFromFile("Assets/eyes.png");

    sf::Texture texture14;
    texture14.loadFromFile("Assets/pause.png");

    sf::Font font;
    font.loadFromFile("assets/Arial.ttf");

    /////////////

    sf::SoundBuffer sound1;
    sound1.loadFromFile("Assets/Audio/SMan_2_Pizza_Theme.wav");

    sf::SoundBuffer sound2;
    sound2.loadFromFile("Assets/Audio/Wii_Menu2.wav");

    sf::SoundBuffer sound3;
    sound3.loadFromFile("Assets/Audio/Mac_Startup.wav");

    sf::SoundBuffer sound4;
    sound4.loadFromFile("Assets/Audio/XP_Dots.wav");

    sf::SoundBuffer sound5;
    sound5.loadFromFile("Assets/Audio/XP_Start.wav");

    sf::SoundBuffer sound6;
    sound6.loadFromFile("Assets/Audio/XP_Teleport.wav");

    sf::SoundBuffer sound7;
    sound7.loadFromFile("Assets/Audio/XP_End.wav");

    /////////

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


    BackG_Wii.play();
    BackG_Wii.setLoop(true);

    XP_Tele.setVolume(50.f);
    BackG_Pizza.setVolume(25.f);


    ///////

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


////////
//Text

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

    //////////
    //Sprite

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
    Paused.setOrigin(0,0);
    Paused.setScale(.5f, .5f);

    /////////////
    //Sprite Vectors

    std::vector<sf::Sprite> PacLife(3, sf::Sprite(texture2));
    PlaceLives(PacLife);


    std::vector<sf::RectangleShape> Dot(340);

    for (int i = 0; i < Dot.size(); i++) {
        Dot[i].setFillColor(sf::Color::White);
        Dot[i].setSize(sf::Vector2f(5, 5));
        Dot[i].setOrigin(2.5,2.5);
    }
    PlaceDots(Dot,image);



    std::vector<sf::RectangleShape> lineArr (70);

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
        Node[i].setFillColor(sf::Color::Black);
        Node[i].setSize(sf::Vector2f(15, 15));
        Node[i].setOrigin(7.5,7.5);
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



    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized) {

                sf::Vector2f size = static_cast<sf::Vector2f>(window.getSize());

                if(size.x > 800) {
                    size.x = 522*1.6;
                }

                if(size.y > 800) {
                    size.y = 620*1.6;
                }

                window.setSize(static_cast<sf::Vector2u>(size));
            }


            if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {

                cout<<"mouse X = "<<sf::Mouse::getPosition(window).x<<" Mouse Y = "<<sf::Mouse::getPosition(window).y<<endl;

            }
        }



        PacManCheck(PacMan,image, LeftWallPos, RigthWallPos, UpWallPos, DownWallPos);

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


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& start_game == true) {

            start_game = false;
            Game_over = false;
            deathTimerOnce = true;

            dotsEaten = 0;
            x = 0,y = 0;
            score = 0;
            Berrytimer = 0;
            lives = 2;
            powerUpTimer = 601;

            BackG_Wii.stop();
            BackG_Wii.setLoop(false);
            Mac_start.play();

            BackG_Pizza.play();
            BackG_Pizza.setLoop(true);

            ised.red = false;
            ised.blue = false;
            ised.orange = false;
            ised.pink = false;

            Deadmove.red = false;
            Deadmove.orange = false;
            Deadmove.blue = false;
            Deadmove.pink = false;


            PowerUp[0].setPosition(30,30);
            PowerUp[2].setPosition(30,495);
            PowerUp[1].setPosition(495,30);
            PowerUp[3].setPosition(495,495);


            PlaceLives(PacLife);


            StartImage.setPosition(1000, 1000);
            PreStart.setPosition(1000,1000);
            NewHS.setPosition(1000,1000);

            PlaceDots(Dot,image);

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

            if(PauseGame == false)
                PauseGame = true;

            else if(PauseGame == true)
                PauseGame = false;
        }

        //////////////////
        //PacMove


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


        if(timer == 10)
            PacMan.setTexture(texture3);


        if(timer == 20) {

            PacMan.setTexture(texture2);
            timer = 0;
        }

        timer++;


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

///////////
//Orange ghost stuff

        OrangeghostCheck(OrangeGhost,image, OrangeLeftWallPos, OrangeRigthWallPos, OrangeUpWallPos, OrangeDownWallPos);

//basic
        if(PacMan.getPosition().y >OrangeGhost.getPosition().y && OrangeDownWallPos == false) {

            OrangeDown = true;
            OrangeUp = false;
        }


        if(PacMan.getPosition().y <OrangeGhost.getPosition().y && OrangeUpWallPos == false) {

            OrangeUp = true;
            OrangeDown = false;

        }

        if(PacMan.getPosition().x >OrangeGhost.getPosition().x && OrangeRigthWallPos == false) {

            OrangeRight = true;
            OrangeLeft = false;

        }

        if(PacMan.getPosition().x <OrangeGhost.getPosition().x && OrangeLeftWallPos == false) {

            OrangeLeft = true;
            OrangeRight = false;

        }

//navigation


        if(PacMan.getPosition().y >OrangeGhost.getPosition().y && OrangeDownWallPos == true && OrangeDown == true) {

            OrangeUpOnce = true;
        }


        if(PacMan.getPosition().y <OrangeGhost.getPosition().y && OrangeUpWallPos == true && OrangeUp == true) {

            OrangeDownOnce = true;
        }

        if(PacMan.getPosition().x >OrangeGhost.getPosition().x && OrangeRigthWallPos == true && OrangeRight == true) {

            OrangeLeftOnce = true;
        }

        if(PacMan.getPosition().x <OrangeGhost.getPosition().x && OrangeLeftWallPos == true && OrangeLeft == true) {

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


        if(OrangeUp == true) {

            Orangey = -1;
        } else {

            Orangey = 1;
        }

        if(OrangeLeft == true) {
            OrangeX = -1;
        } else {
            OrangeX = 1;
        }


        if(OrangeghostCheck(OrangeGhost,image, OrangeLeftWallPos, OrangeRigthWallPos, OrangeUpWallPos, OrangeDownWallPos)) {


            if(OrangeUpWallPos == true && OrangeUp == true) {

                Orangey = 0;
                OrangeUpOnce = false;
            }

            if (OrangeDownWallPos == true && OrangeDown == true) {

                Orangey = 0;
                OrangeDownOnce = false;
            }

            if(OrangeLeftWallPos == true && OrangeLeft == true) {

                OrangeX = 0;
                OrangeLeftOnce = false;
            }

            if(OrangeRigthWallPos == true && OrangeRight == true) {

                OrangeX = 0;
                OrangeRightOnce = false;
            }

        } else {
            OrangeLeftWallPos = false;
            OrangeRigthWallPos = false;
            OrangeUpWallPos = false;
            OrangeDownWallPos = false;
        }

///////////////////////////////////////////////////////////////////////////////////////////

//RED ghost stuff

        RedghostCheck(RedGhost,image, RedLeftWallPos, RedRigthWallPos, RedUpWallPos, RedDownWallPos,PacMan);

//basic

        if(PacMan.getPosition().y >RedGhost.getPosition().y && RedDownWallPos == false) {

            RedDown = true;
            RedUp = false;
        }


        if(PacMan.getPosition().y <RedGhost.getPosition().y && RedUpWallPos == false) {

            RedUp = true;
            RedDown = false;
        }

        if(PacMan.getPosition().x >RedGhost.getPosition().x && RedRigthWallPos == false) {

            RedRight = true;
            RedLeft = false;
        }

        if(PacMan.getPosition().x <RedGhost.getPosition().x && RedLeftWallPos == false) {

            RedLeft = true;
            RedRight = false;
        }

//navigation

        if(RedUpWallPos == true && RedUp == true) {


            RedDownOnce = true;
        }

        if(RedRigthWallPos == true && RedRight == true) {


            RedLeftOnce = true;
        }

        if(RedDownWallPos == true && RedDown == true) {

            RedUpOnce = true;
        }

        if(RedLeftWallPos == true && RedLeft == true) {

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


        if(RedUp == true) {

            RedY = -1;
        }
        if(RedDown == true) {

            RedY = 1;
        }
        if(RedLeft == true) {

            RedX = -1;
        }
        if(RedRight == true) {

            RedX = 1;
        }

        if(RedghostCheck(RedGhost,image, RedLeftWallPos, RedRigthWallPos, RedUpWallPos, RedDownWallPos,PacMan)) {

            if(RedUpWallPos == true && RedUp == true) {

                RedY = 0;
                RedUpOnce = false;
            }

            if (RedDownWallPos == true && RedDown == true) {

                RedY = 0;
                RedDownOnce = false;
            }

            if(RedLeftWallPos == true && RedLeft == true) {

                RedX = 0;
                RedLeftOnce = false;
            }

            if(RedRigthWallPos == true && RedRight == true) {

                RedX = 0;
                RedRightOnce = false;
            }


        } else {
            RedLeftWallPos = false;
            RedRigthWallPos = false;
            RedUpWallPos = false;
            RedDownWallPos = false;
        }
///////////////////////////////////////////////////////////////////////////////////////////

//BLUE ghost stuff

        BlueghostCheck(BlueGhost, image, Blue);

//basic

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

//navigation

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

        if(BlueUp == true) {

            BlueY = -1;
        }
        if(BlueDown == true) {

            BlueY = 1;
        }
        if(BlueLeft == true) {

            BlueX = -1;
        }
        if(BlueRight == true) {

            BlueX = 1;
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

///////////////////////////////////////////////////////////////////////////////////////////

//PINK ghost stuff


        PinkghostCheck(PinkGhost, image, Pink);

//basic

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

//navigation

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




///////////////////////
// teleport

        if(Teleport(PacMan, OrangeGhost, RedGhost, PinkGhost, BlueGhost))
            XP_Tele.play();

/////////////////////
// Hittest

        for (int i = 0; i < Dot.size(); i++) {
            if(PacMan.getGlobalBounds().intersects(Dot[i].getGlobalBounds())) {

                Dot[i].setPosition(1000,1000);
                XP_Dot.play();
                dotsEaten ++;
                score ++;

            }
        }


        if(PacMan.getGlobalBounds().intersects(Berry.getGlobalBounds())) {

            Berry.setPosition(1000,1000);
            score +=200;

        }

        for (int i = 0; i < PowerUp.size(); i++) {
            if(PacMan.getGlobalBounds().intersects(PowerUp[i].getGlobalBounds())) {

                powerUpTimer = 0;
                score +=10;
                PowerUp[i].setPosition(1000,1000);


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


        if(Deadmove.red == false) {

            if(PacMan.getGlobalBounds().intersects(RedGhost.getGlobalBounds())&& ised.red == false) {

                if(killonce == true) {

                    PacDead = true;

                    death_ani_Timer = 0;
                    PacDeath.setTextureRect(sf::IntRect(Pac_wack1));
                    PacDeath.setOrigin(7.5,4);
                    PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
                    killonce = false;
                }
            }

            if(PacMan.getGlobalBounds().intersects(RedGhost.getGlobalBounds())&& ised.red == true) {

                Deadmove.red = true;
                score +=100;
                ised.red = false;
                RedGhost.setTexture(texture13);
            }
        }



        if(Deadmove.orange == false) {

            if(PacMan.getGlobalBounds().intersects(OrangeGhost.getGlobalBounds())&& ised.orange == false) {

                if(killonce == true) {

                    PacDead = true;
                    death_ani_Timer = 0;
                    PacDeath.setTextureRect(sf::IntRect(Pac_wack1));
                    PacDeath.setOrigin(7.5,4);
                    PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
                    killonce = false;
                }
            }

            if(PacMan.getGlobalBounds().intersects(OrangeGhost.getGlobalBounds())&& ised.orange == true) {


                Deadmove.orange = true;
                score +=100;
                ised.orange = false;
                OrangeGhost.setTexture(texture13);
            }
        }



        if(Deadmove.pink == false) {

            if(PacMan.getGlobalBounds().intersects(PinkGhost.getGlobalBounds())&& ised.pink == false) {

                if(killonce == true) {

                    PacDead = true;
                    death_ani_Timer = 0;
                    PacDeath.setTextureRect(sf::IntRect(Pac_wack1));
                    PacDeath.setOrigin(7.5,4);
                    PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
                    killonce = false;
                }
            }

            if(PacMan.getGlobalBounds().intersects(PinkGhost.getGlobalBounds())&& ised.pink == true) {

                Deadmove.pink = true;
                score +=100;
                ised.pink = false;
                PinkGhost.setTexture(texture13);

            }
        }



        if(Deadmove.blue == false) {

            if(PacMan.getGlobalBounds().intersects(BlueGhost.getGlobalBounds())&& ised.blue == false) {

                if(killonce == true) {

                    PacDead = true;
                    death_ani_Timer = 0;
                    PacDeath.setTextureRect(sf::IntRect(Pac_wack1));
                    PacDeath.setOrigin(7.5,4);
                    PacDeath.setPosition(PacMan.getPosition().x, PacMan.getPosition().y);
                    killonce = false;
                }
            }

            if(PacMan.getGlobalBounds().intersects(BlueGhost.getGlobalBounds())&& ised.blue == true) {

                Deadmove.blue = true;
                score +=100;
                ised.blue = false;
                BlueGhost.setTexture(texture13);

            }
        }


////////////


        PowerPelletAni(PowerUp, Pwr_ani_frame, glowTimer);
        glowTimer++;

///////

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




        /////////////////PacMan

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

        ////////////Red Ghost

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

        findSmallestElement(PacClose,Close,Diff);

        paths(PacClose,Close,PacMan,Node,lineArr, RedGhost, OrangeGhost);

        ////////////

        // create berry

        if(Berrytimer == 1200) {

            randtemp = rand()%7;

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



        // death animation and code to reset game

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

            PacDead = false;

            PacDeath.setPosition(1000,1000);
            PacMan.setPosition(sf::Vector2f(266, 326));

            OrangeGhost.setPosition(sf::Vector2f(226, 266));
            RedGhost.setPosition(sf::Vector2f(246, 266));
            PinkGhost.setPosition(sf::Vector2f(266, 266));
            BlueGhost.setPosition(sf::Vector2f(300, 266));

            ised.red = false;
            ised.orange = false;
            ised.blue = false;
            ised.pink = false;

            OrangeGhost.setTexture(texture4);
            RedGhost.setTexture(texture5);
            PinkGhost.setTexture(texture6);
            BlueGhost.setTexture(texture7);

            killonce = true;

            Close.Red = 23;
            Close.Orange = 23;
            Close.Blue = 23;
            Close.Pink = 23;

            Left = false;
            Right = false;
            Up = false;
            Down = false;
            x = 0;
            y = 0;
            Close.Pac = 32;
            PacLife[lives].setPosition(1000,1000);
            lives--;
        }



////////////////////////////

//////////eye code


        if(Deadmove.red == true) {

            if(RedGhost.getPosition().x > 246)
                RedX = -1;

            if(RedGhost.getPosition().x < 246)
                RedX = 1;

            if(RedGhost.getPosition().y < 267)
                RedY = 1;

            if(RedGhost.getPosition().y > 267)
                RedY = -1;


            if((RedGhost.getPosition().x > 240 && RedGhost.getPosition().x < 250) && (RedGhost.getPosition().y > 265 && RedGhost.getPosition().y < 270)) {

                Deadmove.red = false;
                RedGhost.setTexture(texture5);
                RedGhost.setPosition(240,267);
                Close.Red = 23;
            }
        }


        if(Deadmove.orange == true) {

            if(OrangeGhost.getPosition().x > 226)
                OrangeX = -1;

            if(OrangeGhost.getPosition().x < 226)
                OrangeX = 1;

            if(OrangeGhost.getPosition().y < 267)
                Orangey = 1;

            if(OrangeGhost.getPosition().y > 267)
                Orangey = -1;


            if((OrangeGhost.getPosition().x > 220 && OrangeGhost.getPosition().x < 230) && (OrangeGhost.getPosition().y > 265 && OrangeGhost.getPosition().y < 270)) {

                Deadmove.orange = false;
                OrangeGhost.setTexture(texture4);
                OrangeGhost.setPosition(220,267);
                Close.Orange = 23;
            }
        }


        if(Deadmove.blue == true) {

            if(BlueGhost.getPosition().x > 267)
                BlueX = -1;

            if(BlueGhost.getPosition().x < 267)
                BlueX = 1;

            if(BlueGhost.getPosition().y < 267)
                BlueY = 1;

            if(BlueGhost.getPosition().y > 267)
                BlueY = -1;

            if((BlueGhost.getPosition().x > 265 && BlueGhost.getPosition().x < 270) && (BlueGhost.getPosition().y > 265 && BlueGhost.getPosition().y < 270)) {

                Deadmove.blue = false;
                BlueGhost.setTexture(texture7);
                BlueGhost.setPosition(267,267);
                Close.Blue = 23;
            }
        }




        if(Deadmove.pink == true) {

            if(PinkGhost.getPosition().x > 300)
                PinkX = -1;

            if(PinkGhost.getPosition().x < 300)
                PinkX = 1;

            if(PinkGhost.getPosition().y < 267)
                PinkY = 1;

            if(PinkGhost.getPosition().y > 267)
                PinkY = -1;

            if((PinkGhost.getPosition().x > 290 && PinkGhost.getPosition().x < 310) && (PinkGhost.getPosition().y > 265 && PinkGhost.getPosition().y < 270)) {

                Deadmove.pink = false;
                PinkGhost.setTexture(texture6);
                PinkGhost.setPosition(300,267);
                Close.Pink = 23;
            }
        }

        /////////////////////////

        stringstream ss;
        ss<<score;
        ss>>scoreShow;

        scoreDis.setString("Score: "+scoreShow);

        stringstream ss2;
        ss2<<highscore;
        ss2>>HSString;

        HsDis.setString("HS: "+HSString);



        if(dotsEaten == 183) {

            dotsEaten = 0;

            Berrytimer = 0;

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
            Left = false;
            Right = false;
            Up = false;
            Down = false;
            x = 0;
            y = 0;
            Close.Pac = 32;

            Mac_start.play();

            PowerUp[0].setPosition(30,30);
            PowerUp[2].setPosition(30,495);
            PowerUp[1].setPosition(495,30);
            PowerUp[3].setPosition(495,495);

            ised.red = false;
            ised.orange = false;
            ised.blue = false;
            ised.pink = false;

            powerUpTimer = 601;

            OrangeGhost.setTexture(texture4);
            RedGhost.setTexture(texture5);

            PinkGhost.setTexture(texture6);
            BlueGhost.setTexture(texture7);

            PlaceDots(Dot,image);
        }




        if(lives < 0 && deathTimerOnce == true) {
            deathTimerOnce = false;
            death_timer = 0;
            GameDone.setPosition(522/2, 322);

            BackG_Pizza.setLoop(false);
            BackG_Pizza.stop();

            XP_End.play();

            Game_over = true;
            death_timer = 0;
        }


        if(Game_over == true && start_game == false &&death_timer == 120) {

            start_game = true;

            BackG_Wii.play();
            BackG_Wii.setLoop(true);

            SaveHS(highscore,score,HSString,NewHS);
            GameDone.setPosition(1000, 1000);
            StartImage.setPosition(sf::Vector2f(266, 150));
            PreStart.setPosition(522/2, 620/2);

        }

        death_timer ++;
        powerUpTimer ++;
        death_ani_Timer ++;
        Berrytimer++;


        if(Game_over == false && PacDead == false && PauseGame == false) {
            PacMan.move(x,y);
            OrangeGhost.move(OrangeX, Orangey);
            RedGhost.move(RedX, RedY);
            PinkGhost.move(PinkX, PinkY);
            BlueGhost.move(BlueX, BlueY);
        }




        window.clear();
        window.draw(Background);


        /*
         for (int i = 0; i < Node.size(); i++) {
         window.draw(Node[i]);
         }
         */

        for (int i = 0; i < Dot.size(); i++) {

            window.draw(Dot[i]);
        }

        for(int i = 0; i <lineArr.size(); i++) {

            window.draw(lineArr[i]);
        }


        for (int i = 0; i < PowerUp.size(); i++) {

            window.draw(PowerUp[i]);
        }

        for(int i = 0; i<PacLife.size(); i++) {

            window.draw(PacLife[i]);

        }


        window.draw(scoreDis);
        window.draw(HsDis);
        window.draw(Berry);


        if(Game_over == false) {

            if(PacDead == false)
                window.draw(PacMan);

            window.draw(OrangeGhost);
            window.draw(RedGhost);
            window.draw(PinkGhost);
            window.draw(BlueGhost);
        }

        window.draw(PacDeath);

        window.draw(Paused);

        if(Game_over == true)
            window.draw(Menu);


        window.draw(NewHS);

        window.draw(StartImage);
        window.draw(PreStart);
        window.draw(GameDone);


        window.display();
    }

    return 0;
}
