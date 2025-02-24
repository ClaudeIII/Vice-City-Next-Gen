#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"

float PlayX, PlayY, PlayZ, heading, blip_on, skip, HealGB_1, HealGB_2, HealGB_3, HealGB_4, ragdool, speed, cop_on, textur, start, cam_on, set_cam, help, autosave;
float PedR, add_gun1, add_gun2, add_gun3, add_gun4, touch1, touch2, touch3, touch4, Health, carH1, carH2, carH3, carHUD_w, carHUD_y1, carHUD_y2, carHUD_y3, carHUD_x;
float PedX1, PedY1, PedZ1, PedR1, PedX2, PedY2, PedZ2, PedX3, PedY3, PedZ3, PedX4, PedY4, PedZ4, point, speech, audio_on;
float create_car5, create_car6, create_car7, create_car8, press_moped, bonus1, bonus2, bonus3, bonus4, res_moped, del_blip1, del_blip2, del_blip3, del_blip4;

void bonus(void)
{
	SETTIMERC( 0 );
	while(true)
	{
		WAIT(0);
		SET_TEXT_COLOUR(255, 159, 255, 255);
		SET_TEXT_SCALE(0.5, 0.7);
		SET_TEXT_EDGE(1, 0, 0, 0, 255);
		SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
		SET_TEXT_CENTRE(1);
		DISPLAY_TEXT_WITH_NUMBER(0.5, 0.45, "BONUS", 100);//BONUS $~1~
		if ( TIMERC() > 3000 )
		{
			ADD_SCORE( GetPlayerIndex(), +100 );
			break;
		}
	}
}
void phil(void)
{
	blip_on = 0;
	autosave = 0;
	Blip phil_ico;
	WAIT(3000);
	while(true)
	{
		WAIT(0);
		if (autosave == 1)
		{
			autosave = 0;
			G_SAVE_SAVED = 16;
			G_SAVE_OCCURED = TRUE;
			DO_AUTO_SAVE();
			WAIT(500);
			if (DID_SAVE_COMPLETE_SUCCESSFULLY())
			{
				G_SAVE_OCCURED = FALSE;
			}
		}
//============================== Gun Runner ======================================
		if ((G_ONMISSION == 0) && (G_PHIL == 1))
		{
			if (blip_on == 0)
			{
				ADD_BLIP_FOR_COORD(-668.375, 876.086, 5.22, &phil_ico);
				CHANGE_BLIP_SPRITE(phil_ico, BLIP_PACKIE);
				CHANGE_BLIP_SCALE(phil_ico, 1.1);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(phil_ico, "LG_08");//иконка на радаре называние в истории карты "Боярский"
				blip_on = 1;
			}
			DRAW_CHECKPOINT( -668.375, 876.086, 5.22, 1.5, 160, 116, 209);
			GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
			GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -668.375, 876.086, 5.22, &heading);
			if (( heading < 1.5) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
			{
				G_ONMISSION = 1;
				REMOVE_BLIP(phil_ico);
				blip_on = 0;
				SET_MAX_WANTED_LEVEL(2);


				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );
				DO_SCREEN_FADE_OUT( 1000 );
				while(true)
				{
					WAIT(0);
					if (IS_SCREEN_FADED_OUT())
					{
						break;
					}
				}
				SET_CHAR_COORDINATES(GetPlayerPed(), -663.706, 874.532, 5.47574 );
				SET_CHAR_HEADING(GetPlayerPed(), -140.0 );
				ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
				FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
				RELEASE_WEATHER();
				
				Ped ped1, ped2, ped3, ped4, ped5, ped6, ped7, ped8, ped9, ped10, ped11, ped12, ped13, ped14, ped15, ped16;
				Car car1, car2, car3, car4, car5, car6, car7, car8, car9;
				Pickup sweap_1, sweap_2, sweap_3, sweap_4, sweap_5, sweap_6;
				Blip car1_ico, car2_ico, car3_ico, car4_ico, weap1_ico, weap2_ico, weap3_ico, weap4_ico;
				Object gunbox1, gunbox2, gunbox3, gunbox4;
				int dm, cdm;

				skip = 0;
				add_gun1 = 0;
				add_gun2 = 0;
				add_gun3 = 0;
				add_gun4 = 0;
				touch1 = 0;
				touch2 = 0;
				touch3 = 0;
				touch4 = 0;
				create_car5 = 0;
				create_car6 = 0;
				create_car7 = 0;
				create_car8 = 0;
				press_moped = 1;
				bonus1 = 0;
				bonus2 = 0;
				bonus3 = 0;
				bonus4 = 0;
				del_blip1 = 0;
				del_blip2 = 0;
				del_blip3 = 0;
				del_blip4 = 0;
				res_moped = 0;

				uint CarM1 = MODEL_URANUS;
				uint CarM2 = MODEL_PATRIOT;
				uint CarM3 = MODEL_FAGGIO;

				uint PedM1 = MODEL_M_Y_DEALER;
				uint PedM2 = MODEL_M_Y_DORK_02;
				uint gunboxM = ne_wood_gunbox;// GunBox
				uint CarHP1, CarHP2, CarHP3, CarHP4;

				REQUEST_MODEL(CarM1);
				while (!HAS_MODEL_LOADED(CarM1)) WAIT(0);
				REQUEST_MODEL(CarM2);
				while (!HAS_MODEL_LOADED(CarM2)) WAIT(0);
				REQUEST_MODEL(CarM3);
				while (!HAS_MODEL_LOADED(CarM3)) WAIT(0);
				REQUEST_MODEL(PedM1);// Таксист
				while (!HAS_MODEL_LOADED(PedM1));
				REQUEST_MODEL(PedM2);// Таксист
				while (!HAS_MODEL_LOADED(PedM2));

				REQUEST_MODEL(gunboxM);
				while (!HAS_MODEL_LOADED(gunboxM)) WAIT(0);

				LOAD_CHAR_DECISION_MAKER(2, &dm);
				LOAD_COMBAT_DECISION_MAKER(3, &cdm);
				SET_DECISION_MAKER_ATTRIBUTE_SIGHT_RANGE(dm, 50);
				SET_DECISION_MAKER_ATTRIBUTE_SIGHT_RANGE(cdm, 50);

				FORCE_WEATHER_NOW(WEATHER_SUNNY);
				RELEASE_WEATHER();

				//------------ катсцена ----------------
				LOAD_ADDITIONAL_TEXT( "PHIL_1", 6 );
				START_CUTSCENE_NOW("phil_1");
				while (!HAS_CUTSCENE_LOADED())
				{
					WAIT(0);
				}

				DO_SCREEN_FADE_IN(0);
				while (!HAS_CUTSCENE_FINISHED())
				{
					WAIT(0);
				}

				if ((IS_SCREEN_FADING_OUT()) || (IS_SCREEN_FADED_OUT()))
				{
					DO_SCREEN_FADE_IN(0);
				}

				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

				CREATE_OBJECT_NO_OFFSET(gunboxM, -659.77, 868.278, 5.71862, &gunbox1, TRUE);
				CREATE_OBJECT_NO_OFFSET(gunboxM, -659.77, 868.278, 5.71862, &gunbox2, TRUE);
				CREATE_OBJECT_NO_OFFSET(gunboxM, -659.77, 868.278, 5.71862, &gunbox3, TRUE);
				CREATE_OBJECT_NO_OFFSET(gunboxM, -659.77, 868.278, 5.71862, &gunbox4, TRUE);

				SET_OBJECT_HEALTH(gunbox1, 200);
				SET_OBJECT_HEALTH(gunbox2, 200);
				SET_OBJECT_HEALTH(gunbox3, 200);
				SET_OBJECT_HEALTH(gunbox4, 200);

				CREATE_CAR(CarM1, -757.6+433, 23.9+533, 9.9-5, &car1, TRUE);
				CREATE_CAR(CarM1, -763.6+433, 12.9+533, 9.9-5, &car2, TRUE);
				CREATE_CAR(CarM1, -674.9+433, 788.4+533, 10.3-5, &car3, TRUE);
				CREATE_CAR(CarM1, -674.9+433, 777.1+533, 10.3-5, &car4, TRUE);
				CREATE_CAR(CarM2, -631.575, 854.196, 5.86617, &car9, TRUE);
				SET_CAR_HEADING(car9, -115.0);

				//мопеды
				CREATE_CAR(CarM3, 299.551, -787.416, 5.44546, &car5, TRUE);
				CREATE_CAR(CarM3, 295.942, -787.416, 5.44546, &car6, TRUE);
				CREATE_CAR(CarM3, 292.585, -787.416, 5.44546, &car7, TRUE);
				CREATE_CAR(CarM3, 289.167, -787.416, 5.44546, &car8, TRUE);
				
				ATTACH_OBJECT_TO_CAR(gunbox1, car1, 0, -0.39, -0.415, 0.8, 11, 0.0, 22);
				ATTACH_OBJECT_TO_CAR(gunbox2, car2, 0, -0.39, -0.415, 0.8, 11, 0.0, 22);
				ATTACH_OBJECT_TO_CAR(gunbox3, car3, 0, -0.39, -0.415, 0.8, 11, 0.0, 22);
				ATTACH_OBJECT_TO_CAR(gunbox4, car4, 0, -0.39, -0.415, 0.8, 11, 0.0, 22);

				LOCK_CAR_DOORS(car1, 3);
				LOCK_CAR_DOORS(car2, 3);
				LOCK_CAR_DOORS(car3, 3);
				LOCK_CAR_DOORS(car4, 3);
				TURN_OFF_VEHICLE_EXTRA(car1, 9, 0);
				TURN_OFF_VEHICLE_EXTRA(car2, 9, 0);
				TURN_OFF_VEHICLE_EXTRA(car3, 9, 0);
				TURN_OFF_VEHICLE_EXTRA(car4, 9, 0);

				CREATE_CHAR_INSIDE_CAR(car1, 1, PedM1, &ped1);
				CREATE_CHAR_INSIDE_CAR(car2, 1, PedM2, &ped2);
				CREATE_CHAR_INSIDE_CAR(car3, 1, PedM2, &ped3);
				CREATE_CHAR_INSIDE_CAR(car4, 1, PedM1, &ped4);

				CREATE_CHAR_AS_PASSENGER(car1, 1, PedM2, 0, &ped5);
				CREATE_CHAR_AS_PASSENGER(car2, 1, PedM1, 0, &ped6);
				CREATE_CHAR_AS_PASSENGER(car3, 1, PedM1, 0, &ped7);
				CREATE_CHAR_AS_PASSENGER(car4, 1, PedM2, 0, &ped8);

				CREATE_CHAR_AS_PASSENGER(car1, 1, PedM2, 2, &ped9);
				CREATE_CHAR_AS_PASSENGER(car2, 1, PedM2, 2, &ped10);
				CREATE_CHAR_AS_PASSENGER(car3, 1, PedM1, 2, &ped11);
				CREATE_CHAR_AS_PASSENGER(car4, 1, PedM1, 2, &ped12);

				//мопедисты
				CREATE_CHAR_INSIDE_CAR(car5, 1, PedM1, &ped13);
				CREATE_CHAR_INSIDE_CAR(car6, 1, PedM2, &ped14);
				CREATE_CHAR_INSIDE_CAR(car7, 1, PedM1, &ped15);
				CREATE_CHAR_INSIDE_CAR(car8, 1, PedM2, &ped16);

				CREATE_PICKUP_ROTATE(w_grenade, 3, 10, -624.027, 856.452, 5.28738, 90.0, 0.0, 0.0, &sweap_5);
				CREATE_PICKUP_ROTATE(w_mp5, 3, 90, -624.034, 856.909, 5.45563, -75.0, -80.0, 0.0, &sweap_6);
				// Дать винтовку

				ADD_BLIP_FOR_CAR(car1, &car1_ico);
				CHANGE_BLIP_SPRITE(car1_ico, BLIP_OBJECTIVE);
				CHANGE_BLIP_COLOUR(car1_ico, 19);
				CHANGE_BLIP_SCALE(car1_ico, 0.6);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(car1_ico, "MO_TARGET");

				ADD_BLIP_FOR_CAR(car2, &car2_ico);
				CHANGE_BLIP_SPRITE(car2_ico, BLIP_OBJECTIVE);
				CHANGE_BLIP_COLOUR(car2_ico, 19);
				CHANGE_BLIP_SCALE(car2_ico, 0.6);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(car2_ico, "MO_TARGET");

				ADD_BLIP_FOR_CAR(car3, &car3_ico);
				CHANGE_BLIP_SPRITE(car3_ico, BLIP_OBJECTIVE);
				CHANGE_BLIP_COLOUR(car3_ico, 19);
				CHANGE_BLIP_SCALE(car3_ico, 0.6);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(car3_ico, "MO_TARGET");

				ADD_BLIP_FOR_CAR(car4, &car4_ico);
				CHANGE_BLIP_SPRITE(car4_ico, BLIP_OBJECTIVE);
				CHANGE_BLIP_COLOUR(car4_ico, 19);
				CHANGE_BLIP_SCALE(car4_ico, 0.6);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(car4_ico, "MO_TARGET");

				TASK_CAR_DRIVE_WANDER(ped1, car1, 20.0, 2);
				TASK_CAR_DRIVE_WANDER(ped2, car2, 20.0, 2);
				TASK_CAR_DRIVE_WANDER(ped3, car3, 20.0, 2);
				TASK_CAR_DRIVE_WANDER(ped4, car4, 20.0, 2);

				CLEAR_PRINTS();
				PRINT_STRING_IN_STRING("string", "PHI1_01", 5000, 1);//~g~Go and knock the arms off the back of the dealers' trucks.

				UpdateWeaponOfPed(ped5, WEAPON_PISTOL);
				SET_CURRENT_CHAR_WEAPON(ped5, WEAPON_PISTOL, TRUE);
				UpdateWeaponOfPed(ped6, WEAPON_MICRO_UZI);
				SET_CURRENT_CHAR_WEAPON(ped6, WEAPON_MICRO_UZI, TRUE);
				UpdateWeaponOfPed(ped7, WEAPON_PISTOL);
				SET_CURRENT_CHAR_WEAPON(ped7, WEAPON_PISTOL, TRUE);
				UpdateWeaponOfPed(ped8, WEAPON_MICRO_UZI);
				SET_CURRENT_CHAR_WEAPON(ped8, WEAPON_MICRO_UZI, TRUE);

				UpdateWeaponOfPed(ped9, WEAPON_MICRO_UZI);
				SET_CURRENT_CHAR_WEAPON(ped9, WEAPON_MICRO_UZI, TRUE);
				UpdateWeaponOfPed(ped10, WEAPON_DEAGLE);
				SET_CURRENT_CHAR_WEAPON(ped10, WEAPON_DEAGLE, TRUE);
				UpdateWeaponOfPed(ped11, WEAPON_MICRO_UZI);
				SET_CURRENT_CHAR_WEAPON(ped11, WEAPON_MICRO_UZI, TRUE);
				UpdateWeaponOfPed(ped12, WEAPON_DEAGLE);
				SET_CURRENT_CHAR_WEAPON(ped12, WEAPON_DEAGLE, TRUE);

				SET_CHAR_DECISION_MAKER(ped1, dm);
				SET_CHAR_DECISION_MAKER(ped2, dm);
				SET_CHAR_DECISION_MAKER(ped3, dm);
				SET_CHAR_DECISION_MAKER(ped4, dm);
				SET_COMBAT_DECISION_MAKER(ped1, cdm);
				SET_COMBAT_DECISION_MAKER(ped2, cdm);
				SET_COMBAT_DECISION_MAKER(ped3, cdm);
				SET_COMBAT_DECISION_MAKER(ped4, cdm);

				while(true)
				{
					WAIT(0);
					GET_OBJECT_HEALTH(gunbox1, &HealGB_1);
					GET_OBJECT_HEALTH(gunbox2, &HealGB_2);
					GET_OBJECT_HEALTH(gunbox3, &HealGB_3);
					GET_OBJECT_HEALTH(gunbox4, &HealGB_4);
					GET_CAR_HEALTH(car1, &CarHP1);
					GET_CAR_HEALTH(car2, &CarHP2);
					GET_CAR_HEALTH(car3, &CarHP3);
					GET_CAR_HEALTH(car4, &CarHP4);

					GET_CAR_COORDINATES(car1, &PedX1, &PedY1, &PedZ1);
					GET_CAR_COORDINATES(car2, &PedX2, &PedY2, &PedZ2);
					GET_CAR_COORDINATES(car3, &PedX3, &PedY3, &PedZ3);
					GET_CAR_COORDINATES(car4, &PedX4, &PedY4, &PedZ4);

					//DISPLAY_TEXT_WITH_NUMBER(0.9203125, 0.46587074, "CP_TIME_NOZERO", HealGB_1);// 
					//DISPLAY_TEXT_WITH_NUMBER(0.9203125, 0.57587074, "CP_TIME_NOZERO", HealGB_2);// 
					//DISPLAY_TEXT_WITH_NUMBER(0.9203125, 0.68587074, "CP_TIME_NOZERO", HealGB_3);// 
					//DISPLAY_TEXT_WITH_NUMBER(0.9203125, 0.79587074, "CP_TIME_NOZERO", HealGB_4);// 

					// из вываливается
					if (((HealGB_1 < 10) && ( add_gun1 == 0)) || ((CarHP1 < 750) && (add_gun1 == 0)))
					{
						if (IS_CAR_DEAD(car1))
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_10", 5000, 1);//~r~You idiot! You have destroyed the merchandise!
							skip = 1;
							break;
						}
						else
						{
							// Агруссия водителя
							SET_CHAR_RELATIONSHIP_GROUP(ped1, 5);
							SET_CHAR_RELATIONSHIP(ped1, 5, 0);
							SET_SENSE_RANGE(ped1, 2000.0);
							SET_CHAR_WILL_USE_COVER(ped1, 0);
							SET_CHAR_WILL_USE_CARS_IN_COMBAT(ped1, 1);
							TASK_COMBAT(ped1, GetPlayerPed());

							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "PHI1_02", 5000, 1);//~g~The arms dealer dropped his load. Smash the crate and pick up the weapon.
							PLAY_AUDIO_EVENT( "FRONTEND_OTHER_RACE_321" );
							GET_GROUND_Z_FOR_3D_COORD(PedX1, PedY1, PedZ1, &PedZ1);
							// даём

							CREATE_PICKUP_ROTATE(w_eagle, 3, 5, PedX1, PedY1, PedZ1+0.2, 90.0, 0.0, 0.0, &sweap_1);
							ADD_BLIP_FOR_PICKUP(sweap_1, &weap1_ico);
							CHANGE_BLIP_SPRITE(weap1_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(weap1_ico, 5);
							CHANGE_BLIP_SCALE(weap1_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(weap1_ico, "MO_TARGET");
							add_gun1 = 1;
						}
					}
					if (((HealGB_2 < 10) && ( add_gun2 == 0)) || ((CarHP2 < 750) && (add_gun2 == 0)))
					{
						if (IS_CAR_DEAD(car2))
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_10", 5000, 1);//~r~You idiot! You have destroyed the merchandise!
							skip = 1;
							break;
						}
						else
						{
							// Агруссия водителя
							SET_CHAR_RELATIONSHIP_GROUP(ped2, 5);
							SET_CHAR_RELATIONSHIP(ped2, 5, 0);
							SET_SENSE_RANGE(ped2, 2000.0);
							SET_CHAR_WILL_USE_COVER(ped2, 0);
							SET_CHAR_WILL_USE_CARS_IN_COMBAT(ped2, 1);
							TASK_COMBAT(ped2, GetPlayerPed());

							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "PHI1_02", 5000, 1);//~g~The arms dealer dropped his load. Smash the crate and pick up the weapon.
							PLAY_AUDIO_EVENT( "FRONTEND_OTHER_RACE_321" );
							GET_GROUND_Z_FOR_3D_COORD(PedX2, PedY2, PedZ2, &PedZ2);

							// даём
							CREATE_PICKUP_ROTATE(w_pumpshot, 3, 5, PedX2, PedY2, PedZ2+0.2, 90.0, 0.0, 0.0, &sweap_2);
							ADD_BLIP_FOR_PICKUP(sweap_2, &weap2_ico);
							CHANGE_BLIP_SPRITE(weap2_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(weap2_ico, 5);
							CHANGE_BLIP_SCALE(weap2_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(weap2_ico, "MO_TARGET");
							add_gun2 = 1;
						}
					}
					if (((HealGB_3 < 10) && ( add_gun3 == 0)) || ((CarHP3 < 750) && (add_gun3 == 0)))
					{
						if (IS_CAR_DEAD(car3))
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_10", 5000, 1);//~r~You idiot! You have destroyed the merchandise!
							skip = 1;
							break;
						}
						else
						{
							// Агруссия водителя
							SET_CHAR_RELATIONSHIP_GROUP(ped3, 5);
							SET_CHAR_RELATIONSHIP(ped3, 5, 0);
							SET_SENSE_RANGE(ped3, 2000.0);
							SET_CHAR_WILL_USE_COVER(ped3, 0);
							SET_CHAR_WILL_USE_CARS_IN_COMBAT(ped3, 1);
							TASK_COMBAT(ped3, GetPlayerPed());

							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "PHI1_02", 5000, 1);//~g~The arms dealer dropped his load. Smash the crate and pick up the weapon.
							PLAY_AUDIO_EVENT( "FRONTEND_OTHER_RACE_321" );
							GET_GROUND_Z_FOR_3D_COORD(PedX3, PedY3, PedZ3, &PedZ3);

							// даём
							CREATE_PICKUP_ROTATE(w_e2_m249, 3, 5, PedX3, PedY3, PedZ3+0.2, 90.0, 0.0, 0.0, &sweap_3);
							ADD_BLIP_FOR_PICKUP(sweap_3, &weap3_ico);
							CHANGE_BLIP_SPRITE(weap3_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(weap3_ico, 5);
							CHANGE_BLIP_SCALE(weap3_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(weap3_ico, "MO_TARGET");
							add_gun3 = 1;
						}
					}
					if (((HealGB_4 < 10) && ( add_gun4 == 0)) || ((CarHP4 < 750) && (add_gun4 == 0)))
					{
						if (IS_CAR_DEAD(car4))
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_10", 5000, 1);//~r~You idiot! You have destroyed the merchandise!
							skip = 1;
							break;
						}
						else
						{
							// Агруссия водителя
							SET_CHAR_RELATIONSHIP_GROUP(ped4, 5);
							SET_CHAR_RELATIONSHIP(ped4, 5, 0);
							SET_SENSE_RANGE(ped4, 2000.0);
							SET_CHAR_WILL_USE_COVER(ped4, 0);
							SET_CHAR_WILL_USE_CARS_IN_COMBAT(ped4, 1);
							TASK_COMBAT(ped4, GetPlayerPed());

							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "PHI1_02", 5000, 1);//~g~The arms dealer dropped his load. Smash the crate and pick up the weapon.
							PLAY_AUDIO_EVENT( "FRONTEND_OTHER_RACE_321" );
							GET_GROUND_Z_FOR_3D_COORD(PedX4, PedY4, PedZ4, &PedZ4);

							// даём
							CREATE_PICKUP_ROTATE(w_uzi, 3, 5, PedX4, PedY4, PedZ4+0.2, 90.0, 0.0, 0.0, &sweap_4);
							ADD_BLIP_FOR_PICKUP(sweap_4, &weap4_ico);
							CHANGE_BLIP_SPRITE(weap4_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(weap4_ico, 5);
							CHANGE_BLIP_SCALE(weap4_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(weap4_ico, "MO_TARGET");
							add_gun4 = 1;
						}
					}

					if ((IS_CHAR_IN_AREA_3D( GetPlayerPed(), PedX1+20, PedY1+20, PedZ1-20, PedX1-20, PedY1-20, PedZ1+30, 0 )) && (touch1 == 0))
					{
						if (!IS_CAR_DEAD(car1))
						{
							// агрессия
							SET_CHAR_RELATIONSHIP_GROUP(ped5, 5);
							SET_CHAR_RELATIONSHIP_GROUP(ped9, 5);
							SET_CHAR_RELATIONSHIP(ped5, 5, 0);
							SET_CHAR_RELATIONSHIP(ped9, 5, 0);
							SET_CHAR_WILL_USE_COVER(ped5, 0);
							SET_CHAR_WILL_USE_COVER(ped9, 0);
							TASK_COMBAT(ped5, GetPlayerPed());
							TASK_COMBAT(ped9, GetPlayerPed());

							TASK_CAR_DRIVE_WANDER(ped1, car1, 35.0, 2);
							touch1 = 1;
							press_moped = 0;
						}
					}
					if ((IS_CHAR_IN_AREA_3D( GetPlayerPed(), PedX2+20, PedY2+20, PedZ2-20, PedX2-20, PedY2-20, PedZ2+30, 0 )) && (touch2 == 0))
					{
						if (!IS_CAR_DEAD(car2))
						{
							// агрессия
							SET_CHAR_RELATIONSHIP_GROUP(ped6, 5);
							SET_CHAR_RELATIONSHIP_GROUP(ped10, 5);
							SET_CHAR_RELATIONSHIP(ped6, 5, 0);
							SET_CHAR_RELATIONSHIP(ped10, 5, 0);
							SET_CHAR_WILL_USE_COVER(ped6, 0);
							SET_CHAR_WILL_USE_COVER(ped10, 0);
							TASK_COMBAT(ped6, GetPlayerPed());
							TASK_COMBAT(ped10, GetPlayerPed());

							TASK_CAR_DRIVE_WANDER(ped2, car2, 35.0, 2);
							touch2 = 1;
							press_moped = 0;
						}
					}
					if ((IS_CHAR_IN_AREA_3D( GetPlayerPed(), PedX3+20, PedY3+20, PedZ3-20, PedX3-20, PedY3-20, PedZ3+30, 0 )) && (touch3 == 0))
					{
						if (!IS_CAR_DEAD(car3))
						{
							// агрессия
							SET_CHAR_RELATIONSHIP_GROUP(ped7, 5);
							SET_CHAR_RELATIONSHIP_GROUP(ped11, 5);
							SET_CHAR_RELATIONSHIP(ped7, 5, 0);
							SET_CHAR_RELATIONSHIP(ped11, 5, 0);
							SET_CHAR_WILL_USE_COVER(ped7, 0);
							SET_CHAR_WILL_USE_COVER(ped11, 0);
							TASK_COMBAT(ped7, GetPlayerPed());
							TASK_COMBAT(ped11, GetPlayerPed());

							TASK_CAR_DRIVE_WANDER(ped3, car3, 35.0, 2);
							touch3 = 1;
						press_moped = 0;
						}
					}
					if ((IS_CHAR_IN_AREA_3D( GetPlayerPed(), PedX4+20, PedY4+20, PedZ4-20, PedX4-20, PedY4-20, PedZ4+30, 0 )) && (touch4 == 0))
					{
						if (!IS_CAR_DEAD(car4))
						{
							// агрессия
							SET_CHAR_RELATIONSHIP_GROUP(ped8, 5);
							SET_CHAR_RELATIONSHIP_GROUP(ped12, 5);
							SET_CHAR_RELATIONSHIP(ped8, 5, 0);
							SET_CHAR_RELATIONSHIP(ped12, 5, 0);
							SET_CHAR_WILL_USE_COVER(ped8, 0);
							SET_CHAR_WILL_USE_COVER(ped12, 0);
							TASK_COMBAT(ped8, GetPlayerPed());
							TASK_COMBAT(ped12, GetPlayerPed());

							TASK_CAR_DRIVE_WANDER(ped4, car4, 35.0, 2);
							touch4 = 1;
							press_moped = 0;
						}
					}

					// создание наах
					if (press_moped == 0)
					{
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						GENERATE_RANDOM_FLOAT_IN_RANGE(-20.0, 20.0, &PlayX);
						GENERATE_RANDOM_FLOAT_IN_RANGE(-20.0, -95.0, &PlayY);
						GET_OFFSET_FROM_CHAR_IN_WORLD_COORDS(GetPlayerPed(), PlayX, PlayY, 0.0, &PlayX, &PlayY, &PlayZ);
						GET_CLOSEST_CAR_NODE_WITH_HEADING(PlayX, PlayY, PlayZ, &PlayX, &PlayY, &PlayZ, &PedR1);	

						if ((IS_CHAR_DEAD(ped13)) || (create_car5 == 0))
						{
							MARK_CHAR_AS_NO_LONGER_NEEDED(&ped13);
							MARK_CAR_AS_NO_LONGER_NEEDED(&car5);
							CREATE_CAR(CarM3, PlayX, PlayY, PlayZ, &car5, TRUE);
							SET_CAR_HEADING(car5, PedR1-180);
							CREATE_CHAR_INSIDE_CAR(car5, 1, PedM1, &ped13);
							
							UpdateWeaponOfPed(ped13, WEAPON_PISTOL);
							SET_CURRENT_CHAR_WEAPON(ped13, WEAPON_PISTOL, TRUE);

							SET_CHAR_RELATIONSHIP_GROUP(ped13, 5);
							SET_CHAR_RELATIONSHIP(ped13, 5, 0);
							SET_SENSE_RANGE(ped13, 100.0);
							TASK_COMBAT(ped13, GetPlayerPed());
							create_car5 = 1;
						}
						if ((IS_CHAR_DEAD(ped14)) || (create_car6 == 0))
						{
							MARK_CHAR_AS_NO_LONGER_NEEDED(&ped14);
							MARK_CAR_AS_NO_LONGER_NEEDED(&car6);
							CREATE_CAR(CarM3, PlayX-2, PlayY, PlayZ, &car6, TRUE);
							SET_CAR_HEADING(car6, PedR1-180);
							CREATE_CHAR_INSIDE_CAR(car6, 1, PedM2, &ped14);

							UpdateWeaponOfPed(ped14, WEAPON_MICRO_UZI);
							SET_CURRENT_CHAR_WEAPON(ped14, WEAPON_MICRO_UZI, TRUE);

							SET_CHAR_RELATIONSHIP_GROUP(ped14, 5);
							SET_CHAR_RELATIONSHIP(ped14, 5, 0);
							SET_SENSE_RANGE(ped14, 100.0);
							TASK_COMBAT(ped14, GetPlayerPed());
							create_car6 = 1;
						}
						if ((IS_CHAR_DEAD(ped15)) || (create_car7 == 0))
						{
							MARK_CHAR_AS_NO_LONGER_NEEDED(&ped15);
							MARK_CAR_AS_NO_LONGER_NEEDED(&car7);
							CREATE_CAR(CarM3, PlayX, PlayY+2, PlayZ, &car7, TRUE);
							SET_CAR_HEADING(car7, PedR1-180);
							CREATE_CHAR_INSIDE_CAR(car7, 1, PedM1, &ped15);

							UpdateWeaponOfPed(ped15, WEAPON_PISTOL);
							SET_CURRENT_CHAR_WEAPON(ped15, WEAPON_PISTOL, TRUE);

							SET_CHAR_RELATIONSHIP_GROUP(ped15, 5);
							SET_CHAR_RELATIONSHIP(ped15, 5, 0);
							SET_SENSE_RANGE(ped15, 100.0);
							TASK_COMBAT(ped15, GetPlayerPed());
							create_car7 = 1;
						}
						if ((IS_CHAR_DEAD(ped16)) || (create_car8 == 0))
						{
							MARK_CHAR_AS_NO_LONGER_NEEDED(&ped16);
							MARK_CAR_AS_NO_LONGER_NEEDED(&car8);
							CREATE_CAR(CarM3, PlayX, PlayY-2, PlayZ, &car8, TRUE);
							SET_CAR_HEADING(car8, PedR1-180);
							CREATE_CHAR_INSIDE_CAR(car8, 1, PedM1, &ped16);

							UpdateWeaponOfPed(ped16, WEAPON_DEAGLE);
							SET_CURRENT_CHAR_WEAPON(ped16, WEAPON_DEAGLE, TRUE);

							SET_CHAR_RELATIONSHIP_GROUP(ped16, 5);
							SET_CHAR_RELATIONSHIP(ped16, 5, 0);
							SET_SENSE_RANGE(ped16, 100.0);
							TASK_COMBAT(ped16, GetPlayerPed());
							create_car8 = 1;
						}
						bonus1 = 0;
						bonus2 = 0;
						bonus3 = 0;
						bonus4 = 0;
						press_moped = 1;
						res_moped = 1;
					}

					// респавн если игрок далеко либо педы мертвы
					GET_CHAR_COORDINATES(ped13, &PedX1, &PedY1, &PedZ1);
					if ((!IS_CHAR_IN_AREA_3D( GetPlayerPed(), PedX1+200, PedY1+200, PedZ1-20, PedX1-200, PedY1-200, PedZ1+100, 0 )) && (res_moped == 1))
					{
						press_moped = 0;
						create_car5 = 0;
						create_car6 = 0;
						create_car7 = 0;
						create_car8 = 0;
						res_moped = 0;
						touch1 = 0;
						touch2 = 0;
						touch3 = 0;
						touch4 = 0;
					}
					if ((IS_CHAR_DEAD(ped13)) && (IS_CHAR_DEAD(ped14)) && (IS_CHAR_DEAD(ped15)) && (IS_CHAR_DEAD(ped16)))
					{
						press_moped = 0;
					}

					// бонус
					if ((IS_CHAR_DEAD(ped13)) && (bonus1 == 0))
					{
						bonus ();
						bonus1 = 1;
					}
					if ((IS_CHAR_DEAD(ped14)) && (bonus2 == 0))
					{
						bonus ();
						bonus2 = 1;
					}
					if ((IS_CHAR_DEAD(ped15)) && (bonus3 == 0))
					{
						bonus ();
						bonus3 = 1;
					}
					if ((IS_CHAR_DEAD(ped16)) && (bonus4 == 0))
					{
						bonus ();
						bonus4 = 1;
					}
					
					// убираем с оружия
					if ((HAS_PICKUP_BEEN_COLLECTED( sweap_1 )) && (add_gun1 == 1))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "PHI1_04", 5000, 1);//~g~Now go and finish off the remaining arms dealers.
						REMOVE_BLIP(weap1_ico);
						add_gun1 = 2;
					}
					if ((HAS_PICKUP_BEEN_COLLECTED( sweap_2 )) && (add_gun2 == 1))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "PHI1_04", 5000, 1);//~g~Now go and finish off the remaining arms dealers.
						REMOVE_BLIP(weap2_ico);
						add_gun2 = 2;
					}
					if ((HAS_PICKUP_BEEN_COLLECTED( sweap_3 )) && (add_gun3 == 1))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "PHI1_04", 5000, 1);//~g~Now go and finish off the remaining arms dealers.
						REMOVE_BLIP(weap3_ico);
						add_gun3 = 2;
					}
					if ((HAS_PICKUP_BEEN_COLLECTED( sweap_4 )) && (add_gun4 == 1))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "PHI1_04", 5000, 1);//~g~Now go and finish off the remaining arms dealers.
						REMOVE_BLIP(weap4_ico);
						add_gun4 = 2;
					}

					// убираем с
					if ((IS_CAR_DEAD(car1)) && (del_blip1 == 0))
					{
						DETACH_OBJECT(gunbox1, 1);
						SET_OBJECT_COORDINATES(gunbox1, 10.0, 10.0, -55.0);
						SET_OBJECT_DYNAMIC(gunbox1, 0);
						REMOVE_BLIP(car1_ico);
						del_blip1 = 1;
					}
					if ((IS_CAR_DEAD(car2)) && (del_blip2 == 0))
					{
						DETACH_OBJECT(gunbox2, 1);
						SET_OBJECT_COORDINATES(gunbox2, 10.0, 10.0, -55.0);
						SET_OBJECT_DYNAMIC(gunbox2, 0);
						REMOVE_BLIP(car2_ico);
						del_blip2 = 1;
					}
					if ((IS_CAR_DEAD(car3)) && (del_blip3 == 0))
					{
						DETACH_OBJECT(gunbox3, 1);
						SET_OBJECT_COORDINATES(gunbox3, 10.0, 10.0, -55.0);
						SET_OBJECT_DYNAMIC(gunbox3, 0);
						REMOVE_BLIP(car3_ico);
						del_blip3 = 1;
					}
					if ((IS_CAR_DEAD(car4)) && (del_blip4 == 0))
					{
						DETACH_OBJECT(gunbox4, 1);
						SET_OBJECT_COORDINATES(gunbox4, 10.0, 10.0, -55.0);
						SET_OBJECT_DYNAMIC(gunbox4, 0);
						REMOVE_BLIP(car4_ico);
						del_blip4 = 1;
					}

					// провал и выполнение миссии
					if ((HAS_DEATHARREST_EXECUTED()))
					{
						skip = 1;
						break;
					}
					else if ((add_gun1 == 2) && (add_gun2 == 2) && (add_gun3 == 2) && (add_gun4 == 2))
					{
						if ((IS_CAR_DEAD(car1)) && (IS_CAR_DEAD(car2)) && (IS_CAR_DEAD(car3)) && (IS_CAR_DEAD(car4))) 
						{
							skip = 2;
							break;
						}
					}
				}
				// зачещаем скрипт
				WAIT(0);
				SET_MAX_WANTED_LEVEL(6);
				REMOVE_BLIP(car1_ico);
				REMOVE_BLIP(car2_ico);
				REMOVE_BLIP(car3_ico);
				REMOVE_BLIP(car4_ico);
				REMOVE_BLIP(weap1_ico);
				REMOVE_BLIP(weap2_ico);
				REMOVE_BLIP(weap3_ico);
				REMOVE_BLIP(weap4_ico);

				REMOVE_PICKUP(sweap_1);// выгружаем биту
				REMOVE_PICKUP(sweap_2);// выгружаем биту
				REMOVE_PICKUP(sweap_3);// выгружаем биту
				REMOVE_PICKUP(sweap_4);// выгружаем биту
				REMOVE_PICKUP(sweap_5);// выгружаем биту
				REMOVE_PICKUP(sweap_6);// выгружаем биту

				// выгружаем из памяти
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM1);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM2);
				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM1);
				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM2);
				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM3);
				MARK_MODEL_AS_NO_LONGER_NEEDED(gunboxM);

				DELETE_OBJECT(&gunbox1);
				DELETE_OBJECT(&gunbox2);
				DELETE_OBJECT(&gunbox3);
				DELETE_OBJECT(&gunbox4);
				MARK_OBJECT_AS_NO_LONGER_NEEDED(&gunbox1);
				MARK_OBJECT_AS_NO_LONGER_NEEDED(&gunbox2);
				MARK_OBJECT_AS_NO_LONGER_NEEDED(&gunbox3);
				MARK_OBJECT_AS_NO_LONGER_NEEDED(&gunbox4);

				// выгружаем из памяти
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped1);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped2);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped3);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped4);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped5);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped6);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped7);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped8);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped9);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped10);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped11);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped12);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped13);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped14);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped15);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped16);

				MARK_CAR_AS_NO_LONGER_NEEDED(&car1);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car2);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car3);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car4);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car5);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car6);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car7);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car8);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car9);

				if (skip == 1)
				{
					SETTIMERA(0);
					while (true)
					{
						SET_TEXT_COLOUR(255, 159, 255, 255);
						SET_TEXT_SCALE(0.5, 0.6);
						SET_TEXT_EDGE(1, 0, 0, 0, 255);
						SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
						SET_TEXT_CENTRE(1);
						DISPLAY_TEXT(0.5, 0.45, "MISSION_FAILED");

						WAIT( 0 );
						if ( TIMERA() > 3000 )
						{
							break;
						}
					}
				}
				else if (skip == 2)
				{
					SETTIMERA(0);
					TRIGGER_MISSION_COMPLETE_AUDIO(1);//произрываем музыку параметр "(1)" воспроизводит звук из "...\EFLC\pc\audio\Sfx\gps.rpf\GPS\MISSION_COMPLETE_1" (цыфра "6" = "SMC6" в том-же архиве)
					while (true)
					{
						SET_TEXT_COLOUR(255, 159, 255, 255);
						SET_TEXT_SCALE(0.5, 0.7);
						SET_TEXT_EDGE(1, 0, 0, 0, 255);
						SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
						SET_TEXT_CENTRE(1);
						DISPLAY_TEXT(0.5, 0.45, "MISSION_PASSED");

						SET_TEXT_COLOUR(255, 159, 255, 255);
						SET_TEXT_SCALE(0.5, 0.7);
						SET_TEXT_EDGE(1, 0, 0, 0, 255);
						SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
						SET_TEXT_CENTRE(1);
						DISPLAY_TEXT_WITH_NUMBER(0.5, 0.5, "CASH", 2000);// +5000$
						
						WAIT( 0 );
						if ( TIMERA() > 4000 )
						{
							break;
						}
					}
					ADD_SCORE( GetPlayerIndex(), +2000 );
					INCREMENT_FLOAT_STAT(STAT_MADE_FROM_MISSIONS, 2000);
					INCREMENT_INT_STAT(STAT_MISSIONS_PASSED, 1);
					REGISTER_MISSION_PASSED("PHIL_1");
					G_PHIL = 2;
					autosave = 1;
				}

				blip_on = 0;
				G_ONMISSION = 0;
			}
		}

