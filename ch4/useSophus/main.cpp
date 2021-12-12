#include <iostream>
#include <cmath>
using namespace std ;

#include <Eigen/Core>;
#include <Eigen/Geometry>;
#include "sophus/so3.h"
#include "sophus/se3.h"

using namespace Eigen;
using namespace Sophus;


int main() {
    //沿Z轴旋转90度的旋转矩阵
    Matrix3d R = AngleAxisd (M_PI/2,Vector3d(0,0,1)).toRotationMatrix();
    //对应的四元数
    Quaterniond  q(R);

    //从旋转矩阵构造SO3
    SO3 SO3_R(R);
    //从旋转向量构造SO3
    SO3 SO3_v(0,0,M_PI/2);
    //从四元数构造SO3
    SO3 SO3_q(q);

    cout<<"SO(3) from matrix"<<SO3_R<<endl;
    cout<<"SO(3) from vector"<<SO3_v<<endl;
    cout<<"SO(3) from quaternion"<<SO3_q<<endl;


    //使用对数映射得到其李代数
    Vector3d so3=SO3_R.log();
    cout<<"so3 = "<<so3.transpose()<<endl;
    //由向量到反对称矩阵 由反对称矩阵到向量
    cout<<"so3 hat= "<<endl<<SO3::hat(so3)<<endl;
    cout<<"so3 hat vee= "<<SO3::vee(SO3::hat(so3)).transpose()<<endl;

    //增量扰动模型
    //假设更新量有这么多
    Vector3d update_so3(1e-4,0,0);
    SO3 SO3_updated=SO3::exp(update_so3)*SO3_R;//左乘更新
    cout<<"SO3 updated = "<<SO3_updated<<endl;

    cout<<"----------------------------分割线-------------------------------"<<endl;

    //对SE3
    //沿x轴平移1
    Vector3d t(1,0,0);
    //从旋转矩阵构造SE3
    SE3 SE3_Rt(R,t);
    //从旋转向量构造SE3
    SE3 SE3_qt(q,t);
    cout<<"SE3 from R,t "<<SE3_Rt<<endl;
    cout<<"SE3 from q t "<<SE3_qt<<endl;

    //李代数se3是一个六维向量 为了方便 typedf一下
    typedef Matrix<double,6,1> Vector6d;
    Vector6d se3=SE3_qt.log();
    cout<<"se3 = "<<se3.transpose()<<endl;

    cout<<"se3 hat = "<<endl<<SE3::hat(se3)<<endl;
    cout<<"se3 hat vee = "<<SE3::vee(SE3::hat(se3)).transpose()<<endl;

    Vector6d update_se3;
    update_se3.setZero();
    update_se3(0,0)=1e-4;
    SE3 SE3_updated = SE3::exp(update_se3)*SE3_Rt;
    cout<<"SE3 updated = "<<endl<<SE3_updated.matrix()<<endl;

    return 0;
}
