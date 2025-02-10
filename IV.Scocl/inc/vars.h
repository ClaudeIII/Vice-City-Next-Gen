/**
	Settings, Keybinds, and Structure for core
	Orig. by: Herr Muskelprotze

	by: DRS StreetFever
		Youtube :
	ReaperGravityModz
	Drift Rising Team
	
**/


//Xbox 360 buttons
#define BUTTON_SELECT 0xD
#define BUTTON_START 0xC
#define BUTTON_X 0xE
#define BUTTON_Y 0xF
#define BUTTON_A 0x10
#define BUTTON_B 0x11
#define DPAD_UP 0x8
#define DPAD_DOWN 0x9
#define DPAD_LEFT 0xA
#define DPAD_RIGHT 0xB
#define BUTTON_L 0x5
#define BUTTON_R 0x7
#define BUTTON_LB 0x4
#define BUTTON_RB 0x6
#define STICK_LEFT 0x12
#define STICK_RIGHT 0x13

//PS3 Buttons
#define L3  0x12
#define L2  0x5
#define R2  0x7
#define L1  0x4
#define R1  0x6
#define START      0xC
#define SELECT     0xD
#define SQUARE     0xE
#define TRIANGLE   0xF
#define X          0x10
#define CIRCLE     0x11
#define STICK_L    0x12  //L3
#define STICK_R    0x13  //R3

#define pos_x 0.25
#define start_y 0.14

typedef struct _menu_struct{
	char* item_name;
	bool action;
	int type;
	int value;
	int extra_val;
	int maxval;
} menu_struct;

menu_struct menu[20];

typedef struct _online_players{
	//index
	char* gamertag;
	Ped ped;
	int id;
	bool connected;
	//id
	bool mprotection;
	bool force;
	
} online_players;

online_players players[18];

int item_count = 0,
	item_select = 1,
	menu_level = 0,
	player_count = 0,
	last_selected[5];

uint r,g,b,a,s_r,s_g,s_b;
Ped pPlayer, tmp_player_ped;
uint tmp_model, model;
carvi;

Object tmp_object_loop;
uint tmp_model;
//start out as dildo
uint object_launch = 0x3675A6C3;
Ped driver;
Vehicle ClosestCar, pveh;
Group Bgroup;
Group Mgroup;
float x, y, z;

Ped gameped[8];

char* footer;

Object ObjectProjectile;
Camera game_cam;
float prjX, prjY, prjZ, prjT, gcX, gcY, gcZ, gcrotX, gcrotY, gcrotZ, objrotX, objrotZ, BGx, BGy, BGz, x, y, z, dist, heading, veh_hight=0.0;

bool grenade_active;
	
bool in_paint = false;	

uint tick;
int i;
int nvid;

bool xmc_in_game = false;
Ped xmc_char;
bool xmc1 = false;

bool show_menu = false,
	godmode = true,
	DRS_modmenu = false,
	Boubouvirus = false,
	Evade = false,
	Chrome = false,
	Motion97 = false,
	ihaz = false,
	Keredor = false,
	EvilBlunt = false,
	XMC = false,
	DRSLoaderMod1 = false,
	DRSLoaderMod2 = false,
	DRSLoaderMod3 = false,
	DRSLoaderMod4 = false,
	DRSLoaderMod5 = false,
	DRSLoaderMod6 = false,
	DRSLoaderMod7 = false,
	DRSLoaderMod8 = false,
	DRSLoaderMod9 = false,
	DRSLoaderMod10 = false,
	bikefly = false,
	collision = false,
	neverwanted = true,
	objectgun = false,
	invisible = false,
	burstfire = false,
	freezecar = false,
	fastreload = true,
	lowerpveh = false,
	onfire = false,
	autoaim = false,
	pprotection = false,
	superrun = false,
	rainbowmenu = false,
	del_objgun = true,
	hydrolics = false,
	superjump = false,
	forcefield = false,
	chaos = false,
	ammo = true,
	vhelper = true,
	modderprotect = true,
	carsonground = false,
	nfs = false,
	chat_thingy = true,
	drive_free = true,
	ragdoll = false;

 