#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace std;
using namespace Eigen;
#define MS 10
int main() {

    //定义两个四元数
    Quaterniond q1(0.35,0.2,0.3,0.1);
    Quaterniond q2(-0.5,0.4,-0.1,0.2);

    //定义两个平移向量
    Vector3d t1(0.3,0.1,0.1);
    Vector3d t2(-0.1,0.5,0.3);

    q1.normalize();
    q2.normalize();

    Isometry3d T1=Isometry3d::Identity();
    T1.rotate(q1);
    T1.pretranslate(t1);
    Isometry3d T2=Isometry3d::Identity();;
    T2.rotate(q2);
    T2.pretranslate(t2);

    Vector3d p(0.5,0,0.2);
    Vector3d p2=T2*T1.inverse()*p;
    cout<<p2.transpose()<<endl;
    return 0;
   }

