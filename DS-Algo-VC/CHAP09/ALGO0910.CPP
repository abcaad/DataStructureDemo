void L_Rotate(BSTree &p) {  // �㷨 9.10
  // ����p��Ϊ���Ķ�������������������������֮��pָ���µ�������㣬
  // ����ת����֮ǰ���������ĸ����
  BSTree rc;
  rc = p->rchild;            // rcָ��*p�������������
  p->rchild = rc->lchild;    // rc���������ҽ�Ϊ*p��������
  rc->lchild = p;  p = rc;   // pָ���µĸ����
} // L_Rotate
                             