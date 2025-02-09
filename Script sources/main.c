#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"

Pickup tweap_1, tweap_2;
uint lawyer_n, Ammo_nan;
uint Weap1, Weap1_2, get_Weap1, Ammo1_1, Ammo1_2;
uint Weap2, Weap2_2, get_Weap2, Ammo2_1, Ammo2_2;
uint Weap3, Weap3_2, get_Weap3, Ammo3_1, Ammo3_2;
uint Weap4, Weap4_2, get_Weap4, Ammo4_1, Ammo4_2;
uint Weap5, Weap5_2, get_Weap5, Ammo5_1, Ammo5_2;
uint Weap6, Weap6_2, get_Weap6, Ammo6_1, Ammo6_2;
uint Weap7, Weap7_2, get_Weap7, Ammo7_1, Ammo7_2;
uint Weap8, Weap8_2, get_Weap8, Ammo8_1, Ammo8_2;
uint Weap9, Weap9_2, get_Weap9, Ammo9_1, Ammo9_2;
uint Weap0, Weap0_2, get_Weap0, Ammo0_1, Ammo0_2;
float cop_X, cop_Y, cop_Z, cop_R;

float playX, playY, playZ, playR, jump_ok, all_jump, speed;
float jump_1, jump_2, jump_3, jump_4, jump_5, jump_6, jump_7, jump_8, jump_9, jump_10;
float jump_11, jump_12, jump_13, jump_14, jump_15, jump_16, jump_17, jump_18, jump_19, jump_20;
float jump_21, jump_22, jump_23, jump_24, jump_25, jump_26, jump_27, jump_28, jump_29, jump_30;
float jump_31, jump_32, jump_33, jump_34, jump_35, jump_36;

Cam camera;
Car car1;

