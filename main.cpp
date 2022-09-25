#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class environment
{
public:
    int isclean;               // 0 means clean and 1 dirty     

};

int main()
{
    int len, width;

    cout << "Enter the horizontal size of the room" << endl;
    cin >> width;

    cout << "Enter the vertical size of the room" << endl;
    cin >> len;

    cout << "The size of the room is " << len << " x " << width << endl;

    environment** myroom = new environment * [len];

    // Creating Environment
    for (int i = 0; i < len; i++)
    {
        myroom[i] = new environment[width];
    }

    // Randomizing clean or dirty
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < width; j++)
        {
            myroom[i][j].isclean = rand() % 2;  
        }
    }

    //Printing environment
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << myroom[i][j].isclean << " ";
        }
        cout << endl;
    }
    cout << endl;

    //Positioning Cleaner
    int initialPos_x = 999, initialPos_y = 999;
    while (initialPos_x > width)
    {
    cout << "Type initial x position for vaccum cleaner (A) (Must be smaller or equal to width of the environment)" << endl;
    cin >> initialPos_x;
    cout << endl;
    }

    while (initialPos_y > len)
    {
        cout << "Type initial y position for vaccum cleaner (A) (Must be smaller or equal to length of the environment)" << endl;
        cin >> initialPos_y;
        cout << endl;
    }

    //Printing environment with agent's location!
    //printgrid(len, width, initialPos_x, initialPos_y, myroom);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << myroom[i][j].isclean;
            if (i == initialPos_y - 1 && j == initialPos_x - 1 )
            {
                cout << "-A";
            }
            else
            {
                cout << "  ";
            }
            cout << "   ";
        }
        cout << endl;
    }
    cout << endl;

    //Moving Agent
    // Since the initial location is selected by the user, first step is to move agent to pos (1,1)
    int performance = 0;                                                    // Peformance measurer (-1 if moves without cleaning, +5 if it cleans)

    while (initialPos_x > 1)
    {
        if (myroom[initialPos_y-1][initialPos_x-1].isclean == 1)
        {
            cout << "Dirty position found... Cleaning..." << endl << endl << endl;
            myroom[initialPos_y-1][initialPos_x-1].isclean = 0;
            performance = performance + 5;
        }
        
        initialPos_x--;
        performance--;
        //printgrid(len, width, initialPos_x, initialPos_y, myroom);

        // Printing grid
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << myroom[i][j].isclean;
                if (i == initialPos_y - 1 && j == initialPos_x - 1)
                {
                    cout << "-A";
                }
                else
                {
                    cout << "  ";
                }
                cout << "   ";
            }
            cout << endl;
        }
        cout << endl;
    }

    while (initialPos_y > 1)
    {
        if (myroom[initialPos_y-1][initialPos_x-1].isclean == 1)
        {
            cout << "Dirty position found... Cleaning..." << endl << "Next Position" << endl << endl;
            myroom[initialPos_y-1][initialPos_x-1].isclean = 0;
            performance = performance + 5;
        }
       
        initialPos_y--;
        performance--;
        //printgrid(len, width, initialPos_x, initialPos_y, myroom);

        // Printing grid
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << myroom[i][j].isclean;
                if (i == initialPos_y - 1 && j == initialPos_x - 1)
                {
                    cout << "-A";
                }
                else
                {
                    cout << "  ";
                }
                cout << "   ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Current performance: " << performance << endl;

    // Agent is in position (1,1)
    // Now agent must go through entire grid and clean remaining spots

    // Check position
    if (myroom[initialPos_y - 1][initialPos_x - 1].isclean == 1)
    {
        cout << "Dirty position found... Cleaning..." << endl << "Next Position" << endl << endl;
        myroom[initialPos_y - 1][initialPos_x - 1].isclean = 0;
        performance = performance + 5;
    }

    while (initialPos_y <= len)
    {
        while (initialPos_x <= width)
        {
            if (myroom[initialPos_y - 1][initialPos_x - 1].isclean == 1)
            {
                cout << "Dirty position found... Cleaning..." << endl << "Next Position" << endl << endl;
                myroom[initialPos_y - 1][initialPos_x - 1].isclean = 0;
                performance = performance + 5;
            }

            initialPos_x++;
            performance--;
            

            // Printing grid
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    cout << myroom[i][j].isclean;
                    if (i == initialPos_y - 1 && j == initialPos_x - 1)
                    {
                        cout << "-A";
                    }
                    else
                    {
                        cout << "  ";
                    }
                    cout << "   ";
                }
                cout << endl;
            }
            cout << endl;
        }

        initialPos_y++;
        
        //Check if y has reached the end
        if (initialPos_y > len)
        {
            break;
        }
        
        if (myroom[initialPos_y - 1][initialPos_x - 1].isclean == 1)
        {
            cout << "Dirty position found... Cleaning..." << endl << "Next Position" << endl << endl;
            myroom[initialPos_y - 1][initialPos_x - 1].isclean = 0;
            performance = performance + 5;
        }

        while (initialPos_x > 1)
        {
            if (myroom[initialPos_y - 1][initialPos_x - 1].isclean == 1)
            {
                cout << "Dirty position found... Cleaning..." << endl << "Next Position" << endl << endl;
                myroom[initialPos_y - 1][initialPos_x - 1].isclean = 0;
                performance = performance + 5;
            }

            initialPos_x--;
            performance--;
            
            // Printing grid
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    cout << myroom[i][j].isclean;
                    if (i == initialPos_y - 1 && j == initialPos_x - 1)
                    {
                        cout << "-A";
                    }
                    else
                    {
                        cout << "  ";
                    }
                    cout << "   ";
                }
                cout << endl;
            }
            cout << endl;
        }
        
        if (myroom[initialPos_y - 1][initialPos_x - 1].isclean == 1)
        {
            cout << "Dirty position found... Cleaning..." << endl << "Next Position" << endl << endl;
            myroom[initialPos_y - 1][initialPos_x - 1].isclean = 0;
            performance = performance + 5;
        }
        initialPos_x++;
    }
    

    // Printing grid
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << myroom[i][j].isclean;
            if (i == initialPos_y - 1 && j == initialPos_x - 1)
            {
                cout << "-A";
            }
            else
            {
                cout << "  ";
            }
            cout << "   ";
        }
        cout << endl;
    }
    cout << endl;


    cout << endl;
    cout << "All done! PERFORMANCE = " << performance << endl;
    ;
}

