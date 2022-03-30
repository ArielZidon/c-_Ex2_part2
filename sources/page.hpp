#include "Line.hpp"
#include "Direction.hpp"

class page{
    private:

        unsigned int numPage;

        std::vector<Line> lines;
  
        int num_Of_Lines;
  
        bool setLine(unsigned int numLine);
  
        void add_number_of_Line();
  
        Line getLine(int numLine);
  
        unsigned int getNumOfPage () const;
    
    public:

        page(unsigned int numpage); 

        void write(unsigned int  row, unsigned int col, ariel::Direction sideOrUpDown,const std::string & str);   

        std::string read(unsigned int row,unsigned int col, ariel::Direction sideOrUpDown,unsigned int len);  

        void erase(unsigned int row, unsigned int col, ariel::Direction sideOrUpDown,unsigned int len);       

        void show();                                                                                                                                 
};