void text_jump(void)
{
	all_jump += 1;
	ADD_SCORE(GetPlayerIndex(), (all_jump * 100));//äà¸ì èãðîêó äåíåã
	SETTIMERA(0);
	SET_TEXT_COLOUR(0, 180, 130, 255);
	SET_TEXT_SCALE(0.5, 0.7);
	SET_TEXT_EDGE(1, 0, 0, 0, 255);
	SET_TEXT_DROPSHADOW(1, 0, 0, 0, 250);
	SET_TEXT_CENTRE(1);
	DISPLAY_TEXT(0.5, 0.4, "JUMPING_T1");// ïèøåì "Âûïîëíåí óíèêàëüíûé ïðèæîê"
	SET_TEXT_COLOUR(55, 95, 125, 255);
	SET_TEXT_SCALE(0.45, 0.65);
	SET_TEXT_EDGE(1, 0, 0, 0, 255);
	SET_TEXT_DROPSHADOW(1, 0, 0, 0, 250);
	SET_TEXT_CENTRE(1);
	DISPLAY_TEXT_WITH_NUMBER(0.5, 0.45, "JUMPING_T2", (all_jump * 100));// òåêñò "íàãðàäà $~1~"
}
void look_jump(float cam_x, float cam_y, float cam_z)
{
	CREATE_CAM(14, &camera);
	POINT_CAM_AT_COORD(camera, playX, playY, playZ);
	SET_CAM_POS(camera, cam_x, cam_y, cam_z);
	SET_CAM_FOV(camera, 60.20001000);
	SET_CAM_ACTIVE(camera, 1);
	SET_CAM_PROPAGATE(camera, 1);
	ACTIVATE_SCRIPTED_CAMS(1, 1);
	SET_WIDESCREEN_BORDERS(1);
	SETTIMERA(0);
	SET_TIME_SCALE(0.35);
	STORE_CAR_CHAR_IS_IN_NO_SAVE(GetPlayerPed(), &car1);

	if (IS_CAR_IN_AIR_PROPER(car1))
	{
		GET_CHAR_COORDINATES(GetPlayerPed(), &playX, &playY, &playZ);
		POINT_CAM_AT_COORD(camera, playX, playY, playZ);
		DISABLE_PAUSE_MENU(1);
		if ((!IS_CAR_IN_AIR_PROPER(car1)) && (TIMERA() > 150) || (TIMERA() > 3000))
		{
			if (TIMERA() < 1000)
			{
				jump_ok = 0;
			}
			else
			{
				jump_ok = 1;
			}
		}
	}

	ACTIVATE_SCRIPTED_CAMS(0, 0);
	DESTROY_CAM(camera);
	SET_WIDESCREEN_BORDERS(0);
	SET_TIME_SCALE(1.0);
	if (jump_ok == 1)
	{
		text_jump();
	}
}
void jump(void)
{
	GET_CHAR_COORDINATES(GetPlayerPed(), &playX, &playY, &playZ);//âïèñûâàåì êîîðäèíàòû èãðîêà â ïåðåìåííóþ
	GET_CHAR_SPEED(GetPlayerPed(), &speed);
	//DISPLAY_TEXT_WITH_NUMBER(0.9083334, 0.72787074, "CP_TIME_NOZERO", speed);// 

	//===================== jump_1 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -1054.781, -511.546, 12.707, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_1 == 0))
	{
		look_jump(-1088.964, -506.8505, 18.1338);
		if (jump_ok == 1)
		{
			jump_1 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_2 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -919.695, -222.212, 22.673, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_2 == 0))
	{
		look_jump(-927.8242, -248.5606, 31.2329);
		if (jump_ok == 1)
		{
			jump_2 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_3 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -783.49, -378.833, 13, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_3 == 0))
	{
		look_jump(-767.2437, -361.1972, 20.7296);
		if (jump_ok == 1)
		{
			jump_3 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_4 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -819.139, -521.685, 16.016, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_4 == 0))
	{
		look_jump(-761.279, -494.8624, 16.979);
		if (jump_ok == 1)
		{
			jump_4 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_5 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -1118.685, -542.674, 13.121, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_5 == 0))
	{
		look_jump(-1087.165, -540.3603, 18.1604);
		if (jump_ok == 1)
		{
			jump_5 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_6 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -1162.712, -739.881, 13.068, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_6 == 0))
	{
		look_jump(-1131.454, -738.5879, 15.5915);
		if (jump_ok == 1)
		{
			jump_6 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_7 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -1120.337, -697.952, 11.194, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_7 == 0))
	{
		look_jump(-1157.58, -714.3733, 20.3087);
		if (jump_ok == 1)
		{
			jump_7 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_8 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -907.022, -465.257, 13.115, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_8 == 0))
	{
		look_jump(-922.2749, -464.9999, 18.0731);
		if (jump_ok == 1)
		{
			jump_8 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_9 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 457.721, 1430.801, 19.103, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_9 == 0))
	{
		look_jump(433.1404, 1411.404, 14.2009);
		if (jump_ok == 1)
		{
			jump_9 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_10 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 111.972, -846.4981, 4.929, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_10 == 0))
	{
		look_jump(121.9503, -866.5061, 3.6779);
		if (jump_ok == 1)
		{
			jump_10 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_11 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 111.972, -743.589, 4.929, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_11 == 0))
	{
		look_jump(118.4064, -767.2807, 3.4204);
		if (jump_ok == 1)
		{
			jump_11 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_12 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -241.345, 1695.422, 23.916, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_12 == 0))
	{
		look_jump(-257.7014, 1732.213, 19.0565);
		if (jump_ok == 1)
		{
			jump_12 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_13 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -96.84003, 1363.062, 92.71701, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_13 == 0))
	{
		look_jump(-110.2, 1376.4, 93.2);
		if (jump_ok == 1)
		{
			jump_13 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_14 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -406.022, 1686.526, 25.94, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 18) && (jump_14 == 0))
	{
		look_jump(-420.7, 1705.3, 18.4);
		if (jump_ok == 1)
		{
			jump_14 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_15 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 120.553, 1642.196, 41.741, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_15 == 0))
	{
		look_jump(140.5, 1635.7, 34);
		if (jump_ok == 1)
		{
			jump_15 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_16 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -578.583, 502.902, 9.181, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_16 == 0))
	{
		look_jump(-571.154, 470.0057, 9.957);
		if (jump_ok == 1)
		{
			jump_16 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_17 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -509.702, 418.494, 9.181, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_17 == 0))
	{
		look_jump(-497.7841, 407.5568, 6.218799);
		if (jump_ok == 1)
		{
			jump_17 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_18 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -467.789, 793.804, 9.915, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_18 == 0))
	{
		look_jump(-473.6896, 771.6933, 10.5044);
		if (jump_ok == 1)
		{
			jump_18 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_19 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, -608.895, -36.323, 15.855, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 14) && (jump_19 == 0))
	{
		look_jump(-622.6156, -55.86133, 12.1929);
		if (jump_ok == 1)
		{
			jump_19 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_20 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 641.993, -430.672, 13.967, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_20 == 0))
	{
		look_jump(666.5752, -427.8961, 15.5283);
		if (jump_ok == 1)
		{
			jump_20 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_21 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 479.115, -431.415, 19.883, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_21 == 0))
	{
		look_jump(496.3356, -434.6796, 22.5317);
		if (jump_ok == 1)
		{
			jump_21 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_22 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 543.481, -697.6, 29.67, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_22 == 0))
	{
		look_jump(517.5247, -725.3891, 25.4335);
		if (jump_ok == 1)
		{
			jump_22 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_23 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 440.435, -712.895, 11.752, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_23 == 0))
	{
		look_jump(437.1501, -741.4602, 13.7525);
		if (jump_ok == 1)
		{
			jump_23 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_24 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 442.103, -793.505, 14.361, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 16) && (jump_24 == 0))
	{
		look_jump(426.5163, -822.1759, 14.045);
		if (jump_ok == 1)
		{
			jump_24 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_25 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 651.05, -619, 6.84, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_25 == 0))
	{
		look_jump(661.2427, -607.774, 8.4116);
		if (jump_ok == 1)
		{
			jump_25 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_26 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 692.0561, -412.833, 6.84, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_26 == 0))
	{
		look_jump(692.0202, -430.3474, 5.296);
		if (jump_ok == 1)
		{
			jump_26 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_27 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 717.4732, 38.88571, 10, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_27 == 0))
	{
		look_jump(701.9545, 63.37839, 9.2438);
		if (jump_ok == 1)
		{
			jump_27 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_28 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 803.7901, -176.863, 13.895, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_28 == 0))
	{
		look_jump(794.3011, -202.6794, 17.4501);
		if (jump_ok == 1)
		{
			jump_28 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_29 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 894.589, 10.77002, 12.931, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_29 == 0))
	{
		look_jump(859.6391, 8.953125, 6.3656);
		if (jump_ok == 1)
		{
			jump_29 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_30 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 887.1049, 28.26401, 12.931, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_30 == 0))
	{
		look_jump(889.6417, 0.9078979, 13.3283);
		if (jump_ok == 1)
		{
			jump_30 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_31 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 893.91, 149.638, 8.222, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_31 == 0))
	{
		look_jump(895.6723, 133.1857, 12.049);
		if (jump_ok == 1)
		{
			jump_31 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_32 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 692.041, 52.392, 8.688, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_32 == 0))
	{
		look_jump(715.5344, 53.15881, 4.4141);
		if (jump_ok == 1)
		{
			jump_32 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_33 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 750.2051, 309.7988, 36.3731, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 17) && (jump_33 == 0))
	{
		look_jump(734.9448, 317.0932, 28.4501);
		if (jump_ok == 1)
		{
			jump_33 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_34 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 877.5, 414.6, 10, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_34 == 0))
	{
		look_jump(849.4033, 407.3275, 7.7649);
		if (jump_ok == 1)
		{
			jump_34 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_35 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 868.8542, 198.6788, 9.897701, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 19) && (jump_35 == 0))
	{
		look_jump(853.6179, 165.4967, 8.1343);
		if (jump_ok == 1)
		{
			jump_35 = 1;
			jump_ok = 0;
		}
	}
	//===================== jump_36 =====================
	GET_DISTANCE_BETWEEN_COORDS_3D(playX, playY, playZ, 86.18201, 242.259, 6.926, &playR); //
	if ((IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())) && (playR < 3.6) && (speed > 13) && (jump_36 == 0))
	{
		look_jump(115.9934, 234.211, 9.3976);
		if (jump_ok == 1)
		{
			jump_36 = 1;
			jump_ok = 0;
		}
	}

	if (all_jump == 36)
	{
		G_JUMP = 1;
	}
}

int i, isActivated;
int c[30];
int cur;
float timeScale = 1.0;

