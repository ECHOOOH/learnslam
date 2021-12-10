#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace std;
using namespace Eigen;
#define MS 10
int main() {
    Matrix<double,MS,MS> M1=MatrixXd::Random(MS,MS);
    Matrix3d M2=M1.block(0,0,3,3);
    cout.precision(3);
    cout<<M1<<endl;
    cout<<M2<<endl;
    //分块赋值
    M1.block<3,3>(0,0)=MatrixXd::Identity(3,3);
    cout<<M1<<endl;
    return 0;
}
