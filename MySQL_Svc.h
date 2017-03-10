#ifndef MYSQL_SVC_H
#define MYSQL_SVC_H

#include "DB_Svc.h"
#include "DB_Svc_Base.h"
#include "Result.h"

class MySQL_Svc: public DB_Svc_Base
{

 //~MySQL_Svc() = default;

 friend class DB_Svc;

 MySQL_Svc(const Context& c): MySQL_Context(c) {}

 void Connect(const Context& c);

 void Lookup_column(const Context& c);

 void Query(const Context& c);

 void Insertdatapath(const Context& c);

 void Insertdatacode(const Context& c);

 bool IfConnect();

 bool MySQL_Reconnect();

 void CreateStmt();

 Result& FetchResult() {return MySQL_Result;}

 Context MySQL_Context;

 Result MySQL_Result;

};

#endif
