//
////(i == 2 && j == 60)   pacman position
//// grid is independent class
//// pacman inherits grid
//// Ghost inherits grid
//
////inheritance done (pacman->grid , ghost->grid)
////polymorphism done(vitual movePacman, printGrid)
////collision status not working properly
//
//
//#include<iostream>
////#include<conio.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int maxRows = 20, maxCols = 100;
//
//
//
//
//// grid is independent class
//class Grid
//{
//    // char** theGrid;
//    char design;
//
//
//public:
//    char** theGrid;
//    Grid()
//    {
//        design = '0';
//        theGrid = new char* [maxRows];
//        for (int i = 0; i < maxRows; i++)
//        {
//            theGrid[i] = new char[maxCols];
//        }
//
//    }
//
//    
//    const char getDesign()
//    {
//        return design;
//    }
//    // returns index
//    char** returnStartIndex()
//    {
//        return theGrid;  //return 0,0  i,j of the grid
//    }
//    // saves space in whole 2d array
//    void setSpaceOfGrid()
//    {
//        for (int i = 0; i < 20; i++)
//        {
//            for (int j = 0; j < 100; j++)
//            {
//                theGrid[i][j] = ' ';
//            }
//        }
//
//    }
//    // saves "-" in whole 2d array
//
//    void setDotsofGrid()
//    {
//        for (int i = 0; i < 20; i += 2)
//        {
//            for (int j = 0; j < 100; j = j + 5)
//            {
//                theGrid[i][j] = '.';
//            }
//        }
//    }
//    // print grid
//    virtual void printGrid()
//    {
//
//      
//
//    }
//
//    //  designs the grid
//    void designGrid()
//    {
//        for (int i = 0; i < 20; i++)
//        {
//            for (int j = 0; j < 100; j++)
//            {
//                //pacman position
//               /*if (i == 2 && j == 60)
//               {
//                   theGrid[i][j] = 'P';
//               }*/
//
//               // prints boundaries
//                if (i == 0 || i == 19 || j == 0 || j == 99)
//                {
//                    theGrid[i][j] = design;
//                }
//                // prints exit space right left
//                if ((i >= 13 && i < 17 && j == 0) || (i >= 13 && i < 17 && j == 99))
//                {
//                    theGrid[i][j] = ' ';
//                }
//                // print T
//                if (i == 4 && j >= 7 && j <= 27)
//                {
//                    theGrid[i][j] = design;
//                }
//                // print T
//                if (i > 4 && i <= 9 && j == 17)
//                {
//                    theGrid[i][j] = design;
//                }
//
//                // obstacle rectangle
//                if (((i == 4) && (j > 75 && j < 90)) || (i == 7 && (j > 75 && j < 90)))
//                {
//                    theGrid[i][j] = design;
//                }
//
//                // removes dots from with the shapes/G-house
//                if ((i == 6 && (j > 75 && j < 90)) || (i == 12 && (j <= 64 && j >= 51)))
//                {
//                    theGrid[i][j] = ' ';
//                }
//                // obstacle rectangle
//                if ((i >= 4 && i <= 7) && (j == 75 || j == 89))
//                {
//                    theGrid[i][j] = design;
//                }
//
//                // ghost house structue
//                if (i == 15 && (j > 50 && j < 65))
//                {
//                    theGrid[i][j] = design;
//                }
//                //  ghost house structue
//                if ((i > 10 && i < 15) && (j == 64 || j == 51))
//                {
//                    theGrid[i][j] = design;
//                }
//                // prints "ghost house" inside ghost house
//                if (i == 14)
//                {
//                    theGrid[i][52] = 'G';
//                    theGrid[i][53] = 'h';
//                    theGrid[i][54] = 'o';
//                    theGrid[i][55] = 's';
//                    theGrid[i][56] = 't';
//                    theGrid[i][57] = ' ';
//                    theGrid[i][58] = 'H';
//                    theGrid[i][59] = 'o';
//                    theGrid[i][60] = 'u';
//                    theGrid[i][61] = 's';
//                    theGrid[i][62] = 'e';
//                }
//
//                // obstavle wall right left straight lines
//                if ((i == 14 && (j >= 8 && j <= 15)) || (i == 13 && (j >= 78 && j <= 82)))
//                {
//                    theGrid[i][j] = design;
//                }
//
//                // prints L shape on left of G-House
//                if ((i >= 9 && i <= 12 && j == 34) || (i == 12 && j >= 34 && j <= 38) || (i >= 12 && i <= 15 && j == 38))
//                {
//                    theGrid[i][j] = design;
//                }
//
//
//
//
//            }
//
//        }
//
//        
//    }
//
//
//
//    //destructor
//    ~Grid()
//    {
//        cout << "\nDestructor of grid\n";
//        for (int i = 0; i < 20; i++)
//        {
//            delete theGrid[i];
//        }
//
//        delete[]theGrid;
//        theGrid = NULL;
//    }
//
//
//
//};
//
//
//
////pacman inherits grid
//class Pacman : virtual public Grid
//{
//    char myPacman; // it is pacman itself
//    int xP, yP;   // x and y cordinate of pacman
//    int score;     // score of pacman'
//    int lives;
//
//
//public:
//    Pacman()
//    {
//        myPacman = 'P';
//        xP = 2;
//        yP = 60;
//        score = 0;  // initial score is 0
//        lives = 3;  // initial lives are 3e
//    }
//    int getlives() {
//        return lives;
//    }
//    int getscore() {
//        return score;
//    }
//    void setlives() { // decrease a life when collision happens
//        lives--;
//    }
//    void setscore() {
//        score += 20;
//    }
//
//    void moveleft(int& x, int& y) {
//        if (theGrid[x][y - 1] != getDesign())
//        {
//            if (theGrid[x][y - 1] == '.') { //scoring
//                score++;
//            }
//            // if goes into exit tunnel
//            if (/* x >= 13 && x < 17 && y == 0 */ y == 0 && theGrid[x][y] != getDesign())
//            {
//                theGrid[x][y] = ' '; // moving from tunnel previous space blank
//                y = 99;
//            }
//            y--;// moving pacman one step left
//            theGrid[x][y] = '@'; // printing pacman at the new position on grid
//            theGrid[x][y + 1] = ' '; // making empty space on the previous position
//          
//
//
//
//
//
//        }
//
//    }
//    void moveright(int& x, int& y) {
//        if (theGrid[x][y + 1] != getDesign())
//        {
//            if (theGrid[x][y + 1] == '.') { //scoring
//                score++;
//            }
//            // if goes into exit tunnel
//            if (/* x >= 13 && x < 17 && y == 99 */ y == maxCols - 1 && theGrid[x][y] != getDesign())
//            {
//                theGrid[x][y] = ' '; // moving from tunnel previous space blank
//                y = 0;
//            }
//            y++; // moving pacman one step right
//            theGrid[x][y] = '@'; // pacman at new position after move
//            theGrid[x][y - 1] = ' '; // previous space now blank
//
//
//
//        }
//
//    }
//    void moveup(int& x, int& y) {
//        if (theGrid[x - 1][y] != getDesign())
//        {
//            if (theGrid[x - 1][y] == '.') { //scoring
//                score++;
//            }
//            x--; // moving pacman one step up
//            theGrid[x][y] = '@'; // pacman at new position
//            theGrid[x + 1][y] = ' '; // previous position blank
//
//
//
//
//
//        }
//
//    }
//    void movedown(int& x, int& y) {
//        if (x >= 10 && x <= 15 && y > 50 && y < 65) {
//            theGrid[x][y] = '@';
//           
//            x = 10; // same position as before
//           
//        }
//
//        else//if (/choice == 'd' &&/theGrid[x+1][y] != getDesign())
//        {
//            if (theGrid[x + 1][y] != getDesign()) {
//                if (theGrid[x + 1][y] == '.') { //scoring
//                    score++;
//                }
//                x++; // moves one step down
//                theGrid[x][y] = '@'; // pacman at new position
//                theGrid[x - 1][y] = ' '; // previous position
//
//
//
//            }
//        }
//    }
//    char getPacmanSymbol()
//    {
//        return myPacman;
//    }
//
//    void setPacmanPosition()
//    {
//       
//    }
//
//    int getxP() { return xP; }
//    int getyP() { return yP; }
//
//};
//
//
//
////Ghost inherits grid
//class Ghost : virtual public Grid
//{
//    char* ghostArray; //to hold both ghosts
//    char GhostSymbol; // G  follower ghost
//    char RhostSymbol;//R   random ghost
//    Pacman obj;
//    int xG, yG;
//public:
//    Ghost() : obj()
//    {
//        xG = 10;
//        yG = 60;
//        ghostArray = new char[1];
//        GhostSymbol = 'G';
//        RhostSymbol = 'R';
//
//        ghostArray[0] = GhostSymbol;
//        // ghostArray[1] = RhostSymbol;
//    }
//    int getxG() { return xG; }
//    int getyG() { return yG; }
//
//    char getGhostIndex()
//    {
//        return GhostSymbol;
//    }
//    virtual void MoveGhost() {
//    }
//
//
//};
//
////This class has access of all member functions of pacman, ghost and grid
//class GameState : public Pacman, public Ghost {
//
//
//public:
//    
//
//    void MoveGhost(int& xg, int& yg, int px, int py) {
//        
//
//    }
//
//   
//
//    void MovePacman(int xp, int yp, int xg, int yg) //recieves pacman start coordinates as parameters
//    {
//        if (getlives() > 0)
//        {
//            char choice;
//            bool win = false;
//            bool energy = false; // for energizer
//            //int x = getxP(), y = getyP();
//            //char temp;
//            do
//            {
//                cout << "SCORE: " << getscore() << "\t\t\tLIVES: ";
//                for (int i = 0; i < getlives(); i++) {
//                    cout << "# ";
//                }
//                cout << endl;
//                cout << "enter movement direction: ";
//                //choice = _getch();
//                cin >> choice;
//                if (choice == 'l' /* 75 */ ) {
//
//                    
//                    moveleft(xp, yp);
//                    // }
//                    MoveGhost(xg, yg, xp, yp);
//
//                }
//               
//
//                // right
//                if (choice == 'r' /* 77 */ ) {
//                   
//                    moveright(xp, yp);
//                    //}
//                }
//               
//                                //}
//                                // up
//                if (choice == 'u' /* 72 */ ) {// && theGrid[x-1][y] != getDesign())
////                     
//                    moveup(xp, yp);
//                    // }
//                }
//               
//
//                                // down
//                if (choice == 'd' /* 80 */ ) {
//                  
//                    movedown(xp, yp);
//                    
//
//                }
//                
//                cout << xp << yp << xg << yg << endl;
//                if (xp == xg && yp == yg) {
//                    //                    cout << xp<<yp<<xg<<yg<<endl;
//                    theGrid[xp][yp] = ' ';
//                    xp = getxP();
//                    yp = getyP();
//                    theGrid[xp][yp] = '@';
//                    setlives();
//                    //yg++;
//                    theGrid[xg][yg] = 'G';
//                }
//                cout << endl;
//                //cout << "P: "<<getxP()<<","<<getyP()<<endl;
//
//                //end
//                if (choice == 'e' || choice == 'E')
//                {
//                    win = true;
//                }
//
//                system("cls");
//                for (int i = 0; i < 20; i++)
//                {
//                    for (int j = 0; j < 100; j++) {
//                        cout << theGrid[i][j];
//                    }
//                    cout << endl;
//                }
//
//
//
//            } while (win == false);
//
//
//        }
//        else
//            cout << "\nGAME OVER!\n";  //if lives khatam
//
//    }
//
//    void printGrid() {
//        int xp = getxP(), yp = getyP(); // got the initial coordinates of pacman
//        int xg = getxG(), yg = getyG();
//        setSpaceOfGrid();
//        setDotsofGrid();
//        designGrid();
//        theGrid[xp][yp] = '@';//set the initial position of pacman on the grid
//        theGrid[xg][yg] = 'G';//getGhostIndex();
//
//        for (int i = 0; i < 20; i++)
//        {
//            for (int j = 0; j < 100; j++) {
//                cout << theGrid[i][j];
//
//            }
//            cout << endl;
//        }
//        //move function
//        MovePacman(xp, yp, xg, yg); // passing coordinates of pacman to move function
//
//       // MoveGhost();
//    }
//};
//
//
//
//int main()
//{
//
//   
//    GameState obj;
//    obj.printGrid();
//
//  
//
//
//
//
//    return 0;
//}
