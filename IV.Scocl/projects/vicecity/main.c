#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"

Pickup tweap[2];
uint randint, Ammo_nan;
uint Weap[20], get_Weap[10], Ammo[20];
int i, isActivated, c[30], cur, letterKey[26];
float timeScale = 1.0;
Vector3 playerpos;

void ChangeLetterPos(void)
{
	for (i = 1; i < 30; i++)
		c[i - 1] = c[i];

	c[29] = cur;
	return;
}
void UpdateKeys(void)
{
	for (i = 0; i < 26; i++)
	{
		if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(letterKey[i]))
		{
			cur = letterKey[i];
			ChangeLetterPos();
			break;
		}
	}
	return;
}
void CreateCar(char* name)
{
	int ccar;
	float h;

	REQUEST_MODEL(GET_HASH_KEY(name));
	while (!HAS_MODEL_LOADED(GET_HASH_KEY(name))) WAIT(0);

	GET_CHAR_COORDINATES(GetPlayerPed(), &playerpos.x, &playerpos.y, &playerpos.z);
	GET_CHAR_HEADING(GetPlayerPed(), &h);
	h += 90.0;
	h -= 180.0;
	CREATE_CAR(GET_HASH_KEY(name), playerpos.x + COS(h) * 6.0, playerpos.y + SIN(h) * 6.0, playerpos.z, &ccar, 1);
	SET_CAR_HEADING(ccar, h);
	MARK_CAR_AS_NO_LONGER_NEEDED(&ccar);
	MARK_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY(name));
	isActivated = true;
	return;
}
void cheats(void)
{
	if (IS_PLAYER_PLAYING(GetPlayerIndex()))
	{
		UpdateKeys();
		if (!isActivated)
		{
			if ((c[18] == 34) && (c[19] == 18) && (c[20] == 20) && (c[21] == 20) && (c[22] == 35) && (c[23] == 18) && (c[24] == 19) && (c[25] == 18) && (c[26] == 33) && (c[27] == 30) && (c[28] == 31) && (c[29] == 20))
				CreateCar("sabregt");// GETTHEREFAST

			else if ((c[20] == 19) && (c[21] == 22) && (c[22] == 48) && (c[23] == 48) && (c[24] == 23) && (c[25] == 31) && (c[26] == 35) && (c[27] == 46) && (c[28] == 30) && (c[29] == 19))
				CreateCar("trash"); // RUBBISHCAR

			else if ((c[13] == 48) && (c[14] == 18) && (c[15] == 20) && (c[16] == 20) && (c[17] == 18) && (c[18] == 19) && (c[19] == 20) && (c[20] == 35) && (c[21] == 30) && (c[22] == 49) && (c[23] == 17) && (c[24] == 30) && (c[25] == 38) && (c[26] == 37) && (c[27] == 23) && (c[28] == 49) && (c[29] == 34))
				CreateCar("huntley"); // BETTERTHANWALKING

			else if ((c[8] == 34) && (c[9] == 18) && (c[10] == 20) && (c[11] == 20) && (c[12] == 35) && (c[13] == 18) && (c[14] == 19) && (c[15] == 18) && (c[16] == 47) && (c[17] == 18) && (c[18] == 19) && (c[19] == 21) && (c[20] == 33) && (c[21] == 30) && (c[22] == 31) && (c[23] == 20) && (c[24] == 23) && (c[25] == 49) && (c[26] == 32) && (c[27] == 18) && (c[28] == 18) && (c[29] == 32))
				CreateCar("chavos"); // GETTHEREVERYFASTINDEED - spawns Hotring A

			else if ((c[9] == 34) && (c[10] == 18) && (c[11] == 20) && (c[12] == 20) && (c[13] == 35) && (c[14] == 18) && (c[15] == 19) && (c[16] == 18) && (c[17] == 30) && (c[18] == 50) && (c[19] == 30) && (c[20] == 44) && (c[21] == 23) && (c[22] == 49) && (c[23] == 34) && (c[24] == 38) && (c[25] == 21) && (c[26] == 33) && (c[27] == 30) && (c[28] == 31) && (c[29] == 20))
				CreateCar("feroci"); // GETTHEREAMAZINGLYFAST - spawns Hotring B

			else if ((c[16] == 19) && (c[17] == 24) && (c[18] == 46) && (c[19] == 37) && (c[20] == 30) && (c[21] == 49) && (c[22] == 32) && (c[23] == 19) && (c[24] == 24) && (c[25] == 38) && (c[26] == 38) && (c[27] == 46) && (c[28] == 30) && (c[29] == 19))
				CreateCar("stretch"); // ROCKANDROLLCAR

			else if ((c[19] == 20) && (c[20] == 35) && (c[21] == 18) && (c[22] == 38) && (c[23] == 30) && (c[24] == 31) && (c[25] == 20) && (c[26] == 19) && (c[27] == 23) && (c[28] == 32) && (c[29] == 18))
				CreateCar("romero"); // THELASTRIDE

			else if ((c[15] == 34) && (c[16] == 18) && (c[17] == 20) && (c[18] == 20) && (c[19] == 35) && (c[20] == 18) && (c[21] == 19) && (c[22] == 18) && (c[23] == 16) && (c[24] == 22) && (c[25] == 23) && (c[26] == 46) && (c[27] == 37) && (c[28] == 38) && (c[29] == 21))
				CreateCar("willard"); // GETTHEREQUICKLY - spawns modded BloodringA?

			else if ((c[17] == 20) && (c[18] == 19) && (c[19] == 30) && (c[20] == 47) && (c[21] == 18) && (c[22] == 38) && (c[23] == 23) && (c[24] == 49) && (c[25] == 31) && (c[26] == 20) && (c[27] == 21) && (c[28] == 38) && (c[29] == 18))
				CreateCar("peyote"); // TRAVELINSTYLE - spawns modded BloodringB?

			else if ((c[24] == 25) && (c[25] == 30) && (c[26] == 49) && (c[27] == 44) && (c[28] == 18) && (c[29] == 19))
				CreateCar("apc"); // PANZER

			else if ((c[22] == 30) && (c[23] == 31) && (c[24] == 25) && (c[25] == 23) && (c[26] == 19) && (c[27] == 23) && (c[28] == 49) && (c[29] == 18))
			{	// ASPIRINE
				SET_CHAR_HEALTH(GetPlayerPed(), 1000);
				if (IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
				{
					int hcar;
					GET_CAR_CHAR_IS_USING(GetPlayerPed(), &hcar);
					SET_ENGINE_HEALTH(hcar, 1500);
					MARK_CAR_AS_NO_LONGER_NEEDED(hcar);
				}
				isActivated = true;
			}
			else if ((c[12] == 25) && (c[13] == 19) && (c[14] == 18) && (c[15] == 46) && (c[16] == 23) && (c[17] == 24) && (c[18] == 22) && (c[19] == 31) && (c[20] == 25) && (c[21] == 19) && (c[22] == 24) && (c[23] == 20) && (c[24] == 18) && (c[25] == 46) && (c[26] == 20) && (c[27] == 23) && (c[28] == 24) && (c[29] == 49))
			{	// PRECIOUSPROTECTION
				ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
				isActivated = true;
			}
			else if ((c[20] == 20) && (c[21] == 35) && (c[22] == 22) && (c[23] == 34) && (c[24] == 31) && (c[25] == 20) && (c[26] == 24) && (c[27] == 24) && (c[28] == 38) && (c[29] == 31))
			{	// THUGSTOOLS
				//UpdateWeaponOfPed(GetPlayerPed(), WEAPON_BRASSKNUCKLES);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_BASEBALLBAT);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_PISTOL);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_SHOTGUN);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_EPISODIC_7); //TEC9
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_EPISODIC_9); //RUGER
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_M40A1);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_FTHROWER);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MOLOTOV);
				isActivated = true;
			}
			else if ((c[13] == 25) && (c[14] == 19) && (c[15] == 24) && (c[16] == 33) && (c[17] == 18) && (c[18] == 31) && (c[19] == 31) && (c[20] == 23) && (c[21] == 24) && (c[22] == 49) && (c[23] == 30) && (c[24] == 38) && (c[25] == 20) && (c[26] == 24) && (c[27] == 24) && (c[28] == 38) && (c[29] == 31))
			{	// PROFESSIONALTOOLS
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_EPISODIC_4); //KATANA
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_DEAGLE);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_EPISODIC_11); //STUBBY SHOTGUN
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MICRO_UZI); //MAC10
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_M4);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_SNIPERRIFLE);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_RLAUNCHER);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_GRENADE);
				isActivated = true;
			}
			else if ((c[19] == 49) && (c[20] == 22) && (c[21] == 20) && (c[22] == 20) && (c[23] == 18) && (c[24] == 19) && (c[25] == 20) && (c[26] == 24) && (c[27] == 24) && (c[28] == 38) && (c[29] == 31))
			{	// NUTTERTOOLS
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_EPISODIC_22); //CHAINSAW
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_DEAGLE);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_BARETTA);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MP5);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_M4);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_SNIPERRIFLE);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MINIGUN);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_GRENADE);
				isActivated = true;
			}
			else if ((c[18] == 38) && (c[19] == 18) && (c[20] == 30) && (c[21] == 47) && (c[22] == 18) && (c[23] == 50) && (c[24] == 18) && (c[25] == 30) && (c[26] == 38) && (c[27] == 24) && (c[28] == 49) && (c[29] == 18))
			{	// LEAVEMEALONE
				CLEAR_WANTED_LEVEL(GetPlayerIndex());
				isActivated = true;
			}
			else if ((c[12] == 21) && (c[13] == 24) && (c[14] == 22) && (c[15] == 17) && (c[16] == 24) && (c[17] == 49) && (c[18] == 20) && (c[19] == 20) && (c[20] == 30) && (c[21] == 37) && (c[22] == 18) && (c[23] == 50) && (c[24] == 18) && (c[25] == 30) && (c[26] == 38) && (c[27] == 23) && (c[28] == 47) && (c[29] == 18))
			{	// YOUWONTTAKEMEALIVE
				int wl;
				STORE_WANTED_LEVEL(GetPlayerIndex(), &wl);
				wl += 2;
				if (wl > 6)
					wl = 6;

				ALTER_WANTED_LEVEL(GetPlayerIndex(), wl);
				APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
				isActivated = true;
			}
			else if ((c[12] == 23) && (c[13] == 46) && (c[14] == 30) && (c[15] == 49) && (c[16] == 20) && (c[17] == 20) && (c[18] == 30) && (c[19] == 37) && (c[20] == 18) && (c[21] == 23) && (c[22] == 20) && (c[23] == 30) && (c[24] == 49) && (c[25] == 21) && (c[26] == 50) && (c[27] == 24) && (c[28] == 19) && (c[29] == 18))
			{	// ICANTTAKEITANYMORE
				EXPLODE_CHAR_HEAD(GetPlayerPed());
				isActivated = true;
			}
			else if ((c[21] == 30) && (c[22] == 48) && (c[23] == 23) && (c[24] == 20) && (c[25] == 32) && (c[26] == 19) && (c[27] == 23) && (c[28] == 18) && (c[29] == 34))
			{	// ABITDRIEG 
				FORCE_WEATHER_NOW(WEATHER_CLOUDY);
				isActivated = true;
			}
			else if ((c[18] == 30) && (c[19] == 25) && (c[20] == 38) && (c[21] == 18) && (c[22] == 30) && (c[23] == 31) && (c[24] == 30) && (c[25] == 49) && (c[26] == 20) && (c[27] == 32) && (c[28] == 30) && (c[29] == 21))
			{	// APLEASANTDAY
				FORCE_WEATHER_NOW(WEATHER_SUNNY);
				isActivated = true;
			}
			else if ((c[20] == 30) && (c[21] == 38) && (c[22] == 24) && (c[23] == 47) && (c[24] == 18) && (c[25] == 38) && (c[26] == 21) && (c[27] == 32) && (c[28] == 30) && (c[29] == 21))
			{	// ALOVELYDAY
				FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
				isActivated = true;

			}
			else if ((c[19] == 46) && (c[20] == 30) && (c[21] == 20) && (c[22] == 31) && (c[23] == 30) && (c[24] == 49) && (c[25] == 32) && (c[26] == 32) && (c[27] == 24) && (c[28] == 34) && (c[29] == 31))
			{	// CATSANDDOGS
				FORCE_WEATHER_NOW(WEATHER_RAINING);
				isActivated = true;
			}
			else if ((c[17] == 46) && (c[18] == 30) && (c[19] == 49) && (c[20] == 20) && (c[21] == 31) && (c[22] == 18) && (c[23] == 18) && (c[24] == 30) && (c[25] == 20) && (c[26] == 35) && (c[27] == 23) && (c[28] == 49) && (c[29] == 34))
			{	// CANTSEEATHING
				FORCE_WEATHER_NOW(WEATHER_FOGGY);
				isActivated = true;
			}
			else if ((c[23] == 48) && (c[24] == 23) && (c[25] == 34) && (c[26] == 48) && (c[27] == 30) && (c[28] == 49) && (c[29] == 34))
			{	// BIGBANG - Explodes nearest cars
				int j, k, bcar;
				float px, py, pz;
				GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
				for (j = 0; j < 20; j++)
				{
					for (k = 0; k < 20; k++)
					{
						bcar = GET_CLOSEST_CAR(px + (j * 10 - 100), py + (k * 10 - 100), pz, 300.0, 0, 69);
						if (DOES_VEHICLE_EXIST(bcar))
						{
							EXPLODE_CAR(bcar, 1, 0);
							MARK_CAR_AS_NO_LONGER_NEEDED(&bcar);
						}
					}
				}
				isActivated = true;
			}
			else if ((c[23] == 24) && (c[24] == 49) && (c[25] == 31) && (c[26] == 25) && (c[27] == 18) && (c[28] == 18) && (c[29] == 32))
			{	// ONSPEED - Speeds up time
				timeScale += 0.2;
				if (timeScale > 2.4)
					timeScale = 2.4;

				SET_TIME_SCALE(timeScale);
				isActivated = true;
			}
			else if ((c[19] == 48) && (c[20] == 24) && (c[21] == 24) && (c[22] == 24) && (c[23] == 24) && (c[24] == 24) && (c[25] == 24) && (c[26] == 19) && (c[27] == 23) && (c[28] == 49) && (c[29] == 34))
			{	// BOOOOOORING - Slows down time
				timeScale -= 0.2;
				if (timeScale <= 0.0)
					timeScale = 0.2;

				SET_TIME_SCALE(timeScale);
				isActivated = true;
			}

			if (isActivated)
			{
				isActivated = false;
				cur = 0;

				for (i = 0; i < 30; i++)
					c[i] = 0;

				PRINT_HELP("CHEAT1");
				INCREMENT_INT_STAT(STAT_TIMES_CHEATED, 1);
			}
		}
	}
}