void ChangeLetterPos(void) {
	isActivated = false;
	for (i = 1; i < 30; i++) {
		c[i - 1] = c[i];
	}
	c[29] = cur;
	return;
}
void UpdateKeys(void) {
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(16)) {
		cur = 16;
		ChangeLetterPos();
	}
	else
		if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(17)) {
			cur = 17;
			ChangeLetterPos();
		}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(18)) {
		cur = 18;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(19)) {
		cur = 19;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(20)) {
		cur = 20;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(21)) {
		cur = 21;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(22)) {
		cur = 22;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(23)) {
		cur = 23;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(24)) {
		cur = 24;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(25)) {
		cur = 25;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(30)) {
		cur = 30;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(31)) {
		cur = 31;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(32)) {
		cur = 32;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(33)) {
		cur = 33;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(34)) {
		cur = 34;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(35)) {
		cur = 35;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(36)) {
		cur = 36;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(37)) {
		cur = 37;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(38)) {
		cur = 38;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(44)) {
		cur = 44;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(45)) {
		cur = 45;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(46)) {
		cur = 46;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(47)) {
		cur = 47;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(48)) {
		cur = 48;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(49)) {
		cur = 49;
		ChangeLetterPos();
	}
	if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(50)) {
		cur = 50;
		ChangeLetterPos();
	}
	if ((IS_GAME_KEYBOARD_KEY_JUST_PRESSED(57)) || (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(26)) || (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(27)) || (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(39)) || (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(40)) || (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(51)) || (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(52)) || (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(53))) {
		cur = 0;
		ChangeLetterPos();
	}
	return;
}
void CreateCar(char* name) {
	int ccar;
	float x, y, z, h, px, py;
	REQUEST_MODEL(GET_HASH_KEY(name));
	while (!HAS_MODEL_LOADED(GET_HASH_KEY(name))) {
		WAIT(0);
	}
	GET_CHAR_COORDINATES(GetPlayerPed(), &x, &y, &z);
	GET_CHAR_HEADING(GetPlayerPed(), &h);
	h += 90.0;
	px = x + COS(h) * 6.0;
	py = y + SIN(h) * 6.0;
	h -= 180.0;
	CREATE_CAR(GET_HASH_KEY(name), px, py, z, &ccar, 1);
	SET_CAR_HEADING(ccar, h);
	MARK_CAR_AS_NO_LONGER_NEEDED(&ccar);
	MARK_MODEL_AS_NO_LONGER_NEEDED(GET_HASH_KEY(name));
	PRINT_HELP("CHEAT1");
	isActivated = true;
	return;
}
void cheats(void)
{
	if (ALLOW_ONE_TIME_ONLY_COMMANDS_TO_RUN)
	{
		isActivated = false;
		for (i = 0; i < 30; i++)
		{
			c[i] = 0;
		}
		int a[30];
	}
	if (IS_PLAYER_PLAYING(GetPlayerIndex()))
	{
		UpdateKeys();
		if (!isActivated) {
			// GETTHEREFAST - спавн Sabre
			if ((c[18] == 34) && (c[19] == 18) && (c[20] == 20) && (c[21] == 20) && (c[22] == 35) && (c[23] == 18) && (c[24] == 19) && (c[25] == 18) && (c[26] == 33) && (c[27] == 30) && (c[28] == 31) && (c[29] == 20)) {
				CreateCar("sabregt");
				// RUBBISHCAR - спавн мусоровоза
			}
			else if ((c[20] == 19) && (c[21] == 22) && (c[22] == 48) && (c[23] == 48) && (c[24] == 23) && (c[25] == 31) && (c[26] == 35) && (c[27] == 46) && (c[28] == 30) && (c[29] == 19)) {
				CreateCar("trash");
				// BETTERTHANWALKING - спавн гольфкара	
			}
			else if ((c[13] == 48) && (c[14] == 18) && (c[15] == 20) && (c[16] == 20) && (c[17] == 18) && (c[18] == 19) && (c[19] == 20) && (c[20] == 35) && (c[21] == 30) && (c[22] == 49) && (c[23] == 17) && (c[24] == 30) && (c[25] == 38) && (c[26] == 37) && (c[27] == 23) && (c[28] == 49) && (c[29] == 34)) {
				CreateCar("huntley");
				// GETTHEREVERYFASTINDEED - спавн Hotring A	
			}
			else if ((c[8] == 34) && (c[9] == 18) && (c[10] == 20) && (c[11] == 20) && (c[12] == 35) && (c[13] == 18) && (c[14] == 19) && (c[15] == 18) && (c[16] == 47) && (c[17] == 18) && (c[18] == 19) && (c[19] == 21) && (c[20] == 33) && (c[21] == 30) && (c[22] == 31) && (c[23] == 20) && (c[24] == 23) && (c[25] == 49) && (c[26] == 32) && (c[27] == 18) && (c[28] == 18) && (c[29] == 32)) {
				CreateCar("chavos");
				// GETTHEREAMAZINGLYFAST - спавн Hotring B
			}
			else if ((c[9] == 34) && (c[10] == 18) && (c[11] == 20) && (c[12] == 20) && (c[13] == 35) && (c[14] == 18) && (c[15] == 19) && (c[16] == 18) && (c[17] == 30) && (c[18] == 50) && (c[19] == 30) && (c[20] == 44) && (c[21] == 23) && (c[22] == 49) && (c[23] == 34) && (c[24] == 38) && (c[25] == 21) && (c[26] == 33) && (c[27] == 30) && (c[28] == 31) && (c[29] == 20)) {
				CreateCar("feroci");
				// ROCKANDROLLCAR - спавн лимузина	
			}
			else if ((c[16] == 19) && (c[17] == 24) && (c[18] == 46) && (c[19] == 37) && (c[20] == 30) && (c[21] == 49) && (c[22] == 32) && (c[23] == 19) && (c[24] == 24) && (c[25] == 38) && (c[26] == 38) && (c[27] == 46) && (c[28] == 30) && (c[29] == 19)) {
				CreateCar("stretch");
				// THELASTRIDE - спавн катафалка	
			}
			else if ((c[19] == 20) && (c[20] == 35) && (c[21] == 18) && (c[22] == 38) && (c[23] == 30) && (c[24] == 31) && (c[25] == 20) && (c[26] == 19) && (c[27] == 23) && (c[28] == 32) && (c[29] == 18)) {
				CreateCar("romero");
				// GETTHEREQUICKLY - спавн первой тачки из Bloodring
			}
			else if ((c[15] == 34) && (c[16] == 18) && (c[17] == 20) && (c[18] == 20) && (c[19] == 35) && (c[20] == 18) && (c[21] == 19) && (c[22] == 18) && (c[23] == 16) && (c[24] == 22) && (c[25] == 23) && (c[26] == 46) && (c[27] == 37) && (c[28] == 38) && (c[29] == 21)) {
				CreateCar("willard");
				// TRAVELINSTYLE - спавн второй тачки из Bloodring
			}
			else if ((c[17] == 20) && (c[18] == 19) && (c[19] == 30) && (c[20] == 47) && (c[21] == 18) && (c[22] == 38) && (c[23] == 23) && (c[24] == 49) && (c[25] == 31) && (c[26] == 20) && (c[27] == 21) && (c[28] == 38) && (c[29] == 18)) {
				CreateCar("peyote");
				// PANZER - спавн танка	
			}
			else if ((c[24] == 25) && (c[25] == 30) && (c[26] == 49) && (c[27] == 44) && (c[28] == 18) && (c[29] == 19)) {
				CreateCar("pstockade");
				// ASPIRINE - восстановление жизни	
			}
			else if ((c[22] == 30) && (c[23] == 31) && (c[24] == 25) && (c[25] == 23) && (c[26] == 19) && (c[27] == 23) && (c[28] == 49) && (c[29] == 18)) {
				SET_CHAR_HEALTH(GetPlayerPed(), 1000);
				if (IS_CHAR_IN_ANY_CAR(GetPlayerPed())) {
					int hcar;
					STORE_CAR_CHAR_IS_IN_NO_SAVE(GetPlayerPed(), &hcar);
					SET_ENGINE_HEALTH(hcar, 1500);
					MARK_CAR_AS_NO_LONGER_NEEDED(&hcar);
				}
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// PRECIOUSPROTECTION - броня
			}
			else if ((c[12] == 25) && (c[13] == 19) && (c[14] == 18) && (c[15] == 46) && (c[16] == 23) && (c[17] == 24) && (c[18] == 22) && (c[19] == 31) && (c[20] == 25) && (c[21] == 19) && (c[22] == 24) && (c[23] == 20) && (c[24] == 18) && (c[25] == 46) && (c[26] == 20) && (c[27] == 23) && (c[28] == 24) && (c[29] == 49)) {
				ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// THUGSTOOLS - первый пак с оружием
			}
			else if ((c[20] == 20) && (c[21] == 35) && (c[22] == 22) && (c[23] == 34) && (c[24] == 31) && (c[25] == 20) && (c[26] == 24) && (c[27] == 24) && (c[28] == 38) && (c[29] == 31)) {
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_PISTOL);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_SHOTGUN);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MICRO_UZI);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_BASEBALLBAT);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MOLOTOV);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// PROFESSIONALTOOLS - второй пак с оружием
			}
			else if ((c[13] == 25) && (c[14] == 19) && (c[15] == 24) && (c[16] == 33) && (c[17] == 18) && (c[18] == 31) && (c[19] == 31) && (c[20] == 23) && (c[21] == 24) && (c[22] == 49) && (c[23] == 30) && (c[24] == 38) && (c[25] == 20) && (c[26] == 24) && (c[27] == 24) && (c[28] == 38) && (c[29] == 31)) {
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_DEAGLE);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_SHOTGUN);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MP5);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_KNIFE);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_GRENADE);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// NUTTERTOOLS - третий пак с оружием
			}
			else if ((c[19] == 49) && (c[20] == 22) && (c[21] == 20) && (c[22] == 20) && (c[23] == 18) && (c[24] == 19) && (c[25] == 20) && (c[26] == 24) && (c[27] == 24) && (c[28] == 38) && (c[29] == 31)) {
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_DEAGLE);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_SNIPERRIFLE);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_M4);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_EPISODIC_22);
				UpdateWeaponOfPed(GetPlayerPed(), WEAPON_RLAUNCHER);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// LEAVEMEALONE - убрать звезды розыска
			}
			else if ((c[18] == 38) && (c[19] == 18) && (c[20] == 30) && (c[21] == 47) && (c[22] == 18) && (c[23] == 50) && (c[24] == 18) && (c[25] == 30) && (c[26] == 38) && (c[27] == 24) && (c[28] == 49) && (c[29] == 18)) {
				CLEAR_WANTED_LEVEL(GetPlayerIndex());
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// YOUWONTTAKEMEALIVE - добавить две звезды
			}
			else if ((c[12] == 21) && (c[13] == 24) && (c[14] == 22) && (c[15] == 17) && (c[16] == 24) && (c[17] == 49) && (c[18] == 20) && (c[19] == 20) && (c[20] == 30) && (c[21] == 37) && (c[22] == 18) && (c[23] == 50) && (c[24] == 18) && (c[25] == 30) && (c[26] == 38) && (c[27] == 23) && (c[28] == 47) && (c[29] == 18)) {
				int wl;
				STORE_WANTED_LEVEL(GetPlayerIndex(), &wl);
				wl += 2;
				if (wl > 6) {
					wl = 6;
				}
				ALTER_WANTED_LEVEL(GetPlayerIndex(), wl);
				APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// ICANTTAKEITANYMORE - игрок умирает
			}
			else if ((c[12] == 23) && (c[13] == 46) && (c[14] == 30) && (c[15] == 49) && (c[16] == 20) && (c[17] == 20) && (c[18] == 30) && (c[19] == 37) && (c[20] == 18) && (c[21] == 23) && (c[22] == 20) && (c[23] == 30) && (c[24] == 49) && (c[25] == 21) && (c[26] == 50) && (c[27] == 24) && (c[28] == 19) && (c[29] == 18)) {
				EXPLODE_CHAR_HEAD(GetPlayerPed());
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// ABITDRIEG - облачная погода
			}
			else if ((c[21] == 30) && (c[22] == 48) && (c[23] == 23) && (c[24] == 20) && (c[25] == 32) && (c[26] == 19) && (c[27] == 23) && (c[28] == 18) && (c[29] == 34)) {
				FORCE_WEATHER_NOW(WEATHER_CLOUDY);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// APLEASANTDAY - хорошая погода
			}
			else if ((c[18] == 30) && (c[19] == 25) && (c[20] == 38) && (c[21] == 18) && (c[22] == 30) && (c[23] == 31) && (c[24] == 30) && (c[25] == 49) && (c[26] == 20) && (c[27] == 32) && (c[28] == 30) && (c[29] == 21)) {
				FORCE_WEATHER_NOW(WEATHER_SUNNY);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// ALOVELYDAY - ясная погода
			}
			else if ((c[20] == 30) && (c[21] == 38) && (c[22] == 24) && (c[23] == 47) && (c[24] == 18) && (c[25] == 38) && (c[26] == 21) && (c[27] == 32) && (c[28] == 30) && (c[29] == 21)) {
				FORCE_WEATHER_NOW(WEATHER_EXTRA_SUNNY);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// CATSANDDOGS - дождливая погода
			}
			else if ((c[19] == 46) && (c[20] == 30) && (c[21] == 20) && (c[22] == 31) && (c[23] == 30) && (c[24] == 49) && (c[25] == 32) && (c[26] == 32) && (c[27] == 24) && (c[28] == 34) && (c[29] == 31)) {
				FORCE_WEATHER_NOW(WEATHER_RAINING);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// CANTSEEATHING - туманная погода
			}
			else if ((c[17] == 46) && (c[18] == 30) && (c[19] == 49) && (c[20] == 20) && (c[21] == 31) && (c[22] == 18) && (c[23] == 18) && (c[24] == 30) && (c[25] == 20) && (c[26] == 35) && (c[27] == 23) && (c[28] == 49) && (c[29] == 34)) {
				FORCE_WEATHER_NOW(WEATHER_FOGGY);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// BIGBANG - взорвать все машины
			}
			else if ((c[23] == 48) && (c[24] == 23) && (c[25] == 34) && (c[26] == 48) && (c[27] == 30) && (c[28] == 49) && (c[29] == 34)) {
				int j, k, bcar;
				float px, py, pz;
				GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
				for (j = 0; j < 20; j++) {
					for (k = 0; k < 20; k++) {
						bcar = GET_CLOSEST_CAR(px + (j * 10 - 100), py + (k * 10 - 100), pz, 300.0, 0, 69);
						if (DOES_VEHICLE_EXIST(bcar)) {
							EXPLODE_CAR(bcar, 1, 0);
							MARK_CAR_AS_NO_LONGER_NEEDED(&bcar);
						}
					}
				}
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// ONSPEED - ускорить время игры
			}
			else if ((c[23] == 24) && (c[24] == 49) && (c[25] == 31) && (c[26] == 25) && (c[27] == 18) && (c[28] == 18) && (c[29] == 32)) {
				timeScale += 0.2;
				if (timeScale > 2.4) {
					timeScale = 2.4;
				}
				SET_TIME_SCALE(timeScale);
				PRINT_HELP("CHEAT1");
				isActivated = true;
				// BOOOOOORING - замедлить время игры
			}
			else if ((c[19] == 48) && (c[20] == 24) && (c[21] == 24) && (c[22] == 24) && (c[23] == 24) && (c[24] == 24) && (c[25] == 24) && (c[26] == 19) && (c[27] == 23) && (c[28] == 49) && (c[29] == 34)) {
				timeScale -= 0.2;
				if (timeScale <= 0.0) {
					timeScale = 0.2;
				}
				SET_TIME_SCALE(timeScale);
				PRINT_HELP("CHEAT1");
				isActivated = true;
			}
		}
	}
}

