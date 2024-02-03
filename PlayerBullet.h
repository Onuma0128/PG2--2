#pragma once
#include <Novice.h>
#include "struct.h"

class PlayerBullet
{
public:

	//プレイヤーの弾の初期化
	void Initalize();
	//プレイヤーの弾の更新処理
	void Update();
	//プレイヤーの弾の描画処理
	void Draw();

	//プレイヤーの弾
	Character playerBullet_[kBulletNum];
	int playerBulletGH_;
};