void get_weap(int ID_scan)
{
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 1, &get_Weap[1], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 2, &get_Weap[2], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 3, &get_Weap[3], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 4, &get_Weap[4], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 5, &get_Weap[5], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 6, &get_Weap[6], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 7, &get_Weap[7], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 8, &get_Weap[8], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 9, &get_Weap[9], &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 0, &get_Weap[0], &Ammo_nan, &Ammo_nan);

	if (ID_scan == 1)
	{
		if (get_Weap[1] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 1, &Weap[1], &Ammo[1], &Ammo_nan);
		
		if (get_Weap[2] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 2, &Weap[2], &Ammo[2], &Ammo_nan);
		
		if (get_Weap[3] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 3, &Weap[3], &Ammo[3], &Ammo_nan);
		
		if (get_Weap[4] != 0)
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 4, &Weap[4], &Ammo[4], &Ammo_nan);
		
		if (get_Weap[5] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 5, &Weap[5], &Ammo[5], &Ammo_nan);
		
		if (get_Weap[6] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 6, &Weap[6], &Ammo[6], &Ammo_nan);
		
		if (get_Weap[7] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 7, &Weap[7], &Ammo[7], &Ammo_nan);
		
		if (get_Weap[8] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 8, &Weap[8], &Ammo[8], &Ammo_nan);
		
		if (get_Weap[9] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 9, &Weap[9], &Ammo[9], &Ammo_nan);
		
		if (get_Weap[0] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 0, &Weap[0], &Ammo[0], &Ammo_nan);
		
		if (DOES_PICKUP_EXIST(tweap[0]))		
			REMOVE_PICKUP(tweap[0]);
		
		CREATE_PICKUP_ROTATE(vc_weap_basket, 3, 0, 527.01, 799.434, 16.5562, 0.0, 0.0, 0.0, &tweap[0]);
	}
	else if ((ID_scan == 2) || (ID_scan == 3))
	{
		if (get_Weap[1] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 1, &Weap[11], &Ammo[11], &Ammo_nan);
		
		if (get_Weap[2] != 0)
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 2, &Weap[12], &Ammo[12], &Ammo_nan);
		
		if (get_Weap[3] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 3, &Weap[13], &Ammo[13], &Ammo_nan);
		
		if (get_Weap[4] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 4, &Weap[14], &Ammo[14], &Ammo_nan);
		
		if (get_Weap[5] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 5, &Weap[15], &Ammo[15], &Ammo_nan);
		
		if (get_Weap[6] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 6, &Weap[16], &Ammo[16], &Ammo_nan);
		
		if (get_Weap[7] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 7, &Weap[17], &Ammo[17], &Ammo_nan);
		
		if (get_Weap[8] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 8, &Weap[18], &Ammo[18], &Ammo_nan);
		
		if (get_Weap[9] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 9, &Weap[19], &Ammo[19], &Ammo_nan);
		
		if (get_Weap[0] != 0)		
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 0, &Weap[10], &Ammo[10], &Ammo_nan);
		
		if (DOES_PICKUP_EXIST(tweap[1]))	
			REMOVE_PICKUP(tweap[1]);
		
		if (ID_scan == 2)		
			CREATE_PICKUP_ROTATE(vc_weap_basket, 3, 0, -974.819, -294.504, 8.84402, 0.0, 0.0, -135.0, &tweap[1]);		
		else if (ID_scan == 3)		
			CREATE_PICKUP_ROTATE(vc_weap_basket, 3, 0, -1026.69, -298.557, 8.84074, 0.0, 0.0, -40.0, &tweap[1]);
		
	}
	REMOVE_ALL_CHAR_WEAPONS(GetPlayerPed());

	while (((IS_CHAR_IN_AREA_2D(GetPlayerPed(), 532.444, 800.618, 522.444, 800.962, 0)) && (!IS_CHAR_IN_AREA_2D(GetPlayerPed(), -974.18, -299.184, -974.749, -299.524, 0)) && (!IS_CHAR_IN_AREA_2D(GetPlayerPed(), -1031.328, -298.285, -1032.396, -298.624, 0)))) WAIT(0);
}
void lawyer(void)
{
	while (HAS_CHAR_BEEN_ARRESTED(GetPlayerPed())) WAIT(0);

	SetTime(2000);
	GENERATE_RANDOM_INT_IN_RANGE(0, 4, &randint);

	NEW_SCRIPTED_CONVERSATION();
	ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");

	if (randint == 0)
		ADD_LINE_TO_CONVERSATION(0, "R8_CA", "", 0, 0);
	else if (randint == 1)
		ADD_LINE_TO_CONVERSATION(0, "R8_DA", "", 0, 0);
	else if (randint == 2)
		ADD_LINE_TO_CONVERSATION(0, "R8_EA", "", 0, 0);
	else if (randint == 3)
		ADD_LINE_TO_CONVERSATION(0, "R8_ZA", "", 0, 0);
	else
		ADD_LINE_TO_CONVERSATION(0, "R8_A_AA", "", 0, 0);

	START_SCRIPT_CONVERSATION(1, 1);
}

