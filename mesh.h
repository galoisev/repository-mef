#ifndef __MESH__
#define __MESH__

#include <iostream>
#include "assert.h"


typedef double R;

class R2
{
    public:
        R x,y;
        R2():x(0),y(0){}//default constructor
        R2(R a, R b):x(a),y(b){}//constructor
        R2(R2 P, R2 Q):x(Q.x-P.x),y(Q.y-P.y){}
        R2(const R2& P)=default;//copy constructor
        R2& operator=(const R2& P)=default;//copy assignment
        
        friend std::ostream& operator<<(std::ostream& f, const R2& P)
        {
            f << P.x << "," << P.y ; 
            return f;
        }
        friend std::istream& operator>>(std::istream& f, R2& P)
        {
            f >> P.x >> P.y;
            return f;
        }
        
        R2 operator+ (R2 P)const{return R2(x+P.x,y+P.y);}
        R2 operator- (R2 P)const{return R2(x-P.x,y-P.y);}
        R2 operator+=(R2 P)
        {
            x += P.x;
            y += P.y;
            return (*this);
        }
        R2 operator-=(R2 P)
        {
            x -= P.x;
            y -= P.y;
            return (*this);
        }
        R2 operator- ()const {return R2(-x,-y);}
        R2 operator+ ()const {return (*this);}
        R  operator, (R2 P)const{return (x*P.x + y*P.y);}//produit scalaire
        R  operator^ (R2 P)const{return (x*P.y - y*P.x);}//produit mixte
        R2 perp(){return R2(-y,x);}//la perpendiculaire
        R2 operator* (R c)const{return R2(x*c,y*c);}
        R2 operator/ (R c)const
        {
            assert((c > 0)||(c < 0));
            return R2(x/c,y/c);            
        }
        
        void affichage(const char*msg)
        {
            std::cout << "\n";
            std::cout << "\t" << msg << "(" << x << "," << y << ")" << std::endl;
        }
};


// La classe Label (références des sommets ou des triangles) 
class Label
{
    public:
        int lab;
        Label(int r=0):lab(r){}
        int onGamma()const{return lab;}
        
        friend std::ostream& operator<<(std::ostream& f, const Label& r)
        {
            f << r.lab;
            return f;
        }
        friend std::istream& operator>>(std::istream& f, Label& r)
        {
            f >> r.lab;
            return f;
        }
};


class Vertex:public R2,public Label
{
    public:
        Vertex():R2(),Label(){};
        Vertex(R2 P, int r=0):R2(P),Label(r){}
        friend std::ostream& operator<<(std::ostream& f, const Vertex& v)
        {
            f << (R2)v << " " << (Label &)v ;
            return f;
        }
        friend std::istream& operator>>(std::istream& f, Vertex& v)
        {
            f >> (R2&)v >> (Label&)v;
            return f;
        }
    
};


class Mesh 
{
    public:
    
};




#endif //__MESH__
