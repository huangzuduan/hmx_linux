#include "WorldUser.h"

WorldUser::WorldUser():sessid(tempid)
{
	fepSession = NULL;
	sceneSession = NULL;
}

WorldUser::~WorldUser()
{

}

void WorldUser::sendToFep(NetMsgSS* pMsg, int32 nSize)
{
	if (fepSession)
	{
		fepSession->sendMsg(pMsg, nSize);
	}
}

void WorldUser::sendToSs(NetMsgSS* pMsg, int32 nSize)
{
	if (sceneSession)
	{
		sceneSession->sendMsg(pMsg, nSize);
	}
}