#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"

float PlayX, PlayY, PlayZ, PedX, PedY, PedZ, PedR, PlayR, blip_on, time_m, time_s, sound, play, text1, text2, stalking, stalkerR, in_car, skip, textur, in_cord, volume, speed, shkala, shkalaON, autosave;
float shkalaH1, shkalaH2, shkalaH3, shkalaHUD_y1, shkalaHUD_y2, shkalaHUD_y3, HUD_w, HUD_x, play_aud, play_Speech, super_ped;			

void rockers(void)
{
	blip_on = 0;
	autosave = 0;
	Blip rock_ico;
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
//============================== Love Juice ======================================
		if ((G_ONMISSION == 0) && (G_ROCK == 1))
		{
			if (blip_on == 0)
			{
				ADD_BLIP_FOR_COORD(-442.551, 1692.462, 5.088, &rock_ico);
				CHANGE_BLIP_SPRITE(rock_ico, BLIP_FIRE_STATION);
				CHANGE_BLIP_SCALE(rock_ico, 1.1);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "LG_19");
				blip_on = 1;
			}
			DRAW_CHECKPOINT( -442.551, 1692.462, 5.088, 1.5, 160, 116, 209);
			GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
			GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -442.551, 1692.462, 5.088, &PlayR);
			if (( PlayR < 1.5) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
			{
				G_ONMISSION = 1;
				REMOVE_BLIP(rock_ico);
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
				SET_CHAR_COORDINATES(GetPlayerPed(), -440.859, 1692.332, 5.34);
				SET_CHAR_HEADING(GetPlayerPed(), -90.0);
				
				Car car1, car2;
				Ped ped1, ped2;
				Cam camera;
				Pickup bag;
				Texture fon, timer;
				int money_plaer;

				time_m = 2;
				time_s = 0;
				sound = 0;
				play = 0;
				text1 = 0;
				text2 = 0;
				stalking = 0;
				in_car = 0;
				skip = 0;

				textur = LOAD_TXD( "sunshine_race" );
				fon = GET_TEXTURE( textur, "fon_hud" );
				timer = GET_TEXTURE( textur, "timer_hud" );

				uint CarM1 = MODEL_PCJ;// Диллер-байк
				uint PedM1 = MODEL_IG_ANNA;
				uint PedM2 = MODEL_M_M_ENFORCER;// Диллер

				REQUEST_MODEL(CarM1);
				while (!HAS_MODEL_LOADED(CarM1)) WAIT(0);
				REQUEST_MODEL(PedM1);
				while (!HAS_MODEL_LOADED(PedM1));
				REQUEST_MODEL(PedM2);// Диллер
				while (!HAS_MODEL_LOADED(PedM2));

				CREATE_CAR(CarM1, 286.232, -791.79, 5.445, &car2, TRUE);
				LOCK_CAR_DOORS(car2, 3);
				SET_CAR_ENGINE_ON(car2, 1, 1);
				CREATE_CHAR (26, PedM1, 293.032, -785.32, 5.06, &ped1, TRUE);
				CREATE_CHAR (26, PedM2, 291.032, -785.32, 5.06, &ped2, TRUE);// Диллер
				SET_CHAR_COMPONENT_VARIATION(ped1, 1, 1, 0);
				ADD_SCORE( GetPlayerIndex(), +500);// отнимаем у сумму

				// лояльность игроку
				SET_CHAR_RELATIONSHIP_GROUP(ped1, 18);
				SET_CHAR_RELATIONSHIP(ped1, 5, 24);
				SET_SENSE_RANGE(ped1, 0.01);

				uint hour, minute, weather;
				GET_TIME_OF_DAY(&hour, &minute);
				GET_CURRENT_WEATHER(&weather);
				FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
				FORWARD_TO_TIME_OF_DAY(19, 0);
				MUTE_GAMEWORLD_AND_POSITIONED_RADIO_FOR_TV( 1 );
				
				//------------ катсцена ----------------
				LOAD_ADDITIONAL_TEXT( "ROK_1", 6 );
				START_CUTSCENE_NOW("rok_1");
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

				MUTE_GAMEWORLD_AND_POSITIONED_RADIO_FOR_TV( 0 );
				FORCE_WEATHER_NOW( weather );
				RELEASE_WEATHER();
				FORWARD_TO_TIME_OF_DAY(hour, minute);
				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

				ADD_BLIP_FOR_COORD(-85.34, 1662.781, 4.952, &rock_ico);
				CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
				CHANGE_BLIP_COLOUR(rock_ico, 5);
				CHANGE_BLIP_SCALE(rock_ico, 0.6);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_POINT");
				PRINT_STRING_IN_STRING("string", "RBM1_12", 5000, 1);//~g~Go and collect the 'Love Juice' ingredients from the dealer.

				// часть 1 посигналь
				while(true)
				{
					WAIT(0);
					DRAW_CHECKPOINT( -85.34, 1662.781, 4.952, 1.5, 160, 116, 209);
					GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
					GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -85.34, 1662.781, 4.952, &PlayR);
					if ( PlayR < 2.1)
					{
						if (IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed()))
						{
							// посигнальте
							if (text1 == 0)
							{
								PRINT_HELP("NEHELP3");//Press ~INPUT_VEH_HORN~ button to sound horn.
								PRINT_STRING_IN_STRING("string", "HORN", 5000, 1);//~COL_NET_12~Sound the horn.
								text1 = 1;
							}
							if (IS_PLAYER_PRESSING_HORN(0))// проверка "игрок посигналил"
							{
								CLEAR_HELP();
								REMOVE_BLIP(rock_ico);
								SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );

								// камера
								CREATE_CAM( 14, &camera );
								POINT_CAM_AT_COORD	( camera, -85.341, 1662.781, 5.608 );
								SET_CAM_POS			( camera, -76.384, 1651.037, 10.157 );
								SET_CAM_ACTIVE( camera, 1 );
								SET_CAM_PROPAGATE( camera, 1 );
								ACTIVATE_SCRIPTED_CAMS(1, 1);
								SET_CAM_FOV( camera, 45.0 );
								SET_WIDESCREEN_BORDERS( 1 );

								SET_CHAR_COORDINATES(ped2, -83.647, 1651.852, 5.251);
								SET_CHAR_HEADING(ped2, 0.0);

								SET_CAR_COORDINATES(car2, -85.137, 1649.687, 5.924);
								SET_CAR_HEADING(car2, 70.0);
								TASK_GO_STRAIGHT_TO_COORD(ped2, -84.555, 1661.43, 5.251, 4, -2);

								//им анимации
								REQUEST_ANIMS( "amb@hang_str_idls" );
								while (!HAVE_ANIMS_LOADED( "amb@hang_str_idls" )) WAIT(0);

								SetTime(2500);
								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, ped2, "ROMAN");
								ADD_LINE_TO_CONVERSATION(0, "R2_LL", "ROK1_1A", 0, 0);//Looking for something special? I got what you need!
								TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped2, "stand_idle_k", "amb@hang_str_idls", 8.0, 1, 0, 0, 0, 2000 );
								START_SCRIPT_CONVERSATION(1, 1);
								SetTime(3300);
								SetSpeech();

								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, ped2, "NIKO");
								ADD_LINE_TO_CONVERSATION(0, "R2_LM", "ROK1_9", 0, 0);//Thanks for the money, sucker!
								START_SCRIPT_CONVERSATION(1, 1);

								TASK_ENTER_CAR_AS_DRIVER(ped2, car2, -1);
								SetTime(1450);
								SetSpeech();

								STORE_SCORE(GetPlayerIndex(), &money_plaer);// записываем средства в переменную
								if ( money_plaer >= 500 )
								{
									ADD_SCORE( GetPlayerIndex(), -500);// отнимаем у сумму
								}
								SET_CHAR_MONEY(ped2, 500);
								
								
								POINT_CAM_AT_COORD	( camera, -85.137, 1649.687, 5.924 );
								SET_CAM_POS			( camera, -79.945, 1661.095, 8.333 );
								SETTIMERA( 0 );

								while(true)
								{
									WAIT(0);
									if (IS_CHAR_SITTING_IN_ANY_CAR(ped2))
									{
										break;
									}
									else if (TIMERA() > 3000)
									{
										WARP_CHAR_INTO_CAR(ped2, car2);
										break;
									}
								}

								TASK_CAR_MISSION_COORS_TARGET_NOT_AGAINST_TRAFFIC(ped2, car2, -414.916, 1708.169, 4.989, 4, 100.0, 2, 5, 10);// пед едит на нужные координаты("p1"-пед,"a2"-машины,хyz,какой-то флаг,скорость движения,какие-то флаги)
								SetTime(2000);

								ADD_BLIP_FOR_CHAR(ped2, &rock_ico);
								CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
								CHANGE_BLIP_COLOUR(rock_ico, 5);
								CHANGE_BLIP_SCALE(rock_ico, 0.6);
								CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "MO_TARGET");

								
								ACTIVATE_SCRIPTED_CAMS( 0, 0 );
								END_CAM_COMMANDS( &camera );
								SET_WIDESCREEN_BORDERS( 0 );

								SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );
								CLEAR_PRINTS();
								PRINT_STRING_IN_STRING("string", "RBM1_17", 5000, 1);//~g~Kill the dealer and get the drugs!
								SETTIMERA( 0 );
								text1 = 0;
								break;
							}
							text2 = 0;
						}
						else
						{
							if (text2 == 0)
							{
								PRINT_STRING_IN_STRING("string", "RBM1_14", 5000, 1);//~g~You need a car or a motorcycle!
								text2 = 1;
							}
						}
					}
					else
					{
						if (text1 == 1)
						{
							text1 = 0;
						}
						if (text2 == 1)
						{
							text2 = 0;
						}
					}
					if ((HAS_DEATHARREST_EXECUTED()))
					{
						skip = 1;
						break;
					}
				}
				// часть 2 убей диллера
				if (skip == 0)
				{
					while(true)
					{
						WAIT(0);
						if ((text1 == 0) && (TIMERA() > 3000))
						{
							TASK_CAR_DRIVE_WANDER(ped2, car2, 100.0, 2);
							text1 = 1;
						}
						if (IS_CAR_DEAD(car2))
						{
							if (IS_CHAR_SITTING_IN_ANY_CAR(ped2))
							{
								if (IS_CHAR_DEAD(ped2))
								{
									CLEAR_PRINTS();
									PRINT_STRING_IN_STRING("string", "RBM1_10", 5000, 1);//~r~You idiot! You have destroyed the merchandise!
									skip = 1;
									break;
								}
							}
						}
						if ((IS_CHAR_DEAD(ped2)) || (IS_CHAR_INJURED(ped2)))
						{
							// оформление второй части
							GET_CHAR_COORDINATES(ped2,  &PlayX, &PlayY, &PlayZ);
							GET_GROUND_Z_FOR_3D_COORD(PlayX, PlayY, PlayZ, &PlayZ);
							CREATE_PICKUP( mission_keis, 22, PlayX+0.2, PlayY+0.2, PlayZ+0.2, &bag, 0 );// сумка
							REMOVE_BLIP(rock_ico);

							ADD_BLIP_FOR_PICKUP(bag, &rock_ico);
							CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(rock_ico, 5);
							CHANGE_BLIP_SCALE(rock_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "MO_TARGET");//иконка на радаре ""

							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "ASM4_21", 5000, 1);//~g~Get the briefcase!
							break;
						}
						else if ((HAS_DEATHARREST_EXECUTED()))
						{
							skip = 1;
							break;
						}
						GET_CHAR_COORDINATES(ped2,  &PedX, &PedY, &PedZ);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, PedX, PedY, PedZ, &PlayR);
						if ( PlayR > 250.5)
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_15", 5000, 1);//~r~You have lost the dealer, our cash and the drugs!
							skip = 1;
							break;
						}
					}
				}
				// часть 3 поднять кейс 
				if (skip == 0)
				{
					while(true)
					{
						WAIT(0);
						if (HAS_PICKUP_BEEN_COLLECTED( bag ))
						{
							REMOVE_BLIP(rock_ico);

							// телефонный звонок
							SetTime(1000);
							START_CUSTOM_MOBILE_PHONE_RINGING( 14 ); // 14 - "SOLO" из \audio\sfx\general.rpf\GENERAL\MUSIC_RINGTONES
							PRINT_HELP_FOREVER("NE_M_CALL"); //Press ~INPUT_PHONE_ACCEPT~ to answer a call. Press ~INPUT_PHONE_CANCEL~ to drop.
							SetTime(1500);
							STOP_MOBILE_PHONE_RINGING();
							CLEAR_HELP();

							Object trubka_1;
							uint trubka = vc_mob_phone;
							REQUEST_MODEL(trubka);
							while (!HAS_MODEL_LOADED(trubka)) WAIT(0);
							CREATE_OBJECT_NO_OFFSET(trubka, 1.1, 1.1, -1.1, &trubka_1, TRUE);

							// анимация разговора по телефону
							ATTACH_OBJECT_TO_PED( trubka_1, GetPlayerPed(), 1232, 0.070, 0.052, 0.003, 3.30000000, 0.30000000, -0.45000000, 0 );
							REQUEST_ANIMS( "cellphone" );
							while (!HAVE_ANIMS_LOADED( "cellphone" )) WAIT(0);
							SET_CURRENT_CHAR_WEAPON(GetPlayerPed(), WEAPON_UNARMED, TRUE);
							TASK_PLAY_ANIM_SECONDARY_UPPER_BODY( GetPlayerPed(), "cellphone_in", "cellphone", 8.0, 0, 0, 0, 1, -1 );
							SetTime(1000);
							TASK_PLAY_ANIM_SECONDARY_UPPER_BODY( GetPlayerPed(), "cellphone_talk", "cellphone", 8.0, 1, 0, 0, 0, -1 );

							if ((!HAS_DEATHARREST_EXECUTED()))
							{
								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
								ADD_LINE_TO_CONVERSATION(0, "R2_LN", "MOB_07A", 0, 0);//Hey mate, the guys could do with some company, if you know what I mean...
								START_SCRIPT_CONVERSATION(1, 1);
								SetSpeech();
							}
							if ((!HAS_DEATHARREST_EXECUTED()))
							{
								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
								ADD_LINE_TO_CONVERSATION(0, "R2_LO", "MOB_07B", 0, 0);//I know just the girl.
								START_SCRIPT_CONVERSATION(1, 1);
								SetSpeech();
							}

							//Выгружаем телефон
							TASK_PLAY_ANIM_SECONDARY_UPPER_BODY( GetPlayerPed(), "cellphone_out", "cellphone", 1.0, 0, 0, 0, 0, -1 );
							SetTime(1000);
							DETACH_OBJECT( trubka_1, 1 );
							SET_OBJECT_COORDINATES(trubka_1, 1.1, 1.1, -1.1);
							MARK_OBJECT_AS_NO_LONGER_NEEDED(&trubka_1);
							DELETE_OBJECT( &trubka_1 );
							
							SET_CHAR_COORDINATES(ped1, 730.092, 825.666, 12.132);
							SET_CHAR_HEADING(ped1, -90.0);

							ADD_BLIP_FOR_COORD(738.624, 825.113, 10.174, &rock_ico);
							CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(rock_ico, 5);
							CHANGE_BLIP_SCALE(rock_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_POINT");//иконка на радаре ""

							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_1", 5000, 1);//~g~Go and collect Mercedes from her apartment.
							text2 = 0;
							break;
						}
						else if ((HAS_DEATHARREST_EXECUTED()))
						{
							skip = 1;
							break;
						}
					}
				}
				// часть 4 забери
				if (skip == 0)
				{
					while(true)
					{
						WAIT(0);
						DRAW_CHECKPOINT( 738.624, 825.113, 10.174, 1.5, 160, 116, 209);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, 738.624, 825.113, 10.174, &PlayR);
						if ( PlayR < 2.0)
						{
							if (IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed()))
							{
								REMOVE_BLIP(rock_ico);
								SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );

								// камера
								CREATE_CAM( 14, &camera );
								POINT_CAM_AT_COORD	( camera, 738.281, 822.057, 10.891 );
								SET_CAM_POS			( camera, 727.416, 835.034, 14.047 );
								SET_CAM_ACTIVE( camera, 1 );
								SET_CAM_PROPAGATE( camera, 1 );
								ACTIVATE_SCRIPTED_CAMS(1, 1);
								SET_CAM_FOV( camera, 45.0 );
								SET_WIDESCREEN_BORDERS( 1 );

								TASK_GO_STRAIGHT_TO_COORD(ped1, 740.796, 827.117, 10.174, 2, -2);

								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
								ADD_LINE_TO_CONVERSATION(0, "R2_LP", "ROK1_5", 0, 0);//Hey, Mercedes!
								START_SCRIPT_CONVERSATION(1, 1);
								SetSpeech();

								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
								ADD_LINE_TO_CONVERSATION(0, "R2_LQ", "ROK1_6", 0, 0);//Hiya, Tommy. And how are you?
								START_SCRIPT_CONVERSATION(1, 1);
								SetSpeech();

								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
								ADD_LINE_TO_CONVERSATION(0, "R2_LR", "ROK1_7", 0, 0);//Just fine. Listen, you fancy having Love Fist?
								START_SCRIPT_CONVERSATION(1, 1);
								SetSpeech();

								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "NIKO");
								ADD_LINE_TO_CONVERSATION(0, "R2_LS", "ROK1_8", 0, 0);//Ok, but just as a favor I expect returned..
								START_SCRIPT_CONVERSATION(1, 1);
								SetSpeech();

								
								ACTIVATE_SCRIPTED_CAMS( 0, 0 );
								END_CAM_COMMANDS( &camera );
								SET_WIDESCREEN_BORDERS( 0 );
								SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

								ADD_BLIP_FOR_COORD(-438.107, 1696.831, 4.989, &rock_ico);
								CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
								CHANGE_BLIP_COLOUR(rock_ico, 5);
								CHANGE_BLIP_SCALE(rock_ico, 0.6);
								CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_POINT");//иконка на радаре ""
								SetTime(500);

								CLEAR_PRINTS();
								PRINT_STRING_IN_STRING("string", "RBM1_13", 5000, 1);//~g~Get the 'Love Juice' and Mercedes to the band before they are needed on stage.
								break;
							}
							else
							{
								if (text2 == 0)
								{
									CLEAR_PRINTS();
									PRINT_STRING_IN_STRING("string", "RBM1_14", 5000, 1);//~g~You need a car or a motorcycle!
									text2 = 1;
								}
							}
						}
						else
						{
							if (text2 == 1)
							{
								text2 = 0;
							}
						}
						if ((IS_CHAR_DEAD(ped1)) || (IS_CHAR_INJURED(ped1)))
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_8", 5000, 1);//~r~Mercedes is dead!
							skip = 1;
							break;
						}
						else if ((HAS_DEATHARREST_EXECUTED()))
						{
							skip = 1;
							break;
						}
					}
				}
				// часть 5 отвези
				if (skip == 0)
				{
					while(true)
					{
						WAIT(0);
						//============================ HUD ============================
						// таймер
						if (TIMERA() > 999)
						{
							time_s -= 1;
							SETTIMERA( 0 );
						}
						if (time_s < 0)
						{
							time_m -= 1;
							time_s = 59;
						}

						// таймер
						DRAW_SPRITE( fon, 0.8765625, 0.7838, 0.14322917, 0.0296, 0.0, 246, 151, 255, 155 );
						//DRAW_SPRITE( timer, 0.8765625, 0.7838, 0.14322917, 0.0592, 0.0, 255, 255, 255, 255 );
						if ((time_m == 0) && (time_s < 16))
						{
							SET_TEXT_COLOUR(235, 25, 35, 255);
							SET_TEXT_SCALE(0.156, 0.267);
							SET_TEXT_DROPSHADOW(1, 80, 0, 0, 255);
							DISPLAY_TEXT(0.78815097, 0.77731852, "RACES"); //TIME:

							SET_TEXT_COLOUR(235, 25, 35, 255);
							SET_TEXT_SCALE(0.26, 0.445);
							SET_TEXT_DROPSHADOW(1, 80, 0, 0, 255);
							SET_TEXT_CENTRE(1);
							DISPLAY_TEXT_WITH_NUMBER(0.9088542, 0.76954074, "CP_TIME_ZERO", time_m);// минуты

							SET_TEXT_COLOUR(235, 25, 35, 255);
							SET_TEXT_SCALE(0.26, 0.445);
							SET_TEXT_DROPSHADOW(1, 80, 0, 0, 255);
							DISPLAY_TEXT(0.9203125, 0.76954074, "CP_TIME_SEP");

							SET_TEXT_COLOUR(235, 25, 35, 255);
							SET_TEXT_SCALE(0.26, 0.445);
							SET_TEXT_DROPSHADOW(1, 80, 0, 0, 255);
							SET_TEXT_CENTRE(1);
							if ( time_s > 9 )
							{
								DISPLAY_TEXT_WITH_NUMBER(0.9348959, 0.76954074, "CP_TIME_NOZERO", time_s);// секунды
							}
							else
							{
								DISPLAY_TEXT_WITH_NUMBER(0.9348959, 0.76954074, "CP_TIME_ZERO", time_s);// секунды
							}
						}
						else
						{
							SET_TEXT_COLOUR(95, 195, 247, 255);
							SET_TEXT_SCALE(0.156, 0.267);
							SET_TEXT_DROPSHADOW(1, 26, 90, 128, 255);
							DISPLAY_TEXT(0.78815097, 0.77731852, "RACES"); //TIME:

							SET_TEXT_COLOUR(95, 195, 247, 255);
							SET_TEXT_SCALE(0.26, 0.445);
							SET_TEXT_DROPSHADOW(1, 26, 90, 128, 255);
							SET_TEXT_CENTRE(1);
							DISPLAY_TEXT_WITH_NUMBER(0.9088542, 0.76954074, "CP_TIME_ZERO", time_m);// минуты

							SET_TEXT_COLOUR(95, 195, 247, 255);
							SET_TEXT_SCALE(0.26, 0.445);
							SET_TEXT_DROPSHADOW(1, 26, 90, 128, 255);
							DISPLAY_TEXT(0.9203125, 0.76954074, "CP_TIME_SEP");

							SET_TEXT_COLOUR(95, 195, 247, 255);
							SET_TEXT_SCALE(0.26, 0.445);
							SET_TEXT_DROPSHADOW(1, 26, 90, 128, 255);
							SET_TEXT_CENTRE(1);
							if ( time_s > 9 )
							{
								DISPLAY_TEXT_WITH_NUMBER(0.9348959, 0.76954074, "CP_TIME_NOZERO", time_s);// секунды
							}
							else
							{
								DISPLAY_TEXT_WITH_NUMBER(0.9348959, 0.76954074, "CP_TIME_ZERO", time_s);// секунды
							}
						}

						if ((sound == 0) && (time_s == 15) && (time_m == 0))
						{
							DISABLE_FRONTEND_RADIO();
							while (!(PRELOAD_STREAM("MP_COUNTDOWN")));
							PRELOAD_STREAM("MP_COUNTDOWN");  // имя берется из sounds.dat15, также можно проиграть музыку из радио
							PLAY_STREAM_FRONTEND();
							sound = 1;
						}

						// сталкинг
						GET_CHAR_COORDINATES(ped1,  &PedX, &PedY, &PedZ);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						if (IS_CHAR_IN_AREA_3D( GetPlayerPed(), PedX+22, PedY+22, PedZ+15, PedX-22, PedY-22, PedZ-15, 0 ))
						{
							if (stalking == 0)
							{
								TASK_GO_TO_CHAR( ped1, GetPlayerPed(), -1, 13.50000000 );
								stalking = 1;
							}

							GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, PedX, PedY, PedZ, &stalkerR);
							if ((stalkerR < 1.5) && (stalking == 1) && (in_car == 0))
							{
								stalking = 2;
								TASK_GO_STRAIGHT_TO_COORD(ped1, PedX, PedY, PedZ, 4, -2);
							}
							else if ((stalkerR > 5.5) && (stalking == 2) && (in_car == 0))
							{
								stalking = 0;
							}

							if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (!IS_CHAR_SITTING_IN_ANY_CAR(ped1)) && (in_car == 0))
							{
								in_car = 1;
								GET_CAR_CHAR_IS_USING(GetPlayerPed(), &car1);
								TASK_ENTER_CAR_AS_PASSENGER(ped1, car1, -1, 0);
								SETTIMERB( 0 );
							}
							else if ((!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (in_car == 1))
							{
								if (IS_CHAR_SITTING_IN_ANY_CAR(ped1))
								{
									in_car = 0;
									TASK_LEAVE_CAR(ped1, car1);
									MARK_CAR_AS_NO_LONGER_NEEDED(&car1);
									TASK_GO_TO_CHAR( ped1, GetPlayerPed(), -1, 13.50000000 );
									stalking = 1;
								}
							}
							else if ((!IS_CHAR_SITTING_IN_ANY_CAR(ped1)) && (in_car == 1) && (TIMERB() > 15000))
							{
								WARP_CHAR_INTO_CAR_AS_PASSENGER(ped1, car1, 0);
							}
						}
						else
						{
							if (stalking == 1)
							{
								stalking = 0;
								TASK_GO_STRAIGHT_TO_COORD(ped1, PedX, PedY, PedZ, 4, -2);
								PRINT_STRING_IN_STRING("string", "HEY", 5000, 1);//~g~Don't go solo, keep your posse together!
							}
						}

						DRAW_CHECKPOINT( -438.107, 1696.831, 4.989, 1.5, 160, 116, 209);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -438.107, 1696.831, 4.989, &PlayR);
						GET_DISTANCE_BETWEEN_COORDS_3D( PedX, PedY, PedZ, -438.107, 1696.831, 4.989, &in_cord);
						if (( PlayR < 2.2) && (in_cord < 2.5))
						{
							if (sound == 1)
							{
								STOP_STREAM();
								ENABLE_FRONTEND_RADIO();
							}
							SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );

							// камера
							CREATE_CAM( 14, &camera );
							POINT_CAM_AT_COORD	( camera, -437.331, 1699.276, 6.069 );
							SET_CAM_POS			( camera, -441.059, 1680.391, 11.842 );
							SET_CAM_ACTIVE( camera, 1 );
							SET_CAM_PROPAGATE( camera, 1 );
							ACTIVATE_SCRIPTED_CAMS(1, 1);
							SET_CAM_FOV( camera, 45.0 );
							SET_WIDESCREEN_BORDERS( 1 );

							if (car1 != 0)
							{
								if (IS_CHAR_IN_CAR(ped1, car1))
								{
									TASK_LEAVE_CAR(ped1, car1);
									SetTime (700);
								}
							}
							TASK_GO_STRAIGHT_TO_COORD(ped1, -442.551, 1692.462, 5.088, 2, -2);

							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_MA", "MERC_39", 0, 0);//I'll see you later, big boy.
							START_SCRIPT_CONVERSATION(1, 1);
							SetTime (6000);

							
							POINT_CAM_AT_COORD	( camera, -442.551, 1692.462, 6.279 );
							SET_CAM_POS			( camera, -436.217, 1683.129, 7.715 );
							SetTime (3000);

							
							ACTIVATE_SCRIPTED_CAMS( 0, 0 );
							END_CAM_COMMANDS( &camera );
							SET_WIDESCREEN_BORDERS( 0 );
							SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

							SET_CHAR_COORDINATES(ped1, -83.647, 1651.852, 5.251);
							skip = 2;
							break;
						}
						// провал миссии
						if ((time_m == 0) && (time_s == 0))
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_7", 5000, 1);//~r~You did not get the Love Juice in time!
							skip = 1;
							break;
						}
						else if ((IS_CHAR_DEAD(ped1)) || (IS_CHAR_INJURED(ped1)))
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM1_8", 5000, 1);//~r~Mercedes is dead!
							skip = 1;
							break;
						}
					}
				}
				// зачещаем скрипт
				WAIT(0);
				REMOVE_BLIP(rock_ico);
				ABORT_SCRIPTED_CONVERSATION( 0 );

				// выгружаем из памяти
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM1);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM2);
				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM1);

				// выгружаем из памяти
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped1);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped2);

				// выгружаем из памяти
				if (car1 != 0)
				{
					MARK_CAR_AS_NO_LONGER_NEEDED(&car1);
				}
				MARK_CAR_AS_NO_LONGER_NEEDED(&car2);

				RELEASE_TEXTURE( fon );
				RELEASE_TEXTURE( timer );
				REMOVE_TXD( textur );

				if (sound == 1)
				{
					STOP_STREAM();
					ENABLE_FRONTEND_RADIO();
				}

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
					REGISTER_MISSION_PASSED("ROCK_1");
					G_ROCK = 2;
					autosave = 1;
				}
				blip_on = 0;
				G_ONMISSION = 0;
			}
		}

