#ifndef RESULT_H
#define RESULT_H

#include <memory>
#include "mysql_connection.h"
#include "driver/mysql_public_iface.h"

class Result
{

 public:

 Result() = default;

 Result(std::shared_ptr<sql::Connection> con):

 MySQL_con(con){}

 Result(std::shared_ptr<sql::Statement> stmt):

 MySQL_stmt(stmt){}

 Result(std::shared_ptr<sql::ResultSet> res):

 MySQL_res(res){}

 Result(std::shared_ptr<sql::Connection> con,
        std::shared_ptr<sql::ResultSet>  res):

 MySQL_con(con),
 MySQL_res(res){}

 Result(std::shared_ptr<sql::Connection> con,
        std::shared_ptr<sql::Statement> stmt):

 MySQL_con(con),
 MySQL_stmt(stmt){}

 Result(std::shared_ptr<sql::Statement> stmt,
        std::shared_ptr<sql::ResultSet> res):

 MySQL_stmt(stmt),
 MySQL_res(res){}

 Result(std::shared_ptr<sql::Connection> con,
        std::shared_ptr<sql::Statement> stmt,
        std::shared_ptr<sql::ResultSet> res):

 MySQL_con(con),
 MySQL_stmt(stmt),
 MySQL_res(res){}

 virtual ~Result() = default;

 void SetConnection(sql::Connection* con) {MySQL_con.reset(con);}
 void SetConnection(std::shared_ptr<sql::Connection> con) {MySQL_con = con;}

 std::shared_ptr<sql::Connection> GetConnection() { return MySQL_con; }

 void SetStatement(sql::Statement* stmt) {MySQL_stmt.reset(stmt);}
 void SetStatement(std::shared_ptr<sql::Statement> stmt) {MySQL_stmt = stmt;}

 std::shared_ptr<sql::Statement> GetStatement() { return MySQL_stmt; }

 void SetResult(sql::ResultSet* res) {MySQL_res.reset(res);}
 void SetResult(std::shared_ptr<sql::ResultSet> res) {MySQL_res = res;}

 std::shared_ptr<sql::ResultSet> GetResult() { return MySQL_res; }

 private:

 std::shared_ptr<sql::Connection> MySQL_con;

 std::shared_ptr<sql::Statement> MySQL_stmt;

 std::shared_ptr<sql::ResultSet> MySQL_res;

};

#endif
