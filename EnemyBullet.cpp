#include "EnemyBullet.h"

void EnemyBullet::SetEnemyPosition(float posX, float posY)
{
	enemyBullet_.Position.x = posX;
	enemyBullet_.Position.y = posY;
}

void EnemyBullet::Initalize()
{
	enemyBullet_.Position.x = -100;
	enemyBullet_.Position.y = -100;
	enemyBullet_.Velocity.x = 5;
	enemyBullet_.Velocity.y = 5;
	enemyBullet_.Width = 20;
	enemyBullet_.Height = 20;
	enemyBullet_.Color = WHITE;
	enemyBullet_.isAlive = false;
	enemyBulletGH_ = Novice::LoadTexture("./Sprite/enemyBullet.png");
}

void EnemyBullet::Update()
{
	enemyBullet_.Position.y += enemyBullet_.Velocity.y;

	if (enemyBullet_.Position.y > 720) {
		enemyBullet_.isAlive = false;
	}
}

void EnemyBullet::Draw()
{
	if (enemyBullet_.isAlive) {
		Novice::DrawSprite((int)enemyBullet_.Position.x, (int)enemyBullet_.Position.y, enemyBulletGH_, 1, 1, 0.0f, enemyBullet_.Color);
	}
}
