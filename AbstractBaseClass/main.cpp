#include<iostream>
using namespace std;

class Vehicle	
{
	int speed;
public:
	virtual void move() = 0;	
};

class GroundVehicle :public Vehicle {};

class Car :public GroundVehicle
{
public:
	void move()override
	{
		cout << "Ìàøèíà åäèò íà ÷åòûðåõ êîëåñàõ, ñî ñêîðîñòüþ " << endl;
	}
};
class Bike :public GroundVehicle
{
public:
	void move()override
	{
		cout << "Ìîòîöèêë åäèò íà äâóõ êîëåñàõ" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehicle;
	//GroundVehicle gv;
	Car bmw;
	bmw.move();

	Bike harley_devidson;
	harley_devidson.move();
}