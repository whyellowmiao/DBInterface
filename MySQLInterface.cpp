#include "MySQLInterface.h"
#include <stdexcept>

void MySQLInterface::Connect(const Context& c)
{

 std::shared_ptr<sql::Connection>
 con(sql::mysql::get_driver_instance()
 ->connect(c.Get_Con_Info().GetURL(),
           c.Get_Con_Info().GetUSER(),
           c.Get_Con_Info().GetPASSWORD()));

 MySQL_Result.SetConnection(con);

 if(IfConnect())

 #ifdef FORSNIPER
 LogInfo << "Successfully accessed to " <<
 c.Get_Con_Info().GetURL() << std::endl;
 #else
 std::cout << "Successfully accessed to " <<
 c.Get_Con_Info().GetURL() << std::endl;
 #endif

 else

 #ifdef FORSNIPER
 LogError << "Connected failed" << std::endl;
 #else
 std::cerr << "Connected failed" << std::endl;
 #endif

}

bool MySQLInterface::IfConnect()
{

 if(MySQL_Result.GetConnection()!=NULL)
 {

  if(MySQL_Result.GetConnection()->isValid())

  return true;

 }

 else

 return false;

}

bool MySQLInterface::MySQL_Reconnect()

{

 for(int i=1;i<5;i++)
 {
  Connect(MySQL_Context);
  if(IfConnect())
  return true;
 }

 #ifdef FORSNIPER
 LogError << "Tried too many times " << std::endl;
 LogError << "Please check your coninformation " << std::endl;
 #else
 std::cerr << "Tried too many times " << std::endl;
 std::cerr << "Please check your coninformation " << std::endl;
 #endif

 return false;

}

void MySQLInterface::Lookup_column(const Context& c)

{

 if(!IfConnect())
 MySQL_Reconnect();

 if(IfConnect())

 {

 CreateStmt();

 MySQL_Result.GetStatement()->execute("use "+c.Get_Request().GetSchema());
 //Read out data from the table
 std::string read_query = "select ";
 for (auto i : c.Get_Request().GetPro())
 read_query = read_query + i + ",";
 if(false == read_query.empty())
 read_query.erase(read_query.end()-1);
 read_query = read_query + " from " + c.Get_Request().GetTableName();
 read_query = read_query + " limit 0,5";

 #ifdef FORSNIPER
 LogInfo << read_query << std::endl;
 #else
 std::cout << read_query << std::endl;
 #endif

 //Store the data
 std::shared_ptr<sql::ResultSet>
 res(MySQL_Result.GetStatement()->executeQuery(read_query));

 MySQL_Result.SetResult(res);

 #ifdef FORSNIPER
 LogInfo << "Result has been stored" << std::endl;
 #else
 std::cout << "Result has been stored" << std::endl;
 #endif

 //The stuff below is used to test the code, just ignore it.
 /*size_t row_count = res->rowsCount()-1;
 std::cout << "row_count is " << row_count << std::endl;

 //Selecting in ascending order but fetching in descending (reverse) order

 res->afterLast();
 if(true != res->isAfterLast())
 throw std::runtime_error("Position should be after last row (1)");

 while (res->previous())
 {
 for(auto i : c.Get_Request().GetPro())
  {
  std::cout << "#\t\t Row " << row_count << " "
  << i << " = " <<
  res->getString(i) << std::endl;
  }
 row_count--;
 }*/

 //stmt->execute(your SQL query);
 
 //MySQL_Result.SetStatement(stmt);

 //std::shared_ptr<sql::ResultSet>
 //res(stmt->executeQuery(your SQL query));
 //
 //MySQL_Result.SetResult(res);
 //
 }

}

void MySQLInterface::CreateStmt()

{

 std::shared_ptr<sql::Statement>
 stmt(MySQL_Result.GetConnection()->createStatement());

 MySQL_Result.SetStatement(stmt);

}

void MySQLInterface::Query(const Context& c)

{
 if(IfConnect())

 {
 
 /*std::shared_ptr<sql::Statement>
 stmt(MySQL_Result.GetConnection()->createStatement());*/

 CreateStmt();

 if(c.Get_Request().GetSchema().empty());
 else MySQL_Result.GetStatement()->execute("use "+c.Get_Request().GetSchema());

 MySQL_Result.GetStatement()->execute(c.Get_Request().GetSqlquery());

 }
}

void MySQLInterface::Insertdatapath(const Context& c)

{
 if(IfConnect())
 {
  CreateStmt();
  
  if(c.Get_Request().GetSchema().empty());
  else 
  MySQL_Result.GetStatement()->execute("use "+c.Get_Request().GetSchema());

  std::string query;
  query = "load data local infile "
        + c.Get_Request().GetSqlquery()
        + " into table "
        + c.Get_Request().GetTableName();
  MySQL_Result.GetStatement()->execute(query);

  #ifdef FORSNIPER
  LogInfo << "Successfully inserted data to"
          << c.Get_Request().GetTableName() << std::endl;
  #else
  std::cout << "Successfully inserted data to "
            << c.Get_Request().GetTableName() << std::endl;
  #endif

 }
}

void MySQLInterface::Insertdatacode(const Context& c)
{
 if(IfConnect())
 {
  CreateStmt();

  if(c.Get_Request().GetSchema().empty());
  else
  MySQL_Result.GetStatement()->execute("use "+c.Get_Request().GetSchema());

  std::string query;
  query = "insert into "
        + c.Get_Request().GetTableName()
        + " values "
        + c.Get_Request().GetSqlquery();

  MySQL_Result.GetStatement()->execute(query);

  #ifdef FORSNIPER
  LogInfo <<  "Successfully inserted data to "
          << c.Get_Request().GetTableName() << std::endl;
  #else
  std::cout << "Successfully inserted data to "
            << c.Get_Request().GetTableName() << std::endl;
  #endif
 }
}
/*
int main()

{

 Con_Info coninfo(MySQL, "tcp://127.0.0.1", "root", "7H8tuy?aEag:3");

 std::vector<std::string> 
 column {"CountryCode", "IsOfficial", "Percentage"};
 std::string table = "CountryLanguage";
 std::string schema = "world";
 Request request{column, MySQL, lookup, schema, table};

 Context context(coninfo, request);

 DB_Svc svc(context);

 svc.Connect(context);

 svc.Query(context);

 return 0;

}*/
