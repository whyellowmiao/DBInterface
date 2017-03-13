#ifndef MYSQLINTERFACE_H
#define MYSQLINTERFACE_H

#include "DBInterface.h"
#include "DBInterfaceBase.h"
#include "Result.h"

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

 Result& FetchResult() {return MySQL_Result;}

 Context MySQL_Context;

 Result MySQL_Result;

};

#endif