void SetTime(uint time)
{
	SETTIMERA( 0 );
	while(true)
	{
		WAIT(0);
		if ((TIMERA() > time) || (HAS_DEATHARREST_EXECUTED()))
		{
			break;
		}
	}
}
void get_weap(int ID_scan)
{
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 1, &get_Weap1, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 2, &get_Weap2, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 3, &get_Weap3, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 4, &get_Weap4, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 5, &get_Weap5, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 6, &get_Weap6, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 7, &get_Weap7, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 8, &get_Weap8, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 9, &get_Weap9, &Ammo_nan, &Ammo_nan);
	GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 0, &get_Weap0, &Ammo_nan, &Ammo_nan);

	if (ID_scan == 1)
	{
		if (get_Weap1 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 1, &Weap1, &Ammo1_1, &Ammo_nan);
		}
		if (get_Weap2 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 2, &Weap2, &Ammo2_1, &Ammo_nan);
		}
		if (get_Weap3 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 3, &Weap3, &Ammo3_1, &Ammo_nan);
		}
		if (get_Weap4 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 4, &Weap4, &Ammo4_1, &Ammo_nan);
		}
		if (get_Weap5 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 5, &Weap5, &Ammo5_1, &Ammo_nan);
		}
		if (get_Weap6 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 6, &Weap6, &Ammo6_1, &Ammo_nan);
		}
		if (get_Weap7 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 7, &Weap7, &Ammo7_1, &Ammo_nan);
		}
		if (get_Weap8 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 8, &Weap8, &Ammo8_1, &Ammo_nan);
		}
		if (get_Weap9 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 9, &Weap9, &Ammo9_1, &Ammo_nan);
		}
		if (get_Weap0 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 0, &Weap0, &Ammo0_1, &Ammo_nan);
		}
		if (DOES_PICKUP_EXIST(tweap_1))
		{
			REMOVE_PICKUP(tweap_1);
		}
		CREATE_PICKUP_ROTATE(vc_weap_basket, 3, 0, 527.01, 799.434, 16.5562, 0.0, 0.0, 0.0, &tweap_1);
	}
	else if ((ID_scan == 2) || (ID_scan == 3)) 
	{
		if (get_Weap1 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 1, &Weap1_2, &Ammo1_2, &Ammo_nan);
		}
		if (get_Weap2 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 2, &Weap2_2, &Ammo2_2, &Ammo_nan);
		}
		if (get_Weap3 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 3, &Weap3_2, &Ammo3_2, &Ammo_nan);
		}
		if (get_Weap4 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 4, &Weap4_2, &Ammo4_2, &Ammo_nan);
		}
		if (get_Weap5 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 5, &Weap5_2, &Ammo5_2, &Ammo_nan);
		}
		if (get_Weap6 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 6, &Weap6_2, &Ammo6_2, &Ammo_nan);
		}
		if (get_Weap7 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 7, &Weap7_2, &Ammo7_2, &Ammo_nan);
		}
		if (get_Weap8 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 8, &Weap8_2, &Ammo8_2, &Ammo_nan);
		}
		if (get_Weap9 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 9, &Weap9_2, &Ammo9_2, &Ammo_nan);
		}
		if (get_Weap0 != 0)
		{
			GET_CHAR_WEAPON_IN_SLOT(GetPlayerPed(), 0, &Weap0_2, &Ammo0_2, &Ammo_nan);
		}

		if (DOES_PICKUP_EXIST(tweap_2))
		{
			REMOVE_PICKUP(tweap_2);
		}
		if (ID_scan == 2)
		{
			CREATE_PICKUP_ROTATE(vc_weap_basket, 3, 0, -974.819, -294.504, 8.84402, 0.0, 0.0, -135.0, &tweap_2);
		}
		else if (ID_scan == 3)
		{
			CREATE_PICKUP_ROTATE(vc_weap_basket, 3, 0, -1026.69, -298.557, 8.84074, 0.0, 0.0, -40.0, &tweap_2);
		}
	}
	REMOVE_ALL_CHAR_WEAPONS(GetPlayerPed());
	while (TRUE) 
	{
		WAIT(0);
		if ((!IS_CHAR_IN_AREA_2D(GetPlayerPed(), 532.444, 800.618, 522.444, 800.962, 0)) && (!IS_CHAR_IN_AREA_2D(GetPlayerPed(), -974.18, -299.184, -974.749, -299.524, 0)) && (!IS_CHAR_IN_AREA_2D(GetPlayerPed(), -1031.328, -298.285, -1032.396, -298.624, 0)))
		{
			break;
		}
	}
}
void lawyer(void)
{
	while (TRUE) 
	{
		WAIT(0);
		if (!HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()))
		{
			break;
		}
	}
	SET_CHAR_COORDINATES(GetPlayerPed(), cop_X, cop_Y, cop_Z);
	SET_CHAR_HEADING(GetPlayerPed(), cop_R);
	SetTime(2000);
	GENERATE_RANDOM_INT_IN_RANGE( 1, 15, &lawyer_n);
	if ((lawyer_n == 1) || (lawyer_n == 6) || (lawyer_n == 11))
	{
		NEW_SCRIPTED_CONVERSATION();
		ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
		ADD_LINE_TO_CONVERSATION(0, "R8_CA", "", 0, 0);
		START_SCRIPT_CONVERSATION(1, 1);
	}
	else if ((lawyer_n == 2) || (lawyer_n == 7) || (lawyer_n == 12))
	{
		NEW_SCRIPTED_CONVERSATION();
		ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
		ADD_LINE_TO_CONVERSATION(0, "R8_DA", "", 0, 0);
		START_SCRIPT_CONVERSATION(1, 1);
	}
	else if ((lawyer_n == 3) || (lawyer_n == 8) || (lawyer_n == 13))
	{
		NEW_SCRIPTED_CONVERSATION();
		ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
		ADD_LINE_TO_CONVERSATION(0, "R8_EA", "", 0, 0);
		START_SCRIPT_CONVERSATION(1, 1);
	}
	else if ((lawyer_n == 4) || (lawyer_n == 9) || (lawyer_n == 14))
	{
		NEW_SCRIPTED_CONVERSATION();
		ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
		ADD_LINE_TO_CONVERSATION(0, "R8_ZA", "", 0, 0);
		START_SCRIPT_CONVERSATION(1, 1);
	}
	else if ((lawyer_n == 5) || (lawyer_n == 10) || (lawyer_n == 15))
	{
		NEW_SCRIPTED_CONVERSATION();
		ADD_NEW_CONVERSATION_SPEAKER(0, GetPlayerPed(), "ROMAN");
		ADD_LINE_TO_CONVERSATION(0, "R8_A_AA", "", 0, 0);
		START_SCRIPT_CONVERSATION(1, 1);
	}
}

