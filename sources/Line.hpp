#include <iostream>
#include <string>
#include <vector>
#define maxLength 100
#define add_10_lines 10
#define extra_pages = 30;

class Line
{

private:

    std::vector<char> line;

    void hasBeenWrited(unsigned int & column,const std::string & str);     

    static void checkChar(unsigned int & column,char write_char);  

    static void inLine(unsigned int & column,unsigned int len);   

public:

        Line();  

        const std::vector<char> getLine();    

        void write(unsigned int  column,const std::string & str);  

        std::string read(unsigned int column,unsigned int len); 

        void erase(unsigned int  column,unsigned int len);     

        char getchar(unsigned long index);                                                                                                                                              
};
