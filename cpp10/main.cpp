#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>


using namespace std;

int main()
{
    const int iFieldWidth(20), iFieldHeight(20);
    const char charLeaveCell('#'), charDeadCell('*');
    int iGenerations = 100;
    bool bCellArray[iFieldWidth * iFieldHeight] = {false};
    bool bTempCellArray[iFieldWidth * iFieldHeight] = {false};

    srand((unsigned)time(NULL));
    short shRandomNumber = rand();


    for(int y = 0; y < iFieldWidth; y++)
    {

        for(int x=0; x<iFieldHeight; x++)
        {
            bCellArray[x + y * iFieldWidth] = rand()%2;
            if(bCellArray[x + y * iFieldWidth])
            {
                cout << "\033[32m"  << charLeaveCell << "\033[0m  ";
            }
            else
            {
                cout << "\033[31m" << charDeadCell << "\033[0m  ";
            }
        }
        cout << endl;

    }
     sleep(2);//2 секунды
             system("clear"); // очищаем консоль
//cout << "_______________________________________________________" << endl;

    for(int g = 0; g < iGenerations; g++)
    {
        for(int y = 0; y < iFieldWidth; y++)
        {
            for(int x=0, iCellCounter = 0; x<iFieldHeight; x++)
            {

                if(bCellArray[x + y * iFieldWidth])
                {

                    if( ((x-1)>=0) && ((y-1)>=0))
                    {
                        if(bCellArray[(x-1) + (y-1) * iFieldWidth])
                            iCellCounter++;

                    }

                    if((y-1)>=0)
                    {
                        if(bCellArray[x + (y-1) * iFieldWidth])
                            iCellCounter++;

                    }

                    if( ((x+1)<=iFieldWidth-1) && ((y-1)>=0))
                    {
                        if(bCellArray[(x+1) + (y-1) * iFieldWidth])
                            iCellCounter++;

                    }

                    if((x-1)>=0)
                    {
                        if(bCellArray[(x-1) + y * iFieldWidth])
                            iCellCounter++;

                    }

                    if((x+1)<=iFieldWidth-1)
                    {
                        if(bCellArray[(x+1) + y * iFieldWidth])
                            iCellCounter++;

                    }

                    if(((x-1)>=0) && ((y+1)<=iFieldHeight-1))
                    {
                        if(bCellArray[(x-1) + (y+1) * iFieldWidth])
                            iCellCounter++;
                    }

                    if((y+1)<=iFieldHeight-1)
                    {
                        if(bCellArray[x + (y+1) * iFieldWidth])
                            iCellCounter++;
                    }
                    if(((x+1)<=iFieldWidth-1) && ((y+1)<=iFieldHeight-1))
                    {
                        if(bCellArray[(x+1) + (y+1) * iFieldWidth])
                            iCellCounter++;
                    }
                   // cout << iCellCounter << endl;
}

                    if((iCellCounter < 2) || (iCellCounter > 3))
                    {
                        bTempCellArray[x + y * iFieldWidth] = false;
                        cout << "\033[31m" << charDeadCell << "\033[0m  ";

                    }
                    else
                    {
                        if((!bCellArray[x + y * iFieldWidth]) && (iCellCounter != 3))
                        {
                            bTempCellArray[x + y * iFieldWidth] = false;
                            cout << "\033[31m" << charDeadCell << "\033[0m  ";


                        }
                        else
                        {
                            bTempCellArray[x + y * iFieldWidth] = true;
                            cout << "\033[32m"  << charLeaveCell << "\033[0m  ";
                        }


                    }
                    iCellCounter = 0;

                }
                 cout << endl;
            }



         for(int i = 0; i < (iFieldHeight * iFieldWidth); i++){
            bCellArray[i] = bTempCellArray[i];
            }

 sleep(2);//2 секунды
             system("clear"); // очищаем консоль
            //cout << "_______________________________________________________" << endl;
    }




    return 0;
}
