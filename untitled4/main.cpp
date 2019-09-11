#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace std;
using namespace Eigen;
int main()
{
    Matrix2d A;
    Matrix3d B;
    Matrix<double ,2,3> C;
    A<<2,0,1,1;
    B<<2,2,3,1,1,2,3,1,0;
    C<<1,0,2,1,3,1;

    cout<<A.inverse()*C*B.inverse()<<endl;

}