void ShellInsert(SqList &L, int dk) {  // �㷨10.4
  // ��˳���L��һ��ϣ���������򡣱��㷨���㷨10.1���������޸ģ�
  //     1. ǰ���¼λ�õ�������dk��������1��
  //     2. r[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ������λ�����ҵ���
  int i,j;
  for (i=dk+1; i<=L.length; ++i)
    if (LT(L.r[i].key, L.r[i-dk].key)) { // �轫L.r[i]�������������ӱ�
      L.r[0] = L.r[i];                   // �ݴ���L.r[0]
      for (j=i-dk; j>0 && LT(L.r[0].key, L.r[j].key); j-=dk)
        L.r[j+dk] = L.r[j];              // ��¼���ƣ����Ҳ���λ��
      L.r[j+dk] = L.r[0];                // ����
    }
} // ShellInsert