//============================== Boomshine Saigon ======================================
		else if ((G_ONMISSION == 0) && (G_PHIL == 3))
		{
			if (blip_on == 0)
			{
				ADD_BLIP_FOR_COORD(-668.375, 876.086, 5.22, &phil_ico);
				CHANGE_BLIP_SPRITE(phil_ico, BLIP_PACKIE);
				CHANGE_BLIP_SCALE(phil_ico, 1.1);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(phil_ico, "LG_08");//иконка на радаре называние в истории карты "Боярский"
				blip_on = 1;
			}
			DRAW_CHECKPOINT( -668.375, 876.086, 5.22, 1.5, 160, 116, 209);
			GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
			GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -668.375, 876.086, 5.22, &heading);
			if (( heading < 1.5) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
			{
				G_ONMISSION = 1;
				REMOVE_BLIP(phil_ico);
				blip_on = 0;

				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );
				DO_SCREEN_FADE_OUT( 1000 );
				while(true)
				{
					WAIT(0);
					if (IS_SCREEN_FADED_OUT())
					{
						break;
					}
				}
				
				Ped ped1;
				Car car1;
				Cam camera;
				Texture fon;

				uint CarM1 = MODEL_PATRIOT;
				uint PedM1 = MODEL_IG_BRUCIE;// Фил
				uint hour, minute;

				REQUEST_MODEL(CarM1);
				while (!HAS_MODEL_LOADED(CarM1)) WAIT(0);

				REQUEST_MODEL(PedM1);// Фил
				while (!HAS_MODEL_LOADED(PedM1));

				CLEAR_AREA(-631.575, 854.196, 5.86617, 55.0, 1);
				CREATE_CAR(CarM1, -631.575, 854.196, 5.86617, &car1, TRUE);
				SET_CAR_HEADING(car1, -115.0);

				CREATE_CHAR (26, PedM1, 41.17, -821.214, 2.606, &ped1, TRUE);// Фил
				SET_CHAR_COMPONENT_VARIATION(ped1, 1, 2, 0);
				WARP_CHAR_INTO_CAR(GetPlayerPed(), car1);

				ATTACH_PED_TO_CAR( ped1, car1, 0, 0.0, -0.73, 1.2, 90.0, 0, 1, 1 );
				FREEZE_CHAR_POSITION(ped1, 1);
				SET_CHAR_COLLISION(ped1, 0);
				SET_CHAR_BLEEDING(ped1, 1);

				//им текстуры
				textur = LOAD_TXD( "sunshine_race" );
				fon = GET_TEXTURE( textur, "fon_hud" );

				FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
				RELEASE_WEATHER();
				FORWARD_TO_TIME_OF_DAY(18, 20);

				//грузим анимацию
				REQUEST_ANIMS( "amb@drunk" );
				while (!HAVE_ANIMS_LOADED( "amb@drunk" )) WAIT(0);

				FORCE_WEATHER_NOW(WEATHER_SUNNY);
				RELEASE_WEATHER();

				//------------ катсцена ----------------
				LOAD_ADDITIONAL_TEXT( "PHIL_2", 6 );
				START_CUTSCENE_NOW("phil_2");
				while (!HAS_CUTSCENE_LOADED())
				{
					WAIT(0);
				}

				DO_SCREEN_FADE_IN(0);
				while (!HAS_CUTSCENE_FINISHED())
				{
					WAIT(0);
				}

				if ((IS_SCREEN_FADING_OUT()) || (IS_SCREEN_FADED_OUT()))
				{
					DO_SCREEN_FADE_IN(0);
				}

				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

				GET_ROOT_CAM( &camera );
				SET_DRUNK_CAM( camera, 0.50000000, 500000 );

				uint randint;
				HealGB_1 = 1;
				touch1 = 0;
				ragdool = 0;
				bonus1 = 0;
				cop_on = 0;
				carHUD_x = 0.922156;
				carHUD_w = 0.0739583;
				Health = 500;
				point = 1;
				start = 0;
				speech = 1;
				audio_on = 0;

				ADD_BLIP_FOR_COORD(-438.495, 63.1979, 4.9, &phil_ico);
				CHANGE_BLIP_SPRITE(phil_ico, BLIP_OBJECTIVE);
				CHANGE_BLIP_COLOUR(phil_ico, 5);
				CHANGE_BLIP_SCALE(phil_ico, 0.6);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(phil_ico, "NE_POINT");

				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped1, "wastedc", "amb@drunk", 8.0, 1, 0, 0, 0, -1 );

				PRINT_STRING_IN_STRING("string", "PHI2_01", 5000, 1);//~g~Quick, get Phil to the hospital.

				SETTIMERA( 0 );
				SETTIMERB( 0 );
				SETTIMERC( 0 );

				while (TRUE)
				{
					WAIT(0);
					// аудио
					if ( audio_on == 0)
					{
						if (TIMERC() > 7500)
						{
							if (!IS_SCRIPTED_CONVERSATION_ONGOING())
							{
								if (speech == 1)
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_KQ", "PHI2_08", 0, 0);//Watch out! Charlie in the tree line!
									START_SCRIPT_CONVERSATION(1, 1);
									SETTIMERC( 0 );
									speech = 2;
								}
								else if (speech == 2)
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "NIKO");
									ADD_LINE_TO_CONVERSATION(0, "R11_KR", "PHI2_09", 0, 0);//Is it me or are the roads made of jelly?
									START_SCRIPT_CONVERSATION(1, 1);
									SETTIMERC( 0 );
									speech = 3;
								}
								else if (speech == 3)
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_LA", "PHI2_10", 0, 0);//Broken Spoon to Mother Hen, you copy?
									START_SCRIPT_CONVERSATION(1, 1);
									SETTIMERC( 0 );
									speech = 4;
								}
								else if (speech == 4)
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_LC", "PHI2_11", 0, 0);//Spooney Wooney Woo Woo Woooo!
									START_SCRIPT_CONVERSATION(1, 1);
									SETTIMERC( 0 );
									speech = 99;
								}
								else if (speech == 5)
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_LE", "PHI2_12", 0, 0);//He's come for me boy!
									START_SCRIPT_CONVERSATION(1, 1);
									SETTIMERC( 0 );
									speech = 6;
								}
								else if (speech == 6)
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_LG", "PHI2_13", 0, 0);//Black feathered wings beating all around...
									START_SCRIPT_CONVERSATION(1, 1);
									SETTIMERC( 0 );
									speech = 7;
								}
								else if (speech == 7)
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_LH", "PHI2_14", 0, 0);//It's beautiful, man ... it's beautiful ... but so cold ...
									START_SCRIPT_CONVERSATION(1, 1);
									SETTIMERC( 0 );
									speech = 8;
								}
							}
						}
					}
					else
					{
						if (!IS_SCRIPTED_CONVERSATION_ONGOING())
						{
							if (audio_on == 1)
							{
								// есть один хирург
								if (!IS_SCRIPTED_CONVERSATION_ONGOING())
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_KO", "PHI2_06", 0, 0);//There's an ex-army surgeon owes me a few favors and a lawnmower.
									START_SCRIPT_CONVERSATION(1, 1);
									audio_on = 2;
								}
							}
							else if (audio_on == 2)
							{
								// он в Малой Гаване
								if (!IS_SCRIPTED_CONVERSATION_ONGOING())
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_KP", "PHI2_07", 0, 0);//He's got a place down Little Havana - ooo look, a giant fish.
									START_SCRIPT_CONVERSATION(1, 1);
									audio_on = 3;
								}
							}
							else if (audio_on == 3)
							{
								if (!IS_SCRIPTED_CONVERSATION_ONGOING())
								{
									CLEAR_PRINTS();
									PRINT_STRING_IN_STRING("string", "NE_PHI2_H", 5000, 1);//~g~Take Phil to the surgeon in Little Havana.
									SETTIMERC( 0 );
									audio_on = 0;
									speech = 5;
								}
							}
							else if (audio_on == 104)
							{
								// рация копов
								if (!IS_SCRIPTED_CONVERSATION_ONGOING())
								{
									NEW_SCRIPTED_CONVERSATION();
									ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
									ADD_LINE_TO_CONVERSATION(0, "R11_LJ", "PHI2_15", 0, 0);//10-4 we've got a drunk driver.
									START_SCRIPT_CONVERSATION(1, 1);
									SETTIMERC( 0 );
									audio_on = 0;
								}
							}
						}
					}


					GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
					GET_GROUND_Z_FOR_3D_COORD(PlayX, PlayY, PlayZ, &PedR);
					GET_CHAR_SPEED(GetPlayerPed(), &speed);

					//пьяная езда/ходьба
					if (IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed()))
					{
						if (speed > 5)
						{
							if ((HealGB_1 == 1) || (HealGB_1 == 3) || (HealGB_1 == 5))
							{
								if (touch1 < 0.1)
								{
									touch1 += 0.002;
								}
								else
								{
									GENERATE_RANDOM_INT_IN_RANGE(0, 5, &randint);
									HealGB_1 = randint;
								}
							}
							else if ((HealGB_1 == 0) || (HealGB_1 == 2) || (HealGB_1 == 4))
							{
								if (touch1 > -0.1)
								{
									touch1 -= 0.002;
								}
								else
								{
									GENERATE_RANDOM_INT_IN_RANGE(0, 5, &randint);
									HealGB_1 = randint;
								}
							}
							SET_VEHICLE_STEER_BIAS( car1, touch1 );
						}
						if ((ragdool == 1) || (ragdool == 2))
						{
							ragdool = 0;
						}
					}
					else
					{
						if (ragdool == 0)
						{
							SETTIMERA( 0 );
							ragdool = 1;
						}
						if ((TIMERA() > 2500) && (ragdool == 1))
						{
							SWITCH_PED_TO_RAGDOLL( GetPlayerPed(), 0, 95000, 1, 1, 1, 0 );
							CREATE_NM_MESSAGE( 1, 79 );
							SET_NM_MESSAGE_FLOAT( 89, 8.70000000 );
							SET_NM_MESSAGE_FLOAT( 98, 0.60000000 );
							SET_NM_MESSAGE_FLOAT( 81, 8.39999900 );
							SET_NM_MESSAGE_FLOAT( 82, 0.70000000 );
							SET_NM_MESSAGE_INT( 85, 65535 );
							SET_NM_MESSAGE_BOOL( 95, 1 );
							SET_NM_MESSAGE_FLOAT( 101, 0.80000000 );
							SET_NM_MESSAGE_FLOAT( 102, 999.00000000 );
							SET_NM_MESSAGE_FLOAT( 84, 1.40000000 );
							SET_NM_MESSAGE_FLOAT( 83, 1.95000000 );
							SET_NM_MESSAGE_FLOAT( 94, 1.00000000 );
							SET_NM_MESSAGE_FLOAT( 110, 0.0000 );
							SET_NM_MESSAGE_FLOAT( 111, 0.1000 );
							SET_NM_MESSAGE_FLOAT( 112, 0.1000 );
							SET_NM_MESSAGE_FLOAT( 108, 0.0000 );
							SET_NM_MESSAGE_FLOAT( 113, 0.6000 );
							SET_NM_MESSAGE_FLOAT( 109, 0.2000 );
							SET_NM_MESSAGE_FLOAT( 91, 0.1000 );
							SET_NM_MESSAGE_FLOAT( 93, 0.1000 );
							SET_NM_MESSAGE_FLOAT( 106, -0.3000 );
							SEND_NM_MESSAGE( GetPlayerPed() );
							GIVE_PLAYER_RAGDOLL_CONTROL( GetPlayerIndex(), 1 );
							ragdool = 2;
							SETTIMERA( 0 );
						}
					}

					if ((!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (ragdool == 2))
					{
						if ((TIMERA() > 10000) && (bonus1 == 0))
						{
							SWITCH_PED_TO_RAGDOLL( GetPlayerPed(), 0, 95000, 1, 1, 1, 0 );
							GIVE_PLAYER_RAGDOLL_CONTROL( GetPlayerIndex(), 0 );
							bonus1 = 1;
						}
						else if ((PlayZ < PedR+0.5) && (bonus1 == 0))
						{
							bonus1 = 2;
						}
						else if (((TIMERA() > 12000) && (bonus1 == 1)) || (bonus1 == 2))
						{
							DO_SCREEN_FADE_OUT( 1000 );
							while(true)
							{
								WAIT(0);
								if (IS_SCREEN_FADED_OUT())
								{
									break;
								}
							}
							bonus1 = 99;
							SET_DRUNK_CAM( camera, 0.0, 0 );
							GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
							SET_CHAR_COORDINATES(GetPlayerPed(), PlayX, PlayY, PlayZ );
							WAIT(500);
							DO_SCREEN_FADE_IN( 1000 );
							EXPLODE_CHAR_HEAD(ped1);
							GET_TIME_OF_DAY(&hour, &minute);
							FORWARD_TO_TIME_OF_DAY(hour+3, minute+5);
							//break;
						}
					}

					// Агрессия копов
					if ((IS_COP_PED_IN_AREA_3D_NO_SAVE(PlayX+25, PlayY+25, PlayZ-10, PlayX-25, PlayY-25, PlayZ+20)) && (cop_on == 0))
					{
						ALTER_WANTED_LEVEL(GetPlayerIndex(), 2);
						APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
						cop_on = 1;
						audio_on = 104;
					}
					else
					{
						if (cop_on == 1)
						{
							if (!IS_WANTED_LEVEL_GREATER(GetPlayerIndex(), 0)) //проверка розыска.
							{
								cop_on = 0;
							}
						}
					}

					// Phil HUD
					DRAW_SPRITE( fon, 0.8765625, 0.7838, 0.14322917, 0.0296, 0.0, 246, 151, 255, 155 );
					DRAW_SPRITE( 0, 0.915054, 0.7838, 0.059166, 0.014, 0.0, 27, 89, 130, 255 );

					if (Health < 5)
					{
						carH1 = 0;
					}
					else
					{
						carH1 = Health-100;
					}
					carH2 = carHUD_w/500;
					carH3 = carH2*carH1;
					carHUD_y1 = carHUD_w-carH3;
					carHUD_y2 = carHUD_y1/2;
					carHUD_y3 = carHUD_x-carHUD_y2;
					DRAW_SPRITE( 0, carHUD_y3, 0.7838, carH3, 0.014, 0.0, 97, 194, 247, 255 );

					SET_TEXT_COLOUR(95, 195, 247, 255);
					SET_TEXT_SCALE(0.156, 0.267);
					SET_TEXT_DROPSHADOW(1, 26, 90, 128, 255);
					DISPLAY_TEXT(0.78815097, 0.77731852, "PHI2_04"); //PHIL'S HEALTH:

					if (TIMERB() > 350)
					{
						Health -= 1;
						SETTIMERB( 0 );
					}

					// Чекпойнты
					if ( point == 1)
					{
						DRAW_CHECKPOINT( -438.495, 63.1979, 4.9, 2.5, 160, 116, 209);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PedX1, &PedY1, &PedZ1);
						GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -438.495, 63.1979, 4.9, &heading);
						GET_DISTANCE_BETWEEN_COORDS_3D( PedX1, PedY1, PedZ1, -438.495, 63.1979, 4.9, &PedR1);
						if (( heading < 2.5) && (PedR1 < 2.5))
						{
							//Не в больницу...
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R11_KN", "PHI2_05", 0, 0);//Not the hospital, man! Too many cops and Viet Cong!
							START_SCRIPT_CONVERSATION(1, 1);
							audio_on = 1;

							REMOVE_BLIP(phil_ico);
							ADD_BLIP_FOR_COORD(-751.153, -128.764, 5.3, &phil_ico);
							CHANGE_BLIP_SPRITE(phil_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(phil_ico, 5);
							CHANGE_BLIP_SCALE(phil_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(phil_ico, "MO_TARGET");
							point = 2;
						}
					}
					else
					{
						DRAW_CHECKPOINT( -751.153, -128.764, 5.3, 2.5, 160, 116, 209);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PedX1, &PedY1, &PedZ1);
						GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -751.153, -128.764, 5.3, &heading);
						GET_DISTANCE_BETWEEN_COORDS_3D( PedX1, PedY1, PedZ1, -751.153, -128.764, 5.3, &PedR1);
						if (( heading < 2.5) && (PedR1 < 2.5))
						{

							SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );

							DO_SCREEN_FADE_OUT( 500 );
							while(true)
							{
								WAIT(0);
								if (IS_SCREEN_FADED_OUT())
								{
									break;
								}
							}
							SET_DRUNK_CAM( camera, 0.0, 0 );

							DETACH_PED(ped1, 0);
							FREEZE_CHAR_POSITION(ped1, 0);
							SET_CHAR_COLLISION(ped1, 1);
							SET_ANIM_GROUP_FOR_CHAR(ped1, "move_injured_upper");
							
							SET_CHAR_COORDINATES(ped1, -754.906, -130.599, 5.85832);
							SET_CHAR_HEADING(ped1, 90.0);
							SetTime(500);

							DO_SCREEN_FADE_IN( 500 );

							
							CREATE_CAM( 14, &camera );
							POINT_CAM_AT_COORD	( camera, -755.721, -130.771, 5.85832 );
							SET_CAM_POS			( camera, -751.107, -117.519, 9.45726 );
							SET_CAM_ACTIVE( camera, 1 );
							SET_CAM_PROPAGATE( camera, 1 );
							ACTIVATE_SCRIPTED_CAMS(1, 1);
							SET_CAM_FOV( camera, 45.0 );
							SET_WIDESCREEN_BORDERS( 1 );

							TASK_GO_STRAIGHT_TO_COORD(ped1, -764.689, -131.092, 5.9656, 2, -2);
							SetTime(4000);

							DO_SCREEN_FADE_OUT( 500 );
							while(true)
							{
								WAIT(0);
								if (IS_SCREEN_FADED_OUT())
								{
									break;
								}
							}

							POINT_CAM_AT_COORD	( camera, -620.644, 851.899, 17.9063 );
							SET_CAM_POS			( camera, -597.032, 846.256, 18.8137 );
							DO_SCREEN_FADE_IN( 500 );

							SETTIMERA(0);
							while (true)
							{
								SET_TEXT_COLOUR(93, 200, 252, 255);
								SET_TEXT_SCALE(0.5, 0.7);
								SET_TEXT_EDGE(1, 0, 0, 0, 255);
								SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
								SET_TEXT_CENTRE(1);
								DISPLAY_TEXT(0.5, 0.45, "PHI_AS1");//PHILS PLACE ASSET COMPLETED
								WAIT( 0 );
								if ( TIMERA() > 5000 )
								{
									break;
								}
							}

							SET_CHAR_COORDINATES(ped1, 75.676, 73.762, 6.342);
							POINT_CAM_AT_COORD	( camera, -674.954, 876.103, 9.16035 );// куда смотрит камера
							SET_CAM_POS			( camera, -671.766, 873.266, 8.46922 );// расположение

							PRINT_STRING_IN_STRING("string", "PHI_AS2", 5500, 1);//~g~New Weapons available to purchase from Phils Place.
							SetTime(5000);

							DO_SCREEN_FADE_OUT( 500 );
							while(true)
							{
								WAIT(0);
								if (IS_SCREEN_FADED_OUT())
								{
									break;
								}
							}
							

							// убираем
							SET_CAM_BEHIND_PED( GetPlayerPed() );
							ACTIVATE_SCRIPTED_CAMS( 0, 0 );
							END_CAM_COMMANDS( &camera );
							SET_WIDESCREEN_BORDERS( 0 );
							SetTime(500);

							DO_SCREEN_FADE_IN( 500 );
							SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

							skip = 2;
							break;
						}
					}

					if (IS_CHAR_IN_CAR(GetPlayerPed(), car1))
					{
						if (start == 1)
						{
							if ( point == 1)
							{
								REMOVE_BLIP(phil_ico);
								ADD_BLIP_FOR_COORD(-438.495, 63.1979, 4.9, &phil_ico);
								CHANGE_BLIP_SPRITE(phil_ico, BLIP_OBJECTIVE);
								CHANGE_BLIP_COLOUR(phil_ico, 5);
								CHANGE_BLIP_SCALE(phil_ico, 0.6);
								CHANGE_BLIP_NAME_FROM_TEXT_FILE(phil_ico, "NE_POINT");

								CLEAR_PRINTS();
								PRINT_STRING_IN_STRING("string", "PHI2_01", 5000, 1);//~g~Quick, get Phil to the hospital.
								start = 0;
							}
							else
							{
								REMOVE_BLIP(phil_ico);
								ADD_BLIP_FOR_COORD(-751.153, -128.764, 5.3, &phil_ico);
								CHANGE_BLIP_SPRITE(phil_ico, BLIP_OBJECTIVE);
								CHANGE_BLIP_COLOUR(phil_ico, 5);
								CHANGE_BLIP_SCALE(phil_ico, 0.6);
								CHANGE_BLIP_NAME_FROM_TEXT_FILE(phil_ico, "NE_POINT");

								CLEAR_PRINTS();
								PRINT_STRING_IN_STRING("string", "NE_PHI2_H", 5000, 1);//~g~Take Phil to the surgeon in Little Havana.
								start = 0;
							}
						}
					}
					else
					{
						if (start == 0)
						{
							REMOVE_BLIP(phil_ico);
							ADD_BLIP_FOR_CAR(car1, &phil_ico);
							CHANGE_BLIP_SPRITE(phil_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(phil_ico, 19);
							CHANGE_BLIP_SCALE(phil_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(phil_ico, "NE_CAR");

							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "IN_VEH", 5000, 1);//~COL_NET_12~Hey! Get back in the vehicle!
							start = 1;
						}
					}

					// Провал миссии
					if ((HAS_DEATHARREST_EXECUTED()))// игрок мёртв/арестован
					{
						skip = 1;
						break;
					}
					else if ((IS_CHAR_DEAD(ped1)) || (Health < 101))
					{
						EXPLODE_CHAR_HEAD(ped1);
						skip = 1;
						break;
					}
				}

				
				REMOVE_BLIP(phil_ico);
				RELEASE_TEXTURE( fon );
				REMOVE_TXD( textur );
				SET_DRUNK_CAM( camera, 0.0, 0 );
				SET_VEHICLE_STEER_BIAS( car1, 0 );

				DETACH_PED(ped1, 0);
				FREEZE_CHAR_POSITION(ped1, 0);
				SET_CHAR_COLLISION(ped1, 1);

				if (skip == 1)
				{
					WARP_CHAR_INTO_CAR_AS_PASSENGER(ped1, car1, 2);
					SetTime(1000);
					NEW_SCRIPTED_CONVERSATION();
					ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
					ADD_LINE_TO_CONVERSATION(0, "R11_MA", "NEPHI2_D", 0, 0);//Phil... Damn...
					START_SCRIPT_CONVERSATION(1, 1);
					SetSpeech();
					CLEAR_PRINTS();
					PRINT_STRING_IN_STRING("string", "PHI2_03", 5000, 1);//~r~Phil Cassidy is dead!!! Now who's gonna supply arms in Vice City?
				}

				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM1);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM1);

				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped1);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car1);

				if (skip == 1)
				{
					SETTIMERA(0);
					while (true)
					{
						SET_TEXT_COLOUR(255, 159, 255, 255);
						SET_TEXT_SCALE(0.5, 0.6);
						SET_TEXT_EDGE(1, 0, 0, 0, 255);
						SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
						SET_TEXT_CENTRE(1);
						DISPLAY_TEXT(0.5, 0.45, "MISSION_FAILED");

						WAIT( 0 );
						if ( TIMERA() > 3000 )
						{
							break;
						}
					}
				}
				else if (skip == 2)
				{
					SETTIMERA(0);
					TRIGGER_MISSION_COMPLETE_AUDIO(1);//произрываем музыку параметр "(1)" воспроизводит звук из "...\EFLC\pc\audio\Sfx\gps.rpf\GPS\MISSION_COMPLETE_1" (цыфра "6" = "SMC6" в том-же архиве)
					while (true)
					{
						SET_TEXT_COLOUR(255, 159, 255, 255);
						SET_TEXT_SCALE(0.5, 0.7);
						SET_TEXT_EDGE(1, 0, 0, 0, 255);
						SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
						SET_TEXT_CENTRE(1);
						DISPLAY_TEXT(0.5, 0.45, "MISSION_PASSED");

						SET_TEXT_COLOUR(255, 159, 255, 255);
						SET_TEXT_SCALE(0.5, 0.7);
						SET_TEXT_EDGE(1, 0, 0, 0, 255);
						SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
						SET_TEXT_CENTRE(1);
						DISPLAY_TEXT_WITH_NUMBER(0.5, 0.5, "CASH", 4000);// +5000$
						
						WAIT( 0 );
						if ( TIMERA() > 4000 )
						{
							break;
						}
					}
					ADD_SCORE( GetPlayerIndex(), +4000 );
					INCREMENT_FLOAT_STAT(STAT_MADE_FROM_MISSIONS, 4000);
					INCREMENT_INT_STAT(STAT_MISSIONS_PASSED, 1);
					REGISTER_MISSION_PASSED("PHIL_2");
					G_PHIL = 4;
					autosave = 1;
				}
				
				G_ONMISSION = 0;
			}
		}
		else if ((G_ONMISSION == 0) && (G_PHIL == 5))
		{
			if (blip_on == 0)
			{
				ADD_BLIP_FOR_COORD(-668.375, 876.086, 5.22, &phil_ico);
				CHANGE_BLIP_SPRITE(phil_ico, BLIP_PACKIE);
				CHANGE_BLIP_SCALE(phil_ico, 1.1);
				SET_BLIP_AS_SHORT_RANGE(phil_ico, 1);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(phil_ico, "LG_08");//иконка на радаре называние в истории карты "Боярский"
				blip_on = 1;
			}
		}
		else
		{
			if (blip_on == 1)
			{
				REMOVE_BLIP(phil_ico);
				blip_on = 0;
			}
		}
