#ifndef MYSQLINTERFACE_H
#define MYSQLINTERFACE_H

#include "DBInterface.h"
#include "DBInterfaceBase.h"
#include "DBIResult.h"

class MySQLInterface: public DBInterfaceBase
{

 friend class DBInterface;

 MySQLInterface(const Context& c): MySQL_Context(c) {}

 void Connect();

 void Lookup_column();

 void Query();

 void Insertdatapath();

 void Insertdatacode();

 bool IfConnect();

 bool MySQL_Reconnect();

 void CreateStmt();

 DBIResult& FetchResult() {return MySQL_Result;}

 Context MySQL_Context;

 DBIResult MySQL_Result;

};

#endif
