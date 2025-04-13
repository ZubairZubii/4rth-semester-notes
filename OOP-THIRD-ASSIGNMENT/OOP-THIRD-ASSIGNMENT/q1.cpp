#include<iostream>
#include<string>
using namespace std;


class Block
{
public:
    string form;
    string color;
    Block() 
    {
        form = "";
        color = "";
    }

    Block(string f, string c = "")
    {
        form = f;
        color = c;
    }

    void setform(string f) {
         form=f;
    }

    void setcolor(string c)
    {
        color=c;
    }
    string getform() {
        return form;
    }

    string getcolor() {
        return color;
    }
     
 

     friend ostream& operator<<(ostream& out, const Block& b) {
       
         out << "( " << b.form << " , " << b.color << " ) ";

         return out;
     }
   
};

class Build 
{
public:
    Block ***content;
    int height ;
    int deep;
    int width;

    
    Build(){
        content = NULL;
        height = 0;
        width = 0;
        deep = 0;

    }

    Build(Block& b) :height(1),width(1),deep(1){
     
        content=(new Block **[height]);
        content[0] = new Block * [deep];
        content[0][0] = new Block[width]{ b };
    }

    Build(int a1, int b1, int c1) 
    {
  
        height = a1;
        deep = b1;
        width = c1;
        

        content = new Block * *[a1];

        for (int i = 0; i <a1; i++)
        {
            content[i] = new Block * [b1];
            for (int j = 0; j < b1; j++) 
            {
               content[i][j] = new Block[c1];
            }
        }

    }

    friend ostream& operator<<(ostream& out, const Build& b)
    { 
        int no = 4;
        for (int i = 0; i < b.height; i++)
        {
            out << "Layer " << no << " :" << endl;

            for (int j = 0; j < b.deep; j++)
            {
                for (int k = 0; k < b.width; k++)
                {
                    if( b.content[i][j][k].color !="")
                    cout << b.content[i][j][k];
                }
            }
            no-= 1;
            cout << endl;
        }
        return out;
    }


    Build operator^=(const Build& other)
    {
        int a, b, c;
        a = height+ other.height;
        if (deep > other.deep || width > other.width) {
            b = deep;  
            c = width;
        }
        else {
            b = other.deep;
            c = other.width;
        }
 
        Build rez(a,b,c);
        
       for (int i = 0; i < height; i++) {
            for (int j = 0; j < deep; j++) {
                for (int k = 0; k < width; k++) {
                    rez.content[i][j][k].form = content[i][j][k].form;
                    rez.content[i][j][k].color = content[i][j][k].color;
                    
                }
            }
        }

        
        for (int i = 0; i < other.height; i++) {
            for (int j = 0; j < other.deep; j++) {
                for (int k = 0; k < other.width; k++) {
                    rez.content[height+i][j][k].color = other.content[i][j][k].color;
                    rez.content[height + i][j][k].form = other.content[i][j][k].form;
                }
            }
        }

        
        content = rez.content;
        height = rez.height;
        deep = rez.deep;
        width = rez.width;

    
        return *this;
    
    }

  
    Build operator +=(const Build& other) {

        {
            int a, b, c;
            if (height > other.height and deep > other.deep) {
                a = height;
                b = deep;
                c = width;
            }
            else
            {
                a = height;
                b = deep;
                c = width + other.width;
            }
            Build rez(a, b, c);

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < deep; j++)
                {
                    for (int k = 0; k < width; k++)
                    {
                        rez.content[i][j][k].form = content[i][j][k].form;
                        rez.content[i][j][k].color = content[i][j][k].color;

                    }
                }
            }

            for (int i = 0; i < other.height; i++)
            {
                for (int j = 0; j < other.deep; j++)
                {
                    for (int k = 0; k < other.width; k++)
                    {
                        rez.content[i][j][width + k].form = other.content[i][j][k].form;
                        rez.content[i][j][width + k].color = other.content[i][j][k].color;

                    }
                }
            }

            content = rez.content;
            height = rez.height;
            deep = rez.deep;
            width = rez.width;
        
        
        }

        return *this;
    }

    Build operator-=(const Build& other) {
        int a, b, c;
        if (height > other.height) {
            a = height;
            b = deep;
            c = width;
        }
        else
        {
            a = height;
            b = deep + other.deep;
            c = other.width;
        }
        Build rez(a, b, c);

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < deep; j++) {
                for (int k = 0; k < width; k++) {
                    rez.content[i][j][k].form = content[i][j][k].form;
                    rez.content[i][j][k].color = content[i][j][k].color;
                }
            }
        }

        for (int i = 0; i < other.height; i++) {
            for (int j = 0; j < other.deep; j++) {
                for (int k = 0; k < other.width; k++) {
                    rez.content[i][deep + j][k].form = other.content[i][j][k].form;
                    rez.content[i][deep + j][k].color = other.content[i][j][k].color;
                }
            }
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < deep; j++) {
                delete[] content[i][j];
            }
            delete[] content[i];
        }
        delete[] content;

        content = rez.content;
        height = rez.height;
        deep = rez.deep;
        width = rez.width;

        
      for (int i = 0; i < rez.height; i++) {
          for (int j = 0; j < rez.deep; j++) {
              delete[] rez.content[i][j];
          }
          delete[] rez.content[i];
      }
      delete[] rez.content;

        return *this;
    }



    friend Build operator*(unsigned int n, Build const& a) {

        Build obj1=a;
        Build obj2=a;
        for (int i = 0; i < n; i++) {
         obj1+=obj2; 
        }

        return obj1;
    }


    
    friend Build operator/(unsigned int n, Build const& a)
    {

        Build obj1 = a;
        Build obj2 = a;
        for (unsigned int i = 0; i < n; i++) {
            obj1 ^= obj2;
        }

        return obj1;
    }


    friend Build operator%(unsigned int n, Build const& a)
    {

        Build obj1 = a;
        Build obj2 = a;
        for (unsigned int i = 0; i < n; i++) {
            obj1 -= obj2;
        }

        return obj1;
    }


};

int main() {
 
    Block b1("Simple", "White");
    Block b2("ObliquedL", "red");
    Block b3("ObliquedR", "red");
    Block b4("Simple", "red");
    Block _block1 = b1 ^ b2;
    Block _block2 = _block1 ^ b1;
    cout << _block2;
    //Block _block1 = b1 + b2;
    //Block _block1 = b1 + b2;
    //Block _block1 = b1 + b2;

    //Build build1(b1);
    //Build first = 3 * build1;
    // Build build2(b1);
    // Build second = 2 / first;
    // Build build3(b2);
    // Build build4(b4);
    // Build build5(b3);
    // Build build6(b2);
    // Build build7(b3);
    // Build third = 1 * build4;
    // build3 += third;
    // build3 += build5;
    // build3 ^= second;
    // build6 += build7;
    // build6 ^= build3;
    // cout << build6;

}

















