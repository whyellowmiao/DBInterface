#ifndef DBINTERFACEBASE_H
#define DBINTERFACEBASE_H

#include <iostream>
#include "Context.h"
#include "Result.h"

class Result;

class DBInterfaceBase
{

 public:
 //protected:

 DBInterfaceBase() = default;
 virtual ~DBInterfaceBase() = default;

 //private:

 virtual void Connect(const Context&)  = 0;

 virtual void Query(const Context&)  = 0;

 virtual void Lookup_column(const Context&) = 0;

 virtual void Insertdatapath(const Context&) = 0;

 virtual void Insertdatacode(const Context&) = 0;

 virtual Result& FetchResult() = 0;

};

#endif
