void R_Rotate(BSTree &p) {  //  �㷨 9.9
  // ����*pΪ���Ķ�������������������������֮��pָ���µ�������㣬
  // ����ת����֮ǰ���������ĸ����
  BSTree lc;
  lc = p->lchild;            // lcָ��*p�������������
  p->lchild = lc->rchild;    // lc���������ҽ�Ϊ*p��������
  lc->rchild = p;  p = lc;   // pָ���µĸ����
} // R_Rotate