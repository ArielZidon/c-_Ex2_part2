#include "page.hpp"
namespace ariel {
class Notebook{

    private:

        unsigned int _pages;

        std::vector<page> _page;

        bool legal_num_of_page(int page) const;

    public:

        Notebook();

        page getPage(int page_num);                                                 

        void setPage(int page_num); 

        void show(int page);

        void write(int s, int r, int col, ariel::Direction sideOrUpDown,const std::string & str);  

        std::string read(int p, int r, int col, ariel::Direction sideOrUpDown,int len);

        void erase(int p,int r, int col, ariel::Direction sideOrUpDown,int l);        
};
}
