#pragma once
#include "Player.h"
#include "Enemy.h"
#include "PlayerBullet.h"

class Game
{
public:
	//ゲームのシーン
	enum GameScene {
		Title,
		MainGame,
		GameClear,
		GameOver
	};
	GameScene scene;
	
	//プレイヤーの包含
	Player* player_;
	//敵の包含
	Enemy* enemy_;

	int SceneGH_[3];


	//ゲームの初期化
	void Initalize();
	//ゲームの更新処理
	void Update(char* keys, char* preKeys);
	//ゲームの描画処理
	void Draw();

	//プレイヤーと敵の当たり判定
	void playerEnemyCollision();
	//プレイヤーの弾と敵の当たり判定
	void playerBulletEnemyCollision();
	//敵の弾とプレイヤーの当たり判定
	void enemyBulletPlayerCollision();
	//プレイヤーの弾と敵の弾の当たり判定
	void playerBulletEnemyBulletCollision();
};

