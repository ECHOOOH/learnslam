# CH3 三维空间刚体运动 笔记



### 旋转矩阵

+ 向量在指定坐标系下用坐标表示
  $$
  \boldsymbol{a}=[\boldsymbol{e}_1,\boldsymbol{e}_2,\boldsymbol{e}_3]\begin{bmatrix}a_1\\a_2\\a_3\end{bmatrix}=a_1\boldsymbol{e}_1+a_2\boldsymbol{e}_2+a_3\boldsymbol{e}_3
  $$

+ 内积
  $$
  \boldsymbol{a}·\boldsymbol{b}=\boldsymbol{a}^T\boldsymbol{b}=\sum_{i=1}^3a_ib_i=|a||b|cos\langle\boldsymbol{a},\boldsymbol{b}\rangle
  $$

+ 外积
  $$
  \boldsymbol{a}\times\boldsymbol{b}=\begin{bmatrix}i&j&k \\a_1&a_2&a_3\\b_1&b_2&b_3\end{bmatrix}=\begin{bmatrix}a_2b_3-a_3b_2\\a_3b_1-a_1b_3\\a_1b_2-a_2b_1\end{bmatrix}=\begin{bmatrix}0&-a_3&a_2\\a_3&0&-a_1\\-a_2&a_1&0\end{bmatrix}\boldsymbol{b}\triangleq\boldsymbol{a}\^{}\boldsymbol{b}
  $$