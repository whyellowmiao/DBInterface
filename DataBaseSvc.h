#ifndef DATABASESVC_H
#define DATABASESVC_H

#include <boost/python.hpp>
#include <memory>
#include <string>
#include "Result.h"
#include "Context.h"
#include "DBInterfaceBase.h"
#include "SniperKernel/SvcBase.h"

class DBInterfaceBase;
class Result;
class MySQLInterface;

class DataBaseSvc : public SvcBase
{

 public :

 DataBaseSvc(const std::string& name);
 virtual ~DataBaseSvc();

 bool initialize();
 bool finalize();

 void Query() const{ svc -> Query(); }
 void Lookup_column() const { svc -> Lookup_column(); }
 void Insertdatapath() const { svc -> Insertdatapath(); }
 void Insertdatacode() const { svc -> Insertdatacode(); }
 void Session(const Context&);
 Result& FetchResult() const { svc -> FetchResult(); }
 private :

 std::string furl;
 std::string fuser;
 std::string fpassword;
 int fdbtype;

 std::shared_ptr<DBInterfaceBase> svc;
 Context db_context;

 void Connect() const { svc -> Connect(); }
 void Use_MySQL_Connector();
};

#endif
