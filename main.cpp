#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Clamp.h"
#include <time.h>

const char kWindowTitle[] = "スライムの旅路";
const int kwindowsUp = 0;
const int kwindowsLeft = 0;
const int kwindowsDown = 720;
const int kwindowsRight = 1280;
const int maxEnemys = 10;
const int maxTerrains = 30;
const int maxBlock = 11;
const int maxBlockY = 20;
const int maxFreeBlocks = 20;
const int terrainType = 10;
const int maxMapX = 4;
const int maxMapY = 4;
const int maxBar = 10;
const int barNumber = 5;
const int maxCollision = 8;
const int maxBoss = 3;
const int maxGhosts = 10;
const int maxDevilAtacks = 5;
const int maxBeams = 30;
const int maxExplodes = 50;
const int maxFlyEnemys = 5;
const int maxDigit = 2;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	//スクロール初期化
	int sPosX = 640;
	float sX = 0;
	float sPosY = 360;
	float sY = 0.0f;

	int sSpeed = 3;
	//背景の画像
	int bgHandle[maxMapX] = { 0 };
	bgHandle[0] = Novice::LoadTexture("./Resources/bg_1.png");
	bgHandle[1] = Novice::LoadTexture("./Resources/bg_2.png");
	bgHandle[2] = Novice::LoadTexture("./Resources/bg_3.png");
	bgHandle[3] = Novice::LoadTexture("./Resources/bg_4.png");
	int caveBgHandle = Novice::LoadTexture("./Resources/cave_bg.png");
	int waterfallBgHandle = Novice::LoadTexture("./Resources/waterfall_bg.png");
	int waterfallBgHandle2 = Novice::LoadTexture("./Resources/waterfall_bg.png");
	int waterfallGround = Novice::LoadTexture("./Resources/waterfall_ground.png");
	int cliffBgHandle = Novice::LoadTexture("./Resources/cliff_bg.png");
	int wall1Handle = Novice::LoadTexture("./Resources/wall1.png");
	int wall2Handle = Novice::LoadTexture("./Resources/wall2.png");
	int ivy1Handle = Novice::LoadTexture("./Resources/ivy1.png");
	int ivy2Handle = Novice::LoadTexture("./Resources/ivy2.png");
	int jellyfish1Handle = Novice::LoadTexture("./Resources/jellyfish1.png");
	int jellyfish2Handle = Novice::LoadTexture("./Resources/jellyfish2.png");
	int jellyfish3Handle = Novice::LoadTexture("./Resources/jellyfish3.png");
	int icicle1Handle = Novice::LoadTexture("./Resources/icicle1.png");
	int icicle2Handle = Novice::LoadTexture("./Resources/icicle2.png");
	int icicle3Handle = Novice::LoadTexture("./Resources/icicle3.png");
	int icicle4Handle = Novice::LoadTexture("./Resources/icicle4.png");
	int enemy1Handle = Novice::LoadTexture("./Resources/enemy1.png");
	int enemy2Handle = Novice::LoadTexture("./Resources/enemy2.png");
	int slime1Handle = Novice::LoadTexture("./Resources/slime1.png");
	int slime3Handle = Novice::LoadTexture("./Resources/slime3.png");
	int slime2Handle = Novice::LoadTexture("./Resources/slime2.png");
	int slime4Handle = Novice::LoadTexture("./Resources/slime4.png");
	int slimeBackHandle = Novice::LoadTexture("./Resources/slime_back.png");
	int skeletonBgHandle = Novice::LoadTexture("./Resources/skeleton_bg.png");
	int skeletonBgEnd1Handle = Novice::LoadTexture("./Resources/skeleton_bg_end1.png");
	int skeletonBgEnd2Handle = Novice::LoadTexture("./Resources/skeleton_bg_end2.png");
	int skeletonBgEnd3Handle = Novice::LoadTexture("./Resources/skeleton_bg_end3.png");
	int skeleton1Handle = Novice::LoadTexture("./Resources/skeleton1.png");
	int skeleton2Handle = Novice::LoadTexture("./Resources/skeleton2.png");
	int skeleton3Handle = Novice::LoadTexture("./Resources/skeleton3.png");
	int skeletonSickle1Handle = Novice::LoadTexture("./Resources/skeleton_sickle1.png");
	int skeletonSickle2Handle = Novice::LoadTexture("./Resources/skeleton_sickle2.png");
	int skeletonSickle3Handle = Novice::LoadTexture("./Resources/skeleton_sickle3.png");
	int skeletonSickle4Handle = Novice::LoadTexture("./Resources/skeleton_sickle4.png");
	int sickleAtack1Handle = Novice::LoadTexture("./Resources/sickle_atack1.png");
	int sickleAtack2Handle = Novice::LoadTexture("./Resources/sickle_atack2.png");
	int sickleAtack3Handle = Novice::LoadTexture("./Resources/sickle_atack3.png");
	int sickleAtack4Handle = Novice::LoadTexture("./Resources/sickle_atack4.png");
	int skeletonDoor1Handle = Novice::LoadTexture("./Resources/skeleton_door1.png");
	int skeletonDoor2Handle = Novice::LoadTexture("./Resources/skeleton_door2.png");
	int skeletonDoor3Handle = Novice::LoadTexture("./Resources/skeleton_door3.png");
	int skeletonDoor4Handle = Novice::LoadTexture("./Resources/skeleton_door2.png");
	int skeletonDoorEnd1Handle = Novice::LoadTexture("./Resources/skeleton_door_end1.png");
	int skeletonDoorEnd2Handle = Novice::LoadTexture("./Resources/skeleton_door_end2.png");
	int ghostUp1Handle = Novice::LoadTexture("./Resources/ghost1.png");
	int ghostUp2Handle = Novice::LoadTexture("./Resources/ghost2.png");
	int ghostUp3Handle = Novice::LoadTexture("./Resources/ghost3.png");
	int ghostSide1Handle = Novice::LoadTexture("./Resources/ghost_side1.png");
	int ghostSide2Handle = Novice::LoadTexture("./Resources/ghost_side2.png");
	int ghostSide3Handle = Novice::LoadTexture("./Resources/ghost_side3.png");
	int ghostDown1Handle = Novice::LoadTexture("./Resources/ghost_down1.png");
	int ghostDown2Handle = Novice::LoadTexture("./Resources/ghost_down2.png");
	int ghostDown3Handle = Novice::LoadTexture("./Resources/ghost_down3.png");
	int ghostAtackHandle = Novice::LoadTexture("./Resources/ghost_atack.png");
	int ghostAtackSideHandle = Novice::LoadTexture("./Resources/ghost_atack_side.png");
	int ghostFire1Handle = Novice::LoadTexture("./Resources/ghost_fire1.png");
	int ghostFire2Handle = Novice::LoadTexture("./Resources/ghost_fire2.png");
	int ghostFire3Handle = Novice::LoadTexture("./Resources/ghost_fire3.png");
	int ghostBgHandle = Novice::LoadTexture("./Resources/ghost_bg.png");
	int ghostEscapeHandle = Novice::LoadTexture("./Resources/escape.png");
	int ghostSignHandle = Novice::LoadTexture("./Resources/sign.png");
	int ghostStairsHandle = Novice::LoadTexture("./Resources/ghost_stairs.png");
	int ghostBlockHandle = Novice::LoadTexture("./Resources/ghost_block.png");
	int ghostFreeBlockHandle = Novice::LoadTexture("./Resources/ghost_freeblock.png");
	int ghostWarp1Handle = Novice::LoadTexture("./Resources/ghost_warp1.png");
	int ghostWarp2Handle = Novice::LoadTexture("./Resources/ghost_warp2.png");
	int ghostWarp3Handle = Novice::LoadTexture("./Resources/ghost_warp3.png");
	int ghostWarp4Handle = Novice::LoadTexture("./Resources/ghost_warp4.png");
	int ghostWarp5Handle = Novice::LoadTexture("./Resources/ghost_warp5.png");
	int ghostWarp6Handle = Novice::LoadTexture("./Resources/ghost_warp6.png");
	int ghostDoor1Handle = Novice::LoadTexture("./Resources/ghost_door1.png");
	int ghostDoor2Handle = Novice::LoadTexture("./Resources/ghost_door2.png");
	int ghostDoor3Handle = Novice::LoadTexture("./Resources/ghost_door3.png");
	int ghostDoor4Handle = Novice::LoadTexture("./Resources/ghost_door4.png");
	int ghostAmulet1Handle = Novice::LoadTexture("./Resources/amulet1.png");
	int ghostAmulet2Handle = Novice::LoadTexture("./Resources/amulet2.png");
	int ghostEndDoor1Handle = Novice::LoadTexture("./Resources/ghost_end_door1.png");
	int ghostEndDoor2Handle = Novice::LoadTexture("./Resources/ghost_end_door2.png");
	int ghostEndDoor3Handle = Novice::LoadTexture("./Resources/ghost_end_door3.png");
	int ghostEndDoor4Handle = Novice::LoadTexture("./Resources/ghost_end_door4.png");
	int ghostEndDoor5Handle = Novice::LoadTexture("./Resources/ghost_end_door5.png");
	int ghostEndDoor6Handle = Novice::LoadTexture("./Resources/ghost_end_door6.png");
	int ghostExit1Handle = Novice::LoadTexture("./Resources/ghost_exit1.png");
	int ghostExit2Handle = Novice::LoadTexture("./Resources/ghost_exit2.png");
	int forestGroundHandle = Novice::LoadTexture("./Resources/forest_ground.png");
	int forestBg1Handle = Novice::LoadTexture("./Resources/forest_bg1.png");
	int forestBg2Handle = Novice::LoadTexture("./Resources/forest_bg2.png");
	int forestEndBg1Handle = Novice::LoadTexture("./Resources/forest_end_bg1.png");
	int forestEndBg2Handle = Novice::LoadTexture("./Resources/forest_end_bg2.png");
	int forestEndBg3Handle = Novice::LoadTexture("./Resources/forest_end_bg3.png");
	int devilStartBgHandle = Novice::LoadTexture("./Resources/devil_start_bg.png");
	int devilDoor1Handle = Novice::LoadTexture("./Resources/devil_door1.png");
	int devilDoor2Handle = Novice::LoadTexture("./Resources/devil_door2.png");
	int devilDoor3Handle = Novice::LoadTexture("./Resources/devil_door3.png");
	int devilDoor4Handle = Novice::LoadTexture("./Resources/devil_door4.png");
	int slimeDirSide1Handle = Novice::LoadTexture("./Resources/slime_dir_side1.png");
	int slimeDirSide2Handle = Novice::LoadTexture("./Resources/slime_dir_side2.png");
	int slimeDirUp1Handle = Novice::LoadTexture("./Resources/slime_dir_up1.png");
	int slimeDirUp2Handle = Novice::LoadTexture("./Resources/slime_dir_up2.png");
	int slimeDirDown1Handle = Novice::LoadTexture("./Resources/slime_dir_down1.png");
	int slimeDirDown2Handle = Novice::LoadTexture("./Resources/slime_dir_down2.png");
	int slimeShot1Handle = Novice::LoadTexture("./Resources/slime_shot1.png");
	int slimeShot2Handle = Novice::LoadTexture("./Resources/slime_shot2.png");
	int slimeShot3Handle = Novice::LoadTexture("./Resources/slime_shot3.png");
	int slimeShot4Handle = Novice::LoadTexture("./Resources/slime_shot4.png");
	int slimeShot5Handle = Novice::LoadTexture("./Resources/slime_shot5.png");
	int slimeShot6Handle = Novice::LoadTexture("./Resources/slime_shot6.png");
	int devilEyeHandle = Novice::LoadTexture("./Resources/devil_eye.png");
	int devilEye1Handle = Novice::LoadTexture("./Resources/devil_eye1.png");
	int devilEye2Handle = Novice::LoadTexture("./Resources/devil_eye2.png");
	int devilEye3Handle = Novice::LoadTexture("./Resources/devil_eye3.png");
	int devilEye4Handle = Novice::LoadTexture("./Resources/devil_eye4.png");
	int devilEye5Handle = Novice::LoadTexture("./Resources/devil_eye5.png");
	int devilEye6Handle = Novice::LoadTexture("./Resources/devil_eye6.png");
	int devilEyeCloseHandle = Novice::LoadTexture("./Resources/devil_eye_close.png");
	int devilBodyHandle = Novice::LoadTexture("./Resources/devil_body.png");
	int devilBody1Handle = Novice::LoadTexture("./Resources/devil_body1.png");
	int devilBody2Handle = Novice::LoadTexture("./Resources/devil_body2.png");
	int devilBody3Handle = Novice::LoadTexture("./Resources/devil_body3.png");
	int devilBody4Handle = Novice::LoadTexture("./Resources/devil_body4.png");
	int devilBgHandle = Novice::LoadTexture("./Resources/devil_bg.png");
	int devilMarkHandle = Novice::LoadTexture("./Resources/devil_atack_mark.png");
	int devilMark1Handle = Novice::LoadTexture("./Resources/devil_atack_mark1.png");
	int devilMark2Handle = Novice::LoadTexture("./Resources/devil_atack_mark2.png");
	int devilMark3Handle = Novice::LoadTexture("./Resources/devil_atack_mark3.png");
	int devilBullet1Handle = Novice::LoadTexture("./Resources/devil_atack_bullet1.png");
	int devilBullet2Handle = Novice::LoadTexture("./Resources/devil_atack_bullet2.png");
	int devilBeam1Handle = Novice::LoadTexture("./Resources/devil_atack_beam.png");
	int fireBar1Handle = Novice::LoadTexture("./Resources/forest_firebar.png");
	int forestBlockHandle = Novice::LoadTexture("./Resources/forest_block.png");
	int mouse1Handle = Novice::LoadTexture("./Resources/mouse1.png");
	int mouse2Handle = Novice::LoadTexture("./Resources/mouse2.png");
	int slimeHome1Handle = Novice::LoadTexture("./Resources/slime_home1.png");
	int slimeHome2Handle = Novice::LoadTexture("./Resources/slime_home2.png");
	int slimeHome3Handle = Novice::LoadTexture("./Resources/slime_home3.png");
	int slimeHome4Handle = Novice::LoadTexture("./Resources/slime_home4.png");
	int slimeHome5Handle = Novice::LoadTexture("./Resources/slime_home5.png");
	int title1Handle = Novice::LoadTexture("./Resources/title1.png");
	int title2Handle = Novice::LoadTexture("./Resources/title2.png");
	int title3Handle = Novice::LoadTexture("./Resources/title3.png");
	int title4Handle = Novice::LoadTexture("./Resources/title4.png");
	int title5Handle = Novice::LoadTexture("./Resources/title5.png");
	int title6Handle = Novice::LoadTexture("./Resources/title6.png");
	int title7Handle = Novice::LoadTexture("./Resources/title7.png");
	int title8Handle = Novice::LoadTexture("./Resources/title8.png");
	int title9Handle = Novice::LoadTexture("./Resources/title9.png");
	int title10Handle = Novice::LoadTexture("./Resources/title10.png");
	int title11Handle = Novice::LoadTexture("./Resources/title11.png");
	int title12Handle = Novice::LoadTexture("./Resources/title12.png");
	int title13Handle = Novice::LoadTexture("./Resources/title13.png");
	int xHandle = Novice::LoadTexture("./Resources/x.png");
	int titleStart1Handle = Novice::LoadTexture("./Resources/title_start1.png");
	int titleStart2Handle = Novice::LoadTexture("./Resources/title_start2.png");
	int titleLule1Handle = Novice::LoadTexture("./Resources/title_lule1.png");
	int titleLule2Handle = Novice::LoadTexture("./Resources/title_lule2.png");
	int gameOver1Handle = Novice::LoadTexture("./Resources/gameover1.png");
	int gameOver2Handle = Novice::LoadTexture("./Resources/gameover2.png");
	int gameOver3Handle = Novice::LoadTexture("./Resources/gameover3.png");
	int gameOver4Handle = Novice::LoadTexture("./Resources/gameover4.png");
	int gameOver5Handle = Novice::LoadTexture("./Resources/gameover5.png");
	int gameOver6Handle = Novice::LoadTexture("./Resources/gameover6.png");
	int gameOverRetry1Handle = Novice::LoadTexture("./Resources/gameover_retry1.png");
	int gameOverRetry2Handle = Novice::LoadTexture("./Resources/gameover_retry2.png");
	int gameOverGiveUp1Handle = Novice::LoadTexture("./Resources/gameover_giveup1.png");
	int gameOverGiveUp2Handle = Novice::LoadTexture("./Resources/gameover_giveup2.png");
	int gameClear1Handle = Novice::LoadTexture("./Resources/gameclear1.png");
	int gameClear2Handle = Novice::LoadTexture("./Resources/gameclear2.png");
	int gameClear3Handle = Novice::LoadTexture("./Resources/gameclear3.png");
	int gameLuleBgHandle = Novice::LoadTexture("./Resources/lule.png");
	int lulePage1Handle = Novice::LoadTexture("./Resources/lule_page1.png");
	int lulePage2Handle = Novice::LoadTexture("./Resources/lule_page2.png");
	int backTitle1Handle = Novice::LoadTexture("./Resources/back_title1.png");
	int backTitle2Handle = Novice::LoadTexture("./Resources/back_title2.png");
	int back1Handle = Novice::LoadTexture("./Resources/back1.png");
	int back2Handle = Novice::LoadTexture("./Resources/back2.png");
	int next1Handle = Novice::LoadTexture("./Resources/next1.png");
	int next2Handle = Novice::LoadTexture("./Resources/next2.png");
	int startGroundHandle = Novice::LoadTexture("./Resources/start_ground.png");
	int groundHandle = Novice::LoadTexture("./Resources/ground.png");
	int caveUpHandle = Novice::LoadTexture("./Resources/cave_up.png");
	int devilGroundHandle = Novice::LoadTexture("./Resources/devil_ground.png");
	int skeletonTerrainHandle = Novice::LoadTexture("./Resources/skeleton_terrain.png");
	int skeletonGroundHandle = Novice::LoadTexture("./Resources/skeleton_ground.png");
	int tryIvy1Handle = Novice::LoadTexture("./Resources/try_ivy1.png");
	int tryIvy2Handle = Novice::LoadTexture("./Resources/try_ivy2.png");
	int tryEnemy1Handle = Novice::LoadTexture("./Resources/try_enemy.png");
	int doorSelect1Handle = Novice::LoadTexture("./Resources/door_slect1.png");
	int doorSelect2Handle = Novice::LoadTexture("./Resources/door_slect2.png");
	int doorSelect3Handle = Novice::LoadTexture("./Resources/door_slect3.png");
	int doorSelect4Handle = Novice::LoadTexture("./Resources/door_slect4.png");
	int doorSelect5Handle = Novice::LoadTexture("./Resources/door_slect5.png");
	int doorSelect6Handle = Novice::LoadTexture("./Resources/door_slect6.png");
	int doorSelect7Handle = Novice::LoadTexture("./Resources/door_slect7.png");
	int doorSelect8Handle = Novice::LoadTexture("./Resources/door_slect8.png");
	int bossLule1Handle = Novice::LoadTexture("./Resources/boss_lule1.png");
	int bossLule2Handle = Novice::LoadTexture("./Resources/boss_lule2.png");
	int bossLule3Handle = Novice::LoadTexture("./Resources/boss_lule3.png");
	int gameClearTitle1Handle = Novice::LoadTexture("./Resources/gameclear_title1.png");
	int gameClearTitle2Handle = Novice::LoadTexture("./Resources/gameclear_title2.png");
	int numH[10] = { 0 };
	numH[0] = Novice::LoadTexture("./Resources/number1.png");
	numH[1] = Novice::LoadTexture("./Resources/number2.png");
	numH[2] = Novice::LoadTexture("./Resources/number3.png");
	numH[3] = Novice::LoadTexture("./Resources/number4.png");
	numH[4] = Novice::LoadTexture("./Resources/number5.png");
	numH[5] = Novice::LoadTexture("./Resources/number6.png");
	numH[6] = Novice::LoadTexture("./Resources/number7.png");
	numH[7] = Novice::LoadTexture("./Resources/number8.png");
	numH[8] = Novice::LoadTexture("./Resources/number9.png");
	numH[9] = Novice::LoadTexture("./Resources/number10.png");

	typedef struct vector2 {
		float X;
		float WorldX;
		float startX;
		float momentX;
		float Y;
		float WorldY;
		float momentY;
		float startY;
	};
	typedef struct circle {
		vector2 pos;
		vector2 velocity;
		vector2 acceleration;
		vector2 dir;
		vector2 shotVelocity;
		vector2 start;
		vector2 end;
		float t;
		float easeT;
		float tIncrement;
		int stop;
		int maxReflect;
		int reflect;
		int frame;
		int back;
		int isSpace;
		float vibration;

		float rX;
		float rY;
		int color;
		float alive;
	};
	typedef struct Life {
		vector2 pos;
		vector2 velocity;
		vector2 acceleration;
		vector2 dir;
		vector2 shotVelocity;
		float rX;
		float rY;
		int color;
		float alive;
		float hp;
	};
	typedef struct Block {
		vector2 pos = { 0 };
		vector2 width = { 0 };
		int color;
	};
	//背景の初期化
	int gameOverAnimationTime = 0;
	Block gameStart = { 0 };
	gameStart.color = WHITE;
	gameStart.width.X = 500.0f;
	gameStart.width.Y = 200.0f;
	gameStart.pos.X = 650;
	gameStart.pos.Y = 300;
	Block gameLule = { 0 };
	gameLule.color = WHITE;
	gameLule.width.X = 500.0f;
	gameLule.width.Y = 100.0f;
	gameLule.pos.X = gameStart.pos.X;
	gameLule.pos.Y = gameStart.pos.Y + gameLule.width.Y + 100;
	int upIn = 0;
	int downIn = 0;
	Block gameNext = { 0 };
	gameNext.width.X = 256.0f;
	gameNext.width.Y = 80.0f;
	gameNext.pos.X = kwindowsRight - gameNext.width.X - 32;
	gameNext.pos.Y = kwindowsDown - gameNext.width.Y - 32;
	gameNext.color = WHITE;
	Block gameReturn = { 0 };
	gameReturn.width.X = gameNext.width.X;
	gameReturn.width.Y = gameNext.width.Y;
	gameReturn.pos.X = kwindowsLeft + 32;
	gameReturn.pos.Y = kwindowsDown - gameReturn.width.Y - 32;
	gameReturn.color = WHITE;
	Block returnTitle = { 0 };
	returnTitle.width.X = gameNext.width.X;
	returnTitle.width.Y = gameNext.width.Y;
	returnTitle.pos.X = kwindowsRight / 2 - returnTitle.width.X / 2;
	returnTitle.pos.Y = kwindowsDown - returnTitle.width.Y - 32;
	returnTitle.color = WHITE;
	int page = 0;
	int returnTitleIn = 0;
	Block tryField = { 0 };
	tryField.width.X = 600.0f;
	tryField.width.Y = 256.0f;
	tryField.pos.X = kwindowsRight - tryField.width.X - 32 - 32;
	tryField.pos.Y = 32 + returnTitle.width.Y + 96;
	tryField.color = 0x88cb7fff;
	Block tryIvy = { 0 };
	tryIvy.width.X = 70.0f;
	tryIvy.width.Y = tryField.width.Y;
	tryIvy.pos.X = tryField.pos.X + 144.0f;
	tryIvy.pos.Y = tryField.pos.Y;
	circle tryEnemy = { 0 };
	tryEnemy.color = WHITE;
	tryEnemy.alive = 1;
	tryEnemy.rX = 48.0f;
	tryEnemy.rY = 48.0f;
	tryEnemy.pos.X = tryField.pos.X + 32;
	tryEnemy.pos.Y = tryField.pos.Y + tryField.width.Y - tryEnemy.rY;
	int rightIn = 0;
	int leftIn = 0;
	int score = 0;
	int scoreNumber = 0;

	float luleSizeX = 0;
	float luleSizeY = 0;

	int gameStartAnimationTime = 0;
	int skyBgAnimationTime = 0;
	vector2 bg[maxMapY][maxMapX] = { 0 };
	for (int i = 0; i < maxMapY; i++) {
		for (int j = 0; j < maxMapX; j++) {
			bg[i][j].X = 0 + j * kwindowsRight;
			bg[i][j].Y = 0 - i * kwindowsDown;
		}
	}
	vector2 bgX[maxMapX] = { 0 };
	for (int i = 0; i < maxMapX; i++) {
		bgX[i].X = 0 + kwindowsRight * i;
		bgX[i].Y = 0;
	}
	circle bgY[maxMapY] = { 0 };
	for (int i = 0; i < maxMapY; i++) {
		bgY[i].pos.X = 0;
		bgY[i].pos.Y = 0 - i * kwindowsDown;
		bgY[i].rX = kwindowsRight;
		bgY[i].rY = kwindowsDown;
	}
	bgY[0].color = BLACK;
	bgY[1].color = BLUE;
	bgY[2].color = RED;
	bgY[3].color = GREEN;
	//時間
	int timer = 0;
	int momentTimer = 0;
	int number = 300;
	int momentNumber = number;
	int counter = 0;
	int eachNumber[maxDigit] = { 0 };
	int eachScore[4] = { 0 };
	//穴.地面の初期化
	float isHole = 0;
	Block waterfall[2] = { 0 };
	for (int i = 0; i < 2; i++) {
		waterfall[i].pos.Y = -1440.0f - i * 720 * 3;

	}

	Block ground = { 0 };
	ground.pos.WorldX = 0.0f;
	ground.pos.WorldY = kwindowsDown - 64.0f;
	ground.width.WorldX = bgX[3].X + kwindowsRight;
	ground.width.WorldY = 64.0f;
	Block hole[10] = { 0 };
	hole[0].pos.X = 320.0f;
	hole[0].width.X = 1200.0f;
	hole[0].pos.Y = ground.pos.WorldY;
	hole[0].width.Y = ground.width.WorldY;

	hole[1].pos.X = 3000.0f;
	hole[1].width.X = 900.0f;
	hole[1].pos.Y = ground.pos.WorldY;
	hole[1].width.Y = ground.width.WorldY;
	//マウス位置.マウス関連の初期化
	typedef struct vector2Int {
		int X;
		int Y;
	};
	vector2Int mouse = { 0 };
	vector2Int mouseClick = { 0 };
	float mouseDragX = 0.0f;
	float mouseDragY = 0.0f;
	float mouseDragDis = 0.0f;
	float radian = 0.0f;
	float friction = 0.8f;
	float mouseDisX = 0.0f;
	float mouseDisY = 0.0f;
	float mouseDis = 0.0f;
	//プレイヤーの初期化
	circle a = { 0 };
	circle b = { 0 };
	circle startA = { 0 };
	int slimeHp = 10;
	int momentSlimeHp = slimeHp;
	a.tIncrement = 0.2f;
	a.maxReflect = 4;
	a.rX = 30;
	a.rY = a.rX;
	a.pos.X = sPosX + 700.0f;
	a.pos.WorldX = (bg[0][maxMapX - 1].X + 1300);
	a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY - 100.0f;
	a.pos.WorldY = a.pos.Y;
	a.color = WHITE;
	a.velocity.X = 11;
	a.velocity.Y = 11;
	a.alive = 1.0f;
	startA.pos.X = a.pos.X;
	startA.pos.WorldX = a.pos.WorldX;
	startA.pos.Y = a.pos.Y;
	startA.pos.WorldY = a.pos.WorldY;
	b.rX = a.rX;
	b.rY = a.rY;
	int animeDir = 0;
	float isGround = 0;
	int isShot = 0;
	int slimeShot = 0;
	int scaleSpeed = 3;
	float isHitEnemy[maxEnemys] = { 0 };
	int slimeAnimationTime = 0;
	int slimeAnimationType = 0;
	//敵の初期化
	circle enemy[maxEnemys] = { 0 };
	float treadEnemy[maxEnemys] = { 0 };
	float enemyIsHole[maxEnemys] = { 0 };
	float enemyIsHitTerrain[maxEnemys] = { 0 };
	float hitEnemy = 0.0f;
	for (int i = 0; i < maxEnemys; i++) {
		enemy[i].rX = 60.0f;
		enemy[i].rY = 60.0f;
		enemy[i].pos.X = 600.0f + i * 400;
		enemy[i].pos.Y = ground.pos.WorldY - enemy[i].rY - i * 50;
		enemy[i].color = 0x6c2735ff;
		enemy[i].alive = 1;
		enemy[i].velocity.X = 3.0f;
	}
	int enemyAnimationTime[maxEnemys] = { 0 };
	int enemyAnimationType[maxEnemys] = { 0 };
	for (int i = 0; i < maxEnemys; i++) {
		enemyAnimationType[i] = 1;
	}
	circle flyEnemy[maxFlyEnemys] = { 0 };
	for (int i = 0; i < maxFlyEnemys; i++) {
		flyEnemy[i].rX = 20.0f;
		flyEnemy[i].rY = 20.0f;
		flyEnemy[i].pos.Y = 0 - i * 200.0f;
		flyEnemy[i].pos.X = 3000.0f - i * 10;
		flyEnemy[i].color = RED;
		flyEnemy[i].velocity.X = 5.0f;
		flyEnemy[i].velocity.Y = 5.0f;
	}
	int jellyfishAnimationTime[maxFlyEnemys] = { 0 };
	float flyEnemyRadian[maxFlyEnemys] = { 0 };
	//ボスの初期化
	circle bossAtackCollision[maxCollision] = { 0 };
	int skeletonAnimationType = 0;
	int skeletonAnimationTime = 0;
	int sickleAnimationTime = 0;
	float bossTime = 0.0f;
	float atackCoolTime = 0.0f;
	float atackTime = 0.0f;
	unsigned int currentTime = time(nullptr);
	srand(currentTime);
	int AtackType = rand() % 5;
	int isBossAtack = 0;
	int initialize = 0;
	int defeatMotion = 0;
	Life boss = { 0 };
	boss.rX = 100;
	boss.rY = 100;
	boss.pos.X = 900.0f;
	boss.pos.Y = ground.pos.WorldY - boss.rY;
	boss.pos.startX = boss.pos.X;
	boss.pos.startY = boss.pos.Y;
	boss.color = WHITE;
	boss.hp = 5;
	boss.velocity.X = 3;
	boss.alive = 1;
	float isHitBoss = 0.0f;
	float bossHitStop = 0.0f;
	float treadBoss = 0;
	float bossDisX[maxCollision] = { 0 };
	float bossDisY[maxCollision] = { 0 };
	float bossDis[maxCollision] = { 0 };
	for (int i = 0; i < maxCollision; i++) {
		bossAtackCollision[i].velocity.X = 13;
		bossAtackCollision[i].velocity.Y = 13;
	}

	enum ANIMATION {
		LEFT,
		RIGHT,
		CLIMB,
		UP,
		DOWN
	};
	//魔王の初期化
	Life devil[2] = { 0 };
	int devilBodyAnimationTime = 0;
	int effect = 1;
	int devilEffectTime = 0;
	int devilStartAnimationTime = 0;
	int devilMarkAnimationTime = 0;
	int devilStartFlag = 0;
	int eyeColor = WHITE;
	int hitInvincible = 0;
	devil[1].alive = 1;
	devil[1].hp = 10.0f;
	devil[0].pos.X = kwindowsRight;
	devil[0].pos.Y = 200.0f;
	devil[1].pos.X = kwindowsRight - 64.0f;
	devil[1].pos.Y = devil[0].pos.Y;
	devil[0].color = WHITE;
	devil[1].color = RED;
	for (int i = 0; i < 2; i++) {
		devil[i].velocity.X = 3;
		devil[i].velocity.Y = 0;
	}
	circle atackCollision[maxDevilAtacks] = { 0 };
	for (int i = 0; i < maxDevilAtacks; i++) {
		atackCollision[i].color = BLACK;
		atackCollision[i].rX = 30.0f;
		atackCollision[i].rY = 30.0f;
		atackCollision[i].velocity.X = 15.0f;
		atackCollision[i].velocity.Y = 15.0f;
	}
	int devilBullets[maxDevilAtacks] = { 0 };
	int mark[maxDevilAtacks] = { 0 };
	int momentTime[maxDevilAtacks] = { 0 };
	int momentAtackTime = 0;
	float atackRadian[maxDevilAtacks] = { 0 };
	int move = 0;
	int moveDir = 0;
	circle beam[maxBeams] = { 0 };
	for (int i = 0; i < maxBeams; i++) {
		beam[i].pos.startY = 10 + i * 30;
		beam[i].rX = 30.0f;
		beam[i].rY = 30.0f;
		beam[i].color = RED;
	}
	float beamRadian = 0.0f;
	//撃破用
	circle explode[maxExplodes] = { 0 };
	for (int i = 0; i < maxExplodes; i++) {
		explode[i].rX = 10.0f;
		explode[i].rY = 10.0f;
		explode[i].color = 0xba2636ff;
	}
	int explodeTime = 0;
	int explodeFlag = 0;
	int explodePos = 0;
	//障害物の初期化
	circle terrainA = { 0 };
	terrainA.pos.X = 700.0f;
	terrainA.pos.Y = bgY[1].pos.Y - terrainA.rY;
	terrainA.rX = 400.0f;
	terrainA.rY = 10.0f;
	terrainA.velocity.X = 5.0f;
	circle terrain[maxTerrains] = { {0} };
	for (int i = 0; i < maxTerrains; i++) {
		terrain[i].rX = 50.0f;
		terrain[i].rY = 50.0f;
		if (i % 2 == 0) {
			terrain[i].pos.Y = kwindowsDown * -1 + 10.0f;
		}
		else {
			terrain[i].pos.Y = kwindowsDown * -2 + 400.0f;
		}
		terrain[i].pos.X = 450.0f + i * 150.0f;

		if (i >= 10) {
			terrain[i].rX = 50.0f;
			terrain[i].rY = 100.0f;
			terrain[i].pos.X = 400.0f + (i - 10) * 300.0f;
			terrain[i].pos.Y = ground.pos.WorldY - terrain[i].rY;
			terrain[i].color = 0x316745ff;
			if (i < 14) {
				terrain[i].rY = 200.0f;
				terrain[i].pos.Y = kwindowsDown - terrain[i].rY;
				terrain[i].color = 0x5a5359ff;
			}
		}
	}
	terrain[23].pos.X = -200.0f;
	terrain[24].rX = 600;
	terrain[25].pos.X = -1000.0f;
	terrain[19].pos.X = 0;
	terrain[19].pos.Y = bgY[1].pos.Y;
	terrain[19].rX = kwindowsRight * maxMapX;
	terrain[19].rY = (kwindowsDown * 2) - ground.width.WorldY;
	Block freeBlock[maxFreeBlocks] = { 0 };
	freeBlock[9].pos.Y = terrain[19].pos.Y + 200.0f;
	freeBlock[9].width.X = 2000.0f;
	freeBlock[9].width.Y = 720.0f;
	circle icicle[2] = { 0 };
	int icicleDown = 0;
	int icicleTime = 0;
	for (int i = 0; i < 2; i++) {
		icicle[i].rX = 16.0f;
		icicle[i].rY = 16.0f + i * 10;
		icicle[i].pos.X = 900.0f;
		icicle[i].pos.Y = freeBlock[9].pos.Y + freeBlock[9].width.Y;
		icicle[i].color = BLUE;
	}

	//ダンジョンの構成ブロック
	Block block[maxBlockY][maxBlock] = { 0 };
	for (int i = 0; i < maxBlockY; i++) {
		if (i != 9 && i != 19) {
			block[i][0].width.X = 400.0f;
			block[i][0].width.Y = 100.0f;
			if (i < maxBlockY / 2) {
				block[i][0].pos.X = kwindowsRight - block[i][0].width.X + 200;
				block[i][0].pos.Y = ground.pos.WorldY - block[i][0].width.Y - i * 300;
				block[i][0].width.X = 800.0f;
			}
			else {
				block[i][0].pos.X = kwindowsLeft - 200;
				block[i][0].pos.Y = ground.pos.WorldY - block[i][0].width.Y - (i - maxBlockY / 2) * 300;
			}
		}

	}
	for (int i = 1; i < maxBlock; i++) {
		block[0][i].width.X = 90.0f;
		block[0][i].width.Y = 40.0f;
		block[0][i].pos.X = block[0][0].pos.X - block[0][i].width.X - (i - 1) * block[0][i].width.X;
		block[0][i].pos.Y = block[0][0].pos.Y - block[0][i].width.Y + 20 - (i - 1) * (block[0][i].width.Y / 2);
	}
	block[3][0].pos.Y += 90;
	block[2][0].width.Y /= 2;
	block[12][0].width.Y /= 2;
	block[13][0].pos.Y += 90;
	block[3][0].width.Y -= 40;
	block[13][0].width.Y -= 40;
	block[4][0].pos.Y += 170;
	block[14][0].pos.Y += 170;
	block[4][0].width.Y -= 40;
	block[14][0].width.Y -= 40;
	block[11][0].pos.Y += 80.0f;
	block[11][0].width.Y -= 50.0f;
	block[1][0].pos.Y += 80.0f;
	block[1][0].width.Y -= 50.0f;
	block[2][0].pos.Y += 30.0f;
	block[12][0].pos.Y = block[2][0].pos.Y;
	block[19][0].pos.X = -1000.0f;
	for (int i = 1; i < maxBlock; i++) {
		for (int j = 12; j < maxBlockY; j++) {
			if (j != 14 && j != 15 && j != 16 && j != 18) {
				block[j][i].width.X = 90.0f;
				block[j][i].width.Y = 40.0f;
				block[j][i].pos.X = block[j][0].pos.X + block[j][0].width.X - 100 + block[j][i].width.X + (i - 1) * block[j][i].width.X;
				block[j][i].pos.Y = block[j][0].pos.Y - block[j][i].width.Y + 20 - (i - 1) * (block[j][i].width.Y / 2);
			}
		}


	}
	block[14][0].width.X += 200.0f;
	block[16][0].width.X += 200.0f;
	block[17][0].width.X += 2000.0f;
	block[5][0].pos.X -= 680.0f;
	block[5][0].width.X += 680.0f;
	block[7][0].pos.X = block[17][0].pos.X + block[17][0].width.X;
	block[1][0].pos.X -= 200.0f;
	freeBlock[2].width.X = 50.0f;
	freeBlock[2].width.Y = 100.0f;
	freeBlock[2].pos.X = block[13][5].pos.X + block[13][5].width.X - freeBlock[2].width.X;
	freeBlock[2].pos.Y = block[13][5].pos.Y + 1;
	freeBlock[0].width.X = 30.0f;
	freeBlock[0].width.Y = 500.0f;
	freeBlock[0].pos.X = block[1][0].pos.X;
	freeBlock[0].pos.Y = block[1][0].pos.Y - freeBlock[0].width.Y;

	freeBlock[1].pos.X = 0.0f;
	freeBlock[1].width.X = kwindowsRight;
	freeBlock[1].pos.Y = block[3][0].pos.Y - 1;
	freeBlock[1].width.Y = 10.0f;
	freeBlock[3].width.X = 30.0f;
	freeBlock[3].width.Y = 1100.0f;
	freeBlock[3].pos.X = block[14][0].pos.X + block[14][0].width.X - freeBlock[3].width.X;
	freeBlock[3].pos.Y = block[14][0].pos.Y + block[14][0].width.Y - freeBlock[3].width.Y;
	freeBlock[4].pos.X = block[16][0].pos.X + block[16][0].width.X;
	freeBlock[4].pos.Y = block[16][0].pos.Y + block[16][0].width.Y;
	freeBlock[4].width.X = block[6][0].pos.X - block[14][0].pos.X + block[14][0].width.X;
	freeBlock[4].width.Y = 10.0f;
	freeBlock[5].width.X = 30.0f;
	freeBlock[5].width.Y = 200.0f;
	freeBlock[5].pos.X = block[8][0].pos.X - freeBlock[5].width.X;
	freeBlock[5].pos.Y = block[17][0].pos.Y - freeBlock[5].width.Y;
	freeBlock[6].width.X = 30.0f;
	freeBlock[6].width.Y = 800.0f;
	freeBlock[6].pos.X = block[18][0].pos.X + block[18][0].width.X - freeBlock[5].width.X;
	freeBlock[6].pos.Y = block[18][0].pos.Y - freeBlock[6].width.Y;
	freeBlock[7].width.X = 270.0f;
	freeBlock[7].width.Y = 40.0f;
	freeBlock[7].pos.X = block[13][2].pos.X + block[13][2].width.X;
	freeBlock[7].pos.Y = block[13][2].pos.Y;
	freeBlock[8].width.X = 70.0f;
	freeBlock[8].width.Y = 20.0f;
	freeBlock[8].pos.X = freeBlock[3].pos.X - freeBlock[8].width.X;
	freeBlock[8].pos.Y = block[15][0].pos.Y + block[15][0].width.Y + 140.0f;

	circle startWarp = { 0 };
	circle endWarp = { 0 };
	float warpSize = 1.0f;
	int warpFlag = 0;
	int warpAnimationTime = 0;
	startWarp.rX = 40.0f;
	startWarp.rY = 40.0f;
	startWarp.pos.X = block[16][0].pos.X + block[16][0].width.X - startWarp.rX - 30.0f;
	startWarp.pos.Y = block[16][0].pos.Y - startWarp.rY;
	startWarp.color = BLUE;
	endWarp.rX = startWarp.rX;
	endWarp.rY = startWarp.rY;
	endWarp.pos.X = block[8][0].pos.X + endWarp.rX;
	endWarp.pos.Y = block[17][0].pos.Y - endWarp.rY;
	Block exit = { 0 };
	int exitAnimationTime = 0;
	exit.width.X = 80.0f;
	exit.width.Y = 120.0f;
	exit.pos.X = block[18][0].pos.X + block[18][0].width.X - exit.width.X - 60;
	exit.pos.Y = block[18][0].pos.Y - exit.width.Y;
	circle amulet = { 0 };
	int getAmulet = 0;
	int amuletAnimationTime = 0;
	amulet.rX = 50.0f;
	amulet.rY = 50.0f;
	amulet.pos.X = block[8][0].pos.X + 80.0f;
	amulet.pos.Y = block[8][0].pos.Y - amulet.rY;
	//ダンジョンのゴースト初期化
	circle ghost[maxGhosts] = { 0 };
	float ghostRadian[maxGhosts] = { 0.0f };
	float ghostRadianX[maxGhosts] = { 0.0f };
	float ghostRadianY[maxGhosts] = { 0.0f };
	int ghostAnimationType = LEFT;
	int ghostAnimationTime = 0;
	int ghostAtackFlag = 0;
	int ghostFireAnimationTime = 0;
	float ghostSize = 1.0f;
	for (int i = 0; i < maxGhosts; i++) {
		ghost[i].pos.X = 1000.0f;
		ghost[i].pos.Y = 650.0f - i * 300;
		ghost[i].rX = 70.0f;
		ghost[i].rY = 70.0f;
		ghost[i].velocity.X = 3.0f;
		ghost[i].velocity.Y = 3.0f;
		ghost[i].color = BLACK;
	}
	circle appear[maxGhosts] = { 0 };
	for (int i = 0; i < maxGhosts; i++) {
		appear[i].color = BLACK;
		appear[i].rX = 120.0f;
		appear[i].rY = appear[i].rX;
		appear[i].pos.X = 100 + i * 100;
		appear[i].pos.Y = block[12][0].pos.Y - appear[i].rY - i * 350;
	}
	int clearGhost = 0;
	int eatTime = 0;
	int atackStop = 0;
	//蔓の初期化
	Block rope = { 0 };
	int ivyAnimationTime = 0;
	int isClimb = 0;
	rope.pos.X = 2900.0f;
	rope.pos.Y = terrain[19].pos.Y;
	rope.width.X = 70.0f;
	rope.width.Y = (kwindowsDown * 2) - ground.width.WorldY;
	//ファイアバーの初期化
	float barRadian[maxBar] = { 0 };
	float isHitBar = 0.0f;
	float disX = 0;
	float disY = 0;
	float dis = 0;
	circle bar[maxBar][barNumber] = { 0 };
	for (int i = 0; i < maxBar; i++) {
		barRadian[i] = i * 3;
		for (int j = 0; j < barNumber; j++) {
			bar[i][j].rX = 20;
			bar[i][j].rY = 20;
			bar[i][j].pos.startX = terrain[i].rX / 2 + j * bar[i][j].rX * 2;
			bar[i][j].pos.startY = 0.0f;
		}

	}
	//ボス部屋の初期化
	int skeletonDoorAnimationTime = 0;
	int skeletonEndAnimationTime = 0;
	int skeletonEndFlag = 0;
	int ghostEndFlag = 0;
	int ghostDoorAnimatioTime = 0;
	int ghostEndAnimationTime = 0;
	int devilDoorAnimationTime = 0;

	Block bossDoor[maxBoss] = { 0 };
	int doorType[maxBoss] = { 0 };
	for (int i = 0; i < maxBoss; i++) {
		bossDoor[i].width.X = 80.0f;
		bossDoor[i].width.Y = bossDoor[i].width.X;
		bossDoor[i].pos.X = 150.0f;
		bossDoor[i].pos.Y = kwindowsDown - ground.width.WorldY - bossDoor[i].width.Y - i * (kwindowsDown * 2);
	}
	bossDoor[1].width.Y = 120.0f;
	bossDoor[1].pos.X -= 20.0f;
	bossDoor[1].pos.Y = terrain[19].pos.Y - bossDoor[1].width.Y;
	bossDoor[2].width.Y = 300.0f;
	bossDoor[2].width.X = 300.0f;
	bossDoor[2].pos.Y = terrain[19].pos.Y - bossDoor[2].width.Y;
	bossDoor[2].pos.X = kwindowsRight * 3 + kwindowsRight / 2;

	Block popUp[3] = { 0 };
	int popUpColor[3] = { WHITE,BLACK,BLACK };
	for (int i = 0; i < 3; i++) {
		popUp[i].pos.X = kwindowsLeft + kwindowsRight / 2;
		popUp[i].pos.Y = kwindowsUp + kwindowsDown / 2;
	}

	float sceneChange = 0;
	int startSceneChange = 0;
	enum SCENE {
		TITLE = 100,
		LULE,
		STAGE,
		STAGEBOSS,
		STAGEBOSS2,
		STAGEBOSS3,
		GAMEOVER,
		GAMECLEAR


	};
	int clearSkeleton = 0;
	int scene = TITLE;


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene) {
		case TITLE:
			//アニメーションの時間
			//プレイヤー
			slimeAnimationTime += 1;
			if (slimeAnimationTime == 80) {
				slimeAnimationTime = 0;
				currentTime = time(nullptr);
				srand(currentTime);
				slimeAnimationType = rand() % 5;
			}
			Novice::GetMousePosition(&mouse.X, &mouse.Y);
			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
				startSceneChange = 1;
			}
			//ゲームスタート
			if (mouse.X < gameStart.pos.X + gameStart.width.X &&
				mouse.X > gameStart.pos.X &&
				mouse.Y < gameStart.pos.Y + gameStart.width.Y &&
				mouse.Y > gameStart.pos.Y ||
				startSceneChange == 1) {
				gameStart.color = RED;
				upIn = 1;
				if (Novice::IsTriggerMouse(0)) {
					startSceneChange = 1;
				}
			}
			else {
				gameStart.color = WHITE;
				upIn = 0;
			}
			if (startSceneChange == 1 && gameStartAnimationTime < 120) {
				gameStartAnimationTime += 1;
			}
			else if (startSceneChange == 1) {
				//初期値に戻す
				gameStartAnimationTime = 0;
				skyBgAnimationTime = 0;
				//時間
				timer = 0;
				counter = 0;
				//穴.地面の初期化
				isHole = 0;
				for (int i = 0; i < 2; i++) {
					waterfall[i].pos.Y = -1440.0f - i * 720 * 3;

				}
				//マウス位置.マウス関連の初期化
				mouseDragX = 0.0f;
				mouseDragY = 0.0f;
				mouseDragDis = 0.0f;
				radian = 0.0f;
				mouseDisX = 0.0f;
				mouseDisY = 0.0f;
				mouseDis = 0.0f;
				//プレイヤーの初期化
				a.tIncrement = 0.2f;
				a.reflect = 0;
				a.easeT = 0.0f;
				a.t = 0.0f;
				a.frame = 0;
				a.stop = 0;
				a.vibration = 0.0f;
				a.maxReflect = 4;
				scoreNumber = 0;
				score = 0;
				slimeHp = 10;
				momentSlimeHp = slimeHp;
				a.pos.X = sPosX + 700.0f;
				a.pos.WorldX = (bg[0][maxMapX - 1].X + 1300);
				a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY - 100.0f;
				a.pos.WorldY = a.pos.Y;
				a.color = WHITE;
				a.alive = 1.0f;
				a.shotVelocity.X = 0.0f;
				a.shotVelocity.Y = 0.0f;
				a.velocity.Y = 0.0f;
				animeDir = 0;
				isGround = 0;
				isShot = 0;
				slimeShot = 0;
				slimeAnimationTime = 0;
				slimeAnimationType = 0;
				//敵の初期化
				for (int i = 0; i < maxEnemys; i++) {
					isHitEnemy[i] = 0;
					treadEnemy[i] = 0;
					enemyIsHole[i] = 0;
					enemyIsHitTerrain[i] = 0;
					enemyAnimationTime[i] = 0;
					enemyAnimationType[i] = 1;
					enemy[i].rX = 60.0f;
					enemy[i].rY = 60.0f;
					enemy[i].pos.X = 600.0f + i * 400;
					enemy[i].pos.Y = ground.pos.WorldY - enemy[i].rY - i * 50;
					enemy[i].color = 0x6c2735ff;
					enemy[i].alive = 1;
					enemy[i].velocity.X = 3.0f;
				}
				hitEnemy = 0.0f;
				for (int i = 0; i < maxFlyEnemys; i++) {
					flyEnemy[i].pos.Y = 0 - i * 200.0f;
					flyEnemy[i].pos.X = 3000.0f - i * 10;
					flyEnemy[i].color = RED;
					flyEnemyRadian[i] = 0;
					jellyfishAnimationTime[i] = 0;
				}
				//ボスの初期化
				skeletonAnimationType = 0;
				skeletonAnimationTime = 0;
				sickleAnimationTime = 0;
				bossTime = 0.0f;
				atackCoolTime = 0.0f;
				atackTime = 0.0f;
				currentTime = time(nullptr);
				srand(currentTime);
				AtackType = rand() % 5;
				isBossAtack = 0;
				initialize = 0;
				defeatMotion = 0;
				boss.pos.X = boss.pos.startX;
				boss.pos.Y = boss.pos.startY;
				boss.color = WHITE;
				boss.hp = 5;
				boss.alive = 1;
				isHitBoss = 0.0f;
				bossHitStop = 0.0f;
				treadBoss = 0;
				for (int i = 0; i < maxCollision; i++) {
					bossAtackCollision[i].velocity.X = 13;
					bossAtackCollision[i].velocity.Y = 13;
					bossDisX[i] = 0;
					bossDisY[i] = 0;
					bossDis[i] = 0;
				}
				//魔王の初期化
				devilBodyAnimationTime = 0;
				effect = 1;
				devilEffectTime = 0;
				devilStartAnimationTime = 0;
				devilMarkAnimationTime = 0;
				devilStartFlag = 0;
				eyeColor = WHITE;
				hitInvincible = 0;
				devil[1].alive = 1;
				devil[1].hp = 6.0f;
				devil[0].pos.X = kwindowsRight;
				devil[0].pos.Y = 200.0f;
				devil[1].pos.X = kwindowsRight - 64.0f;
				devil[1].pos.Y = devil[0].pos.Y;
				devil[0].color = WHITE;
				devil[1].color = RED;
				for (int i = 0; i < 2; i++) {
					devil[i].velocity.X = 3;
					devil[i].velocity.Y = 0;
				}
				for (int i = 0; i < maxDevilAtacks; i++) {
					atackCollision[i].color = BLACK;
					atackCollision[i].velocity.X = 15.0f;
					atackCollision[i].velocity.Y = 15.0f;
					devilBullets[i] = 0;
					mark[i] = 0;
					momentTime[i] = 0;
					atackRadian[i] = 0.0f;
				}
				momentAtackTime = 0;
				move = 0;
				moveDir = 0;
				beamRadian = 0.0f;
				//撃破用
				for (int i = 0; i < maxExplodes; i++) {
					explode[i].rX = 10.0f;
					explode[i].rY = 10.0f;
					explode[i].color = 0xba2636ff;
				}
				explodeTime = 0;
				explodeFlag = 0;
				explodePos = 0;
				//障害物の初期化
				terrainA.rY = 0.0f;
				terrainA.pos.X = 700.0f;
				terrainA.pos.Y = bgY[1].pos.Y - terrainA.rY;
				terrainA.rX = 400.0f;
				terrainA.rY = 10.0f;
				terrainA.velocity.X = 5.0f;
				icicleDown = 0;
				icicleTime = 0;
				for (int i = 0; i < 2; i++) {
					icicle[i].pos.X = 900.0f;
					icicle[i].pos.Y = freeBlock[9].pos.Y + freeBlock[9].width.Y;
					icicle[i].color = BLUE;
				}
				warpSize = 1.0f;
				warpFlag = 0;
				warpAnimationTime = 0;
				startWarp.color = BLUE;
				exitAnimationTime = 0;
				getAmulet = 0;
				amuletAnimationTime = 0;
				amulet.pos.X = block[8][0].pos.X + 80.0f;
				amulet.pos.Y = block[8][0].pos.Y - amulet.rY;
				//ダンジョンのゴースト初期化
				ghostAnimationType = LEFT;
				ghostAnimationTime = 0;
				ghostAtackFlag = 0;
				ghostFireAnimationTime = 0;
				ghostSize = 1.0f;
				for (int i = 0; i < maxGhosts; i++) {
					ghostRadian[i] = 0.0f;
					ghostRadianX[i] = 0.0f;
					ghostRadianY[i] = 0.0f;
					ghost[i].pos.X = 1000.0f;
					ghost[i].pos.Y = 650.0f - i * 300;
					ghost[i].rX = 70.0f;
					ghost[i].rY = 70.0f;
					ghost[i].velocity.X = 3.0f;
					ghost[i].velocity.Y = 3.0f;
					ghost[i].color = BLACK;
				}
				for (int i = 0; i < maxGhosts; i++) {
					appear[i].color = BLACK;
					appear[i].rX = 120.0f;
					appear[i].rY = appear[i].rX;
					appear[i].pos.X = 100 + i * 100;
					appear[i].pos.Y = block[12][0].pos.Y - appear[i].rY - i * 350;
				}
				clearGhost = 0;
				eatTime = 0;
				atackStop = 0;
				//蔓の初期化
				ivyAnimationTime = 0;
				isClimb = 0;
				//ファイアバーの初期化
				isHitBar = 0.0f;
				disX = 0;
				disY = 0;
				dis = 0;
				for (int i = 0; i < maxBar; i++) {
					barRadian[i] = i * 3;
				}
				//ボス部屋の初期化
				skeletonDoorAnimationTime = 0;
				skeletonEndAnimationTime = 0;
				skeletonEndFlag = 0;
				ghostEndFlag = 0;
				ghostDoorAnimatioTime = 0;
				ghostEndAnimationTime = 0;
				devilDoorAnimationTime = 0;

				for (int i = 0; i < maxBoss; i++) {
					doorType[i] = 0;
				}
				popUpColor[0] = WHITE;
				popUpColor[1] = BLACK;
				popUpColor[2] = BLACK;
				for (int i = 0; i < 3; i++) {
					popUp[i].pos.X = kwindowsLeft + kwindowsRight / 2;
					popUp[i].pos.Y = kwindowsUp + kwindowsDown / 2;
				}
				sceneChange = 0;
				clearSkeleton = 0;
				//
				a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY - terrain[24].rY - 10;
				a.pos.WorldY = kwindowsDown - a.rY - ground.width.WorldY - terrain[24].rY - 10;
				gameStartAnimationTime = 0;
				scene = STAGE;
			}
			if (mouse.X < gameLule.pos.X + gameLule.width.X &&
				mouse.X > gameLule.pos.X &&
				mouse.Y < gameLule.pos.Y + gameLule.width.Y &&
				mouse.Y > gameLule.pos.Y && startSceneChange == 0) {
				gameLule.color = BLUE;
				downIn = 1;
				if (Novice::IsTriggerMouse(0)) {
					tryEnemy.alive = 1;
					tryEnemy.pos.X = tryField.pos.X + 32;
					tryEnemy.pos.Y = tryField.pos.Y + tryField.width.Y - tryEnemy.rY;
					a.pos.X = sPosX + 700.0f;
					a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY - 100.0f;
					ivyAnimationTime = 0;
					scene = LULE;
				}

			}
			else {
				gameLule.color = WHITE;
				downIn = 0;
			}
			//タイトル
			if (startSceneChange == 0) {
				if (slimeAnimationTime < 10) {
					Novice::DrawSprite(0, 0, title1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (slimeAnimationTime < 20) {
					Novice::DrawSprite(0, 0, title2Handle, 1, 1, 0.0f, WHITE);
				}
				else if (slimeAnimationTime < 30) {
					Novice::DrawSprite(0, 0, title3Handle, 1, 1, 0.0f, WHITE);
				}
				else if (slimeAnimationTime < 40) {
					Novice::DrawSprite(0, 0, title4Handle, 1, 1, 0.0f, WHITE);
				}
				else if (slimeAnimationTime < 50) {
					Novice::DrawSprite(0, 0, title5Handle, 1, 1, 0.0f, WHITE);
				}
				else if (slimeAnimationTime < 60) {
					Novice::DrawSprite(0, 0, title6Handle, 1, 1, 0.0f, WHITE);
				}
				else if (slimeAnimationTime < 70) {
					Novice::DrawSprite(0, 0, title7Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(0, 0, title8Handle, 1, 1, 0.0f, WHITE);
				}
			}
			else {
				if (gameStartAnimationTime < 30) {
					Novice::DrawSprite(0, 0, title9Handle, 1, 1, 0.0f, WHITE);
				}
				else if (gameStartAnimationTime < 60) {
					Novice::DrawSprite(0, 0, title10Handle, 1, 1, 0.0f, WHITE);
				}
				else if (gameStartAnimationTime < 80) {
					Novice::DrawSprite(0, 0, title11Handle, 1, 1, 0.0f, WHITE);
				}
				else if (gameStartAnimationTime < 100) {
					Novice::DrawSprite(0, 0, title12Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(0, 0, title13Handle, 1, 1, 0.0f, WHITE);
				}
			}

			//セレクト
			Novice::DrawBox(gameStart.pos.X, gameStart.pos.Y, gameStart.width.X, gameStart.width.Y, 0.0f, gameStart.color, kFillModeSolid);
			if (upIn == 0) {
				Novice::DrawSprite(gameStart.pos.X - 8, gameStart.pos.Y - 8, titleStart1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(gameStart.pos.X - 8, gameStart.pos.Y - 8, titleStart2Handle, 1, 1, 0.0f, WHITE);
			}
			Novice::DrawBox(gameLule.pos.X, gameLule.pos.Y, gameLule.width.X, gameLule.width.Y, 0.0f, gameLule.color, kFillModeSolid);
			if (downIn == 0) {
				Novice::DrawSprite(gameLule.pos.X - 8, gameLule.pos.Y - 8, titleLule1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(gameLule.pos.X - 8, gameLule.pos.Y - 8, titleLule2Handle, 1, 1, 0.0f, WHITE);
			}
			//マウス
			Novice::SetMouseCursorVisibility(0);
			if (Novice::IsPressMouse(0) == 0) {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse2Handle, 1, 1, 0.0f, WHITE);
			}
			break;
		case LULE:
			Novice::GetMousePosition(&mouse.X, &mouse.Y);
			a.pos.momentX = a.pos.X;
			a.pos.momentY = a.pos.Y;
			//アニメーションの時間
			//プレイヤー
			slimeAnimationTime += 1;
			if (slimeAnimationTime >= 60) {
				slimeAnimationTime = 0;
				currentTime = time(nullptr);
				srand(currentTime);
				slimeAnimationType = rand() % 5;
			}
			//ツタ
			if (page == 0) {
				ivyAnimationTime += 1;
				if (ivyAnimationTime >= 40) {
					ivyAnimationTime = 0;
				}
			}
			//プレイヤーの操作
			if (page == 0) {
				if (keys[DIK_A]) {
					a.pos.X -= a.velocity.X;
					if (isClimb == 0) {
						animeDir = LEFT;
					}
				}
				if (keys[DIK_D]) {
					a.pos.X += a.velocity.X;
					if (isClimb == 0) {
						animeDir = RIGHT;
					}
				}
				if (keys[DIK_SPACE] && isGround == 1) {
					a.velocity.Y = 20;
					isGround = 0;
				}
			}
			else {
				if (Novice::IsPressMouse(0) == 0) {
					if (keys[DIK_A] && isShot == 0) {
						a.pos.X -= a.velocity.X;
						if (isClimb == 0) {
							animeDir = LEFT;
						}
					}
					if (keys[DIK_D] && isShot == 0) {
						a.pos.X += a.velocity.X;
						if (isClimb == 0) {
							animeDir = RIGHT;
						}

					}
					if (keys[DIK_SPACE] && isShot == 0 && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
				else if (Novice::IsPressMouse(0) == 1) {
					if (keys[DIK_A]) {
						a.pos.X -= a.velocity.X / 2;
						animeDir = LEFT;
					}
					if (keys[DIK_D]) {
						a.pos.X += a.velocity.X / 2;
						animeDir = RIGHT;
					}
					if (keys[DIK_SPACE] && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
			}

			//マウスで引っ張る
			if (page > 0) {
				Novice::GetMousePosition(&mouse.X, &mouse.Y);
				if (Novice::IsTriggerMouse(0)) {
					slimeShot = 0;
					mouseClick.X = mouse.X;
					mouseClick.Y = mouse.Y;
				}
				if (Novice::IsPressMouse(0)) {
					isShot = 1;
					radian = atan2f((mouseClick.Y - mouse.Y), (mouseClick.X - mouse.X));
					a.dir.X = cosf(radian);
					a.dir.Y = sinf(radian);
					mouseDisX = sqrtf((mouseClick.X - mouse.X) * (mouseClick.X - mouse.X));
					mouseDisY = sqrtf((mouseClick.Y - mouse.Y) * (mouseClick.Y - mouse.Y));
					mouseDragX = mouseDisX;
					mouseDragY = mouseDisY;
					mouseDis = mouseDisX + mouseDisY;
					a.shotVelocity.X = mouseDisX / 4;
					a.shotVelocity.Y = mouseDisY / 4;
				}
				else if (isShot == 1) {
					slimeShot = 1;
					mouseDis = 0.0f;
					a.pos.X += a.dir.X * a.shotVelocity.X;
					a.pos.Y += a.dir.Y * a.shotVelocity.Y;
				}
				else {
					mouseDis = 0.0f;
				}
				if (a.shotVelocity.X > 0.0f && isShot == 1) {
					a.shotVelocity.X -= friction * sqrtf(a.dir.X * a.dir.X);
				}
				else if (a.shotVelocity.X < 0.0f && isShot == 1) {
					a.shotVelocity.X += friction * sqrtf(a.dir.X * a.dir.X);
				}
				if (a.shotVelocity.X <= friction && a.shotVelocity.X >= -friction && isShot == 1) {
					a.shotVelocity.X = 0.0f;
				}

				if (a.shotVelocity.Y > 0.0f && isShot == 1) {
					a.shotVelocity.Y -= friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				else if (a.shotVelocity.Y < 0.0f && isShot == 1) {
					a.shotVelocity.Y += friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				if (a.shotVelocity.Y <= friction && a.shotVelocity.Y >= -friction && isShot == 1) {
					a.shotVelocity.Y = 0.0f;
				}
				if (Novice::IsPressMouse(0) == 0 && a.shotVelocity.X == 0.0f && a.shotVelocity.Y == 0.0f && isShot == 1) {
					isShot = 0;
					slimeShot = 0;
				}
			}
			//重力
			if (isClimb == 0) {
				a.velocity.Y -= 0.8f;
				a.pos.Y -= a.velocity.Y;
			}
			//ツタを登る処理
			if (page == 0) {
				if (a.pos.X > tryIvy.pos.X - a.rX && a.pos.X < tryIvy.pos.X + tryIvy.width.X + a.rX && a.pos.Y >= tryIvy.pos.Y - a.rY) {
					if (keys[DIK_W] && a.pos.Y > tryIvy.pos.Y - a.rY) {
						isClimb = 1;
						a.velocity.Y = 0.0f;
						isGround = 1;
						a.pos.Y -= 6.0f;
						animeDir = CLIMB;
					}
					else if (keys[DIK_S]) {
						isClimb = 1;
						a.velocity.Y = 0.0f;
						isGround = 1;
						a.pos.Y += 6.0f;
						animeDir = CLIMB;
					}
					else if (keys[DIK_SPACE]) {
						if (isClimb == 1) {
							animeDir = LEFT;
						}
						isGround = 0;
						isClimb = 0;
					}
				}
				else {
					if (isClimb == 1) {
						animeDir = LEFT;
					}
					isClimb = 0;
				}
			}
			else {
				if (isClimb == 1) {
					animeDir = LEFT;
				}
				isClimb = 0;
			}
			if (page == 1) {
				//敵を吹き飛ばした時の判定
				if (a.pos.momentY <= tryEnemy.pos.Y - a.rY && tryEnemy.alive == 1 ||
					a.pos.momentX <= tryEnemy.pos.X - a.rX && tryEnemy.alive == 1 ||
					a.pos.momentX >= tryEnemy.pos.X + tryEnemy.rX + a.rX && tryEnemy.alive == 1) {
					if (a.pos.Y >= tryEnemy.pos.Y - a.rY && a.pos.X > tryEnemy.pos.X - a.rX && a.pos.X < tryEnemy.pos.X + tryEnemy.rX + a.rX && a.shotVelocity.Y > 20 &&
						Novice::IsPressMouse(0) != 1 ||
						a.pos.Y >= tryEnemy.pos.Y - a.rY && a.pos.X > tryEnemy.pos.X - a.rX && a.pos.X < tryEnemy.pos.X + tryEnemy.rX + a.rX && a.shotVelocity.X > 20 &&
						Novice::IsPressMouse(0) != 1) {
						a.shotVelocity.Y *= -0.5f;
						a.shotVelocity.X *= -0.5f;
						tryEnemy.alive = 0;
					}
					else if (a.pos.Y >= tryEnemy.pos.Y - a.rY && a.pos.X > tryEnemy.pos.X - a.rX && a.pos.X < tryEnemy.pos.X + tryEnemy.rX + a.rX) {
						a.pos.X = sPosX + 700.0f;
						a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY - 100.0f;
						a.velocity.Y = 0.0f;
						a.shotVelocity.X = 0.0f;
						a.shotVelocity.Y = 0.0f;
					}
				}
				else if (a.pos.Y >= tryEnemy.pos.Y - a.rY && a.pos.X > tryEnemy.pos.X - a.rX && a.pos.X < tryEnemy.pos.X + tryEnemy.rX + a.rX && tryEnemy.alive == 1) {
					a.pos.X = sPosX + 700.0f;
					a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY - 100.0f;
					a.velocity.Y = 0.0f;
					a.shotVelocity.X = 0.0f;
					a.shotVelocity.Y = 0.0f;
				}
				if (tryEnemy.alive == 0 && tryEnemy.color >= WHITE - 0xff) {
					tryEnemy.color -= 10;
				}
				else if (tryEnemy.alive == 0 && tryEnemy.color <= WHITE - 0xff) {
					tryEnemy.alive = 1;
					tryEnemy.color = WHITE;
				}
			}
			//壁
			if (a.pos.X <= tryField.pos.X + a.rX) {
				a.shotVelocity.X *= -1;
				a.pos.X = tryField.pos.X + a.rX;
			}
			else if (a.pos.X >= tryField.pos.X + tryField.width.X - a.rX) {
				a.shotVelocity.X *= -1;
				a.pos.X = tryField.pos.X + tryField.width.X - a.rX;
			}
			if (a.pos.Y >= tryField.pos.Y + tryField.width.Y - a.rY) {
				a.shotVelocity.Y *= -1;
				a.velocity.Y = 0.0f;
				isGround = 1;
				a.pos.Y = tryField.pos.Y + tryField.width.Y - a.rY;
			}
			else if (a.pos.Y <= tryField.pos.Y + a.rY) {
				a.shotVelocity.Y *= -1;
				a.velocity.Y = 0.0f;
				a.pos.Y = tryField.pos.Y + a.rY;
			}
			if (mouse.X < gameNext.pos.X + gameNext.width.X &&
				mouse.X > gameNext.pos.X &&
				mouse.Y < gameNext.pos.Y + gameNext.width.Y &&
				mouse.Y > gameNext.pos.Y && page < 1 ||
				startSceneChange == 1) {
				gameNext.color = RED;
				upIn = 1;
				if (Novice::IsTriggerMouse(0)) {
					page += 1;
					mouseClick.X = mouse.X;
					mouseClick.Y = mouse.Y;
				}
			}
			else {
				gameNext.color = WHITE;
				upIn = 0;
			}
			if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0 && page < 1) {
				gameNext.color = RED;
				upIn = 1;
				page += 1;
			}
			if (mouse.X < gameReturn.pos.X + gameReturn.width.X &&
				mouse.X > gameReturn.pos.X &&
				mouse.Y < gameReturn.pos.Y + gameReturn.width.Y &&
				mouse.Y > gameReturn.pos.Y && startSceneChange == 0 && page > 0) {
				gameReturn.color = BLUE;
				downIn = 1;
				if (Novice::IsTriggerMouse(0)) {
					page -= 1;
				}
			}
			else {
				gameReturn.color = WHITE;
				downIn = 0;
			}
			if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0 && page > 0) {
				gameReturn.color = BLUE;
				downIn = 1;
				page -= 1;
			}
			if (mouse.X < returnTitle.pos.X + returnTitle.width.X &&
				mouse.X > returnTitle.pos.X &&
				mouse.Y < returnTitle.pos.Y + returnTitle.width.Y &&
				mouse.Y > returnTitle.pos.Y ||
				startSceneChange == 1) {
				returnTitle.color = RED;
				returnTitleIn = 1;
				if (Novice::IsTriggerMouse(0)) {
					page = 0;
					returnTitleIn = 0;
					scene = TITLE;
				}
			}
			else {
				returnTitleIn = 0;
				returnTitle.color = WHITE;

			}
			mouseDisX = a.pos.X - mouseClick.X;
			mouseDisY = a.pos.Y - mouseClick.Y;
			Novice::DrawSprite(kwindowsLeft, 0, gameLuleBgHandle, 1, 1, 0.0f, WHITE);
			if (page == 0) {
				Novice::DrawSprite(32, 32 + returnTitle.width.Y, lulePage1Handle, 1, 1, 0.0f, WHITE);
			}
			else if (page == 1) {
				Novice::DrawSprite(32, 32 + returnTitle.width.Y, lulePage2Handle, 1, 1, 0.0f, WHITE);
			}
			Novice::DrawBox(tryField.pos.X, tryField.pos.Y, tryField.width.X, tryField.width.Y, 0.0f, tryField.color, kFillModeSolid);
			if (page == 0) {
				if (ivyAnimationTime < 20) {
					Novice::DrawSprite(tryIvy.pos.X, tryIvy.pos.Y, tryIvy1Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(tryIvy.pos.X, tryIvy.pos.Y, tryIvy2Handle, 1, 1, 0.0f, WHITE);
				}
			}
			//試し敵
			else if (page == 1) {
				Novice::DrawSprite(tryEnemy.pos.X, tryEnemy.pos.Y, tryEnemy1Handle, 1, 1, 0.0f, tryEnemy.color);
			}
			//セレクト
			if (page < 1) {
				if (upIn == 0) {
					Novice::DrawSprite(gameNext.pos.X - 8, gameNext.pos.Y - 8, next1Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(gameNext.pos.X - 8, gameNext.pos.Y - 8, next2Handle, 1, 1, 0.0f, WHITE);
				}
			}
			if (page > 0) {
				if (downIn == 0) {
					Novice::DrawSprite(gameReturn.pos.X - 8, gameReturn.pos.Y - 8, back1Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(gameReturn.pos.X - 8, gameReturn.pos.Y - 8, back2Handle, 1, 1, 0.0f, WHITE);
				}
			}
			Novice::DrawBox(returnTitle.pos.X, returnTitle.pos.Y, returnTitle.width.X, returnTitle.width.Y, 0.0f, returnTitle.color, kFillModeSolid);
			if (returnTitleIn == 0) {
				Novice::DrawSprite(returnTitle.pos.X - 8, returnTitle.pos.Y - 8, backTitle1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(returnTitle.pos.X - 8, returnTitle.pos.Y - 8, backTitle2Handle, 1, 1, 0.0f, WHITE);
			}
			//プレイヤーの描画
			if (page == 0) {
				if (animeDir == LEFT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime1Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime3Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime2Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime4Handle, 1, 1, 0.0f, a.color);
					}
				}
				else if (animeDir == RIGHT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime1Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime3Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime2Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime4Handle, -1, 1, 0.0f, a.color);
					}

				}
				else if (animeDir == CLIMB) {
					Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeBackHandle, 1, 1, 0.0f, a.color);
				}



			}
			else {
				if (Novice::IsPressMouse(0) == 0 && slimeShot == 0) {
					if (animeDir == LEFT) {
						if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationType != 4) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime3Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime2Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationType == 4) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime4Handle, 1, 1, 0.0f, a.color);
						}
					}
					else if (animeDir == RIGHT) {
						if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
							Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime1Handle, -1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationType != 4) {
							Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime3Handle, -1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
							Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime2Handle, -1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationType == 4) {
							Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime4Handle, -1, 1, 0.0f, a.color);
						}

					}
					else if (animeDir == CLIMB) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeBackHandle, 1, 1, 0.0f, a.color);
					}
				}
				else if (Novice::IsPressMouse(0) == 1 && slimeShot == 0) {
					if (mouseDragX > mouseDragY) {
						if (mouse.X - mouseClick.X > 0) {
							if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
								slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
								slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
								Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirSide1Handle, 1, 1, 0.0f, a.color);
							}
							else if (slimeAnimationTime <= 60) {
								Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirSide2Handle, 1, 1, 0.0f, a.color);
							}
						}
						else {
							if (slimeAnimationTime > 0 && slimeAnimationTime < 10 ||
								slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
								slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
								Novice::DrawSprite(a.pos.X + a.rX, a.pos.Y - a.rY, slimeDirSide1Handle, -1, 1, 0.0f, a.color);
							}
							else if (slimeAnimationTime <= 60) {
								Novice::DrawSprite(a.pos.X + a.rX, a.pos.Y - a.rY, slimeDirSide2Handle, -1, 1, 0.0f, a.color);
							}
						}

					}
					else if (mouseDragX <= mouseDragY && slimeShot == 0) {
						if (mouse.Y - mouseClick.Y > 0) {
							if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
								slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
								slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
								Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirUp1Handle, 1, 1, 0.0f, a.color);
							}
							else if (slimeAnimationTime <= 60) {
								Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirUp2Handle, 1, 1, 0.0f, a.color);
							}
						}
						else {
							if (slimeAnimationTime <= 0 && slimeAnimationTime < 10 ||
								slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
								slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
								Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirDown1Handle, 1, 1, 0.0f, a.color);
							}
							else if (slimeAnimationTime <= 60) {
								Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirDown2Handle, 1, 1, 0.0f, a.color);
							}
						}

					}
				}
				else if (slimeShot == 1) {
					if (slimeAnimationTime >= 0 && slimeAnimationTime < 5 ||
						slimeAnimationTime >= 30 && slimeAnimationTime < 35) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot1Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime >= 5 && slimeAnimationTime < 10 ||
						slimeAnimationTime >= 35 && slimeAnimationTime < 40) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot2Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime >= 10 && slimeAnimationTime < 15 ||
						slimeAnimationTime >= 40 && slimeAnimationTime < 45) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot3Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime >= 15 && slimeAnimationTime < 20 ||
						slimeAnimationTime >= 45 && slimeAnimationTime < 50) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot4Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime >= 20 && slimeAnimationTime < 25 ||
						slimeAnimationTime >= 50 && slimeAnimationTime < 55) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot5Handle, 1, 1, 0.0f, a.color);
					}
					else {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot6Handle, 1, 1, 0.0f, a.color);
					}

				}
			}
			//マウス
			Novice::SetMouseCursorVisibility(0);
			if (Novice::IsPressMouse(0) == 0) {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse2Handle, 1, 1, 0.0f, WHITE);
			}
			//引っ張りエフェクト
			if (page > 0) {
				if (Novice::IsPressMouse(0)) {
					Novice::DrawEllipse(mouseClick.X, mouseClick.Y, 10, 10, 0.0f, WHITE, kFillModeSolid);
					Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), WHITE);
					if (a.shotVelocity.Y >= 30 || a.shotVelocity.X >= 30) {
						Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), RED);
					}
				}
			}

			break;
		case STAGE:
			//開始処理
			if (startSceneChange > 0) {
				startSceneChange += 1;
				a.pos.X -= 2;
				a.pos.WorldX -= 2;
				if (startSceneChange == 80) {
					startSceneChange = 0;
				}
			}
			//経過時間
			if (startSceneChange == 0 && devilStartAnimationTime == 0 && a.alive == 1 && sceneChange != 1) {
				counter += 1;
			}
			if (counter == 60) {
				counter = 0;
				timer += 1;
			}
			//残機
			momentSlimeHp = slimeHp;
			if (momentSlimeHp < 1000 && momentSlimeHp >= 0) {
				if (momentSlimeHp >= 10) {
					eachNumber[0] = momentSlimeHp / 10;
					momentSlimeHp = momentSlimeHp % 10;
				}
				else {
					eachNumber[0] = 0;
				}
				if (momentSlimeHp >= 0) {
					eachNumber[1] = momentSlimeHp;
				}
				else {
					eachNumber[1] = 0;
				}
			}

			//アニメーションの時間
			//プレイヤー
			slimeAnimationTime += 1;
			if (slimeAnimationTime >= 60) {
				slimeAnimationTime = 0;
				currentTime = time(nullptr);
				srand(currentTime);
				slimeAnimationType = rand() % 5;
			}
			//ツタ
			ivyAnimationTime += 1;
			if (ivyAnimationTime == 40) {
				ivyAnimationTime = 0;
			}
			//敵
			for (int i = 0; i < maxEnemys; i++) {
				enemyAnimationTime[i] += 1;
				if (enemy[i].alive && enemyAnimationTime[i] == 30) {
					enemyAnimationTime[i] = 0;
					enemyAnimationType[i] *= -1;
				}
			}
			for (int i = 0; i < maxFlyEnemys; i++) {
				jellyfishAnimationTime[i] += 1;
				if (jellyfishAnimationTime[i] >= 60) {
					jellyfishAnimationTime[i] = 0;
				}
			}
			//ドア
			if (boss.alive) {
				skeletonDoorAnimationTime += 1;
				if (skeletonDoorAnimationTime == 80) {
					skeletonDoorAnimationTime = 0;
				}
			}
			else if (boss.alive == 0) {
				if (skeletonEndAnimationTime < 60 && skeletonEndFlag == 0) {
					skeletonEndAnimationTime += 1;
				}
				else {
					skeletonEndFlag = 1;
					skeletonEndAnimationTime = 0;
				}
			}
			if (clearGhost == 0) {
				ghostDoorAnimatioTime += 1;
				if (ghostDoorAnimatioTime == 100) {
					ghostDoorAnimatioTime = 0;
				}
			}
			else if (clearGhost == 1) {
				if (ghostEndAnimationTime < 150 && ghostEndFlag == 0) {
					ghostEndAnimationTime += 1;
				}
				else {
					ghostEndFlag = 1;
					ghostEndAnimationTime = 0;
				}
			}
			if (boss.alive == 0 && clearGhost == 1) {
				devilDoorAnimationTime += 1;
				if (devilDoorAnimationTime == 80) {
					devilDoorAnimationTime = 0;
				}
			}
			//空
			if (clearGhost == 0) {
				skyBgAnimationTime += 1;
				if (skyBgAnimationTime == 120) {
					skyBgAnimationTime = 0;
				}
			}
			else if (clearGhost == 1 && boss.alive == 0 && ghostEndFlag == 1 && skeletonEndFlag == 1) {
				if (devilStartAnimationTime < 120 && devilStartFlag == 0) {
					devilStartAnimationTime += 1;
				}
				else {
					devilStartAnimationTime = 0;
					devilStartFlag = 1;
				}
			}
			if (devilStartAnimationTime == 120) {
				a.pos.X = sPosX;
				a.pos.WorldX = bossDoor[2].pos.X + bossDoor[2].width.X / 2;
				a.pos.Y = sPosY;
				a.pos.WorldY = bossDoor[2].pos.Y + bossDoor[2].width.Y - a.rY - 1;
			}
			//移動前の座標情報
			a.pos.momentX = a.pos.WorldX;
			a.pos.momentY = a.pos.WorldY;

			terrainA.pos.momentX = terrainA.pos.X;
			terrainA.pos.momentY = terrainA.pos.Y;

			for (int i = 0; i < maxEnemys; i++) {
				enemy[i].pos.momentX = enemy[i].pos.X;
				enemy[i].pos.momentY = enemy[i].pos.Y;
			}

			//プレイヤーの操作
			if (a.alive && sceneChange != 1 && devilStartAnimationTime == 0 && ghostEndAnimationTime == 0 && skeletonEndAnimationTime == 0 && startSceneChange == 0) {
				if (Novice::IsPressMouse(0) == 0) {
					if (keys[DIK_A] && isShot == 0) {
						a.pos.X -= a.velocity.X;
						a.pos.WorldX -= a.velocity.X;
						if (isClimb == 0) {
							animeDir = LEFT;
						}
					}
					if (keys[DIK_D] && isShot == 0) {
						a.pos.X += a.velocity.X;
						a.pos.WorldX += a.velocity.X;
						if (isClimb == 0) {
							animeDir = RIGHT;
						}

					}
					if (keys[DIK_SPACE] && isShot == 0 && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
				else if (Novice::IsPressMouse(0) == 1) {
					if (keys[DIK_A]) {
						a.pos.X -= a.velocity.X / 2;
						a.pos.WorldX -= a.velocity.X / 2;
						animeDir = LEFT;
					}
					if (keys[DIK_D]) {
						a.pos.X += a.velocity.X / 2;
						a.pos.WorldX += a.velocity.X / 2;
						animeDir = RIGHT;
					}
					if (keys[DIK_SPACE] && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
			}
			//重力
			if (a.alive == 1 && isClimb == 0) {
				a.velocity.Y -= 0.8f;
				a.pos.Y -= a.velocity.Y;
				a.pos.WorldY -= a.velocity.Y;
			}
			for (int i = 0; i < maxEnemys; i++) {
				if (enemy[i].alive == 1) {
					enemy[i].velocity.Y -= 0.8f;
					enemy[i].pos.Y -= enemy[i].velocity.Y;
				}
			}
			if (icicleDown == 1 && icicle[0].pos.Y < 1000.0f) {
				for (int i = 0; i < 2; i++) {
					icicle[i].velocity.Y -= 0.8f;
					icicle[i].pos.Y -= icicle[i].velocity.Y;
				}
			}
			//マウスで引っ張る
			Novice::GetMousePosition(&mouse.X, &mouse.Y);
			if (a.alive && sceneChange != 1 && devilStartAnimationTime == 0 && ghostEndAnimationTime == 0 && skeletonEndAnimationTime == 0 && startSceneChange == 0) {
				if (Novice::IsTriggerMouse(0)) {
					slimeShot = 0;
					mouseClick.X = mouse.X;
					mouseClick.Y = mouse.Y;
				}
				if (Novice::IsPressMouse(0)) {
					isShot = 1;
					radian = atan2f((mouseClick.Y - mouse.Y), (mouseClick.X - mouse.X));
					a.dir.X = cosf(radian);
					a.dir.Y = sinf(radian);
					mouseDisX = sqrtf((mouseClick.X - mouse.X) * (mouseClick.X - mouse.X));
					mouseDisY = sqrtf((mouseClick.Y - mouse.Y) * (mouseClick.Y - mouse.Y));
					mouseDragX = mouseDisX;
					mouseDragY = mouseDisY;
					mouseDis = mouseDisX + mouseDisY;
					a.shotVelocity.X = mouseDisX / 4;
					a.shotVelocity.Y = mouseDisY / 4;
				}
				else if (isShot == 1) {
					slimeShot = 1;
					mouseDis = 0.0f;
					a.pos.X += a.dir.X * a.shotVelocity.X;
					a.pos.WorldX += a.dir.X * a.shotVelocity.X;
					a.pos.Y += a.dir.Y * a.shotVelocity.Y;
					a.pos.WorldY += a.dir.Y * a.shotVelocity.Y;
				}
				else {
					mouseDis = 0.0f;
				}
				if (a.shotVelocity.X > 0.0f && isShot == 1) {
					a.shotVelocity.X -= friction * sqrtf(a.dir.X * a.dir.X);
				}
				else if (a.shotVelocity.X < 0.0f && isShot == 1) {
					a.shotVelocity.X += friction * sqrtf(a.dir.X * a.dir.X);
				}
				if (a.shotVelocity.X <= friction && a.shotVelocity.X >= -friction && isShot == 1) {
					a.shotVelocity.X = 0.0f;
				}

				if (a.shotVelocity.Y > 0.0f && isShot == 1) {
					a.shotVelocity.Y -= friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				else if (a.shotVelocity.Y < 0.0f && isShot == 1) {
					a.shotVelocity.Y += friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				if (a.shotVelocity.Y <= friction && a.shotVelocity.Y >= -friction && isShot == 1) {
					a.shotVelocity.Y = 0.0f;
				}
				if (Novice::IsPressMouse(0) == 0 && a.shotVelocity.X == 0.0f && a.shotVelocity.Y == 0.0f && isShot == 1) {
					isShot = 0;
					slimeShot = 0;
				}
			}

			//障害物の動き
			terrainA.pos.X -= terrainA.velocity.X;
			if (terrainA.pos.X <= terrain[0].pos.X) {
				terrainA.pos.X = terrain[0].pos.X;
				terrainA.velocity.X *= -1;
			}
			else if (terrainA.pos.X + terrainA.rX >= terrain[9].pos.X + terrain[9].rX) {
				terrainA.pos.X = terrain[9].pos.X + terrain[9].rX - terrainA.rX;
				terrainA.velocity.X *= -1;
			}
			if (a.pos.momentY <= terrainA.pos.Y - a.rY && keys[DIK_A] == 0 && keys[DIK_D] == 0) {
				if (a.pos.WorldY >= terrainA.pos.Y - a.rY && a.pos.WorldX > terrainA.pos.X - a.rX && a.pos.WorldX < terrainA.pos.X + terrainA.rX + a.rX) {
					a.pos.WorldX -= terrainA.velocity.X;
				}
			}
			//障害物の当たり判定X
			for (int i = 0; i < maxTerrains; i++) {
				if (i != 19) {
					a.shotVelocity.X = ClampShotX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, terrainA.pos.X, (terrainA.pos.X + terrainA.rX), terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), a.shotVelocity.X, isGround);
					a.shotVelocity.Y = ClampShotY(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, terrainA.pos.X, (terrainA.pos.X + terrainA.rX), terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), a.shotVelocity.Y, isGround);

					a.pos.WorldX = ClampX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.WorldY, a.rY, terrain[i].pos.X, (terrain[i].pos.X + terrain[i].rX), terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY));
					a.shotVelocity.X = ClampShotX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, terrain[i].pos.X, (terrain[i].pos.X + terrain[i].rX), terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), a.shotVelocity.X, isGround);

				}
				else {
					a.pos.WorldX = ClampX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.WorldY, a.rY, terrain[i].pos.X, (terrain[i].pos.X + terrain[i].rX), terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY));
					a.shotVelocity.X = spClampShotX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, terrain[i].pos.X, (terrain[i].pos.X + terrain[i].rX), terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), a.shotVelocity.X, isGround);

				}
			}
			for (int i = 9; i < maxFreeBlocks; i++) {
				a.pos.WorldX = ClampX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.WorldY, a.rY, freeBlock[i].pos.X, (freeBlock[i].pos.X + freeBlock[i].width.X), freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y));
				a.shotVelocity.X = ClampShotX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, freeBlock[i].pos.X, (freeBlock[i].pos.X + freeBlock[i].width.X), freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), a.shotVelocity.X, isGround);
				isGround = ClampGround(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X, isGround);
				a.velocity.Y = ClampVelocityY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X, a.velocity.Y);
				a.pos.WorldY = ClampY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X);

			}
			//障害物の当たり判定Y
			for (int i = 0; i < maxTerrains; i++) {
				if (i != 19) {
					a.pos.WorldY = ClampY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), terrainA.pos.X, terrainA.pos.X + terrainA.rX);
					isGround = ClampGround(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), terrainA.pos.X, terrainA.pos.X + terrainA.rX, isGround);
					a.velocity.Y = ClampVelocityY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), terrainA.pos.X, terrainA.pos.X + terrainA.rX, a.velocity.Y);
					a.shotVelocity.Y = ClampShotY(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, terrain[i].pos.X, (terrain[i].pos.X + terrain[i].rX), terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), a.shotVelocity.Y, isGround);

					a.pos.WorldY = ClampY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), terrain[i].pos.X, terrain[i].pos.X + terrain[i].rX);
					isGround = ClampGround(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), terrain[i].pos.X, terrain[i].pos.X + terrain[i].rX, isGround);
					a.velocity.Y = ClampVelocityY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), terrain[i].pos.X, terrain[i].pos.X + terrain[i].rX, a.velocity.Y);
				}
				else {
					a.pos.WorldY = spClampY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), terrain[i].pos.X, terrain[i].pos.X + terrain[i].rX);
					isGround = ClampGround(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), terrain[i].pos.X, terrain[i].pos.X + terrain[i].rX, isGround);
					a.velocity.Y = spClampVelocityY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), terrain[i].pos.X, terrain[i].pos.X + terrain[i].rX, a.velocity.Y);
					a.shotVelocity.Y = spClampShotY(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, terrain[i].pos.X, (terrain[i].pos.X + terrain[i].rX), terrain[i].pos.Y, (terrain[i].pos.Y + terrain[i].rY), a.shotVelocity.Y, isGround);

				}


			}
			//敵の当たり判定
			for (int i = 0; i < maxEnemys; i++) {
				if (treadEnemy[i] == 0 && enemy[i].alive) {
					//敵の動き
					enemy[i].pos.X += enemy[i].velocity.X;
					//敵が障害物と当たった時の判定
					for (int j = 0; j < maxTerrains; j++) {
						enemy[i].velocity.X = ClampEnemyReflectX(enemy[i].pos.momentX, enemy[i].pos.X, enemy[i].rX, enemy[i].pos.momentY, enemy[i].pos.Y, enemy[i].rY, terrain[j].pos.X, (terrain[j].pos.X + terrain[j].rX), terrain[j].pos.Y, (terrain[j].pos.Y + terrain[j].rY), enemy[i].velocity.X);
					}
				}
				//敵を吹き飛ばした時の判定
				if (a.pos.momentY <= enemy[i].pos.Y - a.rY && treadEnemy[i] == 0 && a.alive == 1 ||
					a.pos.momentX <= enemy[i].pos.X - a.rX && treadEnemy[i] == 0 && a.alive == 1 ||
					a.pos.momentX >= enemy[i].pos.X + a.rX && treadEnemy[i] == 0 && a.alive == 1) {
					if (a.pos.WorldY >= enemy[i].pos.Y - a.rY && a.pos.WorldX > enemy[i].pos.X - a.rX && a.pos.WorldX < enemy[i].pos.X + enemy[i].rX + a.rX && a.shotVelocity.Y > 20 &&
						Novice::IsPressMouse(0) != 1 && a.alive == 1 ||
						a.pos.WorldY >= enemy[i].pos.Y - a.rY && a.pos.WorldX > enemy[i].pos.X - a.rX && a.pos.WorldX < enemy[i].pos.X + enemy[i].rX + a.rX && a.shotVelocity.X > 20 &&
						Novice::IsPressMouse(0) != 1 && a.alive == 1) {
						a.shotVelocity.Y *= -0.5f;
						a.shotVelocity.X *= -0.5f;
						slimeHp += 1;
						score += 10;
						treadEnemy[i] = 1;
						if (a.isSpace == 1) {
							a.isSpace = 0;
							a.back = 1;
						}
						else {
							a.back = 0;
							a.isSpace = 1;
						}
					}
					else if (a.pos.WorldY >= enemy[i].pos.Y - a.rY && a.pos.WorldX > enemy[i].pos.X - a.rX && a.pos.WorldX < enemy[i].pos.X + enemy[i].rX + a.rX) {
						hitEnemy = 1;
						a.color = RED;
						a.velocity.Y = 0.0f;
						a.alive = 0;
					}
				}
				if (treadEnemy[i] == 1) {
					enemy[i].pos.Y += 1;
					enemy[i].rY -= 1;
					enemy[i].color -= 0xff / 150;
				}
				if (enemy[i].rY <= 0) {
					treadEnemy[i] = 0;
					enemy[i].alive = 0;
					enemy[i].pos.X = -1000;
				}
				//敵とプレイヤーの接触判定
				if (treadEnemy[i] == 0) {
					a.pos.WorldX = ClampX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.WorldY, a.rY, enemy[i].pos.X, (enemy[i].pos.X + enemy[i].rX), enemy[i].pos.Y, (enemy[i].pos.Y + enemy[i].rY));
					a.pos.WorldY = ClampY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.WorldX, a.rX, enemy[i].pos.Y, (enemy[i].pos.Y + enemy[i].rY), enemy[i].pos.X, enemy[i].pos.X + enemy[i].rX);
					isHitEnemy[0] = HitX(a.pos.momentX, a.pos.WorldX, a.rX, a.pos.WorldY, a.rY, enemy[i].pos.X, (enemy[i].pos.X + enemy[i].rX), enemy[i].pos.Y, (enemy[i].pos.Y + enemy[i].rY), isHitEnemy[0]);
					if (isHitEnemy[0] == 1 && a.alive == 1) {
						hitEnemy = 1;
						a.color = RED;
						a.velocity.Y = 0.0f;
						a.alive = 0;
					}
					else if (isHitEnemy[0] == 2 && a.alive == 1) {
						hitEnemy = 1;
						a.color = RED;
						a.velocity.Y = 0.0f;
						a.alive = 0;
					}
				}
				//敵が壁に当たった判定
				if (kwindowsLeft >= enemy[i].pos.X && enemy[i].alive == 1) {
					enemy[i].pos.X = kwindowsLeft;
					enemy[i].velocity.X *= -1;
				}
				if (enemy[i].pos.X + enemy[i].rX >= bgX[maxMapX - 1].X + kwindowsRight && enemy[i].alive == 1) {
					enemy[i].pos.X = bgX[maxMapX - 1].X + kwindowsRight - enemy[i].rX;
					enemy[i].velocity.X *= -1;
				}
				//上下の当たり判定
				if (enemy[i].pos.Y <= bgY[maxMapY - 1].pos.Y) {
					enemy[i].pos.Y = bgY[maxMapY - 1].pos.Y;
				}
				if (enemy[i].pos.Y + enemy[i].rY >= kwindowsDown - ground.width.WorldY && enemyIsHole[i] == 0) {
					enemy[i].velocity.Y = 0.0f;
					enemy[i].pos.Y = kwindowsDown - enemy[i].rY - ground.width.WorldY;
				}
				//敵が穴に落ちる判定
				for (int j = 0; j < 10; j++) {
					if (enemy[i].pos.X >= hole[j].pos.X && enemy[i].pos.X + enemy[i].rX <= hole[j].pos.X + hole[j].width.X) {
						enemyIsHole[i] = 1;
					}
				}
				if (enemy[i].pos.Y > kwindowsDown) {
					enemy[i].alive = 0;
					enemy[i].pos.X = -1000;
				}
			}
			//氷柱の当たり判定
			for (int i = 0; i < 2; i++) {
				if (icicleDown == 0 && a.alive || icicleDown == 1 && a.alive) {
					disX = (a.pos.WorldX - icicle[0].pos.X) * (a.pos.WorldX - icicle[0].pos.X);
					disY = (a.pos.WorldY - icicle[0].pos.Y) * (a.pos.WorldY - icicle[0].pos.Y);
					dis = sqrtf(disX + disY);
					if (dis <= a.rX + icicle[0].rX * 25) {
						icicle[i].color = RED;
						disX = (a.pos.WorldX - icicle[i].pos.X) * (a.pos.WorldX - icicle[i].pos.X);
						disY = (a.pos.WorldY - icicle[i].pos.Y) * (a.pos.WorldY - icicle[i].pos.Y);
						dis = sqrtf(disX + disY);
						if (icicleTime == 0) {
							icicleTime += 1;
						}
						if (dis <= a.rX + icicle[i].rX) {
							a.color = RED;
							a.alive = 0;
							hitEnemy = 1;
						}
					}
					else {
						icicle[i].color = BLUE;
					}
				}
			}
			if (icicleTime > 0 && icicleTime < 120) {
				icicleTime += 1;
			}
			else if (icicleTime > 0) {
				icicleDown = 1;
				if (icicleDown == 1) {
					icicleTime += 1;
				}
				if (icicleTime > 300) {
					icicleDown = 0;
					icicleTime = 0;
					for (int i = 0; i < 2; i++) {
						icicle[i].velocity.Y = 0.0f;
						icicleDown = 0;
						icicleTime = 0;
						icicle[i].pos.X = 900.0f;
						icicle[i].pos.Y = freeBlock[9].pos.Y + freeBlock[9].width.Y;
					}
				}
			}
			//空飛ぶ敵の当たり判定
			for (int i = 0; i < maxFlyEnemys; i++) {
				flyEnemyRadian[i] += M_PI / 180;
				if (cosf(flyEnemyRadian[i]) > 0) {
					flyEnemy[i].pos.X -= flyEnemy[i].velocity.X * cosf(flyEnemyRadian[i] / (1 + i));
					flyEnemy[i].pos.Y += flyEnemy[i].velocity.Y * sinf(flyEnemyRadian[i]);
				}
				else if (cosf(flyEnemyRadian[i]) < 0) {
					flyEnemy[i].pos.X -= flyEnemy[i].velocity.X * cosf(flyEnemyRadian[i] / (1 + i));
					flyEnemy[i].pos.Y -= flyEnemy[i].velocity.Y * sinf(flyEnemyRadian[i]);
				}
				if (flyEnemy[i].pos.X >= kwindowsRight * 3 - flyEnemy[i].rX) {
					flyEnemy[i].velocity.X *= -1;
				}
				else if (flyEnemy[i].pos.X <= kwindowsRight * 2 + flyEnemy[i].rX) {
					flyEnemy[i].velocity.X *= -1;
				}
				disX = (a.pos.WorldX - flyEnemy[i].pos.X) * (a.pos.WorldX - flyEnemy[i].pos.X);
				disY = (a.pos.WorldY - flyEnemy[i].pos.Y) * (a.pos.WorldY - flyEnemy[i].pos.Y);
				dis = sqrtf(disX + disY);
				if (dis <= a.rX + flyEnemy[i].rX && a.alive == 1) {
					hitEnemy = 1;
					a.color = RED;
					a.alive = 0;
				}

			}
			//ファイアバーの当たり判定
			for (int i = 0; i < maxBar; i++) {
				barRadian[i] += M_PI / 180;
				for (int j = 0; j < barNumber; j++) {
					bar[i][j].pos.X = bar[i][j].pos.startX * cosf(barRadian[i]) - bar[i][j].pos.startY * sinf(barRadian[i]) + terrain[i].pos.X + terrain[i].rX / 2;
					bar[i][j].pos.Y = bar[i][j].pos.startY * cosf(barRadian[i]) + bar[i][j].pos.startX * sinf(barRadian[i]) + terrain[i].pos.Y + terrain[i].rY / 2;
					disX = (a.pos.WorldX - bar[i][j].pos.X) * (a.pos.WorldX - bar[i][j].pos.X);
					disY = (a.pos.WorldY - bar[i][j].pos.Y) * (a.pos.WorldY - bar[i][j].pos.Y);
					dis = sqrtf(disX + disY);
					if (dis < a.rX + bar[i][j].rX && a.alive == 1) {
						isHitBar = 1;
						a.alive = 0;
					}
					dis = 0.0f;
				}

			}
			//ツタを登る処理
			if (a.alive && a.pos.WorldX > rope.pos.X - a.rX && a.pos.WorldX < rope.pos.X + rope.width.X + a.rX && a.pos.WorldY >= rope.pos.Y - a.rY &&
				a.shotVelocity.X == 0.0f && a.shotVelocity.Y == 0.0f) {
				if (keys[DIK_W] && a.pos.WorldY > rope.pos.Y - a.rY) {
					isClimb = 1;
					a.velocity.Y = 0.0f;
					isGround = 1;
					a.pos.Y -= 6.0f;
					a.pos.WorldY -= 6.0f;
					animeDir = CLIMB;
				}
				else if (keys[DIK_S]) {
					isClimb = 1;
					a.velocity.Y = 0.0f;
					isGround = 1;
					a.pos.Y += 6.0f;
					a.pos.WorldY += 6.0f;
					animeDir = CLIMB;
				}
				else if (keys[DIK_SPACE]) {
					if (isClimb == 1) {
						animeDir = LEFT;
					}
					isGround = 0;
					isClimb = 0;
				}
			}
			else {
				if (isClimb == 1) {
					animeDir = LEFT;
				}
				isClimb = 0;
			}
			//ボス部屋に移動.シーンチェンジ
			for (int i = 0; i < maxBoss; i++) {
				if (a.pos.WorldX - a.rX <= bossDoor[i].pos.X + bossDoor[i].width.X && a.pos.WorldX + a.rX >= bossDoor[i].pos.X && a.pos.WorldY + a.rY >= bossDoor[i].pos.Y && a.pos.WorldY - a.rY <= bossDoor[i].pos.Y + bossDoor[i].width.Y) {
					if (i == 0 && clearSkeleton == 0) {
						if (keys[DIK_S] && preKeys[DIK_S] == 0 && sceneChange != 1 ||
							keys[DIK_W] && preKeys[DIK_W] == 0 && sceneChange != 1) {
							doorType[i] = 1;
							sceneChange = 2;
						}
					}
					else if (i == 2 && clearGhost == 1 && clearSkeleton == 1 && sceneChange != 1) {
						if (keys[DIK_S] && preKeys[DIK_S] == 0 ||
							keys[DIK_W] && preKeys[DIK_W] == 0) {
							doorType[i] = 1;
							sceneChange = 2;
						}
					}
					else if (i == 1 && clearGhost == 0 && sceneChange != 1) {
						if (keys[DIK_S] && preKeys[DIK_S] == 0 ||
							keys[DIK_W] && preKeys[DIK_W] == 0) {
							doorType[i] = 1;
							sceneChange = 2;
						}
					}

					if (sceneChange == 2 && doorType[i] == 1) {
						if (luleSizeX < 1.0f - 0.025f) {
							luleSizeX += 0.025f;
							luleSizeY += 0.025f;
						}
						else {
							luleSizeX = 1.0f;
							luleSizeY = 1.0f;
						}
						if (popUp[0].width.X < 600) {
							popUp[0].width.X += 15;
							popUp[0].pos.X -= 15 / 2;
							popUp[0].width.Y += 15 * 0.5;
							popUp[0].pos.Y -= (15 * 0.5) / 2;
						}
						else {
							popUp[1].width.X = 120;
							popUp[1].pos.X = popUp[0].pos.X + 50;
							popUp[1].width.Y = 50;
							popUp[1].pos.Y = popUp[0].pos.Y + popUp[0].width.Y + 10;
							popUp[2].width.X = 120;
							popUp[2].pos.X = popUp[0].pos.X + popUp[0].width.X - 170;
							popUp[2].width.Y = 50;
							popUp[2].pos.Y = popUp[0].pos.Y + popUp[0].width.Y + 10;
							if (mouse.X >= popUp[1].pos.X && mouse.X <= popUp[1].pos.X + popUp[1].width.X &&
								mouse.Y >= popUp[1].pos.Y && mouse.Y <= popUp[1].pos.Y + popUp[1].width.Y) {
								popUpColor[1] = RED;
								leftIn = 1;
								if (Novice::IsTriggerMouse(0)) {
									sceneChange = 1;
								}
							}
							else {
								popUpColor[1] = BLACK;
								leftIn = 0;
							}
							if (mouse.X >= popUp[2].pos.X && mouse.X <= popUp[2].pos.X + popUp[2].width.X &&
								mouse.Y >= popUp[2].pos.Y && mouse.Y <= popUp[2].pos.Y + popUp[2].width.Y) {
								popUpColor[2] = BLUE;
								rightIn = 1;
								if (Novice::IsTriggerMouse(0)) {
									luleSizeX = 0.0f;
									luleSizeY = 0.0f;
									popUp[1].pos.X = -1000;
									popUp[2].pos.X = -1000;
									popUp[0].pos.X = kwindowsLeft + kwindowsRight / 2;
									popUp[0].pos.Y = kwindowsUp + kwindowsDown / 2;
									popUp[0].width.X = 0.0f;
									popUp[0].width.Y = 0.0f;
									popUp[1].width.X = 0;
									popUp[1].width.Y = 0;
									popUp[2].width.X = 0;
									popUp[2].width.Y = 00;
									sceneChange = 0;

								}
							}
							else {
								popUpColor[2] = BLACK;
								rightIn = 0;
							}
						}
					}
					if (a.pos.WorldX > bossDoor[i].pos.X + (bossDoor[i].width.X / 2) && sceneChange == 1 && doorType[i] == 1) {
						animeDir = LEFT;
						a.pos.WorldX -= 1;
						a.pos.X -= 1;
						if (a.pos.WorldX < bossDoor[i].pos.X + (bossDoor[i].width.X / 2)) {
							a.pos.WorldX = bossDoor[i].pos.X + (bossDoor[0].width.X / 2);
						}
					}
					else if (a.pos.WorldX < bossDoor[i].pos.X + (bossDoor[i].width.X / 2) && sceneChange == 1 && doorType[i] == 1) {
						animeDir = RIGHT;
						a.pos.WorldX += 1;
						a.pos.X += 1;
						if (a.pos.WorldX > bossDoor[i].pos.X + (bossDoor[i].width.X / 2)) {
							a.pos.WorldX = bossDoor[i].pos.X + (bossDoor[i].width.X / 2);
						}
					}
					else if (sceneChange == 1 && doorType[i] == 1) {
						currentTime = time(nullptr);
						srand(currentTime);
						atackTime = rand() % 5;
						for (int i = 0; i < 5; i++) {
							if (atackTime == i) {
								atackTime = 60 + i * 60;
							}
						}
						//ボス部屋ごとの代入
						//スケルトン
						if (i == 0) {
							bossAtackCollision[0].pos.X = -1000;
							terrainA.pos.X = 700.0f;
							terrainA.pos.Y = 500;
							terrainA.rX = 200.0f;
							terrainA.rY = 40.0f;
							terrainA.velocity.X = 5.0f;
							boss.alive = 1;
							defeatMotion = 0;
						}
						//ダンジョン
						else if (i == 1) {
							a.pos.X = kwindowsLeft + a.rX + 400.0f;
							a.pos.WorldX = a.pos.X;
							a.pos.Y = kwindowsDown - ground.width.WorldY - a.rY;
							a.pos.WorldY = a.pos.Y;
							ghost[0].alive = 1;
							sY = 0.0f;
							atackTime = 0.0f;
						}
						//魔王
						else if (i == 2) {
							sX = 640;
							a.pos.X = 640;
							a.pos.WorldX = a.pos.X + sX;
							a.pos.Y = kwindowsDown - ground.width.WorldY - a.rY;
							a.pos.WorldY = a.pos.Y;
						}
						scene = STAGEBOSS + i;
						luleSizeX = 0.0f;
						luleSizeY = 0.0f;
						popUp[0].pos.X = kwindowsLeft + kwindowsRight / 2;
						popUp[0].pos.Y = kwindowsUp + kwindowsDown / 2;
						popUp[0].width.X = 0.0f;
						popUp[0].width.Y = 0.0f;
						popUp[1].width.X = 0;
						popUp[1].width.Y = 0;
						popUp[2].width.X = 0;
						popUp[2].width.Y = 0;
						sceneChange = 0;

					}
				}
				else {
					doorType[i] = 0;
				}
			}
			if (doorType[0] == 0 && doorType[1] == 0 && doorType[2] == 0) {
				luleSizeX = 0.0f;
				luleSizeY = 0.0f;
				popUp[0].pos.X = kwindowsLeft + kwindowsRight / 2;
				popUp[0].pos.Y = kwindowsUp + kwindowsDown / 2;
				popUp[0].width.X = 0.0f;
				popUp[0].width.Y = 0.0f;
				popUp[1].width.X = 0;
				popUp[1].width.Y = 0;
				popUp[2].width.X = 0;
				popUp[2].width.Y = 0;
				popUp[1].pos.X = -1000;
				popUp[2].pos.X = -1000;
				sceneChange = 0;
			}

			//穴
			for (int i = 0; i < 10; i++) {
				if (a.pos.WorldX >= hole[i].pos.X + a.rX && a.pos.WorldX <= hole[i].pos.X + hole[i].width.X - a.rX) {
					isHole = 1;
					if (a.pos.WorldY < kwindowsDown - a.rY - ground.width.WorldY) {
						isHole = 0;
					}
				}
			}
			if (a.pos.WorldY > kwindowsDown + a.rY + 50) {
				a.alive = 0;
			}
			//復活処理
			if (a.alive == 0) {
				if (isHitBar == 1) {
					a.color -= 5;
				}
				if (isHitBar && a.color <= WHITE - 0xff) {
					a.alive = 1;
				}
				if (hitEnemy == 1) {
					a.color -= 5;
				}
				if (a.color <= RED - 0xff && hitEnemy == 1) {
					a.alive = 1;
				}
				if (isHole == 1) {
					a.alive = 1;
				}
				if (a.alive == 1) {
					slimeHp -= 1;
					//ゲームオーバー処理
					if (slimeHp <= -1) {
						scene = GAMEOVER;
					}
					//復活
					else {
						isHitBar = 0;
						hitEnemy = 0;
						isHole = 0;
						a.color = WHITE;
						a.alive = 1;
						a.velocity.Y = 0.0f;
						a.shotVelocity.X = 0.0f;
						a.shotVelocity.Y = 0.0f;
						a.pos.X = startA.pos.X;
						a.pos.WorldX = startA.pos.WorldX;
						a.pos.Y = startA.pos.Y;
						a.pos.WorldY = startA.pos.WorldY;

					}
				}

			}
			//壁の当たり判定
			if (kwindowsLeft + a.rX >= a.pos.X) {
				a.shotVelocity.X *= -1;
				a.pos.X = kwindowsLeft + a.rX;
				a.pos.WorldX = a.pos.X;
			}
			if (kwindowsRight - a.rX <= a.pos.X && startSceneChange == 0) {
				a.shotVelocity.X *= -1;
				a.pos.X = kwindowsRight - a.rX;
				a.pos.WorldX = a.pos.X + bgX[3].X;
			}
			//上下の当たり判定
			if (kwindowsUp + a.rY >= a.pos.Y) {
				a.shotVelocity.Y *= -0.5f;
				a.shotVelocity.X *= 0.5f;
				a.pos.Y = kwindowsUp + a.rY;
				a.pos.WorldY = bgY[2].pos.Y + a.rY;
			}
			if (kwindowsDown - a.rY - ground.width.WorldY <= a.pos.Y && isHole == 0) {
				a.shotVelocity.Y *= -0.5;
				a.shotVelocity.X *= 0.5;
				isGround = 1;
				a.velocity.Y = 0.0f;
				a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY;
				a.pos.WorldY = kwindowsDown - a.rX - ground.width.WorldY;
			}
			else if (isHole == 1) {
				isGround = 0;
			}
			//滝の動き
			for (int i = 0; i < 2; i++) {
				waterfall[i].pos.Y += 5;
				if (waterfall[0].pos.Y >= kwindowsDown) {
					waterfall[0].pos.Y = -720.0f * 2;
					waterfall[1].pos.Y = -1440.0f - 1 * 720 * 3;
				}
			}

			//スクロール位置の操作
			if (keys[DIK_LEFT]) {
				sPosX -= sSpeed;
			}
			if (keys[DIK_RIGHT]) {
				sPosX += sSpeed;
			}

			//スクロール値Xの計算
			if (a.pos.WorldX >= sPosX && a.pos.WorldX <= bgX[3].X + sPosX) {
				a.pos.X = sPosX;
				sX = a.pos.WorldX - sPosX;
			}
			if (a.pos.WorldX <= sPosX) {
				a.pos.X = a.pos.WorldX;
				sX = 0;
			}
			if (a.pos.WorldX >= bgX[3].X + sPosX) {
				sX = bgX[3].X;
				//a.pos.WorldX = a.pos.X + sX;
				a.pos.X = a.pos.WorldX - sX;
			}
			//スクロール値Yの計算
			if (a.pos.WorldY <= sPosY && a.pos.WorldY >= bgY[2].pos.Y + sPosY) {
				a.pos.Y = sPosY;
				sY = a.pos.WorldY - a.pos.Y;
			}
			if (a.pos.WorldY >= sPosY) {
				a.pos.Y = a.pos.WorldY;
				sY = 0;
			}
			if (a.pos.WorldY <= bgY[2].pos.Y + sPosY) {
				sY = bgY[2].pos.Y;
				a.pos.Y = a.pos.WorldY - sY;

			}
			mouseDisX = a.pos.X - mouseClick.X;
			mouseDisY = a.pos.Y - mouseClick.Y;

			//
			if (keys[DIK_B] && preKeys[DIK_B] == 0) {
				if (a.isSpace == 1) {
					a.isSpace = 0;
					a.back = 1;
				}
				else {
					a.back = 0;
					a.isSpace = 1;
				}
			}
			if (a.isSpace == 1 && a.back == 0 && a.reflect != a.maxReflect) {
				a.frame += 1;
				if (a.stop == 0) {
					a.t += a.tIncrement;
					a.easeT = a.t * a.t;
				}
				if (a.easeT > 1.2f && a.reflect < a.maxReflect && a.reflect % 2 == 0) {
					a.tIncrement *= -1;
					a.reflect += 1;

				}
				else if (a.easeT < 0.8f && a.reflect % 2 == 1 && a.reflect < a.maxReflect) {
					a.tIncrement *= -1;
					a.reflect += 1;
				}
				if (a.reflect == a.maxReflect) {
					a.vibration = 0;
					a.isSpace = 0;
					a.back = 1;
				}
				a.vibration = (1.0f - a.easeT) * 0 + a.easeT * 16;
			}
			else  {
				if (a.easeT > 0.0f) {
					a.easeT -= 0.1f;
				}
				else {
					a.easeT = 0.0f;
				}
				a.tIncrement = 0.2f;
				a.reflect = 0;
				a.easeT = 0.0f;
				a.t = 0.0f;
				a.frame = 0;
				a.stop = 0;
				a.vibration = 0.0f;
			}



			///
			/// ↑更新処理ここまで
			///

			///
			/// ↓描画処理ここから
			///

			//マップの画像
			Novice::DrawSprite(freeBlock[9].pos.X - sX - a.vibration, freeBlock[9].pos.Y - 200 - sY, forestGroundHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(0 - sX - a.vibration, 0 - sY, caveBgHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(2000 - sX - a.vibration, kwindowsDown * -1 - sY, cliffBgHandle, 1, 1, 0.0f, WHITE);
			if (boss.alive == 0 && clearGhost == 1) {
				Novice::DrawSprite(bgY[2].pos.X - sX - a.vibration, bgY[2].pos.Y - sY, devilStartBgHandle, 1, 1, 0.0f, WHITE);
			}
			for (int i = 0; i < 2; i++) {
				Novice::DrawSprite(hole[1].pos.X + 25 - sX - a.vibration, waterfall[i].pos.Y - sY, waterfallBgHandle, 1, 1, 0.0f, WHITE);
			}
			Novice::DrawSprite(hole[1].pos.X + 25 - sX - a.vibration, kwindowsDown * -1 - sY, waterfallGround, 1, 1, 0.0f, WHITE);
			if (clearGhost == 0 || ghostEndAnimationTime < 75) {
				if (skyBgAnimationTime < 60) {
					Novice::DrawSprite(bgY[2].pos.X - sX - a.vibration, bgY[2].pos.Y - sY, forestBg1Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(bgY[2].pos.X - sX - a.vibration, bgY[2].pos.Y - sY, forestBg2Handle, 1, 1, 0.0f, WHITE);
				}
			}
			//地面の描画
			Novice::DrawSprite(ground.pos.WorldX - sX - a.vibration, ground.pos.WorldY - sY, groundHandle, 1, 1, 0.0f, WHITE);
			//ツタの描画
			if (ivyAnimationTime < 20) {
				Novice::DrawSprite(rope.pos.X - sX - a.vibration, rope.pos.Y - sY, ivy1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(rope.pos.X - sX - a.vibration, rope.pos.Y - sY, ivy2Handle, 1, 1, 0.0f, WHITE);
			}
			//敵の描画
			for (int i = 0; i < maxEnemys; i++) {
				if (enemy[i].alive == 1 && enemyAnimationTime[i] < 15) {
					Novice::DrawSprite(enemy[i].pos.X - sX - a.vibration, enemy[i].pos.Y - sY, enemy1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (enemy[i].alive == 1 && enemyAnimationType[i] == 1) {
					Novice::DrawSprite(enemy[i].pos.X - sX - a.vibration, enemy[i].pos.Y - sY, enemy2Handle, 1, 1, 0.0f, WHITE);
				}
				else if (enemy[i].alive == 1 && enemyAnimationType[i] == -1) {
					Novice::DrawSprite(enemy[i].pos.X - sX - a.vibration + enemy[i].rX, enemy[i].pos.Y - sY, enemy2Handle, -1, 1, 0.0f, WHITE);
				}
			}
			//障害物の描画
			Novice::DrawBox(terrainA.pos.X - sX - a.vibration, terrainA.pos.Y - sY, terrainA.rX, terrainA.rY, 0.0f, WHITE, kFillModeSolid);
			for (int i = 0; i < maxTerrains; i++) {
				if (i != 19 && i >= 10) {
					Novice::DrawSprite(terrain[i].pos.X - sX - a.vibration, terrain[i].pos.Y - sY, wall2Handle, 1, 1, 0.0f, WHITE);
				}
			}
			Novice::DrawSprite(freeBlock[9].pos.X - sX - a.vibration, freeBlock[9].pos.Y - sY, caveUpHandle, 1, 1, 0.0f, WHITE);
			for (int i = 10; i < 14; i++) {
				Novice::DrawSprite(terrain[i].pos.X - sX - a.vibration, terrain[i].pos.Y - sY, wall1Handle, 1, 1, 0.0f, WHITE);
			}
			Novice::DrawSprite(terrain[24].pos.X - sX - a.vibration, terrain[24].pos.Y - sY, startGroundHandle, 1, 1, 0.0f, WHITE);
			if (icicleDown == 0) {
				if (icicleTime < 40) {
					Novice::DrawSprite(icicle[0].pos.X - icicle[0].rX - sX - a.vibration, icicle[0].pos.Y - icicle[0].rY - sY, icicle1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (icicleTime < 100) {
					Novice::DrawSprite(icicle[0].pos.X - icicle[0].rX - sX - a.vibration, icicle[0].pos.Y - icicle[0].rY - sY, icicle2Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(icicle[0].pos.X - icicle[0].rX - sX - a.vibration, icicle[0].pos.Y - icicle[0].rY - sY, icicle3Handle, 1, 1, 0.0f, WHITE);
				}

			}
			else {
				Novice::DrawSprite(icicle[0].pos.X - icicle[0].rX - sX - a.vibration, icicle[0].pos.Y - icicle[0].rY - sY, icicle4Handle, 1, 1, 0.0f, WHITE);
			}
			//スクロール位置
			Novice::DrawLine(sPosX, kwindowsUp, sPosX, kwindowsDown, 0x00000000);
			//ボス部屋の扉
			if (clearGhost == 0) {
				if (ghostDoorAnimatioTime < 25) {
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostDoor1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (ghostDoorAnimatioTime < 50) {
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostDoor2Handle, 1, 1, 0.0f, WHITE);
				}
				else if (ghostDoorAnimatioTime < 75) {
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostDoor3Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostDoor4Handle, 1, 1, 0.0f, WHITE);
				}
			}
			else if (clearGhost == 1) {
				if (ghostEndAnimationTime < 25 && ghostEndFlag == 0) {
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostEndDoor1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (ghostEndAnimationTime < 50 && ghostEndFlag == 0) {
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostEndDoor2Handle, 1, 1, 0.0f, WHITE);
				}
				else if (ghostEndAnimationTime < 75 && ghostEndFlag == 0) {
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostEndDoor3Handle, 1, 1, 0.0f, WHITE);

				}
				else if (ghostEndAnimationTime < 100 && ghostEndFlag == 0) {
					Novice::DrawSprite(bgY[2].pos.X - sX - a.vibration, bgY[2].pos.Y - sY, forestEndBg1Handle, 1, 1, 0.0f, WHITE);
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostEndDoor4Handle, 1, 1, 0.0f, WHITE);
				}
				else if (ghostEndAnimationTime < 125 && ghostEndFlag == 0) {
					Novice::DrawSprite(bgY[2].pos.X - sX - a.vibration, bgY[2].pos.Y - sY, forestEndBg2Handle, 1, 1, 0.0f, WHITE);
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostEndDoor5Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					if (boss.alive == 1) {
						Novice::DrawSprite(bgY[2].pos.X - sX - a.vibration, bgY[2].pos.Y - sY, forestEndBg3Handle, 1, 1, 0.0f, WHITE);
					}
					else {
						Novice::DrawSprite(bgY[2].pos.X - sX - a.vibration, bgY[2].pos.Y - sY, devilStartBgHandle, 1, 1, 0.0f, WHITE);
					}
					Novice::DrawSprite(bossDoor[1].pos.X - 50 - sX - a.vibration, bossDoor[1].pos.Y - 100 - sY, ghostEndDoor6Handle, 1, 1, 0.0f, WHITE);
				}
			}
			if (boss.alive) {
				if (skeletonDoorAnimationTime < 20) {
					Novice::DrawSprite(bossDoor[0].pos.X - 50 - sX - a.vibration, bossDoor[0].pos.Y - 50 - sY, skeletonDoor1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (skeletonDoorAnimationTime < 40) {
					Novice::DrawSprite(bossDoor[0].pos.X - 50 - sX - a.vibration, bossDoor[0].pos.Y - 50 - sY, skeletonDoor2Handle, 1, 1, 0.0f, WHITE);
				}
				else if (skeletonDoorAnimationTime < 60) {
					Novice::DrawSprite(bossDoor[0].pos.X - 50 - sX - a.vibration, bossDoor[0].pos.Y - 50 - sY, skeletonDoor3Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(bossDoor[0].pos.X - 50 - sX - a.vibration, bossDoor[0].pos.Y - 50 - sY, skeletonDoor2Handle, 1, 1, 0.0f, WHITE);
				}
			}
			else if (boss.alive == 0) {
				if (skeletonEndAnimationTime < 20 && skeletonEndFlag == 0) {
					Novice::DrawSprite(bossDoor[0].pos.X - 50 - sX - a.vibration, bossDoor[0].pos.Y - 50 - sY, skeletonDoor1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (skeletonEndAnimationTime < 40 && skeletonEndFlag == 0) {
					Novice::DrawSprite(bossDoor[0].pos.X - 50 - sX - a.vibration, bossDoor[0].pos.Y - 50 - sY, skeletonDoorEnd1Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(bossDoor[0].pos.X - 50 - sX - a.vibration, bossDoor[0].pos.Y - 50 - sY, skeletonDoorEnd2Handle, 1, 1, 0.0f, WHITE);
				}
			}
			if (boss.alive == 0 && clearGhost == 1) {
				if (devilDoorAnimationTime < 20) {
					Novice::DrawSprite(bossDoor[2].pos.X - sX - a.vibration, bossDoor[2].pos.Y - sY, devilDoor1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (devilDoorAnimationTime < 40) {
					Novice::DrawSprite(bossDoor[2].pos.X - sX - a.vibration, bossDoor[2].pos.Y - sY, devilDoor2Handle, 1, 1, 0.0f, WHITE);
				}
				else if (devilDoorAnimationTime < 60) {
					Novice::DrawSprite(bossDoor[2].pos.X - sX - a.vibration, bossDoor[2].pos.Y - sY, devilDoor3Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(bossDoor[2].pos.X - sX - a.vibration, bossDoor[2].pos.Y - sY, devilDoor4Handle, 1, 1, 0.0f, WHITE);
				}
			}
			//海月
			for (int i = 0; i < maxFlyEnemys; i++) {
				if (jellyfishAnimationTime[i] < 20) {
					Novice::DrawSprite(flyEnemy[i].pos.X - flyEnemy[i].rX - sX - a.vibration, flyEnemy[i].pos.Y - flyEnemy[i].rX - sY, jellyfish1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (jellyfishAnimationTime[i] < 40) {
					Novice::DrawSprite(flyEnemy[i].pos.X - flyEnemy[i].rX - sX - a.vibration, flyEnemy[i].pos.Y - flyEnemy[i].rX - sY, jellyfish2Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(flyEnemy[i].pos.X - flyEnemy[i].rX - sX - a.vibration, flyEnemy[i].pos.Y - flyEnemy[i].rX - sY, jellyfish3Handle, 1, 1, 0.0f, WHITE);
				}
			}
			//家
			if (startSceneChange == 0) {
				Novice::DrawSprite(kwindowsRight * 4 - 128 - sX - a.vibration, kwindowsDown - ground.width.WorldY - 256 - 100 - sY, slimeHome1Handle, 1, 1, 0.0f, WHITE);
			}
			else if (startSceneChange < 20) {
				Novice::DrawSprite(kwindowsRight * 4 - 128 - sX - a.vibration, kwindowsDown - ground.width.WorldY - 256 - 100 - sY, slimeHome2Handle, 1, 1, 0.0f, WHITE);
			}
			else if (startSceneChange < 40) {
				Novice::DrawSprite(kwindowsRight * 4 - 128 - sX - a.vibration, kwindowsDown - ground.width.WorldY - 256 - 100 - sY, slimeHome3Handle, 1, 1, 0.0f, WHITE);
			}
			else if (startSceneChange < 60) {
				Novice::DrawSprite(kwindowsRight * 4 - 128 - sX - a.vibration, kwindowsDown - ground.width.WorldY - 256 - 100 - sY, slimeHome4Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(kwindowsRight * 4 - 128 - sX - a.vibration, kwindowsDown - ground.width.WorldY - 256 - 100 - sY, slimeHome5Handle, 1, 1, 0.0f, WHITE);
			}
			//プレイヤー残機
			Novice::DrawSprite(0 + a.rX, 0 + a.rY, slime1Handle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(a.rX + a.rX + a.rX + 10, 0 + a.rY + 16, xHandle, 1, 1, 0.0f, WHITE);
			//プレイヤーの描画
			if (Novice::IsPressMouse(0) == 0 && slimeShot == 0) {
				if (animeDir == LEFT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime1Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime3Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime2Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime4Handle, 1, 1, 0.0f, a.color);
					}
				}
				else if (animeDir == RIGHT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime1Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime3Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime2Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime4Handle, -1, 1, 0.0f, a.color);
					}

				}
				else if (animeDir == CLIMB) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeBackHandle, 1, 1, 0.0f, a.color);
				}
			}
			else if (Novice::IsPressMouse(0) == 1 && slimeShot == 0) {
				if (mouseDragX > mouseDragY) {
					if (mouse.X - mouseClick.X > 0) {
						if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide2Handle, 1, 1, 0.0f, a.color);
						}
					}
					else {
						if (slimeAnimationTime > 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X + a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide1Handle, -1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X + a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide2Handle, -1, 1, 0.0f, a.color);
						}
					}

				}
				else if (mouseDragX <= mouseDragY && slimeShot == 0) {
					if (mouse.Y - mouseClick.Y > 0) {
						if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirUp1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirUp2Handle, 1, 1, 0.0f, a.color);
						}
					}
					else {
						if (slimeAnimationTime <= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirDown1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirDown2Handle, 1, 1, 0.0f, a.color);
						}
					}

				}
			}
			else if (slimeShot == 1) {
				if (slimeAnimationTime >= 0 && slimeAnimationTime < 5 ||
					slimeAnimationTime >= 30 && slimeAnimationTime < 35) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot1Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 5 && slimeAnimationTime < 10 ||
					slimeAnimationTime >= 35 && slimeAnimationTime < 40) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot2Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 10 && slimeAnimationTime < 15 ||
					slimeAnimationTime >= 40 && slimeAnimationTime < 45) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot3Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 15 && slimeAnimationTime < 20 ||
					slimeAnimationTime >= 45 && slimeAnimationTime < 50) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot4Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 20 && slimeAnimationTime < 25 ||
					slimeAnimationTime >= 50 && slimeAnimationTime < 55) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot5Handle, 1, 1, 0.0f, a.color);
				}
				else {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot6Handle, 1, 1, 0.0f, a.color);
				}

			}
			//森ブロック
			for (int i = 0; i < 10; i++) {
				Novice::DrawSprite(terrain[i].pos.X - sX - a.vibration, terrain[i].pos.Y - sY, forestBlockHandle, 1, 1, 0.0f, WHITE);
			}
			// ファイアバーの描画
			for (int i = 0; i < maxBar; i++) {
				for (int j = 0; j < barNumber; j++) {
					Novice::DrawSprite(bar[i][j].pos.X - bar[i][j].rX - sX - a.vibration, bar[i][j].pos.Y - bar[i][j].rX - sY, fireBar1Handle, 1, 1, 0.0f, WHITE);
				}
			}
			//ポップアップ
			if (sceneChange == 2) {
				if (doorType[0]) {
					Novice::DrawSprite(popUp[0].pos.X, popUp[0].pos.Y, bossLule1Handle, luleSizeX, luleSizeY, 0.0f, WHITE);
				}
				else if (doorType[1]) {
					Novice::DrawSprite(popUp[0].pos.X, popUp[0].pos.Y, bossLule2Handle, luleSizeX, luleSizeY, 0.0f, WHITE);
				}
				else if (doorType[2]) {
					Novice::DrawSprite(popUp[0].pos.X, popUp[0].pos.Y, bossLule3Handle, luleSizeX, luleSizeY, 0.0f, WHITE);
				}
				if (leftIn == 0) {
					Novice::DrawSprite(popUp[1].pos.X - 8, popUp[1].pos.Y - 8, doorSelect1Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(popUp[1].pos.X - 8, popUp[1].pos.Y - 8, doorSelect2Handle, 1, 1, 0.0f, WHITE);
				}
				if (rightIn == 0) {
					Novice::DrawSprite(popUp[2].pos.X - 8, popUp[2].pos.Y - 8, doorSelect3Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(popUp[2].pos.X - 8, popUp[2].pos.Y - 8, doorSelect4Handle, 1, 1, 0.0f, WHITE);
				}
			}
			//引っ張りエフェクト
			if (Novice::IsPressMouse(0) && a.alive) {
				Novice::DrawEllipse(mouseClick.X, mouseClick.Y, 10, 10, 0.0f, WHITE, kFillModeSolid);
				Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), WHITE);
				if (a.shotVelocity.Y >= 30 || a.shotVelocity.X >= 30) {
					Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), RED);
				}
			}
			Novice::SetMouseCursorVisibility(0);
			if (Novice::IsPressMouse(0) == 0) {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse2Handle, 1, 1, 0.0f, WHITE);
			}
			break;
		case STAGEBOSS:
			//経過時間
			if (a.alive && boss.alive && defeatMotion == 0) {
				counter += 1;
			}
			if (counter == 60) {
				counter = 0;
				timer += 1;
			}
			momentSlimeHp = slimeHp;
			if (momentSlimeHp < 1000 && momentSlimeHp >= 0) {
				if (momentSlimeHp >= 10) {
					eachNumber[0] = momentSlimeHp / 10;
					momentSlimeHp = momentSlimeHp % 10;
				}
				else {
					eachNumber[0] = 0;
				}
				if (momentSlimeHp >= 0) {
					eachNumber[1] = momentSlimeHp;
				}
				else {
					eachNumber[1] = 0;
				}
			}
			//アニメーションの時間
			//プレイヤー
			slimeAnimationTime += 1;
			if (slimeAnimationTime == 60) {
				slimeAnimationTime = 0;
				currentTime = time(nullptr);
				srand(currentTime);
				slimeAnimationType = rand() % 5;
			}
			//スケルトン
			skeletonAnimationTime += 1;
			if (skeletonAnimationTime == 60) {
				skeletonAnimationTime = 0;
			}
			if (AtackType == 0 || AtackType == 4) {
				sickleAnimationTime += 1;
				if (sickleAnimationTime == 20) {
					sickleAnimationTime = 0;
				}
			}
			else {
				sickleAnimationTime = 0;
			}
			//移動前の座標
			a.pos.momentX = a.pos.X;
			a.pos.momentY = a.pos.Y;
			boss.pos.momentX = boss.pos.X;
			boss.pos.momentY = boss.pos.Y;
			terrainA.pos.momentX = terrainA.pos.X;
			terrainA.pos.momentY = terrainA.pos.Y;
			//プレイヤーの操作
			if (a.alive && boss.alive) {
				if (Novice::IsPressMouse(0) == 0) {
					if (keys[DIK_A] && isShot == 0) {
						a.pos.X -= a.velocity.X;
						a.pos.WorldX -= a.velocity.X;
						animeDir = LEFT;
					}
					if (keys[DIK_D] && isShot == 0) {
						a.pos.X += a.velocity.X;
						a.pos.WorldX += a.velocity.X;
						animeDir = RIGHT;
					}
					if (keys[DIK_SPACE] && isShot == 0 && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
				else if (Novice::IsPressMouse(0) == 1) {
					if (keys[DIK_A]) {
						a.pos.X -= a.velocity.X / 2;
						a.pos.WorldX -= a.velocity.X / 2;
						animeDir = LEFT;
					}
					if (keys[DIK_D]) {
						a.pos.X += a.velocity.X / 2;
						a.pos.WorldX += a.velocity.X / 2;
						animeDir = RIGHT;
					}
					if (keys[DIK_SPACE] && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
			}

			//マウスで引っ張る
			Novice::GetMousePosition(&mouse.X, &mouse.Y);
			if (a.alive && boss.alive) {
				if (Novice::IsTriggerMouse(0)) {
					slimeShot = 0;
					mouseClick.X = mouse.X;
					mouseClick.Y = mouse.Y;
				}
				if (Novice::IsPressMouse(0)) {
					isShot = 1;
					radian = atan2f((mouseClick.Y - mouse.Y), (mouseClick.X - mouse.X));
					a.dir.X = cosf(radian);
					a.dir.Y = sinf(radian);
					mouseDisX = sqrtf((mouseClick.X - mouse.X) * (mouseClick.X - mouse.X));
					mouseDisY = sqrtf((mouseClick.Y - mouse.Y) * (mouseClick.Y - mouse.Y));
					mouseDragX = mouseDisX;
					mouseDragY = mouseDisY;
					mouseDis = mouseDisX + mouseDisY;
					a.shotVelocity.X = mouseDisX / 4;
					a.shotVelocity.Y = mouseDisY / 4;
				}
				else if (isShot == 1) {
					slimeShot = 1;
					mouseDis = 0.0f;
					a.pos.X += a.dir.X * a.shotVelocity.X;
					a.pos.WorldX += a.dir.X * a.shotVelocity.X;
					a.pos.Y += a.dir.Y * a.shotVelocity.Y;
					a.pos.WorldY += a.dir.Y * a.shotVelocity.Y;
				}
				else {
					mouseDis = 0.0f;
				}
				if (a.shotVelocity.X > 0.0f && isShot == 1) {
					a.shotVelocity.X -= friction * sqrtf(a.dir.X * a.dir.X);
				}
				else if (a.shotVelocity.X < 0.0f && isShot == 1) {
					a.shotVelocity.X += friction * sqrtf(a.dir.X * a.dir.X);
				}
				if (a.shotVelocity.X <= friction && a.shotVelocity.X >= -friction && isShot == 1) {
					a.shotVelocity.X = 0.0f;
				}

				if (a.shotVelocity.Y > 0.0f && isShot == 1) {
					a.shotVelocity.Y -= friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				else if (a.shotVelocity.Y < 0.0f && isShot == 1) {
					a.shotVelocity.Y += friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				if (a.shotVelocity.Y <= friction && a.shotVelocity.Y >= -friction && isShot == 1) {
					a.shotVelocity.Y = 0.0f;
				}
				if (Novice::IsPressMouse(0) == 0 && a.shotVelocity.X == 0.0f && a.shotVelocity.Y == 0.0f && isShot == 1) {
					slimeShot = 0;
					isShot = 0;
				}
			}

			//重力
			if (a.alive) {
				a.velocity.Y -= 0.8f;
				a.pos.Y -= a.velocity.Y;
				a.pos.WorldY -= a.velocity.Y;
			}

			boss.velocity.Y -= 0.8f;
			boss.pos.Y -= boss.velocity.Y;
			if (isBossAtack == 2) {
				bossAtackCollision[0].velocity.Y -= 0.8f;
				bossAtackCollision[0].pos.Y -= bossAtackCollision[0].velocity.Y;
			}

			//障害物の動き
			terrainA.pos.X -= terrainA.velocity.X;
			if (terrainA.pos.X <= kwindowsLeft) {
				terrainA.pos.X = kwindowsLeft;
				terrainA.velocity.X *= -1;
			}
			else if (terrainA.pos.X + terrainA.rX >= kwindowsRight) {
				terrainA.pos.X = kwindowsRight - terrainA.rX;
				terrainA.velocity.X *= -1;
			}
			if (a.pos.momentY <= terrainA.pos.Y - a.rY && keys[DIK_A] == 0 && keys[DIK_D] == 0) {
				if (a.pos.Y >= terrainA.pos.Y - a.rY && a.pos.X > terrainA.pos.X - a.rX && a.pos.X < terrainA.pos.X + terrainA.rX + a.rX) {
					a.pos.X -= terrainA.velocity.X;
				}
			}
			a.pos.X = ClampX(a.pos.momentX, a.pos.X, a.rX, a.pos.Y, a.rY, terrainA.pos.X, (terrainA.pos.X + terrainA.rX), terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY));
			a.shotVelocity.X = ClampShotX(a.pos.momentX, a.pos.X, a.rX, a.pos.momentY, a.pos.Y, a.rY, terrainA.pos.X, (terrainA.pos.X + terrainA.rX), terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), a.shotVelocity.X, isGround);
			a.shotVelocity.Y = ClampShotY(a.pos.momentX, a.pos.X, a.rX, a.pos.momentY, a.pos.Y, a.rY, terrainA.pos.X, (terrainA.pos.X + terrainA.rX), terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), a.shotVelocity.Y, isGround);
			if (a.pos.X < terrainA.pos.X + terrainA.rX + a.rX &&
				a.pos.X > terrainA.pos.X - a.rX &&
				a.pos.momentY >= terrainA.pos.Y &&
				a.pos.momentY <= terrainA.pos.Y + terrainA.rY &&
				terrainA.velocity.X < 0) {
				a.pos.X = terrainA.pos.X + terrainA.rX + a.rX;
			}
			else if (a.pos.X > terrainA.pos.X - a.rX &&
				a.pos.X < terrainA.pos.X + terrainA.rX + a.rX &&
				a.pos.momentY >= terrainA.pos.Y &&
				a.pos.momentY <= terrainA.pos.Y + terrainA.rY &&
				terrainA.velocity.X > 0) {
				a.pos.X = terrainA.pos.X - a.rX;
			}
			a.pos.Y = ClampY(a.pos.momentY, a.pos.Y, a.rY, a.pos.X, a.rX, terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), terrainA.pos.X, terrainA.pos.X + terrainA.rX);
			isGround = ClampGround(a.pos.momentY, a.pos.Y, a.rY, a.pos.X, a.rX, terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), terrainA.pos.X, terrainA.pos.X + terrainA.rX, isGround);
			a.velocity.Y = ClampVelocityY(a.pos.momentY, a.pos.Y, a.rY, a.pos.X, a.rX, terrainA.pos.Y, (terrainA.pos.Y + terrainA.rY), terrainA.pos.X, terrainA.pos.X + terrainA.rX, a.velocity.Y);


			//ボス攻撃：壁の当たり判定
			if (kwindowsLeft + bossAtackCollision[0].rX >= bossAtackCollision[0].pos.X && isBossAtack == 1 && AtackType == 0 ||
				kwindowsLeft + bossAtackCollision[0].rX >= bossAtackCollision[0].pos.X && isBossAtack == 1 && AtackType == 4) {
				isBossAtack = 2;
				bossAtackCollision[0].pos.X = kwindowsLeft + bossAtackCollision[0].rX;
			}
			if (kwindowsRight - bossAtackCollision[0].rX <= bossAtackCollision[0].pos.X && isBossAtack == 1 && AtackType == 0 ||
				kwindowsRight - bossAtackCollision[0].rX <= bossAtackCollision[0].pos.X && isBossAtack == 1 && AtackType == 4) {
				isBossAtack = 2;
				bossAtackCollision[0].pos.X = kwindowsRight - bossAtackCollision[0].rX;
			}
			//ボス攻撃：上下の当たり判定
			if (kwindowsUp + bossAtackCollision[0].rY >= bossAtackCollision[0].pos.Y && isBossAtack == 1 && AtackType == 0 ||
				kwindowsUp + bossAtackCollision[0].rY >= bossAtackCollision[0].pos.Y && isBossAtack == 1 && AtackType == 4) {
				isBossAtack = 2;
				bossAtackCollision[0].pos.Y = kwindowsUp + bossAtackCollision[0].rY;
			}
			if (kwindowsDown - bossAtackCollision[0].rY - ground.width.WorldY <= bossAtackCollision[0].pos.Y && AtackType == 0 ||
				kwindowsDown - bossAtackCollision[0].rY - ground.width.WorldY <= bossAtackCollision[0].pos.Y && AtackType == 4) {
				isBossAtack = 3;
				bossAtackCollision[0].velocity.Y = 0.0f;
				bossAtackCollision[0].pos.Y = kwindowsDown - bossAtackCollision[0].rY - ground.width.WorldY;
			}
			//ボスが攻撃されたときに止まる時間
			if (bossHitStop > 0) {
				bossHitStop -= 1;
			}
			else {
				bossHitStop = 0;
			}
			//ボスが攻撃されたときに吹っ飛ぶ
			boss.pos.X += boss.shotVelocity.X;
			if (boss.shotVelocity.X > 0) {
				skeletonAnimationType = RIGHT;
				boss.shotVelocity.X -= boss.velocity.X;
			}
			else if (boss.shotVelocity.X < 0) {
				skeletonAnimationType = LEFT;
				boss.shotVelocity.X += boss.velocity.X;
			}
			if (boss.shotVelocity.X <= boss.velocity.X && boss.shotVelocity.X >= -boss.velocity.X) {
				boss.shotVelocity.X = 0.0f;
			}
			if (bossHitStop == 0 && boss.alive) {
				//ボスの動き
				if (a.pos.X <= boss.pos.X + boss.rX / 2 && a.alive == 1 &&
					boss.shotVelocity.X <= 0 && atackCoolTime == 0 && isBossAtack == 0) {
					boss.pos.X -= boss.velocity.X;
					skeletonAnimationType = LEFT;
				}
				else if (a.pos.X >= boss.pos.X + boss.rX / 2 && a.alive == 1 &&
					boss.shotVelocity.X <= 0 && atackCoolTime == 0 && isBossAtack == 0) {
					boss.pos.X += boss.velocity.X;
					skeletonAnimationType = RIGHT;
				}
				if (isBossAtack == 0) {
					bossTime += 1;
				}
				//武器を拾いに行く
				if (isBossAtack == 3 && atackCoolTime == 0) {
					if (boss.pos.X + boss.rX / 2 <= bossAtackCollision[0].pos.X) {
						boss.pos.X += boss.velocity.X * 3;
						skeletonAnimationType = RIGHT;
						if (boss.pos.X + boss.rX / 2 >= bossAtackCollision[0].pos.X) {
							isBossAtack = 0;
							atackCoolTime = 0;
							initialize = 0;
							bossAtackCollision[0].pos.X = -1000;
							bossAtackCollision[0].pos.Y = -1000;
						}
					}
					else if (boss.pos.X + boss.rX / 2 >= bossAtackCollision[0].pos.X) {
						boss.pos.X -= boss.velocity.X * 3;
						skeletonAnimationType = LEFT;
						if (boss.pos.X + boss.rX / 2 <= bossAtackCollision[0].pos.X) {
							isBossAtack = 0;
							atackCoolTime = 0;
							initialize = 0;
							bossAtackCollision[0].pos.X = -1000;
							bossAtackCollision[0].pos.Y = -1000;
						}
					}
				}
			}

			//ボスの攻撃フラグ
			if (bossTime >= atackTime && isBossAtack == 0 && boss.alive) {
				atackCoolTime = 120;
				isBossAtack = 1;
				currentTime = time(nullptr);
				srand(currentTime);
				AtackType = rand() % 5;
				bossTime = 0;

				currentTime = time(nullptr);
				srand(currentTime);
				atackTime = rand() % 5;
				for (int i = 0; i < 5; i++) {
					if (atackTime == i) {
						atackTime = 60 + i * 30;
					}
				}
			}
			//ボスの攻撃パターン
			if (isBossAtack == 1) {
				if (AtackType == 0) {
					float bossRadian = 0.0f;
					if (initialize == 0) {
						initialize = 1;
						if (a.pos.X <= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - boss.pos.X));
							bossAtackCollision[0].pos.X = boss.pos.X;
							bossAtackCollision[0].pos.Y = boss.pos.Y;
						}
						else if (a.pos.X >= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - (boss.pos.X + boss.rX)));
							bossAtackCollision[0].pos.X = boss.pos.X + boss.rX;
							bossAtackCollision[0].pos.Y = boss.pos.Y;
						}

						bossAtackCollision[0].dir.X = cosf(bossRadian);
						bossAtackCollision[0].dir.Y = sinf(bossRadian);
						bossAtackCollision[0].shotVelocity.X = bossAtackCollision[0].dir.X * bossAtackCollision[0].velocity.X;
						bossAtackCollision[0].shotVelocity.Y = bossAtackCollision[0].dir.Y * bossAtackCollision[0].velocity.X;
						bossAtackCollision[0].rX = 50;
						bossAtackCollision[0].rY = 50;
					}
					bossAtackCollision[0].pos.X += bossAtackCollision[0].shotVelocity.X;
					bossAtackCollision[0].pos.Y += bossAtackCollision[0].shotVelocity.Y;

				}
				else if (AtackType == 1 && bossHitStop == 0) {
					float bossRadian = 0.0f;
					if (initialize == 0) {
						initialize = 1;
						if (a.pos.X <= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - boss.pos.X));
						}
						else if (a.pos.X >= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - (boss.pos.X + boss.rX)));
						}
						bossAtackCollision[0].dir.X = cosf(bossRadian);
						bossAtackCollision[0].dir.Y = sinf(bossRadian);
						bossAtackCollision[0].shotVelocity.X = bossAtackCollision[0].dir.X * bossAtackCollision[0].velocity.X;
						bossAtackCollision[0].shotVelocity.Y = bossAtackCollision[0].dir.Y * bossAtackCollision[0].velocity.X;
						bossAtackCollision[0].rX = 50;
						bossAtackCollision[0].rY = 50;
					}
					if (boss.shotVelocity.X > 0) {
						skeletonAnimationType = RIGHT;
					}
					else if (boss.shotVelocity.X < 0) {
						skeletonAnimationType = LEFT;
					}
					boss.pos.X += bossAtackCollision[0].shotVelocity.X * 2;
					boss.pos.Y += bossAtackCollision[0].shotVelocity.Y * 2;

				}
				else if (AtackType == 2 && bossHitStop == 0) {
					float bossRadian = 0.0f;
					if (initialize == 0) {
						initialize = 1;
						if (a.pos.X <= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - boss.pos.X));
						}
						else if (a.pos.X >= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - (boss.pos.X + boss.rX)));
						}
						bossAtackCollision[0].dir.X = cosf(bossRadian);
						bossAtackCollision[0].dir.Y = sinf(bossRadian);
						bossAtackCollision[0].shotVelocity.X = bossAtackCollision[0].dir.X * bossAtackCollision[0].velocity.X;
						bossAtackCollision[0].shotVelocity.Y = bossAtackCollision[0].dir.Y * bossAtackCollision[0].velocity.X;
					}
					if (boss.shotVelocity.X > 0) {
						skeletonAnimationType = RIGHT;
					}
					else if (boss.shotVelocity.X < 0) {
						skeletonAnimationType = LEFT;
					}
					boss.pos.X += bossAtackCollision[0].shotVelocity.X * 3;

				}
				else if (AtackType == 3 && bossHitStop == 0) {
					float bossRadian = 0.0f;
					if (initialize == 0) {
						initialize = 1;
						if (a.pos.X <= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - boss.pos.X));
						}
						else if (a.pos.X >= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - (boss.pos.X + boss.rX)));
						}
						bossAtackCollision[0].dir.X = cosf(bossRadian);
						bossAtackCollision[0].dir.Y = sinf(bossRadian);
						bossAtackCollision[0].shotVelocity.X = bossAtackCollision[0].dir.X * bossAtackCollision[0].velocity.X;
						bossAtackCollision[0].shotVelocity.Y = bossAtackCollision[0].dir.Y * bossAtackCollision[0].velocity.X;
					}
					if (boss.shotVelocity.X > 0) {
						skeletonAnimationType = RIGHT;
					}
					else if (boss.shotVelocity.X < 0) {
						skeletonAnimationType = LEFT;
					}
					boss.pos.X += bossAtackCollision[0].shotVelocity.X * 3;

				}
				else if (AtackType == 4) {
					float bossRadian = 0.0f;
					if (initialize == 0) {
						initialize = 1;
						if (a.pos.X <= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - boss.pos.X));
							bossAtackCollision[0].pos.X = boss.pos.X;
							bossAtackCollision[0].pos.Y = boss.pos.Y;
						}
						else if (a.pos.X >= boss.pos.X + boss.rX / 2 && boss.alive == 1 && a.alive == 1) {
							bossRadian = atan2f((a.pos.Y - boss.pos.Y), (a.pos.X - (boss.pos.X + boss.rX)));
							bossAtackCollision[0].pos.X = boss.pos.X + boss.rX;
							bossAtackCollision[0].pos.Y = boss.pos.Y;
						}

						bossAtackCollision[0].dir.X = cosf(bossRadian);
						bossAtackCollision[0].dir.Y = sinf(bossRadian);
						bossAtackCollision[0].shotVelocity.X = bossAtackCollision[0].dir.X * bossAtackCollision[0].velocity.X;
						bossAtackCollision[0].shotVelocity.Y = bossAtackCollision[0].dir.Y * bossAtackCollision[0].velocity.X;
						bossAtackCollision[0].rX = 50;
						bossAtackCollision[0].rY = 50;
					}
					bossAtackCollision[0].pos.X += bossAtackCollision[0].shotVelocity.X;
					bossAtackCollision[0].pos.Y += bossAtackCollision[0].shotVelocity.Y;

				}

			}
			//攻撃のクールタイム
			if (atackCoolTime > 0 && bossHitStop == 0) {
				atackCoolTime -= 1;
			}
			else if (isBossAtack == 1) {
				atackCoolTime = 0;
				initialize = 0;
				isBossAtack = 0;
			}

			//ボスの当たり判定
			if (boss.alive) {
				a.pos.Y = ClampY(a.pos.momentY, a.pos.Y, a.rY, a.pos.X, a.rX, boss.pos.Y, (boss.pos.Y + boss.rY), boss.pos.X, boss.pos.X + boss.rX);
				//敵が攻撃された判定
				if (a.pos.momentY <= boss.pos.Y - a.rY && treadBoss == 0) {
					if (a.pos.Y >= boss.pos.Y - a.rY && a.pos.X > boss.pos.X - a.rX && a.pos.X < boss.pos.X + boss.rX + a.rX) {
						if (Novice::IsPressMouse(0) == 0) {
							if (a.shotVelocity.Y >= 40 || a.shotVelocity.Y <= -40) {
								a.velocity.Y = 20;
								boss.shotVelocity.X = a.dir.X * a.shotVelocity.X;
								a.shotVelocity.Y = 0.0f;
								a.shotVelocity.X *= -0.5f;
								bossHitStop = 60.0f;
								treadBoss = 1;
								boss.hp -= 1;
								score += 40;
								if (a.isSpace == 1) {
									a.isSpace = 0;
									a.back = 1;
								}
								else {
									a.back = 0;
									a.isSpace = 1;
								}
							}
							//攻撃のスピードが足りない場合
							else {
								a.shotVelocity.Y = 0.0f;
								a.shotVelocity.X = 0.0f;
								isHitBoss = 1;
							}

						}
						//マウスを押した状態で接敵
						else {
							a.shotVelocity.Y = 0.0f;
							a.shotVelocity.X = 0.0f;
							isHitBoss = 1;
						}

					}
				}
				//横から当たった場合
				else if (a.alive == 1) {
					isHitBoss = HitX(a.pos.momentX, a.pos.X, a.rX, a.pos.Y, a.rY, boss.pos.X, (boss.pos.X + boss.rX), boss.pos.Y, (boss.pos.Y + boss.rY), isHitBoss);
				}
				//攻撃された判定を戻す
				if (treadBoss == 1) {
					treadBoss = 0;
				}

				if (isHitBoss == 1 && a.alive == 1) {
					a.velocity.Y = 0.0f;
					a.alive = 0;
				}
				else if (isHitBoss == 2 && a.alive == 1) {
					a.velocity.Y = 0.0f;
					a.alive = 0;
				}
			}

			//ボスの撃破処理
			if (boss.hp <= 0) {
				slimeShot = 0;
				if (boss.color > WHITE - 0xff) {
					boss.color -= 5;
				}
				boss.alive = 0;
				defeatMotion += 1;
				if (defeatMotion == 180) {
					isGround = 0;
					a.velocity.Y = 15;
					a.pos.Y -= a.velocity.Y;
				}
				else if (defeatMotion >= 240) {
					animeDir = LEFT;
					a.pos.X -= a.velocity.X * 2;
					if (a.pos.X <= 0) {
						clearSkeleton = 1;
						atackCoolTime = 0;
						atackStop = 0;
						atackTime = 0;
						bossTime = 0;
						a.pos.X = bossDoor[0].pos.X + bossDoor[0].width.X / 2;
						a.pos.WorldX = a.pos.X;
						a.pos.Y = bossDoor[0].pos.Y + bossDoor[0].width.Y / 2;
						a.pos.WorldY = a.pos.Y;
						a.velocity.Y = 10;
						a.shotVelocity.X = 0.0f;
						a.shotVelocity.Y = 0.0f;
						terrainA.rY = 0.0f;
						terrainA.pos.X = 700.0f;
						terrainA.pos.Y = bgY[1].pos.Y - terrainA.rY;
						terrainA.rX = 400.0f;
						terrainA.rY = 10.0f;
						terrainA.velocity.X = 5.0f;
						popUp[1].pos.X = -1000;
						popUp[2].pos.X = -1000;
						scene = STAGE;
					}
				}
			}

			//ボス攻撃とプレイヤーの当たり判定
			disX = (a.pos.X - bossAtackCollision[0].pos.X) * (a.pos.X - bossAtackCollision[0].pos.X);
			disY = (a.pos.Y - bossAtackCollision[0].pos.Y) * (a.pos.Y - bossAtackCollision[0].pos.Y);
			dis = sqrtf(disX + disY);
			if (dis <= a.rX + bossAtackCollision[0].rX && boss.alive) {
				a.alive = 0;
				isHitBoss = 1;
			}
			//復活処理
			if (a.alive == 0) {
				if (isHitBoss == 1 || isHitBoss == 2) {
					a.color -= 5;
				}
				if (isHitBoss && a.color <= WHITE - 0xff) {
					boss.pos.X = boss.pos.startX;
					boss.pos.Y = boss.pos.startY;

					scene = STAGE;
					a.color = WHITE;
					isHitBoss = 0.0f;
					a.alive = 1;
					a.velocity.Y = 0.0f;
					a.shotVelocity.X = 0.0f;
					a.shotVelocity.Y = 0.0f;
					a.pos.X = bossDoor[0].pos.X + bossDoor[0].width.X / 2;
					a.pos.WorldX = a.pos.X;
					a.pos.Y = bossDoor[0].pos.Y + bossDoor[0].width.Y - a.rY - 1;
					a.pos.WorldY = a.pos.Y;
				}
				if (isHole == 1) {
					a.color = WHITE;
					a.alive = 1;
					a.velocity.Y = 0.0f;
					a.shotVelocity.X = 0.0f;
					a.shotVelocity.Y = 0.0f;
					a.pos.X = startA.pos.X;
					a.pos.WorldX = startA.pos.WorldX;
					a.pos.Y = startA.pos.Y;
					a.pos.WorldY = startA.pos.WorldY;
					isHole = 0;
				}
				if (a.alive == 1) {
					slimeHp -= 1;
					//ゲームオーバー処理
					if (slimeHp <= -1) {
						scene = GAMEOVER;
					}
					//復活
					else {
						boss.pos.startX = boss.pos.X;
						boss.pos.startY = boss.pos.Y;
						boss.velocity.X = 3;
						boss.shotVelocity.X = 0.0f;
						initialize = 0;
						bossAtackCollision[0].pos.X = -1000;
						bossAtackCollision[0].pos.Y = -1000;
						isBossAtack = 0;
						atackCoolTime = 0.0f;
						atackTime = 0.0f;
						bossTime = 0.0f;
						bossHitStop = 0.0f;
						terrainA.rY = 0.0f;
						terrainA.pos.X = 700.0f;
						terrainA.pos.Y = bgY[1].pos.Y - terrainA.rY;
						terrainA.rX = 400.0f;
						terrainA.rY = 10.0f;
						terrainA.velocity.X = 5.0f;
						popUp[1].pos.X = -1000;
						popUp[2].pos.X = -1000;
					}
				}
			}


			//ボス：壁の当たり判定
			if (kwindowsLeft >= boss.pos.X) {
				boss.pos.X = kwindowsLeft;
			}
			if (kwindowsRight - boss.rX <= boss.pos.X) {
				boss.pos.X = kwindowsRight - boss.rX;
			}
			//ボス：上下の当たり判定
			if (kwindowsUp >= boss.pos.Y) {
				boss.pos.Y = kwindowsUp;
			}
			if (kwindowsDown - boss.rY - ground.width.WorldY <= boss.pos.Y) {
				boss.velocity.Y = 0.0f;
				boss.pos.Y = kwindowsDown - boss.rY - ground.width.WorldY;
			}
			//プレイヤー：壁の当たり判定
			if (kwindowsLeft + a.rX >= a.pos.X && boss.alive) {
				a.shotVelocity.X *= -1;
				a.pos.X = kwindowsLeft + a.rX;
				a.pos.WorldX = a.pos.X;
			}
			if (kwindowsRight - a.rX <= a.pos.X && boss.alive) {
				a.shotVelocity.X *= -1;
				a.pos.X = kwindowsRight - a.rX;
				a.pos.WorldX = a.pos.X + bgX[3].X;
			}
			//プレイヤー：上下の当たり判定
			if (kwindowsUp + a.rY >= a.pos.Y) {
				a.shotVelocity.Y *= -1;
				a.pos.Y = kwindowsUp + a.rY;
				a.pos.WorldY = bgY[3].pos.Y + a.rY;
			}
			if (kwindowsDown - a.rY - ground.width.WorldY <= a.pos.Y && isHole == 0) {
				a.shotVelocity.Y *= -1;
				isGround = 1;
				a.velocity.Y = 0.0f;
				a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY;
				a.pos.WorldY = kwindowsDown - a.rX - ground.width.WorldY;
			}
			else if (isHole == 1) {
				isGround = 0;
			}
			mouseDisX = a.pos.X - mouseClick.X;
			mouseDisY = a.pos.Y - mouseClick.Y;
			//振動
			if (a.isSpace == 1 && a.back == 0 && a.reflect != a.maxReflect) {
				a.frame += 1;
				if (a.stop == 0) {
					a.t += a.tIncrement;
					a.easeT = a.t * a.t;
				}
				if (a.easeT > 1.2f && a.reflect < a.maxReflect && a.reflect % 2 == 0) {
					a.tIncrement *= -1;
					a.reflect += 1;

				}
				else if (a.easeT < 0.8f && a.reflect % 2 == 1 && a.reflect < a.maxReflect) {
					a.tIncrement *= -1;
					a.reflect += 1;
				}
				if (a.reflect == a.maxReflect) {
					a.vibration = 0;
					a.isSpace = 0;
					a.back = 1;
				}
				a.vibration = (1.0f - a.easeT) * 0 + a.easeT * 16;
			}
			else {
				if (a.easeT > 0.0f) {
					a.easeT -= 0.1f;
				}
				else {
					a.easeT = 0.0f;
				}
				a.tIncrement = 0.2f;
				a.reflect = 0;
				a.easeT = 0.0f;
				a.t = 0.0f;
				a.frame = 0;
				a.stop = 0;
				a.vibration = 0.0f;
			}
			
			//背景の描画
			Novice::DrawSprite(0 - a.vibration, 0, skeletonBgHandle, 1, 1, 0.0f, WHITE);
			if (defeatMotion >= 140 && defeatMotion < 200) {
				Novice::DrawSprite(0 - a.vibration, 0, skeletonBgEnd1Handle, 1, 1, 0.0f, WHITE);
			}
			else if (boss.alive == 0 && defeatMotion >= 200 && defeatMotion < 260) {
				Novice::DrawSprite(0 - a.vibration, 0, skeletonBgEnd2Handle, 1, 1, 0.0f, WHITE);
			}
			else if (boss.alive == 0 && defeatMotion >= 260) {
				Novice::DrawSprite(0 - a.vibration, 0, skeletonBgEnd3Handle, 1, 1, 0.0f, WHITE);
			}
			//地面の描画
			Novice::DrawSprite(ground.pos.WorldX - a.vibration, ground.pos.WorldY, skeletonGroundHandle, 1, 1, 0.0f, WHITE);
			//障害物の描画
			Novice::DrawSprite(terrainA.pos.X - a.vibration, terrainA.pos.Y, skeletonTerrainHandle, 1, 1, 0.0f, WHITE);
			//ボスの描画
			if (isBossAtack != 3 && AtackType == 0 ||
				isBossAtack != 3 && AtackType == 4) {
				if (sickleAnimationTime < 5) {
					Novice::DrawSprite(bossAtackCollision[0].pos.X - bossAtackCollision[0].rX - a.vibration, bossAtackCollision[0].pos.Y - bossAtackCollision[0].rY, sickleAtack1Handle, 1, 1, 0.0f, boss.color);
				}
				else if (sickleAnimationTime < 10) {
					Novice::DrawSprite(bossAtackCollision[0].pos.X - bossAtackCollision[0].rX - a.vibration, bossAtackCollision[0].pos.Y - bossAtackCollision[0].rY, sickleAtack2Handle, 1, 1, 0.0f, boss.color);
				}
				else if (sickleAnimationTime < 15) {
					Novice::DrawSprite(bossAtackCollision[0].pos.X - bossAtackCollision[0].rX - a.vibration, bossAtackCollision[0].pos.Y - bossAtackCollision[0].rY, sickleAtack3Handle, 1, 1, 0.0f, boss.color);
				}
				else {
					Novice::DrawSprite(bossAtackCollision[0].pos.X - bossAtackCollision[0].rX - a.vibration, bossAtackCollision[0].pos.Y - bossAtackCollision[0].rY, sickleAtack4Handle, 1, 1, 0.0f, boss.color);
				}
			}
			else if (isBossAtack == 3 && AtackType == 0 || isBossAtack == 3 && AtackType == 4) {
				Novice::DrawSprite(bossAtackCollision[0].pos.X - bossAtackCollision[0].rX - a.vibration, bossAtackCollision[0].pos.Y - bossAtackCollision[0].rY, skeletonSickle1Handle, 1, 1, 0.0f, boss.color);
			}
			if (skeletonAnimationType == LEFT) {
				if (skeletonAnimationTime < 20) {
					if (isBossAtack == 0) {
						Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeletonSickle1Handle, 1, 1, 0.0f, boss.color);
					}
					else if (AtackType == 1 || AtackType == 2 || AtackType == 3) {
						Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeletonSickle4Handle, 1, 1, 0.0f, boss.color);
					}
					Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeleton1Handle, 1, 1, 0.0f, boss.color);
				}
				else if (skeletonAnimationTime < 40) {
					if (isBossAtack == 0) {
						Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeletonSickle2Handle, 1, 1, 0.0f, boss.color);
					}
					else if (AtackType == 1 || AtackType == 2 || AtackType == 3) {
						Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeletonSickle4Handle, 1, 1, 0.0f, boss.color);
					}
					Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeleton2Handle, 1, 1, 0.0f, boss.color);
				}
				else {
					if (isBossAtack == 0) {
						Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeletonSickle3Handle, 1, 1, 0.0f, boss.color);
					}
					else if (AtackType == 1 || AtackType == 2 || AtackType == 3) {
						Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeletonSickle4Handle, 1, 1, 0.0f, boss.color);
					}
					Novice::DrawSprite(boss.pos.X - a.vibration, boss.pos.Y, skeleton3Handle, 1, 1, 0.0f, boss.color);
				}
			}
			else if (skeletonAnimationType == RIGHT) {
				if (skeletonAnimationTime < 20) {
					if (isBossAtack == 0) {
						Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeletonSickle1Handle, -1, 1, 0.0f, boss.color);
					}
					else if (AtackType == 1 || AtackType == 2 || AtackType == 3) {
						Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeletonSickle4Handle, -1, 1, 0.0f, boss.color);
					}
					Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeleton1Handle, -1, 1, 0.0f, boss.color);
				}
				else if (skeletonAnimationTime < 40) {
					if (isBossAtack == 0) {
						Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeletonSickle2Handle, -1, 1, 0.0f, boss.color);
					}
					else if (AtackType == 1 || AtackType == 2 || AtackType == 3) {
						Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeletonSickle4Handle, -1, 1, 0.0f, boss.color);
					}
					Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeleton2Handle, -1, 1, 0.0f, boss.color);
				}
				else {
					if (isBossAtack == 0) {
						Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeletonSickle3Handle, -1, 1, 0.0f, boss.color);
					}
					else if (AtackType == 1 || AtackType == 2 || AtackType == 3) {
						Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeletonSickle4Handle, -1, 1, 0.0f, boss.color);
					}
					Novice::DrawSprite(boss.pos.X + boss.rX - a.vibration, boss.pos.Y, skeleton3Handle, -1, 1, 0.0f, boss.color);
				}
			}
			//プレイヤー残機
			Novice::DrawSprite(0 + a.rX, 0 + a.rY, slime1Handle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(a.rX + a.rX + a.rX + 10 - a.vibration, 0 + a.rY + 16, xHandle, 1, 1, 0.0f, WHITE);
			if (Novice::IsPressMouse(0) == 0 && slimeShot == 0) {
				if (animeDir == LEFT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime1Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime3Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime2Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime4Handle, 1, 1, 0.0f, a.color);
					}
				}
				else if (animeDir == RIGHT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime1Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime3Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime2Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime4Handle, -1, 1, 0.0f, a.color);
					}

				}
				else if (animeDir == CLIMB) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeBackHandle, 1, 1, 0.0f, a.color);
				}
			}
			else if (Novice::IsPressMouse(0) == 1 && slimeShot == 0) {
				if (mouseDragX > mouseDragY) {
					if (mouse.X - mouseClick.X > 0) {
						if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide2Handle, 1, 1, 0.0f, a.color);
						}
					}
					else {
						if (slimeAnimationTime > 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X + a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide1Handle, -1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X + a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide2Handle, -1, 1, 0.0f, a.color);
						}
					}

				}
				else if (mouseDragX <= mouseDragY) {
					if (mouse.Y - mouseClick.Y > 0) {
						if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirUp1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirUp2Handle, 1, 1, 0.0f, a.color);
						}
					}
					else {
						if (slimeAnimationTime <= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirDown1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirDown2Handle, 1, 1, 0.0f, a.color);
						}
					}

				}

			}
			else if (slimeShot == 1) {
				if (slimeAnimationTime >= 0 && slimeAnimationTime < 5 ||
					slimeAnimationTime >= 30 && slimeAnimationTime < 35) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot1Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 5 && slimeAnimationTime < 10 ||
					slimeAnimationTime >= 35 && slimeAnimationTime < 40) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot2Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 10 && slimeAnimationTime < 15 ||
					slimeAnimationTime >= 40 && slimeAnimationTime < 45) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot3Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 15 && slimeAnimationTime < 20 ||
					slimeAnimationTime >= 45 && slimeAnimationTime < 50) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot4Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 20 && slimeAnimationTime < 25 ||
					slimeAnimationTime >= 50 && slimeAnimationTime < 55) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot5Handle, 1, 1, 0.0f, a.color);
				}
				else {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot6Handle, 1, 1, 0.0f, a.color);
				}

			}
			//引っ張りエフェクト
			if (Novice::IsPressMouse(0) && a.alive) {
				Novice::DrawEllipse(mouseClick.X, mouseClick.Y, 10, 10, 0.0f, WHITE, kFillModeSolid);
				Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), WHITE);
				if (a.shotVelocity.Y >= 50) {
					Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), RED);
				}
			}
			Novice::SetMouseCursorVisibility(0);
			if (Novice::IsPressMouse(0) == 0) {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse2Handle, 1, 1, 0.0f, WHITE);
			}
			break;
		case STAGEBOSS2:
			//経過時間
			if (sceneChange != 1 && a.alive == 1) {
				counter += 1;
			}
			if (counter == 60) {
				counter = 0;
				timer += 1;
			}
			momentSlimeHp = slimeHp;
			if (momentSlimeHp < 1000 && momentSlimeHp >= 0) {
				if (momentSlimeHp >= 10) {
					eachNumber[0] = momentSlimeHp / 10;
					momentSlimeHp = momentSlimeHp % 10;
				}
				else {
					eachNumber[0] = 0;
				}
				if (momentSlimeHp >= 0) {
					eachNumber[1] = momentSlimeHp;
				}
				else {
					eachNumber[1] = 0;
				}
			}
			//アニメーションの時間
			//プレイヤー
			slimeAnimationTime += 1;
			if (slimeAnimationTime == 60) {
				slimeAnimationTime = 0;
				currentTime = time(nullptr);
				srand(currentTime);
				slimeAnimationType = rand() % 5;
			}
			//ゴースト
			ghostAnimationTime += 1;
			if (ghostAnimationTime == 60) {
				ghostAnimationTime = 0;
			}
			ghostFireAnimationTime += 1;
			if (ghostFireAnimationTime == 30) {
				ghostFireAnimationTime = 0;
			}
			//ワープ
			warpAnimationTime += 1;
			if (warpAnimationTime == 60) {
				warpAnimationTime = 0;
			}
			//御札
			if (getAmulet == 0) {
				amuletAnimationTime += 1;
				if (amuletAnimationTime == 60) {
					amuletAnimationTime = 0;
				}
			}
			//出口
			exitAnimationTime += 1;
			if (exitAnimationTime == 60) {
				exitAnimationTime = 0;
			}
			//移動前の座標
			a.pos.momentX = a.pos.X;
			a.pos.momentY = a.pos.WorldY;
			terrainA.pos.momentX = terrainA.pos.X;
			terrainA.pos.momentY = terrainA.pos.Y;
			//プレイヤーの操作
			if (a.alive && sceneChange != 1) {
				if (Novice::IsPressMouse(0) == 0) {
					if (keys[DIK_A] && isShot == 0) {
						a.pos.X -= a.velocity.X;
						a.pos.WorldX -= a.velocity.X;
						animeDir = LEFT;
					}
					if (keys[DIK_D] && isShot == 0) {
						a.pos.X += a.velocity.X;
						a.pos.WorldX += a.velocity.X;
						animeDir = RIGHT;
					}
					if (keys[DIK_SPACE] && isShot == 0 && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
				else if (Novice::IsPressMouse(0) == 1) {
					if (keys[DIK_A]) {
						a.pos.X -= a.velocity.X / 2;
						a.pos.WorldX -= a.velocity.X / 2;
						animeDir = LEFT;
					}
					if (keys[DIK_D]) {
						a.pos.X += a.velocity.X / 2;
						a.pos.WorldX += a.velocity.X / 2;
						animeDir = RIGHT;
					}
					if (keys[DIK_SPACE] && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
			}

			//マウスで引っ張る
			if (a.alive && sceneChange != 1) {
				Novice::GetMousePosition(&mouse.X, &mouse.Y);
				if (Novice::IsTriggerMouse(0)) {
					slimeShot = 0;
					mouseClick.X = mouse.X;
					mouseClick.Y = mouse.Y;
				}
				if (Novice::IsPressMouse(0)) {
					isShot = 1;
					radian = atan2f((mouseClick.Y - mouse.Y), (mouseClick.X - mouse.X));
					a.dir.X = cosf(radian);
					a.dir.Y = sinf(radian);
					mouseDisX = sqrtf((mouseClick.X - mouse.X) * (mouseClick.X - mouse.X));
					mouseDisY = sqrtf((mouseClick.Y - mouse.Y) * (mouseClick.Y - mouse.Y));
					mouseDragX = mouseDisX;
					mouseDragY = mouseDisY;
					mouseDis = mouseDisX + mouseDisY;
					a.shotVelocity.X = mouseDisX / 4;
					a.shotVelocity.Y = mouseDisY / 4;
				}
				else if (isShot == 1) {
					slimeShot = 1;
					mouseDis = 0.0f;
					a.pos.X += a.dir.X * a.shotVelocity.X;
					a.pos.WorldX += a.dir.X * a.shotVelocity.X;
					a.pos.Y += a.dir.Y * a.shotVelocity.Y;
					a.pos.WorldY += a.dir.Y * a.shotVelocity.Y;
				}
				else {
					mouseDis = 0.0f;
				}
				if (a.shotVelocity.X > 0.0f && isShot == 1) {
					a.shotVelocity.X -= friction * sqrtf(a.dir.X * a.dir.X);
				}
				else if (a.shotVelocity.X < 0.0f && isShot == 1) {
					a.shotVelocity.X += friction * sqrtf(a.dir.X * a.dir.X);
				}
				if (a.shotVelocity.X <= friction && a.shotVelocity.X >= -friction && isShot == 1) {
					a.shotVelocity.X = 0.0f;
				}

				if (a.shotVelocity.Y > 0.0f && isShot == 1) {
					a.shotVelocity.Y -= friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				else if (a.shotVelocity.Y < 0.0f && isShot == 1) {
					a.shotVelocity.Y += friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				if (a.shotVelocity.Y <= friction && a.shotVelocity.Y >= -friction && isShot == 1) {
					a.shotVelocity.Y = 0.0f;
				}
				if (Novice::IsPressMouse(0) == 0 && a.shotVelocity.X == 0.0f && a.shotVelocity.Y == 0.0f && isShot == 1) {
					slimeShot = 0;
					isShot = 0;
				}
			}

			//重力
			if (a.alive) {
				a.velocity.Y -= 0.8f;
				a.pos.Y -= a.velocity.Y;
				a.pos.WorldY -= a.velocity.Y;
			}
			//ゴーストの動き
			currentTime = time(nullptr);
			srand(currentTime);
			for (int i = 0; i < maxGhosts; i++) {
				if (ghost[i].alive && sceneChange == 0 && a.alive) {
					if (i != 0) {
						ghostRadian[i] = atan2f((ghost[i].pos.Y - a.pos.WorldY), (ghost[i].pos.X - a.pos.X));
						ghost[i].dir.X = cosf(ghostRadian[i]);
						ghost[i].dir.Y = sinf(ghostRadian[i]);
						ghost[i].pos.X -= ghost[i].velocity.X * ghost[i].dir.X;
						ghost[i].pos.Y -= ghost[i].velocity.Y * ghost[i].dir.Y;
					}
					else if (eatTime == 0 && atackStop == 0 && atackTime == 0) {
						ghostRadian[i] = atan2f((ghost[i].pos.Y - a.pos.WorldY), (ghost[i].pos.X - a.pos.X));
						ghost[i].dir.X = cosf(ghostRadian[i]);
						ghost[i].dir.Y = sinf(ghostRadian[i]);
						ghost[i].pos.X -= ghost[i].velocity.X * ghost[i].dir.X;
						ghost[i].pos.Y -= ghost[i].velocity.Y * ghost[i].dir.Y;
						if (ghost[i].velocity.X * ghost[i].dir.X * ghost[i].velocity.X * ghost[i].dir.X > ghost[i].velocity.Y * ghost[i].dir.Y * ghost[i].velocity.Y * ghost[i].dir.Y) {
							if (ghost[i].dir.X > 0) {
								ghostAnimationType = LEFT;
							}
							else {
								ghostAnimationType = RIGHT;
							}
						}
						else {
							if (ghost[i].dir.Y > 0) {
								ghostAnimationType = UP;
							}
							else {
								ghostAnimationType = DOWN;
							}
						}
					}

				}
				disX = (a.pos.X - appear[i].pos.X) * (a.pos.X - appear[i].pos.X);
				disY = (a.pos.WorldY - appear[i].pos.Y) * (a.pos.WorldY - appear[i].pos.Y);
				dis = sqrtf(disX + disY);
				if (i < maxGhosts - 1) {
					if (dis <= a.rX + appear[i].rX && ghost[i + 1].alive == 0) {
						ghost[i + 1].pos.X = (rand() % 12) * 100;
						ghost[i + 1].pos.Y = a.pos.WorldY + 200.0f;;
						ghost[i + 1].alive = 1;
					}

				}
				disX = (ghost[0].pos.X - ghost[i].pos.X) * (ghost[0].pos.X - ghost[i].pos.X);
				disY = (ghost[0].pos.Y - ghost[i].pos.Y) * (ghost[0].pos.Y - ghost[i].pos.Y);
				dis = sqrtf(disX + disY);
				if (i != 0 && ghost[i].alive == 1 && dis <= ghost[0].rX + ghost[i].rX && atackStop == 0) {
					ghost[i].alive = 2;
					eatTime = 60;
					ghost[0].velocity.X += 0.3f;
					ghost[0].velocity.Y += 0.3f;
					ghostSize += 0.1f;
				}
			}
			if (atackCoolTime < 150 && eatTime == 0 && atackStop == 0 && atackTime == 0 && sceneChange == 0 && a.alive) {
				atackCoolTime += 1;
			}
			else if (atackTime == 0 && sceneChange == 0 && atackStop == 0 && eatTime == 0 && atackTime == 0 && a.alive) {
				atackCoolTime = 0;
				atackStop = 10;
				atackTime = 60;
				ghostRadian[0] = atan2f((ghost[0].pos.Y - a.pos.WorldY), (ghost[0].pos.X - a.pos.X));
				ghost[0].dir.X = cosf(ghostRadian[0]);
				ghost[0].dir.Y = sinf(ghostRadian[0]);
				ghost[0].shotVelocity.X = ghost[0].velocity.X * ghost[0].dir.X;
				ghost[0].shotVelocity.Y = ghost[0].velocity.Y * ghost[0].dir.Y;
			}
			if (atackTime > 0 && sceneChange == 0 && atackStop == 0 && atackCoolTime == 0) {
				if (eatTime > 0) {
					atackTime = 0;
				}
				else {
					ghostAtackFlag = 1;
					ghost[0].pos.X -= ghost[0].shotVelocity.X * 4;
					ghost[0].pos.Y -= ghost[0].shotVelocity.Y * 4;
					atackTime -= 1;
				}
			}
			else if (sceneChange == 0 && atackStop == 0) {
				ghostAtackFlag = 0;
				atackTime = 0;
			}
			if (atackStop > 0 && eatTime == 0 && sceneChange == 0) {
				atackStop -= 1;
			}
			else if (sceneChange == 0) {
				atackStop = 0;
			}
			if (eatTime > 0 && sceneChange == 0) {
				eatTime -= 1;
				ghost[0].rX += 0.25f;
				ghost[0].rY += 0.25f;
			}
			else if (sceneChange == 0) {
				eatTime = 0;
			}
			//プレイヤーとゴーストの当たり判定
			for (int i = 0; i < maxGhosts; i++) {
				if (ghost[i].alive == 1) {
					disX = (a.pos.X - ghost[i].pos.X) * (a.pos.X - ghost[i].pos.X);
					disY = (a.pos.WorldY - ghost[i].pos.Y) * (a.pos.WorldY - ghost[i].pos.Y);
					dis = sqrtf(disX + disY);
					if (dis <= a.rX + ghost[i].rX) {
						isHitBoss = 1;
						a.alive = 0;
					}
				}
			}
			//ワープの当たり判定
			disX = (a.pos.X - startWarp.pos.X) * (a.pos.X - startWarp.pos.X);
			disY = (a.pos.WorldY - startWarp.pos.Y) * (a.pos.WorldY - startWarp.pos.Y);
			dis = sqrtf(disX + disY);
			if (dis <= a.rX + startWarp.rX) {
				startWarp.color = RED;
				warpFlag = 1;
				if (keys[DIK_S] && preKeys[DIK_S] == 0 && a.alive) {
					a.pos.X = endWarp.pos.X;
					a.pos.WorldY = endWarp.pos.Y;
					a.pos.momentX = a.pos.X;
					a.pos.momentY = a.pos.WorldY;
				}
			}
			else {
				disX = (a.pos.X - endWarp.pos.X) * (a.pos.X - endWarp.pos.X);
				disY = (a.pos.WorldY - endWarp.pos.Y) * (a.pos.WorldY - endWarp.pos.Y);
				dis = sqrtf(disX + disY);
				if (dis <= a.rX + endWarp.rX) {
					startWarp.color = RED;
					warpFlag = 1;
					if (keys[DIK_S] && preKeys[DIK_S] == 0 && a.alive) {
						a.pos.X = startWarp.pos.X;
						a.pos.WorldY = startWarp.pos.Y;
						a.pos.momentX = a.pos.X;
						a.pos.momentY = a.pos.WorldY;
					}
				}
				else {
					warpFlag = 0;
					startWarp.color = BLUE;
				}
			}
			//障害物の当たり判定X
			for (int i = 0; i < maxBlockY; i++) {
				for (int j = 0; j < maxBlock; j++) {
					a.pos.X = ClampX(a.pos.momentX, a.pos.X, a.rX, a.pos.WorldY, a.rY, block[i][j].pos.X, (block[i][j].pos.X + block[i][j].width.X), block[i][j].pos.Y, (block[i][j].pos.Y + block[i][j].width.Y));
					a.shotVelocity.X = notUpClampShotX(a.pos.momentX, a.pos.X, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, block[i][j].pos.X, (block[i][j].pos.X + block[i][j].width.X), block[i][j].pos.Y, (block[i][j].pos.Y + block[i][j].width.Y), a.shotVelocity.X, isGround);
					a.shotVelocity.Y = notUpClampShotY(a.pos.momentX, a.pos.X, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, block[i][j].pos.X, (block[i][j].pos.X + block[i][j].width.X), block[i][j].pos.Y, (block[i][j].pos.Y + block[i][j].width.Y), a.shotVelocity.Y, isGround);
					//階段
					if (i == 0) {
						if (a.pos.momentX >= block[0][j].pos.X + block[0][j].width.X + a.rX) {
							if (a.pos.X <= block[0][j].pos.X + block[0][j].width.X + a.rX && a.pos.WorldY > block[0][j].pos.Y - a.rY && a.pos.WorldY < block[0][j].pos.Y + block[0][j].width.Y + a.rY) {
								a.pos.WorldY = block[0][j].pos.Y - a.rY;
								a.shotVelocity.X = 0.0f;
								a.shotVelocity.Y = 0.0f;
								a.pos.X -= 1;
							}
						}
					}
					else if (i >= 12 && i != 14 && i != 15 && i != 16 && i != 18) {
						if (a.pos.momentX <= block[i][j].pos.X - a.rX) {
							if (a.pos.X >= block[i][j].pos.X - a.rX && a.pos.WorldY > block[i][j].pos.Y - a.rY && a.pos.WorldY < block[i][j].pos.Y + block[i][j].width.Y + a.rY) {
								a.pos.WorldY = block[i][j].pos.Y - a.rY;
								a.shotVelocity.X = 0.0f;
								a.shotVelocity.Y = 0.0f;
								a.pos.X += 1;
							}
						}
					}
				}
				if (a.pos.momentX >= block[11][0].pos.X + block[11][0].width.X + a.rX) {
					if (a.pos.X <= block[11][0].pos.X + block[11][0].width.X + a.rX && a.pos.WorldY > block[11][0].pos.Y - a.rY && a.pos.WorldY < block[11][0].pos.Y + block[11][0].width.Y + a.rY) {
						a.pos.WorldY = block[11][0].pos.Y - a.rY;
						a.pos.X -= 1;
					}
				}

			}
			if (a.pos.momentX <= block[3][0].pos.X - a.rX) {
				if (a.pos.X >= block[3][0].pos.X - a.rX && a.pos.WorldY > block[3][0].pos.Y - a.rY && a.pos.WorldY < block[3][0].pos.Y + block[3][0].width.Y + a.rY) {
					a.pos.WorldY = block[3][0].pos.Y - a.rY;
					a.pos.X += 1;
				}
			}
			if (a.pos.momentX <= block[4][0].pos.X - a.rX) {
				if (a.pos.X >= block[4][0].pos.X - a.rX && a.pos.WorldY > block[4][0].pos.Y - a.rY && a.pos.WorldY < block[4][0].pos.Y + block[4][0].width.Y + a.rY) {
					a.pos.WorldY = block[4][0].pos.Y - a.rY;
					a.pos.X += 1;
				}
			}
			for (int i = 0; i < 9; i++) {
				a.pos.X = ClampX(a.pos.momentX, a.pos.X, a.rX, a.pos.WorldY, a.rY, freeBlock[i].pos.X, (freeBlock[i].pos.X + freeBlock[i].width.X), freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y));
				a.shotVelocity.X = ClampShotX(a.pos.momentX, a.pos.X, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, freeBlock[i].pos.X, (freeBlock[i].pos.X + freeBlock[i].width.X), freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), a.shotVelocity.X, isGround);
				a.shotVelocity.Y = ClampShotY(a.pos.momentX, a.pos.X, a.rX, a.pos.momentY, a.pos.WorldY, a.rY, freeBlock[i].pos.X, (freeBlock[i].pos.X + freeBlock[i].width.X), freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), a.shotVelocity.Y, isGround);
			}

			//障害物の当たり判定Y
			for (int i = 0; i < maxBlockY; i++) {
				for (int j = 0; j < maxBlock; j++) {
					a.pos.WorldY = ClampY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, block[i][j].pos.Y, (block[i][j].pos.Y + block[i][j].width.Y), block[i][j].pos.X, block[i][j].pos.X + block[i][j].width.X);
					isGround = ClampGround(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, block[i][j].pos.Y, (block[i][j].pos.Y + block[i][j].width.Y), block[i][j].pos.X, block[i][j].pos.X + block[i][j].width.X, isGround);
					a.velocity.Y = ClampVelocityY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, block[i][j].pos.Y, (block[i][j].pos.Y + block[i][j].width.Y), block[i][j].pos.X, block[i][j].pos.X + block[i][j].width.X, a.velocity.Y);
				}

			}
			for (int i = 0; i < 9; i++) {
				if (i != 1 && i != 4) {
					a.pos.WorldY = ClampY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X);
					isGround = ClampGround(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X, isGround);
					a.velocity.Y = ClampVelocityY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X, a.velocity.Y);

				}
				else {
					a.pos.WorldY = spClampY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X);
					if (isGround == 0) {
						isGround = ClampGround(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X, isGround);
					}
					a.velocity.Y = spClampVelocityY(a.pos.momentY, a.pos.WorldY, a.rY, a.pos.X, a.rX, freeBlock[i].pos.Y, (freeBlock[i].pos.Y + freeBlock[i].width.Y), freeBlock[i].pos.X, freeBlock[i].pos.X + freeBlock[i].width.X, a.velocity.Y);

				}
			}
			if (a.pos.X <= freeBlock[2].pos.X + freeBlock[2].width.X + a.rX && a.pos.X >= freeBlock[2].pos.X && a.pos.WorldY > freeBlock[2].pos.Y - a.rY && a.pos.WorldY < freeBlock[2].pos.Y + freeBlock[2].width.Y + a.rY) {
				a.pos.X = freeBlock[2].pos.X + freeBlock[2].width.X + a.rX;
			}
			if (a.pos.X <= freeBlock[5].pos.X + freeBlock[5].width.X + a.rX && a.pos.X >= freeBlock[5].pos.X && a.pos.WorldY > freeBlock[5].pos.Y - a.rY && a.pos.WorldY < freeBlock[5].pos.Y + freeBlock[5].width.Y + a.rY) {
				a.pos.X = freeBlock[5].pos.X + freeBlock[5].width.X + a.rX;
			}
			disX = (a.pos.X - amulet.pos.X) * (a.pos.X - amulet.pos.X);
			disY = (a.pos.WorldY - amulet.pos.Y) * (a.pos.WorldY - amulet.pos.Y);
			dis = sqrtf(disX + disY);
			if (dis < a.rX + amulet.rX) {
				getAmulet = 1;
			}
			//出口の処理
			if (a.pos.X - a.rX <= exit.pos.X + exit.width.X && a.pos.X + a.rX >= exit.pos.X && a.pos.WorldY + a.rY >= exit.pos.Y && a.pos.WorldY - a.rY <= exit.pos.Y + exit.width.Y) {
				if (keys[DIK_S] && preKeys[DIK_S] == 0 && getAmulet == 1 && a.alive ||
					keys[DIK_W] && preKeys[DIK_W] == 0 && getAmulet == 1 && a.alive) {
					sceneChange = 2;
				}
				if (sceneChange == 2) {
					if (popUp[0].width.X <= 400) {
						popUp[0].width.X += 10;
						popUp[0].pos.X -= 10 / 2;
						popUp[0].width.Y += 10 * 0.5;
						popUp[0].pos.Y -= (10 * 0.5) / 2;
					}
					else {
						popUp[1].width.X = 120;
						popUp[1].pos.X = popUp[0].pos.X + 50;
						popUp[1].width.Y = 50;
						popUp[1].pos.Y = popUp[0].pos.Y + 100;
						popUp[2].width.X = 120;
						popUp[2].pos.X = popUp[0].pos.X + popUp[0].width.X - 170;
						popUp[2].width.Y = 50;
						popUp[2].pos.Y = popUp[0].pos.Y + 100;
						if (mouse.X >= popUp[1].pos.X && mouse.X <= popUp[1].pos.X + popUp[1].width.X &&
							mouse.Y >= popUp[1].pos.Y && mouse.Y <= popUp[1].pos.Y + popUp[1].width.Y) {
							popUpColor[1] = RED;
							leftIn = 1;
							if (Novice::IsTriggerMouse(0)) {
								sceneChange = 1;
							}
						}
						else {
							leftIn = 0;
							popUpColor[1] = BLACK;
						}
						if (mouse.X >= popUp[2].pos.X && mouse.X <= popUp[2].pos.X + popUp[2].width.X &&
							mouse.Y >= popUp[2].pos.Y && mouse.Y <= popUp[2].pos.Y + popUp[2].width.Y) {
							popUpColor[2] = BLUE;
							rightIn = 1;
							if (Novice::IsTriggerMouse(0)) {
								popUp[0].pos.X = kwindowsLeft + kwindowsRight / 2;
								popUp[0].pos.Y = kwindowsUp + kwindowsDown / 2;
								popUp[0].width.X = 0.0f;
								popUp[0].width.Y = 0.0f;
								popUp[1].width.X = 0;
								popUp[1].width.Y = 0;
								popUp[2].width.X = 0;
								popUp[2].width.Y = 00;
								sceneChange = 0;
							}
						}
						else {
							rightIn = 0;
							popUpColor[2] = BLACK;
						}
					}
				}
				if (a.pos.X > exit.pos.X + (exit.width.X / 2) && sceneChange == 1) {
					animeDir = LEFT;
					a.pos.X -= 1;
					a.pos.WorldX -= 1;
					if (a.pos.X < exit.pos.X + (exit.width.X / 2)) {
						a.pos.X = exit.pos.X + (exit.width.X / 2);
					}
				}
				else if (a.pos.X < exit.pos.X + (exit.width.X / 2) && sceneChange == 1) {
					animeDir = RIGHT;
					a.pos.WorldX += 1;
					a.pos.X += 1;
					if (a.pos.X > exit.pos.X + (exit.width.X / 2)) {
						a.pos.X = exit.pos.X + (exit.width.X / 2);
					}
				}
				else if (sceneChange == 1) {
					a.shotVelocity.X = 0.0f;
					a.shotVelocity.Y = 0.0f;
					terrainA.rY = 0.0f;
					terrainA.pos.X = 700.0f;
					terrainA.pos.Y = bgY[1].pos.Y - terrainA.rY;
					terrainA.rX = 400.0f;
					terrainA.rY = 10.0f;
					terrainA.velocity.X = 5.0f;
					score += 200;
					scene = STAGE;
					clearGhost = 1;
					atackCoolTime = 0;
					atackStop = 0;
					atackTime = 0;
					bossTime = 0;
					eatTime = 0;
					a.pos.X = bossDoor[1].pos.X;
					a.pos.WorldX = a.pos.X;
					a.pos.WorldY = bossDoor[1].pos.Y;
					a.pos.Y = 360.0f;
					isGround = 1;
					a.velocity.Y = 0.0f;
					popUp[0].pos.X = kwindowsLeft + kwindowsRight / 2;
					popUp[0].pos.Y = kwindowsUp + kwindowsDown / 2;
					popUp[0].width.X = 0.0f;
					popUp[0].width.Y = 0.0f;
					popUp[1].width.X = 0;
					popUp[1].width.Y = 0;
					popUp[2].width.X = 0;
					popUp[2].width.Y = 0;
					popUp[1].pos.X = -1000;
					popUp[2].pos.X = -1000;
					sceneChange = 0;
					leftIn = 0;
					rightIn = 0;

				}
			}
			else {
				popUp[0].pos.X = kwindowsLeft + kwindowsRight / 2;
				popUp[0].pos.Y = kwindowsUp + kwindowsDown / 2;
				popUp[0].width.X = 0.0f;
				popUp[0].width.Y = 0.0f;
				popUp[1].width.X = 0;
				popUp[1].width.Y = 0;
				popUp[2].width.X = 0;
				popUp[2].width.Y = 0;
				sceneChange = 0;
				popUp[1].pos.X = -1000;
				popUp[2].pos.X = -1000;
				leftIn = 0;
				rightIn = 0;
			}
			//復活処理
			if (a.alive == 0) {
				if (isHitBoss == 1 || isHitBoss == 2) {
					a.color -= 5;
				}
				if (isHitBoss && a.color <= WHITE - 0xff) {
					boss.pos.X = boss.pos.startX;
					boss.pos.Y = boss.pos.startY;

					scene = STAGE;
					isHole = 0;
					a.color = WHITE;
					isHitBoss = 0.0f;
					a.alive = 1;
					a.velocity.Y = 0.0f;
					a.shotVelocity.X = 0.0f;
					a.shotVelocity.Y = 0.0f;
					a.pos.X = bossDoor[1].pos.X + bossDoor[1].width.X / 2;
					a.pos.WorldX = a.pos.X;
					a.pos.Y = sPosY;
					a.pos.WorldY = bossDoor[1].pos.Y + bossDoor[1].width.Y - a.rY - 1;
				}
				if (a.alive == 1) {
					slimeHp -= 1;
					//ゲームオーバー処理
					if (slimeHp <= -1) {
						scene = GAMEOVER;
					}
					//復活
					else {
						ghostAnimationTime = 0;
						ghostAtackFlag = 0;
						ghostFireAnimationTime = 0;
						ghostSize = 1.0f;
						for (int i = 0; i < maxGhosts; i++) {
							if (i != 0) {
								ghost[i].alive = 0;
							}
							ghost[i].pos.X = 1000.0f;
							ghost[i].pos.Y = 650.0f - i * 300;
							ghost[i].rX = 70.0f;
							ghost[i].rY = 70.0f;
							ghost[i].velocity.X = 3.0f;
							ghost[i].velocity.Y = 3.0f;
							ghost[i].color = BLACK;
						}
						eatTime = 0;
						atackStop = 0;
						initialize = 0;
						isBossAtack = 0;
						atackCoolTime = 0.0f;
						atackTime = 0.0f;
						bossTime = 0.0f;
						bossHitStop = 0.0f;
						terrainA.rY = 0.0f;
						terrainA.pos.X = 700.0f;
						terrainA.pos.Y = bgY[1].pos.Y - terrainA.rY;
						terrainA.rX = 400.0f;
						terrainA.rY = 10.0f;
						terrainA.velocity.X = 5.0f;
						popUp[1].pos.X = -1000;
						popUp[2].pos.X = -1000;
					}
				}
			}
			//壁の当たり判定
			if (kwindowsLeft + a.rX > a.pos.X) {
				b.pos.X = a.pos.X + kwindowsRight;
				if (b.pos.X + a.rX < kwindowsRight) {
					a.pos.X = b.pos.X;
					b.pos.X = 2000;
				}
			}
			else if (kwindowsRight - a.rX < a.pos.X) {
				b.pos.X = a.pos.X - kwindowsRight;
				if (b.pos.X - a.rX > kwindowsLeft) {
					a.pos.X = b.pos.X;
					b.pos.X = -1000;
				}
			}
			else {
				b.pos.X = -1000;
			}
			//上下の当たり判定
			if (kwindowsUp + a.rY >= a.pos.Y) {
				a.shotVelocity.Y *= -0.5f;
				a.shotVelocity.X *= 0.5f;
				a.pos.Y = kwindowsUp + a.rY;
				a.pos.WorldY = bgY[3].pos.Y + a.rY;
			}
			if (kwindowsDown - a.rY - ground.width.WorldY <= a.pos.Y) {
				a.shotVelocity.Y *= -1;
				a.shotVelocity.X *= 1;
				isGround = 1;
				a.velocity.Y = 0.0f;
				a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY;
				a.pos.WorldY = kwindowsDown - a.rX - ground.width.WorldY;
			}
			//スクロール値Yの計算
			if (a.pos.WorldY <= sPosY && a.pos.WorldY >= bgY[3].pos.Y + sPosY) {
				a.pos.Y = sPosY;
				sY = a.pos.WorldY - a.pos.Y;
			}
			if (a.pos.WorldY >= sPosY) {
				a.pos.Y = a.pos.WorldY;
				sY = 0;
			}
			if (a.pos.WorldY <= bgY[3].pos.Y + sPosY) {
				sY = bgY[3].pos.Y;
				a.pos.Y = a.pos.WorldY - sY;

			}
			mouseDisX = a.pos.X - mouseClick.X;
			mouseDisY = a.pos.Y - mouseClick.Y;


			mouseDisX = a.pos.X - mouseClick.X;
			mouseDisY = a.pos.Y - mouseClick.Y;
			//振動
			if (a.isSpace == 1 && a.back == 0 && a.reflect != a.maxReflect) {
				a.frame += 1;
				if (a.stop == 0) {
					a.t += a.tIncrement;
					a.easeT = a.t * a.t;
				}
				if (a.easeT > 1.2f && a.reflect < a.maxReflect && a.reflect % 2 == 0) {
					a.tIncrement *= -1;
					a.reflect += 1;

				}
				else if (a.easeT < 0.8f && a.reflect % 2 == 1 && a.reflect < a.maxReflect) {
					a.tIncrement *= -1;
					a.reflect += 1;
				}
				if (a.reflect == a.maxReflect) {
					a.vibration = 0;
					a.isSpace = 0;
					a.back = 1;
				}
				a.vibration = (1.0f - a.easeT) * 0 + a.easeT * 16;
			}
			else {
				if (a.easeT > 0.0f) {
					a.easeT -= 0.1f;
				}
				else {
					a.easeT = 0.0f;
				}
				a.tIncrement = 0.2f;
				a.reflect = 0;
				a.easeT = 0.0f;
				a.t = 0.0f;
				a.frame = 0;
				a.stop = 0;
				a.vibration = 0.0f;
			}


			//マップの画像
			for (int i = 0; i < maxMapY; i++) {
				Novice::DrawSprite(bg[0][0].X, bg[3][0].Y - sY, ghostBgHandle, 1, 1, 0.0f, WHITE);
			}
			//地面の描画
			Novice::DrawBox(ground.pos.WorldX - sX, ground.pos.WorldY - sY, ground.width.WorldX, ground.width.WorldY, 0.0f, 0x2f4f4fff, kFillModeSolid);
			//障害物の描画
			for (int i = 0; i < maxBlockY; i++) {
				for (int j = 0; j < maxBlock; j++) {
					Novice::DrawBox(block[i][j].pos.X, block[i][j].pos.Y - sY, block[i][j].width.X, block[i][j].width.Y, 0.0f, 0x1f1f1fff, kFillModeSolid);
				}
			}
			for (int i = 0; i < 9; i++) {
				Novice::DrawBox(freeBlock[i].pos.X, freeBlock[i].pos.Y - sY, freeBlock[i].width.X, freeBlock[i].width.Y, 0.0f, 0x1f1f1fff, kFillModeSolid);
			}
			for (int i = 1; i < maxBlock; i++) {
				Novice::DrawSprite(block[0][i].pos.X, block[0][i].pos.Y - sY, ghostStairsHandle, 1, 1, 0.0f, WHITE);
			}
			for (int i = 12; i < maxBlockY; i++) {
				if (i == 12 || i == 13 || i == 17) {
					for (int j = 1; j < maxBlock; j++) {
						Novice::DrawSprite(block[i][j].pos.X + block[i][j].width.X, block[i][j].pos.Y - sY, ghostStairsHandle, -1, 1, 0.0f, WHITE);
					}
				}
			}
			Novice::DrawSprite(550, -330 - sY, ghostFreeBlockHandle, 1, 1, 0.0f, WHITE);
			//お札の描画
			if (getAmulet == 0) {
				if (amuletAnimationTime < 30) {
					Novice::DrawSprite(amulet.pos.X - 44, amulet.pos.Y - 10 - sY, ghostAmulet1Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(amulet.pos.X - 44, amulet.pos.Y - 10 - sY, ghostAmulet2Handle, 1, 1, 0.0f, WHITE);
				}

			}
			//標識の描画
			Novice::DrawSprite(200, 400 - sY, ghostEscapeHandle, 2, 2, 0.0f, WHITE);
			Novice::DrawSprite(1000, 100 - sY, ghostSignHandle, 1, 1, cos(M_PI / 4), WHITE);
			//ワープの描画
			if (warpFlag == 0) {
				if (warpAnimationTime < 20) {
					Novice::DrawSprite(startWarp.pos.X - startWarp.rX, startWarp.pos.Y - startWarp.rX - sY, ghostWarp1Handle, warpSize, warpSize, 0.0f, WHITE);
					Novice::DrawSprite(endWarp.pos.X - startWarp.rX, endWarp.pos.Y - startWarp.rX - sY, ghostWarp1Handle, warpSize, warpSize, 0.0f, WHITE);
				}
				else if (warpAnimationTime < 40) {
					Novice::DrawSprite(startWarp.pos.X - startWarp.rX, startWarp.pos.Y - startWarp.rX - sY, ghostWarp2Handle, warpSize, warpSize, 0.0f, WHITE);
					Novice::DrawSprite(endWarp.pos.X - startWarp.rX, endWarp.pos.Y - startWarp.rX - sY, ghostWarp2Handle, warpSize, warpSize, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(startWarp.pos.X - startWarp.rX, startWarp.pos.Y - startWarp.rX - sY, ghostWarp3Handle, warpSize, warpSize, 0.0f, WHITE);
					Novice::DrawSprite(endWarp.pos.X - startWarp.rX, endWarp.pos.Y - startWarp.rX - sY, ghostWarp3Handle, warpSize, warpSize, 0.0f, WHITE);
				}

			}
			else {
				if (warpAnimationTime < 20) {
					Novice::DrawSprite(startWarp.pos.X - startWarp.rX, startWarp.pos.Y - startWarp.rX - sY, ghostWarp4Handle, warpSize, warpSize, 0.0f, WHITE);
					Novice::DrawSprite(endWarp.pos.X - startWarp.rX, endWarp.pos.Y - startWarp.rX - sY, ghostWarp4Handle, warpSize, warpSize, 0.0f, WHITE);
				}
				else if (warpAnimationTime < 40) {
					Novice::DrawSprite(startWarp.pos.X - startWarp.rX, startWarp.pos.Y - startWarp.rX - sY, ghostWarp5Handle, warpSize, warpSize, 0.0f, WHITE);
					Novice::DrawSprite(endWarp.pos.X - startWarp.rX, endWarp.pos.Y - startWarp.rX - sY, ghostWarp5Handle, warpSize, warpSize, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(startWarp.pos.X - startWarp.rX, startWarp.pos.Y - startWarp.rX - sY, ghostWarp6Handle, warpSize, warpSize, 0.0f, WHITE);
					Novice::DrawSprite(endWarp.pos.X - startWarp.rX, endWarp.pos.Y - startWarp.rX - sY, ghostWarp6Handle, warpSize, warpSize, 0.0f, WHITE);
				}

			}
			//ダンジョンのドア
			Novice::DrawBox(exit.pos.X, exit.pos.Y - sY, exit.width.X, exit.width.Y, 0.0f, GREEN, kFillModeSolid);
			if (exitAnimationTime < 30) {
				Novice::DrawSprite(exit.pos.X, exit.pos.Y - sY, ghostExit1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(exit.pos.X, exit.pos.Y - sY, ghostExit2Handle, 1, 1, 0.0f, WHITE);
			}
			//ゴーストの描画
			for (int i = 1; i < maxGhosts; i++) {
				if (ghost[i].alive == 1) {
					if (ghostFireAnimationTime < 10) {
						Novice::DrawSprite(ghost[i].pos.X - ghost[i].rX, ghost[i].pos.Y - ghost[i].rY - sY, ghostFire1Handle, 1, 1, 0.0f, WHITE);
					}
					else if (ghostFireAnimationTime < 20) {
						Novice::DrawSprite(ghost[i].pos.X - ghost[i].rX, ghost[i].pos.Y - ghost[i].rY - sY, ghostFire2Handle, 1, 1, 0.0f, WHITE);
					}
					else {
						Novice::DrawSprite(ghost[i].pos.X - ghost[i].rX, ghost[i].pos.Y - ghost[i].rY - sY, ghostFire3Handle, 1, 1, 0.0f, WHITE);
					}
				}

			}
			if (ghostAnimationType == LEFT) {
				if (ghostAnimationTime < 20) {
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostSide1Handle, ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == LEFT) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackSideHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
				else if (ghostAnimationTime < 40) {
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostSide2Handle, ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == LEFT) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackSideHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
				else {
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostSide3Handle, ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == LEFT) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackSideHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
			}
			else if (ghostAnimationType == RIGHT) {
				if (ghostAnimationTime < 20) {
					Novice::DrawSprite(ghost[0].pos.X + ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostSide1Handle, -ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == RIGHT) {
						Novice::DrawSprite(ghost[0].pos.X + ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackSideHandle, -ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
				else if (ghostAnimationTime < 40) {
					Novice::DrawSprite(ghost[0].pos.X + ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostSide2Handle, -ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == RIGHT) {
						Novice::DrawSprite(ghost[0].pos.X + ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackSideHandle, -ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
				else {
					Novice::DrawSprite(ghost[0].pos.X + ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostSide3Handle, -ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == RIGHT) {
						Novice::DrawSprite(ghost[0].pos.X + ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackSideHandle, -ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
			}
			else if (ghostAnimationType == UP) {
				if (ghostAnimationTime < 20) {
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostUp1Handle, ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == UP) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
				else if (ghostAnimationTime < 40) {
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostUp2Handle, ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == UP) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
				else {
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostUp3Handle, ghostSize, ghostSize, 0.0f, WHITE);
					if (ghostAtackFlag == 1 && ghostAnimationType == UP) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
				}
			}
			else if (ghostAnimationType == DOWN) {
				if (ghostAnimationTime < 20) {
					if (ghostAtackFlag == 1 && ghostAnimationType == DOWN) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostDown1Handle, ghostSize, ghostSize, 0.0f, WHITE);
				}
				else if (ghostAnimationTime < 40) {
					if (ghostAtackFlag == 1 && ghostAnimationType == DOWN) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostDown2Handle, ghostSize, ghostSize, 0.0f, WHITE);
				}
				else {
					if (ghostAtackFlag == 1 && ghostAnimationType == DOWN) {
						Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostAtackHandle, ghostSize, ghostSize, 0.0f, WHITE);
					}
					Novice::DrawSprite(ghost[0].pos.X - ghost[0].rX, ghost[0].pos.Y - ghost[0].rY - sY, ghostDown3Handle, ghostSize, ghostSize, 0.0f, WHITE);
				}
			}
			//プレイヤー残機
			Novice::DrawSprite(0 + a.rX, 0 + a.rY, slime1Handle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(a.rX + a.rX + a.rX + 10, 0 + a.rY + 16, xHandle, 1, 1, 0.0f, WHITE);
			//プレイヤーの描画
			if (Novice::IsPressMouse(0) == 0 && slimeShot == 0) {
				if (animeDir == LEFT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime1Handle, 1, 1, 0.0f, a.color);
						Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slime1Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime3Handle, 1, 1, 0.0f, a.color);
						Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slime3Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime2Handle, 1, 1, 0.0f, a.color);
						Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slime2Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slime4Handle, 1, 1, 0.0f, a.color);
						Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slime4Handle, 1, 1, 0.0f, a.color);
					}
				}
				else if (animeDir == RIGHT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime1Handle, -1, 1, 0.0f, a.color);
						Novice::DrawSprite(b.pos.X - b.rX + b.rX * 2, a.pos.Y - a.rY, slime1Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime3Handle, -1, 1, 0.0f, a.color);
						Novice::DrawSprite(b.pos.X - b.rX + b.rX * 2, a.pos.Y - a.rY, slime3Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime2Handle, -1, 1, 0.0f, a.color);
						Novice::DrawSprite(b.pos.X - b.rX + b.rX * 2, a.pos.Y - a.rY, slime2Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2, a.pos.Y - a.rY, slime4Handle, -1, 1, 0.0f, a.color);
						Novice::DrawSprite(b.pos.X - b.rX + b.rX * 2, a.pos.Y - a.rY, slime4Handle, -1, 1, 0.0f, a.color);
					}

				}
				else if (animeDir == CLIMB) {
					Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeBackHandle, 1, 1, 0.0f, a.color);
				}
			}
			else if (Novice::IsPressMouse(0) == 1 && slimeShot == 0) {
				if (mouseDragX > mouseDragY) {
					if (mouse.X - mouseClick.X > 0) {
						if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirSide1Handle, 1, 1, 0.0f, a.color);
							Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slimeDirSide1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirSide2Handle, 1, 1, 0.0f, a.color);
							Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slimeDirSide2Handle, 1, 1, 0.0f, a.color);
						}
					}
					else {
						if (slimeAnimationTime > 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X + a.rX, a.pos.Y - a.rY, slimeDirSide1Handle, -1, 1, 0.0f, a.color);
							Novice::DrawSprite(b.pos.X - b.rX + b.rX * 2, a.pos.Y - a.rY, slimeDirSide1Handle, -1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X + a.rX, a.pos.Y - a.rY, slimeDirSide2Handle, -1, 1, 0.0f, a.color);
							Novice::DrawSprite(b.pos.X - b.rX + b.rX * 2, a.pos.Y - a.rY, slimeDirSide2Handle, -1, 1, 0.0f, a.color);
						}
					}

				}
				else if (mouseDragX <= mouseDragY) {
					if (mouse.Y - mouseClick.Y > 0) {
						if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirUp1Handle, 1, 1, 0.0f, a.color);
							Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slimeDirUp1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirUp2Handle, 1, 1, 0.0f, a.color);
							Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slimeDirUp2Handle, 1, 1, 0.0f, a.color);
						}
					}
					else {
						if (slimeAnimationTime <= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirDown1Handle, 1, 1, 0.0f, a.color);
							Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slimeDirDown1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeDirDown2Handle, 1, 1, 0.0f, a.color);
							Novice::DrawSprite(b.pos.X - b.rX, a.pos.Y - a.rY, slimeDirDown2Handle, 1, 1, 0.0f, a.color);
						}
					}

				}

			}
			else if (slimeShot == 1) {
				if (slimeAnimationTime >= 0 && slimeAnimationTime < 5 ||
					slimeAnimationTime >= 30 && slimeAnimationTime < 35) {
					Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot1Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 5 && slimeAnimationTime < 10 ||
					slimeAnimationTime >= 35 && slimeAnimationTime < 40) {
					Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot2Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 10 && slimeAnimationTime < 15 ||
					slimeAnimationTime >= 40 && slimeAnimationTime < 45) {
					Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot3Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 15 && slimeAnimationTime < 20 ||
					slimeAnimationTime >= 45 && slimeAnimationTime < 50) {
					Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot4Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 20 && slimeAnimationTime < 25 ||
					slimeAnimationTime >= 50 && slimeAnimationTime < 55) {
					Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot5Handle, 1, 1, 0.0f, a.color);
				}
				else {
					Novice::DrawSprite(a.pos.X - a.rX, a.pos.Y - a.rY, slimeShot6Handle, 1, 1, 0.0f, a.color);
				}

			}

			//ポップアップ
			if (sceneChange == 2) {
				for (int i = 0; i < 3; i++) {
					Novice::DrawBox(popUp[i].pos.X, popUp[i].pos.Y, popUp[i].width.X, popUp[i].width.Y, 0.0f, popUpColor[i], kFillModeSolid);
				}
				if (leftIn == 0) {
					Novice::DrawSprite(popUp[1].pos.X - 8, popUp[1].pos.Y - 8, doorSelect5Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(popUp[1].pos.X - 8, popUp[1].pos.Y - 8, doorSelect6Handle, 1, 1, 0.0f, WHITE);
				}
				if (rightIn == 0) {
					Novice::DrawSprite(popUp[2].pos.X - 8, popUp[2].pos.Y - 8, doorSelect7Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(popUp[2].pos.X - 8, popUp[2].pos.Y - 8, doorSelect8Handle, 1, 1, 0.0f, WHITE);
				}
			}
			//引っ張りエフェクト
			if (Novice::IsPressMouse(0) && a.alive) {
				Novice::DrawEllipse(mouseClick.X, mouseClick.Y, 10, 10, 0.0f, WHITE, kFillModeSolid);
				Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), WHITE);
			}
			Novice::SetMouseCursorVisibility(0);
			if (Novice::IsPressMouse(0) == 0) {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse2Handle, 1, 1, 0.0f, WHITE);
			}
			break;
		case STAGEBOSS3:
			//経過時間
			if (effect == 0 && devil[1].alive && a.alive == 1) {
				counter += 1;
			}
			if (counter == 60) {
				counter = 0;
				timer += 1;
			}
			momentSlimeHp = slimeHp;
			if (momentSlimeHp < 1000 && momentSlimeHp >= 0) {
				if (momentSlimeHp >= 10) {
					eachNumber[0] = momentSlimeHp / 10;
					momentSlimeHp = momentSlimeHp % 10;
				}
				else {
					eachNumber[0] = 0;
				}
				if (momentSlimeHp >= 0) {
					eachNumber[1] = momentSlimeHp;
				}
				else {
					eachNumber[1] = 0;
				}
			}
			//アニメーションの時間
			//プレイヤー
			slimeAnimationTime += 1;
			if (slimeAnimationTime == 60) {
				slimeAnimationTime = 0;
				currentTime = time(nullptr);
				srand(currentTime);
				slimeAnimationType = rand() % 5;
			}
			if (devil[1].alive == 1) {
				devilBodyAnimationTime += 1;
				if (devilBodyAnimationTime == 60) {
					devilBodyAnimationTime = 0;
				}
			}
			//魔王の攻撃
			if (isBossAtack) {
				devilMarkAnimationTime += 1;
				if (devilMarkAnimationTime == 60) {
					devilMarkAnimationTime = 0;
				}
			}

			//移動前の座標
			a.pos.momentX = a.pos.X;
			a.pos.momentY = a.pos.Y;
			//プレイヤーの操作
			if (a.alive && effect == 0) {
				if (Novice::IsPressMouse(0) == 0) {
					if (keys[DIK_A] && isShot == 0) {
						a.pos.X -= a.velocity.X;
						a.pos.WorldX -= a.velocity.X;
						animeDir = LEFT;
					}
					if (keys[DIK_D] && isShot == 0) {
						a.pos.X += a.velocity.X;
						a.pos.WorldX += a.velocity.X;
						animeDir = RIGHT;
					}
					if (keys[DIK_SPACE] && isShot == 0 && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
				else if (Novice::IsPressMouse(0) == 1) {
					if (keys[DIK_A]) {
						a.pos.X -= a.velocity.X / 2;
						a.pos.WorldX -= a.velocity.X / 2;
						animeDir = LEFT;
					}
					if (keys[DIK_D]) {
						a.pos.X += a.velocity.X / 2;
						a.pos.WorldX += a.velocity.X / 2;
						animeDir = RIGHT;
					}
					if (keys[DIK_SPACE] && isGround == 1) {
						a.velocity.Y = 20;
						isGround = 0;
					}
				}
			}

			//マウスで引っ張る
			Novice::GetMousePosition(&mouse.X, &mouse.Y);
			if (a.alive && effect == 0) {
				if (Novice::IsTriggerMouse(0)) {
					slimeShot = 0;
					mouseClick.X = mouse.X;
					mouseClick.Y = mouse.Y;
				}
				if (Novice::IsPressMouse(0)) {
					isShot = 1;
					radian = atan2f((mouseClick.Y - mouse.Y), (mouseClick.X - mouse.X));
					a.dir.X = cosf(radian);
					a.dir.Y = sinf(radian);
					mouseDisX = sqrtf((mouseClick.X - mouse.X) * (mouseClick.X - mouse.X));
					mouseDisY = sqrtf((mouseClick.Y - mouse.Y) * (mouseClick.Y - mouse.Y));
					mouseDragX = mouseDisX;
					mouseDragY = mouseDisY;
					mouseDis = mouseDisX + mouseDisY;
					a.shotVelocity.X = mouseDisX / 4;
					a.shotVelocity.Y = mouseDisY / 4;
				}
				else if (isShot == 1) {
					slimeShot = 1;
					mouseDis = 0.0f;
					a.pos.X += a.dir.X * a.shotVelocity.X;
					a.pos.WorldX += a.dir.X * a.shotVelocity.X;
					a.pos.Y += a.dir.Y * a.shotVelocity.Y;
					a.pos.WorldY += a.dir.Y * a.shotVelocity.Y;
				}
				else {
					mouseDis = 0.0f;
				}
				if (a.shotVelocity.X > 0.0f && isShot == 1) {
					a.shotVelocity.X -= friction * sqrtf(a.dir.X * a.dir.X);
				}
				else if (a.shotVelocity.X < 0.0f && isShot == 1) {
					a.shotVelocity.X += friction * sqrtf(a.dir.X * a.dir.X);
				}
				if (a.shotVelocity.X <= friction && a.shotVelocity.X >= -friction && isShot == 1) {
					a.shotVelocity.X = 0.0f;
				}

				if (a.shotVelocity.Y > 0.0f && isShot == 1) {
					a.shotVelocity.Y -= friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				else if (a.shotVelocity.Y < 0.0f && isShot == 1) {
					a.shotVelocity.Y += friction * sqrtf(a.dir.Y * a.dir.Y);
				}
				if (a.shotVelocity.Y <= friction && a.shotVelocity.Y >= -friction && isShot == 1) {
					a.shotVelocity.Y = 0.0f;
				}
				if (Novice::IsPressMouse(0) == 0 && a.shotVelocity.X == 0.0f && a.shotVelocity.Y == 0.0f && isShot == 1) {
					slimeShot = 0;
					isShot = 0;
				}
			}

			//重力
			if (a.alive) {
				a.velocity.Y -= 0.8f;
				a.pos.Y -= a.velocity.Y;
				a.pos.WorldY -= a.velocity.Y;
			}
			//魔王の登場演出
			if (effect == 1) {
				if (devilEffectTime < 120) {
					devilEffectTime += 1;
					devil[0].rX = 128.0f;
					devil[0].rY = 128.0f;
				}
				else {
					effect = 0;
					devil[1].pos.X = devil[0].pos.X;
					devil[1].pos.Y = devil[0].pos.Y + 76;
					devil[1].rX = 64;
					devil[1].rY = 64;
				}

			}
			//魔王の移動
			if (effect == 0 && isBossAtack == 0 && atackStop == 0 && explodeFlag == 0) {
				if (move < 120) {
					move += 1;
				}
				else {
					move = 0;
					currentTime = time(nullptr);
					srand(currentTime);
					moveDir = rand() % 2;
				}
				if (a.pos.WorldX > devil[1].pos.X) {
					for (int i = 0; i < 2; i++) {
						devil[i].pos.X += devil[i].velocity.X;
						devil[i].pos.Y += devil[i].velocity.Y;
					}
				}
				else if (a.pos.WorldX < devil[1].pos.X) {
					for (int i = 0; i < 2; i++) {
						devil[i].pos.X -= devil[i].velocity.X;
						devil[i].pos.Y -= devil[i].velocity.Y;
					}
				}
			}

			//魔王の攻撃
			if (effect == 0 && explodeFlag == 0) {
				if (atackCoolTime < 240 && isBossAtack == 0 && atackStop == 0) {
					atackCoolTime += 1;
				}
				else if (isBossAtack == 0 && atackStop == 0) {
					atackStop = 30;
					atackCoolTime = 0;
					currentTime = time(nullptr);
					srand(currentTime);
					AtackType = rand() % 3;
				}
				if (atackStop > 0) {
					atackStop -= 1;
					if (atackStop == 0) {
						isBossAtack = 1;
					}
				}
				else {
					atackStop = 0;
				}
				//攻撃の種類
				if (isBossAtack && AtackType == 0 && atackTime < 240) {
					atackTime += 1;
					if (initialize == 0) {
						beamRadian = 0;
					}
					devil[1].color = 0xffd900ff;
					for (int i = 0; i < maxBeams; i++) {
						if (atackTime > i * 2) {
							beam[i].pos.X = beam[i].pos.startX * cosf(beamRadian) - beam[i].pos.startY * sinf(beamRadian) + devil[1].pos.X;
							beam[i].pos.Y = beam[i].pos.startY * cosf(beamRadian) + beam[i].pos.startX * sinf(beamRadian) + devil[1].pos.Y + 30.0f;
							disX = (a.pos.WorldX - beam[i].pos.X) * (a.pos.WorldX - beam[i].pos.X);
							disY = (a.pos.Y - beam[i].pos.Y) * (a.pos.Y - beam[i].pos.Y);
							dis = sqrtf(disX + disY);
							if (dis < a.rX + beam[i].rX && a.alive == 1) {
								isHitBoss = 1;
								a.alive = 0;
							}
							initialize = 1;
							dis = 0.0f;
						}
					}
					if (atackTime >= (maxBeams - 1) * 2) {
						if (atackTime < 65 + (maxBeams - 1) * 2) {
							beamRadian -= M_PI / 180;
						}
						else {
							beamRadian += M_PI / 180;
						}
					}
				}
				else if (isBossAtack && AtackType == 1 && atackTime < 480) {
					atackTime += 1;
					devil[1].color = BLACK;
					if (initialize == 0) {
						for (int i = 0; i < maxDevilAtacks; i++) {
							devilBullets[i] = 1;
						}
						atackCollision[0].pos.X = devil[0].pos.X - devil[0].rX - atackCollision[0].rX - 50.0f;
						atackCollision[0].pos.Y = devil[0].pos.Y;
						atackCollision[1].pos.X = devil[0].pos.X + devil[0].rX + atackCollision[1].rX + 50.0f;
						atackCollision[1].pos.Y = devil[0].pos.Y;
						atackCollision[2].pos.X = devil[0].pos.X;
						atackCollision[2].pos.Y = devil[0].pos.Y - devil[0].rY - atackCollision[2].rY - 50.0f;
						atackCollision[3].pos.X = devil[0].pos.X - devil[0].rX - atackCollision[3].rX - 25.0f;
						atackCollision[3].pos.Y = devil[0].pos.Y - devil[0].rY - atackCollision[3].rY - 25.0f;
						atackCollision[4].pos.X = devil[0].pos.X + devil[0].rX + atackCollision[4].rX + 25.0f;
						atackCollision[4].pos.Y = devil[0].pos.Y - devil[0].rY - atackCollision[4].rY - 25.0f;
					}
					if (atackTime < 10 && devilBullets[0]) {//一個目の弾
						atackTime += 1;
						atackRadian[0] = atan2f((atackCollision[0].pos.Y - a.pos.Y), (atackCollision[0].pos.X - a.pos.WorldX));
						atackCollision[0].dir.X = cosf(atackRadian[0]);
						atackCollision[0].dir.Y = sinf(atackRadian[0]);
						atackCollision[0].shotVelocity.X = atackCollision[0].velocity.X * atackCollision[0].dir.X;
						atackCollision[0].shotVelocity.Y = atackCollision[0].velocity.Y * atackCollision[0].dir.Y;
					}
					else if (atackCollision[0].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[0]) {
						atackCollision[0].pos.X -= atackCollision[0].shotVelocity.X;
						atackCollision[0].pos.Y -= atackCollision[0].shotVelocity.Y;
						if (atackCollision[0].pos.Y >= kwindowsDown - ground.width.WorldY) {
							devilBullets[0] = 0;
							momentAtackTime = atackTime;
							atackCollision[0].pos.Y = kwindowsDown - ground.width.WorldY;
						}
					}
					else if (atackTime < momentAtackTime + 10 && atackCollision[1].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[1]) {//二個目の弾
						atackTime += 1;
						atackRadian[1] = atan2f((atackCollision[1].pos.Y - a.pos.Y), (atackCollision[1].pos.X - a.pos.WorldX));
						atackCollision[1].dir.X = cosf(atackRadian[1]);
						atackCollision[1].dir.Y = sinf(atackRadian[1]);
						atackCollision[1].shotVelocity.X = atackCollision[1].velocity.X * atackCollision[1].dir.X;
						atackCollision[1].shotVelocity.Y = atackCollision[1].velocity.Y * atackCollision[1].dir.Y;
					}
					else if (atackCollision[1].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[1]) {
						atackCollision[1].pos.X -= atackCollision[1].shotVelocity.X;
						atackCollision[1].pos.Y -= atackCollision[1].shotVelocity.Y;
						if (atackCollision[1].pos.Y >= kwindowsDown - ground.width.WorldY) {
							devilBullets[1] = 0;
							momentAtackTime = atackTime;
							atackCollision[1].pos.Y = kwindowsDown - ground.width.WorldY;
						}
					}
					else if (atackTime < momentAtackTime + 10 && atackCollision[2].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[2]) {//三個目の弾
						atackTime += 1;
						atackRadian[2] = atan2f((atackCollision[2].pos.Y - a.pos.Y), (atackCollision[2].pos.X - a.pos.WorldX));
						atackCollision[2].dir.X = cosf(atackRadian[2]);
						atackCollision[2].dir.Y = sinf(atackRadian[2]);
						atackCollision[2].shotVelocity.X = atackCollision[2].velocity.X * atackCollision[2].dir.X;
						atackCollision[2].shotVelocity.Y = atackCollision[2].velocity.Y * atackCollision[2].dir.Y;
					}
					else if (atackCollision[2].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[2]) {
						atackCollision[2].pos.X -= atackCollision[2].shotVelocity.X;
						atackCollision[2].pos.Y -= atackCollision[2].shotVelocity.Y;
						if (atackCollision[2].pos.Y >= kwindowsDown - ground.width.WorldY) {
							devilBullets[2] = 0;
							momentAtackTime = atackTime;
							atackCollision[2].pos.Y = kwindowsDown - ground.width.WorldY;
						}
					}
					else if (atackTime < momentAtackTime + 10 && atackCollision[3].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[3]) {//四個目の弾
						atackTime += 1;
						atackRadian[3] = atan2f((atackCollision[3].pos.Y - a.pos.Y), (atackCollision[3].pos.X - a.pos.WorldX));
						atackCollision[3].dir.X = cosf(atackRadian[3]);
						atackCollision[3].dir.Y = sinf(atackRadian[3]);
						atackCollision[3].shotVelocity.X = atackCollision[3].velocity.X * atackCollision[3].dir.X;
						atackCollision[3].shotVelocity.Y = atackCollision[3].velocity.Y * atackCollision[3].dir.Y;
					}
					else if (atackCollision[3].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[3]) {
						atackCollision[3].pos.X -= atackCollision[3].shotVelocity.X;
						atackCollision[3].pos.Y -= atackCollision[3].shotVelocity.Y;
						if (atackCollision[3].pos.Y >= kwindowsDown - ground.width.WorldY) {
							devilBullets[3] = 0;
							momentAtackTime = atackTime;
							atackCollision[3].pos.Y = kwindowsDown - ground.width.WorldY;
						}
					}
					else if (atackTime < momentAtackTime + 10 && atackCollision[4].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[4]) {//五個目の弾
						atackTime += 1;
						atackRadian[4] = atan2f((atackCollision[4].pos.Y - a.pos.Y), (atackCollision[4].pos.X - a.pos.WorldX));
						atackCollision[4].dir.X = cosf(atackRadian[4]);
						atackCollision[4].dir.Y = sinf(atackRadian[4]);
						atackCollision[4].shotVelocity.X = atackCollision[4].velocity.X * atackCollision[4].dir.X;
						atackCollision[4].shotVelocity.Y = atackCollision[4].velocity.Y * atackCollision[4].dir.Y;
					}
					else if (atackCollision[4].pos.Y < kwindowsDown - ground.width.WorldY && devilBullets[4]) {
						atackCollision[4].pos.X -= atackCollision[4].shotVelocity.X;
						atackCollision[4].pos.Y -= atackCollision[4].shotVelocity.Y;
						if (atackCollision[4].pos.Y >= kwindowsDown - ground.width.WorldY) {
							devilBullets[4] = 0;
							momentAtackTime = atackTime;
							atackCollision[4].pos.Y = kwindowsDown - ground.width.WorldY;
						}
					}
					for (int i = 0; i < maxDevilAtacks; i++) {
						disX = (a.pos.WorldX - atackCollision[i].pos.X) * (a.pos.WorldX - atackCollision[i].pos.X);
						disY = (a.pos.Y - atackCollision[i].pos.Y) * (a.pos.Y - atackCollision[i].pos.Y);
						dis = sqrtf(disX + disY);
						if (dis < a.rX + atackCollision[i].rX && a.alive == 1) {
							isHitBoss = 1;
							a.alive = 0;
						}
					}
					initialize = 1;
				}
				else if (isBossAtack && AtackType == 2 && atackTime < 360) {
					if (bossHitStop == 0) {
						atackTime += 1;
					}
					if (initialize == 0) {
						for (int i = 0; i < maxDevilAtacks; i++) {
							atackCollision[i].rX = 64.0f;
							atackCollision[i].rY = 64.0f;
						}
					}
					for (int i = 0; i < maxDevilAtacks; i++) {
						if (atackTime > i * 60) {
							if (mark[i] == 0) {
								atackCollision[i].pos.X = a.pos.WorldX;
								atackCollision[i].pos.Y = a.pos.Y;
								momentTime[i] = atackTime;
							}
							mark[i] = 1;
							if (atackTime > momentTime[i] + 30 && mark[i] == 1) {
								atackCollision[i].color = RED;
								disX = (a.pos.WorldX - atackCollision[i].pos.X) * (a.pos.WorldX - atackCollision[i].pos.X);
								disY = (a.pos.Y - atackCollision[i].pos.Y) * (a.pos.Y - atackCollision[i].pos.Y);
								dis = sqrtf(disX + disY);
								if (dis < a.rX + atackCollision[i].rX && a.alive == 1) {
									isHitBoss = 1;
									a.alive = 0;
								}
								initialize = 1;
								dis = 0.0f;
							}
						}
					}
					initialize = 1;
					devil[1].color = BLUE;
				}
				else if (isBossAtack && AtackType == 3 && atackTime < 120) {
					atackTime += 1;
					devil[1].color = GREEN;
				}
				else if (isBossAtack && AtackType == 4 && atackTime < 120) {
					atackTime += 1;
					devil[1].color = WHITE;
				}
				else {
					initialize = 0;
					for (int i = 0; i < maxBeams; i++) {
						beam[i].pos.X = -100.0f;
						beam[i].pos.Y = 0.0f;;
					}
					for (int i = 0; i < maxDevilAtacks; i++) {
						devilBullets[i] = 0;
						mark[i] = 0;
						atackCollision[i].color = BLACK;
						atackCollision[i].rX = 64.0f;
						atackCollision[i].rY = 64.0f;
						atackCollision[i].pos.X = -1000.0f;
					}
					atackTime = 0;
					momentAtackTime = 0;
					isBossAtack = 0;
					devil[1].color = RED;
				}
			}
			//ボスへの攻撃
			if (atackStop > 0 && hitInvincible == 0 || isBossAtack && bossHitStop == 0 && explodeFlag == 0 && hitInvincible == 0) {
				disX = (a.pos.WorldX - devil[1].pos.X) * (a.pos.WorldX - devil[1].pos.X);
				disY = (a.pos.Y - devil[1].pos.Y) * (a.pos.Y - devil[1].pos.Y);
				dis = sqrtf(disX + disY);
				if (dis < a.rX + devil[1].rX && a.alive == 1 && devil[1].hp > 0) {
					a.shotVelocity.X *= -0.5f;
					a.shotVelocity.Y *= -0.5f;
					bossHitStop = 10;
					hitInvincible = 60;
					devil[0].color = WHITE;
					eyeColor = RED;
					devil[1].hp -= 1;
					score += 40;
					if (a.isSpace == 1) {
						a.isSpace = 0;
						a.back = 1;
					}
					else {
						a.back = 0;
						a.isSpace = 1;
					}
					if (devil[1].hp == 0) {
						a.tIncrement = 0.05f;
						a.maxReflect = 20;
						explodeFlag = 1;
					}
				}
				else {
					disX = (a.pos.WorldX - devil[0].pos.X) * (a.pos.WorldX - devil[0].pos.X);
					disY = (a.pos.Y - devil[0].pos.Y) * (a.pos.Y - devil[0].pos.Y);
					dis = sqrtf(disX + disY);
					if (dis < a.rX + devil[0].rX && a.alive == 1) {
						a.shotVelocity.X *= -0.5f;
						a.shotVelocity.Y *= -0.5f;
					}
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					disX = (a.pos.WorldX - devil[i].pos.X) * (a.pos.WorldX - devil[i].pos.X);
					disY = (a.pos.Y - devil[i].pos.Y) * (a.pos.Y - devil[i].pos.Y);
					dis = sqrtf(disX + disY);
					if (dis < a.rX + devil[i].rX && a.alive == 1) {
						a.shotVelocity.X *= -0.5f;
						a.shotVelocity.Y *= -0.5f;
					}
				}
			}
			if (hitInvincible > 0) {
				hitInvincible -= 1;
			}
			else {
				hitInvincible = 0;
			}
			if (bossHitStop > 0) {
				bossHitStop -= 1;
			}
			else if (explodeFlag == 0) {
				bossHitStop = 0;
				eyeColor = WHITE;
				devil[0].color = WHITE;
			}
			//撃破処理
			if (explodeFlag == 1) {
				devil[0].color -= 1;
				if (devil[0].color <= WHITE - 0xff) {
					devil[1].alive = 0;
					popUp[1].pos.X = -1000;
					popUp[2].pos.X = -1000;
					momentTimer = timer;
					scene = GAMECLEAR;
				}
				currentTime = time(nullptr);
				srand(currentTime);
				explodePos = (rand() % 20) - 10;
				explodeTime += 1;
				for (int i = 0; i < maxExplodes; i++) {
					if (explodeTime > i * 30) {


					}
				}
			}
			//ボスの当たり判定
			if (kwindowsLeft + devil[0].rX >= devil[0].pos.X) {
				devil[0].velocity.X *= -1;
				devil[1].velocity.X *= -1;
				devil[0].pos.X = kwindowsLeft + devil[0].rX;
			}
			else if (kwindowsRight * 2 - devil[0].rX <= devil[0].pos.X) {
				devil[0].velocity.X *= -1;
				devil[1].velocity.X *= -1;
				devil[0].pos.X = kwindowsRight * 2 - devil[0].rX;
			}

			//プレイヤー：壁の当たり判定
			if (a.alive) {
				if (kwindowsLeft + a.rX >= a.pos.X) {
					a.shotVelocity.X *= -1;
					a.pos.X = kwindowsLeft + a.rX;
					a.pos.WorldX = a.pos.X;
				}
				else if (kwindowsRight - a.rX <= a.pos.X) {
					a.shotVelocity.X *= -1;
					a.pos.X = kwindowsRight - a.rX;
					a.pos.WorldX = a.pos.X + bgX[1].X;
				}
			}

			//プレイヤー：上下の当たり判定
			if (kwindowsUp + a.rY >= a.pos.Y) {
				a.shotVelocity.Y *= -1;
				a.pos.Y = kwindowsUp + a.rY;
				a.pos.WorldY = bgY[3].pos.Y + a.rY;
			}
			if (kwindowsDown - a.rY - ground.width.WorldY <= a.pos.Y) {
				a.shotVelocity.Y *= -1;
				isGround = 1;
				a.velocity.Y = 0.0f;
				a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY;
				a.pos.WorldY = kwindowsDown - a.rX - ground.width.WorldY;
			}
			else if (isHole == 1) {
				isGround = 0;
			}

			//スクロール値Xの計算
			if (a.alive) {
				if (a.pos.WorldX >= sPosX && a.pos.WorldX <= bgX[1].X + sPosX) {
					a.pos.X = sPosX;
					sX = a.pos.WorldX - sPosX;
				}
				if (a.pos.WorldX <= sPosX) {
					a.pos.X = a.pos.WorldX;
					sX = 0;
				}
				if (a.pos.WorldX >= bgX[1].X + sPosX) {
					sX = bgX[1].X;
					a.pos.X = a.pos.WorldX - sX;
				}
			}
			//プレイヤー復活処理
			if (a.alive == 0) {
				if (isHitBoss == 1 || isHitBoss == 2) {
					a.color -= 5;
				}
				if (isHitBoss && a.color <= WHITE - 0xff) {
					isHole = 0;
					isHitBoss = 0.0f;
					a.alive = 1;
				}
				if (a.alive == 1) {
					//プレイヤー
					slimeHp -= 1;
					//ゲームオーバー処理
					if (slimeHp <= -1) {
						scene = GAMEOVER;
					}
					else {
						sX = 0.0f;
						a.color = WHITE;
						a.pos.X = sPosX;
						a.pos.WorldX = bossDoor[2].pos.X + bossDoor[2].width.X / 2;
						a.pos.Y = sPosY;
						a.pos.WorldY = bossDoor[2].pos.Y + bossDoor[2].width.Y - a.rY - 1;
						a.velocity.Y = 0.0f;
						a.shotVelocity.X = 0.0f;
						a.shotVelocity.Y = 0.0f;
						//魔王
						initialize = 0;
						for (int i = 0; i < maxBeams; i++) {
							beam[i].pos.X = -100.0f;
							beam[i].pos.Y = 0.0f;;
						}
						for (int i = 0; i < maxDevilAtacks; i++) {
							devilBullets[i] = 0;
							mark[i] = 0;
							atackCollision[i].color = BLACK;
							atackCollision[i].rX = 64.0f;
							atackCollision[i].rY = 64.0f;
							atackCollision[i].pos.X = -1000.0f;
						}
						momentAtackTime = 0;
						hitInvincible = 0;
						devil[1].color = RED;
						atackTime = 0;
						atackCoolTime = 0;
						isBossAtack = 0;
						atackStop = 0;
						beamRadian = 0.0f;
						devil[0].pos.X = kwindowsRight;
						devil[0].pos.Y = 200.0f;
						devil[1].pos.X = devil[0].pos.X;
						devil[1].pos.Y = devil[0].pos.Y + 76;
						popUp[1].pos.X = -1000;
						popUp[2].pos.X = -1000;
						scene = STAGE;
					}
				}
			}
			mouseDisX = a.pos.X - mouseClick.X;
			mouseDisY = a.pos.Y - mouseClick.Y;
			//振動
			if (boss.hp > 0) {
				if (a.isSpace == 1 && a.back == 0 && a.reflect != a.maxReflect) {
					a.frame += 1;
					if (a.stop == 0) {
						a.t += a.tIncrement;
						a.easeT = a.t * a.t;
					}
					if (a.easeT > 1.2f && a.reflect < a.maxReflect && a.reflect % 2 == 0) {
						a.tIncrement *= -1;
						a.reflect += 1;

					}
					else if (a.easeT < 0.8f && a.reflect % 2 == 1 && a.reflect < a.maxReflect) {
						a.tIncrement *= -1;
						a.reflect += 1;
					}
					if (a.reflect == a.maxReflect) {
						a.vibration = 0;
						a.isSpace = 0;
						a.back = 1;
					}
					a.vibration = (1.0f - a.easeT) * 0 + a.easeT * 16;
				}
				else {
					if (a.easeT > 0.0f) {
						a.easeT -= 0.1f;
					}
					else {
						a.easeT = 0.0f;
					}
					a.tIncrement = 0.2f;
					a.reflect = 0;
					a.easeT = 0.0f;
					a.t = 0.0f;
					a.frame = 0;
					a.stop = 0;
					a.vibration = 0.0f;
				}
			}
			else {
				if (a.isSpace == 1 && a.back == 0 && a.reflect != a.maxReflect) {
					a.frame += 1;
					if (a.stop == 0) {
						a.t += a.tIncrement;
						a.easeT = a.t * a.t;
					}
					if (a.easeT > 1.2f && a.reflect < a.maxReflect && a.reflect % 2 == 0) {
						a.tIncrement *= -1;
						a.reflect += 1;

					}
					else if (a.easeT < 0.8f && a.reflect % 2 == 1 && a.reflect < a.maxReflect) {
						a.tIncrement *= -1;
						a.reflect += 1;
					}
					if (a.reflect == a.maxReflect) {
						a.vibration = 0;
						a.isSpace = 0;
						a.back = 1;
					}
					a.vibration = (1.0f - a.easeT) * 0 + a.easeT * 64;
				}
				else {
					if (a.easeT > 0.0f) {
						a.easeT -= 0.1f;
					}
					else {
						a.easeT = 0.0f;
					}
					a.tIncrement = 0.2f;
					a.reflect = 0;
					a.easeT = 0.0f;
					a.t = 0.0f;
					a.frame = 0;
					a.stop = 0;
					a.vibration = 0.0f;
				}

			}
			
			//背景の描画
			Novice::DrawSprite(bg[0][0].X - sX - a.vibration, bg[0][0].Y, devilBgHandle, 1, 1, 0.0f, WHITE);
			//地面の描画
			Novice::DrawBox(ground.pos.WorldX - sX - a.vibration, ground.pos.WorldY, ground.width.WorldX, ground.width.WorldY, 0.0f, 0x2f4f4fff, kFillModeSolid);
			Novice::DrawSprite(ground.pos.WorldX - sX - a.vibration, ground.pos.WorldY, devilGroundHandle, 1, 1, 0.0f, WHITE);
			//魔王の描画
			if (devilBodyAnimationTime < 15) {
				Novice::DrawSprite(devil[0].pos.X - devil[0].rX - sX - a.vibration, devil[0].pos.Y - devil[0].rY, devilBody1Handle, 1, 1, 0.0f, eyeColor);
			}
			else if (devilBodyAnimationTime < 30) {
				Novice::DrawSprite(devil[0].pos.X - devil[0].rX - sX - a.vibration, devil[0].pos.Y - devil[0].rY, devilBody2Handle, 1, 1, 0.0f, eyeColor);
			}
			else if (devilBodyAnimationTime < 45) {
				Novice::DrawSprite(devil[0].pos.X - devil[0].rX - sX - a.vibration, devil[0].pos.Y - devil[0].rY, devilBody3Handle, 1, 1, 0.0f, eyeColor);
			}
			else {
				Novice::DrawSprite(devil[0].pos.X - devil[0].rX - sX - a.vibration, devil[0].pos.Y - devil[0].rY, devilBody4Handle, 1, 1, 0.0f, eyeColor);
			}


			if (isBossAtack && effect == 0 ||
				atackStop > 0 && effect == 0) {
				if (AtackType == 0) {
					if (devilBodyAnimationTime >= 0 && devilBodyAnimationTime < 10 && isBossAtack ||
						devilBodyAnimationTime >= 20 && devilBodyAnimationTime < 30 && isBossAtack ||
						devilBodyAnimationTime >= 40 && devilBodyAnimationTime < 50 && isBossAtack) {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye1Handle, 1, 1, 0.0f, eyeColor);
					}
					else if (devilBodyAnimationTime <= 60 && isBossAtack) {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye4Handle, 1, 1, 0.0f, eyeColor);
					}
					else {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye1Handle, 1, 1, 0.0f, eyeColor);
					}

				}
				else if (AtackType == 1) {
					if (devilBodyAnimationTime >= 0 && devilBodyAnimationTime < 10 && isBossAtack ||
						devilBodyAnimationTime >= 20 && devilBodyAnimationTime < 30 && isBossAtack ||
						devilBodyAnimationTime >= 40 && devilBodyAnimationTime < 50 && isBossAtack) {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye2Handle, 1, 1, 0.0f, eyeColor);
					}
					else if (devilBodyAnimationTime <= 60 && isBossAtack) {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye5Handle, 1, 1, 0.0f, eyeColor);
					}
					else {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye2Handle, 1, 1, 0.0f, eyeColor);
					}
				}
				else if (AtackType == 2) {
					if (devilBodyAnimationTime >= 0 && devilBodyAnimationTime < 10 && isBossAtack ||
						devilBodyAnimationTime >= 20 && devilBodyAnimationTime < 30 && isBossAtack ||
						devilBodyAnimationTime >= 40 && devilBodyAnimationTime < 50 && isBossAtack) {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye3Handle, 1, 1, 0.0f, eyeColor);
					}
					else if (devilBodyAnimationTime <= 60 && isBossAtack) {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye6Handle, 1, 1, 0.0f, eyeColor);
					}
					else {
						Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEye3Handle, 1, 1, 0.0f, eyeColor);
					}
				}

			}
			else if (effect == 0) {
				Novice::DrawSprite(devil[1].pos.X - devil[1].rX - sX - a.vibration, devil[1].pos.Y - devil[1].rY, devilEyeCloseHandle, 1, 1, 0.0f, eyeColor);
			}
			//魔王の攻撃描画
			for (int i = 0; i < maxDevilAtacks; i++) {
				if (isBossAtack && AtackType == 1 ||
					isBossAtack && AtackType == 2) {
					//マーキング
					if (AtackType == 2 && atackCollision[i].color == BLACK) {
						Novice::DrawSprite(atackCollision[i].pos.X - atackCollision[i].rX - sX - a.vibration, atackCollision[i].pos.Y - atackCollision[i].rY, devilMark1Handle, 1, 1, 0.0f, WHITE);
					}
					else if (AtackType == 2 && devilMarkAnimationTime < 30) {
						Novice::DrawSprite(atackCollision[i].pos.X - atackCollision[i].rX - sX - a.vibration, atackCollision[i].pos.Y - atackCollision[i].rY, devilMark2Handle, 1, 1, 0.0f, WHITE);
					}
					else if (AtackType == 2 && devilMarkAnimationTime <= 60) {
						Novice::DrawSprite(atackCollision[i].pos.X - atackCollision[i].rX - sX - a.vibration, atackCollision[i].pos.Y - atackCollision[i].rY, devilMark3Handle, 1, 1, 0.0f, WHITE);
					}
					//追尾弾
					else if (AtackType == 1 && devilMarkAnimationTime >= 0 && devilMarkAnimationTime < 10 ||
						AtackType == 1 && devilMarkAnimationTime >= 20 && devilMarkAnimationTime < 30 ||
						AtackType == 1 && devilMarkAnimationTime >= 40 && devilMarkAnimationTime < 50) {
						Novice::DrawSprite(atackCollision[i].pos.X - atackCollision[i].rX - sX - a.vibration, atackCollision[i].pos.Y - atackCollision[i].rY, devilBullet1Handle, 1, 1, 0.0f, WHITE);
					}
					else if (AtackType == 1 && devilMarkAnimationTime <= 60) {
						Novice::DrawSprite(atackCollision[i].pos.X - atackCollision[i].rX - sX - a.vibration, atackCollision[i].pos.Y - atackCollision[i].rY, devilBullet2Handle, 1, 1, 0.0f, WHITE);
					}
				}
			}
			for (int i = 0; i < maxBeams; i++) {
				if (isBossAtack == 1) {
					if (AtackType == 0 && devilMarkAnimationTime >= 0 && devilMarkAnimationTime < 10 ||
						AtackType == 0 && devilMarkAnimationTime >= 20 && devilMarkAnimationTime < 30 ||
						AtackType == 0 && devilMarkAnimationTime >= 40 && devilMarkAnimationTime < 50) {
						Novice::DrawSprite(beam[i].pos.X - beam[i].rX - sX - a.vibration, beam[i].pos.Y - beam[i].rY, devilBeam1Handle, 1, 1, 0.0f, WHITE);
					}
					else if (AtackType == 0 && devilMarkAnimationTime <= 60) {
						Novice::DrawSprite(beam[i].pos.X - beam[i].rX - sX - a.vibration, beam[i].pos.Y - beam[i].rY, devilBeam1Handle, 1, 1, 0.0f, WHITE);
					}
				}
			}
			//プレイヤー残機
			Novice::DrawSprite(0 + a.rX, 0 + a.rY, slime1Handle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(a.rX + a.rX + a.rX + 10, 0 + a.rY + 16, xHandle, 1, 1, 0.0f, WHITE);
			//プレイヤーの描画
			if (Novice::IsPressMouse(0) == 0 && slimeShot == 0) {
				if (animeDir == LEFT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime1Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime3Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime2Handle, 1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slime4Handle, 1, 1, 0.0f, a.color);
					}
				}
				else if (animeDir == RIGHT) {
					if (slimeAnimationTime < 30 && slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime1Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType != 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime3Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationTime < 30 && slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime2Handle, -1, 1, 0.0f, a.color);
					}
					else if (slimeAnimationType == 4) {
						Novice::DrawSprite(a.pos.X - a.rX + a.rX * 2 - a.vibration, a.pos.Y - a.rY, slime4Handle, -1, 1, 0.0f, a.color);
					}

				}
				else if (animeDir == CLIMB) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeBackHandle, 1, 1, 0.0f, a.color);
				}
			}
			else if (Novice::IsPressMouse(0) == 1 && slimeShot == 0) {
				if (mouseDragX > mouseDragY) {
					if (mouse.X - mouseClick.X > 0) {
						if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide2Handle, 1, 1, 0.0f, a.color);
						}
					}
					else {
						if (slimeAnimationTime > 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X + a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide1Handle, -1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X + a.rX - a.vibration, a.pos.Y - a.rY, slimeDirSide2Handle, -1, 1, 0.0f, a.color);
						}
					}

				}
				else if (mouseDragX <= mouseDragY) {
					if (mouse.Y - mouseClick.Y > 0) {
						if (slimeAnimationTime >= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirUp1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirUp2Handle, 1, 1, 0.0f, a.color);
						}
					}
					else {
						if (slimeAnimationTime <= 0 && slimeAnimationTime < 10 ||
							slimeAnimationTime >= 20 && slimeAnimationTime < 30 ||
							slimeAnimationTime >= 40 && slimeAnimationTime < 50) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirDown1Handle, 1, 1, 0.0f, a.color);
						}
						else if (slimeAnimationTime <= 60) {
							Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeDirDown2Handle, 1, 1, 0.0f, a.color);
						}
					}

				}
			}
			else if (slimeShot == 1) {
				if (slimeAnimationTime >= 0 && slimeAnimationTime < 5 ||
					slimeAnimationTime >= 30 && slimeAnimationTime < 35) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot1Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 5 && slimeAnimationTime < 10 ||
					slimeAnimationTime >= 35 && slimeAnimationTime < 40) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot2Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 10 && slimeAnimationTime < 15 ||
					slimeAnimationTime >= 40 && slimeAnimationTime < 45) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot3Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 15 && slimeAnimationTime < 20 ||
					slimeAnimationTime >= 45 && slimeAnimationTime < 50) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot4Handle, 1, 1, 0.0f, a.color);
				}
				else if (slimeAnimationTime >= 20 && slimeAnimationTime < 25 ||
					slimeAnimationTime >= 50 && slimeAnimationTime < 55) {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot5Handle, 1, 1, 0.0f, a.color);
				}
				else {
					Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeShot6Handle, 1, 1, 0.0f, a.color);
				}

			}
			else if (animeDir == CLIMB) {
				Novice::DrawSprite(a.pos.X - a.rX - a.vibration, a.pos.Y - a.rY, slimeBackHandle, 1, 1, 0.0f, a.color);
			}
			//爆発
			if (explodeFlag == 1) {
				for (int i = 0; i < maxExplodes; i++) {
					Novice::DrawEllipse(explode[i].pos.X - sX - a.vibration, explode[i].pos.Y, explode[i].rX, explode[i].rY, 0.0f, explode[i].color, kFillModeWireFrame);
				}
			}
			//引っ張りエフェクト
			if (Novice::IsPressMouse(0) && a.alive) {
				Novice::DrawEllipse(mouseClick.X, mouseClick.Y, 10, 10, 0.0f, WHITE, kFillModeSolid);
				Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), WHITE);
				if (a.shotVelocity.Y >= 40) {
					Novice::DrawLine(mouseClick.X + mouseDisX - (mouse.X - mouseClick.X), mouseClick.Y + mouseDisY - (mouse.Y - mouseClick.Y), mouse.X + mouseDisX - (mouse.X - mouseClick.X), mouse.Y + mouseDisY - (mouse.Y - mouseClick.Y), RED);
				}
			}
			Novice::SetMouseCursorVisibility(0);
			if (Novice::IsPressMouse(0) == 0) {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse2Handle, 1, 1, 0.0f, WHITE);
			}

			break;
		case GAMEOVER:
			if (startSceneChange == 0) {
				gameOverAnimationTime += 1;
				if (gameOverAnimationTime == 30) {
					gameOverAnimationTime = 0;
				}
			}
			Novice::GetMousePosition(&mouse.X, &mouse.Y);
			if (mouse.X < gameStart.pos.X + gameStart.width.X &&
				mouse.X > gameStart.pos.X &&
				mouse.Y < gameStart.pos.Y + gameStart.width.Y &&
				mouse.Y > gameStart.pos.Y ||
				startSceneChange == 1) {
				gameStart.color = RED;
				upIn = 1;
				if (Novice::IsTriggerMouse(0) && startSceneChange == 0) {
					startSceneChange = 1;
				}
			}
			else {
				upIn = 0;
				gameStart.color = WHITE;
			}
			if (mouse.X < gameLule.pos.X + gameLule.width.X &&
				mouse.X > gameLule.pos.X &&
				mouse.Y < gameLule.pos.Y + gameLule.width.Y &&
				mouse.Y > gameLule.pos.Y && startSceneChange == 0) {
				gameLule.color = BLUE;
				downIn = 1;
				if (Novice::IsTriggerMouse(0)) {
					a.color = WHITE;
					scene = TITLE;
				}
			}
			else {
				downIn = 0;
				gameLule.color = WHITE;
			}
			//ゲームオーバー
			if (startSceneChange == 0) {
				if (gameOverAnimationTime < 10) {
					Novice::DrawSprite(0, 0, gameOver1Handle, 1, 1, 0.0f, WHITE);
				}
				else if (gameOverAnimationTime < 20) {
					Novice::DrawSprite(0, 0, gameOver2Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(0, 0, gameOver3Handle, 1, 1, 0.0f, WHITE);
				}
			}
			else {
				if (gameStartAnimationTime < 20) {
					Novice::DrawSprite(0, 0, gameOver4Handle, 1, 1, 0.0f, WHITE);
				}
				else if (gameStartAnimationTime < 40) {
					Novice::DrawSprite(0, 0, gameOver5Handle, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawSprite(0, 0, gameOver6Handle, 1, 1, 0.0f, WHITE);
				}
			}
			if (startSceneChange == 1 && gameStartAnimationTime < 60) {
				gameStartAnimationTime += 1;
			}
			else if (startSceneChange == 1) {
				//初期値に戻す
				gameStartAnimationTime = 0;
				skyBgAnimationTime = 0;
				//時間
				timer = 0;
				counter = 0;
				//穴.地面の初期化
				isHole = 0;
				for (int i = 0; i < 2; i++) {
					waterfall[i].pos.Y = -1440.0f - i * 720 * 3;

				}
				//マウス位置.マウス関連の初期化
				mouseDragX = 0.0f;
				mouseDragY = 0.0f;
				mouseDragDis = 0.0f;
				radian = 0.0f;
				mouseDisX = 0.0f;
				mouseDisY = 0.0f;
				mouseDis = 0.0f;
				//プレイヤーの初期化
				a.tIncrement = 0.2f;
				a.reflect = 0;
				a.easeT = 0.0f;
				a.t = 0.0f;
				a.frame = 0;
				a.stop = 0;
				a.vibration = 0.0f;
				a.maxReflect = 4;
				scoreNumber = 0;
				score = 0;
				slimeHp = 10;
				momentSlimeHp = slimeHp;
				a.pos.X = sPosX + 700.0f;
				a.pos.WorldX = (bg[0][maxMapX - 1].X + 1300);
				a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY - 100.0f;
				a.pos.WorldY = a.pos.Y;
				a.color = WHITE;
				a.alive = 1.0f;
				animeDir = 0;
				isGround = 0;
				isShot = 0;
				slimeShot = 0;
				slimeAnimationTime = 0;
				slimeAnimationType = 0;
				//敵の初期化
				for (int i = 0; i < maxEnemys; i++) {
					isHitEnemy[i] = 0;
					treadEnemy[i] = 0;
					enemyIsHole[i] = 0;
					enemyIsHitTerrain[i] = 0;
					enemyAnimationTime[i] = 0;
					enemyAnimationType[i] = 1;
					enemy[i].rX = 60.0f;
					enemy[i].rY = 60.0f;
					enemy[i].pos.X = 600.0f + i * 400;
					enemy[i].pos.Y = ground.pos.WorldY - enemy[i].rY - i * 50;
					enemy[i].color = 0x6c2735ff;
					enemy[i].alive = 1;
					enemy[i].velocity.X = 3.0f;
				}
				hitEnemy = 0.0f;
				for (int i = 0; i < maxFlyEnemys; i++) {
					flyEnemy[i].pos.Y = 0 - i * 200.0f;
					flyEnemy[i].pos.X = 3000.0f - i * 10;
					flyEnemy[i].color = RED;
					flyEnemyRadian[i] = 0;
				}
				//ボスの初期化
				skeletonAnimationType = 0;
				skeletonAnimationTime = 0;
				sickleAnimationTime = 0;
				bossTime = 0.0f;
				atackCoolTime = 0.0f;
				atackTime = 0.0f;
				currentTime = time(nullptr);
				srand(currentTime);
				AtackType = rand() % 5;
				isBossAtack = 0;
				initialize = 0;
				defeatMotion = 0;
				boss.pos.X = boss.pos.startX;
				boss.pos.Y = boss.pos.startY;
				boss.color = WHITE;
				boss.hp = 5;
				boss.alive = 1;
				isHitBoss = 0.0f;
				bossHitStop = 0.0f;
				treadBoss = 0;
				for (int i = 0; i < maxCollision; i++) {
					bossAtackCollision[i].velocity.X = 13;
					bossAtackCollision[i].velocity.Y = 13;
					bossDisX[i] = 0;
					bossDisY[i] = 0;
					bossDis[i] = 0;
				}
				//魔王の初期化
				devilBodyAnimationTime = 0;
				effect = 1;
				devilEffectTime = 0;
				devilStartAnimationTime = 0;
				devilMarkAnimationTime = 0;
				devilStartFlag = 0;
				eyeColor = WHITE;
				hitInvincible = 0;
				devil[1].alive = 1;
				devil[1].hp = 6.0f;
				devil[0].pos.X = kwindowsRight;
				devil[0].pos.Y = 200.0f;
				devil[1].pos.X = kwindowsRight - 64.0f;
				devil[1].pos.Y = devil[0].pos.Y;
				devil[0].color = WHITE;
				devil[1].color = RED;
				for (int i = 0; i < 2; i++) {
					devil[i].velocity.X = 3;
					devil[i].velocity.Y = 0;
				}
				for (int i = 0; i < maxDevilAtacks; i++) {
					atackCollision[i].color = BLACK;
					atackCollision[i].velocity.X = 15.0f;
					atackCollision[i].velocity.Y = 15.0f;
					devilBullets[i] = 0;
					mark[i] = 0;
					momentTime[i] = 0;
					atackRadian[i] = 0.0f;
				}
				momentAtackTime = 0;
				move = 0;
				moveDir = 0;
				beamRadian = 0.0f;
				//撃破用
				for (int i = 0; i < maxExplodes; i++) {
					explode[i].rX = 10.0f;
					explode[i].rY = 10.0f;
					explode[i].color = 0xba2636ff;
				}
				explodeTime = 0;
				explodeFlag = 0;
				explodePos = 0;
				//障害物の初期化
				terrainA.rY = 0.0f;
				terrainA.pos.X = 700.0f;
				terrainA.pos.Y = bgY[1].pos.Y - terrainA.rY;
				terrainA.rX = 400.0f;
				terrainA.rY = 10.0f;
				terrainA.velocity.X = 5.0f;
				icicleDown = 0;
				icicleTime = 0;
				for (int i = 0; i < 2; i++) {
					icicle[i].pos.X = 900.0f;
					icicle[i].pos.Y = freeBlock[9].pos.Y + freeBlock[9].width.Y;
					icicle[i].color = BLUE;
				}
				warpSize = 1.0f;
				warpFlag = 0;
				warpAnimationTime = 0;
				startWarp.color = BLUE;
				exitAnimationTime = 0;
				getAmulet = 0;
				amuletAnimationTime = 0;
				amulet.pos.X = block[8][0].pos.X + 80.0f;
				amulet.pos.Y = block[8][0].pos.Y - amulet.rY;
				//ダンジョンのゴースト初期化
				ghostAnimationType = LEFT;
				ghostAnimationTime = 0;
				ghostAtackFlag = 0;
				ghostFireAnimationTime = 0;
				ghostSize = 1.0f;
				for (int i = 0; i < maxGhosts; i++) {
					ghostRadian[i] = 0.0f;
					ghostRadianX[i] = 0.0f;
					ghostRadianY[i] = 0.0f;
					ghost[i].pos.X = 1000.0f;
					ghost[i].pos.Y = 650.0f - i * 300;
					ghost[i].rX = 70.0f;
					ghost[i].rY = 70.0f;
					ghost[i].velocity.X = 3.0f;
					ghost[i].velocity.Y = 3.0f;
					ghost[i].color = BLACK;
				}
				for (int i = 0; i < maxGhosts; i++) {
					appear[i].color = BLACK;
					appear[i].pos.X = 100 + i * 100;
					appear[i].pos.Y = block[12][0].pos.Y - appear[i].rY - i * 350;
				}
				clearGhost = 0;
				eatTime = 0;
				atackStop = 0;
				//蔓の初期化
				ivyAnimationTime = 0;
				isClimb = 0;
				//ファイアバーの初期化
				isHitBar = 0.0f;
				disX = 0;
				disY = 0;
				dis = 0;
				for (int i = 0; i < maxBar; i++) {
					barRadian[i] = i * 3;
				}
				//ボス部屋の初期化
				skeletonDoorAnimationTime = 0;
				skeletonEndAnimationTime = 0;
				skeletonEndFlag = 0;
				ghostEndFlag = 0;
				ghostDoorAnimatioTime = 0;
				ghostEndAnimationTime = 0;
				devilDoorAnimationTime = 0;

				for (int i = 0; i < maxBoss; i++) {
					doorType[i] = 0;
				}
				popUpColor[0] = WHITE;
				popUpColor[1] = BLACK;
				popUpColor[2] = BLACK;
				for (int i = 0; i < 3; i++) {
					popUp[i].pos.X = kwindowsLeft + kwindowsRight / 2;
					popUp[i].pos.Y = kwindowsUp + kwindowsDown / 2;
				}
				sceneChange = 0;
				clearSkeleton = 0;
				//
				a.pos.Y = kwindowsDown - a.rY - ground.width.WorldY - terrain[24].rY - 10;
				a.pos.WorldY = kwindowsDown - a.rY - ground.width.WorldY - terrain[24].rY - 10;
				gameStartAnimationTime = 0;
				scene = STAGE;
			}
			//セレクト
			Novice::DrawBox(gameStart.pos.X, gameStart.pos.Y, gameStart.width.X, gameStart.width.Y, 0.0f, gameStart.color, kFillModeSolid);
			if (upIn == 0) {
				Novice::DrawSprite(gameStart.pos.X - 8, gameStart.pos.Y - 8, gameOverRetry1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(gameStart.pos.X - 8, gameStart.pos.Y - 8, gameOverRetry2Handle, 1, 1, 0.0f, WHITE);
			}
			Novice::DrawBox(gameLule.pos.X, gameLule.pos.Y, gameLule.width.X, gameLule.width.Y, 0.0f, gameLule.color, kFillModeSolid);
			if (downIn == 0) {
				Novice::DrawSprite(gameLule.pos.X - 8, gameLule.pos.Y - 8, gameOverGiveUp1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(gameLule.pos.X - 8, gameLule.pos.Y - 8, gameOverGiveUp2Handle, 1, 1, 0.0f, WHITE);
			}
			//マウス
			Novice::SetMouseCursorVisibility(0);
			if (Novice::IsPressMouse(0) == 0) {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse2Handle, 1, 1, 0.0f, WHITE);
			}
			break;
		case GAMECLEAR:
			Novice::GetMousePosition(&mouse.X, &mouse.Y);
			slimeAnimationTime += 1;
			if (slimeAnimationTime == 80) {
				slimeAnimationTime = 0;
				currentTime = time(nullptr);
				srand(currentTime);
				slimeAnimationType = rand() % 5;
			}
			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
				scene = TITLE;
				upIn = 0;
			}
			if (mouse.X < gameStart.pos.X + gameStart.width.X &&
				mouse.X > gameStart.pos.X &&
				mouse.Y < gameStart.pos.Y + gameStart.width.Y &&
				mouse.Y > gameStart.pos.Y) {
				gameStart.color = RED;
				upIn = 1;
				if (Novice::IsTriggerMouse(0)) {
					scene = TITLE;
					upIn = 0;
				}
			}
			else {
				gameStart.color = WHITE;
				upIn = 0;
			}
			//スコア
			if (scoreNumber == 0) {
				scoreNumber = 1;
				score *= slimeHp + 1;
				score -= timer;
				momentTimer = score;
				if (momentTimer < 10000 && momentTimer >= 0) {
					if (momentTimer >= 1000) {
						eachScore[0] = momentTimer / 1000;
						momentTimer = momentTimer % 1000;
					}
					else {
						eachScore[0] = 0;
					}
					if (momentTimer >= 100) {
						eachScore[1] = momentTimer / 100;
						momentTimer = momentTimer % 100;
					}
					else {
						eachScore[1] = 0;
					}
					if (momentTimer >= 10) {
						eachScore[2] = momentTimer / 10;
						momentTimer = momentTimer % 10;
					}
					else {
						eachScore[2] = 0;
					}
					if (momentTimer >= 0) {
						eachScore[3] = momentTimer;
					}
					else {
						eachScore[3] = 0;
					}
				}
				else if (momentTimer >= 10000) {
					eachScore[0] = 9;
					eachScore[1] = 9;
					eachScore[2] = 9;
					eachScore[3] = 9;
				}
				else if (momentTimer < 0) {
					eachScore[0] = 0;
					eachScore[1] = 0;
					eachScore[2] = 0;
					eachScore[3] = 0;
				}
			}

			//ゲームクリア
			if (slimeAnimationTime < 20) {
				Novice::DrawSprite(0, 0, gameClear1Handle, 1, 1, 0.0f, WHITE);
			}
			else if (slimeAnimationTime < 40) {
				Novice::DrawSprite(0, 0, gameClear2Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(0, 0, gameClear3Handle, 1, 1, 0.0f, WHITE);
			}
			if (upIn == 0) {
				Novice::DrawSprite(gameStart.pos.X - 8, gameStart.pos.Y - 8, gameClearTitle1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(gameStart.pos.X - 8, gameStart.pos.Y - 8, gameClearTitle2Handle, 1, 1, 0.0f, WHITE);
			}
			//スコア
			for (int i = 0; i < 4; i++) {
				Novice::DrawSprite(gameStart.pos.X - 8 + 200.0f + i * 65, gameStart.pos.Y - 8 + gameStart.width.Y + 16, numH[eachScore[i]], 1, 1, 0.0f, 0xffffffff);
			}
			//マウス
			Novice::SetMouseCursorVisibility(0);
			if (Novice::IsPressMouse(0) == 0) {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse1Handle, 1, 1, 0.0f, WHITE);
			}
			else {
				Novice::DrawSprite(mouse.X, mouse.Y, mouse2Handle, 1, 1, 0.0f, WHITE);
			}
			break;
		}
		if (scene != TITLE && scene != LULE && scene != GAMEOVER && scene != GAMECLEAR) {
			for (int i = 0; i < maxDigit; i++) {
				Novice::DrawSprite(120 + i * 65, a.rY - 32, numH[eachNumber[i]], 1, 1, 0.0f, 0xffffffff);
			}
		}
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