//============================== Psycho Killer ======================================
		else if ((G_ONMISSION == 0) && (G_ROCK == 2))
		{
			if (blip_on == 0)
			{
				ADD_BLIP_FOR_COORD(-442.551, 1692.462, 5.088, &rock_ico);
				CHANGE_BLIP_SPRITE(rock_ico, BLIP_FIRE_STATION);
				CHANGE_BLIP_SCALE(rock_ico, 1.1);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "LG_19");
				blip_on = 1;
			}
			DRAW_CHECKPOINT( -442.551, 1692.462, 5.088, 1.5, 160, 116, 209);
			GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
			GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -442.551, 1692.462, 5.088, &PlayR);
			if (( PlayR < 1.5) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
			{
				G_ONMISSION = 1;
				REMOVE_BLIP(rock_ico);
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

				SET_CHAR_COORDINATES(GetPlayerPed(), -440.859, 1692.332, 5.34);
				SET_CHAR_HEADING(GetPlayerPed(), -90.0);


				Ped ped1, ped2, ped3, ped4, ped5, ped6, ped7, ped8, ped9, ped10, ped11, ped12, ped13, ped14, ped15, ped16, ped17, ped18;
				Car car1, car2, car3;
				Cam camera;
				Object stol;

				skip = 0;
				in_cord = 0;
				sound = 0;
				in_car = 0;
				play_aud = 1;
				super_ped = 1;

				uint CarM1 = MODEL_COGNOSCENTI;// Лимузин
				uint CarM2 = MODEL_SENTINEL;//а маньяка
				uint CarM3 = MODEL_TRASH;// Мусоровоз
				uint PedM1 = MODEL_IG_BERNIE_CRANE;// Псих-убайча
				uint PedM2 = MODEL_M_M_SECURITYMAN;
				uint PedM3 = MODEL_F_Y_HOOKER_03;// шкура 1
				uint PedM4 = MODEL_F_Y_HOOKER_01;// шкура 2
				uint PedM5 = MODEL_M_Y_HASID_01;// в коже
				uint PedM6 = MODEL_M_Y_GALB_LO_01;
				uint PedM7 = MODEL_M_Y_GALB_LO_02;
				uint PedM8 = MODEL_M_M_SWEEPER;// мусорщик
				uint ObjM1 = lf_mediastage;
				uint AudID;

				REQUEST_MODEL(CarM1);
				while (!HAS_MODEL_LOADED(CarM1)) WAIT(0);
				REQUEST_MODEL(CarM2);
				while (!HAS_MODEL_LOADED(CarM2)) WAIT(0);
				REQUEST_MODEL(CarM3);
				while (!HAS_MODEL_LOADED(CarM3)) WAIT(0);


				uint hour, minute, weather;
				GET_TIME_OF_DAY(&hour, &minute);
				GET_CURRENT_WEATHER(&weather);
				FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
				FORWARD_TO_TIME_OF_DAY(19, 0);
				MUTE_GAMEWORLD_AND_POSITIONED_RADIO_FOR_TV( 1 );
				
				//------------ катсцена ----------------
				LOAD_ADDITIONAL_TEXT( "ROK_2", 6 );
				START_CUTSCENE_NOW("rok_2");
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

				MUTE_GAMEWORLD_AND_POSITIONED_RADIO_FOR_TV( 0 );
				FORCE_WEATHER_NOW( weather );
				RELEASE_WEATHER();
				FORWARD_TO_TIME_OF_DAY(hour, minute);
				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

				CREATE_CAR(CarM1, -433.092, 1681.284, 5.453, &car1, TRUE);
				SET_CAR_HEADING(car1, 180.0);

				ADD_BLIP_FOR_CAR(car1, &rock_ico);
				CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
				CHANGE_BLIP_COLOUR(rock_ico, 19);
				CHANGE_BLIP_SCALE(rock_ico, 0.6);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_POINT");
				PRINT_STRING_IN_STRING("string", "RBM2_1", 5000, 1);//~g~Drive the limo to the signing event and try to draw the psycho out.

				CREATE_CAR(CarM2, 303.109, -787.416, 5.445, &car2, TRUE);
				CREATE_CAR(CarM3, 299.551, -787.416, 5.445, &car3, TRUE);
				LOCK_CAR_DOORS(car2, 3);
				LOCK_CAR_DOORS(car3, 3);

				REQUEST_MODEL(PedM1);// Таксист
				while (!HAS_MODEL_LOADED(PedM1));
				REQUEST_MODEL(PedM2);// Пассажир
				while (!HAS_MODEL_LOADED(PedM2));
				REQUEST_MODEL(PedM3);// Таксист
				while (!HAS_MODEL_LOADED(PedM3));
				REQUEST_MODEL(PedM4);// Таксист
				while (!HAS_MODEL_LOADED(PedM4));
				REQUEST_MODEL(PedM5);// Таксист
				while (!HAS_MODEL_LOADED(PedM5));
				REQUEST_MODEL(PedM6);// Таксист
				while (!HAS_MODEL_LOADED(PedM6));
				REQUEST_MODEL(PedM7);// Таксист
				while (!HAS_MODEL_LOADED(PedM7));
				REQUEST_MODEL(PedM8);// Таксист
				while (!HAS_MODEL_LOADED(PedM8));

				REQUEST_MODEL(ObjM1);
				while (!HAS_MODEL_LOADED(ObjM1)) WAIT(0);

				REQUEST_CAR_RECORDING( 3049 );
				while (!HAS_CAR_RECORDING_BEEN_LOADED( 3049 )) WAIT(0);

				CREATE_CHAR (26, PedM1, -447.587, 1285.01, 5.28142, &ped1, TRUE);// Псих-убийца
				SET_CHAR_HEADING(ped1, -100.0);
				CREATE_CHAR (26, PedM2, -443.063, 1282.63, 5.28142, &ped2, TRUE);
				SET_CHAR_HEADING(ped2, -5.0);
				CREATE_CHAR (26, PedM3, -444.51, 1284.93, 5.28142, &ped3, TRUE);// очередь 1
				SET_CHAR_HEADING(ped3, -100.0);
				CREATE_CHAR (26, PedM4, -446.269, 1284.96, 5.28142, &ped4, TRUE);// очередь 2
				SET_CHAR_HEADING(ped4, -100.0);
				CREATE_CHAR (26, PedM3, -447.913, 1287.53, 5.28142, &ped5, TRUE);// Просто пед 1
				SET_CHAR_HEADING(ped5, -10.0);
				CREATE_CHAR (26, PedM4, -447.656,1288.51,5.28142, &ped6, TRUE);// Просто пед 2
				SET_CHAR_HEADING(ped6, -170.0);
				CREATE_CHAR (26, PedM4, -445.663, 1288.14, 5.28142, &ped7, TRUE);// Просто пед 3
				SET_CHAR_HEADING(ped7, 15.0);
				CREATE_CHAR (26, PedM3, -445.464, 1289.42, 5.28142, &ped8, TRUE);// Просто пед 4
				SET_CHAR_HEADING(ped8, -170.0);
				CREATE_CHAR (26, PedM4, -441.997, 1286.93, 5.28142, &ped9, TRUE);// Просто пед 5
				SET_CHAR_HEADING(ped9, -165.0);
				CREATE_CHAR (26, PedM5, -443.236, 1289.91, 5.28142, &ped10, TRUE);// Просто пед 6
				SET_CHAR_HEADING(ped10, -170.0);
				CREATE_CHAR (26, PedM7, -440.907, 1290.1, 5.28142, &ped11, TRUE);/// Просто пед 7
				SET_CHAR_HEADING(ped11, 175.0);
				CREATE_CHAR (26, PedM7, -439.186, 1289.29, 5.28142, &ped12, TRUE);// Просто пед 8
				SET_CHAR_HEADING(ped12, 165.0);
				CREATE_CHAR (26, PedM6, -437.533, 1287.92, 5.28142, &ped13, TRUE);// Просто пед 9
				SET_CHAR_HEADING(ped13, 165.0);
				CREATE_CHAR (26, PedM3, -436.216, 1289.09, 5.28142, &ped14, TRUE);// Просто пед 10
				SET_CHAR_HEADING(ped14, 165.0);
				CREATE_CHAR (26, PedM3, -437.723, 1290.16, 5.28142, &ped15, TRUE);// Просто пед 11
				SET_CHAR_HEADING(ped15, -165.0);
				CREATE_CHAR (26, PedM4, -434.892, 1288.57, 5.28142, &ped16, TRUE);// Просто пед 12
				SET_CHAR_HEADING(ped16, -165.0);
				CREATE_CHAR (26, PedM6, -432.748, 1287.36, 5.28142, &ped17, TRUE);// Просто пед 13
				SET_CHAR_HEADING(ped17, 165.0);
				CREATE_CHAR_INSIDE_CAR(car3, 1, PedM8, &ped18);


				CREATE_OBJECT_NO_OFFSET(ObjM1, -432.049, 1285.56, 5.01901, &stol, TRUE);
				SET_OBJECT_HEADING(stol, 180.0);
				SET_OBJECT_DYNAMIC(stol, 0);
				SET_OBJECT_INVINCIBLE(stol, 1);
				FREEZE_OBJECT_POSITION(stol, 1);



				
				REQUEST_ANIMS( "missivan_1" );
				while (!HAVE_ANIMS_LOADED( "missivan_1" ));
				REQUEST_ANIMS( "amb@inquisitive" );
				while (!HAVE_ANIMS_LOADED( "amb@inquisitive" ));

				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped5, "argue_b", "missivan_1", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped6, "street_chat_b", "missivan_1", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped7, "argue_b", "missivan_1", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped8, "i_cant_sey", "missivan_1", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped9, "shock_a", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped10, "shock_b", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped11, "shock_c", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped12, "shock_d", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped13, "shock_a", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped14, "shock_b", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped15, "shock_c", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped16, "shock_d", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );
				TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped17, "shock_a", "amb@inquisitive", 1.0, 1, 0, 0, 0, -1 );

				
				while (!(REQUEST_AMBIENT_AUDIO_BANK( "SCRIPT_MISSION/ROCKCROWD" )))
				{
					 WAIT(0);
				}
				AudID = GET_SOUND_ID();
				PLAY_SOUND_FROM_POSITION(AudID, "SCRIPT_MISSION_ROCKCROWD", -440.36, 1287.98, 6.05);

				while (TRUE)
				{
					WAIT(0);
					if (IS_CHAR_IN_CAR(GetPlayerPed(), car1))
					{
						DRAW_CHECKPOINT( -435.115, 1297.69, 4.81705, 1.5, 160, 116, 209);
						if (in_car == 0)
						{
							REMOVE_BLIP(rock_ico);
							ADD_BLIP_FOR_COORD(-435.115, 1297.69, 4.81705, &rock_ico);
							CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(rock_ico, 5);
							CHANGE_BLIP_SCALE(rock_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_POINT");
							in_car = 1;
						}
					}
					else
					{
						if (in_car == 1)
						{
							REMOVE_BLIP(rock_ico);
							ADD_BLIP_FOR_CAR(car1, &rock_ico);
							CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(rock_ico, 19);
							CHANGE_BLIP_SCALE(rock_ico, 0.6);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_CAR");
							PRINT_STRING_IN_STRING("string", "IN_VEH", 5000, 1);//~COL_NET_12~Hey! Get back in the vehicle!
							in_car = 0;
						}
					}

					GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
					GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -435.115, 1297.69, 4.81705, &PlayR);
					if (( PlayR < 2.1) && (in_car == 1))
					{
						if  (IS_CHAR_IN_CAR(GetPlayerPed(), car1))
						{

							REMOVE_BLIP(rock_ico);
							UpdateWeaponOfPed(ped1, WEAPON_PISTOL);

							//им анимации
							REQUEST_ANIMS( "amb@hang_str_idls" );
							while (!HAVE_ANIMS_LOADED( "amb@hang_str_idls" )) WAIT(0);

							
							CREATE_CAM( 14, &camera );
							POINT_CAM_AT_COORD	( camera, -449.047, 1285.901, 6.95093 );
							SET_CAM_POS			( camera, -436.626, 1284.841, 5.43647 );
							SET_CAM_ACTIVE( camera, 1 );
							SET_CAM_PROPAGATE( camera, 1 );
							ACTIVATE_SCRIPTED_CAMS(1, 1);
							SET_CAM_FOV( camera, 45.0 );
							SET_WIDESCREEN_BORDERS( 1 );
							SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );

							TASK_GO_STRAIGHT_TO_COORD(ped4, -439.243, 1284.93, 5.28142, 2, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped3, -439.243, 1284.93, 5.28142, 2, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped1, -439.243, 1284.93, 5.28142, 2, -2);// Пед идёт
							SetTime(1500);
							TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped2, "give_obj", "missivan_1", 1.0, 1, 0, 0, 0, 600 );
							SET_CAR_COORDINATES(car2, -425.191, 1291.22, 5.4854);
							SET_CAR_HEADING(car2, -115.0);
							TASK_GO_STRAIGHT_TO_COORD(ped3, -439.682, 1279.73, 5.28142, 2, -2);// Пед идёт

							SetTime(1500);
							TASK_GO_STRAIGHT_TO_COORD(ped4, -439.682, 1279.73, 5.28142, 2, -2);// Пед идёт
							TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped2, "give_obj", "missivan_1", 1.0, 1, 0, 0, 0, 600 );
							SetTime(1500);

							// стреляет
							SET_CURRENT_CHAR_WEAPON(ped1, WEAPON_PISTOL, TRUE);
							SET_CHAR_HEADING(ped1, -165.0);
							STOP_SOUND(AudID);
							RELEASE_SOUND_ID(AudID);
							play_aud = 0;

							TASK_GO_STRAIGHT_TO_COORD(ped5, -449.024, 1316.54, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped6, -430.853, 1318.65, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped7, -448.303, 1327.91, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped8, -431.863, 1328.72, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped9, -425.171, 1324.88, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped10, -449.024, 1316.54, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped11, -430.853, 1318.65, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped12, -448.303, 1327.91, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped13, -431.863, 1328.72, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped14, -425.171, 1324.88, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped15, -448.303, 1327.91, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped16, -431.863, 1328.72, 4.81705, 3, -2);// Пед идёт
							TASK_GO_STRAIGHT_TO_COORD(ped17, -425.171, 1324.88, 4.81705, 3, -2);// Пед идёт

							PANIC_SCREAM(ped5);
							PANIC_SCREAM(ped6);
							PANIC_SCREAM(ped7);
							PANIC_SCREAM(ped8);
							PANIC_SCREAM(ped9);
							PANIC_SCREAM(ped10);
							PANIC_SCREAM(ped11);
							PANIC_SCREAM(ped12);
							PANIC_SCREAM(ped13);
							PANIC_SCREAM(ped14);
							PANIC_SCREAM(ped15);
							PANIC_SCREAM(ped16);
							PANIC_SCREAM(ped17);


							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "NIKO");
							ADD_LINE_TO_CONVERSATION(0, "R2_MB", "PSYCH_1", 0, 0);//I'll see Love Fist burn!
							START_SCRIPT_CONVERSATION(1, 1);
							SetTime(500);
							TASK_SHOOT_AT_CHAR(ped1, ped2, 1000, 3);
							SetTime(1000);

							EXPLODE_CHAR_HEAD(ped2);
							SetTime(1500);
							SetSpeech();
							SET_CHAR_HEADING(ped1, -40.0);
							SET_CHAR_COORDINATES(ped3, 291.032, -785.32, 5.06);
							SET_CHAR_COORDINATES(ped4, 293.032, -785.32, 5.06);

							POINT_CAM_AT_COORD	( camera, -442.822, 1282.89, 5.94946 );
							SET_CAM_POS			( camera, -438.855, 1286.99, 6.37154 );

							// монолог
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, ped1, "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_MC", "PSYCH_2", 0, 0);//Love Fist ruined my life!
							TASK_PLAY_ANIM_NON_INTERRUPTABLE( ped1, "stand_idle_k", "amb@hang_str_idls", 8.0, 1, 0, 0, 0, 2500 );
							START_SCRIPT_CONVERSATION(1, 1);
							SetTime(2500);

							// убийца бежит в
							CLEAR_AREA(-425.191, 1291.22, 5.4854, 35.0, 1);
							TASK_ENTER_CAR_AS_DRIVER(ped1, car2, -1);
							SetTime(1500);
							
							POINT_CAM_AT_COORD	( camera, -424.734, 1291.27, 5.75685 );
							SET_CAM_POS			( camera, -442.621, 1283.96, 8.15218 );
							SetTime(2000);
							WARP_CHAR_INTO_CAR(ped1, car2);

							ADD_BLIP_FOR_CHAR(ped1, &rock_ico);
							CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
							CHANGE_BLIP_COLOUR(rock_ico, 19);
							CHANGE_BLIP_SCALE(rock_ico, 0.001);
							CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "MO_TARGET");//иконка на радаре называние в истории карты

							TASK_CAR_MISSION_COORS_TARGET_NOT_AGAINST_TRAFFIC(ped1, car2, -250.874, 1282.11, 5.02106, 4, 55.0, 2, 5, 10);// пед едит на нужные координаты("p1"-пед,"a2"-машины,хyz,какой-то флаг,скорость движения,какие-то флаги)

							
							ACTIVATE_SCRIPTED_CAMS( 0, 0 );
							END_CAM_COMMANDS( &camera );
							SET_WIDESCREEN_BORDERS( 0 );
							SetTime(1000);
							SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

							TASK_WANDER_STANDARD(ped5);
							TASK_WANDER_STANDARD(ped6);
							TASK_WANDER_STANDARD(ped7);
							TASK_WANDER_STANDARD(ped8);
							TASK_WANDER_STANDARD(ped9);
							TASK_WANDER_STANDARD(ped10);
							TASK_WANDER_STANDARD(ped11);
							TASK_WANDER_STANDARD(ped12);
							TASK_WANDER_STANDARD(ped13);
							TASK_WANDER_STANDARD(ped14);
							TASK_WANDER_STANDARD(ped15);
							TASK_WANDER_STANDARD(ped16);
							TASK_WANDER_STANDARD(ped17);

							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM2_4", 5000, 1);//~g~Get the Psycho! Don't let him escape!
							break;
						}
					}

					if ((HAS_DEATHARREST_EXECUTED()))
					{
						skip = 1;
						break;
					}
					else if (IS_CAR_DEAD(car2))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "RBM2_2", 5000, 1);//~r~You've wrecked the band's car!
						skip = 1;
						break;
					}
					else if (IS_CHAR_SHOOTING_IN_AREA(GetPlayerPed(), -421.092, 1280.479, -451.092, 1310.479, 0))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "RBM2_7", 5000, 1);//~r~The fans have been attacked, the psycho won't show!
						PANIC_SCREAM(ped5);
						PANIC_SCREAM(ped6);
						PANIC_SCREAM(ped7);
						PANIC_SCREAM(ped8);
						PANIC_SCREAM(ped9);
						PANIC_SCREAM(ped10);
						PANIC_SCREAM(ped11);
						PANIC_SCREAM(ped12);
						PANIC_SCREAM(ped13);
						PANIC_SCREAM(ped14);
						PANIC_SCREAM(ped15);
						PANIC_SCREAM(ped16);
						PANIC_SCREAM(ped17);
						skip = 1;
						break;
					}
					else if ((IS_CHAR_DEAD(ped2)) || (IS_CHAR_INJURED(ped2)))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "RBM2_8", 5000, 1);//~r~The security guards have been attacked, the psycho won't show!
						skip = 1;
						break;
					}
					else if ((IS_CHAR_DEAD(ped1)) || (IS_CHAR_INJURED(ped1)) || (IS_CHAR_DEAD(ped3)) || (IS_CHAR_INJURED(ped3)) || (IS_CHAR_DEAD(ped4)) || (IS_CHAR_INJURED(ped4)) ||(IS_CHAR_DEAD(ped5)) || (IS_CHAR_INJURED(ped5)) ||(IS_CHAR_DEAD(ped6)) || (IS_CHAR_INJURED(ped6)))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "RBM2_7", 5000, 1);//~r~The fans have been attacked, the psycho won't show!
						skip = 1;
						break;
					}
					else if ((IS_CHAR_DEAD(ped7)) || (IS_CHAR_INJURED(ped7)) || (IS_CHAR_DEAD(ped8)) || (IS_CHAR_INJURED(ped8)) || (IS_CHAR_DEAD(ped9)) || (IS_CHAR_INJURED(ped9)) ||(IS_CHAR_DEAD(ped10)) || (IS_CHAR_INJURED(ped10)) ||(IS_CHAR_DEAD(ped11)) || (IS_CHAR_INJURED(ped11)))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "RBM2_7", 5000, 1);//~r~The fans have been attacked, the psycho won't show!
						skip = 1;
						break;
					}
					else if ((IS_CHAR_DEAD(ped12)) || (IS_CHAR_INJURED(ped12)) || (IS_CHAR_DEAD(ped13)) || (IS_CHAR_INJURED(ped13)) || (IS_CHAR_DEAD(ped14)) || (IS_CHAR_INJURED(ped14)) ||(IS_CHAR_DEAD(ped15)) || (IS_CHAR_INJURED(ped15)) ||(IS_CHAR_DEAD(ped16)) || (IS_CHAR_INJURED(ped16)) || (IS_CHAR_DEAD(ped17)) || (IS_CHAR_INJURED(ped17)))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "RBM2_7", 5000, 1);//~r~The fans have been attacked, the psycho won't show!
						skip = 1;
						break;
					}
				}
				if (skip == 0)
				{
					while (TRUE)
					{
						WAIT(0);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						GET_CHAR_COORDINATES(ped1,  &PedX, &PedY, &PedZ);

						if (in_cord == 0)
						{
							GET_DISTANCE_BETWEEN_COORDS_3D( PedX, PedY, PedZ, -250.874, 1282.11, 5.02106, &PedR);
							if (PedR < 25)
							{
								TASK_CAR_MISSION_COORS_TARGET_NOT_AGAINST_TRAFFIC(ped1, car2, -250.903,1645.24,5.02106, 4, 20.0, 2, 5, 10);// пед едит на нужные координаты("p1"-пед,"a2"-машины,хyz,какой-то флаг,скорость движения,какие-то флаги)
								in_cord = 1;
							}
						}
						else if (in_cord == 1)
						{
							GET_DISTANCE_BETWEEN_COORDS_3D( PedX, PedY, PedZ, -250.874, 1282.11, 5.02106, &PedR);
							if (PedR < 10)
							{
								TASK_CAR_MISSION_COORS_TARGET_NOT_AGAINST_TRAFFIC(ped1, car2, -250.903,1645.24,5.02106, 4, 50.0, 2, 5, 10);// пед едит на нужные координаты("p1"-пед,"a2"-машины,хyz,какой-то флаг,скорость движения,какие-то флаги)
								in_cord = 2;
							}
						}
						else if (in_cord == 2)
						{
							GET_DISTANCE_BETWEEN_COORDS_3D( PedX, PedY, PedZ, -250.903, 1645.24, 5.02106, &PedR);
							if (PedR < 55)
							{
								// выезд мусоровоза
								CLEAR_AREA(-250.903, 1645.24, 5.02106, 25.0, 1);
								START_PLAYBACK_RECORDED_CAR_WITH_OFFSET(car3, 3049, 0.0, 0.0, 0.0);
								SET_PLAYBACK_SPEED(car3, 1.25);

								TASK_CAR_DRIVE_WANDER(ped1, car2, 50.0, 2);
								in_cord = 3;
								SETTIMERB( 0 );
							}
						}
						else if (in_cord == 3)
						{
							if (TIMERB() > 5000)
							{
								STOP_PLAYBACK_RECORDED_CAR(car3);
								REMOVE_CAR_RECORDING( 3049 );
								TASK_CAR_DRIVE_WANDER(ped18, car3, 10.0, 2);
								in_cord = 4;
							}
						}

						if (super_ped == 1)
						{
							SET_CHAR_INVINCIBLE(ped1, 1);
							if (TIMERC() > 25000)
							{
								SET_CHAR_INVINCIBLE(ped1, 0);
								super_ped = 0;
							}
						}
						GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, PedX, PedY, PedZ, &PlayR);
						if ( PlayR > 250.1)
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM2_5", 5000, 1);//~r~You lost him, you idiot!
							skip = 1;
							break;
						}
						else if ((IS_CHAR_DEAD(ped1)) || (IS_CHAR_INJURED(ped1)))
						{
							EXPLODE_CHAR_HEAD(ped1);
							skip = 2;
							break;
						}
					}
				}
				// зачещаем скрипт
				WAIT(0);
				REMOVE_BLIP(rock_ico);

				if (play_aud == 1)
				{
					STOP_SOUND(AudID);
					RELEASE_SOUND_ID(AudID);
				}

				if (in_cord == 3)
				{
					STOP_PLAYBACK_RECORDED_CAR(car3);
					REMOVE_CAR_RECORDING( 3049 );
				}

				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM1);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM2);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM3);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM4);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM5);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM6);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM7);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM8);
				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM1);
				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM2);
				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM3);
				MARK_MODEL_AS_NO_LONGER_NEEDED(ObjM1);

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
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped17);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped18);

				MARK_CAR_AS_NO_LONGER_NEEDED(&car1);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car2);
				MARK_CAR_AS_NO_LONGER_NEEDED(&car3);

				DELETE_OBJECT(&stol);
				MARK_OBJECT_AS_NO_LONGER_NEEDED(&stol);

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
					REGISTER_MISSION_PASSED("ROCK_2");
					G_ROCK = 3;
					autosave = 1;
				}
				G_ONMISSION = 0;
			}
		}
