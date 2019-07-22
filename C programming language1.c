
#define setup sizeof(struct student)
#define lis struct student * 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>

void choice_main();
struct student* print();
struct student* input();
void wenjian(lis head);
struct student* revise(); //信息的修改 
struct student* delete();//删除 
struct student* name_search();//按姓名查询 
struct student* class_search();//按班级查询 
struct student* number_search();//按学号查询 
struct student* course_search();//按按课程名查询 
struct student* total_grade_search();//按总分查询 
struct student* one_grade_search();//单科成绩排名 
struct student* class_exce_rate();//班级优秀率 
void output();
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 struct course
{
   char course_name[10];
   float usual_score;//平时成绩 
	float exper_score;//实验成绩 
 	float test_score;//考试成绩 
 	float total_score;//总评成绩 		
	
};
 struct student
 {
 	char number[10];//学号 
 	char _class[5]; //班级 
 	char name[10]; //姓名 
 	float aver_score;//平均成绩 
	float sum;//总分  
 	struct course student[3];
 	struct student *next;
 };
                                                           

int main(int argc, char *argv[]) //主函数 
{
    int choice;
	do{
		choice_main();
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				{
					input();
					system("pause");
					system("cls");
					break; 
				}
		case 2:{
					revise();
					system("pause");
					system("cls");
					break;
				}
		case 3: {
					delete();
					system("pause");
					system("cls");
					break; 
			
				}
		case 4:
				name_search();
				system("pause");
				system("cls");
				break; 
		case 5: {
					class_search();
					system("pause");
					system("cls");	
					break;
				} 
		case 6: {
			number_search();
			system("pause");
			system("cls");
			break;
		} 
		case 7:{
			course_search();
			system("pause");
			system("cls");
			break;
		}
		case 8:{
			total_grade_search();
			system("pause");
			system("cls");
			break;
		} 
		case 9:{
			one_grade_search();
			system("pause");
			system("cls");
			break;
		} 
		case 10:{
			class_exce_rate();
			getchar();
			system("pause");
			system("cls");
			break;
		} 
		case 11: exit(0);break; 
	}
		//choice_main();
		//scanf("%d",&choice);	
	}while(choice!=11);
	return 0;
}

void output()
{
	lis p1;
	int i=0;
	p1=print();
	printf("所有的学生信息：\n");
	printf("_________________________________________________________________________\n");
	while(p1->next!=NULL)
	{
		printf("\t\t学号\t班级\t姓名\t总分\t总平均分\t\n");
		printf("\t\t%s\t%s\t%s\t%.2f\t%.2f\t\n\n",p1->number,p1->_class,p1->name,p1->sum,p1->aver_score);
		for(i=0;i<3;i++)
		{
			printf("\t\t  \t平时成绩\t实验成绩\t考试成绩\t总评成绩\t\n");
			printf("课程名称:"/*p1->student[i].course_name*/);
			printf("   %s\t %.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\n",p1->student[i].course_name,p1->student[i].usual_score,p1->student[i].exper_score,p1->student[i].test_score,p1->student[i].total_score);
		}
		p1=p1->next;
		printf("\n");	
	}
	printf("_________________________________________________________________________\n");
}


void choice_main()//选择菜单界面 
{
	printf("\t\t学生成绩管理信息系统\n\n ");
	printf("\t\t*****************************\n\n");
	printf("\t\t1.输入学生的信息\n");
	printf("\t\t2.修改学生的信息\n");
	printf("\t\t3.删除学生的信息\n");
	printf("\t\t4.按姓名查询\n");
	printf("\t\t5.按班级查询\n");
	printf("\t\t6.按学号查询\n");
	printf("\t\t7.按课程名称查询\n");
	printf("\t\t8.按总分高低排名查询\n");
	printf("\t\t9.单科成绩排名\n");
	printf("\t\t10.查询班级成绩优秀率\n");
	printf("\t\t11.退出系统\n"); 
	printf("\n\n\t\t*****************************\n");
	
	printf("请输入你要选择的功能所对应的序号：");	
 } 

struct student* input()  //学生数据的录入 
{
   int icount;
   lis head;
   lis tail;
   lis p;
   int i=0;
   float sum=0;
   float aver=0;
   head=NULL;
   
