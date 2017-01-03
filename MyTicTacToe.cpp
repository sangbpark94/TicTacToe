#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

	bool xwin = false;
	bool owin = false;
    int i, j, k, l, m, n;
    int tiecount = 0;

    typedef char box[7][7];

    box bb, xb, ob, *grid[3][3];
    box oneb, twob, threeb, fourb, fiveb, sixb, sevenb, eightb, nineb;

    //fill in bb = blank box
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            bb[i][j] = ' ';
        
    //fill in xb = X box
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            xb[i][j] = ' ';
    xb[1][1] = char(219);
    xb[1][5] = char(219);
    xb[2][2] = char(219);
    xb[2][4] = char(219);
    xb[3][3] = char(219);
    xb[4][2] = char(219);
    xb[4][4] = char(219);
    xb[5][1] = char(219);
    xb[5][5] = char(219);

    //fill in ob = O box
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            ob[i][j] = ' ';    
    ob[1][2] = char(219);
    ob[1][3] = char(219);
    ob[1][4] = char(219);
    ob[2][1] = char(219);
    ob[2][5] = char(219);
    ob[3][1] = char(219);
    ob[3][5] = char(219);
    ob[4][1] = char(219);
    ob[4][5] = char(219);
    ob[5][2] = char(219);
    ob[5][3] = char(219);
    ob[5][4] = char(219);

    //fill oneb = box one, to, nineb = box nine
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            oneb[i][j] = ' ';
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            twob[i][j] = ' ';
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            threeb[i][j] = ' ';
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            fourb[i][j] = ' ';
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            fiveb[i][j] = ' ';
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            sixb[i][j] = ' ';
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            sevenb[i][j] = ' ';
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            eightb[i][j] = ' ';
    for(i = 0; i < 7; i++)
        for(j = 0; j < 7; j++)
            nineb[i][j] = ' ';
    oneb[3][3] = char(49);
    twob[3][3] = char(50);
    threeb[3][3] = char(51);
    fourb[3][3] = char(52);
    fiveb[3][3] = char(53);
    sixb[3][3] = char(54);
    sevenb[3][3] = char(55);
    eightb[3][3] = char(56);
    nineb[3][3] = char(57);

    //fill grid with oneb to nineb
    grid[0][0] = &oneb;
    grid[0][1] = &twob;
    grid[0][2] = &threeb;
    grid[1][0] = &fourb;
    grid[1][1] = &fiveb;
    grid[1][2] = &sixb;
    grid[2][0] = &sevenb;
    grid[2][1] = &eightb;
    grid[2][2] = &nineb;

    //player initialize
    int player = 1;

pr:	//print stats
	cout << "Player 1 (X) VS Player 2 (O)" << endl << endl;

    //print board
	for(i = 0; i < 3; i++)
    {   for(k = 0; k < 7; k++)
        {   for(j = 0; j < 3; j++)
            {   for(l = 0; l < 7; l++)
                    cout << (*grid[i][j])[k][l];
                if(j != 2)
					cout << char(179);
            }
            cout << endl;
        }
        if(i != 2)
        {
            for(m = 0; m < 3; m++)
            {   for(n = 0; n < 7; n++)
                    cout << char(196);
                if(m != 2)
				cout << char(197);
            }
            cout << endl;
        }
    }
    cout << endl;

    //Check win
    if(xwin)
    {   cout << "Player 1 wins!" << endl;
		return 0;}
    if(owin)
    {   cout << "Player 2 wins!" << endl;
        return 0;}

	//Check tie
	if(tiecount == 9)
	{	cout << "IT'S A TIE!" << endl;
		return 0;}

    int number;
    cout << "Player " << player << " select a number: ";
in: cin >> number;
    while(number < 1 || number > 9)
    {   cout << endl << endl << "That is an invalid number." << endl;
        cout << "Please select a number: ";
        cin >> number;}
    if(1 <= number <= 3)
    {   while( (grid[0][number-1] == &xb) || (grid[0][number-1] == &ob) )
        {   cout << endl << endl << "That location is already filled." << endl;
            cout << "Please select a number: ";
            goto in;}
        if(player == 1)
            grid[0][number-1] = &xb;
        else if(player == 2)
            grid[0][number-1] = &ob;
        tiecount++;
		goto fl;
    }
    if(4 <= number <= 6)
    {   while( (grid[1][number-4] == &xb) || (grid[1][number-4] == &ob) )
        {   cout << endl << endl << "That location is already filled." << endl;
            cout << "Please select a number: ";
            goto in;}
        if(player == 1)
            grid[1][number-4] = &xb;
        else if(player == 2)
            grid[1][number-4] = &ob;
        tiecount++;
        goto fl;
    } 
    if(7 <= number <= 9)
    {   while( (grid[2][number-7] == &xb) || (grid[2][number-7] == &ob) )
        {   cout << endl << endl << "That location is already filled." << endl;
            cout << "Please select a number: ";
            goto in;}
        if(player == 1)
            grid[1][number-4] = &xb;
        else if(player == 2)
            grid[1][number-4] = &ob;
        tiecount++;
		goto fl;
    }

fl:	if(player == 1)
		player = 2;
	else if(player == 2)
		player = 1;

ch: for(i = 0; i < 3; i++)
    {   if( (grid[i][0] == &xb) && (grid[i][1] == &xb) && (grid[i][2] == &xb) )
            xwin = true;
        if( (grid[0][i] == &xb) && (grid[1][i] == &xb) && (grid[2][i] == &xb) )
            xwin = true;
        if( (grid[i][0] == &ob) && (grid[i][1] == &ob) && (grid[i][2] == &ob) )
            owin = true;
        if( (grid[0][i] == &ob) && (grid[1][i] == &ob) && (grid[2][i] == &ob) )
            owin = true;}

        if( (grid[0][0] == &xb) && (grid[1][1] == &xb) && (grid[2][2] == &xb) )
            xwin = true;    
        if( (grid[0][0] == &ob) && (grid[1][1] == &ob) && (grid[2][2] == &ob) )
            owin = true;            
        if( (grid[0][2] == &xb) && (grid[1][1] == &xb) && (grid[2][0] == &xb) )
            xwin = true;
        if( (grid[0][2] == &ob) && (grid[1][1] == &ob) && (grid[2][0] == &ob) )
            owin = true;
    system("cls");
	goto pr;
}




