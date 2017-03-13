#ifndef DBINTERFACEBASE_H
#define DBINTERFACEBASE_H

#include <iostream>

#include "Context.h"
#include "Result.h"

class Result;

class DBInterfaceBase
{

 //friend class DBInterface;

 //protected:
 public:

 DBInterfaceBase() = default;
 virtual ~DBInterfaceBase() = default;

 //private:

 virtual void Connect()  = 0;

 virtual void Query()  = 0;

 virtual void Lookup_column() = 0;

 virtual void Insertdatapath() = 0;

 virtual void Insertdatacode() = 0;

 virtual Result& FetchResult() = 0;

};

#endif