   p=tail=(lis)malloc(setup);
   head=p;
   printf("__________当输入的学号为 0时，则结束输入学生的信息____________\n");  
   printf("\n请输入学生的信息：学号 姓名 班级 \n");
   while(1) 
   {
   		printf("\n");
   		printf("学号：");
   		scanf("%s",p->number);
		   if(!strcmp("0",p->number))
		   {
		   		break;
		   }
		   printf("班级 姓名（输入时用用一个空格分开）\n");
		    scanf("%s %s",p->_class,p->name);
			printf("\n"); 
			for(i=0;i<3;i++)
			{
				printf("请输入课程名:");
				scanf("%s",p->student[i].course_name);
				printf("及所对应的平时成绩 实验成绩 考试成绩 总评成绩（成绩之间用一个空格分开）："); 
				scanf("%f %f %f %f",&p->student[i].usual_score,&p->student[i].exper_score,&p->student[i].test_score,&p->student[i].total_score);
				sum+=p->student[i].total_score;	
			}
		p->sum=sum;
		aver=p->sum/3;
		p->aver_score=aver;	
   		icount++;
   		if(icount==1)  //只有一个学生信息时 
   		{
   			head=p;
		   p->next=NULL;
		   tail=p;	
   		}
   		else       
   		{
   			p->next=NULL;
   			tail->next=p;
   			tail=p;
   		}
		p=(lis)malloc(setup);
   }
   free(p);
   printf("\n\n*******共有%d个学生的信息录入*******\n\n",icount);
   wenjian(head);  //wenjian函数的调用 
   return (head);
}
 
void wenjian(struct student* head)   //把数据存入文件中 
{
	int i=0;
	FILE *fp;
	struct student* p;
	p=head;
	fp=fopen("data1.txt","wt");
	if(fp==NULL)
	{
		printf("\n文件打开失败，文件可能不存在\n");
		getchar();
		exit(0);
	}
	while(p!=NULL)
	{
		fprintf(fp,"%s %s %s %.2f %.2f\n",p->number,p->_class,p->name,p->sum,p->aver_score);
		for(i=0;i<3;i++)
		{
			fprintf(fp,"%s %.2f %.2f %.2f %.2f\n",p->student[i].course_name,p->student[i].usual_score,p->student[i].exper_score,p->student[i].test_score,p->student[i].total_score);	
		}
		
		p=p->next;
	} 
	fclose(fp);
} 
 
 
lis print()//从文件中显示 
{
	int i=0;
	struct student *head;
	struct student *p1;
	struct student *r;
	FILE *fp;
	fp=fopen("data1.txt","rt");
	if(fp==NULL)
	{
		printf("文件打开失败，文件可能不存在\n");
		_getch();
		exit(0);
	}
	head=(lis)malloc(setup);
	head->next=NULL;
	r=head;
	while(!feof(fp))
	{
		p1=(lis)malloc(setup);
		fscanf(fp,"%s %s %s %f %f\n",p1->number,p1->_class,p1->name,&p1->sum,&p1->aver_score );
		for(i=0;i<3;i++)
		{
			fscanf(fp,"%s %f %f %f %f",p1->student[i].course_name,&p1->student[i].usual_score,&p1->student[i].exper_score,&p1->student[i].test_score,&p1->student[i].total_score);
		}
		r->next=p1;
		r=p1;
	}
	r->next=NULL;
	fclose(fp);
	head = head->next;
	return head;
}


struct student* revise()//修改功能 
{
	   int flag=1;
	   int i=0;
	   struct student* pt;
   		struct student* head;
   		char num[10];
   		head=pt=print();
   		output();
	   printf("\n请输入要修改的学生的学号：");
	   scanf("%s",num);
	   do 
	   {
	   		if(!strcmp(num,pt->number))
	   		{
	   			break;
			   }
			pt=pt->next;
			if(!strcmp(num,pt->number))
			   {
			   		flag=0;
			   }
			else if(pt->next==NULL)
			   {
			   		printf("**********您输入的学号可能不存在*******");
			   		return 0; 
			   }
		}while(flag==1);
	
