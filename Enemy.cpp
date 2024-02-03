#include "Enemy.h"

void Enemy::SetEnemyPosition(float posX, float posY)
{
	enemy_.Position.x = posX;
	enemy_.Position.y = posY;
}

void Enemy::SetEnemyIsAlive(bool isAlive)
{
	enemy_.isAlive = isAlive;
}

void Enemy::SetEnemyHP(int enemyHP,int enemyTime)
{
	enemy_.HP -= enemyHP;
	enemyDamageTime_ -= enemyTime;
}

void Enemy::Initalize()
{
	enemy_.Position.x = 640;
	enemy_.Position.y = 50;
	enemy_.Velocity.x = 8;
	enemy_.Velocity.y = 8;
	enemy_.Width = 50;
	enemy_.Height = 50;
	enemy_.Color = WHITE;
	enemy_.HP = 2;
	enemy_.isAlive = true;
	enemyGH_ = Novice::LoadTexture("./Sprite/enemy.png");
	enemyDamageTime_ = 180;
	enemyAttackTime_ = 120;

	EnemyBullet::Initalize();
}

void Enemy::Update()
{
	if (enemy_.isAlive) {
		enemy_.Position.x += enemy_.Velocity.x;
		if (enemy_.Position.x < 200) {
			enemy_.Velocity.x *= -1;
		}
		if (enemy_.Position.x > 1030) {
			enemy_.Velocity.x *= -1;
		}
		if (enemyAttackTime_ > 0) {
			enemyAttackTime_--;
		}
		if (enemyAttackTime_ == 0) {
			enemyAttackTime_ = 120;
			enemyBullet_.isAlive = true;
			EnemyBullet::SetEnemyPosition(enemy_.Position.x + 15.0f, enemy_.Position.y + 30.0f);
		}
	}

	EnemyBullet::Update();

	if (enemyDamageTime_ < 180) {
		enemyDamageTime_--;
		if (enemyDamageTime_ < 0) {
			enemyDamageTime_ = 180;
			enemy_.isAlive = true;
		}
	}

}

void Enemy::Draw()
{
	if (enemyDamageTime_ == 180) {
		Novice::DrawSprite((int)enemy_.Position.x, (int)enemy_.Position.y, enemyGH_, 1, 1, 0.0f, enemy_.Color);
	}
	EnemyBullet::Draw();
}
