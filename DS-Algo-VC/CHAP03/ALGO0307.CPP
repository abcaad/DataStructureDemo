// �������õ�����Ҫ����
EventList  ev;                // �¼���
Event      en;                // �¼�
LinkQueue  q[5];              // 4���ͻ�����,q[0]δ��
QElemType  customer;          // �ͻ���¼
int TotalTime, CustomerNum;   // �ۼƿͻ�����ʱ��, �ͻ���
int CloseTime;

//---------------- �㷨 3.7 ------------------

int cmp(Event a,  Event b) {
  // ���¼�a�ķ���ʱ��< ��= ��> �¼�b�ķ���ʱ�̷ֱ𷵻�-1��0��1
  if (a.OccurTime < b.OccurTime) return -1;
  if (a.OccurTime > b.OccurTime) return +1;
  return 0;
}

void Random(int &durtime, int &intertime) { // ���������
   durtime = random(2, 10);
   intertime = random(10);
}

int Minimum(LinkQueue q[]) {  // �󳤶���̶���
   int minlen = QueueLength(q[1]);
   int i = 1;
   for (int j=2; j<=4; j++)
      if (QueueLength(q[j]) < minlen) {
         minlen = QueueLength(q[j]);
         i = j;
      }
   return i;
}

void OpenForDay() {
   // ��ʼ������
   TotalTime = 0;  CustomerNum = 0;  // ��ʼ���ۼ�ʱ��Ϳͻ���Ϊ0
   InitList(ev);                     // ��ʼ���¼�����Ϊ�ձ�
   en.OccurTime = 0;  en.NType = 0;  // �趨��һ���ͻ������¼�
   OrderInsert(ev, en, cmp);    // ���¼�����ʱ�̵Ĵ�������¼���
   for (int i=1; i<=4; ++i) InitQueue(q[i]);   // �ÿն���
} // OpenForDay

void CustomerArrived() {
  // �����ͻ������¼���en.NType=0
  int durtime, intertime, i, t;
  ++CustomerNum;
  printf("Customer %d arrived at %d and ", CustomerNum, en.OccurTime);
  Random(durtime, intertime);            // ���������
  t = en.OccurTime + intertime;          // ��һ�ͻ�����ʱ��
  if (t<CloseTime)                       // ������δ���ţ������¼���
    OrderInsert(ev, MakeElem(t, 0), cmp);
  i = Minimum(q);                        // �󳤶���̶���
  printf("enter the Queue %d\n", i);
  EnQueue(q[i], MakeQElem(en.OccurTime, durtime));
  if (QueueLength(q[i]) == 1) //�趨��i���е�һ���뿪�¼��������¼���
    OrderInsert(ev, MakeElem(en.OccurTime+durtime, i), cmp);
} // CustomerArrived

void CustomerDeparture() {
  // �����ͻ��뿪�¼���en.NType>0
  printf("Customer departure at %d\n", en.OccurTime);
  int i = en.NType;  DeQueue(q[i], customer); //ɾ����i���е���ͷ�ͻ�
  TotalTime += en.OccurTime-customer.ArrivalTime; // �ۼƿͻ�����ʱ��
  if (!QueueEmpty(q[i])) {   // �趨��i���е�һ���뿪�¼��������¼���
    GetHead (q[i], customer);
    OrderInsert(ev, MakeElem(en.OccurTime+customer.Duration, i), cmp);
  }
} // CustomerDeparture

void Bank_Simulation(int closetime) {
  int i = 0;
  BLink p;
  CloseTime = closetime;
  printf("Bank_Simulation( %d ) ----- ����ҵ��ģ��\n", closetime);
  OpenForDay();                     // ��ʼ��
  while (!ListEmpty(ev)) {
    printList(ev);
    if (DelFirst(GetHead(ev), p)) {
      en = GetCurElem(p);
      if (en.NType == 0)
        CustomerArrived();       // �����ͻ������¼�
      else CustomerDeparture();   // �����ͻ��뿪�¼�
    }
    if (++i % 9 == 0) {
      printf("\n----- ������������� -----");
      getch();
      printf("\n\n");
    }
  }
  // ���㲢���ƽ������ʱ��
  printf("\nThe Average Time is %f\n", (float)TotalTime/CustomerNum);
} // Bank_Simulation