float saving, text_on, X, Y, Z, R;
void save(void)
{
	//=========================== Printworks ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -643.221, 244.286, 5.832, -646.473, 246.34, 9.572, 0)) && (G_ONMISSION == 0) && (G_COUNT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 1;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = -645.084;
			Y = 246.738;
			Z = 6.27582;
			R = -5.0;
			saving = 1;
			G_SAVE_SAVED = 1;
		}
	}
	else
	{
		if (text_on == 1)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== Sunshine Autos ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -595.019, -317.531, 6.782, -598.862, -313.54, 10.782, 0)) && (G_ONMISSION == 0) && (G_BUSINES_SA > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 2;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = -595.363;
			Y = -318.285;
			Z = 7.53234;
			R = -150.0;
			saving = 1;
			G_SAVE_SAVED = 2;
		}
	}
	else
	{
		if (text_on == 2)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== Interglobal Films ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 349.382, 1463.778, 4.527, 346.333, 1467.335, 8.02, 0)) && (G_ONMISSION == 0) && (G_PRON > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 3;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 346.101;
			Y = 1464.79;
			Z = 5.03874;
			R = 125.0;
			saving = 1;
			G_SAVE_SAVED = 3;
		}
	}
	//äèâàí
	else if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 344.294, 1471.025, 4.527, 342.19, 1473.941, 8.02, 0)) && (G_ONMISSION == 0) && (G_PRON > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 3;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 341.992;
			Y = 1471.62;
			Z = 5.03874;
			R = 125.0;
			saving = 1;
			G_SAVE_SAVED = 3;
		}
	}
	else
	{
		if (text_on == 3)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== Cherry Popper Icecreams ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -445.067, -47.23, 4.972, -447.067, -4.102, 8.562, 0)) && (G_ONMISSION == 0) && (G_ICECREAM > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 4;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = -444.516;
			Y = -45.5149;
			Z = 5.47654;
			R = -80.0;
			saving = 1;
			G_SAVE_SAVED = 4;
		}
	}
	else
	{
		if (text_on == 4)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== Kaufman Cabs ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -564.786, 719.034, 5.225, -566.732, 722.27, 9.459, 0)) && (G_ONMISSION == 0) && (G_CABS > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 5;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = -567.321;
			Y = 720.751;
			Z = 5.67434;
			R = 60.0;
			saving = 1;
			G_SAVE_SAVED = 5;
		}
	}
	else
	{
		if (text_on == 5)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== Malibu Club ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 897.958, 479.305, 9.559, 893.964, 483.173, 12.29, 0)) && (G_ONMISSION == 0) && (G_CLUB > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 6;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 896.001;
			Y = 479.025;
			Z = 9.93599;
			R = -175.0;
			saving = 1;
			G_SAVE_SAVED = 6;
		}
	}
	else
	{
		if (text_on == 6)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== The Boatyard ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -234.66, -952.034, 7.566, -236.961, -949.769, 11.824, 0)) && (G_ONMISSION == 0) && (G_COKERUN > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 7;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = -235.225;
			Y = -949.423;
			Z = 8.07865;
			R = -25.0;
			saving = 1;
			G_SAVE_SAVED = 7;
		}
	}
	else
	{
		if (text_on == 7)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== Pole Position Club ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 508.048, -917.682, 4.345, 505.62, -915.054, 7.33, 0)) && (G_ONMISSION == 0) && (G_STRIP > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 8;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 507.606;
			Y = -917.858;
			Z = 4.84248;
			R = -175.0;
			saving = 1;
			G_SAVE_SAVED = 8;
		}
	}
	else
	{
		if (text_on == 8)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== El Swanko Casa ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 863.972, 1132.26, 6.177, 858.972, 1137.26, 11.177, 0)) && (G_ONMISSION == 0) && (G_SWANKO > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		X = 861.53;
		Y = 1139.81;
		Z = 6.99313;
		R = 0.0;
		saving = 1;
		G_SAVE_SAVED = 9;
	}
	//=========================== Links View Apartment ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 736.09, 906.963, 6.693, 731.09, 911.963, 11.693, 0)) && (G_ONMISSION == 0) && (G_LINKS > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		X = 737.991;
		Y = 909.371;
		Z = 7.45291;
		R = -85.0;
		saving = 1;
		G_SAVE_SAVED = 10;
	}
	//=========================== Hyman Condo ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -400.854, 1841.342, 5.229, -404.119, 1845.572, 10.229, 0)) && (G_ONMISSION == 0) && (G_CONDO > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		X = -401.593;
		Y = 1839.58;
		Z = 5.7949;
		R = -165.0;
		saving = 1;
		G_SAVE_SAVED = 11;
	}
	//=========================== Ocean Heighs Aprt ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 453.212, -972.369, 6.965, 447.555, -969.353, 10.267, 0)) && (G_ONMISSION == 0) && (G_HEIGHS > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		X = 451.255;
		Y = -967.217;
		Z = 7.52892;
		R = -5.0;
		saving = 1;
		G_SAVE_SAVED = 12;
	}
	//=========================== 1102 Washington Street ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 521.188, -272.005, 5.308, 518.527, -269.363, 10.308, 0)) && (G_ONMISSION == 0) && (G_WS_1102 > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		X = 522.489;
		Y = -272.164;
		Z = 6.00446;
		R = -120.0;
		saving = 1;
		G_SAVE_SAVED = 13;
	}
	//=========================== 3321 Vice Point ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 967.985, 1806.919, 11.92, 964.985, 1809.919, 16.438, 0)) && (G_ONMISSION == 0) && (G_VP_3321 > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		X = 963.529;
		Y = 1805.22;
		Z = 12.0903;
		R = 130.0;
		saving = 1;
		G_SAVE_SAVED = 14;
	}

	//=========================== Skumole Shack ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), -125.348, 1231.967, 14.033, -129.233, 1235.396, 17.309, 0)) && (G_ONMISSION == 0) && (G_SHACK > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		X = -127.19;
		Y = 1236.19;
		Z = 14.8111;
		R = 0.0;
		saving = 1;
		G_SAVE_SAVED = 15;
	}
	//=========================== Ocean View Hotel ===========================
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 662.561, -731.554, 13.874, 659.649, -728.9, 17.472, 0)) && (G_ONMISSION == 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 16;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 661.254;
			Y = -731.808;
			Z = 14.4212;
			R = -175.0;
			saving = 1;
			G_SAVE_SAVED = 16;
		}
	}
	else
	{
		if (text_on == 16)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			text_on = 0;
		}
	}
	//=========================== Vercetti Mansion ===========================
	//äèâàí 1 ýòàæ 1
	if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 29.714, -26.031, 12.711, 26.559, -24.301, 15.638, 0)) && (G_ONMISSION == 0) && (G_PROTECT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 17;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 28.115;
			Y = -26.2823;
			Z = 13.2436;
			R = -175.0;
			saving = 1;
			G_SAVE_SAVED = 17;
		}
	}
	//äèâàí 2 ýòàæ 1
	else if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 29.714, -30.213, 12.711, 26.559, -28.483, 15.638, 0)) && (G_ONMISSION == 0) && (G_PROTECT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 17;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 28.0589;
			Y = -28.1805;
			Z = 13.2436;
			R = -10.0;
			saving = 1;
			G_SAVE_SAVED = 17;
		}
	}
	//äèâàí 3 ýòàæ 2
	else if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 62.09, -60.884, 19.687, 59.834, -58.636, 24.098, 0)) && (G_ONMISSION == 0) && (G_PROTECT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 17;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 60.0189;
			Y = -58.3347;
			Z = 20.0673;
			R = 40.0;
			saving = 1;
			G_SAVE_SAVED = 17;
		}
	}
	//äèâàí 4 ýòàæ 2
	else if ((IS_CHAR_IN_AREA_3D(GetPlayerPed(), 48.989, -62.33, 19.687, 46.732, -59.231, 24.098, 0)) && (G_ONMISSION == 0) && (G_PROTECT > 0) && (!IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed())))
	{
		if (text_on == 0)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
			PRINT_HELP("NESAVINGHELP"); // Press the ~INPUT_PHONE_ACCEPT~ button to save the game.
			text_on = 17;
		}
		if ((IS_CONTROL_PRESSED(2, 181)) && (!IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 16)))//ïðîâåðêà íàæàòà-ëè êëàâèøà "Äëÿ ïîêóïêè".
		{
			X = 49.0995;
			Y = -59.0782;
			Z = 20.0673;
			R = -45.0;
			saving = 1;
			G_SAVE_SAVED = 17;
		}
	}
	else
	{
		if (text_on == 17)
		{
			CLEAR_HELP(); // óäàëÿåì òåêñò ïîäñêàçêè
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
		SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), X, Y, Z);
		SET_CHAR_HEADING(GetPlayerPed(), R);
		SET_CHAR_HEALTH(GetPlayerPed(), 200);
		ALTER_WANTED_LEVEL(GetPlayerIndex(), 0);
		APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
		uint h, m;
		GET_TIME_OF_DAY(&h, &m);
		FORWARD_TO_TIME_OF_DAY(h + 6, m);
		WAIT(2000);
		if (DID_SAVE_COMPLETE_SUCCESSFULLY())
		{
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
}

