#pragma once

const int kBulletNum = 5;

struct Vector {
	int x;
	int y;
};

struct Vector2 {
	float x;
	float y;
};

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct Character {
	Vector2 Position;
	Vector2 Velocity;
	Vector2 Acceleration;
	float Width;
	float Height;
	unsigned int Color;
	int HP;
	Direction direction;
	bool isAlive;
};

