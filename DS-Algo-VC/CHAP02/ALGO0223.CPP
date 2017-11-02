int Compare(PElemType a, PElemType b) {
  if (a.expn<b.expn) return -1;
  if (a.expn>b.expn) return 1;
  return 0;
}

void AddPolyn(PLinkList &Pa, PLinkList &Pb) {  // �㷨2.23
  // ����ʽ�ӷ���Pa = Pa��Pb��������������ʽ�Ľ�㹹��"�Ͷ���ʽ"��
  PLink ha,hb,qa,qb;
  PElemType a, b, temp;
  float sum;
  ha = GetHead(Pa);      // ha��hb�ֱ�ָ��Pa��Pb��ͷ���
  hb = GetHead(Pb);
  qa = NextPos(Pa,ha);   // qa��qb�ֱ�ָ��La��Lb�е�ǰ���
  qb = NextPos(Pb,hb);
  while (qa && qb) {     // Pa��Pb���ǿ�
    a = GetCurElem (qa); // a��bΪ�����е�ǰ�Ƚ�Ԫ��
    b = GetCurElem (qb);
    switch (Compare(a,b)) {
      case -1:  // ����ʽPA�е�ǰ����ָ��ֵС
          ha = qa;
          qa = NextPos (Pa, qa);
          break;  
      case 0:   // ���ߵ�ָ��ֵ���
          sum = a.coef + b.coef ;
          if (sum != 0.0) {  // �޸Ķ���ʽPA�е�ǰ����ϵ��ֵ
            temp.coef=sum;
            temp.expn=a.expn;
            SetCurElem(qa, temp) ;
            ha = qa;
          } else {  // ɾ������ʽPA�е�ǰ���
            DelFirst(ha, qa);
            FreeNode(qa);
          }
          DelFirst(hb, qb);
          FreeNode(qb);
          qb = NextPos(Pb, hb);
          qa = NextPos(Pa, ha);
          break;
      case 1:   // ����ʽPB�е�ǰ����ָ��ֵС
          DelFirst(hb, qb);
          InsFirst(ha, qb); 
          qb = NextPos(Pb, hb);
          ha = NextPos(Pa, ha);
          break;
    } // switch
  } // while
  if (!Empty(Pb)) Append(Pa, qb);   // ����Pb��ʣ����
  FreeNode(hb);  // �ͷ�Pb��ͷ���
} // AddPolyn