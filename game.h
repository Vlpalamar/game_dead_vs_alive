#pragma once
#include<D:\visual studio\Spravochnick iz faila\list.h>



class Heroes
{
public:
	int hp;
	int dmg;
	int gold;
	string name;
	
	
	void set_name(string name)
	{
		this->name = name;
	}
	void set_hp( int hp)
	{
		this->hp = hp;
	}
	void set_dmg(int dmg)
	{
		this->dmg = dmg;
	}
	void set_gold(int gold)
	{
		this->gold = gold;
	}
	string getName()
	{
		return this->name;
	}
	int getHp()
	{
		return hp;
	}
	int getDmg()
	{
		return dmg;
	}
	int getGold()
	{
		return gold;
	}
	void print()
	{
		cout <<"NAME: "<<name<< " Hp:" << hp << " DMG:" << dmg << " GOLD:" << gold<<" ";
	}

};
class Archer : public virtual  Heroes
{
protected:

public:
	Archer()
	{
		set_name("Archer");
		set_hp(55);
		set_dmg(35);
		set_gold(100);
	}
	
};
class crossbowman : public virtual  Heroes
{

public:
	crossbowman()
	{
		set_name("Crossbowman");
		set_hp(70);
		set_dmg(25);
		set_gold(50);
	}
};
class swordsman : public virtual  Heroes
{

public:
	swordsman()
	{
		set_name("Swordsman");
		set_hp(100);
		set_dmg(30);
		set_gold(70);
	}
};


class Ork : public virtual  Heroes
{

public:
	Ork()
	{
		set_name("Ork");
		set_hp(85);
		set_dmg(30);
		set_gold(20);
	}
};

class Dragon : public virtual  Heroes
{

public:
	Dragon()
	{
		set_name("Dragon");
		set_hp(35);
		set_dmg(60);
		set_gold(150);
	}
};
class Skeleton : public virtual  Heroes
{

public:
	Skeleton()
	{
		set_name("Skeleton");
		set_hp(40);
		set_dmg(60);
		set_gold(30);
	}
};

class Game: virtual public  Heroes
{
protected:
	ForwardList<Heroes, 10> Team_Alive;
	ForwardList<Heroes, 10> Team_Undead;
	void print_Alive();
	void print_Undead();
	void fight();
public:

	void menu();

	~Game()
	{
		Team_Alive.clear();
		Team_Undead.clear();
	}
	Game()
	{
		
		for (size_t i = 0; i < 10; i++)
		{
			int ch = rand() % 3 + 1;
			if (ch==1)
			{
				Archer a;
				Team_Alive.push_back(a);
			}
			if (ch == 2)
			{
				crossbowman b;
				Team_Alive.push_back(b);
			}
			if (ch == 3)
			{
				swordsman c;
				Team_Alive.push_back(c);
			}		
		}
		for (size_t i = 0; i < 10; i++)
		{
			int ch = rand() % 3 + 1;
			if (ch == 1)
			{
				Ork a;
				Team_Undead.push_back(a);
			}
			if (ch == 2)
			{
				Dragon b;
				Team_Undead.push_back(b);
			}
			if (ch == 3)
			{
				Skeleton c;
				Team_Undead.push_back(c);
			}
		}
	}

};
void Game::fight()
{
	while (!Team_Alive.isEmpty() or !Team_Undead.isEmpty())
	{

		system("cls");
		int al = rand() % Team_Alive.getSize();
		cout << "Alive Hero:";
		Team_Alive[al].print();
		cout << "\n";
		int un = rand() % Team_Undead.getSize();
		cout << "Vs Undead Hero:";
		Team_Undead[un].print();
		bool turn=rand()%2;
		cout << endl;
		do
		{
			if (turn == 0)
			{
				cout << Team_Alive[al].getName() << " hit " << Team_Undead[un].getName() << " with " << Team_Alive[al].getDmg()<<"dmg ";
				Team_Undead[un].set_hp(Team_Undead[un].getHp() - Team_Alive[al].getDmg());
				cout << Team_Undead[un].getHp() << "hp left \n";
				Sleep(3000);
				if (Team_Undead[un].getHp() <= 0)
				{
					Team_Undead.pop_at(un);
					Team_Alive[al].set_gold(Team_Alive[al].getGold() + Team_Undead[un].getGold());
					break;
				}
				cout << Team_Undead[un].getName() << " hit" << Team_Alive[al].getName() << "with" << Team_Undead[un].getDmg() << "dmg ";
				Team_Alive[al].set_hp(Team_Alive[al].getHp() - Team_Undead[un].getDmg());
				cout << Team_Alive[al].getHp() << "hp left\n";
				Sleep(3000);
				if (Team_Alive[al].getHp()<=0)
				{
					Team_Alive.pop_at(al);
					Team_Undead[un].set_gold(Team_Undead[un].getGold() + Team_Alive[al].getGold());
					break;
				}
				
			}
			else
			{
				cout << Team_Undead[un].getName() << " hit" << Team_Alive[al].getName() << "with" << Team_Undead[un].getDmg() << "dmg ";
				Team_Alive[al].set_hp(Team_Alive[al].getHp() - Team_Undead[un].getDmg());
				cout << Team_Alive[al].getHp() << "hp left\n";
				Sleep(3000);
				if (Team_Alive[al].getHp() <= 0)
				{
					Team_Alive.pop_at(al);
					Team_Undead[un].set_gold(Team_Undead[un].getGold() + Team_Alive[al].getGold());
					break;
				}

				cout << Team_Alive[al].getName() << " hit " << Team_Undead[un].getName() <<  "with " << Team_Alive[al].getDmg() << "dmg ";
				Team_Undead[un].set_hp(Team_Undead[un].getHp() - Team_Alive[al].getDmg());
				cout << Team_Undead[un].getHp() << "hp left\n";
				Sleep(3000);
				
				if (Team_Undead[un].getHp() <= 0)
				{
					Team_Undead.pop_at(un);
					Team_Alive[al].set_gold(Team_Alive[al].getGold() + Team_Undead[un].getGold());
					break;
				}
				
			}
			

		} while (true);
	}
}




void Game::menu()
{
	int ch;
	cout << "1.Fight\n"
		<< "2.show Alive who left\n"
		<< "3.show Undead who left\n";
	cin >> ch;
	do
	{
		switch (ch)
		{
		case 1:
			fight();
			menu();
			break;
		case 2:
			print_Alive();
			menu();
			break;
		case 3:
			print_Undead();
			menu();
		default:
			break;
		}
	} while (true);
	
	
	
	
}

void Game::print_Alive()
{
	for (size_t i = 0; i < Team_Alive.getSize(); i++)
	{
		Team_Alive[i].print();
		cout << endl;
	}
}

void Game::print_Undead()
{
	for (size_t i = 0; i < Team_Undead.getSize(); i++)
	{
		Team_Undead[i].print();
		cout << endl;
	}

}

