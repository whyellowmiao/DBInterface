#ifndef CONTEXT_H
#define CONTEXT_H

//#define FORSNIPER

#include <string>
#include "Con_Info.h"
#include "Request.h"

#ifdef FORSNIPER
#include "SniperKernel/SniperLog.h"
#endif

class Context
{

 public:

 Context(const Con_Info& coninf, const Request& reque):

 fCon_Info(coninf),
 fRequest(reque){}

 virtual ~Context() = default;

 const Con_Info& Get_Con_Info() const { return fCon_Info; }

 const Request& Get_Request() const { return fRequest; }

 private:

 Con_Info fCon_Info;

 Request fRequest;

};

#endif