	printf("您要修改的学生信息为："); 
	printf("\n学号：%s",pt->number);
	printf("\n班级：%s",pt->_class);
	printf("\n姓名：%s",pt->name);
	printf("\n总分：%.2f",pt->sum);
	printf("\n平均分：%.2f",pt->aver_score); 
	for(i=0;i<3;i++)
	{
		printf("\n课程名：%s",pt->student[i].course_name);
		printf("\n平时成绩：%.2f",pt->student[i].usual_score);
		printf("\n实验成绩：%.2f",pt->student[i].exper_score);
		printf("\n考试成绩：%.2f",pt->student[i].test_score);
		printf("\n总评成绩：%.2f",pt->student[i].total_score);
	}
	printf("\n\n");
	printf("请输入您要修改的学生的信息：\n\n");
	printf("\n学号：");
	scanf("%s",pt->number); 
	printf("\n班级：");
	scanf("%s",pt->_class); 
	printf("\n姓名：");
	scanf("%s",pt->name); 
	printf("\n总分：");
	scanf("%f",&pt->sum);
	printf("\n平均分：");
	scanf("%f",&pt->aver_score); 
	for(i=0;i<3;i++)
	{
		printf("\n课程名：");
	scanf("%s",pt->student[i].course_name  );
	printf("\n平时成绩：");
	scanf("%f",&pt->student[i].usual_score );
	printf("\n实验成绩：");
	scanf("%f",&pt->student[i].exper_score );
	printf("\n考试成绩：");
	scanf("%f",&pt->student[i].test_score );
	printf("\n总评成绩：");
	scanf("%f",&pt->student[i].total_score );
	}
	wenjian(head);
	printf("**************信息修改成功*************");
}

struct student* delete()//删除功能 
{
    lis pt;
    lis pi;
    lis head;
    int flag=1;
    char num[10];
    int i=0;
    head=pt=pi=print();  //调用print函数 
	output(); 
	printf("\n请输入您要删除的学号：");
	scanf("%s",num);
	do
	{
		if(!strcmp(num,pi->number))
		{
			printf("\n您要删除的学生的信息如下：\n");
			printf("\n学号：%s",pi->number);
			printf("\n班级：%s",pi->_class);
			printf("\n姓名：%s",pi->name);
			printf("\n总分：%.2f",pi->sum);
			printf("\n总分：%.2f",pi->aver_score);
			for(i=0;i<3;i++)
			{
				printf("\n课程名：%s",pi->student[i].course_name);
				printf("\n平时成绩:%0.2f 实验成绩:%0.2f 考试成绩:%0.2f 总评成绩:%0.2f\n",pi->student[i].usual_score,pi->student[i].exper_score,pi->student[i].test_score,pi->student[i].total_score);
			 } 
			
			head=pi->next;
			pt=pt->next;
			free(pi);
			printf("\n\n***该学生信息已被删除*****\n\n");
			wenjian(head);
			return 0;
		}
		pi=pt;
		pt=pt->next;
		 if(!strcmp(num,pt->number))
		{
			flag=0;
		}
		else if(pt->next==NULL)
		{
			printf("\n\n********您输入的学号可能不存在***********\n");
			return 0;
		}
	}while(flag==1);
	printf("\n您要删除的学生的信息如下：\n");	
			printf("\n学号：%s",pt->number);
			printf("\n班级：%s",pt->_class);
			printf("\n姓名：%s",pt->name);
			printf("\n总分：%.2f",pt->sum);
			printf("\n总分：%.2f",pt->aver_score);
			for(i=0;i<3;i++)
			{
				printf("\n课程名：%s",pt->student[i].course_name);
				printf("\n平时成绩:%0.2f 实验成绩:%0.2f 考试成绩:%0.2f 总评成绩:%0.2f\n",pt->student[i].usual_score,pt->student[i].exper_score,pt->student[i].test_score,pt->student[i].total_score);
			}
			pi->next = pt->next;
			free(pt);
			printf("\n\n***该学生信息已被删除*****\n\n");
			wenjian(head);
			return 0;
}


struct student* name_search()//名字查询 
{   
   char name[10];
   lis pt;
   lis head;
   lis pi;
   int flag=1;
   int i=0;
   head=pt=pi=print();
   output();
   printf("请输入你要查询的学生姓名：");
   scanf("%s",name);
   while(pt->next!=NULL)
	 {
	 	if(strcmp(name,pt->name)==0)
	 	{
	 		printf("\n您要查询的学生的信息如下：\n");
			printf("\n学号：%s",pt->number);
			printf("\n班级：%s",pt->_class); 
			printf("\n姓名：%s",pt->name);
			printf("\n总分：%.2f",pt->sum);
			for(i=0;i<3;i++)
			{
				printf("\n课程名：%s",pt->student[i].course_name);
				printf("\n平时成绩:%0.2f 实验成绩:%0.2f 考试成绩:%0.2f 总评成绩:%0.2f\n",pt->student[i].usual_score,pt->student[i].exper_score,pt->student[i].test_score,pt->student[i].total_score);
			}	
		 }
		 pt=pt->next;
	 } 
   printf("\n");
}


