#ifndef _PROC_WORLD_HANDLER_H_
#define _PROC_WORLD_HANDLER_H_

#include "Includes.h"
#include "SrvEngine.h"

struct NetMsgSS;


class ProcWorldHandler : public Single<ProcWorldHandler>
{
public:
	ProcWorldHandler();
	~ProcWorldHandler();

	void RqEnterScene(zSession* pSession, const NetMsgSS* pMsg,int32 nSize);

	void NtEnterResult(zSession* pSession, const NetMsgSS* pMsg, int32 nSize);

	void NtLoadUids(zSession* pSession, const NetMsgSS* pMsg, int32 nSize);
};


#endif

