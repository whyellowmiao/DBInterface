#ifndef DB_SVC_BASE_H
#define DB_SVC_BASE_H

#include <iostream>
#include "Context.h"
#include "Result.h"

class Result;

class DB_Svc_Base
{

 public:
 //protected:

 DB_Svc_Base() = default;
 virtual ~DB_Svc_Base() = default;

 //private:

 virtual void Connect(const Context&)  = 0;

 virtual void Query(const Context&)  = 0;

 virtual void Lookup_column(const Context&) = 0;

 virtual void Insertdatapath(const Context&) = 0;

 virtual void Insertdatacode(const Context&) = 0;

 virtual Result& FetchResult() = 0;

};

#endif
