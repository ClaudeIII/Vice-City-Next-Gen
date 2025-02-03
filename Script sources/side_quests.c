/***********************************************************************
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"
int inamb = 0;
int incopcar = 0;
int inftk = 0;
int intaxi = 0;
int inpizza = 0;
int incrazy = 0;
int inbmx = 0;
int inpcj = 0;
int intopfun = 0;

void ToggleScript(char * name)
{
	REQUEST_SCRIPT(name);
	while (!HAS_SCRIPT_LOADED(name)) WAIT(0);
	G_ONMISSION = 1;
	uint script = START_NEW_SCRIPT(name, 1024);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED(name);
	while (IS_THREAD_ACTIVE(script)) WAIT(0);
	G_ONMISSION = 0;
	WAIT(1000);
}

void main(void)
{
	WAIT(0);
	while (TRUE) 
	{
		WAIT(0);
		if (G_ONMISSION == 0)
		{
			if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("ambulance")))
			{
				if (inamb == 0)
				{
					PRINT_HELP("ATUTOR");
					inamb = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("ambulance");
				}
			}
			else
			{
				if (inamb == 1)
				{
					inamb = 0;
				}
			}

			if ((IS_CHAR_IN_ANY_POLICE_VEHICLE(GetPlayerPed())) || (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("annihilator"))) || (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("fbi"))))
			{
				if (incopcar == 0)
				{
					PRINT_HELP("CTUTOR");
					incopcar = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("vigilante");
				}
			}
			else
			{
				if (incopcar == 1)
				{
					incopcar = 0;
				}
			}

			if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("firetruk")))
			{
				if (inftk == 0)
				{
					PRINT_HELP("FTUTOR");
					inftk = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("firetruck");
				}
			}
			else
			{
				if (inftk == 1)
				{
					inftk = 0;
				}
			}

			if ((IS_CHAR_IN_TAXI(GetPlayerPed())) || (IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_ROM)))
			{
				if (intaxi == 0)
				{
					PRINT_HELP("TTUTOR");
					intaxi = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("taxi");
				}
			}
			else
			{
				if (intaxi == 1)
				{
					intaxi = 0;
				}
			}

			if ((G_PIZZA == 0) && (G_ONMISSION == 0) && (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("hellfury"))))
			{
				if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -461.1, 1331.7, -4.0, -481.1, 1351.7, 16.0, 0)) || (IS_CHAR_IN_AREA_3D(GetPlayerPed(), -585.7, 611.6, -4.2, -605.7, 631.6, 16.2, 0)) || (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 836.8, 620.7, -4.9, 856.8, 640.7, 15.9, 0)))
				{
					if (inpizza == 0)
					{
						ToggleScript("pizza");
						inpizza = 1;
					}
				}
			}
			else
			{
				if (inpizza == 1)
				{
					inpizza = 0;
				}
			}

			if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("stalion"))) && (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 555.0, -610.0, 22.0, 567.0, -635.0, 28.0, 0)) && (G_ONMISSION == 0))
			{
				if (incrazy == 0)
				{
					CLEAR_HELP();
					PRINT_HELP("NEHELP2"); //Press the ~PAD_LB~ button to activate the mission
					incrazy = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("conecrazy");
				}
			}
			else
			{
				if (incrazy == 1)
				{
					incrazy = 0;
				}
			}

			if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow"))) && (LOCATE_CHAR_IN_CAR_3D(GetPlayerPed(), -136.1451, 1384.0923, 17.8402, 2.0, 2.0, 2.0, 0)) && (G_ONMISSION == 0))
			{
				ToggleScript("heli");
			}
			else if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow"))) && (LOCATE_CHAR_IN_CAR_3D(GetPlayerPed(), 461.4463, -778.7614, 11.4712, 2.0, 2.0, 2.0, 0)) && (G_ONMISSION == 0))
			{
				ToggleScript("heli");
			}
			else if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow"))) && (LOCATE_CHAR_IN_CAR_3D(GetPlayerPed(), 808.8450, 865.9194, 6.5155, 2.0, 2.0, 2.0, 0)) && (G_ONMISSION == 0))
			{
				ToggleScript("heli");
			}
			else if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow"))) && (LOCATE_CHAR_IN_CAR_3D(GetPlayerPed(), -453.5938, 769.5693, 8.9773, 2.0, 2.0, 2.0, 0)) && (G_ONMISSION == 0))
			{
				ToggleScript("heli");
			}

			if (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 3.0, 1938.0, 3.5, 13.0, 1948.0, 7.5, 0) && (G_ONMISSION == 0))
			{
				if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sanchez"))) || (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("landstalker"))))
				{
					if (inbmx == 0)
					{
						CLEAR_HELP();
						PRINT_HELP("NEHELP2"); //Press the ~PAD_LB~ button to activate the mission
						inbmx = 1;
					}
					if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
					{
						ToggleScript("bmx");
					}
				}
				else
				{
					if (inbmx == 1)
					{
						inbmx = 0;
					}
				}
			}
			else
			{
				if (inbmx == 1)
				{
					inbmx = 0;
				}
			}

			if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("pcj"))) && (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 937.4, 222.8, 7.0, 943.4, 228.8, 9.0, 0)) && (G_ONMISSION == 0))
			{
				if (inpcj == 0)
				{
					CLEAR_HELP();
					PRINT_HELP("NEHELP2"); //Press the ~PAD_LB~ button to activate the mission
					inpcj = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("pcj");
				}
			}
			else
			{
				if (inpcj == 1)
				{
					inpcj = 0;
				}
			}

			if ((IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO)) && (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 1165.666, 1220.26, 7.0, 1159.666, 1230.26, 12.0, 0)) && (G_ONMISSION == 0))
			{
				if (intopfun == 0)
				{
					CLEAR_HELP();
					PRINT_HELP("NEHELP2"); //Press the ~PAD_LB~ button to activate the mission
					intopfun = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("rcrace");
				}
			}
			else if ((IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO)) && (IS_CHAR_IN_AREA_3D(GetPlayerPed(), -797.529, -697.733, 8.282, -803.539, -705.255, 12.979, 0)) && (G_ONMISSION == 0))
			{
				if (intopfun == 0)
				{
					CLEAR_HELP();
					PRINT_HELP("NEHELP2"); //Press the ~PAD_LB~ button to activate the mission
					intopfun = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("rcheli");
				}
			}
			else if ((IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO)) && (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 744.676, 1780.595, 21.0, 737.676, 1790.595, 27.0, 0)) && (G_ONMISSION == 0))
			{
				if (intopfun == 0)
				{
					CLEAR_HELP();
					PRINT_HELP("NEHELP2"); //Press the ~PAD_LB~ button to activate the mission
					intopfun = 1;
				}
				if (((IS_CONTROL_PRESSED(2, 23)) && (!IS_USING_CONTROLLER())) || ((IS_BUTTON_PRESSED(0, 4)) && (IS_USING_CONTROLLER())))
				{
					ToggleScript("rcplne");
				}
			}
			else
			{
				if (intopfun == 1)
				{
					intopfun = 0;
				}
			}
		}
	}
}
