#include "DBInterface.h"
#include "MySQLInterface.h"

DBInterface::DBInterface()
//db_context(c)

{

 #ifdef FORSNIPER
 LogInfo << "constructing DBInterface..." << std::endl;
 #else
 std::cout << "constructing DBInterface..." << std::endl;
 #endif

/* if(1==db_context.Get_Con_Info().GetDB())

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

  std::cout << "the URL is " << db_context.Get_Con_Info().GetURL() << std::endl;

  std::cout << "Connector with User " 
            << db_context.Get_Con_Info().GetUSER() << std::endl;

  Use_MySQL_Connector();

  std::cout << "DBInterface has been created!" << std::endl;

  #endif
 }
*/
}

void DBInterface::Use_MySQL_Connector()

{

 svc = new MySQLInterface(db_context);

}

void DBInterface::Session(const Context& c)

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

/*int main()

{

 Con_Info coninfo(MySQL, "tcp://127.0.0.1", "root", "Xiao3woaini!");

 std::vector<std::string>
 column {"name", "owner", "species"};
 std::string table = "pet";
 std::string schema = "menagerie";
 Request request{column, MySQL, lookup, schema, table};

 Context context(coninfo, request);

 DB_Svc svc(context);

 //svc.Connect(context);

 //svc.Query(context);
 
 svc.Session(context);

 return 0;

}*/
