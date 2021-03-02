﻿#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 은닉성

// 객체 지향 (OOP Object Oriented Programming)

// - 상속성
// - 은닉성
// - 다형성

// 은닉성 (Data Hiding) = 캡슐화 (Encapsulation)
// 몰라도 되는건 깔끔하게 숨기겠다!
// 숨기는 이유?
// 1) 정말 위험하고 건드리면 안되는 경우
// 2) 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 패달
// - 엔진
// - 문
// - 각종 전기선

// 일반 구매자 입장에서 사용하는 것?
// - 핸들 / 페달 / 문
// 몰라도 됨 (오히려 건드리면 큰일남)
// - 엔진, 각종 전기선

// public
// protected
// private

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음
// - public : 공개적 상속? -> 부모님의 유산 설계 그대로. (public -> public, protected -> protected)
// - protected : 보호받은 상속? -> 내 자손들한테만 물려줄꺼야. (public -> protected, protected -> protected);
// - private : 개인주의 상속? -> 나까지만 잘 쓰고 자손들한테는 아예 안줄꺼임. (public -> private, protected -> private)

class Car {
public: // (멤버 지정자) 접근 지정자

	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey() {
		RunEngine();
	}

protected:
	void DisassembleCar() {} // 차를 분해한다
	void RunEngine() {} // 엔진을 구동시킨다
	void ConnectCircuit() {} // 전기선 연결


public:
};

class SuperCar : private Car // 상속 접근 지정자
{
public:
	void PushRemoteController() {
		RunEngine();
	}
};

class TestSuperCar : SuperCar
{
public:
	void Test() {
	}

private:

};

// '캡슐화'
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker {
public:

	int GetHp() { return _hp; }
	// 사양 : 체력 50 이하 버서커 모드
	void SetHp(int hp) {
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}


private:
	void SetBerserkerMode() {
		cout << "매우 강해짐!" << endl;
	}
private:
	int _hp = 100;
};

int main() 
{	
	Berserker b;
	b.SetHp(20);

	
	

	// 공개된 곳에서 이걸?
	//car.DisassembleCar();

	return 0;
}