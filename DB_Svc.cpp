#include "DB_Svc.h"
#include "MySQL_Svc.h"

DB_Svc::DB_Svc(const Context& c):

 db_context(c)

{

 #ifdef FORSNIPER
 LogInfo << "constructing DB_Svc..." << std::endl;
 #else
 std::cout << "constructing DB_Svc..." << std::endl;
 #endif

 if(1==c.Get_Con_Info().GetDB())

 {

  #ifdef FORSNIPER
  LogInfo << "DB_Svc will connect to MySQL with Connector..." << std::endl;

  LogInfo << "the URL is " << c.Get_Con_Info().GetURL() << std::endl;

  LogInfo << "Connector with User "
            << c.Get_Con_Info().GetUSER() << std::endl;

  Use_MySQL_Connector();

  LogInfo << "DB_Svc has been created!" << std::endl;
  
  #else
  std::cout << "DB_Svc will connect to MySQL with Connector..." << std::endl;

  std::cout << "the URL is " << c.Get_Con_Info().GetURL() << std::endl;

  std::cout << "Connector with User " 
            << c.Get_Con_Info().GetUSER() << std::endl;

  Use_MySQL_Connector();

  std::cout << "DB_Svc has been created!" << std::endl;

  #endif
 }

}

void DB_Svc::Use_MySQL_Connector()

{

 svc = std::shared_ptr<MySQL_Svc>(new MySQL_Svc(db_context));

}

void DB_Svc::Session(const Context& c) const

{

 if(lookup == c.Get_Request().GetRequest())
 {
  #ifdef FORSNIPER
  LogInfo << "the request is select " /*<< extract fproperty*/<< "from "
           << c.Get_Request().GetTableName() << std::endl;
  #else
  std::cout << "the request is select " /*<< extract fproperty*/<< "from "
           << c.Get_Request().GetTableName() << std::endl;
  #endif

  Connect(c);

  Lookup_column(c);

 }

 else if(infilepath == c.Get_Request().GetRequest())
 {

  #ifdef FORSNIPER
  LogInfo << "the request is load data local infile "
            << c.Get_Request().GetSqlquery()
            << " into table "
            << c.Get_Request().GetTableName() << std::endl;
  #else
  std::cout << "the request is load data local infile "
            << c.Get_Request().GetSqlquery()
            << " into table "
            << c.Get_Request().GetTableName() << std::endl;
  #endif

  Connect(c);

  Insertdatapath(c);

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