//============================== Phil Shop ======================================
		if (G_PHIL == 5)
		{
			DRAW_CHECKPOINT( -672.895, 875.737, 5.58947, 0.8, 160, 116, 209);
			GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
			GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -672.895, 875.737, 5.58947, &heading);
			if (( heading < 1.5) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
			{
				Cam camera;
				Cam camera2;
				Cam camera3;
				cam_on = 0;
				set_cam = 1;
				help = 0;
				int money_ped;

				CLEAR_HELP();
				PRINT_HELP_FOREVER("NE_NAVIG"); // навигация
				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );

				CREATE_CAM( 14, &camera );
				POINT_CAM_AT_COORD	( camera, -674.781, 874.688, 9.10574 );
				SET_CAM_POS			( camera, -673.585, 874.688, 9.10574 );
				SET_CAM_ACTIVE( camera, 1 );
				SET_CAM_PROPAGATE( camera, 0 );
				ACTIVATE_SCRIPTED_CAMS(1, 1);

				GET_GAME_CAM(&camera3);
				CREATE_CAM( 3, &camera2 );
				SET_CAM_INTERP_STYLE_DETAILED( camera2, 1, 1, 1, 1 );
				SET_CAM_INTERP_STYLE_CORE( camera2, camera3, camera, 500, 0 );
				SET_CAM_ACTIVE( camera2, 1 );
				SET_CAM_PROPAGATE( camera2, 1 );
				ACTIVATE_SCRIPTED_CAMS(1, 1);

				while (true)
				{
					WAIT(0);
					if (help == 1)
					{
						if (TIMERB() > 1000)
						{
							CLEAR_HELP();
							PRINT_HELP_FOREVER("NE_NAVIG"); // навигация
							help = 0;
						}
					}
					if ((IS_BUTTON_PRESSED( 0, 11 )) || (IS_GAME_KEYBOARD_NAV_RIGHT_PRESSED( 1 ))) //нажато вправо
					{
						SETTIMERA(0);
						while (true)
						{
							WAIT(0);
							if ((IS_BUTTON_PRESSED( 0, 11 )) || (IS_GAME_KEYBOARD_NAV_RIGHT_PRESSED( 1 ))) //нажато вправо
							{
								if (TIMERA() > 600)
								{
									break;
								}
							}
							else if ((!IS_BUTTON_PRESSED( 0, 11 )) || (!IS_GAME_KEYBOARD_NAV_RIGHT_PRESSED( 1 ))) //нажато вправо
							{
								break;
							}
						}
						if (set_cam < 5)
						{
							cam_on = 1;
							set_cam += 1;
						}
					}
					else if ((IS_BUTTON_PRESSED( 0, 10 )) || (IS_GAME_KEYBOARD_NAV_LEFT_PRESSED( 1 ))) //нажато влево
					{
						SETTIMERA(0);
						while (true)
						{
							WAIT(0);
							if ((IS_BUTTON_PRESSED( 0, 10 )) || (IS_GAME_KEYBOARD_NAV_LEFT_PRESSED( 1 ))) //нажато влево
							{
								if (TIMERA() > 600)
								{
									break;
								}
							}
							else if ((!IS_BUTTON_PRESSED( 0, 10 )) || (!IS_GAME_KEYBOARD_NAV_LEFT_PRESSED( 1 ))) //нажато влево
							{
								break;
							}
						}
						if (set_cam >= 2)
						{
							cam_on = 1;
							set_cam -= 1;
						}
					}
					else if ((IS_BUTTON_PRESSED( 0, 17 )) || ((IS_CONTROL_PRESSED( 2, 182 )) && (! IS_USING_CONTROLLER()))) // BACKSPACE
					{
						break;
					}
					else if ((IS_BUTTON_PRESSED( 0, 16 )) || ((IS_CONTROL_PRESSED( 2, 181 )) && (! IS_USING_CONTROLLER()))) //клавиатура ENTER
					{
						STORE_SCORE(GetPlayerIndex(), &money_ped);// записываем средства в переменную
						if (set_cam == 1)
						{
							if (money_ped >= 8000)
							{
								ADD_SCORE( GetPlayerIndex(), -8000 );
								GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_RLAUNCHER, 8, FALSE);	
								SET_CURRENT_CHAR_WEAPON(GetPlayerPed(), WEAPON_RLAUNCHER, TRUE);
							}
							else
							{
								CLEAR_HELP();
								PRINT_HELP("NE_NOTMONEY"); // пишем недостаточно средств
								help = 1;
							}
						}
						else if (set_cam == 2)
						{
							if (money_ped >= 8000)
							{
								ADD_SCORE( GetPlayerIndex(), -8000 );
								GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_EPISODIC_14, 100, FALSE);	
								SET_CURRENT_CHAR_WEAPON(GetPlayerPed(), WEAPON_EPISODIC_14, TRUE);
							}
							else
							{
								CLEAR_HELP();
								PRINT_HELP("NE_NOTMONEY"); // пишем недостаточно средств
								help = 1;
							}
						}
						else if (set_cam == 3)
						{
							if (money_ped >= 4000)
							{
								ADD_SCORE( GetPlayerIndex(), -4000 );
								GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_BARETTA, 20, FALSE);		
								SET_CURRENT_CHAR_WEAPON(GetPlayerPed(), WEAPON_BARETTA, TRUE);
							}
							else
							{
								CLEAR_HELP();
								PRINT_HELP("NE_NOTMONEY"); // пишем недостаточно средств
								help = 1;
							}
						}
						else if (set_cam == 4)
						{
							if (money_ped >= 600)
							{
								ADD_SCORE( GetPlayerIndex(), -600 );
								GIVE_WEAPON_TO_CHAR(GetPlayerPed(), WEAPON_GRENADE, 5, FALSE);	
								SET_CURRENT_CHAR_WEAPON(GetPlayerPed(), WEAPON_GRENADE, TRUE);
							}
							else
							{
								CLEAR_HELP();
								PRINT_HELP("NE_NOTMONEY"); // пишем недостаточно средств
								help = 1;
							}
						}
						else if (set_cam == 5)
						{
							if (money_ped >= 200)
							{
								ADD_SCORE( GetPlayerIndex(), -200 );
								ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
							}
							else
							{
								CLEAR_HELP();
								PRINT_HELP("NE_NOTMONEY"); // пишем недостаточно средств
								help = 1;
							}
						}
						while (true)
						{
							WAIT(0);
							if ((!IS_CONTROL_PRESSED( 2, 181 )) && (!IS_USING_CONTROLLER())) //клавиатура ENTER
							{
								if (!IS_BUTTON_PRESSED( 0, 16 ))
								{
									SETTIMERB(0);
									break;
								}
							}
							else if ((!IS_CONTROL_PRESSED( 2, 181 )) && (IS_USING_CONTROLLER())) //клавиатура ENTER
							{
								if (!IS_BUTTON_PRESSED( 0, 16 ))
								{
									SETTIMERB(0);
									break;
								}
							}
						}
					}
					if (cam_on == 1)
					{
						if (set_cam == 1)
						{
							POINT_CAM_AT_COORD	( camera, -674.781, 874.688, 9.10574 );
							SET_CAM_POS			( camera, -673.585, 874.688, 9.10574 );
						}
						else if (set_cam == 2)
						{
							POINT_CAM_AT_COORD	( camera, -674.781, 876.309, 9.10574 );
							SET_CAM_POS			( camera, -673.585, 876.309, 9.10574 );
						}
						else if (set_cam == 3)
						{
							POINT_CAM_AT_COORD	( camera, -674.781, 877.626, 9.10574 );
							SET_CAM_POS			( camera, -673.585, 877.626, 9.10574 );
						}
						else if (set_cam == 4)
						{
							POINT_CAM_AT_COORD	( camera, -674.781, 878.801, 9.10574 );
							SET_CAM_POS			( camera, -673.585, 878.801, 9.10574 );
						}
						else if (set_cam == 5)
						{
							POINT_CAM_AT_COORD	( camera, -674.781, 879.782, 9.10574 );
							SET_CAM_POS			( camera, -673.585, 879.782, 9.10574 );
						}
						SET_CAM_INTERP_STYLE_CORE( camera2, camera2, camera, 500, 0 );
						cam_on = 0;
					}
				}
				ACTIVATE_SCRIPTED_CAMS( 0, 0 );
				DESTROY_CAM( camera );
				DESTROY_CAM( camera2 );
				CLEAR_HELP();
				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

				while (TRUE)
				{
					WAIT(0);
					DRAW_CHECKPOINT( -672.895, 875.737, 5.58947, 0.8, 160, 116, 209);
					GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
					GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -672.895, 875.737, 5.58947, &heading);
					if ( heading > 2.5)
					{
						break;
					}
				}
			}
		}
	}
}
void main(void)
{
	phil();
	while (TRUE)
	{
		WAIT(0);
	}
	return;
}
