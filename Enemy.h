#pragma once
#include "EnemyBullet.h"

class Enemy : public EnemyBullet
{
public:
	//敵のゲッター
	Character GetEnemy() { return enemy_; }
	//敵のセッター
	void SetEnemyPosition(float posX, float posY);
	void SetEnemyIsAlive(bool isAlive);
	void SetEnemyHP(int enemyHP, int enemyTime);

	//敵の初期化
	void Initalize(); 
	//敵の更新処理
	void Update();
	//敵の描画処理
	void Draw();

private:
	//敵
	Character enemy_;
	int enemyGH_;
	//敵の無敵タイマー
	int enemyDamageTime_;
	//敵の攻撃タイマー
	int enemyAttackTime_;
};