float saving, text_on, heading;
Vector3 pos;

void save(void)
{
	//=========================== Printworks ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -643.221, 244.286, 5.832, -646.473, 246.34, 9.572, 0)) && (G_ONMISSION == 0) && (G_COUNT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 1;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = -645.084;
			pos.y = 246.738;
			pos.z = 6.27582;
			heading = -5.0;
			saving = 1;
			G_SAVE_SAVED = 1;
		}
	}
	else
	{
		if (text_on == 1)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== Sunshine Autos ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -595.019, -317.531, 6.782, -598.862, -313.54, 10.782, 0)) && (G_ONMISSION == 0) && (G_BUSINES_SA > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 2;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = -595.363;
			pos.y = -318.285;
			pos.z = 7.53234;
			heading = -150.0;
			saving = 1;
			G_SAVE_SAVED = 2;
		}
	}
	else
	{
		if (text_on == 2)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== Interglobal Films ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 349.382, 1463.778, 4.527, 346.333, 1467.335, 8.02, 0)) && (G_ONMISSION == 0) && (G_PRON > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 3;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 346.101;
			pos.y = 1464.79;
			pos.z = 5.03874;
			heading = 125.0;
			saving = 1;
			G_SAVE_SAVED = 3;
		}
	}

	else if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 344.294, 1471.025, 4.527, 342.19, 1473.941, 8.02, 0)) && (G_ONMISSION == 0) && (G_PRON > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 3;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 341.992;
			pos.y = 1471.62;
			pos.z = 5.03874;
			heading = 125.0;
			saving = 1;
			G_SAVE_SAVED = 3;
		}
	}
	else
	{
		if (text_on == 3)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== Cherry Popper Icecreams ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -445.067, -47.23, 4.972, -447.067, -4.102, 8.562, 0)) && (G_ONMISSION == 0) && (G_ICECREAM > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 4;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = -444.516;
			pos.y = -45.5149;
			pos.z = 5.47654;
			heading = -80.0;
			saving = 1;
			G_SAVE_SAVED = 4;
		}
	}
	else
	{
		if (text_on == 4)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== Kaufman Cabs ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -564.786, 719.034, 5.225, -566.732, 722.27, 9.459, 0)) && (G_ONMISSION == 0) && (G_CABS > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 5;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = -567.321;
			pos.y = 720.751;
			pos.z = 5.67434;
			heading = 60.0;
			saving = 1;
			G_SAVE_SAVED = 5;
		}
	}
	else
	{
		if (text_on == 5)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== Malibu Club ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 897.958, 479.305, 9.559, 893.964, 483.173, 12.29, 0)) && (G_ONMISSION == 0) && (G_CLUB > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 6;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 896.001;
			pos.y = 479.025;
			pos.z = 9.93599;
			heading = -175.0;
			saving = 1;
			G_SAVE_SAVED = 6;
		}
	}
	else
	{
		if (text_on == 6)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== The Boatyard ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -234.66, -952.034, 7.566, -236.961, -949.769, 11.824, 0)) && (G_ONMISSION == 0) && (G_COKERUN > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 7;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = -235.225;
			pos.y = -949.423;
			pos.z = 8.07865;
			heading = -25.0;
			saving = 1;
			G_SAVE_SAVED = 7;
		}
	}
	else
	{
		if (text_on == 7)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== Pole Position Club ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 508.048, -917.682, 4.345, 505.62, -915.054, 7.33, 0)) && (G_ONMISSION == 0) && (G_STRIP > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 8;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 507.606;
			pos.y = -917.858;
			pos.z = 4.84248;
			heading = -175.0;
			saving = 1;
			G_SAVE_SAVED = 8;
		}
	}
	else
	{
		if (text_on == 8)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== El Swanko Casa ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 863.972, 1132.26, 6.177, 858.972, 1137.26, 11.177, 0)) && (G_ONMISSION == 0) && (G_SWANKO > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		pos.x = 861.53;
		pos.y = 1139.81;
		pos.z = 6.99313;
		heading = 0.0;
		saving = 1;
		G_SAVE_SAVED = 9;
	}
	//=========================== Links View Apartment ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 736.09, 906.963, 6.693, 731.09, 911.963, 11.693, 0)) && (G_ONMISSION == 0) && (G_LINKS > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		pos.x = 737.991;
		pos.y = 909.371;
		pos.z = 7.45291;
		heading = -85.0;
		saving = 1;
		G_SAVE_SAVED = 10;
	}
	//=========================== Hyman Condo ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -400.854, 1841.342, 5.229, -404.119, 1845.572, 10.229, 0)) && (G_ONMISSION == 0) && (G_CONDO > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		pos.x = -401.593;
		pos.y = 1839.58;
		pos.z = 5.7949;
		heading = -165.0;
		saving = 1;
		G_SAVE_SAVED = 11;
	}
	//=========================== Ocean Heighs Aprt ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 453.212, -972.369, 6.965, 447.555, -969.353, 10.267, 0)) && (G_ONMISSION == 0) && (G_HEIGHS > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		pos.x = 451.255;
		pos.y = -967.217;
		pos.z = 7.52892;
		heading = -5.0;
		saving = 1;
		G_SAVE_SAVED = 12;
	}
	//=========================== 1102 Washington Street ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 521.188, -272.005, 5.308, 518.527, -269.363, 10.308, 0)) && (G_ONMISSION == 0) && (G_WS_1102 > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		pos.x = 522.489;
		pos.y = -272.164;
		pos.z = 6.00446;
		heading = -120.0;
		saving = 1;
		G_SAVE_SAVED = 13;
	}
	//=========================== 3321 Vice Point ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 967.985, 1806.919, 11.92, 964.985, 1809.919, 16.438, 0)) && (G_ONMISSION == 0) && (G_VP_3321 > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		pos.x = 963.529;
		pos.y = 1805.22;
		pos.z = 12.0903;
		heading = 130.0;
		saving = 1;
		G_SAVE_SAVED = 14;
	}

	//=========================== Skumole Shack ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -125.348, 1231.967, 14.033, -129.233, 1235.396, 17.309, 0)) && (G_ONMISSION == 0) && (G_SHACK > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		pos.x = -127.19;
		pos.y = 1236.19;
		pos.z = 14.8111;
		heading = 0.0;
		saving = 1;
		G_SAVE_SAVED = 15;
	}
	//=========================== Ocean View Hotel ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 662.561, -731.554, 13.874, 659.649, -728.9, 17.472, 0)) && (G_ONMISSION == 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 16;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 661.254;
			pos.y = -731.808;
			pos.z = 14.4212;
			heading = -175.0;
			saving = 1;
			G_SAVE_SAVED = 16;
		}
	}
	else
	{
		if (text_on == 16)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}
	//=========================== Vercetti Mansion ===========================

	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 29.714, -26.031, 12.711, 26.559, -24.301, 15.638, 0)) && (G_ONMISSION == 0) && (G_PROTECT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 17;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 28.115;
			pos.y = -26.2823;
			pos.z = 13.2436;
			heading = -175.0;
			saving = 1;
			G_SAVE_SAVED = 17;
		}
	}

	else if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 29.714, -30.213, 12.711, 26.559, -28.483, 15.638, 0)) && (G_ONMISSION == 0) && (G_PROTECT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 17;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 28.0589;
			pos.y = -28.1805;
			pos.z = 13.2436;
			heading = -10.0;
			saving = 1;
			G_SAVE_SAVED = 17;
		}
	}

	else if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 62.09, -60.884, 19.687, 59.834, -58.636, 24.098, 0)) && (G_ONMISSION == 0) && (G_PROTECT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 17;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 60.0189;
			pos.y = -58.3347;
			pos.z = 20.0673;
			heading = 40.0;
			saving = 1;
			G_SAVE_SAVED = 17;
		}
	}

	else if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 48.989, -62.33, 19.687, 46.732, -59.231, 24.098, 0)) && (G_ONMISSION == 0) && (G_PROTECT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP();
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 17;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))
		{
			pos.x = 49.0995;
			pos.y = -59.0782;
			pos.z = 20.0673;
			heading = -45.0;
			saving = 1;
			G_SAVE_SAVED = 17;
		}
	}
	else
	{
		if (text_on == 17)
		{
			CLEAR_HELP();
			text_on = 0;
		}
	}

	if (saving == 1)
	{
		CLEAR_HELP();
		saving = 0;
		text_on = 0;
		//DO_SCREEN_FADE_OUT(2000);
		G_SAVE_OCCURED = TRUE;
		ACTIVATE_SAVE_MENU();
		SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), pos.x, pos.y, pos.z);
		SET_CHAR_HEADING(GetPlayerPed(), heading);
		SET_CHAR_HEALTH(GetPlayerPed(), 200);
		ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
		APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
		uint h, m;
		GET_TIME_OF_DAY(&h, &m);
		FORWARD_TO_TIME_OF_DAY(h + 6, m);
		WAIT(2000);
		if (DID_SAVE_COMPLETE_SUCCESSFULLY())
		{
			INCREMENT_INT_STAT(STAT_SAVES_MADE, 1);
			G_SAVE_OCCURED = FALSE;
		}
		//DO_SCREEN_FADE_IN_UNHACKED(2000);
	}
}

