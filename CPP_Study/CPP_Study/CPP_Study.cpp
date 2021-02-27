﻿#include <iostream>

using namespace std;

// 오늘의 주제 : TextRPG2

// main
// - EnterLobby
// -- CreatePlayer
// -- EnterGame
// -- CreateMonster
// -- EnterBattle

enum PlayerType {
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

enum MonsterType {
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo {
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterLobby(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monster);


int main() 
{	
	srand((unsigned)time(nullptr));
	EnterLobby();


	return 0;
}

void EnterLobby() {

	while (true) 
	{
		PrintMessage("로비에 입장했습니다.");

		// Player
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);
		PrintStatInfo("PlayerInfo", playerInfo);
		EnterLobby(&playerInfo);
	}
}

void PrintMessage(const char* msg) {
	cout << "**********************" << endl;
	cout << msg << endl;
	cout << "**********************" << endl;
}

void PrintStatInfo(const char* name, const StatInfo& info) {
	cout << "**********************" << endl;
	cout << name << " HP=" << info.hp << " ATT=" << info.attack << " DEF=" << info.defence  << endl;
	cout << "**********************" << endl;
}

void CreatePlayer(StatInfo* Info) {
	
	bool ready = false;

	while (ready == false) {
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 법사");

		int input;
		cin >> input;

		switch (input)
		{
			case PT_Knight:
				(*Info).hp = 100;
				Info->attack = 10;
				Info->defence = 5;
				ready = true;
				break;
			case PT_Archer:
				(*Info).hp = 80;
				Info->attack = 15;
				Info->defence = 3;
				ready = true;
				break;
			case PT_Mage:
				(*Info).hp = 50;
				Info->attack = 25;
				Info->defence = 1;
				ready = true;
				break;
			default:
				break;
		}
	}
}


void EnterLobby(StatInfo* playerInfo) {
	PrintMessage("게임에 입장했습니다.");
	const int MONSTER_COUNT = 2;

	while (true) {
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);

		for (int i = 0; i < MONSTER_COUNT; i++) 
			PrintStatInfo("Monster", monsterInfo[i]);

		PrintStatInfo("Player", *playerInfo);	

		PrintMessage("[1] 전투 [2] 전투 [3] 도망");
		int input;
		cin >> input;

		if (input == 1 || input == 2) {
			int index = input - 1;
			bool victory = EnterBattle(playerInfo, &monsterInfo[index]);

			if (victory == false)
				break;
		}
	}
}

void CreateMonsters(StatInfo monsterInfo[], int count) {
	for (int i = 0; i < count; i++) {
		int randValue = 1 + rand() % 3;

		switch (randValue)
		{
			case MT_Slime:
				monsterInfo[i].hp = 30;
				monsterInfo[i].attack = 5;
				monsterInfo[i].defence = 1;
				break;
			case MT_Orc:
				monsterInfo[i].hp = 40;
				monsterInfo[i].attack = 8;
				monsterInfo[i].defence = 2;
				break;
			case MT_Skeleton:
				monsterInfo[i].hp = 50;
				monsterInfo[i].attack = 15;
				monsterInfo[i].defence = 3;
				break;
		}
	}
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo) {
	
	while (true) {
		int damage = playerInfo->attack - monsterInfo->defence;

		if (damage < 0)
			damage = 0;

		monsterInfo->hp -= damage;
		if (monsterInfo->hp < 0)
			monsterInfo->hp = 0;

		PrintStatInfo("Monster", *monsterInfo);

		if (monsterInfo->hp == 0) {
			PrintMessage("몬스터를 처치했습니다");
			return true;
		}

		damage = monsterInfo->attack - playerInfo->defence;

		if (damage < 0)
			damage = 0;

		playerInfo->hp -= damage;
		if (playerInfo->hp < 0)
			playerInfo->hp = 0;

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0) {
			PrintMessage("게임 오버!");
			return false;
		}
	}
}