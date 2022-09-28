#include <iostream>
#include "mesh.h"
#include <vector>

#include "matrix.h"

using namespace std;

int main()
{
    cout << "\tTESTING des fonctionnalites des PGMS: mesh.h, matrix.h " << endl;
    cout << "\n";
    cout << "\ttest mef2d" << "\n";
    
    int npts = 3;
    R2 *ptrR2 = new R2[npts];
    ptrR2->x = 12;ptrR2->y=-4;
    ptrR2[1].x = 11;ptrR2[1].y = 7;
    ptrR2[2].x = 0;ptrR2[2].y = 1;
    cout << "\tx=" << ptrR2->x << ",y=" << ptrR2->y << endl;
    ptrR2++;
    cout << "\tx=" << ptrR2->x << ",y=" << ptrR2->y << endl;
    ptrR2++;
    cout << "\tx=" << ptrR2->x << ",y=" << ptrR2->y << endl;
    
    R2 A(3,8),B(2,2),C(9,-3);
    vector<R2> vR2;
    vR2.push_back(A);vR2.push_back(B);vR2.push_back(C);
    vector<R2>::iterator i;
    for(i=vR2.begin();i!=vR2.end();i++)
    {
        cout << "\tx=" << (*i).x << ",y=" << (*i).y << endl;
    }
    
    R2 AB(A,B);
    A.affichage("A=");
    B.affichage("B=");
    AB.affichage("AB=");
    
    Label l1(100),l2;
    std::cout << "\t" << l1.onGamma() << "," << l2.lab << std::endl;
    
    Matrix<double> mat_A(2,2),mat_C;
    mat_A.affichage("mat_A =");
    mat_A.a[1][1]=7;
    Matrix<double> mat_B(mat_A);
    mat_B.affichage("mat_B =");
    mat_C = mat_B;
    mat_C.affichage("mat_C = mat_B");
    
    typedef Matrix<double> matd;
    matd mat_D;
    mat_D = mat_C + mat_C;
    mat_D.affichage("mat_D = mat_C + mat_C");
    matd mat_E;
    mat_E = mat_C - mat_D;
    mat_E.affichage("mat_E = mat_C - mat_D");
    
    mat_E.operator+=(mat_E);
    mat_E.affichage("mat_E += mat_E");
    
    mat_E.operator-=(mat_E);
    mat_E.affichage("mat_E -= mat_E");
    
    matd mat_F,mat_G,mat_H(2,3),mat_I(3,1),mat_HI(2,1);
    
    mat_B.affichage("mat_B =");
    mat_F = mat_B*mat_B;
    mat_F.affichage("mat_F = mat_B*mat_B");
    
    
    std::cout << "\t" << mat_F(1,1) << std::endl;
    

    mat_H.set(0,0,5);mat_H.set(0,1,-2);
    mat_H.set(1,1,4);mat_H.set(1,2,-7);
    mat_H.affichage("mat_H=");
    
    mat_I.set(0,0,1);mat_I.set(1,0,1),mat_I.set(2,0,1);
    mat_I.affichage("mat_I=");
    
    mat_HI.affichage("mat_HI");
    mat_HI = mat_H*mat_I;
    mat_HI.affichage("mat_HI = mat_H*mat_I");
    
    double alpha(2.0);
    mat_HI = mat_HI/alpha;
    mat_HI.affichage("mat_HI/alpha");
    
    mat_HI = mat_HI*alpha;
    mat_HI.affichage("mat_HI*alpha");
    
    
    
    
    

    cout << "\n";
    
}