struct student* class_search()//班级查询 
{
	char class[10];
	lis pt;
	lis head;
	int i=0;
	int flag=1; 
	pt=head=print();
	output();
	printf("请输入你要查询的班级号；");
	scanf("%s",class); 
	printf("\n您要查询的学生的信息如下：\n");
	printf("__________________________________________________________\n");
	printf("\t学号\t班级\t姓名\t\n"); 
	 while(pt->next!=NULL)
	 {
	 	
		 if(strcmp(class,pt->_class)==0)
	 	{
			printf("\t%s\t%s\t%s\t\n",pt->number,pt->_class,pt->name); 
		 }
		 pt=pt->next;
	 }
	 //if(strcmp(class,pt->_class)!=0)
	//{
	 	//class_search();
	 //}
	 printf("__________________________________________________________\n");
}

struct student* number_search()//学号查询 
{
	lis pt;
	lis head;
	head=pt=print();
	char num[10];
	int flag=1;
	int i=0;
	output();
	printf("请输入您要查询的学号：");
	scanf("%s",num);
	do{
		if(!strcmp(num,pt->number))
		{
			printf("\n您要查询的学生信息如下：\n");
			printf("\n学号：%s",pt->number);
			printf("\n班级：%s",pt->_class);
			printf("\n姓名：%s",pt->name);
			printf("\n总分：%.2f",pt->sum);
			printf("\n平均分：%.2f",pt->aver_score);
			for(i=0;i<3;i++)
			{
				printf("\n课程名：%s",pt->student[i].course_name);
				printf("\n平时成绩: %0.2f 实验成绩: %0.2f 考试成绩: %0.2f 总评成绩: %0.2f",pt->student[i].usual_score,pt->student[i].exper_score,pt->student[i].test_score,pt->student[i].total_score);		
			}
			return 0;
		}
		pt=pt->next;
		 if(!strcmp(num,pt->number))
		{
			flag=0;	
		}
		else if(pt->next==NULL)
		{
			printf("\n*******您输入的学号可能不存在********\n");
			return 0; 
		}
	}while(flag==1);
	printf("\n您要查询的学生信息如下：\n");
			printf("\n学号：%s",pt->number);
			printf("\n班级：%s",pt->_class);
			printf("\n姓名：%s",pt->name);
			printf("\n总分：%.2f",pt->sum);
			printf("\n平均分：%.2f",pt->aver_score);
			for(i=0;i<3;i++)
			{
				printf("\n课程名：%s",pt->student[i].course_name);
				printf("\n平时成绩: %0.2f 实验成绩: %0.2f 考试成绩: %0.2f 总评成绩: %0.2f",pt->student[i].usual_score,pt->student[i].exper_score,pt->student[i].test_score,pt->student[i].total_score);		
			}
	printf("\n");		
}


struct student* course_search()//课程名查询 
{
	lis pt;
	lis head;
	head=pt=print();
	//system("cls");  
	char course[10];
	int flag=1;
	int i=0;
	int j=0;
	printf("请输入您要查询的课程名：");
	scanf("%s",course);
	printf("\n您要查询的科目信息如下：\n");
		for(pt;pt!=NULL;pt=pt->next)
		{
			j=0; 
			while(j<3)
			{
				if(strcmp(course,pt->student[j].course_name)==0)
				{
					
					printf("\n学号：%s",pt->number);
					printf("\n班级：%s",pt->_class);
					printf("\n姓名：%s",pt->name);
					printf("\n课程名：%s",pt->student[j].course_name);
					printf("\n平时成绩: %0.2f 实验成绩: %0.2f 考试成绩: %0.2f 总评成绩: %0.2f\n",pt->student[i].usual_score,pt->student[i].exper_score,pt->student[i].test_score,pt->student[i].total_score);	
					
				}
				j++;
			 }
			  
		}
		
}


