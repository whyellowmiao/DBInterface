#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <string>
//#include <memory>
#include "DBIResult.h"
#include "Context.h"
#include "DBInterfaceBase.h"

class DBInterfaceBase;

class DBIResult;

class MySQLInterface;

class DBInterface
{

 public:

 DBInterface();
 //DBInterface() = default;
 //virtual ~DBInterface();

 void Connect() const{ svc -> Connect(); }

 void Query() const{ svc -> Query(); }

 void Lookup_column() const { svc -> Lookup_column(); }

 void Insertdatapath() const { svc -> Insertdatapath(); }

 void Insertdatacode() const { svc -> Insertdatacode(); }

 void Session(const Context& c);

 DBIResult& FetchResult() const { svc -> FetchResult(); }

 private:

 //DB_Svc(std::shared_ptr<DB_Svc_Base> db_svc): svc(db_svc) {}

 DBInterfaceBase* svc;

 Context db_context;

 void Use_MySQL_Connector();

};

 //inline

 //DB_Svc::DB_Svc(const Context& c): svc(new MySQL_Svc(c)){}

#endif
