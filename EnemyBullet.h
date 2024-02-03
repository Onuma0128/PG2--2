#pragma once
#include <Novice.h>
#include "struct.h"

class EnemyBullet
{
public:
	void SetEnemyPosition(float posX, float posY);

	//敵の弾の初期化
	void Initalize();
	//敵の弾の更新処理
	void Update();
	//敵の弾の描画処理
	void Draw();

	Character enemyBullet_;
	int enemyBulletGH_;
};

