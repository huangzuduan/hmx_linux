#ifndef __OFFLINE_USER_MGR_H_
#define __OFFLINE_USER_MGR_H_

#include "Includes.h"
#include "SrvEngine.h"
#include "OfflineUser.h"

class OfflineUserMgr : protected zEntryMgr< zEntryID, zEntryName >
{
public:
	OfflineUserMgr();
	~OfflineUserMgr();
	bool getUniqeID(QWORD& tempid);
	void putUniqeID(const QWORD& tempid);
	OfflineUser* CreateObj();
	void DestroyObj(OfflineUser* user);

	void loadDB();

	bool addUser(OfflineUser *user)
	{
		return zEntryMgr< zEntryID, zEntryName >::addEntry(user);
	}

	OfflineUser* getUserByName(const char * name)
	{
		return (OfflineUser *)zEntryMgr< zEntryID, zEntryName >::getEntryByName(name);
	}

	OfflineUser* getUserByID(QWORD id)
	{
		return (OfflineUser *)zEntryMgr< zEntryID, zEntryName >::getEntryByID(id);
	}

	void removeUser(OfflineUser *user)
	{
		zEntryMgr< zEntryID, zEntryName >::removeEntry(user);
	}

	template <class YourUserEntry>
	bool execEveryUser(execEntry<YourUserEntry> &exec)
	{
		return zEntryMgr< zEntryID, zEntryName >::execEveryEntry<>(exec);
	}

private:

	zObjPool<OfflineUser> objpool;
	
};


#endif


