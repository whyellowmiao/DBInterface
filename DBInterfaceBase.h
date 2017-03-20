#ifndef DBINTERFACEBASE_H
#define DBINTERFACEBASE_H

#include <iostream>

#include "Context.h"
#include "DBIResult.h"

class DBIResult;

class DBInterfaceBase
{

 //friend class DBInterface;

 //protected:
 public:

 DBInterfaceBase() {};
 virtual ~DBInterfaceBase() {};

 //private:

 virtual void Connect()  = 0;

 virtual void Query()  = 0;

 virtual void Lookup_column() = 0;

 virtual void Insertdatapath() = 0;

 virtual void Insertdatacode() = 0;

 virtual DBIResult& FetchResult() = 0;

};

#endif
