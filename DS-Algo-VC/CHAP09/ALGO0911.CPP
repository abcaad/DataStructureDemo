Status InsertAVL(BSTree &T, ElemType e, Boolean &taller) { // �㷨9.11
  // ����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬
  // �����һ������Ԫ��Ϊe���½�㣬������1�����򷵻�0��
  // ��������ʹ����������ʧȥƽ�⣬����ƽ����ת������
  // ��������taller��ӳT�������
  if (!T) {  // �����½�㣬��"����"����tallerΪTRUE
    T = (BSTree) malloc (sizeof(BSTNode));  T->data = e;
    T->lchild = T->rchild = NULL;  T->bf = EH;  taller = TRUE;
  }
  else {
    if (EQ(e.key, T->data.key))    // �����Ѵ��ں�e����ͬ�ؼ��ֵĽ��
      { taller = FALSE;  return 0; } // ���ٲ���
    if (LT(e.key, T->data.key)) {    // Ӧ������*T���������н�������
      if (InsertAVL(T->lchild, e, taller)==0) return 0;    // δ����
      if (taller)  // �Ѳ��뵽*T������������������"����"
        switch (T->bf) {   // ���*T��ƽ���
          case LH:   // ԭ�����������������ߣ���Ҫ����ƽ�⴦��
             LeftBalance(T);   taller = FALSE;  break;
          case EH:   // ԭ�����������ȸߣ��������������߶�ʹ������
             T->bf = LH;  taller = TRUE;  break;
          case RH:   // ԭ�����������������ߣ������������ȸ�
             T->bf = EH;  taller = FALSE;  break;   
        } // switch (T->bf)
    } // if
    else {    // Ӧ������T�����������н�������
      if (InsertAVL(T->rchild, e, taller)==0) return 0;
      if (taller)         // �Ѳ��뵽*T��������������������
        switch (T->bf) {  // ���*T��ƽ���
          case LH:   // ԭ�����������������ߣ������������ȸ�
             T->bf = EH;  taller = FALSE;  break;   
          case EH:   // ԭ�����������ȸߣ��������������߶�ʹ������
             T->bf = RH;  taller = TRUE;  break;
          case RH:   // ԭ�����������������ߣ���Ҫ����ƽ�⴦��
             RightBalance(T);  taller = FALSE;  break;
        } // switch (T->bf)
    } // else
  } // else 
  return 1;
} //InsertAVL