void Union(List &La, List Lb) {  // �㷨2.1
  // �����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
  int La_len,Lb_len,i;
  ElemType e;
  La_len = ListLength(La);          // �����Ա��ĳ���  
  Lb_len = ListLength(Lb);
  for (i=1; i<=Lb_len; i++) {
    GetElem(Lb, i, e);              // ȡLb�е�i������Ԫ�ظ���e
    if (!LocateElem(La, e, equal))  // La�в����ں�e��ͬ������Ԫ��
      ListInsert(La, ++La_len, e);  // ����
  }
} // union