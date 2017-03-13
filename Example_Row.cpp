#include "DB_TableRow.h"
#include "DBiResultPtr.h"

class Example_Row : public DB_TableRow
{
 public:
 
 Example_Row() = default;
 ~Example_Row() = default;

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
 column {"name", "owner", "species"};
 std::string table = "menagerie.pet";
 //std::string schema = "menagerie";
 Request request(column, table, lookup);

 Context context(coninfo, request);

 Example_Row row;
 DBiResultPtr<Example_Row> pr(context);

 pr.Session();

 pr.GetResByRowNum(1);
 std::cout << "name= " << pr.GetString("name") << std::endl;
 std::cout << "owner= " << pr.GetString("owner") << std::endl;
 std::cout << "species= " << pr.GetString("species") << std::endl;

 return 0;
}