struct student* total_grade_search()//总分排序 
{
   lis p;
  struct student stu[100],st;
  int i=0,j=0,t=0;
   p=print();
   while(p!=NULL)
   {
   		i++;
		strcpy(stu[i].number,p->number);
   		strcpy(stu[i]._class,p->_class);
   		strcpy(stu[i].name,p->name);
   		stu[i].sum=p->sum;
   		p=p->next;
   		
	}
	   t=i;
	   for(i=0;i<t-1;i++)
	   {
	   		for(j=i+1;j<t;j++)
	   		{
	   		if(stu[i].sum<stu[j].sum)
	   		{
	   			st=stu[i];
	   			stu[i]=stu[j];
	   			stu[j]=st;	
			}
		   }
		   }
		printf("_________________________________________________________\n");
		for(i=0;i<t-1;i++)
		{
			printf("\t学号\t班级\t姓名\t总分\t\n");
			printf("\t%s\t%s\t%s\t%.2f\n",stu[i].number,stu[i]._class,stu[i].name,stu[i].sum);
			}
		printf("_________________________________________________________\n");	
			
}

struct student* one_grade_search()//单科成绩排名 
{
	lis p;
	lis head;
	char subject[10];
	struct student stu[100],st;
	int i=0,j=0,t=0,k=0;
	printf("请您输入您要查询的科目：");
	scanf("%s",subject);
   	p=print();
   while(p!=NULL)
   {
   		i++;
		strcpy(stu[i].number,p->number);
   		strcpy(stu[i]._class,p->_class);
   		strcpy(stu[i].name,p->name);
   		stu[i].student[0]=p->student[0];
   		stu[i].student[1]=p->student[1];
   		stu[i].student[2]=p->student[2];
   		p=p->next;
	}
	t=i;
	for(i=0;i<t-1;i++)
	   {
	   		for(j=i+1;j<t;j++)
	   		{
	   			for(k=0;k<3;k++)
	   			{
	   				if(strcmp(stu[i].student[k].course_name,subject)==0)
	   				{
	   					if(strcmp(stu[j].student[k].course_name,subject)==0)
					   	{
					   	  if(stu[i].student[k].total_score<stu[j].student[k+1].total_score)
					   	  {
					   	  	 st.student[0].total_score=stu[j].student[k+1].total_score;
					   	  	 stu[j].student[k+1].total_score=stu[i].student[k].total_score;
					   	  	 stu[i].student[k].total_score=st.student[0].total_score;
					   	  	 if(k+1>=4)
					   	  	 {
					   	  	 	break;
								  }
							 }
					   	}
	   			    
					}
				}
		   }
		}
		printf("_____________________________________________________________\n");
		for(i=0;i<t;i++)
		{
			for(k=0;k<3;k++)
			{
				if(strcmp(stu[i].student[k].course_name,subject)==0)
				{
					printf("\t学号\t班级\t姓名\t科目\t总评成绩\t\n");
					printf("\t%s\t%s\t%s\t%s\t%.2f\n",stu[i].number,stu[i]._class,stu[i].name,subject,stu[i].student[k].total_score);
				}
			}
		}
		printf("_____________________________________________________________\n");
} 
 
struct student* class_exce_rate()//优秀率查看 
{
  	lis pt;
	lis head;
	lis p1;
	char subject[10];
	int j=0;
	float i=0;
	float k=0;
	float fail=0; 
	printf("请您输入您要查询的科目：");
	scanf("%s",subject);
	p1=pt=head=print();
    for(pt;pt!=NULL;pt=pt->next)
		{
			j=0; 
			while(j<3)
			{
				if(strcmp(subject,pt->student[j].course_name)==0)
				{
					if(pt->student[j].total_score>=90)
					{
						i=i+1;
						}
					if(pt->student[j].total_score<60)
					{
						fail++;
						}	
					break; 
				}	
				j++;
			}
		}
	printf("__________________________________________________________\n");
	printf("\n此科目成绩大于等于90分的人数为 %.0f\n",i);
	printf("此科目成绩小于60分的人数为 %.0f\n",fail);
	for(p1;p1!=NULL;p1=p1->next)
		{
			j=0; 
			while(j<3)
			{
				if(strcmp(subject,p1->student[j].course_name)==0)
				{
					k++;
					break; 
				}	
				j++;
			}
		}
	printf("学习这科目的总人数为 %.0f\n",k);
	printf("这门科目的优秀率为百分之 %.0f\n",(i/k)*100);
	printf("这门科目的不及格率为百分之 %.0f\n",(fail/k)*100);
	printf("__________________________________________________________\n"); 
}