void main(void)
{
	int intHash;
	uint startOffset;
	bool isPlaying, stop_aud, inInterior, isVolChanged;
	float vol = 0.0;
	float delta;

	inInterior = 0;
	isPlaying = 0;
	isVolChanged = 0;
	stop_aud = 0;

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

	ADD_POLICE_RESTART(831.488, 63.0072, 5.98145, -45.0, 0); // Washington Beach
	ADD_POLICE_RESTART(941.943, 1041.08, 5.54716, 180, 0); // Vice Point

	ADD_HOSPITAL_RESTART(320.068, -433.964, 4.70675, -85, 0); // Ocean Beach
	ADD_HOSPITAL_RESTART(925.961, 1235.05, 6.33435, 80, 0); // Vice Point

	SPECIFY_SCRIPT_POPULATION_ZONE_NUM_PEDS(100); 
	SPECIFY_SCRIPT_POPULATION_ZONE_NUM_SCENARIO_PEDS(100);
	ACTIVATE_SCRIPT_POPULATION_ZONE();

	REGISTER_SAVE_HOUSE(664.601, -746.511, 7.041, 250, "OceanViewHotel", 0);
	REGISTER_SAVE_HOUSE(963.529, 1805.22, 12.0903, 130, "3321VicePoint", 1);
	REGISTER_SAVE_HOUSE(737.991, 909.371, 7.45291, -85, "LinksViewApartment", 2);
	REGISTER_SAVE_HOUSE(861.53, 1139.81, 6.99313, 0, "ElSwankoCasa", 3);
	REGISTER_SAVE_HOUSE(522.489, -272.164, 6.00446, -120, "1102WashingtonStreet", 4);
	REGISTER_SAVE_HOUSE(451.255, -967.217, 7.52892, -5, "OceanHeighsAprt", 5);
	REGISTER_SAVE_HOUSE(-127.19, 1236.19, 14.8111, 0, "SkumoleShack", 6);
	REGISTER_SAVE_HOUSE(-401.593, 1839.58, 5.7949, -165, "HymanCondo", 7);
	REGISTER_SAVE_HOUSE(54.5077, -19.8106, 13.8069, 0, "VercettiMansion", 8);
	REGISTER_SAVE_HOUSE(-645.084, 246.738, 6.27582, -5, "Printworks", 9);
	REGISTER_SAVE_HOUSE(-595.363, -318.285, 7.53234, -150, "SunshineAutos", 10);
	REGISTER_SAVE_HOUSE(349.932, 1461.77, 5.1074, -105, "InterglobalFilms", 11);
	REGISTER_SAVE_HOUSE(-444.516, -45.5149, 5.47654, -80, "CherryPopperIcecreams", 12);
	REGISTER_SAVE_HOUSE(-567.321, 720.751, 5.67434, 60, "KaufmanCabs", 13);
	REGISTER_SAVE_HOUSE(924.395, 454.833, 5.73708, -130, "MalibuClub", 14);
	REGISTER_SAVE_HOUSE(-235.225, -949.423, 8.07865, -25, "TheBoatyard", 15);
	REGISTER_SAVE_HOUSE(529.641, -937.62, 4.65521, -150, "PolePositionClub", 16);
	ENABLE_SAVE_HOUSE(0, TRUE);

	CreateScript("intro");
	DO_SCREEN_FADE_IN_UNHACKED(0);

	while (TRUE) 
	{
		WAIT(0);
		jump();
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

		if (HAS_PICKUP_BEEN_COLLECTED( tweap_1 ))
		{
			UpdateWeaponOfPed(GetPlayerPed(), Weap1);
			UpdateWeaponOfPed(GetPlayerPed(), Weap2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap3);
			UpdateWeaponOfPed(GetPlayerPed(), Weap4);
			UpdateWeaponOfPed(GetPlayerPed(), Weap5);
			UpdateWeaponOfPed(GetPlayerPed(), Weap6);
			UpdateWeaponOfPed(GetPlayerPed(), Weap7);
			UpdateWeaponOfPed(GetPlayerPed(), Weap8);
			UpdateWeaponOfPed(GetPlayerPed(), Weap9);
			UpdateWeaponOfPed(GetPlayerPed(), Weap0);
			SET_CHAR_AMMO(GetPlayerPed(), Weap1, Ammo1_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap2, Ammo2_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap3, Ammo3_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap4, Ammo4_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap5, Ammo5_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap6, Ammo6_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap7, Ammo7_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap8, Ammo8_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap9, Ammo9_1);
			SET_CHAR_AMMO(GetPlayerPed(), Weap0, Ammo0_1);
		}
		if (HAS_PICKUP_BEEN_COLLECTED( tweap_2 ))
		{
			UpdateWeaponOfPed(GetPlayerPed(), Weap1_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap2_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap3_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap4_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap5_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap6_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap7_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap8_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap9_2);
			UpdateWeaponOfPed(GetPlayerPed(), Weap0_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap1_2, Ammo1_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap2_2, Ammo2_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap3_2, Ammo3_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap4_2, Ammo4_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap5_2, Ammo5_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap6_2, Ammo6_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap7_2, Ammo7_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap8_2, Ammo8_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap9_2, Ammo9_2);
			SET_CHAR_AMMO(GetPlayerPed(), Weap0_2, Ammo0_2);
		}

		if (HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()))
		{
			lawyer();
		}

		GET_INTERIOR_FROM_CHAR(GetPlayerPed(), &intHash);
		//DISPLAY_TEXT_WITH_2_NUMBERS(0.2, 0.2, "CAMTEST", intHash, ROUND(vol));
		if (intHash == 514)// MALIBU_CLUB
		{	
			if (isPlaying == 0)
			{
				GENERATE_RANDOM_INT_IN_RANGE(0, 550000, &startOffset);
				while (!(PRELOAD_STREAM_WITH_START_OFFSET("INTERIOR_STREAMS_MALIBU_CLUB", startOffset)))
				{
					WAIT(0);
				}
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
				while (!(PRELOAD_STREAM_WITH_START_OFFSET("INTERIOR_STREAMS_MALL_AMB", startOffset)))
				{
					WAIT(0);
				}
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
				while (!(PRELOAD_STREAM_WITH_START_OFFSET("INTERIOR_STREAMS_HOTEL_MUSIC", startOffset)))
				{
					WAIT(0);
				}
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
				while (!(PRELOAD_STREAM_WITH_START_OFFSET("INTERIOR_STREAMS_STRIPCLUB", startOffset)))
				{
					WAIT(0);
				}
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
				vol += delta*1.5;
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
				vol -= delta*3;
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
