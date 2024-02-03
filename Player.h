#pragma once
#include "PlayerBullet.h"

class Player : public PlayerBullet
{
public:
	//プレイヤーのゲッター
	Character GetPlayer() { return player_; };
	//プレイヤーのセッター
	void SetPlayerPosition(float posX, float posY);
	void SetPlayerIsAlive(bool isAlive);
	void SetPlayerHP(int playerHP,int playerTime);

	//プレイヤーの初期化
	void Initalize();
	//プレイヤーの更新処理
	void Update(char* keys,char* preKeys);
	//プレイヤーの描画処理
	void Draw();

private:
	//プレイヤー
	Character player_;
	int playerGH_;
	//プレイヤーの無敵タイマー
	int playerDamageTime_;

};

