#include <iostream>
#include "DataBaseSvc/DataBaseSvc.h"
#include "SniperKernel/SvcFactory.h"

DECLARE_SERVICE(DataBaseSvc);

DataBaseSvc::DataBaseSvc(const std::string& name):
SvcBase(name)

{
 declProp("Url", furl);
 declProp("User", fuser);
 declProp("Password", fpassword);
 declProp("DB_Type", fdbtype=1);

 #ifdef FORSNIPER
 LogInfo << "constructing DBInterface..." << std::endl;
 #else
 std::cout << "constructing DBInterface..." << std::endl;
 #endif

 if(1==fdbtype)

 {

  #ifdef FORSNIPER
  LogInfo << "DB_Svc will connect to MySQL with Connector..." << std::endl;

  LogInfo << "the URL is " << furl << std::endl;

  LogInfo << "Connector with User " << fuser << std::endl;

  Use_MySQL_Connector();

  LogInfo << "DBInterface has been created!" << std::endl;

  #else
  std::cout << "DBInterface will connect to MySQL with Connector..."
            << std::endl;

  std::cout << "the URL is " << furl << std::endl;

  std::cout << "Connector with User " << fuser << std::endl;

  Use_MySQL_Connector();

  std::cout << "DBInterface has been created!" << std::endl;

  #endif
 }
}

void DataBaseSvc::Use_MySQL_Connector()
{
 svc = std::shared_ptr<MySQLInterface>(new MySQLInterface(db_context));
}

void DataBaseSvc::Session(const Context& c)
{

 db_context = c;

 if(1==db_context.Get_Con_Info().GetDB())

 {

  #ifdef FORSNIPER
  LogInfo << "DB_Svc will connect to MySQL with Connector..." << std::endl;

  LogInfo << "the URL is " << db_context.Get_Con_Info().GetURL() << std::endl;

  LogInfo << "Connector with User "
            << db_context.Get_Con_Info().GetUSER() << std::endl;

  Use_MySQL_Connector();

  LogInfo << "DBInterface has been created!" << std::endl;

  #else
  std::cout << "DBInterface will connect to MySQL with Connector..."
            << std::endl;

  std::cout << "the URL is "
            << db_context.Get_Con_Info().GetURL() << std::endl;

  std::cout << "Connector with User "
            << db_context.Get_Con_Info().GetUSER() << std::endl;

  Use_MySQL_Connector();

  std::cout << "DBInterface has been created!" << std::endl;

  #endif
  }

 if(lookup == db_context.Get_Request().GetRequest())
 {
  #ifdef FORSNIPER
  LogInfo << "the request is select " /*<< extract fproperty*/<< "from "
           << db_context.Get_Request().GetTableName() << std::endl;
  #else
  std::cout << "the request is select " /*<< extract fproperty*/<< "from "
           << db_context.Get_Request().GetTableName() << std::endl;
  #endif

  Connect();

  Lookup_column();

 }

 else if(infilepath == db_context.Get_Request().GetRequest())
 {

  #ifdef FORSNIPER
  LogInfo << "the request is load data local infile "
            << db_context.Get_Request().GetSqlquery()
            << " into table "
            << db_context.Get_Request().GetTableName() << std::endl;
  #else
  std::cout << "the request is load data local infile "
            << db_context.Get_Request().GetSqlquery()
            << " into table "
            << db_context.Get_Request().GetTableName() << std::endl;
  #endif

  Connect();

  Insertdatapath();

 }
}

bool DataBaseSvc::initialize()
{
 Connect();
}

bool DataBaseSvc::finalize()
{}
