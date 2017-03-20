#include "DB_TableRow.h"
#include "DBIResultPtr.h"

class Example_Row : public DB_TableRow
{
 public:
 
 Example_Row() {};
 ~Example_Row() {};

 void Store(Context&);

 private:

 std::string name;

 int    attribute1;

 float  attribute2;

 long   attribute3;

 double attribute4;

};

void Example_Row::Store(Context& c)
{
}

int main()
{
 Con_Info coninfo(MySQL, "tcp://127.0.0.1", "root", "Xiao3woaini!");

 std::vector<std::string>
 column;
 column.push_back("name");
 column.push_back("owner");
 column.push_back("species");
 std::string table = "menagerie.pet";
 //std::string schema = "menagerie";
 Request request(column, table, lookup);

 Context context(coninfo, request);

 Example_Row row;
 DBIResultPtr<Example_Row> pr(context);

 pr.Session();

 pr.GetResByRowNum(1);
 std::cout << "name= " << pr.GetString("name") << std::endl;
 std::cout << "owner= " << pr.GetString("owner") << std::endl;
 std::cout << "species= " << pr.GetString("species") << std::endl;

 return 0;
}
