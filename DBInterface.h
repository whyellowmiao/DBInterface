#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <string>
#include <memory>
#include "Result.h"
#include "Context.h"
#include "DBInterfaceBase.h"

class DBInterfaceBase;

class Result;

class MySQLInterface;

class DBInterface
{

 public:

 DBInterface(const Context&c );

 void Connect(const Context& c) const{ svc -> Connect(c); }

 void Query(const Context& c) const{ svc -> Query(c); }

 void Lookup_column(const Context& c) const { svc -> Lookup_column(c); }

 void Insertdatapath(const Context& c) const { svc -> Insertdatapath(c); }

 void Insertdatacode(const Context& c) const { svc -> Insertdatacode(c); }

 void Session(const Context& c) const;

 Result& FetchResult() const { svc -> FetchResult(); }

 private:

 //DB_Svc(std::shared_ptr<DB_Svc_Base> db_svc): svc(db_svc) {}

 std::shared_ptr<DBInterfaceBase> svc;

 Context db_context;

 void Use_MySQL_Connector();

};

 //inline

 //DB_Svc::DB_Svc(const Context& c): svc(new MySQL_Svc(c)){}

#endif