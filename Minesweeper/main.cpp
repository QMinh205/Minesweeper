#include "Texture.h"
#include "Buttons.h"
#include "Variables.h"
#include "Constant.h"
#include "Function.h"
using namespace std;

int WinMain(int argc, char* argv[])
{
	//Start up SDL and create window
	if (!init())
	{
		cout << "Failed to initialize" << '\n';
	}
	else
	{
		if (loadmedia())
		{
			if (loadMenuMedia())
			{
				showMenu();
				while (mainLoop)
				{
					if (isChoosing)
					{
						showModeChoice();
					}
					if(customMode) CustomMode();
					while (isRunning)
					{
						handleEvent();
						setButtonPosition();
						renderGame();
					}
				}
			}
		}
	}
	//Free resources and close SDL
	close();
	return 0;
}
