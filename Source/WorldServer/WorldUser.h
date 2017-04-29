#ifndef __WORLD_USER_H_
#define __WORLD_USER_H_

#include "Includes.h"
#include "SrvEngine.h"

/*

  动态缓存在线用户类
	
 */

// id=uid,tempid=sessid,name=nick
class WorldUser : public zEntry
{
public:
	WorldUser();
	~WorldUser();
	void sendToFep(NetMsgSS* pMsg, int32 nSize);
	void sendToSs(NetMsgSS* pMsg, int32 nSize);

public:

	zSession* fepSession;
	zSession* sceneSession;

public:

	QWORD& sessid;
	int64 sceneid;
	int32 mapid;
	int16 level;
	int32 enterscenetime; // 进入或切换场景时间 

};


#endif