//============================== Publicity Tour ======================================
		else if ((G_ONMISSION == 0) && (G_ROCK == 4))
		{
			if (blip_on == 0)
			{
				ADD_BLIP_FOR_COORD(-442.551, 1692.462, 5.088, &rock_ico);
				CHANGE_BLIP_SPRITE(rock_ico, BLIP_FIRE_STATION);
				CHANGE_BLIP_SCALE(rock_ico, 1.1);
				CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "LG_19");
				blip_on = 1;
			}
			DRAW_CHECKPOINT( -442.551, 1692.462, 5.088, 1.5, 160, 116, 209);
			GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
			GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -442.551, 1692.462, 5.088, &PlayR);
			if (( PlayR < 1.5) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
			{
				G_ONMISSION = 1;
				REMOVE_BLIP(rock_ico);
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

				Ped ped1, ped2, ped3;
				Car car1;
				Cam camera;
				Texture fon;

				skip = 0;
				text1 = 0;
				text2 = 1;
				shkalaON = 0;
				shkala = 100;
				play = 0;
				HUD_x = 0.922156;
				HUD_w = 0.0739583;
				play_Speech = 0;

				uint CarM1 = MODEL_COGNOSCENTI;// Лимузин
				uint PedM1 = MODEL_IG_JEFF;// роцкер 1
				uint PedM2 = MODEL_IG_KENNY;// роцкер 2
				uint PedM3 = MODEL_IG_RICKY;// роцкер 3
				
				textur = LOAD_TXD( "sunshine_race" );
				fon = GET_TEXTURE( textur, "fon_hud" );

				REQUEST_MODEL(CarM1);
				while (!HAS_MODEL_LOADED(CarM1)) WAIT(0);
				REQUEST_MODEL(PedM1);// Таксист
				while (!HAS_MODEL_LOADED(PedM1));
				REQUEST_MODEL(PedM2);// Пассажир
				while (!HAS_MODEL_LOADED(PedM2));
				REQUEST_MODEL(PedM3);// Таксист
				while (!HAS_MODEL_LOADED(PedM3));

				FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
				FORWARD_TO_TIME_OF_DAY(19, 0);
				MUTE_GAMEWORLD_AND_POSITIONED_RADIO_FOR_TV( 1 );
				
				//------------ катсцена ----------------
				LOAD_ADDITIONAL_TEXT( "ROK_3A", 6 );
				START_CUTSCENE_NOW("rok_3a");
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

				MUTE_GAMEWORLD_AND_POSITIONED_RADIO_FOR_TV( 0 );
				CREATE_CAR(CarM1, -433.092, 1681.284, 5.453, &car1, TRUE);
				SET_CAR_HEADING(car1, 180.0);

				WARP_CHAR_INTO_CAR(GetPlayerPed(), car1);
				CREATE_CHAR_AS_PASSENGER(car1, 1, PedM1, 0, &ped1);//
				CREATE_CHAR_AS_PASSENGER(car1, 1, PedM2, 1, &ped2);//
				CREATE_CHAR_AS_PASSENGER(car1, 1, PedM3, 2, &ped3);//

				FORCE_WEATHER_NOW(WEATHER_RAINING);
				FORWARD_TO_TIME_OF_DAY(20, 00);
				RELEASE_TIME_OF_DAY();

				
				CREATE_CAM( 14, &camera );
				POINT_CAM_AT_COORD	( camera, -433.092, 1681.28, 5.56777);
				SET_CAM_POS			( camera, -436.985, 1671.16, 5.9729 );
				SET_CAM_ACTIVE( camera, 1 );
				SET_CAM_PROPAGATE( camera, 1 );
				ACTIVATE_SCRIPTED_CAMS(1, 1);
				SET_CAM_FOV( camera, 45.0 );
				SET_WIDESCREEN_BORDERS( 1 );

				// воспроизводим аудио
				NEW_SCRIPTED_CONVERSATION();
				ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
				ADD_LINE_TO_CONVERSATION(0, "R2_MD", "ROK3_1", 0, 0);//At last man, time for a well earned drink. The venue's just a hundred yards down the road.
				START_SCRIPT_CONVERSATION(1, 1);
				SetSpeech();

				NEW_SCRIPTED_CONVERSATION();
				ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
				ADD_LINE_TO_CONVERSATION(0, "R2_ME", "ROK3_2", 0, 0);//Better make it a large one then. Hey Tommy, change the tunes, man.
				START_SCRIPT_CONVERSATION(1, 1);
				SetSpeech();

				NEW_SCRIPTED_CONVERSATION();
				ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
				ADD_LINE_TO_CONVERSATION(0, "R2_MF", "ROK3_3", 0, 0);//I get confused if my head ain't banging. Ah look, what's this? Hey Tommy, stick this tape on.
				START_SCRIPT_CONVERSATION(1, 1);
				SetSpeech();

				NEW_SCRIPTED_CONVERSATION();
				ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
				ADD_LINE_TO_CONVERSATION(0, "R2_MG", "ROK3_4", 0, 0);//Love Fist. Your time polluting the airwaves is over. I gave you the chance to be friends.
				START_SCRIPT_CONVERSATION(1, 1);
				SetSpeech();

				NEW_SCRIPTED_CONVERSATION();
				ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
				ADD_LINE_TO_CONVERSATION(0, "R2_MH", "ROK3_5", 0, 0);//Now, I'm giving you the chance to die. Try to slow down and your limousine will explode, along with your BIG, HAIRY ARSES!
				START_SCRIPT_CONVERSATION(1, 1);
				SetSpeech();
				SetTime(1000);

				
				ACTIVATE_SCRIPTED_CAMS( 0, 0 );
				END_CAM_COMMANDS( &camera );
				SET_WIDESCREEN_BORDERS( 0 );
				SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );

				SETTIMERA( 0 );
				SETTIMERC( 0 );
				text2 = 1;

				while (TRUE)
				{
					WAIT(0);

					// трёп
					if (text2 == 1)
					{
						NEW_SCRIPTED_CONVERSATION();
						ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
						ADD_LINE_TO_CONVERSATION(0, "R2_MI", "ROK3_6", 0, 0);//Tommy pal, you gotta save the band! I'm getting bored of this. Just keep the pedal to the metal!!
						START_SCRIPT_CONVERSATION(1, 1);
						play_Speech = 1;
						text2 = 2;
					}
					else if (text2 == 2)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_MJ", "ROK3_7", 0, 0);//We gotta find the bomb! Can't we just drive around all day? Aye, we've got plenty to drink..
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 3;
						}
					}
					else if (text2 == 3)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_MK", "ROK3_8", 0, 0);//Won't the bomb not be in the engine? We'll have to stop to get it. We're all going to die! I'm gonna get drunk!
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 4;
						}
					}
					else if (text2 == 4)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
							ADD_LINE_TO_CONVERSATION(0, "R2_ML", "ROK3_9", 0, 0);//Hey, there's a queue here pal! The answer ain't in the drinks cabinet! Get out of my way!
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 5;
						}
					}
					else if (text2 == 5)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
							ADD_LINE_TO_CONVERSATION(0, "R2_MM", "ROK3_10", 0, 0);//Hey, the vodka bottle's got wires coming out of it! That's not vodka, that's BOOMSHINE!
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 6;
						}
					}
					else if (text2 == 6)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
							ADD_LINE_TO_CONVERSATION(0, "R2_MN", "ROK3_11", 0, 0);//WAAAAAAGGGHHHH!!!! And it's wired to blow!! WAAAAAAAAAAAAGGGHHHHHHHH!!!!
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 7;
						}
					}
					else if (text2 == 7)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_MO", "ROK3_12", 0, 0);//They always said the drink would kill me. I've seen this on the telly. you gotta pull out one of the wires. Which wire? I don't know, man.
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 8;
						}
					}
					else if (text2 == 8)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_NA", "ROK3_13", 0, 0);//I don't have a clue. Willy, say something. I'm gonna play bass in hell.
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 9;
						}
					}
					else if (text2 == 9)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_OA", "ROK3_14", 0, 0);//Tommy man, keep driving fast, pal. Somebody do something. Aye, clever!
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 10;
						}
					}
					else if (text2 == 10)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_PA", "ROK3_15", 0, 0);//'Somebody do something', what kind of crap is that, I've seen braver girls. Okay tough guy, you do something.
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 11;
						}
					}
					else if (text2 == 11)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_QB", "ROK3_16", 0, 0);//Look, man, I play a musical instrument I don't have a clue about bomb disposal. Willy could just suck the boomshine out with a straw.
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 12;
						}
					}
					else if (text2 == 12)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_QB_QQQ1", "ROK3_17", 0, 0);//Aye, I've heard that your good at that kind of thing. Hey, I was off my tits that night, as well you know!
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 13;
						}
					}
					else if (text2 == 13)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_RA", "ROK3_18", 0, 0);//Just pass Willy a straw! A straw?!?! This is the Love Fist Tour Bus!
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 14;
						}
					}
					else if (text2 == 14)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_RB", "ROK3_19", 0, 0);//Where am I gonna get a straw from, know wot I mean? Which wire, Tommy? The green one. There isn't a green one.
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 15;
						}
					}
					else if (text2 == 15)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
							ADD_LINE_TO_CONVERSATION(0, "R2_RC", "ROK3_20", 0, 0);//Or is this one green? Any of these wires look green to you?
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 16;
						}
					}
					else if (text2 == 16)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_RD", "ROK3_21", 0, 0);//Oh no! Death's on the cards! Everything looks green! I should have dumped you lot when I had the chance man.
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 17;
						}
					}
					else if (text2 == 17)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_WA", "ROK3_22", 0, 0);//Glory seeker. Capitalist. I've been carrying you for years. Shut up. You're a muppit.
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 18;
						}
					}
					else if (text2 == 18)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_WB", "ROK3_23", 0, 0);//A big screaming girl. Yeah. Shut up and pull a wire. Which wire? This one..
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 19;
						}
					}
					else if (text2 == 19)
					{
						if (play_Speech == 0)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R2_WC", "ROK3_24", 0, 0);//NO! Man, we're okay. We ain't been blown up, pal.
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 20;
							SETTIMERC( 0 );
						}
					}
					else if (text2 == 20) 
					{
						if (TIMERC() > 5000)
						{
							text2 = 21;
							SETTIMERC( 0 );
						}
					}
					if (play_Speech == 1)
					{
						if (!IS_SCRIPTED_CONVERSATION_ONGOING())
						{
							play_Speech = 0;
						}
					}

					if (!IS_CHAR_IN_CAR(GetPlayerPed(), car1))
					{
						if (text1 == 0)
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "IN_VEH", 5000, 1);//~COL_NET_12~Hey! Get back in the vehicle!
							text1 = 1;
						}
					}
					else
					{
						if (text1 == 1)
						{
							text1 = 0;
						}
					}


					if (((speed >= 20) && (shkalaON == 0)) || ((TIMERA() > 4000) && (shkalaON == 0)))
					{
						shkalaON = 1;
						SETTIMERA( 0 );
						SETTIMERB( 0 );
					}

					if (shkalaON == 1)
					{
						if (speed < 5)
						{
							if (TIMERB() > 100)
							{
								shkala += 50;
								SETTIMERB( 0 );
							}
						}
						else if (speed < 16)
						{
							if (TIMERB() > 125)
							{
								if (shkala < 300)
								{
									shkala += speed*((shkala/100)/2);
								}
								else
								{
									shkala += speed*1.5;
								}
								SETTIMERB( 0 );
							}
						}

						else if (speed >= 20)
						{
							if (shkala > 101)
							{
								if (TIMERB() > 200)
								{
									shkala -= speed;
									SETTIMERB( 0 );
								}
							}
							else
							{
								shkala = 100;
							}
						}
					}
					
					GET_CHAR_SPEED(GetPlayerPed(), &speed);

					// -------------------------- HUD --------------------------
					DRAW_SPRITE( fon, 0.8765625, 0.7838, 0.14322917, 0.0296, 0.0, 246, 151, 255, 155 );
					DRAW_SPRITE( 0, 0.915054, 0.7838, 0.059166, 0.014, 0.0, 27, 89, 130, 255 );
					if (shkala < 105)
					{
						shkalaH1 = 0;
					}
					else
					{
						shkalaH1 = shkala-100;
					}
					
					shkalaH2 = HUD_w/1000;
					shkalaH3 = shkalaH2*shkalaH1;
					shkalaHUD_y1 = HUD_w-shkalaH3;
					shkalaHUD_y2 = shkalaHUD_y1/2;
					shkalaHUD_y3 = HUD_x-shkalaHUD_y2;
					DRAW_SPRITE( 0, shkalaHUD_y3, 0.7838, shkalaH3, 0.014, 0.0, 97, 194, 247, 255 );

					SET_TEXT_COLOUR(95, 195, 247, 255);
					SET_TEXT_SCALE(0.156, 0.267);
					SET_TEXT_DROPSHADOW(1, 26, 90, 128, 255);
					DISPLAY_TEXT(0.78815097, 0.77731852, "RBM3_6"); //DETONATION:

					if (shkala >= 900)
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "RBM3_4", 5000, 1);//~r~You've killed Love Fist!
						EXPLODE_CAR(car1, 1, 1);
						skip = 1;
						break;
					}
					else if ((IS_CHAR_DEAD(ped1)) || (IS_CHAR_INJURED(ped1)) || (IS_CHAR_DEAD(ped2)) || (IS_CHAR_INJURED(ped2)) || (IS_CHAR_DEAD(ped3)) || (IS_CHAR_INJURED(ped3)))
					{
						CLEAR_PRINTS();
						PRINT_STRING_IN_STRING("string", "RBM3_4", 5000, 1);//~r~You've killed Love Fist!
						skip = 1;
						break;
					}
					else if ((HAS_DEATHARREST_EXECUTED()))
					{
						skip = 1;
						break;
					}

					if (text2 == 21)
					{
						SETTIMERA(0);
						while (true)
						{
							SET_TEXT_COLOUR(255, 159, 255, 255);
							SET_TEXT_SCALE(0.5, 0.7);
							SET_TEXT_EDGE(1, 0, 0, 0, 255);
							SET_TEXT_DROPSHADOW(1, 0, 0, 0, 200);
							SET_TEXT_CENTRE(1);
							DISPLAY_TEXT(0.5, 0.35, "RBM3_7");// пишем "Бомба обезврежина" BOMB DEFUSED!
							WAIT( 0 );
							if ( TIMERA() > 4000 )
							{
								break;
							}
						}
						text1 = 0;
						text2 = 1;
						break;
					}
					
				}
				if (skip == 0)
				{
					while (TRUE)
					{
						WAIT(0);

						// трёп
						if (text2 == 1)
						{
							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
							ADD_LINE_TO_CONVERSATION(0, "R2_XA", "ROK3_25", 0, 0);//Tommy, man, nice one. Rock and roll, man. Ain't we got a gig to go to?
							START_SCRIPT_CONVERSATION(1, 1);
							play_Speech = 1;
							text2 = 2;
						}
						else if (text2 == 2)
						{
							if (play_Speech == 0)
							{
								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
								ADD_LINE_TO_CONVERSATION(0, "R2_XB", "ROK3_26", 0, 0);//A racket to make? Groupies to abuse? LOVE FIST!
								START_SCRIPT_CONVERSATION(1, 1);
								play_Speech = 1;
								text2 = 3;
							}
						}
						else if (text2 == 3)
						{
							if (play_Speech == 0)
							{
								NEW_SCRIPTED_CONVERSATION();
								ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
								ADD_LINE_TO_CONVERSATION(0, "R2_XD", "ROK3_27", 0, 0);//Have you finished with that bottle?
								START_SCRIPT_CONVERSATION(1, 1);
								play_Speech = 1;
								text2 = 4;
							}
						}
						else if (text2 == 4)
						{
							if (play_Speech == 0)
							{
								if (TIMERC() > 2000)
								{
									text2 = 5;
									SETTIMERC( 0 );
								}
							}
						}
						else if (text2 == 5) 
						{
							if (TIMERC() > 1000)
							{
								ADD_BLIP_FOR_COORD(-439.597, 1587.51, 4.77215, &rock_ico);
								CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
								CHANGE_BLIP_COLOUR(rock_ico, 5);
								CHANGE_BLIP_SCALE(rock_ico, 0.6);
								CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_POINT");

								CLEAR_PRINTS();
								PRINT_STRING_IN_STRING("string", "RBM3_1", 5000, 1);//~g~Drive Love Fist to the venue.
								text2 = 6;
							}
						}
						if (play_Speech == 1)
						{
							if (!IS_SCRIPTED_CONVERSATION_ONGOING())
							{
								play_Speech = 0;
							}
						}

						DRAW_CHECKPOINT( -439.597, 1587.51, 4.77215, 2.0, 160, 116, 209);
						GET_CHAR_COORDINATES(GetPlayerPed(),  &PlayX, &PlayY, &PlayZ);
						GET_DISTANCE_BETWEEN_COORDS_3D( PlayX, PlayY, PlayZ, -439.597, 1587.51, 4.77215, &PlayR);
						if (( PlayR < 2.1) && (IS_CHAR_IN_CAR(GetPlayerPed(), car1)))
						{
							SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 0, 0, 0 );

							
							CREATE_CAM( 14, &camera );
							POINT_CAM_AT_COORD	( camera, -439.597, 1587.51, 5.60977);
							SET_CAM_POS			( camera, -443.717, 1572.57, 9.10312 );
							SET_CAM_ACTIVE( camera, 1 );
							SET_CAM_PROPAGATE( camera, 1 );
							ACTIVATE_SCRIPTED_CAMS(1, 1);
							SET_CAM_FOV( camera, 45.0 );
							SET_WIDESCREEN_BORDERS( 1 );
							SetTime(1000);

							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R4_AA", "ROK3_69", 0, 0);//At this rate, we'll never get to play live.
							START_SCRIPT_CONVERSATION(1, 1);
							SetSpeech();

							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "NIKO");
							ADD_LINE_TO_CONVERSATION(0, "R4_AB", "ROK3_70", 0, 0);//Oohh shite! My bowels...
							START_SCRIPT_CONVERSATION(1, 1);
							SetSpeech();

							NEW_SCRIPTED_CONVERSATION();
							ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
							ADD_LINE_TO_CONVERSATION(0, "R4_AC", "ROK3_71", 0, 0);//We gotta get on with it - thanks again Tommy, Know what I am saying, nice one, bye!
							START_SCRIPT_CONVERSATION(1, 1);
							SetSpeech();

							// роцкеры уходят
							TASK_GO_STRAIGHT_TO_COORD(ped1, -453.037, 1587.87, 7.00665, 2, -2);
							TASK_GO_STRAIGHT_TO_COORD(ped2, -453.037, 1587.87, 7.00665, 2, -2);
							TASK_GO_STRAIGHT_TO_COORD(ped3, -453.037, 1587.87, 7.00665, 2, -2);
							SetTime(6000);

							
							SET_CHAR_COORDINATES(ped1, 159.45, -679.962, 2.171);
							SET_CHAR_COORDINATES(ped2, 159.45, -681.38, 2.171);
							SET_CHAR_COORDINATES(ped3, 159.45, -682.799, 2.171);

							
							ACTIVATE_SCRIPTED_CAMS( 0, 0 );
							END_CAM_COMMANDS( &camera );
							SET_WIDESCREEN_BORDERS( 0 );
							SET_PLAYER_CONTROL_ADVANCED( GetPlayerIndex(), 1, 1, 1 );
							CLEAR_PRINTS();
							skip = 2;
							break;
						}
						else if ((IS_CHAR_DEAD(ped1)) || (IS_CHAR_INJURED(ped1)) || (IS_CHAR_DEAD(ped2)) || (IS_CHAR_INJURED(ped2)) || (IS_CHAR_DEAD(ped3)) || (IS_CHAR_INJURED(ped3)))
						{
							CLEAR_PRINTS();
							PRINT_STRING_IN_STRING("string", "RBM3_4", 5000, 1);//~r~You've killed Love Fist!
							skip = 1;
							break;
						}
						else if ((HAS_DEATHARREST_EXECUTED()))
						{
							skip = 1;
							break;
						}
						if (!IS_CHAR_IN_CAR(GetPlayerPed(), car1))
						{
							if (text1 == 0)
							{
								REMOVE_BLIP(rock_ico);
								ADD_BLIP_FOR_CAR(car1, &rock_ico);
								CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
								CHANGE_BLIP_COLOUR(rock_ico, 19);
								CHANGE_BLIP_SCALE(rock_ico, 0.6);
								CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_CAR ");
								CLEAR_PRINTS();
								PRINT_STRING_IN_STRING("string", "IN_VEH", 5000, 1);//~COL_NET_12~Hey! Get back in the vehicle!
								text1 = 1;
							}
						}
						else
						{
							if (text1 == 1)
							{
								REMOVE_BLIP(rock_ico);
								ADD_BLIP_FOR_COORD(-439.597, 1587.51, 4.77215, &rock_ico);
								CHANGE_BLIP_SPRITE(rock_ico, BLIP_OBJECTIVE);
								CHANGE_BLIP_COLOUR(rock_ico, 5);
								CHANGE_BLIP_SCALE(rock_ico, 0.6);
								CHANGE_BLIP_NAME_FROM_TEXT_FILE(rock_ico, "NE_POINT");
								CLEAR_PRINTS();
								PRINT_STRING_IN_STRING("string", "RBM3_1", 5000, 1);//~g~Drive Love Fist to the venue.
								text1 = 0;
							}
						}
					}
				}

				// чистим скрипт
				WAIT(0);
				ABORT_SCRIPTED_CONVERSATION( 0 );
				RELEASE_WEATHER();
				REMOVE_BLIP(rock_ico);

				// выгружаем из памяти
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM1);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM2);
				MARK_MODEL_AS_NO_LONGER_NEEDED(PedM3);
				MARK_MODEL_AS_NO_LONGER_NEEDED(CarM1);

				// выгружаем из памяти
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped1);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped2);
				MARK_CHAR_AS_NO_LONGER_NEEDED(&ped3);

				// выгружаем из памяти
				MARK_CAR_AS_NO_LONGER_NEEDED(&car1);

				RELEASE_TEXTURE( fon );
				REMOVE_TXD( textur );

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
						DISPLAY_TEXT_WITH_NUMBER(0.5, 0.5, "CASH", 8000);// +5000$
						
						WAIT( 0 );
						if ( TIMERA() > 4000 )
						{
							break;
						}
					}
					ADD_SCORE( GetPlayerIndex(), +8000 );
					REGISTER_MISSION_PASSED("ROCK_3");
					G_ROCK = 5;
					autosave = 1;
				}

				blip_on = 0;
				G_ONMISSION = 0;
			}
		}
		else if ((G_ONMISSION == 0) && (G_ROCK >= 5))
		{
			break;
		}
		else
		{
			if (blip_on == 1)
			{
				REMOVE_BLIP(rock_ico);
				blip_on = 0;
			}
		}
	}
}
void main(void)
{
	//THIS_SCRIPT_SHOULD_BE_SAVED();
	if (G_ROCK < 5)
	{
		rockers();
	}
	while (TRUE)
	{
		WAIT(0);
	}
	return;
}
