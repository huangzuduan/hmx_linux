#ifndef _PROC_WORLD_HANDLER_H_
#define _PROC_WORLD_HANDLER_H_

#include "Includes.h"

class zSession;
struct NetMsgSS;


class ProcWorldHandler : public Single<ProcWorldHandler>
{
public:
	ProcWorldHandler();
	~ProcWorldHandler();

};


#endif

