#include "PlayerMgr.h"

PlayerMgr::PlayerMgr()
{

}

PlayerMgr::~PlayerMgr()
{

}

Player* PlayerMgr::CreateObj(zSession* _session)
{
	return objpool.CreateObj(_session);
}

void PlayerMgr::DestoryObj(Player* obj)
{
	objpool.DestroyObj(obj);
}

Player* PlayerMgr::get(int64 id)
{
	return (Player*)zEntryMgr<zEntryID>::getEntryByID(id);
}

bool PlayerMgr::add(Player* obj)
{
	return zEntryMgr<zEntryID>::addEntry(obj);
}

void PlayerMgr::remove(Player* obj)
{
	zEntryMgr<zEntryID>::removeEntry(obj);
}

void PlayerMgr::Update(const zTaskTimer* timer)
{
	struct MyStruct : public execEntry<Player>
	{
		MyStruct(const zTaskTimer* _timer):timer(_timer)
		{
		}
		virtual bool exec(Player *entry)
		{
			entry->Update(timer);
			return true;
		}
		const zTaskTimer* timer;
	};

	MyStruct exec(timer);
	zEntryMgr<zEntryID>::execEveryEntry(exec);
}
