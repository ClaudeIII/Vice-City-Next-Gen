/*	---------------------------------------------------------------
	 This header contains GTAIV/EFLC PC script common functions.

	 This file is a part of scocl project (C) Alexander Blade 2011

	 More script functions added by Claude_III
	---------------------------------------------------------------  */

#pragma once

#include "natives.h"
#include "consts.h"

void CheckModelLoad(uint model)
{
	if (!HAS_MODEL_LOADED(model))
	{
		REQUEST_MODEL(model);
		while (!HAS_MODEL_LOADED(model)) WAIT(0);
	}
}

void CreateScript(char* name)
{
	if (GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(name) == 0)
	{
		REQUEST_SCRIPT(name);
		while (!HAS_SCRIPT_LOADED(name)) WAIT(0);
		START_NEW_SCRIPT(name, 1024);
		MARK_SCRIPT_AS_NO_LONGER_NEEDED(name);
	}
}

void GetModelOfWeaponType(int weapontype)
{
	uint Result;

	GET_WEAPONTYPE_MODEL(weapontype, &Result);
	return Result;
}

Player GetPlayerIndex(void)
{
	return GET_PLAYER_ID();
}

Ped GetPlayerPed(void)
{
	Ped playerped = INVALID_HANDLE;
	if ( PLAYER_HAS_CHAR(GetPlayerIndex()) )
		GET_PLAYER_CHAR(GetPlayerIndex(), &playerped);
	return playerped;
}

void UpdateWeaponOfPed(Ped ped, Weapon weapon)
{
	if (HAS_CHAR_GOT_WEAPON(ped, weapon))
	{
		SET_CHAR_AMMO(ped, weapon, AMMO_MAX);    
	}
	else
	{
		GIVE_WEAPON_TO_CHAR(ped, weapon, AMMO_MAX, FALSE);	
	}
}

bool HasPlayerDeathArrest() {
	return HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()) || IS_PLAYER_DEAD(GetPlayerIndex());
}

void FinishStoryMission(char* scriptName) {
	// Cleanup
	SET_CREATE_RANDOM_COPS(true);
	SWITCH_POLICE_HELIS(true);
	SET_CAR_DENSITY_MULTIPLIER(1.0f);
	DONT_DISPATCH_COPS_FOR_PLAYER(GetPlayerIndex(), true);
	SUPPRESS_FADE_IN_AFTER_DEATH_ARREST(false);
	SET_POLICE_IGNORE_PLAYER(GetPlayerIndex(), false);
	CLEAR_BRIEF();

	INCREMENT_INT_STAT(STAT_MISSIONS_PASSED, 1);
	REGISTER_MISSION_PASSED(scriptName);

	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(scriptName);
}

Car CreateVehicle(uint hash, float x, float y, float z, float heading) {
	REQUEST_MODEL(hash);
	while (!HAS_MODEL_LOADED(hash)) WAIT(0);
	Car car;
	CREATE_CAR(hash, x, y, z, &car, true);
	SET_CAR_HEADING(car, heading);
	MARK_MODEL_AS_NO_LONGER_NEEDED(hash);
	return car;
}

Car CreateVehicle_DontRequestModel(uint hash, float x, float y, float z, float heading) {
	Car car;
	CREATE_CAR(hash, x, y, z, &car, true);
	SET_CAR_HEADING(car, heading);
	return car;
}

Ped CreatePed(uint modelHash, float x, float y, float z, float heading, uint pedType) {
	Ped ped;

	REQUEST_MODEL(modelHash);
	while (!HAS_MODEL_LOADED(modelHash)) WAIT(0);
	CREATE_CHAR(pedType, modelHash, 0.0f, 0.0f, 0.0f, &ped, true);
	SET_CHAR_COORDINATES_NO_OFFSET(ped, x, y, z);
	SET_CHAR_HEADING(ped, heading);
	MARK_MODEL_AS_NO_LONGER_NEEDED(modelHash);

	return ped;
}

Ped CreatePed_DontRequestModel(uint modelHash, float x, float y, float z, float heading, uint pedType) {
	Ped ped;

	CREATE_CHAR(pedType, modelHash, 0.0f, 0.0f, 0.0f, &ped, true);
	SET_CHAR_COORDINATES_NO_OFFSET(ped, x, y, z);
	SET_CHAR_HEADING(ped, heading);

	return ped;
}

/*
	seatIndex: from -1 to 2. If -1 is specified, this will be the driver's seat
*/
Ped CreatePedInCar(uint modelHash, uint pedType, Car car, uint seatIndex) {
	Ped ped;

	REQUEST_MODEL(modelHash);
	while (!HAS_MODEL_LOADED(modelHash)) WAIT(0);

	if (seatIndex == -1)
		CREATE_CHAR_INSIDE_CAR(car, pedType, modelHash, &ped);
	else
		CREATE_CHAR_AS_PASSENGER(car, pedType, modelHash, seatIndex, &ped);

	MARK_MODEL_AS_NO_LONGER_NEEDED(modelHash);

	return ped;
}

/*
	seatIndex: from -1 to 2. If -1 is specified, this will be the driver's seat
*/
Ped CreatePedInCar_DontRequestModel(uint modelHash, uint pedType, Car car, uint seatIndex) {
	Ped ped;

	if (seatIndex == -1)
		CREATE_CHAR_INSIDE_CAR(car, pedType, modelHash, &ped);
	else
		CREATE_CHAR_AS_PASSENGER(car, pedType, modelHash, seatIndex, &ped);

	return ped;
}

Object CreateObject(uint hash, float x, float y, float z, float heading) {
	REQUEST_MODEL(hash);
	while (!HAS_MODEL_LOADED(hash)) WAIT(0);
	Object object;
	CREATE_OBJECT_NO_OFFSET(hash, x, y, z, &object, true);
	SET_OBJECT_HEADING(object, heading);
	MARK_MODEL_AS_NO_LONGER_NEEDED(hash);
	return object;
}

Object CreateObject_DontRequestModel(uint hash, float x, float y, float z, float heading) {
	Object object;
	CREATE_OBJECT_NO_OFFSET(hash, x, y, z, &object, true);
	SET_OBJECT_HEADING(object, heading);
	return object;
}

Ped CreateRandomPed(float x, float y, float z, float heading, uint pedType) {
	Ped ped;

	CREATE_RANDOM_CHAR(x, y, z, &ped);
	SET_CHAR_HEADING(ped, heading);

	if (pedType != -1)
		SET_CHAR_RELATIONSHIP_GROUP(ped, pedType);

	return ped;
}

/*
	seatIndex: from -1 to 2. If -1 is specified, this will be the driver's seat
*/
Ped CreateRandomPedInCar(Car car, uint seatIndex, uint pedType) {
	Ped ped;

	if (seatIndex == -1)
		CREATE_RANDOM_CHAR_AS_DRIVER(car, &ped);
	else
		CREATE_RANDOM_CHAR_AS_PASSENGER(car, seatIndex, &ped);

	if (pedType != -1)
		SET_CHAR_RELATIONSHIP_GROUP(ped, pedType);

	return ped;
}