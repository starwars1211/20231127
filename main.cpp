#include <iostream>
#include <vector>

using namespace std;

class AActor
{
public:
	virtual void Do() { cout << "Parent"; }
};

class ACharacter : public AActor
{
public:
	virtual void Do() override { cout << "Child1"; }
};
class AGameModeBasse : public AActor
{
public:
	virtual void Do() override { cout << "Child2"; }

	void PostLogin() { cout << "PostLogin"; }
};

class IItem
{
public:
	virtual void Use() = 0;
};

class Knife : public IItem
{
	// Inherited via IItem
	void Use() override
	{
		cout << "Çü·ÄÀÌ°¡ ÃãÀ» Ãá´Ù" << endl;
	}
};

class Gun : public IItem
{
	// Inherited via IItem
	void Use() override
	{
		cout << "Çü·ÉÀÏ°¡ ÃÑÀ» ½ð´Ù." << endl;
	}
};

class Inventory
{
public:
	void Pickup(IItem* PickedupItem)
	{
		Data.push_back(PickedupItem);
	}

	IItem* operator[](int Index) const
	{
		return Data[Index];
	}

private:
	vector<IItem*> Data;
};


int main()
{
	Inventory I;
	I.Pickup(new Knife());
	I.Pickup(new Gun());
	I[0]->Use();
	I[1]->Use();

	//vector<AActor*> Parents;
	//Parents.push_back(new ACharacter);
	//Parents.push_back(new AGameModeBasse);
	//Parents.push_back(new ACharacter);
	//for (int i = 0; i < Parents.size(); ++i)
	//{
	//	AGameModeBasse* GM = dynamic_cast<AGameModeBasse*>(Parents[i]);
	//	if (GM)
	//	{
	//		GM->PostLogin();
	//	}

	//	ACharacter* Char = dynamic_cast<ACharacter*>(Parents[i]);
	//}

	return 0;
}