void InitScriptLauncher(void)
{
	CreateScript("ambstreams");
	CreateScript("AVERY");
	CreateScript("BIKE");
	CreateScript("business_sale");
	CreateScript("COKERUN");
	CreateScript("CORTEZ");
	CreateScript("COUNT");
	CreateScript("CUBAN");
	CreateScript("DIAZ");
	CreateScript("HAITI");
	CreateScript("ICECREAM");
	CreateScript("KAUFMAN");
	//if (!G_LAWYER == 5)
	CreateScript("LAWYER");
	CreateScript("MALIBU");
	CreateScript("map_bounds");
	CreateScript("mob_phone");
	CreateScript("packages");
	CreateScript("PHIL");
	CreateScript("pickups");
	CreateScript("PRON");
	CreateScript("PROTECT");
	CreateScript("ROCK");
	CreateScript("side_quests");
	CreateScript("stadium");
	CreateScript("street_phone");
	CreateScript("STRIP");
	CreateScript("sunshine_garages");
	CreateScript("sunshine_race");
	CreateScript("weap_sounds");
	CreateScript("WORLD");
	CreateScript("vc_jump");
}

void main(void)
{
	int intHash;
	uint startOffset;
	bool isPlaying, stop_aud, inInterior, isVolChanged;
	float vol, delta;

	letterKey[0] = KEY_Q;
	letterKey[1] = KEY_W;
	letterKey[2] = KEY_E;
	letterKey[3] = KEY_R;
	letterKey[4] = KEY_T;
	letterKey[5] = KEY_Y;
	letterKey[6] = KEY_U;
	letterKey[7] = KEY_I;
	letterKey[8] = KEY_O;
	letterKey[9] = KEY_P;
	letterKey[10] = KEY_A;
	letterKey[11] = KEY_S;
	letterKey[12] = KEY_D;
	letterKey[13] = KEY_F;
	letterKey[14] = KEY_G;
	letterKey[15] = KEY_H;
	letterKey[16] = KEY_J;
	letterKey[17] = KEY_K;
	letterKey[18] = KEY_L;
	letterKey[19] = KEY_Z;
	letterKey[20] = KEY_X;
	letterKey[21] = KEY_C;
	letterKey[22] = KEY_V;
	letterKey[23] = KEY_B;
	letterKey[24] = KEY_N;
	letterKey[25] = KEY_M;

	int randint;
	GENERATE_RANDOM_INT(&randint);
	SET_RANDOM_SEED(randint);
	THIS_SCRIPT_SHOULD_BE_SAVED();
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(TRUE);
	UNLOCK_LAZLOW_STATION();

	G_ONMISSION = 0;
	G_COLLECTOR = 0;
	G_SALE_NO = 0;
	G_MAIN_CALL = 0;
	G_LANCE_CALL = 0;
	G_MERSEDES_CALL = 0;
	G_AVERY_CALL = 0;

	G_LAWYER = 0;
	G_BIKE = 0;
	G_COKERUN = 0;
	G_COUNT = 0;
	G_CUBAN = 0;
	G_DIAZ = 0;
	G_HAITI = 0;
	G_ICECREAM = 0;
	G_CABS = 0;
	G_CLUB = 0;
	G_PHIL = 0;
	G_PRON = 0;
	G_PROTECT = 0;
	G_ROCK = 0;
	G_STRIP = 0;
	G_BUSINES_SA = 0;
	G_ASSASSIN = 0;
	G_AVERY = 0;
	G_CORTEZ = 0;

	G_SWANKO = 0;
	G_LINKS = 0;
	G_CONDO = 0;
	G_HEIGHS = 0;
	G_WS_1102 = 0;
	G_VP_3321 = 0;
	G_SHACK = 0;

	G_BLOODRING = 0;
	G_HOTRING = 0;
	G_DIRTRING = 0;
	G_TAXI = 0;
	G_PIZZA = 0;
	G_MEDIC = 0;
	G_FIRE = 0;
	G_COPCAR = 0;
	G_HELI1SC = 0;
	G_BMX_1 = 0;
	G_CARPRK = 0;
	G_PCJ = 0;
	G_RC_1 = 0;
	G_JUMP = 0;
	G_PACKET = 0;
	G_SA_RACE = 0;

	SET_PLAYER_CONTROL(GetPlayerIndex(), TRUE);
	FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
	FORWARD_TO_TIME_OF_DAY(06, 00);
	RELEASE_WEATHER();
	RELEASE_TIME_OF_DAY();
	SET_CAR_DENSITY_MULTIPLIER(1.0);
	SET_MAX_WANTED_LEVEL(6);
	SET_INT_STAT(STAT_ISLANDS_UNLOCKED, 2); // Is this even needed?

	REGISTER_SAVE_HOUSE(664.601, -746.511, 7.041, 250, "OceanViewHotel", 0);
	ENABLE_SAVE_HOUSE(0, true);

	ADD_POLICE_RESTART(831.488, 63.0072, 5.98145, -45.0, 0); // Washington Beach
	ADD_POLICE_RESTART(941.943, 1041.08, 5.54716, 180, 0); // Vice Point

	ADD_HOSPITAL_RESTART(320.068, -433.964, 4.70675, -85, 0); // Ocean Beach
	ADD_HOSPITAL_RESTART(925.961, 1235.05, 6.33435, 80, 0); // Vice Point

	SPECIFY_SCRIPT_POPULATION_ZONE_NUM_PEDS(100);
	SPECIFY_SCRIPT_POPULATION_ZONE_NUM_SCENARIO_PEDS(100);
	ACTIVATE_SCRIPT_POPULATION_ZONE();

	CreateScript("intro");

	while (TRUE)
	{
		WAIT(0);
		cheats();
		save();
		if (ALLOW_ONE_TIME_ONLY_COMMANDS_TO_RUN)
			InitScriptLauncher();

		if (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 532.444, 800.618, 14.841, 522.444, 800.962, 20.841, 0))
			get_weap(1);
		if (IS_CHAR_IN_AREA_3D(GetPlayerPed(), -974.18, -299.184, 8.415, -974.749, -299.524, 13.73, 0))
			get_weap(2);
		if (IS_CHAR_IN_AREA_3D(GetPlayerPed(), -1031.328, -298.285, 8.415, -1032.396, -298.624, 13.73, 0))
			get_weap(3);

		if (HAS_PICKUP_BEEN_COLLECTED(tweap[0]))
		{
			UpdateWeaponOfPed(GetPlayerPed(), Weap[1]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[2]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[3]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[4]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[5]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[6]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[7]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[8]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[9]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[0]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[1], Ammo[1]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[2], Ammo[2]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[3], Ammo[3]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[4], Ammo[4]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[5], Ammo[5]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[6], Ammo[6]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[7], Ammo[7]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[8], Ammo[8]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[9], Ammo[9]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[0], Ammo[0]);
		}
		if (HAS_PICKUP_BEEN_COLLECTED(tweap[1]))
		{
			UpdateWeaponOfPed(GetPlayerPed(), Weap[11]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[12]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[13]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[14]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[15]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[16]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[17]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[18]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[19]);
			UpdateWeaponOfPed(GetPlayerPed(), Weap[10]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[11], Ammo[11]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[12], Ammo[12]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[13], Ammo[13]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[14], Ammo[14]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[15], Ammo[15]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[16], Ammo[16]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[17], Ammo[17]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[18], Ammo[18]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[19], Ammo[19]);
			SET_CHAR_AMMO(GetPlayerPed(), Weap[10], Ammo[10]);
		}

		if (HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()))
			lawyer();

		GET_INTERIOR_FROM_CHAR(GetPlayerPed(), &intHash); // This sucks we should remove this hackjob and use a proper method of interior music using rageAT/Parik audio tool
		if (intHash == 514) // MALIBU_CLUB
		{
			if (isPlaying == 0)
			{
				GENERATE_RANDOM_INT_IN_RANGE(0, 550000, &startOffset);
				while (!(PRELOAD_STREAM_WITH_START_OFFSET("INTERIOR_STREAMS_MALIBU_CLUB", startOffset))) WAIT(0);

				PLAY_STREAM_FRONTEND();
				SET_STREAM_PARAMS(0.0, 15000);
				isPlaying = 1;
				isVolChanged = 1;
			}
			inInterior = 1;
		}
		else if (intHash == 258) // MALL
		{
			if (isPlaying == 0)
			{
				GENERATE_RANDOM_INT_IN_RANGE(0, 200000, &startOffset);
				while (!(PRELOAD_STREAM_WITH_START_OFFSET("INTERIOR_STREAMS_MALL_AMB", startOffset))) WAIT(0);

				PLAY_STREAM_FRONTEND();
				SET_STREAM_PARAMS(0.0, 15000);
				isPlaying = 1;
				isVolChanged = 1;
			}
			inInterior = 1;
		}
		else if (intHash == 1026)// HOTEL
		{
			if (isPlaying == 0)
			{
				GENERATE_RANDOM_INT_IN_RANGE(0, 450000, &startOffset);
				while (!(PRELOAD_STREAM_WITH_START_OFFSET("INTERIOR_STREAMS_HOTEL_MUSIC", startOffset))) WAIT(0);

				PLAY_STREAM_FRONTEND();
				SET_STREAM_PARAMS(0.0, 15000);
				isPlaying = 1;
				isVolChanged = 1;
			}
			inInterior = 1;
		}
		else if (intHash == 1282)// STRIP
		{
			if (isPlaying == 0)
			{
				GENERATE_RANDOM_INT_IN_RANGE(0, 650000, &startOffset);
				while (!(PRELOAD_STREAM_WITH_START_OFFSET("INTERIOR_STREAMS_STRIPCLUB", startOffset))) WAIT(0);

				PLAY_STREAM_FRONTEND();
				SET_STREAM_PARAMS(0.0, 15000);
				isPlaying = 1;
				isVolChanged = 1;
			}
			inInterior = 1;
		}
		else
		{
			inInterior = 0;
			if (stop_aud == 1)
			{
				SET_STREAM_PARAMS(15.1, 15000);
				STOP_STREAM();
				isVolChanged = 0;
				isPlaying = 0;
				stop_aud = 0;
			}
		}

		GET_FRAME_TIME(&delta);
		if (inInterior == 1)
		{
			if (isVolChanged == 1)
			{
				vol += delta * 1.5;
				SET_STREAM_PARAMS(vol, 15000);
				if (vol > 15.1)
				{
					vol = 15.1;
					isVolChanged = 0;
				}
			}
		}
		else
		{
			if (isPlaying == 1)
			{
				vol -= delta * 3;
				SET_STREAM_PARAMS(vol, 15000);
				if (vol <= 0.0)
				{
					vol = 0.0;
					stop_aud = 1;
				}
			}
		}
	}
}