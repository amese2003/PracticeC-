#pragma once


// ���漱��
class Player;
class Field;

// is - a
// has - a
class Game {
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();
	
private:


	// [4-8] -------->> []
	Player* _player;
	Field* _field;
};