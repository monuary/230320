#include<iostream>
#include<cstring>
using namespace std;

class Gun
{
	int bullet=0;
public:
	Gun(){}
	Gun(int bnum):bullet(bnum){}
	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police:public Gun
{
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) :handcuffs(bcuff)
	{
		if (bnum > 0)pistol = new Gun(bnum);	//Gun*pistol;�� Gun*pistol();�� ���� ������, Gun(){}�� �ʿ��ϴ�.
		else pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)cout << "Hut BBANG!" << endl;
		else pistol->Shot();
	}
	~Police() { if (pistol != NULL)delete pistol; }	//�����ʹ� ��� �� ���־� �Ѵ�.
};

int main()
{
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3);
	pman2.Shot();
	pman2.PutHandcuff();
	return 0;
}

//IS-A ������ ǥ���� ����� �����ϴ�. ��, HAS-A ������ ǥ���� ����� ���� ���α׷� ���濡 ������ ������ �ش�.
//cpp�� ���߻�ӵ� ����������, ���α׷��� �����ϰ� �Ѵ�.