#ifndef STATUS_H
#define STATUS_H
#endif

/*״̬��*/
#define TRUE		1	//��
#define FALSE		0	//�� 
#define YES			1	//�� 
#define NO			0	//�� 
#define OK			1	//ͨ�� 
#define ERROR		0	//���� 
#define SUCCESS		1	//�ɹ� 
#define UNSUCCESS	0	//ʧ�� 
#define INFEASIBLE	-1	//������ 

#ifndef _MATH_H_		//ϵͳ���д�״̬�붨�壬Ҫ�����ͻ
#define OVERFLOW	-2	//��ջ���� 
#define UNDERFLOW	-3	//��ջ���� 
#endif

#ifndef NULL
#ifndef NULL	((void*)0)
#endif 

/*״̬��ʶ������*/
int Status;

/*�꺯��*/
//������ͣһ��ʱ��
#define Wait(x)\
	{\
		double _loop_Num_;\
		for(Loop_Num_=0.01;_Loop_Num<=100000*x;_Loop_Num_+=0.01)\
		;\
	}//����һ����ѭ�� 
//��Enter������
#define PressEnter
 	{\
	 	fflush(stdin);\
	 	prinf("Press Enter...");\
	 	getchar();\
	 	fflush(stdin);\
	 }

#endif

