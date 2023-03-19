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
		if (bnum > 0)pistol = new Gun(bnum);	//Gun*pistol;은 Gun*pistol();과 같기 때문에, Gun(){}가 필요하다.
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
	~Police() { if (pistol != NULL)delete pistol; }	//포인터는 사용 후 없애야 한다.
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

//IS-A 관계의 표현에 상속은 유용하다. 단, HAS-A 관계의 표현에 상속을 쓰면 프로그램 변경에 제약을 가져다 준다.
//cpp는 다중상속도 지원하지만, 프로그램을 복잡하게 한다.